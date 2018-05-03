/* ######################################################################## */
/* 									   										*/
/* 		TRSMeasure.C	Time-Resolved Spectroscopy	 Release 7.0  Oct  2006 */
/* 									   										*/
/* ######################################################################## */


/* ########################   NOTES   ################################## */

/* ########################   HELP   ################################## */
// Board = Physical TCSPC Board
// Det = Detector channel as determined by the router bits
// Chann = Channel of the MCA (=minimum time division)
// Frame = Data transferred from the boards and effectively stored in RAM
// Page = Curve belonging to a Frame

/* ########################   HEADINGS   ################################## */

#include <ansi_c.h>
#include <utility.h>
#include <cvirte.h>    /* Needed if linking in external compiler; harmless otherwise */
#include <formatio.h>
#include <userint.h>
#include <gpib.h>
#include "easyio.h"
#include <tcpsupp.h>
#include <rs232.h>
#include <analysis.h>
#include <dataacq.h>
#include "measure.h"   
#include "trs.h" 
#include "mbc32.h" 
#include "spcm_def.h"
#include "spc_isa_def.h"
#include "thlibc.h"
#include "thdefin.h"
#include "W32nii3eMOD.h"
#include <NIDAQmx.h>
#include <DAQmxIOctrl.h>

//#include "MAMM.h"

#include "MercLib210.h" //PI Driver header file

/* ########################   MEASURE PROCEDURES   ########################### */

TaskHandle	taskmodpower=0;
/* DO MEASUREMENT */
void CVICALLBACK Measure(int menuBar,int menuItem,void *callbackData,int panel){
	char isw,is,it,il;
	if(IS_PROFILING) InitProf();
	do{ 
		P.Contest.Run=CONTEST_MEAS;
		P.Contest.Function=CONTEST_MEAS;
		CompleteParmS();
		/**/UpdatePanel();
		InitFiber();
		InitSource();
		//InitGeom();
		InitFilter();
		InitTwitch();
		InitDisplay();
		InitTime();
		InitMem();
		for(isw=0;isw<MAX_SWITCH;isw++)
			if(P.Switch[isw].Switch){
				InitPosSwitch(isw);
		    	InitSwitch(isw);
		    	}
		for(is=0;is<MAX_STEP;is++)
			if(P.Step[is].Step){
				InitPos(is);
				InitStep(is);
				}
		for(it=0;it<MAX_TRIM;it++)
			if(P.Trim[it].Trim) InitTrim(it);
		for(il=0;il<MAX_LOOP;il++)
			if(P.Loop[il].Break) InitBreak(il);
		InitSync();
		InitOma();
		InitOphir();
		SpcInit();
		switch (P.Info.Appl){
			case APPL_MAMM: 
				break;
			default: 
				InitDataFile(); 
				break;
			}
		InitMoxy();
		InitPres();
		switch (P.Info.Appl){
			case APPL_GEN: KernelGen(); break;
			case APPL_SPECTRA: KernelGen(); break;
			case APPL_MAMM: KernelMamm(); break;
			case APPL_MOXY: KernelMoxy(); break;
			}
		CloseMeasure();
		CloseDataFile();
		UpdateTag();
		CloseMem();
		TextOut();
		
		if(IS_PROFILING) RecProf("Pre Calib");
		CalibrateTime(1.0);
		if(IS_PROFILING) RecProf("Post Calib");
		CloseTime();
		CloseMoxy();
		CloseOma();
		CloseOphir();
		SetActivePanel(hParm);
		DisplayPanel(hParm);
		}
	while(!P.Command.Abort&&P.Meas.Autorun);
	if(IS_PROFILING) CloseProf();
	}

/* RUN OSCILLOSCOPE */
void CVICALLBACK RunOscilloscope (int menuBar, int menuItem, void *callbackData,int panel){
	P.Contest.Run=CONTEST_OSC;
	P.Contest.Function=CONTEST_OSC;
	CompleteParmS();
	/**/UpdatePanel();
	InitDisplay();
	InitTime();
	InitMem();
	SpcInit();
	
	Oscilloscope();
	
	CloseMem();
	CloseTime();
	SetActivePanel(hParm);
	}


/* MEASURE KERNEL */
void KernelGen(){
	int panel,control;
	long il;
	char is,isw,it;
	Oscilloscope();
	if(P.Command.Abort) return;
	for(is=0;is<MAX_STEP;is++)
		DefineHome(is);
	
	for(P.Loop[LOOP1].Idx=0;P.Loop[LOOP1].Idx<P.Loop[LOOP1].Num;P.Loop[LOOP1].Idx++){
		if(P.Command.Abort) break;
		for(P.Loop[LOOP2].Idx=0;P.Loop[LOOP2].Idx<P.Loop[LOOP2].Num;P.Loop[LOOP2].Idx++){
			if(P.Command.Abort) break;
			for(P.Loop[LOOP3].Idx=0;P.Loop[LOOP3].Idx<P.Loop[LOOP3].Num;P.Loop[LOOP3].Idx++){
				GetUserEvent (0, &panel, &control);
				if(P.Command.Abort) break;
				
				SetLoopActual();
				DecideAction();
				for(isw=0;isw<MAX_SWITCH;isw++)
				    if(P.Action.MoveSwitch[isw]) MoveSwitch(CalcGoalSwitch(isw),isw);
				for(is=0;is<MAX_STEP;is++)
					if(P.Action.MoveStep[is]) MoveStep(&P.Step[is].Actual,CalcGoal(is),is,(char)(P.Step[is].Mode!=STEP_MULTI),P.Action.Status);
				for(is=0;is<MAX_STEP;is++)
					if(P.Action.WaitStep[is]) WaitStep(&P.Step[is].Actual,CalcGoal(is),is,P.Action.Status);
				for(it=0;it<MAX_TRIM;it++)
					if((P.Action.Trim[it])&&!P.Trim[it].Break) AutoTrim(it);
				if(P.Action.DisplayStatus) DisplayStatus();
				for(il=0;il<MAX_LOOP;il++)
					if(P.Action.Break[il]){Oscilloscope();if(P.Command.Abort) break;}
				for(it=0;it<MAX_TRIM;it++)
					if((P.Action.Trim[it])&&P.Trim[it].Break) AutoTrim(it);
				if(P.Action.StartOma) StartOma();
				if(P.Action.Ophir) GetOphir();
				if(P.Action.WaitChrono) WaitChrono();
				for(is=0;is<MAX_STEP;is++)
					if(P.Action.StartCont[is]) StartCont(is,P.Action.Status);
				if(P.Action.StartSync) StartSync();
				if(P.Action.SpcReset) SpcReset(P.Action.Status,P.Meas.Clear,P.Meas.Stop);
				if(P.Action.WaitEnd) WaitEnd(P.Spc.TimeM,P.Wait.Pos,P.Wait.Type,P.Wait.Step);
				if(P.Action.StopSync) StopSync();
				if(P.Action.SpcStop) SpcStop(P.Action.Status);
			//	if(P.Action.StopAdc) StopAdc();		 // mi da errore...Andrea F
				if(P.Action.StopOma) StopOma();
				if(P.Action.SpcOut) SpcOut(P.Action.Status);
				if(P.Action.DisplayPlot) DisplayPlot();
				if(P.Action.DisplayRoi) DisplayRoi();
				if(P.Action.DataSave) DataSave();
				for(is=0;is<MAX_STEP;is++)
					if(P.Action.WaitCont[is]) WaitCont(is,P.Action.Status);
				NewAcq();

				if(P.Command.ReadUIR) GetUserEvent (0, &panel, &control);
	 			}
	 	    }
	    }
	}

	
/* RUN DO STEP */
int CVICALLBACK RunDoStep(int panel,int control,int event,void *callbackData,int eventData1,int eventData2){
	char issue;
	int homecontrol;
	if(event!=EVENT_COMMIT) return 0;
	P.Contest.Run=CONTEST_OSC;
	switch(control){
		case DO_STEP_EXECUTE_1: issue=0; homecontrol=DO_STEP_HOME_1; break;
		case DO_STEP_EXECUTE_2: issue=1; homecontrol=DO_STEP_HOME_2; break;
		case DO_STEP_EXECUTE_3: issue=2; homecontrol=DO_STEP_HOME_3; break;
		}
	DoStep(issue,homecontrol);
	return 0;
	}


/* DO STEP */
void DoStep(char Issue, int Homecontrol){
	struct DoStepS *dostep=&P.DoStep[Issue];
	char step=dostep->Step;
	double factor=P.Step[step].Factor;
	CompleteParmS();
	InitDisplay();
	InitStep(step);
	P.Step[step].Actual=(long)(dostep->Home*factor);
	MoveStep(&P.Step[step].Actual,(long)(dostep->Goal*factor),step,TRUE,TRUE);
	if(dostep->Oscill){
		InitMem();
		SpcInit();
		Oscilloscope();
		CloseMem();
		}
//	else if(dostep->Break) NoOscilloscope();	//TODO: check
	if(dostep->Return) MoveStep(&P.Step[step].Actual,(long)(dostep->Home*factor),step,TRUE,TRUE);
	else SetCtrlVal(hDoStep,Homecontrol,dostep->Goal);
	SetActivePanel(hParm);
	}


/* OSCILLOSCOPE */
void Oscilloscope(void){
	int panel,control;
	char status=TRUE;
	int wait_type=(((P.Wait.Type==WAIT_POS)||(P.Wait.Type==WAIT_COUNT))?WAIT_DELAY:P.Wait.Type);
	SetCtrlVal (hDisplay, DISPLAY_CONTPAUSE, OFF);
	SetCtrlVal (hDisplay, DISPLAY_MESSAGE,"Press CONTINUE to go on with measurement\n");
	P.Command.Continue=FALSE;
	P.Contest.Function = CONTEST_OSC;
	SpcTime(P.Spc.TimeO);
	while(!P.Command.Continue && !P.Command.Abort){
		GetUserEvent (0, &panel, &control);
		SpcReset(status,P.Meas.Clear,P.Meas.Stop);
		WaitEnd(P.Spc.TimeO,0,wait_type,0);
		if(P.Meas.Stop) SpcStop(status);
		SpcOut(status);
		DisplayRoi();
		DisplayPlot();
		}

	if(P.Contest.Run==CONTEST_MEAS)
		switch(P.Spc.Type){
			case SPC300:
			case SPC630:  
			case SPC130: 
				SyncWait (P.Spc.TimeInit, SPC_TIMEDELAY); 
				break;
			}
	//SpcReset(status,TRUE,TRUE); //TODO: needed?
	SpcStop(status); //TODO: needed?
	SpcTime(P.Spc.TimeM);
	P.Spc.Trash=TRUE;
	P.Contest.Function = CONTEST_MEAS;
	}		


/* DECIDE ACTUAL LOOP INDEX */
void SetLoopActual(void){
	int il;
	for(il=0;il<MAX_LOOP;il++) P.Loop[il].Actual=P.Loop[il].Idx;
	for(il=1;il<MAX_LOOP;il++)
		if((P.Loop[il].Invert)&&REMINDER(P.Loop[il-1].Idx,2)) P.Loop[il].Actual=P.Loop[il].Num-1-P.Loop[il].Idx;
	}


/* DECIDE ACTION TO BE PERFORMED ACCORDING TO LOOP STATUS */
void DecideAction(void){
	long il1 = P.Loop[LOOP1].Idx;
	long il2 = P.Loop[LOOP2].Idx;
	long il3 = P.Loop[LOOP3].Idx;
	long index=1+il3+il2*P.Loop[LOOP3].Num+il1*P.Loop[LOOP2].Num*P.Loop[LOOP3].Num;
	int first3=(il3==0);
	int first2=(first3&&(il2==0));
	int first1=(first2&&(il1==0));
	int last3=(il3==(P.Loop[LOOP3].Num-1));
	int last2=(last3&&(il2==(P.Loop[LOOP2].Num-1)));
	int last1=(last2&&(il1==(P.Loop[LOOP1].Num-1)));
	int second3=(il3==1);
	int second2=(first3&&(il2==1));
	int second1=(first2&&(il1==1));
	int new3 = TRUE;
	int new2 = first3;
	int new1 = first2;
	int old3 = TRUE;
	int old2 = last3;
	int old1 = last2;
	int isw,is,it,il,ie;
	int first[3],last[3],second[3],new[3],old[3];
	char action,isbreak;
	first[LOOP1]=first1; first[LOOP2]=first2; first[LOOP3]=first3;
	last[LOOP1]=last1; last[LOOP2]=last2; last[LOOP3]=last3;
	second[LOOP1]=second1; second[LOOP2]=second2; second[LOOP3]=second3;
	new[LOOP1]=new1; new[LOOP2]=new2; new[LOOP3]=new3;
	old[LOOP1]=old1; old[LOOP2]=old2; old[LOOP3]=old3;

   	// Move Switch
   	for(isw=0;isw<MAX_SWITCH;isw++)
   		P.Action.MoveSwitch[isw]=(P.Switch[isw].Switch&&new[P.Switch[isw].Loop]);
		
   	// Do Sync
   	P.Action.StartSync=(P.Sync.Sync&&new[P.Sync.Loop]);
   	P.Action.StopSync=(P.Sync.Sync&&new[P.Sync.Loop]);

	// Move Step
   	for(is=0;is<MAX_STEP;is++){
   		if(P.Step[is].Step)
			switch (P.Loop[P.Step[is].Loop].Cont) {
				case CONT_NONE:
				case CONT_STEP: action=new[P.Step[is].Loop]; break;
				case CONT_RANGE: action=first[P.Step[is].Loop]; break;
				}
		else action=FALSE;
  		P.Action.MoveStep[is]=(P.Step[is].Step&&action);
  		}
	
	// Adc
	P.Action.StopAdc=((P.Power.Power)&&P.Action.MoveStep[P.Power.Step]);
		
   	// Wait Step
   	for(is=0;is<MAX_STEP;is++)
		P.Action.WaitStep[is]=(P.Action.MoveStep[is]&&(P.Step[is].Mode==STEP_MULTI));
		
	// Start Cont 
   	for(is=0;is<MAX_STEP;is++){
   		if(P.Step[is].Step)
			switch (P.Loop[P.Step[is].Loop].Cont) {
				case CONT_NONE: action=FALSE; break;
				case CONT_STEP: action=new[P.Step[is].Loop]; break;
				case CONT_RANGE: action=first[P.Step[is].Loop]; break;
				}
		else action=FALSE;
  		P.Action.StartCont[is]=(P.Step[is].Step&&action);
  		}
	
	// Wait Cont 
   	for(is=0;is<MAX_STEP;is++){
   		if(P.Step[is].Step)
			switch (P.Loop[P.Step[is].Loop].Cont) {
				case CONT_NONE: action=FALSE; break;
				case CONT_STEP: action=old[P.Step[is].Loop]; break;
				case CONT_RANGE: action=last[P.Step[is].Loop]; break;
				}
		else action=FALSE;
  		P.Action.WaitCont[is]=(P.Step[is].Step&&action);
  		}
	
   	// Trim
   	for(it=0;it<MAX_TRIM;it++)
   		if(!P.Trim[it].Trim) P.Action.Trim[it]=FALSE;
		else P.Action.Trim[it]=(new[P.Step[P.Trim[it].Step].Loop]&&P.Trim[it].Trim);

/*   	for(it=0;it<MAX_TRIM;it++){
   		if(!P.Trim[it].Trim) action=FALSE;
		else{
			loop=P.Step[P.Trim[it].Step].Loop;
			switch (P.Trim[it].Type) {
				case ONLY_FIRST: action=first[loop]; break;
				case ONLY_SEC:
					action=second[loop];
					if(loop>1){
						P.Action.MoveStep[P.Trim[it].Step]=FALSE;
						P.Action.WaitStep[P.Trim[it].Step]=FALSE;
						}
					break;
				default: action=new[loop]; break;
				}
			}
		}
*/
	// Break
	for(il=0;il<MAX_LOOP;il++){
		isbreak=FALSE;
		if((strlen(P.Loop[il].FName)!=0)&&P.Loop[il].Break){ 
			for(ie=0;ie<P.Loop[il].ExceptNum;ie++)
				if(P.Loop[il].ExceptLabel[ie]==(P.Loop[il].First+P.Loop[il].Actual*P.Loop[il].Delta)) isbreak=P.Loop[il].ExceptValue[ie];
			}
		else isbreak=P.Loop[il].Break;
		P.Action.Break[il]=(new[il]&&isbreak);
		}
	if(P.Action.Break[LOOP1]==TRUE){
		P.Action.Break[LOOP2]=FALSE;
		P.Action.Break[LOOP3]=FALSE;
		}
	if(P.Action.Break[LOOP2]==TRUE)
		P.Action.Break[LOOP3]=FALSE;

	// WaitChrono
	action = first2;
	P.Action.WaitChrono = (action&&P.Chrono.Chrono);
	
	// Spc Reset
	P.Action.SpcReset=TRUE;
	
	// Spc Stop
	P.Action.SpcStop=(last1||P.Meas.Stop);
	
	// Spc Out
	P.Action.SpcOut=TRUE;

	// Data Save
   	P.Action.DataSave=(REMINDER(index,P.Ram.Loop)==0);
		
	// Status
    if(P.Meas.Status==0) P.Action.DisplayStatus=FALSE;
   	else P.Action.DisplayStatus=(REMINDER(index,P.Meas.Status)==0);
 	
 	// DisplayPlot
    if(P.Meas.Plot==0) P.Action.DisplayPlot=FALSE;
   	else P.Action.DisplayPlot=(REMINDER(index,P.Meas.Plot)==0);
	
 	// DisplayRoi
    if(P.Meas.Roi==0) P.Action.DisplayRoi=FALSE;
   	else P.Action.DisplayRoi=(REMINDER(index,P.Meas.Roi)==0);
	
	// Wait End 
	P.Action.WaitEnd= TRUE;
	if(P.Action.StopSync&&(P.Sync.Dir==SYNC_INPUT)&&(P.Sync.Pattern==SYNC_ONE)) P.Action.WaitEnd=FALSE;
	
	// New Frame
	//P.Action.NewFrame = (P.Acq.Actual==P.Acq.Frame);
	
	// Oma
	P.Action.StartOma = (P.Oma.Oma&&new[P.Oma.Loop]);
	P.Action.StopOma = (P.Oma.Oma&&old[P.Oma.Loop]);
	
	// Ophir
	if(P.Ophir.Ophir) P.Action.Ophir = new[P.Ophir.Loop];
	else P.Action.Ophir = FALSE;
	}


/* RESTORE INITIAL CONDITIONS */
void CloseMeasure(void){
	char isw,is,it;
	SpcClose();
	for(isw=0;isw<MAX_SWITCH;isw++)
		if(P.Switch[isw].Switch) MoveSwitch(P.Switch[isw].Home,isw);
	for(is=MAX_STEP-1;is>=0;is--)
		if(P.Step[is].Step) MoveStep(&P.Step[is].Actual,P.Step[is].Home,is,TRUE,TRUE);
//	for(is=0;is<MAX_STEP;is++)
//		if(P.Step[is].Step&&(P.Step[is].Mode!=STEP_SINGLE)) WaitStep(&P.Step[is].Actual,P.Step[is].Home,is,TRUE);
	Delay(1.0);
	//**if(P.Mamm.Mamm) MoveStep(&P.Step[P.Mamm.Step[Y]].Actual,P.Step[P.Mamm.Step[Y]].Actual+(long)(-1*1*P.Step[P.Mamm.Step[Y]].Factor),P.Mamm.Step[Y],WAIT_TRUE,FALSE);
	
	for(isw=0;isw<MAX_SWITCH;isw++)
		if(P.Switch[isw].Switch) CloseSwitch(isw);
	for(is=0;is<MAX_STEP;is++)
		if(P.Step[is].Step) CloseStep(is);
	for(it=0;it<MAX_TRIM;it++)
		if(P.Trim[it].Trim) SaveTrim(it);
		
// TODO: CHECK FOR P.Meas:Ram==0 in MAMM		
/*	if(P.Mamm.Mamm&&(P.Meas.Ram==0)){ //datasave
		P.File.File = fopen (P.File.Path, "ab");
		fwrite(DataRam0, sizeof(long),P.Mamm.Idx[X].Num*P.Mamm.Idx[Y].Num*P.Num.Board*P.Chann.Num,P.File.File);
		fclose(P.File.File);
		free(DataRam0);
		}*/
	}


/* INITIALIZE MEMORY */
void InitMem(void){
	SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "Initializing Memory ... ");
	
	D.Osc=DAlloc2D(P.Num.Board*P.Num.Det,P.Chann.Num); 
	D.Buffer=DAlloc2D(P.Num.Board,P.Num.Det*P.Chann.Num); 
	if(P.Spc.Subtract) D.Last=DAlloc1D(P.Chann.Num); 
	
	if(P.Contest.Run!=CONTEST_MEAS){ Passed(); return;}
	
	if(P.Moxy.Moxy) D.Bank=DAlloc2D(P.Num.Board,SPC_BANK_DIM); 
	if(P.Info.SubHeader) D.Sub=SAlloc2D(P.Frame.Num,P.Num.Page);
	D.Data=DAlloc3D(P.Frame.Num,P.Num.Page,P.Chann.Num); 
	
	Passed();
	}


/* CLOSE MEMORY */
void CloseMem(void){
	DFree2D(D.Osc,P.Num.Board*P.Num.Det); 
	DFree2D(D.Buffer,P.Num.Board); 
	if(P.Spc.Subtract) DFree1D(D.Last); 
	
	if(P.Contest.Run!=CONTEST_MEAS) return;
	
	if(P.Moxy.Moxy) DFree2D(D.Bank,P.Num.Board); 
	if(P.Info.SubHeader) SFree2D(D.Sub,P.Frame.Num);
	DFree3D(D.Data,P.Frame.Num,P.Num.Page); 
	}


/* COMPLETE STRUCTURE PARM */
void CompleteParmS(void){  
	int  is,isw,il,it,ir,ips,ipp,nb;
    int LoopFactorTot;
    int NumBlock=0;
    char loopX, loopY;
	int fiber,page;
	char *string;
    		   
   	// Presentation
   	if (P.Presentation.Flag == TRUE) {
   		ips=0;  
   		while ((P.TBlock.Num[ips]!=0) && (ips<MAX_ROW_PRES_BLOCK)) {
   			if (ips==0){
   				ipp=0;
   				NumBlock=0;
	   			}
   			else { 
   				if (P.TBlock.Num[ips]!=P.TBlock.Num[ips-1]) {
   					P.BlockObj[NumBlock].LengthPart[ipp]=END_LENGTH_POINTER;
   					NumBlock++;
   					ipp=0;
	   				}
   				}
   			P.BlockObj[NumBlock].Num=P.TBlock.Num[ips];
   			P.BlockObj[NumBlock].TypePart[ipp]=P.TBlock.Type[ips]; 
   			P.BlockObj[NumBlock].LengthPart[ipp]=P.TBlock.StopFrame[ips]-P.TBlock.StartFrame[ips];
   			P.BlockObj[NumBlock].Param1[ipp][0]=P.TBlock.Param1[ips][0]; 
   			P.BlockObj[NumBlock].Param2[ipp]=P.TBlock.Param2[ips];
   			P.BlockObj[NumBlock].Param3[ipp]=P.TBlock.Param3[ips];
   			ipp++;
   			ips++;	
	   		}
   		NumBlock++;
   		
   		for (nb=0;nb<NumBlock;nb++){
   			P.BlockObj[nb].ActualRepetition=0;
   			}
   		for (nb=0;nb<NumBlock;nb++) {
   			ipp=0;
   			P.BlockObj[nb].Length=0;
   			while (P.BlockObj[nb].LengthPart[ipp]!=END_LENGTH_POINTER) {
   				P.BlockObj[nb].Length=P.BlockObj[nb].Length+P.BlockObj[nb].LengthPart[ipp];
   				ipp++;
   				}
   			}
   		ips=0;
   		P.TSequence.FrameTot=0;
   		while ((P.TSequence.BlockUsed[ips]!=0) && (ips<MAX_ROW_PRES_BLOCK)) {
   			for (nb=0;nb<NumBlock;nb++) {
   				if (P.TSequence.BlockUsed[ips]==P.BlockObj[nb].Num) {
   					P.TSequence.FrameTot=P.TSequence.FrameTot+(P.TSequence.Repeat[ips]*P.BlockObj[nb].Length);
   					}
   				}
   			ips++;
   			}
   		if (P.TPartition.Align==TRUE) {
   			LoopFactorTot=1; 	
   			for (il=0;il<MAX_LOOP;il++) {
   				LoopFactorTot=LoopFactorTot*P.TPartition.LoopFactor[il];
   				}
   			if (P.TSequence.FrameTot!=LoopFactorTot) {
   				for (il=0;il<MAX_LOOP;il++) {
   					if (il==LOOP3) P.TPartition.LoopFactor[il]=P.TSequence.FrameTot;
   					else P.TPartition.LoopFactor[il]=1;
   					}
   				}
   			for (il=0;il<MAX_LOOP;il++) {
   				P.Loop[il].Home=0;		  // ALE + DAV
   				P.Loop[il].First=0;
   				P.Loop[il].Delta=0;		  // ALE + DAV
   				if (P.TPartition.LoopFactor[il]==0) P.Loop[il].Last=P.TPartition.LoopFactor[il];
   				else P.Loop[il].Last=P.TPartition.LoopFactor[il]-1;
   				}
   			}
   		}
   	
   	// Contest
   	
    // Command
    P.Command.Abort=FALSE;
    
    // File
    MakePath();
    SetCtrlVal (hParm, PARM_FILE_TAG, P.File.Tag);
    
    // Wait
    P.Wait.Step=0;
    if(P.Wait.Type==WAIT_POS)
    	for(is=MAX_STEP-1;is>=0;is--)
    		if(P.Step[is].Step&&(P.Loop[P.Step[is].Loop].Cont!=NONE)&&(P.Step[is].Mode==STEP_CONT)) P.Wait.Step=is;
    
    // Step
    for(is=0;is<MAX_STEP;is++){
    	if((P.Step[is].Type==NONE)||(P.Step[is].Loop==LOOP_NONE)) P.Step[is].Step=FALSE;
    	else{
    		sprintf(P.Step[is].FPath,"%s\\%s%s",DIRFILEPOS,P.Step[is].FName,EXTFILEPOS);
	  		P.Step[is].Step=TRUE;
			P.Step[is].Speed=FAST;
			if(P.Step[is].Freq>P.Step[is].FreqMax) P.Step[is].Freq=P.Step[is].FreqMax;
		 	}
		}
	
	// Switch
    for(isw=0;isw<MAX_SWITCH;isw++){
    	if( (P.Switch[isw].Switch) && (P.Switch[isw].Loop!=LOOP_NONE) && (P.Switch[isw].Device!=NONE)) {
    	sprintf(P.Switch[isw].FPath,"%s\\%s%s",DIRFILEPOS,P.Switch[isw].FName,EXTFILEPOS);}
		else P.Switch[isw].Switch=FALSE;
		}

    // Loop
   	for(il=0;il<MAX_LOOP;il++){
   		P.Loop[il].Delta=abs(P.Loop[il].Delta);
   		if(P.Loop[il].Delta==0) P.Loop[il].Delta=1;
   		P.Loop[il].Delta*=((P.Loop[il].First<=P.Loop[il].Last)?1:-1);
		P.Loop[il].Num=abs((P.Loop[il].Last-P.Loop[il].First)/P.Loop[il].Delta)+1;
		if(P.Loop[il].Cont==CONT_RANGE) P.Loop[il].Num-=1;
		sprintf(P.Loop[il].FPath,"%s\\%s%s",DIRFILEBREAK,P.Loop[il].FName,EXTFILEBREAK);
		}

	// Mamm
	//sta = GetCtrlVal (hMamm, MAMM_MAMM, &mammval);
	if (P.Info.Appl==APPL_MAMM){
		P.Mamm.Mamm=TRUE;
		loopX=P.Mamm.Loop[X];
		loopY=P.Mamm.Loop[Y];
		P.Mamm.Idx[X].Home=(P.Loop[loopX].Home-P.Loop[loopX].First)/P.Loop[loopX].Delta;
		P.Mamm.Idx[Y].Home=(P.Loop[loopY].Home-P.Loop[loopY].First)/P.Loop[loopY].Delta;
		P.Mamm.Idx[X].Actual=P.Mamm.Idx[X].Home;
		P.Mamm.Idx[Y].Actual=P.Mamm.Idx[Y].Home;
		P.Mamm.Idx[X].Num=P.Loop[loopX].Num;
		P.Mamm.Idx[Y].Num=P.Loop[loopY].Num;
//**		P.Spc.TimeM=P.Loop[loopX].Delta*P.Step[P.Mamm.Step[X]].Factor/P.Step[P.Mamm.Step[X]].Freq;
//**    	SetCtrlVal (hParm, PARM_SPC_TIME, P.Spc.TimeM);
//		for(ib=0;ib<MAMM_NUM_BOARD;ib++){
//			P.Mamm.Count.High[ib]=(long)(P.Mamm.Count.HighU[ib]*P.Spc.TimeM);	// to set after P.Spc.Time
//			P.Mamm.Count.Mid[ib]=(long)(P.Mamm.Count.MidU[ib]*P.Spc.TimeM);	// to set after P.Spc.Time
//			P.Mamm.Count.Low[ib]=(long)(P.Mamm.Count.LowU[ib]*P.Spc.TimeM);	// to set after P.Spc.Time
//			}
		}
	else P.Mamm.Mamm=FALSE;

	// Spc
	switch (P.Spc.Type) {
		case NONE:P.Spc.Calib=10.0;break;    
		case VARRO:P.Spc.Calib=CALIB_VARRO;break;
		case SPC300:P.Spc.Calib=CALIB_SPC300;break; 
	//	case SILENA:P.Spc.Calib=CALIB_SILENA;break; 
		case THARP:break;
		case SPC630:P.Spc.Calib=CALIB_SPC630;break;
		case SPC130:P.Spc.Calib=CALIB_SPC130;break;
		case TEST:P.Spc.Calib=TEST_CALIB;
		}
	if (P.Spc.Type==SPC130) {
		if(P.Num.Board>0) MakePathname (DIR_INI, SPC130_1_INI_FILE, P.Spc.Settings[0]);
		if(P.Num.Board>1) MakePathname (DIR_INI, SPC130_2_INI_FILE, P.Spc.Settings[1]);
		if(P.Num.Board>2) MakePathname (DIR_INI, SPC130_3_INI_FILE, P.Spc.Settings[2]);
		if(P.Num.Board>3) MakePathname (DIR_INI, SPC130_4_INI_FILE, P.Spc.Settings[3]);
		}
	if (P.Spc.Type==SPC300) MakePathname (DIR_INI, SPC300_INI_FILE, P.Spc.Settings[0]);
	if (P.Spc.Type==SPC630) MakePathname (DIR_INI, SPC630_INI_FILE, P.Spc.Settings[0]);
	if (P.Spc.Type==THARP) MakePathname (DIR_INI, THARP_INI_FILE, P.Spc.Settings[0]);
	
	if ((P.Spc.Type==SPC630)||(P.Spc.Type==SPC130))
		 P.Spc.Factor=P.Spc.Calib/P.Spc.Scale;
	else
		P.Spc.Factor = P.Spc.Calib*P.Spc.Scale; 
    
    P.Chann.Num = P.Chann.Last-P.Chann.First+1;
	P.Spc.Started=FALSE;
	P.Spc.Trash=TRUE;
	if((P.Spc.Type==SPC300)||(P.Spc.Type==SPC630)||(P.Spc.Type==SPC130)) P.Meas.Stop=TRUE;
	if((P.Spc.Type==SPC300)||(P.Spc.Type==SPC630)||(P.Spc.Type==SPC130)||(P.Spc.Type==TEST)) P.Spc.Format=SPC_SHORT;
	else P.Spc.Format=SPC_LONG;
	P.Spc.Subtract=(P.Meas.Stop?FALSE:TRUE);

    P.Oscill.Zoom.Last=MIN(P.Oscill.Zoom.Last,P.Chann.Num-1);
    P.Oscill.Zoom.First=MAX(P.Oscill.Zoom.First,0);
    if(P.Oscill.Zoom.Last==0) P.Oscill.Zoom.Last=P.Chann.Num-1;
    for(ir=0;ir<MAX_ROW_OSCILL;ir++){
    	P.Oscill.Last[ir]=MIN(P.Oscill.Last[ir],P.Chann.Num-1);
    	P.Oscill.First[ir]=MAX(P.Oscill.First[ir],0);
    	}

	// Detector
	P.Num.Det = 1;
	for(ir=0;ir<P.Spc.RoutingBits;ir++) P.Num.Det*=2;
	
	// Filter-Page-Acq
	P.Acq.Frame=1; //TODO: sistemare per Oxym+Spectra..
	if(P.Layout.Layout){
		P.Num.Prot=0;
		for(ir=0;ir<MAX_ROW_PROT;ir++)
			if(P.Acq.Frame<=P.TProt.AcqStop[ir]){
				P.Acq.Frame=P.TProt.AcqStop[ir];
				P.Num.Prot=ir+1;
				}
		}
	if(P.Info.Appl==APPL_MOXY) P.Num.LoopxFrame=1;
	else P.Num.LoopxFrame=P.Acq.Frame;
	P.Acq.Actual=0;
	P.Acq.Tot=P.Acq.Frame*(P.Loop[LOOP1].Num*P.Loop[LOOP2].Num*P.Loop[LOOP3].Num)/P.Num.LoopxFrame;
	P.Acq.Counter=0;
	P.Acq.Bank=SPC_BANK_DIM/(P.Chann.Num*P.Num.Det);

	
	// Ram
	if(P.Meas.Ram==0) P.Ram.Loop=P.Loop[LOOP1].Num*P.Loop[LOOP2].Num*P.Loop[LOOP3].Num;
	else P.Ram.Loop = MAX(P.Meas.Ram,P.Num.LoopxFrame);
	P.Ram.Num = (P.Loop[LOOP1].Num*P.Loop[LOOP2].Num*P.Loop[LOOP3].Num)/P.Ram.Loop;
	P.Ram.Actual=0;
	
	// Frame
	P.Frame.Num = CEIL(P.Ram.Loop,P.Num.LoopxFrame);
	if (P.Info.Appl==APPL_MAMM) P.Frame.Num = P.Loop[LOOP3].Num;
	P.Frame.Actual = 0;
	
	// Moxy
	P.Moxy.Moxy = (P.Info.Appl==APPL_MOXY);
	P.Moxy.TimeMic = (int)(SEC_TO_MICROSEC*P.Spc.TimeM/P.Acq.Frame);
	P.Moxy.TimeSpc = (float) P.Spc.TimeM/P.Acq.Frame*(1-MOXY_OVERHEAD);
	
	// Fiber
	if(!P.Layout.Layout) P.Num.Fiber=P.Num.Board*P.Num.Det;
	else P.Num.Fiber=MAX_FIBER;

	// Source													//ALE
	if(!P.Layout.Layout) P.Num.Source=P.Num.Board*P.Num.Det;	//ALE
	else P.Num.Source=MAX_SOURCE;								//ALE
	
	// Chrono
	P.Chrono.Chrono = (P.Chrono.Delta>0);
    
    
	// Oma
	P.Oma.Oma=(P.Oma.Loop==OMA_NONE?FALSE:TRUE);
	
	// Ophir
	P.Ophir.Ophir=(P.Ophir.Loop==OPHIR_NONE?FALSE:TRUE);
	
	// Power
	P.Power.Power=(P.Power.Step!=NEG);
	if(P.Power.Power) P.Power.Loop=P.Step[P.Power.Step].Loop;
			
	// NumPage 
	page=0;
	if(!P.Layout.Layout) P.Num.Page=P.Acq.Frame*P.Num.Board*P.Num.Det;
	else{
		for(ir=0;ir<MAX_ROW_PROT;ir++){
			string = P.TProt.Fibers[ir];
			strcat(string,",");
			while((strlen(string)>1)&&(sscanf(string,"%d",&fiber)!=EOF)){
				switch (fiber){
					case -1: page+=0; break;
					case 0: page+=P.Num.Fiber; break;
					default: page+=1; break;
					}
				string += 1+FindPattern (string,0,-1,",",1,0);
				}
			string = P.TProt.Fibers[ir];
			string[strlen(string)-1]='\0'; // delete last ',' from the UIR string
			}
		P.Num.Page=page;
		}

	// Roi
	for(ir=0;ir<MAX_ROW_ROI;ir++) P.Roi.Lambda[ir]=0.0; //TODO: UIR
	for(ir=0;ir<MAX_ROW_ROI;ir++) P.Roi.Rho[ir]=0.0; //TODO: UIR
	if(P.Roi.Window==WINDOW_REF)
		for(ip=0;ip<MAX_ROW_ROI;ip++){ 
			P.Roi.Page[ip]=ip;
			P.Roi.First[ip]=P.Oscill.First[0];
			P.Roi.Last[ip]=P.Oscill.Last[0];
			P.Roi.Fract[ip]=P.Oscill.Fract[0];
			}
	if(P.Roi.Window==WINDOW_SIG)
		for(ip=0;ip<MAX_ROW_ROI;ip++){ 
			P.Roi.Page[ip]=ip;
			P.Roi.First[ip]=P.Oscill.First[1];
			P.Roi.Last[ip]=P.Oscill.Last[1];
			P.Roi.Fract[ip]=P.Oscill.Fract[1];
			}
	if(P.Roi.Window==WINDOW_REFs_SIGs)
		for(ir=0;ir<MAX_ROW_OSCILL;ir++)
			for(ip=0;ip<MAX_ROW_ROI/2;ip++){ 
				P.Roi.Page[ip+ir*MAX_ROW_ROI/2]=ip;
				P.Roi.First[ip+ir*MAX_ROW_ROI/2]=P.Oscill.First[ir];
				P.Roi.Last[ip+ir*MAX_ROW_ROI/2]=P.Oscill.Last[ir];
				P.Roi.Fract[ip+ir*MAX_ROW_ROI/2]=P.Oscill.Fract[ir];
				}
	if(P.Roi.Window==WINDOW_REFSIG_)
		for(ip=0;ip<MAX_ROW_ROI/2;ip++) 
			for(ir=0;ir<MAX_ROW_OSCILL;ir++){
				P.Roi.Page[2*ip+ir]=ip;
				P.Roi.First[2*ip+ir]=P.Oscill.First[ir];
				P.Roi.Last[2*ip+ir]=P.Oscill.Last[ir];
				P.Roi.Fract[2*ip+ir]=P.Oscill.Fract[ir];
				}
				
	for(ip=0;ip<MAX_ROW_ROI;ip++){
		P.Roi.RoiM[ip]=FALSE;
		P.Roi.RoiO[ip]=FALSE;
		}

	if(P.Roi.Window==WINDOW_REFs_SIGs){
		for(ip=0;ip<MIN(MAX_ROW_ROI/2,P.Num.Board*P.Num.Det);ip++){
			P.Roi.RoiO[ip]=TRUE;
			P.Roi.RoiO[ip+MAX_ROW_ROI/2]=TRUE;
			}
		for(ip=0;ip<MIN(MAX_ROW_ROI/2,P.Num.Page);ip++){
			P.Roi.RoiM[ip]=TRUE;
			P.Roi.RoiM[ip+MAX_ROW_ROI/2]=TRUE;
			}
		}
	else if(P.Roi.Window==WINDOW_REFSIG_){
		for(ip=0;ip<MIN(MAX_ROW_ROI,2*P.Num.Board*P.Num.Det);ip++)
			P.Roi.RoiO[ip]=TRUE;
		for(ip=0;ip<MIN(MAX_ROW_ROI,2*P.Num.Page);ip++)
			P.Roi.RoiM[ip]=TRUE;
		}
	else if(P.Roi.Window==WINDOW_MANUAL){
		for(ip=0;ip<MAX_ROW_ROI;ip++)
			if(P.Roi.Page[ip]>=0){
			P.Roi.RoiO[ip]=TRUE;
			P.Roi.RoiM[ip]=TRUE;
			}
		}
	else{
		for(ip=0;ip<MIN(MAX_ROW_ROI,P.Num.Board*P.Num.Det);ip++)
			P.Roi.RoiO[ip]=TRUE;
		for(ip=0;ip<MIN(MAX_ROW_ROI,P.Num.Page);ip++)
			P.Roi.RoiM[ip]=TRUE;
		}

	if (P.Info.Appl==APPL_MAMM) 
		for(il=0; il<MAMM_NUM_LAMBDA ;il++)
			P.Roi.Lambda[il] = P.Mamm.Lambda[il];

	// Plot
	P.Plot.NumM = MIN(MAX_PLOT,P.Num.Page);
	P.Plot.NumO = MIN(MAX_PLOT,P.Num.Board*P.Num.Det);
	
    // Trim (dopo Roi)
    for (it=0;it<MAX_TRIM;it++){
    	if(P.Trim[it].Step==-1) P.Trim[it].Trim=FALSE;
    	else{
    		P.Trim[it].Trim=TRUE;
        	P.Trim[it].Loop=P.Step[P.Trim[it].Step].Loop;
        	P.Trim[it].Delta=(long)(P.Trim[it].DeltaU*P.Step[P.Trim[it].Step].Factor);
        	P.Trim[it].Roi.First=P.Roi.First[P.Trim[it].Region];
       		P.Trim[it].Roi.Last=P.Roi.Last[P.Trim[it].Region];
			}
		}
		
	}


/* WRITE FILE PATH */	
void MakePath(void) {   
	char tagzero[128];
	NewItoa(P.File.Tag,tagzero,NUMZERO);
    sprintf(P.File.Name,"%s%s",P.File.Prefix,tagzero);
	sprintf(P.File.Path, "%s\\%s.%s",P.File.Dir,P.File.Name,P.File.Ext);
	}   

/* ########################   PRESENTATION PROCEDURES   ########################### */

// WRITE STIMULI SEQUENCE
void InitPres(void) {
	int *BufferSequenceActual;
	int *BufferSequence;
	int *AbsoluteTime;
	int *Block;
	int *BlockActual;
	int *Repeat;
	int *RepeatActual;
	int *BaseLine;
	int *BaseLineActual;
	int *Task;
	int *TaskActual;
	int *Recovery;
	int *RecoveryActual;
	char *Param1;
	int *Param2,*Param3;
	char *Param1Actual;
	int *Param2Actual,*Param3Actual;
	int *RelativeTime;
	int *RelativeTimeActual;
	int ret,ipt,ipr,ips,ipb,ipl,ipc,counter,seed1,seed2,seed3;
	int TaskNum,swap,flag;
	int BlockUsedActual=0;
	double RandomPosition;
	char StimuliFileName[2*STRLEN],PresentationFileName[2*STRLEN];
	FILE *StimuliFile,*PresentationFile;
	
	if (!P.Presentation.Flag) return;
	SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "Initializing Presentation ... "); 
	
	BufferSequence = calloc (P.TSequence.FrameTot, sizeof(*BufferSequence));
	Block = calloc (P.TSequence.FrameTot, sizeof(*Block));
	AbsoluteTime = calloc (P.TSequence.FrameTot, sizeof(*AbsoluteTime));
	Repeat = calloc (P.TSequence.FrameTot, sizeof(*Repeat));
	BaseLine = calloc (P.TSequence.FrameTot, sizeof(*BaseLine));
	Task = calloc (P.TSequence.FrameTot, sizeof(*Task));
	Recovery = calloc (P.TSequence.FrameTot, sizeof(*Recovery));
	RelativeTime = calloc (P.TSequence.FrameTot, sizeof(*RelativeTime));
	Param1 = calloc (P.TSequence.FrameTot+1, sizeof(*Param1));
	Param2 = calloc (P.TSequence.FrameTot, sizeof(*Param2));
	Param3 = calloc (P.TSequence.FrameTot, sizeof(*Param3));
	
	ipt=0;TaskNum=0;
	BufferSequenceActual=BufferSequence;
	while ((P.TSequence.BlockUsed[ipt]!=0) && (ipt<MAX_ROW_PRES_BLOCK)) {
		for (ipr=0;ipr<P.TSequence.Repeat[ipt];ipr++) {
			*BufferSequenceActual=P.TSequence.BlockUsed[ipt];
			BufferSequenceActual++;
			TaskNum++;
			}
		ipt++;
		}	
	
	if (P.TSequence.Shuffle) {
		ret = GetSystemTime (&seed1, &seed2, &seed3);
		ret=WhiteNoise(1,(double)(TaskNum-1), (seed1*seed2*seed3), &RandomPosition);
		for (ipc=0;ipc<seed1+seed2*seed3;ipc++) {
			for (ips=0;ips<TaskNum;ips++) { 
				ret=WhiteNoise(1,(double)(TaskNum-1), -1, &RandomPosition);
				swap=*(BufferSequence+ips);
				*(BufferSequence+ips)=*(BufferSequence+(int)abs(TruncateRealNumber(RandomPosition)));
				*(BufferSequence+(int)abs(TruncateRealNumber(RandomPosition)))=swap;
				}
			}	
		}
	
	BlockActual=Block;
	RepeatActual=Repeat;
	RelativeTimeActual=RelativeTime;
	BaseLineActual=BaseLine;
	TaskActual=Task;
	RecoveryActual=Recovery;
	Param1Actual=Param1;
	Param2Actual=Param2;
	Param3Actual=Param3;
	for (ips=0;ips<TaskNum;ips++) {
		flag=FALSE;
		for (ipb=0;(ipb<MAX_ROW_PRES_BLOCK) && (flag==FALSE);ipb++) {
			if ((*(BufferSequence+ips))==P.BlockObj[ipb].Num) {
				flag=TRUE;
				BlockUsedActual=ipb;
				P.BlockObj[BlockUsedActual].ActualRepetition++;
				}
			}
		counter=0;ipl=0;
		for (ipt=0;ipt<P.BlockObj[BlockUsedActual].Length;ipt++) {
			*BlockActual=P.BlockObj[BlockUsedActual].Num;
			*RepeatActual=P.BlockObj[BlockUsedActual].ActualRepetition;
			*RelativeTimeActual=ipt;
			if (ipl==P.BlockObj[BlockUsedActual].LengthPart[counter]) {
				ipl=0;							   
				counter++;
				}		
			switch (P.BlockObj[BlockUsedActual].TypePart[counter]) {
				case BASELINE_CONST:*BaseLineActual=1;
									*TaskActual=0;
									*RecoveryActual=0;
									*Param1Actual=P.BlockObj[BlockUsedActual].Param1[counter][0];
									*Param2Actual=P.BlockObj[BlockUsedActual].Param2[counter];
									*Param3Actual=P.BlockObj[BlockUsedActual].Param3[counter];
									break;
				case TASK_CONST:	*BaseLineActual=0;
									*TaskActual=1;
									*RecoveryActual=0;
									*Param1Actual=P.BlockObj[BlockUsedActual].Param1[counter][0];
									*Param2Actual=P.BlockObj[BlockUsedActual].Param2[counter];
									*Param3Actual=P.BlockObj[BlockUsedActual].Param3[counter];
									break;
				case RECOVERY_CONST:*BaseLineActual=0;
									*TaskActual=0;
									*RecoveryActual=1;
									*Param1Actual=P.BlockObj[BlockUsedActual].Param1[counter][0];
									*Param2Actual=P.BlockObj[BlockUsedActual].Param2[counter];
									*Param3Actual=P.BlockObj[BlockUsedActual].Param3[counter];
									break;
				default: break;
				}
			BlockActual++;
			RepeatActual++;
			RelativeTimeActual++;     
			BaseLineActual++;
			TaskActual++;
			RecoveryActual++;
			Param1Actual++;
			Param2Actual++;
			Param3Actual++;
			ipl++;		
			}
		}
	
	for (ips=0;ips<P.TSequence.FrameTot;ips++) {
		*(AbsoluteTime+ips)=ips;
		}
	
	sprintf(StimuliFileName,"%s\\%s", P.Presentation.FStimuliDir, P.Presentation.FStimuliName);
	sprintf(PresentationFileName,"%s\\%s", P.Presentation.FInitPresentationDir, P.Presentation.FInitPresentationName);
	StimuliFile = fopen (StimuliFileName, "w");
	PresentationFile = fopen (PresentationFileName, "w");
	fprintf (StimuliFile,"AbsTime\tType\tRepeat\tBaseL\tTask\tRecov\tRelTime\tParam1\tParam2\tParam3\n");
	for (ips=0;ips<P.TSequence.FrameTot;ips++) {
		fprintf (StimuliFile,"%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",*(AbsoluteTime+ips),*(Block+ips),*(Repeat+ips),
				 *(BaseLine+ips),*(Task+ips),*(Recovery+ips),*(RelativeTime+ips),(int)(*(Param1+ips)),*(Param2+ips),*(Param3+ips));
		fprintf (PresentationFile,"%c\t%d\t%d\n",*(Param1+ips),*(Param2+ips),*(Param3+ips));
		}
	fprintf (PresentationFile,"#\t#\t#\n");
	fclose(StimuliFile);
	fclose(PresentationFile);
	
	free(BufferSequence); 
	free(Block); 
	free(AbsoluteTime); 
	free(Repeat); 
	free(BaseLine); 
	free(Task); 
	free(Recovery); 
	free(RelativeTime); 
	free(Param1); 
	free(Param2); 
	free(Param3);
	Passed();
	}	
	
/* ########################   PROTOCOL PROCEDURES   ########################### */

// WRITE FIBER ARRAY
void InitFiber(void){
	int ir,ib,id,iff,fiber;
	char *string;
	int num_rows=0;
	for(iff=0;iff<MAX_FIBER;iff++)
		P.Fiber[iff].Fiber=FALSE;
	if(!P.Layout.Layout)
		for(ib=0;ib<P.Num.Board;ib++)
			for(id=0;id<P.Num.Det;id++){
				P.Fiber[ib*P.Num.Det+id].Board=ib;
				P.Fiber[ib*P.Num.Det+id].Det=id;
				P.Fiber[ib*P.Num.Det+id].Fiber=TRUE;
				}
	else{
		for(ir=0;ir<MAX_ROW_FIBER;ir++)
			if(strlen(P.TFiber.Fibers[ir])>0) num_rows++;
		for(ir=0;ir<num_rows;ir++){
			string=P.TFiber.Fibers[ir];
			strcat(string,",");
			while(sscanf(string,"%d",&fiber)!=EOF){
				P.Fiber[fiber-1].Board=P.TFiber.Board[ir]-1;
				P.Fiber[fiber-1].Det=P.TFiber.Det[ir]-1;
				P.Fiber[fiber-1].Fiber=TRUE;
				string += 1+FindPattern (string,0,-1,",",1,0);
				}
			P.TFiber.Fibers[ir][strlen(P.TFiber.Fibers[ir])-1]='\0';
			}
		}
	}
	

// WRITE GEOM ON FIBER AND SOURCES			
void InitGeom(void){
	int fi,si;
	void *ptr = 0; //ALE
	
	if(strlen(P.Layout.FGeometry)==0){
		for(fi=0;fi<P.Num.Fiber;fi++){
			P.Fiber[fi].Coord=GEOM_COORD_CART;
			P.Fiber[fi].Pad=1;
			P.Fiber[fi].Xf=P.Const.Rho;
			P.Fiber[fi].Yf=0;
			P.Fiber[fi].Zf=0;
			P.Fiber[fi].Rf=0;
			P.Fiber[fi].Nf=0;
			}
		for(si=0;si<1;si++){
			P.Source[si].Coord=GEOM_COORD_CART;
			P.Source[si].Pad=1;
			P.Source[si].Xs=0;
			P.Source[si].Ys=0;
			P.Source[si].Zs=0;
			P.Source[si].Rs=0;
			P.Source[si].Ns=0;
			}
		}
	else
		LoadGeom (hGeom, GEOMETRY_LOAD_GEO,EVENT_COMMIT,ptr,0,0);	//ALE 
	}

	
// WRITE SOURCE ARRAY
void InitSource(void){
	int ir,sourceU;
	int nums;																//ALE
	if(!P.Layout.Layout) return;
	for(ir=0;ir<MAX_ROW_SOURCE;ir++){
		sourceU=P.TSource.Source[ir];
		if(sourceU>0) P.Source[sourceU-1].Switch=P.TSource.Switch[ir]-1;
		if(sourceU>0) P.Source[sourceU-1].Chann=P.TSource.Chann[ir]-1;
		}
	nums = 0;
	for(ir=0;ir<MAX_ROW_SOURCE;ir++){										//ALE
		sourceU=P.TSource.Source[ir];										//ALE
		if(sourceU>0) nums++;												//ALE
		}																	//ALE
	P.Num.Source = nums;													//ALE
	}
	
// WRITE FILTER ARRAY
void InitFilter(void){
	int ir,ia,ib,id,iff,f1,f2;
	int source, fiber, count_fiber;
	char *string;

	// NOTE: part of this procedure is set in the CompleteParm to calculate P.Num.Page
	int page=0;
	if(!P.Layout.Layout){
		for(ia=0;ia<P.Acq.Frame;ia++)
			for(ib=0;ib<P.Num.Board;ib++)
				for(id=0;id<P.Num.Det;id++){
					page=ia*P.Num.Board*P.Num.Det+ib*P.Num.Det+id;
					P.Filter.Page[ia][ib][id]=page;
					P.Page[page].Source=0;
					P.Page[page].Fiber=ib*P.Num.Det+id;
					P.Page[page].Board=ib; 
					}
			P.Num.Page=P.Acq.Frame*P.Num.Board*P.Num.Det;
			}
	else{
		for(ia=0;ia<P.Acq.Frame;ia++)
			for(ib=0;ib<P.Num.Board;ib++)
				for(id=0;id<P.Num.Det;id++)
					P.Filter.Page[ia][ib][id]=-1;
		for(ir=0;ir<MAX_ROW_PROT;ir++){
			count_fiber = 0;
			string = P.TProt.Fibers[ir];
			source = P.TProt.Source[ir];
			strcat(string,",");
			while((strlen(string)>1)&&(sscanf(string,"%d",&fiber)!=EOF)){
				switch (fiber){
					case -1: f1=0; f2=0; break;
					case 0: f1=0; f2=P.Num.Fiber; break;
					default: f1=fiber; f2=fiber+1; break;
					}
				for(iff=f1;iff<f2;iff++){
					if(P.Layout.Order==LAYOUT_PARALL)
						for(ia=P.TProt.AcqStart[ir];ia<P.TProt.AcqStop[ir];ia++)
							P.Filter.Page[ia][P.Fiber[fiber-1].Board][P.Fiber[fiber-1].Det]=page;
					else{
						ia=P.TProt.AcqStart[ir]+count_fiber;
						P.Filter.Page[ia][P.Fiber[fiber-1].Board][P.Fiber[fiber-1].Det]=page;
						count_fiber++;
						}
					P.Page[page].Source=source-1;
					P.Page[page].Fiber=fiber-1;
					P.Page[page].Board=P.Fiber[fiber-1].Board; 
					page++;
					}
				string += 1+FindPattern (string,0,-1,",",1,0);
				}
			string = P.TProt.Fibers[ir];
			string[strlen(string)-1]='\0'; // delete last ',' from the UIR string
			}
		P.Num.Page=page;
		}
	}
	
	
// WRITE TWITCH ARRAY
void InitTwitch(void){
	int ir,ia,is;
	char source;
	if(!P.Layout.Layout) return;
	P.Twitch.NoSwitch=0;
	for(ia=0;ia<MAX_ACQ;ia++)
		for(is=0;is<MOXY_NUM_SWITCH;is++)
			P.Twitch.Chann[ia][is]=MOXY_CHANN_REST;
	for(ir=0;ir<P.Num.Prot;ir++){
		source = P.TProt.Source[ir];
		for(ia=P.TProt.AcqStart[ir];ia<P.TProt.AcqStop[ir];ia++)
			P.Twitch.Chann[ia][P.Source[source-1].Switch]=P.Source[source-1].Chann;
		}
	if(P.Moxy.Moxy) {
		for(is=0;is<MOXY_NUM_SWITCH;is++) {
			for(ia=0;ia<P.Acq.Frame-1;ia++) {
				if (P.Twitch.Chann[ia][is]!=P.Twitch.Chann[ia+1][is]) P.Twitch.NoSwitch++;
				}
			}
		}
	}
	
	
// COMPILE SUBHEADER
void CompileSub(long Ram, long Frame, long Page){
	int ir,loop1,loop2,loop3,loop_steps;
	double dX,dY,dZ;
	char fiber=P.Page[Page].Fiber;
	char source=P.Page[Page].Source;
	char num_roi=0;
	T_SUB *sub=&D.Sub[Frame][Page];

	sub->Geom = (char) P.Info.Geom;
	sub->Source = (char) source+1;
	sub->Fiber = (char) fiber+1;
	sub->Det = (char) P.Fiber[fiber].Det+1;
	sub->Board = (char) P.Fiber[fiber].Board+1;
	sub->Coord = (char) P.Fiber[fiber].Coord;
	sub->Pad = (char) P.Fiber[fiber].Pad;
	sub->Xf = (double) P.Fiber[fiber].Xf;
	sub->Yf = (double) P.Fiber[fiber].Yf;
	sub->Zf = (double) P.Fiber[fiber].Zf;
	sub->Rf = (double) P.Fiber[fiber].Rf;
	sub->Xs = (double) P.Source[source].Xs;
	sub->Ys = (double) P.Source[source].Ys;
	sub->Zs = (double) P.Source[source].Zs;
	sub->Rs = (double) P.Source[source].Rs;
	dX=(sub->Xf-sub->Xs); dY=(sub->Yf-sub->Ys); dZ=(sub->Zf-sub->Zs);
	sub->Rho = sqrt(dX*dX+dY*dY+dZ*dZ);
	sub->TimeNom = (double) P.Page[Page].TimeNom;
	sub->TimeEff = (double) P.Page[Page].TimeEff;
	sub->n = (double) Pad[sub->Pad].Nn;
	loop_steps=Ram*P.Frame.Num+Frame;
	CalcLoopIndex(loop_steps,&loop1,&loop2,&loop3);
	sub->Loop[LOOP1] = (long) loop1;
	sub->Loop[LOOP2] = (long) loop2;
	sub->Loop[LOOP3] = (long) loop3;
	sub->Acq = (long) P.Page[Page].Acq;
	sub->Page = (long) Page;
	for(ir=0;ir<MAX_ROW_ROI;ir++)
		if(P.Roi.Page[ir]==Page){
			sub->RoiFirst[num_roi] = (short) P.Roi.First[ir];
			sub->RoiLast[num_roi] = (short) P.Roi.Last[ir];
			sub->RoiLambda[num_roi] = (double) (P.Oma.Oma?P.Oma.Baric:P.Roi.Lambda[ir]);
			sub->RoiPower[num_roi] = (double) CalcPower(Frame, Page, ir);
			num_roi++;
			}
	sub->RoiNum = (char) num_roi;
	}

// CALC POWER
double CalcPower(long Frame, long Page, int Roi){
	double power=0.;
	int ic;

	if(P.Oma.Oma) power = P.Oma.Peak;
	//if(P.Power.Power) power = P.Step[P.Power.Step].Actual/FPM_CALIB_FACT;
	if(P.Power.Power) power = P.Step[P.Power.Step].Actual/ADC_FACTOR;
	if(P.Info.Appl == APPL_MAMM) 
		for(ic=P.Roi.First[Roi]; ic<=P.Roi.Last[Roi]; ic++)
			power += D.Data[Frame][Page][ic];

	return(power);
	}

// CALC LOOP INDEX
void CalcLoopIndex(long Steps,long *Loop1,long *Loop2,long *Loop3){
	*Loop1=(long) Steps/(P.Loop[LOOP2].Num*P.Loop[LOOP3].Num);
	Steps-=*Loop1*P.Loop[LOOP2].Num*P.Loop[LOOP3].Num;
	*Loop2=(long) Steps/P.Loop[LOOP3].Num;
	Steps-=*Loop2*P.Loop[LOOP3].Num;
	*Loop3=(long) Steps;
	}


/* ########################   DISPLAY PROCEDURES   ########################### */

/* TEXT OUTPUT */	
void TextOut(void){
	if(P.Command.Abort)
		SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "\n Measure aborted!!!\n\n");
	else
		SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "\n Finished!!!\n\n");
	}

/* UPDATE FILE TAG */
void UpdateTag(void){
	P.File.Tag+=1;
	SetCtrlVal (hParm, PARM_FILE_TAG, P.File.Tag);
	}

/* INITIALIZE DISPLAY PANEL */
void InitDisplay(void){
	int il,iw,is,ir,it,ip;
	int color[MAX_PLOT];
	
	//color
	color[0]=MakeColor(0,100,143);
	color[1]=MakeColor(100,0,207);
	color[2]=MakeColor(0,15,255);
	color[3]=MakeColor(0,79,255);
	color[4]=MakeColor(0,143,255);
	color[5]=MakeColor(0,207,255);
	color[6]=MakeColor(15,255,239);
	color[7]=MakeColor(79,255,175);
	color[8]=MakeColor(143,255,111);
	color[9]=MakeColor(207,255,47);
	color[10]=MakeColor(255,239,0);
	color[11]=MakeColor(255,175,0);
	color[12]=MakeColor(255,111,0);
	color[13]=MakeColor(255,47,0);
	color[14]=MakeColor(239,0,0);
	color[15]=MakeColor(175,0,0);

	SetActivePanel (hDisplay);
	SetCtrlVal (hDisplay, DISPLAY_CONTPAUSE, ON);
	SetCtrlVal (hDisplay, DISPLAY_MEASURE, OFF);
	SetCtrlVal (hDisplay, DISPLAY_MOVE, OFF);
	SetCtrlVal (hDisplay, DISPLAY_TRIM, OFF);
	for(il=0;il<MAX_LOOP;il++)
		SetTableCellAttribute (hDisplay, DISPLAY_T_LOOP, MakePoint(1,il+1), ATTR_CTRL_VAL,0);
	for(is=0;is<MAX_STEP;is++)
		SetTableCellAttribute (hDisplay,DISPLAY_T_TRIS,MakePoint(COL_TRIS_STEP,is+1),ATTR_CTRL_VAL,0.0);
	for(iw=0;iw<MAX_STEP;iw++)
		SetTableCellAttribute (hDisplay,DISPLAY_T_TRIS,MakePoint(COL_TRIS_SWITCH,iw+1),ATTR_CTRL_VAL,0);
	for(it=0;it<MAX_TRIM;it++)
		SetTableCellAttribute (hDisplay,DISPLAY_T_TRIS,MakePoint(COL_TRIS_TRIM,it+1),ATTR_CTRL_VAL,0);
	for(ir=0;ir<MAX_ROW_ROI;ir++){
		SetTableCellAttribute (hDisplay,DISPLAY_T_ROI,MakePoint(COL_ROI_PAGE,ir+1),ATTR_CTRL_VAL,P.Roi.Page[ir]);
		SetTableCellAttribute (hDisplay,DISPLAY_T_ROI,MakePoint(COL_ROI_FIRST,ir+1),ATTR_CTRL_VAL,P.Roi.First[ir]);
		SetTableCellAttribute (hDisplay,DISPLAY_T_ROI,MakePoint(COL_ROI_LAST,ir+1),ATTR_CTRL_VAL,P.Roi.Last[ir]);
		SetTableCellAttribute (hDisplay,DISPLAY_T_ROI,MakePoint(COL_ROI_AREA,ir+1),ATTR_CTRL_VAL,0);
		SetTableCellAttribute (hDisplay,DISPLAY_T_ROI,MakePoint(COL_ROI_MAX,ir+1),ATTR_CTRL_VAL,0);
		SetTableCellAttribute (hDisplay,DISPLAY_T_ROI,MakePoint(COL_ROI_PEAK,ir+1),ATTR_CTRL_VAL,0);
		SetTableCellAttribute (hDisplay,DISPLAY_T_ROI,MakePoint(COL_ROI_WIDTH,ir+1),ATTR_CTRL_VAL,0.0);
		}	  

	for(ip=0;ip<MAX_PLOT;ip++) {
		SetCtrlAttribute (hDisplay, DISPLAY_PLOT_PLOT_1+ip, ATTR_ON_COLOR, color[ip]);
		SetCtrlAttribute (hDisplay, DISPLAY_PLOT_PLOT_1+ip, ATTR_OFF_COLOR, color[ip]);
			}

	ProcessDrawEvents ();
	}


/* DISPLAY STATUS OF PROGRAM */
void DisplayStatus(void){
	char is,iw,il;
	for(il=0;il<MAX_LOOP;il++)
		SetTableCellAttribute (hDisplay,DISPLAY_T_LOOP,MakePoint(1,il+1),ATTR_CTRL_VAL,P.Loop[il].First+P.Loop[il].Delta*P.Loop[il].Idx);
	for(is=0;is<MAX_STEP;is++)
		if(P.Step[is].Step)
			SetTableCellAttribute (hDisplay,DISPLAY_T_TRIS,MakePoint(COL_TRIS_STEP,is+1),ATTR_CTRL_VAL,(P.Step[is].Actual/(1.0*P.Step[is].Factor)));
	for(iw=0;iw<MAX_SWITCH;iw++)
		if(P.Switch[iw].Switch)
			SetTableCellAttribute (hDisplay,DISPLAY_T_TRIS,MakePoint(COL_TRIS_SWITCH,iw+1),ATTR_CTRL_VAL,P.Switch[iw].Actual);
	ProcessDrawEvents ();
	}


/* DISPLAY CURVE ON PLOT */
void DisplayPlot(void){
	if(P.Graph.Type==GRAPH_PLOT) GraphPlot();
	if(P.Graph.Type==GRAPH_ROI) GraphRoi();
	}

/* SET DISPLAY PLOT */
void SetGraphType(void){
	int visible;
	
	GetCtrlAttribute (hDisplay, DISPLAY_GRAPH_PLOT, ATTR_VISIBLE, &visible);
	if(visible!=(P.Graph.Type==GRAPH_PLOT))
		SetCtrlAttribute (hDisplay, DISPLAY_GRAPH_PLOT, ATTR_VISIBLE,!visible);
	GetCtrlAttribute (hDisplay, DISPLAY_GRAPH_ROI, ATTR_VISIBLE, &visible);
	if(visible!=(P.Graph.Type==GRAPH_ROI))
		SetCtrlAttribute (hDisplay, DISPLAY_GRAPH_ROI, ATTR_VISIBLE,!visible);
	};

/* DISPLAY CURVE ON PLOT */
void GraphPlot(void){
	int plot_num,ip,page;
	//int red,green,blue;
	int color[MAX_PLOT];
	int is_meas=(P.Contest.Function==CONTEST_MEAS);
	int type_data=(sizeof(T_DATA)==sizeof(short)?VAL_UNSIGNED_SHORT_INTEGER:VAL_UNSIGNED_INTEGER);

	int chan, minplot, maxplot, roipage;
	
/**/	minplot = 1e0;
/**/	maxplot = 1e5;

/*	for(ip=0;ip<MAX_PLOT;ip++){
		red=COLOR_FULL*(1-COLOR_FRACT*(1-1.0/4*ip+1))-1;
		blue=COLOR_FULL*(1-COLOR_FRACT*(1-1.0/4*(ip/4)+1))-1;
		green=COLOR_FULL*(1-COLOR_FRACT*(1-1.0/4*(ip/16)+1))-1;
		color[ip]=MakeColor (red, blue, green);
		}*/
	
	color[0]=MakeColor(0,100,143);
	color[1]=MakeColor(100,0,207);
	color[2]=MakeColor(0,15,255);
	color[3]=MakeColor(0,79,255);
	color[4]=MakeColor(0,143,255);
	color[5]=MakeColor(0,207,255);
	color[6]=MakeColor(15,255,239);
	color[7]=MakeColor(79,255,175);
	color[8]=MakeColor(143,255,111);
	color[9]=MakeColor(207,255,47);
	color[10]=MakeColor(255,239,0);
	color[11]=MakeColor(255,175,0);
	color[12]=MakeColor(255,111,0);
	color[13]=MakeColor(255,47,0);
	color[14]=MakeColor(239,0,0);
	color[15]=MakeColor(175,0,0);
//	if((P.Num.Board==1)&&(P.Num.Det==1)) color[0]=VAL_YELLOW;

	SetGraphType();
	SetAxisScalingMode (hDisplay, DISPLAY_GRAPH_PLOT, VAL_XAXIS, VAL_MANUAL,
						P.Oscill.Zoom.First,P.Oscill.Zoom.Last);
	plot_num=(is_meas?P.Plot.NumM:P.Plot.NumO);
//**	for(ip=0;ip<plot_num;ip++)
//**		if(P.Plot.Plot[ip]){
	for(ip=0;ip<MAX_PLOT;ip++)
		if(P.Plot.Plot[ip]){
			page=P.Plot.PageU[ip]-1;
			if(page<plot_num){
				D.Curve=(is_meas?D.Data[P.Frame.Actual][page]:D.Osc[page]);
				hPlot[ip] = PlotY (hDisplay, DISPLAY_GRAPH_PLOT, D.Curve,
							   P.Chann.Num, type_data, VAL_SCATTER,
							   VAL_SMALL_CROSS, VAL_SOLID, 1, color[ip]);
				// Draw markers
				for(ir=0;ir<MAX_ROW_ROI;ir++)
					if(is_meas?P.Roi.RoiM[ir]:P.Roi.RoiO[ir]) {
						GetTableCellAttribute (hDisplay, DISPLAY_T_ROI, MakePoint(COL_ROI_PAGE,ir+1), ATTR_CTRL_VAL,
		   						&roipage);
						if(roipage == page) {
							GetTableCellAttribute (hDisplay, DISPLAY_T_ROI, MakePoint(COL_ROI_FIRST,ir+1), ATTR_CTRL_VAL,
								   &chan);
							PlotLine (hDisplay, DISPLAY_GRAPH_PLOT, chan, minplot, chan, maxplot, 
									color[ip]);
							GetTableCellAttribute (hDisplay, DISPLAY_T_ROI, MakePoint(COL_ROI_LAST,ir+1), ATTR_CTRL_VAL,
								   &chan);
							PlotLine (hDisplay, DISPLAY_GRAPH_PLOT, chan, minplot, chan, maxplot, 
									color[ip]);

							}

						}
				}
			}

	RefreshGraph (hDisplay, DISPLAY_GRAPH_PLOT);
	DeleteGraphPlot (hDisplay, DISPLAY_GRAPH_PLOT, -1, VAL_DELAYED_DRAW);
	}
	
	
/* DISPLAY NUM ON PLOT */
void GraphRoi(void){
	int hArea,hWidth;

	SetGraphType();
    SetCtrlAttribute(hDisplay,DISPLAY_GRAPH_ROI,ATTR_ACTIVE_YAXIS,VAL_LEFT_YAXIS);
	hArea = PlotY (hDisplay, DISPLAY_GRAPH_ROI, P.Roi.Area, MAX_ROW_ROI,
				   VAL_INTEGER, VAL_VERTICAL_BAR, VAL_NO_POINT, VAL_SOLID,
				   1, VAL_RED);
    SetCtrlAttribute(hDisplay,DISPLAY_GRAPH_ROI,ATTR_ACTIVE_YAXIS,VAL_RIGHT_YAXIS);
	hWidth=PlotY(hDisplay,DISPLAY_GRAPH_ROI,P.Roi.Width,MAX_ROW_ROI,VAL_DOUBLE,
				VAL_CONNECTED_POINTS,VAL_SOLID_DIAMOND,VAL_SOLID,1,VAL_GREEN);
	RefreshGraph(hDisplay,DISPLAY_GRAPH_ROI);
	DeleteGraphPlot(hDisplay,DISPLAY_GRAPH_ROI,-1,VAL_DELAYED_DRAW);
	}
	
	
/* ANALYZE CURVES */
void DisplayRoi(void){
	int ir,ib,ic,id;
	double treshold;
	long first,last, peak, area, max;
	int is_meas=(P.Contest.Function==CONTEST_MEAS);
	
	if(!is_meas)
		for(ib=0;ib<P.Num.Board;ib++){
			area=0;
			for(id=0;id<P.Num.Det;id++)
				for(ic=0;ic<P.Chann.Num;ic++)
					area+=D.Osc[id+ib*P.Num.Det][ic];
			area/=P.Spc.TimeO;
			SetTableCellAttribute(hDisplay,DISPLAY_T_BOARD,MakePoint(1,ib+1),ATTR_CTRL_VAL,area);
			}			
	for(ir=0;ir<MAX_ROW_ROI;ir++)
		if(is_meas?P.Roi.RoiM[ir]:P.Roi.RoiO[ir]){
			D.Curve=(is_meas?D.Data[P.Frame.Actual][P.Roi.Page[ir]]:D.Osc[P.Roi.Page[ir]]);
			P.Roi.Area[ir]=CalcArea(P.Roi.First[ir],P.Roi.Last[ir]);
			GetRange(P.Roi.First[ir],P.Roi.Last[ir],P.Oscill.Fract[REF],&max,&peak,&first,&last,&treshold);
			P.Roi.Width[ir]=CalcWidth(first,last,treshold);
			SetTableCellAttribute (hDisplay,DISPLAY_T_ROI,MakePoint(COL_ROI_AREA,ir+1),ATTR_CTRL_VAL,P.Roi.Area[ir]);
			SetTableCellAttribute (hDisplay,DISPLAY_T_ROI,MakePoint(COL_ROI_MAX,ir+1),ATTR_CTRL_VAL,max);
			SetTableCellAttribute (hDisplay,DISPLAY_T_ROI,MakePoint(COL_ROI_PEAK,ir+1),ATTR_CTRL_VAL,peak);
			SetTableCellAttribute (hDisplay,DISPLAY_T_ROI,MakePoint(COL_ROI_WIDTH,ir+1),ATTR_CTRL_VAL,P.Roi.Width[ir]);
			}
	if(is_meas?P.Roi.RoiM[P.Value.Roi-1]:P.Roi.RoiO[P.Value.Roi-1]){
		SetTableCellAttribute (hDisplay,DISPLAY_T_VALUE,MakePoint(COL_VALUE_AREA,1),ATTR_CTRL_VAL,P.Roi.Area[P.Value.Roi-1]);
		SetTableCellAttribute (hDisplay,DISPLAY_T_VALUE,MakePoint(COL_VALUE_WIDTH,1),ATTR_CTRL_VAL,P.Roi.Width[P.Value.Roi-1]);
		}

	ProcessDrawEvents ();
	}


/* CALCULATE AREA */
long CalcArea(long First, long Last){
	long area=0;
	short ic;
	for(ic=First;ic<=Last;ic++) area+=D.Curve[ic];
	return(area);
	}


/* CALCULATE WIDTH */   
double CalcWidth(long First,long Last,double Treshold){
	int FirstP=First+1;
	int LastM=Last-1;
	double dff_df,dll_dl,df,dff,dl,dll;
	double deltaF,deltaL;
	if(FirstP==P.Chann.Num) FirstP=First;
	if(LastM==-1) LastM=Last;
	df=D.Curve[First];
	dff=D.Curve[FirstP];
	dl=D.Curve[Last];
	dll=D.Curve[LastM];
	dff_df=dff-df;
	dll_dl=dll-dl;
	if(dff_df==0) dff_df=1;
	if(dll_dl==0) dll_dl=1;
	if(Treshold<=df) deltaF=0.0; else deltaF=(Treshold-df)/dff_df;
	if(Treshold<=dl) deltaL=0.0; else deltaL=(Treshold-dl)/dll_dl;
	return((Last-First-deltaF-deltaL)*P.Spc.Factor);
	}


/* CALCULATE RANGE HIGHER THAN PEAK FRACTION */
void GetRange(long RoiFirst,long RoiLast,double Fract,long *Max, long *Peak, long *pRangeFirst,long *pRangeLast,double *Treshold){
	short ic;
	*Max=0;
	*Peak=RoiFirst;
	for(ic=RoiFirst;ic<=RoiLast;ic++)
		if(*Max<D.Curve[ic]){
			*Max = D.Curve[ic];
			*Peak = ic;
			}
	ic = *Peak;
	*Treshold=(long)(*Max*Fract);
	while((ic>RoiFirst) && (D.Curve[ic]>=(*Treshold))) ic--;
	*pRangeFirst=ic;
	ic = *Peak;
	while((ic<RoiLast) && (D.Curve[ic]>=(*Treshold))) ic++;
	*pRangeLast=ic;
	if(*Max==0) {*pRangeFirst=RoiFirst; *pRangeLast=RoiLast;}
	}


// READ CONTROL ON CONTINUE/PAUSE
int CVICALLBACK GetCommand(int panel, int control, int event, void *callbackData, int eventData1, int eventData2){
	if(event!=EVENT_COMMIT) return 0;
	switch (control){
		case DISPLAY_CONTPAUSE:GetCtrlVal (hDisplay, control, &P.Command.Continue);break;
		case DISPLAY_ABORT:P.Command.Abort=TRUE;break;
		}
	return 0;
	}


/* ########################   WAIT FUNCTIONS   ######### */

// WAIT END
void WaitEnd(double Time,long Pos,char Type,char Step){
	switch (Type) {
		case WAIT_TIME: SyncWait(P.Spc.Zero,Time); break;
		case WAIT_DELAY: Delay(Time); break;
		case WAIT_SPC: SpcWait(); break;
		case WAIT_COUNT: WaitCount(); break;
		case WAIT_POS: WaitPos(Step,Pos); break;
		}
	}
	
	
/* WAIT FOR COUNT */
void WaitCount(void){
	int ib,ic;
	double elapTime,expTime;
	long Area[MAX_PLOT];
	long minArea=MAX_COUNTS;

	D.Curve=D.Data[P.Frame.Actual][0]; //TODO: check for multi detectors
	while(TimerN()<(P.Spc.Zero+SPC_MIN_TIME));
	SpcPause();
	elapTime=TimerN()-P.Spc.Zero;
	SpcOut(P.Action.Status);
	SpcRestart();
	for(ib=0;ib<P.Num.Board;ib++) Area[ib]=0;
	for(ib=0;ib<P.Num.Board;ib++)
		for(ic=P.Oscill.First[SIG];ic<P.Oscill.Last[SIG];ic++)
			Area[ib]+=D.Curve[ic];
	//for(ib=0;ib<2*P.Num.Board;ib++)	 //OLD VERSION:PROBABLY 2* is an error?
	for(ib=0;ib<P.Num.Board;ib++)
		if(Area[ib]<minArea) minArea=Area[ib];
	if(minArea==0) minArea=1;
	expTime = (elapTime*P.Spc.Count)/minArea;
	if(expTime>P.Spc.TimeM) expTime=P.Spc.TimeM;
	while(TimerN()<(P.Spc.Zero+expTime));
	}


// WAIT CHRONO
void WaitChrono(void){
	char first = (P.Loop[LOOP1].Idx==0)&&(P.Loop[LOOP2].Idx==0)&&(P.Loop[LOOP3].Idx==0);
	if(first)
		P.Chrono.Now = TimerN();
	else {
		SyncWait (P.Chrono.Now, P.Chrono.Delta);
		P.Chrono.Now += P.Chrono.Delta;
		}
	P.Spc.Trash = TRUE;
	}


/* ########################   SPC FUNCTIONS   ######### */


/* INITIALIZE */
void SpcInit(void){
	int ib;
	switch(P.Spc.Type){
		case NONE:  break;  
		case VARRO:  InitVarro(); break;
	//	case SILENA:  InitSilena(); break;
		case SPC300: InitSpc300();break;
		case THARP: InitTimeharp();break;
		case SPC630:  
		case SPC130: for(ib=0;ib<P.Num.Board;ib++) InitSpcm(ib);break;
		case TEST: break;
		}
	}


/* CLOSE SPC */
void SpcClose(void){
	SpcStop(FALSE);
	switch(P.Spc.Type){
		case NONE:  break;  
		case VARRO:  break;
	//	case SILENA:  break;
		case SPC300: break;
		case THARP: break;
		case SPC630:  
		case SPC130: CloseSpcm(); break;
		case TEST: break;
		}
	}

	
/* SPC PAUSE */
void SpcPause(void){
	int ib;
	switch(P.Spc.Type){
		case NONE: break;  
		case VARRO: CharCommVarro('d'); break; //TODO check
	//	case SILENA: DataStopSilena(); break; //TODO check
		case SPC300: SPCI_pause_measurement(); break;
		case THARP: TH_StopMeas(); break;  //TODO check
		case SPC630:  
		case SPC130: for(ib=0;ib<P.Num.Board;ib++) SPC_pause_measurement(ib); break;
		case TEST: break;
		}
	}
	

/* CLEAR DATA */
void SpcClear(void){
	int ic;

	if(P.Spc.Subtract) for(ic=0;ic<P.Chann.Num;ic++) D.Last[ic]=0;
	switch(P.Spc.Type){
		case NONE:  break;  
		case VARRO: CharCommVarro('e'); break;
	// 	case SILENA: ClearSilena(); break;
		case SPC300: SPCI_fill_memory(-1,0,0); break;
		case THARP: TH_ClearHistMem(); break;
		case SPC630:
		case SPC130: ClearSpcm(); break;
		case TEST: break;
		}
	P.Spc.Zero=TimerN();
	P.Spc.Trash=FALSE;
}


/* DATA IN */
void SpcIn(){
	int ib;
	switch(P.Spc.Type){
		case NONE:  break;  
		case VARRO: CharCommVarro('a'); break;
	//	case SILENA: DataInSilena(); break;
		case SPC300: SPCI_start_measurement(); break;
		case THARP: TH_StartMeas(); break;
		case SPC630: 
		case SPC130: for(ib=0;ib<P.Num.Board;ib++) SPC_start_measurement(ib); break;
		case TEST: break;
		}
	P.Spc.Zero=TimerN();
	P.Spc.Started=TRUE;
	}


/* DATA RESTART */
void SpcRestart(void){  //TODO: check
	int ib;
	switch(P.Spc.Type){
		case NONE:  break;  
		case VARRO: CharCommVarro('a'); break;
	//	case SILENA: DataInSilena(); break;
		case SPC300: SPCI_restart_measurement(); break;
		case THARP: TH_StartMeas(); break;
		case SPC630: 
		case SPC130: for(ib=0;ib<P.Num.Board;ib++) SPC_restart_measurement(ib); break;
		case TEST: break;
		}
	}


/* OPTIMIZED DATA CLEAR & DATA IN */
void SpcReset(char Status, char Clear, char Stop){
	if(Clear) SpcClear();
	if(P.Spc.Trash) SpcOut(FALSE);
	if(Stop||(!P.Spc.Started)) SpcIn();
	if(Status) SetCtrlVal (hDisplay, DISPLAY_MEASURE, ON);
	P.Spc.Trash=FALSE;
	}
	

/* DATA SET TIME */
void SpcTime(float Time){ 
	int ib;
	if(P.Wait.Type!=WAIT_SPC) Time *= 2;
	switch(P.Spc.Type){
		case NONE:  break;  
		case VARRO: /**/; break;
	//	case SILENA: /**/; break;
		case SPC300: SPCI_set_parameter(COLLECT_TIME,Time); break;
		case THARP: TH_SetMMode(0,1000*Time); break;
		case SPC630: 
		case SPC130: for(ib=0;ib<P.Num.Board;ib++) SPC_set_parameter(ib,COLLECT_TIME,Time); break;
		case TEST: break;
		}
	}


/* DATA STOP */
void SpcStop(char Status){
	short ib;
	//**	CalcTime();
	switch(P.Spc.Type){
		case NONE:  break;  
		case VARRO: CharCommVarro('d'); break;
	//	case SILENA: DataStopSilena(); break;
		case SPC300: SPCI_stop_measurement(); break;
		case THARP: TH_StopMeas();break;
		case SPC630:
		case SPC130: for(ib=0;ib<P.Num.Board;ib++) SPC_stop_measurement(ib);break;
		case TEST: break;
		}
	CalcTime();
	if(Status) SetCtrlVal (hDisplay, DISPLAY_MEASURE, OFF);
	P.Spc.Started=FALSE;
	}


/* WAIT SPC */
void SpcWait(void){
	short mod_state;
	int ib;
    unsigned char statusmeas;
	switch(P.Spc.Type){
		case NONE:  break;  
		case VARRO: while(CheckAcqVarro()); break;  // check !
	//	case SILENA: do _GetMeasInfo(&realtime,&livetime,&deadtime,&statusmeas);
					 while(statusmeas != SILENA_TIMESTOP); break;
		case SPC300: do SPCI_test_state(&mod_state);
					 while((mod_state & SPC_ARMED) != 0);break;
		case THARP: while(TH_CTCStatus()==0);
					TH_StopMeas();break; 
		case SPC630:   
		case SPC130: for(ib=0;ib<P.Num.Board;ib++)
    					do SPC_test_state(ib,&mod_state);
						while((mod_state & SPC_ARMED) != 0);break;
		case TEST: Delay((P.Contest.Function==CONTEST_OSC?P.Spc.TimeO:P.Spc.TimeM));break;
		}
	}


/* TRANSFER DATA FROM SPC INTO MEMORY */
void SpcGet(void){
	switch(P.Spc.Type){
		case NONE:  break;  
		case VARRO: GetDataVarro(); break;
	//	case SILENA: GetDataSilena(); break;
		case SPC300: GetDataSpc300();break; 
		case THARP: GetDataTimeharp();break; 
		case SPC630:   
		case SPC130: GetDataSpcm();break;
		case TEST:  GetDataTest();break;
		}
	}


/* DATA OUT AND PRE-PROCESSING */
void SpcOut(char Status){
	if(P.Spc.Started) CalcTime();
	SpcGet();
	DataCopy();
	if((P.Spc.Type==VARRO)||(P.Spc.Type==SILENA)) DataReverse();
	if((P.Spc.Type==VARRO)||(P.Spc.Type==SILENA)) DataSubtract();
	if(Status) SetCtrlVal (hDisplay, DISPLAY_MEASURE, OFF);
	}


/* SUBTRACT LAST DATA */
void DataSubtract(void){
	short ic;
	D.Curve=D.Data[0][0];
	for(ic=0; ic<P.Chann.Num; ic++){
		D.Curve[ic] -= D.Last[ic];
		D.Last[ic] += D.Curve[ic];
		}
	}  


/* REVERSE DATA */
void DataReverse(void){
	short num = P.Chann.Num;
	int ic;
	T_DATA temp;
	D.Curve=D.Data[0][0];
	for(ic=0;ic<(num/2);ic++){
		temp = D.Curve[ic];
		D.Curve[ic] = D.Curve[num-1-ic];
		D.Curve[num-1-ic] = temp;
		}
	}

	
/* CALCULATE EFFECTIVE TIME */
void CalcTime(void){
	short ib,state;
	double now;
	float meas_time, rem_time;
	if(P.Spc.Type==SPC130){
		for(ib=0;ib<P.Num.Board;ib++){
			SPC_test_state(ib,&state);
			SPC_get_actual_coltime(ib, &rem_time);
			SPC_get_parameter(ib, COLLECT_TIME, &meas_time);
			P.Spc.EffTime[ib] = meas_time - rem_time;
			}
		}
	else {
		now=TimerN();
		P.Spc.EffTime[0]=now-P.Spc.Zero;
		P.Spc.Zero=now;
		}
	}


/* COPY CURVE TO DATA */
void DataCopy(void){
	int ib,id;
	long page;
	int ic;
	int is_meas=(P.Contest.Function==CONTEST_MEAS);
	
	if(!is_meas)
		for(ib=0;ib<P.Num.Board;ib++)
			for(id=0;id<P.Num.Det;id++)
				for(ic=0;ic<P.Chann.Num;ic++)
					D.Osc[id+ib*P.Num.Det][ic]=D.Buffer[ib][ic+id*P.Chann.Num];
	else{
		for(ib=0;ib<P.Num.Board;ib++){
			for(id=0;id<P.Num.Det;id++){
				page=P.Filter.Page[P.Acq.Actual][ib][id];
				if(page!=-1){
					P.Page[page].Acq=P.Acq.Actual;
					P.Page[page].TimeNom=P.Spc.TimeM;
					P.Page[page].TimeEff=P.Spc.EffTime[ib];
					for(ic=0;ic<P.Chann.Num;ic++) D.Data[P.Frame.Actual][page][ic]+=D.Buffer[ib][ic+id*P.Chann.Num];
					if(P.Info.SubHeader) CompileSub(P.Ram.Actual,P.Frame.Actual,page);
					}
				}
			}
		}
	}
	

/* UPDATE ALL ACQ INDEXES */
void NewAcq(void){
	P.Acq.Actual++;
	if(P.Acq.Actual==P.Acq.Frame){
		P.Frame.Actual++;
		P.Acq.Actual=0;
		}
	if(P.Frame.Actual==P.Frame.Num){
		P.Ram.Actual++;
		P.Frame.Actual=0;
		} 
	}


/* ########################   SPC300 SPC FUNCTIONS   ####################### */


/* INITIALIZE SPC300 */
void InitSpc300(void){
	SPCIdata spc_data;
	SPCIMemConfig  spc_mem_info;
	short init;
	short meas_page=0;
	int ret=0;

	SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "Initializing SPC300 ... "); 
	init=SPCI_get_init_status();
	if(init!=INIT_OK){
		ret=SPCI_init(P.Spc.Settings[0]);
		if((ret<0)&&(ret!=SPC_IN_USE)) ErrHandler(ERR_SPC,ret,"SPC_Init");
		P.Spc.TimeInit=TimerN();	// era Timer()
		init=SPCI_get_init_status();
		}
	SpcTime(P.Spc.TimeM);
	ret+=SPCI_get_parameters(&spc_data);
	ret+=SPCI_configure_memory(spc_data.adc_resolution,P.Spc.RoutingBits,&spc_mem_info);
	ret+=SPCI_fill_memory(-1,meas_page,0);
	ret+=SPCI_set_page(meas_page);
	if(ret>=0) Passed(); else Failure("ret < 0");
	} 


/* TRANSFER DATA FROM SPC*/	
void GetDataSpc300(void){
	SPCI_read_data_page(0,P.Num.Det-1,(unsigned short*)D.Buffer[0]);
	}
	

/* ########################   SPCM FUNCTIONS (Spc630, Spc130)  ####################### */

/* INIT SPCM */	
void InitSpcm(int Board){
	char message[STRLEN];
	SPCdata spc_data;
	SPCMemConfig  spc_mem_info;
	short init,ret;
	
	sprintf (message, "Initializing SPCM, Module #%d, ...", Board);
	SetCtrlVal (hDisplay, DISPLAY_MESSAGE, message); 
	
	init=SPC_get_init_status(Board);
	if(init!=INIT_OK){
		ret=SPC_init(P.Spc.Settings[Board]);
		if((ret<0)&&(ret!=SPC_IN_USE)) ErrHandler(ERR_SPC,ret,"SPC_Init");
		P.Spc.TimeInit=TimerN();   // era Timer() 
		init=SPC_get_init_status(Board);
		}
	if((init!=INIT_OK)&&(init!=INIT_MOD_IN_USE)) ErrHandler(ERR_SPC,0,"SPC_get_init_status");
	if(init==INIT_MOD_IN_USE){
		ret=SPC_read_parameters_from_inifile(&spc_data,P.Spc.Settings[Board]);
		if(ret<0) ErrHandler(ERR_SPC,ret,"SPC_read_parameters_from_inifile");
		ret=SPC_set_parameters(Board,&spc_data);
		if(ret<0) ErrHandler(ERR_SPC,ret,"SPC_set_parameters");
		}
	ret=SPC_set_parameter(Board,COLLECT_TIME,P.Spc.TimeM);
	if(ret<0) ErrHandler(ERR_SPC,ret,"SPC_get_parameters:Time");
	ret=SPC_get_parameters(Board,&spc_data);
	if(ret<0) ErrHandler(ERR_SPC,ret,"SPC_get_parameters");
	ret=SPC_configure_memory(Board,spc_data.adc_resolution,P.Spc.RoutingBits,&spc_mem_info);
	if(ret<0) ErrHandler(ERR_SPC,ret,"SPC_configure_memory");
	P.Spc.MaxPage[Board]=spc_mem_info.maxpage;
	SPC_set_page(Board,0);
	if(ret<0) ErrHandler(ERR_SPC,ret,"SPC_set_page");
							   
	Passed();
	} 


/* INIT SPCM */	
void CloseSpcm(void){
	short ret;
	if(P.Moxy.Moxy){
		ret=SPC_enable_sequencer(SPC_ALL,FALSE);
		if(ret<0) ErrHandler(ERR_SPC,ret,"SPC_enable_sequencer");
		SPC_set_parameter(SPC_ALL, TRIGGER, 0); // no trigger
		if(ret<0) ErrHandler(ERR_SPC,ret,"SPC_set_parameter");
		}
	} 


/* TRANSFER DATA FROM SPCM */	
void GetDataSpcm(void){
	short state;
	int ib;
	int ret=0;

	P.Spc.Overflow=FALSE;
	for(ib=0;ib<P.Num.Board;ib++){
		ret=SPC_test_state(ib,&state);
		if(ret<0) ErrHandler(ERR_SPC,ret,"SPC_test_state");
		P.Spc.Overflow|=(state&SPC_OVERFLOW);
		ret=SPC_read_data_page(ib,0,0,(unsigned short*)D.Buffer[ib]);   
		if(ret<0) ErrHandler(ERR_SPC,ret,"SPC_read_data_page");
		}
	}


/* CLEAR SPCM */	
void ClearSpcm(void){
	short ret;
	if(P.Moxy.Moxy) ret=SPC_fill_memory(-1,-1,-1,0); 
	else ret=SPC_fill_memory(-1,-1,0,0); 
	if(ret<0) ErrHandler(ERR_SPC,ret,"SPC_fill_memory");
	ret=test_fill_state();
	if(ret<0) ErrHandler(ERR_SPC,ret,"test_fill_state");
	}


// TEST FILL STATE
short test_fill_state(void){
	short ret,state;
	time_t starttime,endtime;
	int ib;
	
	for (ib=0;ib<P.Num.Board;ib++){
		time(&starttime);
		while(1){
			ret=SPC_test_state(ib, &state);
			if(ret<0) return ret;
			if((state & SPC_HFILL_NRDY)==0) break;  // fill finished
			time(&endtime);
			if(difftime(endtime,starttime)>SPC130_TIMEOUT) return (-SPC_FILL_TOUT);  
			}
		}	 
	return 0;  
	}
	

/* ########################   THARP SPC FUNCTIONS   ####################### */


/* INITIALIZE THARP */
void InitTimeharp(void){
	long IOBase;
	long CFDDiscriminMin;
	long CFDZeroCross;
	long SYNCLevel;
	long RangeNo;
	long Offset;
	int retcode;
	FILE *pFile;

	SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "Initializing Time Harp ... "); 

	// read iniFile
	pFile = fopen(P.Spc.Settings[0],"rb");
	fscanf(pFile,"%ld\n",&IOBase);
	fscanf(pFile,"%ld\n",&CFDDiscriminMin);
	fscanf(pFile,"%ld\n",&CFDZeroCross);
	fscanf(pFile,"%ld\n",&SYNCLevel);
	fscanf(pFile,"%ld\n",&RangeNo);
	fscanf(pFile,"%ld\n",&Offset);
	fclose(pFile);
	
	// init Board
	//**retcode = TH_FPGAInit(IOBase);
	//**retcode = TH_RegisterInit();
//	/**/retcode = TH_Initialize(); 
	retcode = TH_Calibrate();
	retcode = TH_SetCFDDiscrMin(CFDDiscriminMin);
	retcode = TH_SetCFDZeroCross(CFDZeroCross);
	retcode = TH_SetSyncLevel(SYNCLevel);
	retcode = TH_SetRange(RangeNo);
	retcode = TH_SetOffset(Offset);
	//retcode = TH_SetMMode(0,ACQTMAX);  //TODO: control ACQTMAX 
	SpcTime(P.Spc.TimeM);
	retcode = TH_ClearHistMem();
	P.Spc.Calib = 1000*TH_GetResolution();
    P.Spc.Factor = P.Spc.Calib*P.Spc.Scale;
    //TODO: INSERT HERE CONTROL ON RETCODE
	Passed();
} 


/* TRANSFER DATA FROM THARP */	
void GetDataTimeharp(void){
	int retcode;
	short ic;
	unsigned long tempData[BLOCKSIZE];
	retcode = TH_GetBlock(tempData);
	for(ic=0;ic<P.Chann.Num;ic++) D.Buffer[0][ic]=(T_DATA) tempData[ic+P.Chann.First];
	}
	

/* ########################   VARRO SPC FUNCTIONS   ####################### */

/* INITIALIZE VARRO */
void InitVarro(void){
	char comstring[STRLEN], numstring[STRLEN];
	InitIeee();
	SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "Initializing Varro ... "); 
	P.Gpib[GPIBVARRO].hGpib = ibdev (GPIB0, GPIBVARRO, NO_SAD, T10s, 0, 0);
	if(P.Gpib[GPIBVARRO].hGpib<0){ Failure("Error: Initializing Varro"); return;}
	ibclr (P.Gpib[GPIBVARRO].hGpib);
	StringCommVarro("HP100000");                                // set time mode
	strcpy(comstring,"HQ0");                                    // set unit = second
	strcat(comstring,NewItoa((unsigned short)(INFINITY),numstring,5));
	StringCommVarro(comstring); 								// set number of units
	Passed();
	}


/* CHECK END ACQUISITION VARRO */
char CheckAcqVarro(void){
    char cbuffer[STRLEN];
    StringCommVarro("BM");
    SendAck();
    GpibRead(GPIBVARRO,cbuffer,6);
    SendAck();
	if(cbuffer[5] == 'A') return(1); else return(0);
}

	
/* TRANSFER DATA FROM VARRO TO MEMORY */
void GetDataVarro(void){
	char comstring[STRLEN], numstring[STRLEN];
    strcpy(comstring, "RSOD00");
    strcat(comstring, NewItoa(P.Chann.First,numstring,5));
    strcat(comstring, NewItoa(P.Chann.Last,numstring,5));
    CompLRC(comstring, strlen(comstring));
    StringCommVarro(comstring);  
    SendAck();
    GpibRead(GPIBVARRO,(char*)D.Buffer[0],SLI*(P.Chann.Num));
    SendAck();
	}


/* FUNCTION SEND PRESET COMMAND TO VARRO */
void StringCommVarro(char *comstring){
    NewComm();
    GpibWrite(GPIBVARRO,comstring);
	GetAck();
}


/* FUNCTION EXECUTE COMMAND TO VARRO */
void CharCommVarro(char comchar){
	char command[2];
	command[0]=comchar;
	command[1]='\0';
	GpibWrite(GPIBVARRO,command);
  	GetAck();  
}


/* SEND NEW COMMAND TO VARRO */
void NewComm(void){
	char command[2];
	command[0]=64;
	command[1]='\0';
	GpibWrite(GPIBVARRO,command);
	GetAck();
}


/* SEND ACK TO VARRO */
void SendAck(void){
	char command[2];
	command[0]=6;
	command[1]='\0';
	GpibWrite(GPIBVARRO,command);
}


/* GET ACK FROM VARRO */
void GetAck(void){
	char answer[2];
	GpibRead(GPIBVARRO,answer,1);
	if(answer[0]!=6) Failure("Error: Not ACK from Varro");
}


/* ########################   SILENA SPC FUNCTIONS   ####################### */

/* Conflict between THARP and SILENA:Options->Build Options->Default calling convention
/* 1)_Cdecl  -> SILENA works, THARP doesn't work;
/* 2)_Stdcall-> SILENA doesn't work, THARP works.


/* INITIALIZE SILENA */
/*void InitSilena(void){
	int status;
	unsigned char swstatus,bootfwrel,maxmen,maxtask;
	unsigned short mbcmodel;
	
	SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "Initializing Silena ... "); 
    status=_InitMbcPortAddress(MBADR);
    if (status!=1) Failure("Error: Cannot Initialize Silena MBC board");
	status=_GetCardConfig(&swstatus,&mbcmodel,&bootfwrel,&maxmen,&maxtask);
    if (swstatus!=1) Failure("Error: Firmware not loaded for Silena MBC\nRun EMCA program");
	status=_SetAdcGainInput((unsigned short)(MAX_CHANN_SILENA/P.Spc.Scale),EXTAMPL_SILENA);
    if (status!=1) Failure("Error: Cannot Set ADC Gain for Silena MBC board");
	status=_SelectMemoryRangeGroup((unsigned short)(MAX_CHANN_SILENA/P.Spc.Scale),(unsigned char)GROUP_SILENA);
    if (status!=1) Failure("Error: Cannot Set Memory Range for Silena MBC board");
	switch(P.Wait.Type){
		case WAIT_COUNT:{
			SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "Count ... ");
			//SetSilenaCount(); //TODO: check
			SetSilenaRoi();
			break;
			}
		case WAIT_TIME:
		case WAIT_DELAY:
		case WAIT_SPC:
		case WAIT_POS:{
			SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "Time ... ");
			SetSilenaTime();
			break;
			}
		}
	Passed();
	}


/* SET SILENA TIME-STOP CONDITION VALUE */
/*void SetSilenaTime(void){
    char timestop[3];
	int status;
	
    // SELECT TIME-STOP MODE 
    timestop[0]=1;timestop[1]=0;timestop[2]=0;
    status=_SelectStopMode(timestop);
   
    // SELECT REALTIME vs LIVETIME MODE 
    status=_SelectTimeMode((char)LIVETIME);
    
    // SELECT TIMESCALE 
    status=_SelectTimeUnit((char)TIMESCALE);
 
    // PRESET TIME VALUE 
    status=_PresetTime(INFINITY);
    };

/* SET SILENA REGION OF INTEREST */
/*void SetSilenaRoi(void){
	int status;
    status=_SetRoi((unsigned short)P.Chann.First,(unsigned short)P.Chann.Last);
    }


/* CLEAR DATA SILENA */
/*void ClearSilena(void){
	int status;
    status=_ClearMemory((unsigned short)P.Chann.First,(unsigned short)P.Chann.Last);
    };


/* DATA IN SILENA */
/*void DataInSilena(void){
    char start[4];
	int status;
    start[0]=1;start[1]=0;start[2]=0;start[3]=0;
    status=_StartStopDataIn(start);
    };


/* CHECK END ACQUISITION SILENA */
/*char CheckAcqSilena(void){
	switch(P.Wait.Type){
		case WAIT_COUNT: /*CheckCountSilena()*/;/*break;	   //TODO:check
		}
 return 0;		
}


/* STOP DATA IN SILENA */
/*void DataStopSilena(void){
    char stop[4];
	int status;
    stop[0]=2;stop[1]=0;stop[2]=0;stop[3]=0;
    status=_StartStopDataIn(stop);
    }


/* SLEEP UNTIL END SILENA*/
/*void WaitEndSilena(unsigned char tcstop){
    unsigned long  realtime, livetime;
    unsigned char deadtime, statusmeas;
	do _GetMeasInfo(&realtime,&livetime,&deadtime,&statusmeas);
	while(statusmeas != tcstop);
    }


/* ACQUIRE DATA FROM SILENA */
/*void GetDataSilena(void){
	int status;
    status=_TransferData((unsigned short)P.Chann.First,(unsigned short)P.Chann.Last,MBC_TO_PC,(unsigned char*)D.Buffer[0]);
    }


/* ########################   TEST DATA SIMULTING SPC   ######################## */

/* TRANSFER DATA FROM TEST */	
void GetDataTest(void){
	double *dataD;
	double mua,mus,r,v,area,value,timeA,t;
	int ib,id,ic,il;
	int delta=P.Chann.Num/2;
	dataD = calloc (P.Chann.Num, sizeof(*dataD));
	for(ib=0;ib<P.Num.Board;ib++)
		for(id=0;id<P.Num.Det;id++){
			for(il=0;il<2;il++){
				mus=TEST_MUS/(P.Num.Det*P.Num.Board*(il/0.3+1/0.3))*(1+2*(id+ib*P.Num.Det));
				mua=TEST_MUA/(P.Num.Det*P.Num.Board*(il/0.3+1/0.3))*(1+2*(id+ib*P.Num.Det));
				r=TEST_RHO;
				v=TEST_V;
				for(ic=0;ic<delta;ic++){
					t=(ic+0.5)*P.Spc.Factor;
					dataD[ic+il*delta]=(pow(t,-5/2)/mus)*exp(-mua*v*t)*exp(-(3*r*r*mus)/(4*v*t));
					}
				area=0;
				}
			for(ic=0;ic<P.Chann.Num;ic++)
				area+=dataD[ic];
			for(ic=0;ic<P.Chann.Num;ic++){
				timeA=(P.Contest.Function==CONTEST_OSC?P.Spc.TimeO:P.Spc.TimeM);
				value=(TEST_AREA*timeA/area*dataD[ic]);
				value*=(1-TEST_NOISE+(2*TEST_NOISE*rand())/RAND_MAX);
				D.Buffer[ib][ic+id*P.Chann.Num] = (T_DATA) value;
				}
			}
	free(dataD);
	}
	

/* ########################   TRIMMER PROCEDURES   ######################## */


/* INIT INCREMENT POS/NEG VERSION*/
void InitTrim(char Trim){
	}


/* AUTO TRIMMER */
void AutoTrim(int Trim){
	struct TrimS *T = &P.Trim[Trim];
	char si=T->Step;
	char datareset,tellpos,movestep,startstep,dataclear,datain,typewait,datastop,dataout;
	char versus=(T->Dir==TRIM_DIR_DOWN?-1:1);
	long jump=(T->Dir==TRIM_DIR_MIDDLE?1:0);
	long Origin=P.Step[si].Actual-jump*(T->Delta*T->Num)/2;
	long oldpos=P.Step[si].Actual;
	long label;
	long goalstep;
	char isfirst,islast;
	long loop_index;
	char loop=P.Step[si].Loop;
	char is_any_SPC = ((P.Spc.Type==SPC300)||(P.Spc.Type==SPC630)||(P.Spc.Type==SPC130));
	short page = P.Roi.Page[T->Region];

	// Initialize
	//P.Contest.Function=CONTEST_TRIM;
	P.Contest.Function=CONTEST_OSC;
	if(T->Type==CONT) SpcTime((float) 5*T->Num*T->Time);
	else SpcTime((float) INFINITY);
	if(P.Action.Status) SetCtrlVal (hDisplay, DISPLAY_TRIM, ON);
	T->ImprovedA=FALSE;
	T->ImprovedW=FALSE;
	T->PosAct=0;
	T->Trial=0;
	T->Set=0;
	T->Best=((T->Sign==LOWER)?INIT_LOWER:INIT_HIGHER);
	T->BestA=INIT_HIGHER;
	T->BestW=INIT_LOWER;
	MoveStep(&P.Step[si].Actual,Origin,si,TRUE,FALSE);
	T->PosBest = P.Step[si].Actual;
	
	// If already Success, then exit
	SpcReset(FALSE,is_any_SPC,is_any_SPC);
	WaitEnd(T->Time,0,WAIT_TIME,si);
	SpcStop(FALSE);
	SpcOut(FALSE);
	D.Curve=D.Osc[page];
	CheckTrimGoal(Trim);
	if(T->Status) DisplayRoi();
	if(T->Status) SetTableCellVal(hDisplay,DISPLAY_T_TRIS,MakePoint(COL_TRIS_STEP,si+1),(1.0*T->PosAct)/P.Step[si].Factor);
	if(T->Status) SetTableCellVal(hDisplay,DISPLAY_T_TRIS,MakePoint(COL_TRIS_TRIM,Trim+1),T->Trial);
	if(T->Status) ProcessDrawEvents ();
	if(T->Display) DisplayPlot();
	if(T->Success){
		if(P.Action.Status) SetTableCellVal(hDisplay,DISPLAY_T_TRIS,MakePoint(COL_TRIS_TRIM,Trim+1),T->Set);
		if(P.Action.Status) SetCtrlVal (hDisplay, DISPLAY_TRIM, OFF);
		loop_index=P.Loop[loop].Actual;
		label = loop_index*P.Loop[loop].Delta+P.Loop[loop].First;
		T->Label[loop_index]=label;
		T->Pos[loop_index]=(1.0*P.Step[si].Actual/P.Step[si].Factor);
		P.Spc.Trash=TRUE;
		SpcTime(P.Spc.TimeM);
		P.Contest.Function=CONTEST_MEAS;
		return;
		}


	// Continue with standard procedure
	if(T->Type==CONT) SetVel(si,(T->Delta/T->Time));
	if(T->Type==LIGTH) P.Step[si].Speed=SLOW;
	do {
		isfirst=(T->Trial==0);
		islast=(T->Trial==(T->Num-1));

		// Decide Action
		switch (T->Type) {
			case LIGTH:
				datareset=(isfirst||is_any_SPC);
				movestep=TRUE;
				startstep=FALSE;
				dataclear=is_any_SPC;
				datain=is_any_SPC;
				typewait=WAIT_TIME;
				tellpos=FALSE;
				datastop=is_any_SPC;
				dataout=TRUE;
				break;
			case CONT:
				movestep=FALSE;
				startstep=isfirst;
				dataclear=is_any_SPC;
				datain=is_any_SPC;
				datareset=(isfirst||is_any_SPC);
				typewait=WAIT_POS;
				tellpos=TRUE;
				datastop=((P.Meas.Stop?islast:FALSE)||is_any_SPC);
				dataout=TRUE;
				break;
			}
			
		// Do Action
		T->Trial++;
		goalstep=Origin+versus*T->Trial*T->Delta;
		if(movestep) MoveStep(&P.Step[si].Actual,goalstep,si,TRUE,FALSE);
		if(startstep) MoveStep(&P.Step[si].Actual,Origin+versus*T->Num*T->Delta,si,FALSE,FALSE);
		if(datareset) SpcReset(FALSE,dataclear,datain);
		WaitEnd(T->Time,goalstep,typewait,si);
		if(tellpos) TellPos(si,&T->PosAct);
		if(datastop) SpcStop(FALSE);
		if(dataout) SpcOut(FALSE);
		D.Curve=D.Osc[page];
		CheckTrimGoal(Trim);
		if(T->Status) DisplayRoi();
		if(T->Status) SetTableCellVal(hDisplay,DISPLAY_T_TRIS,MakePoint(COL_TRIS_STEP,si+1),(1.0*T->PosAct)/P.Step[si].Factor);
		if(T->Status) SetTableCellVal(hDisplay,DISPLAY_T_TRIS,MakePoint(COL_TRIS_TRIM,Trim+1),T->Trial);
		if(T->Status) ProcessDrawEvents ();
		if(T->Display) DisplayPlot();
		T->Stop=(T->Trial>T->Num);
		}
	while(!T->Success && !T->Stop);
	
	if(T->Type==CONT)
		if((T->Stop)&&(P.Step[si].Type==MICRO)) GetMicro(P.Step[si].Axis+1,&P.Step[si].Actual); //WaitStep()????!
		else StopStep(si);
	
	if(T->Type==CONT) SetVel(si,P.Step[si].Freq);
	if(T->Target==TARGET_AREAWIDTH){
		if(T->ImprovedW){
			T->Set=T->SetW;
			T->PosBest=T->PosW;
			}
		else if(T->ImprovedA){
			T->Set=T->SetA;
			T->PosBest=T->PosA;
			}
		else{
			T->Set=jump*T->Num/2;
			T->PosBest=oldpos;
			}
		}
	if(P.Action.Status) SetTableCellVal(hDisplay,DISPLAY_T_TRIS,MakePoint(COL_TRIS_TRIM,Trim+1),T->Set);
	if(T->Type==LIGTH) T->PosBest=Origin+versus*T->Delta*T->Set;
	MoveStep(&P.Step[si].Actual,T->PosBest-versus*T->Delta/2,si,TRUE,TRUE);
	//**if(!T->Success) MoveStep(&P.Step[si].Actual,T->PosBest-versus*T-Delta/2,si,TRUE,TRUE);
	if(P.Action.Status) SetCtrlVal (hDisplay, DISPLAY_TRIM, OFF);
	loop_index=P.Loop[loop].Actual;
	label = loop_index*P.Loop[loop].Delta+P.Loop[loop].First;
	T->Label[loop_index]=label;
	T->Pos[loop_index]=(1.0*P.Step[si].Actual/P.Step[si].Factor);
	P.Spc.Trash=TRUE;
	SpcTime(P.Spc.TimeM);
	P.Contest.Function=CONTEST_MEAS;
	}


/* CHECK IF TRIMMER GOAL IS REACHED OR IMPROVED */
void CheckTrimGoal(int Step){
	long max, peak;
	struct TrimS *T = &P.Trim[Step];
	double Treshold,area,width;
	short board=P.Page[P.Roi.Page[T->Region]].Board;
	if(T->Target==TARGET_AREAWIDTH){
		T->Success=FALSE;
		GetRange(T->Roi.First,T->Roi.Last,T->Fract,&max,&peak,&T->Range.First,&T->Range.Last,&Treshold);
		area=CalcArea(T->Roi.First,T->Roi.Last);
		area*=1.0/P.Spc.EffTime[board];
		width=CalcWidth(T->Range.First,T->Range.Last,Treshold);
		if(area>T->Goal)
			if(width<T->BestW){
				T->ImprovedW=TRUE;
				T->BestW=width;
				T->SetW=T->Trial;
				T->PosW=T->PosAct;
				}
		else if(area>T->BestA){
			T->ImprovedA=TRUE;
			T->BestA=area;
			T->SetA=T->Trial;
			T->PosA=T->PosAct;
			}
		return;
		}
	GetRange(T->Roi.First,T->Roi.Last,T->Fract,&max,&peak,&T->Range.First,&T->Range.Last,&Treshold);
	switch (T->Target) {
		case TARGET_WIDTH: T->Value = CalcWidth(T->Range.First,T->Range.Last,Treshold);break;
		case TARGET_AREA: T->Value = CalcArea(T->Roi.First,T->Roi.Last);break;
		}
	if(T->Sign == LOWER) {
		T->Success = (T->Value<T->Goal);
		T->Improved = (T->Value<T->Best);
		}
	else {
		T->Success = (T->Value>T->Goal);
		T->Improved = (T->Value>T->Best);
		}
	if(T->Improved){
		T->Best=T->Value;
		T->Set=T->Trial;
		T->PosBest=T->PosAct;
		}
	}


/* SAVE TRIMMER RESULTS */
void SaveTrim(char Trim){
	FILE *fpos, *ftrim;
	long label;
	double dpos;
	int il,zero,save;
	char match;
	char title_1[STRLEN],title_2[STRLEN],message_1[STRLEN],message_2[STRLEN];
	char name[PATHLEN],FPathPos[PATHLEN],FPathCopy[PATHLEN],FPathTemp[PATHLEN],FPathTrim[PATHLEN];
	
	char loop=P.Trim[Trim].Loop;
	char step=P.Trim[Trim].Step;
	double delta=0.0;
	
	if(!P.Trim[Trim].Prompt) return;
	
	sprintf(FPathPos,"%s",P.Step[step].FPath);
	sprintf(FPathCopy,"%s\\x%s%s",DIRFILEPOS,P.Step[step].FName,EXTFILEPOS);
	sprintf(FPathTemp,"%s\\temp%s",DIRFILEPOS,EXTFILEPOS);
	sprintf (title_1, "%s%s", SAVETRIM_TITLE_1,P.Step[step].FName);
	sprintf (title_2, "%s", SAVETRIM_TITLE_2);
	sprintf (message_1, "%s", SAVETRIM_MESSAGE_1);
	sprintf (message_2, "%s", SAVETRIM_MESSAGE_2);
	save = GenericMessagePopup (title_1, message_1, "SAVE CHANGES",
								  "SAVE & COPY", "CANCEL", name, PATHLEN-1, 0,
								  VAL_GENERIC_POPUP_BTN1,
								  VAL_GENERIC_POPUP_BTN1,
								  VAL_GENERIC_POPUP_BTN3);
	zero = ConfirmPopup (title_2, message_2);
	
	if(zero)
		for(il=0;il<P.Loop[loop].Num;il++)
			if(P.Trim[Trim].Label[il]==P.Loop[loop].Home) delta=P.Trim[Trim].Pos[il];
	
	if(save==VAL_GENERIC_POPUP_BTN3) return;
	if(save==VAL_GENERIC_POPUP_BTN2) CopyFile (FPathPos, FPathCopy);
	CopyFile (FPathPos, FPathTemp);
	if(strlen(name)!=0) sprintf(FPathTrim,"%s\\%s%s",DIRFILEPOS,name,EXTFILEPOS);
	else sprintf(FPathTrim,FPathPos);
	
	// save kernel
    fpos=fopen(FPathTemp,"r");
	ftrim = fopen (FPathTrim, "w");
	while(!feof(fpos)){
    	fscanf(fpos,"%ld",&label);
		fscanf(fpos,"%lf",&dpos);
    	fprintf(ftrim,"%ld\t",label);
    	match=FALSE;
		il=0;
		while((il<P.Loop[loop].Num)&&!match) if(label==P.Trim[Trim].Label[il++]) match=TRUE;
		--il;
		if(match)
			fprintf(ftrim,"%lf\n",P.Trim[Trim].Pos[il]-delta);
		else
			fprintf(ftrim,"%lf\n",dpos-delta);
		}
	fclose(fpos);
	fclose(ftrim);
	DeleteFile (FPathTemp);
	}


/* ########################   SWITCH PROCEDURES   ######################## */

/* INITIALIZE SWITCH */
void InitSwitch(char Switch){
	switch(P.Switch[Switch].Device){
		case SWITCH2X2:     if(P.Switch[Switch].Type==TIO) InitSwitch2X2(Switch); break;
		case SWITCH1X4:	    if((P.Switch[Switch].Type==TIO)||(P.Switch[Switch].Type==NI_6602)) InitSwitch1X4(Switch); break;
		case SWITCH1X9:     if((P.Switch[Switch].Type==TIO)||(P.Switch[Switch].Type==NI_6602)) InitSwitch1X9(Switch); break;
		case SWITCH_EOL2x2:  if((P.Switch[Switch].Type==LPT) || (P.Switch[Switch].Type==COM)) InitSwitch2X2EOL(Switch); break;                                  //Reb
		default:break; 
		}
}


/* CLOSE SWITCH */
void CloseSwitch(char Switch){
	int com;
	 switch(P.Switch[Switch].Device){
		case SWITCH2X2:     break;
		case SWITCH1X4:     break;
		case SWITCH1X9:     break;
		case SWITCH_EOL2x2:  switch (P.Switch[Switch].Type){
								case LPT: break;
								case COM: com = P.Switch[Switch].Line0;
								          CloseCom (com);
										  break;
								default:break;
								}
			
		default:break; 
		}
}
	
/* MOVE SWITCH */
void MoveSwitch(long Goal, char Switch){
	 if (Goal!=P.Switch[Switch].Actual){
	 P.Switch[Switch].Actual=Goal;
	 switch(P.Switch[Switch].Device){
	 	case SHUTTER:
		case SWITCH2X2:    if(P.Switch[Switch].Type==TIO) MoveSwitch2X2(Goal,Switch); break;
		case SWITCH1X4:    if((P.Switch[Switch].Type==TIO)||(P.Switch[Switch].Type==NI_6602)) MoveSwitch1X4_old(Goal,Switch);
						   else if(P.Switch[Switch].Type==NIDAQmx); MoveSwitch1X4(Goal,Switch); break;
		case SWITCH1X9:    if((P.Switch[Switch].Type==TIO)||(P.Switch[Switch].Type==NI_6602)) MoveSwitch1X9(Goal,Switch); break;
		case SWITCH_EOL2x2: if((P.Switch[Switch].Type==LPT)||(P.Switch[Switch].Type==COM))  MoveSwitch2X2EOL(Goal,Switch); break; 
		default:break; 
		}
	}
	}

/* CALCULATE GOAL FOR SWITCH */
long CalcGoalSwitch(char Switch){
	char loop = P.Switch[Switch].Loop;
	long index;
	index = P.Loop[loop].Actual;
	return(P.Switch[Switch].Pos[index]);
	}
	
/* INIT POS FOR SWITCH*/
void InitPosSwitch(char Switch){
	int il;
	int sethome = FALSE;
	int numread = 0;
	long label;
	int loop=P.Switch[Switch].Loop;
	long num=P.Loop[loop].Num;
	double dpos;
	char message[STRLEN];
	FILE *fpos;

	sprintf(message,"Initializing Array Position for Switch # %d ... ",Switch);
	SetCtrlVal (hDisplay,DISPLAY_MESSAGE,message);
    if(strlen(P.Switch[Switch].FName)==0){
		P.Switch[Switch].Home = (long)(P.Loop[loop].Home); 
    	for(il=0;il<num;il++)
    		P.Switch[Switch].Pos[il]=(long)(P.Loop[loop].First+il*P.Loop[loop].Delta);
    	}
    else {
    	fpos=fopen(P.Switch[Switch].FPath,"r");
		if(fpos==NULL){
			Failure("Error Loading File Position");
			return;
			}				
	   	while(!feof(fpos)){
    		fscanf(fpos,"%ld",&label);
			fscanf(fpos,"%lf",&dpos);
			if(label==P.Loop[loop].Home)
				if(!sethome){
					P.Switch[Switch].Home = (long)(dpos+0.5); // contollare +0.5;Andrea 18/2/2002
					sethome = TRUE;
					}
			for(il=0;il<num;il++){
				     if(label==(P.Loop[loop].First+il*P.Loop[loop].Delta)){
					 P.Switch[Switch].Pos[il]=(long)(dpos+0.5);
					 numread++;
					 }
				}
			}
				
		fclose(fpos);
		if(numread<(num-1)){ Failure("Error: Not Enough Points on File Pos"); return;}
		}
	
	P.Switch[Switch].Actual=P.Switch[Switch].Home;
	sprintf(message,"Home=%ld  ",P.Switch[Switch].Home);
	SetCtrlVal (hDisplay,DISPLAY_MESSAGE,message);
	
	Passed();
 }
 
 
// SWITCH 2X2
 
	
/* INITIALIZE SWITCH 2X2 */
void InitSwitch2X2(char Switch){
    //char line0=P.Switch[Switch].Line0;
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "Initializing PC-TIO Board for Switch2X2");
	/*P.Switch[Switch].Tio.Board = STEP_TIO_BOARD1;
	strcpy(P.Switch[Switch].Tio.sPort,STEP_TIO_PORT1);
    P.Switch[Switch].Tio.lSwitch0 = line0;
    P.Switch[Switch].Tio.lSwitch1 = line0+1;
	WriteToDigitalLine (P.Switch[Switch].Tio.Board,P.Switch[Switch].Tio.sPort,P.Switch[Switch].Tio.lSwitch0,8,0,LOW_LEVEL);
	WriteToDigitalLine (P.Switch[Switch].Tio.Board,P.Switch[Switch].Tio.sPort,P.Switch[Switch].Tio.lSwitch1,8,0,LOW_LEVEL);*/
    WriteToDigitalLine (P.Switch[Switch].Board,P.Switch[Switch].Port,P.Switch[Switch].Line0,8,0,P.Switch[Switch].Home);
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE," PASSED\n");
	}


/*MOVE SWITCH2X2 */  
void MoveSwitch2X2(long Goal,char Switch){
	 /*short line =((Goal==0)?P.Switch[Switch].Tio.lSwitch1:P.Switch[Switch].Tio.lSwitch0);
     WriteToDigitalLine (P.Switch[Switch].Tio.Board,P.Switch[Switch].Tio.sPort,line,8,0,HIGH_LEVEL);
     Delay(0.1);
     WriteToDigitalLine (P.Switch[Switch].Tio.Board,P.Switch[Switch].Tio.sPort,line,8,0,LOW_LEVEL);*/
     WriteToDigitalLine (P.Switch[Switch].Board,P.Switch[Switch].Port,P.Switch[Switch].Line0,8,0,Goal);
     //**Delay(0.1);
     }

 // SWITCH 1X4
	
/* INITIALIZE SWITCH 1X4 */
void InitSwitch1X4(char Switch){
	short value[3]={0, 0, 0};
    char line0=P.Switch[Switch].Line0;
	char board=P.Switch[Switch].Board; 
	char port[2];
	int il=0;
	int loop=P.Switch[Switch].Loop;
	strcpy(port,P.Switch[Switch].Port);
	for (il=0;il<P.Loop[loop].Num;il++){   /*Controllo sui numeri di canali dello switch*/
		if ((P.Switch[Switch].Pos[il]>4)||(P.Switch[Switch].Pos[il]<0)){
			Failure("Number of fiber unknown");
			return;
			}
		}
	switch (P.Switch[Switch].Home) {
		case FIBER_OFF: value[0]=0;value[1]=0;value[2]=0;break; //off
		case FIBER_1:   value[0]=1;value[1]=0;value[2]=0;break; //fiber 1
		case FIBER_2:   value[0]=0;value[1]=1;value[2]=0;break; //fiber 2
		case FIBER_3:   value[0]=1;value[1]=1;value[2]=0;break; //fiber 3
		case FIBER_4:   value[0]=0;value[1]=0;value[2]=1;break; //fiber 4
		default:        Failure("Home position unknown");break;
		}
	switch (P.Switch[Switch].Type) {
		case TIO:     SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "Initializing PC-TIO Board for Switch 1X4");
	                  P.Switch[Switch].Tio.Board = board;
	                  strcpy(P.Switch[Switch].Tio.sPort,port);
                      P.Switch[Switch].Tio.lSwitch0 = line0;
                      P.Switch[Switch].Tio.lSwitch1 = line0+1;
	                  P.Switch[Switch].Tio.lSwitch2 = line0+2;
	                  WriteToDigitalLine (P.Switch[Switch].Tio.Board,P.Switch[Switch].Tio.sPort, P.Switch[Switch].Tio.lSwitch0, 8, 0, value[0]);
	                  WriteToDigitalLine (P.Switch[Switch].Tio.Board,P.Switch[Switch].Tio.sPort, P.Switch[Switch].Tio.lSwitch1, 8, 0, value[1]);
	                  WriteToDigitalLine (P.Switch[Switch].Tio.Board,P.Switch[Switch].Tio.sPort, P.Switch[Switch].Tio.lSwitch2, 8, 0, value[2]);
		 			  break;
		 case NI_6602:SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "Initializing NI_6602 Board for Switch 1X4");
	                  P.Switch[Switch].Nidaq.Board = board;
	                  strcpy(P.Switch[Switch].Nidaq.sPort,port);
                      P.Switch[Switch].Nidaq.lSwitch0 = line0;
                      P.Switch[Switch].Nidaq.lSwitch1 = line0+1;
	                  P.Switch[Switch].Nidaq.lSwitch2 = line0+2;
	                  WriteToDigitalLine (P.Switch[Switch].Nidaq.Board,P.Switch[Switch].Nidaq.sPort, P.Switch[Switch].Nidaq.lSwitch0, 8, 0, value[0]);
	                  WriteToDigitalLine (P.Switch[Switch].Nidaq.Board,P.Switch[Switch].Nidaq.sPort, P.Switch[Switch].Nidaq.lSwitch1, 8, 0, value[1]);
	                  WriteToDigitalLine (P.Switch[Switch].Nidaq.Board,P.Switch[Switch].Nidaq.sPort, P.Switch[Switch].Nidaq.lSwitch2, 8, 0, value[2]);
		 			  break;
		 case NIDAQmx: break;
		 default:     break;
		 }
	SetCtrlVal (hDisplay, DISPLAY_MESSAGE," PASSED\n");
	}

/* INITIALIZE SWITCH 1X9 */
void InitSwitch1X9(char Switch) {
	short value[4]={1, 1, 1, 1};
	char line0=P.Switch[Switch].Line0;
	short board=(short)P.Switch[Switch].Board; 
	char port[2];
	int il=0;
	int loop=P.Switch[Switch].Loop;
	strcpy(port,P.Switch[Switch].Port);
	for (il=0;il<P.Loop[loop].Num;il++){   /*Controllo sui numeri di canali dello switch*/
		if ((P.Switch[Switch].Pos[il]>9)||(P.Switch[Switch].Pos[il]<1)){
			Failure("Number of fiber unknown");
			return;
			}
		}
	switch (P.Switch[Switch].Home) {
		case FIBER_1: value[0]=0;value[1]=0;value[2]=0;value[3]=0;break;
		case FIBER_2: value[0]=1;value[1]=0;value[2]=0;value[3]=0;break;
		case FIBER_3: value[0]=0;value[1]=1;value[2]=0;value[3]=0;break;
		case FIBER_4: value[0]=1;value[1]=1;value[2]=0;value[3]=0;break;
		case FIBER_5: value[0]=0;value[1]=0;value[2]=1;value[3]=0;break;
		case FIBER_6: value[0]=1;value[1]=0;value[2]=1;value[3]=0;break;
		case FIBER_7: value[0]=0;value[1]=1;value[2]=1;value[3]=0;break;
		case FIBER_8: value[0]=1;value[1]=1;value[2]=1;value[3]=0;break;
		case FIBER_9: value[0]=0;value[1]=0;value[2]=0;value[3]=1;break;
		default:      Failure("Home position unknown");break;
		}
	switch (P.Switch[Switch].Type) {
		case TIO:    SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "Initializing PC-TIO Board for Switch 1X9");
		             P.Switch[Switch].Tio.Board = board;
	                 strcpy(P.Switch[Switch].Tio.sPort,port);
                     P.Switch[Switch].Tio.lSwitch0 = line0;
                     P.Switch[Switch].Tio.lSwitch1 = line0+1;
	                 P.Switch[Switch].Tio.lSwitch2 = line0+2;
	                 P.Switch[Switch].Tio.lSwitch3 = line0+3;
					 WriteToDigitalLine (2, "1", 4, 8, 0, value[0]);
					 WriteToDigitalLine (2, "1", 5, 8, 0, value[1]);
					 WriteToDigitalLine (2, "1", 6, 8, 0, value[2]);
					 WriteToDigitalLine (2, "1", 7, 8, 0, value[3]);
//	         		 WriteToDigitalLine (P.Switch[Switch].Tio.Board,P.Switch[Switch].Tio.sPort, P.Switch[Switch].Tio.lSwitch0, 8, 0, value[0]);
//	                 WriteToDigitalLine (P.Switch[Switch].Tio.Board,P.Switch[Switch].Tio.sPort, P.Switch[Switch].Tio.lSwitch1, 8, 0, value[1]);
//	                 WriteToDigitalLine (P.Switch[Switch].Tio.Board,P.Switch[Switch].Tio.sPort, P.Switch[Switch].Tio.lSwitch2, 8, 0, value[2]);
//	                 WriteToDigitalLine (P.Switch[Switch].Tio.Board,P.Switch[Switch].Tio.sPort, P.Switch[Switch].Tio.lSwitch3, 8, 0, value[3]);
	    			 break;
	    case NI_6602:SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "Initializing NI-6602 Board for Switch 1X9");
	                 P.Switch[Switch].Nidaq.Board = board;
	                 strcpy(P.Switch[Switch].Nidaq.sPort,port);
                     P.Switch[Switch].Nidaq.lSwitch0 = line0;
                     P.Switch[Switch].Nidaq.lSwitch1 = line0+1;
	                 P.Switch[Switch].Nidaq.lSwitch2 = line0+2;
	                 P.Switch[Switch].Nidaq.lSwitch3 = line0+3;
	                 WriteToDigitalLine (P.Switch[Switch].Nidaq.Board,P.Switch[Switch].Nidaq.sPort, P.Switch[Switch].Nidaq.lSwitch1, 32, 0, value[0]); 
	                 WriteToDigitalLine (P.Switch[Switch].Nidaq.Board,P.Switch[Switch].Nidaq.sPort, P.Switch[Switch].Nidaq.lSwitch1, 32, 0, value[1]);
	                 WriteToDigitalLine (P.Switch[Switch].Nidaq.Board,P.Switch[Switch].Nidaq.sPort, P.Switch[Switch].Nidaq.lSwitch2, 32, 0, value[2]);
	                 WriteToDigitalLine (P.Switch[Switch].Nidaq.Board,P.Switch[Switch].Nidaq.sPort, P.Switch[Switch].Nidaq.lSwitch3, 32, 0, value[3]);
					 break;
		default:	 break;
		}
	SetCtrlVal (hDisplay, DISPLAY_MESSAGE," PASSED\n");
	}

/*MOVE SWITCH 1X9 */
void MoveSwitch1X9(long Goal,char Switch){
	short value[4]={1, 1, 1, 1};
	switch (Goal)  {
		case FIBER_1: value[0]=0;value[1]=0;value[2]=0;value[3]=0;break;
		case FIBER_2: value[0]=1;value[1]=0;value[2]=0;value[3]=0;break;
		case FIBER_3: value[0]=0;value[1]=1;value[2]=0;value[3]=0;break;
		case FIBER_4: value[0]=1;value[1]=1;value[2]=0;value[3]=0;break;
		case FIBER_5: value[0]=0;value[1]=0;value[2]=1;value[3]=0;break;
		case FIBER_6: value[0]=1;value[1]=0;value[2]=1;value[3]=0;break;
		case FIBER_7: value[0]=0;value[1]=1;value[2]=1;value[3]=0;break;
		case FIBER_8: value[0]=1;value[1]=1;value[2]=1;value[3]=0;break;
		case FIBER_9: value[0]=0;value[1]=0;value[2]=0;value[3]=1;break;
		default: break;
		}
	switch (P.Switch[Switch].Type) {
		case TIO:    
					 WriteToDigitalLine (2, "1", 4, 8, 0, value[0]);
					 WriteToDigitalLine (2, "1", 5, 8, 0, value[1]);
					 WriteToDigitalLine (2, "1", 6, 8, 0, value[2]);
					 WriteToDigitalLine (2, "1", 7, 8, 0, value[3]);
		
//				     WriteToDigitalLine (P.Switch[Switch].Tio.Board,P.Switch[Switch].Tio.sPort, P.Switch[Switch].Tio.lSwitch0, 32, 0, value[0]);
//	                 WriteToDigitalLine (P.Switch[Switch].Tio.Board,P.Switch[Switch].Tio.sPort, P.Switch[Switch].Tio.lSwitch1, 32, 0, value[1]);
//	                 WriteToDigitalLine (P.Switch[Switch].Tio.Board,P.Switch[Switch].Tio.sPort, P.Switch[Switch].Tio.lSwitch2, 32, 0, value[2]);
//	                 WriteToDigitalLine (P.Switch[Switch].Tio.Board,P.Switch[Switch].Tio.sPort, P.Switch[Switch].Tio.lSwitch3, 32, 0, value[3]);
	    			 break;
	    case NI_6602:WriteToDigitalLine (P.Switch[Switch].Nidaq.Board,P.Switch[Switch].Nidaq.sPort, P.Switch[Switch].Nidaq.lSwitch0, 32, 0, value[0]);
	                 WriteToDigitalLine (P.Switch[Switch].Nidaq.Board,P.Switch[Switch].Nidaq.sPort, P.Switch[Switch].Nidaq.lSwitch1, 32, 0, value[1]);
	                 WriteToDigitalLine (P.Switch[Switch].Nidaq.Board,P.Switch[Switch].Nidaq.sPort, P.Switch[Switch].Nidaq.lSwitch2, 32, 0, value[2]);
	                 WriteToDigitalLine (P.Switch[Switch].Nidaq.Board,P.Switch[Switch].Nidaq.sPort, P.Switch[Switch].Nidaq.lSwitch3, 32, 0, value[3]);
					 break;
		default:	 break;
		}
	}
	
/*MOVE SWITCH 1X4 */  
void MoveSwitch1X4_old(long Goal,char Switch){
     short value[3]={0, 0, 0};  
     switch (Goal) {
		case FIBER_OFF: value[0]=0;value[1]=0;value[2]=0;break; //off
		case FIBER_1:   value[0]=0;value[1]=0;value[2]=1;break; //fiber 1
		case FIBER_2:   value[0]=0;value[1]=1;value[2]=0;break; //fiber 2
		case FIBER_3:   value[0]=0;value[1]=1;value[2]=1;break; //fiber 3
		case FIBER_4:   value[0]=1;value[1]=0;value[2]=0;break; //line 4
		default: break;
		}
	 switch (P.Switch[Switch].Type) {
		case TIO:    WriteToDigitalLine (P.Switch[Switch].Tio.Board,P.Switch[Switch].Tio.sPort, P.Switch[Switch].Tio.lSwitch0, 8, 0, value[0]);
	                 WriteToDigitalLine (P.Switch[Switch].Tio.Board,P.Switch[Switch].Tio.sPort, P.Switch[Switch].Tio.lSwitch1, 8, 0, value[1]);
	                 WriteToDigitalLine (P.Switch[Switch].Tio.Board,P.Switch[Switch].Tio.sPort, P.Switch[Switch].Tio.lSwitch2, 8, 0, value[2]);
	    			 break;
	    case NI_6602:WriteToDigitalLine (P.Switch[Switch].Nidaq.Board,P.Switch[Switch].Nidaq.sPort, P.Switch[Switch].Nidaq.lSwitch0, 8, 0, value[0]);
	                 WriteToDigitalLine (P.Switch[Switch].Nidaq.Board,P.Switch[Switch].Nidaq.sPort, P.Switch[Switch].Nidaq.lSwitch1, 8, 0, value[1]);
	                 WriteToDigitalLine (P.Switch[Switch].Nidaq.Board,P.Switch[Switch].Nidaq.sPort, P.Switch[Switch].Nidaq.lSwitch2, 8, 0, value[2]);
					 break;
		default:	 break;
	    }
	 } 

/*MOVE SWITCH 1X4 _ MODIFICA */  
/*void MoveSwitch1X4(long Goal,char Switch){
     uInt8 value[3]={0, 0, 0};
	 int32 status,written;
	 
	// NOTE: IMPLEMENTED USING NIDAQmx (e.g. NIDAQmx)
	TaskHandle taskswitch0 = 0;
	TaskHandle taskswitch1 = 0;
	TaskHandle taskswitch2 = 0;	
	 
	status = DAQmxCreateTask ("Taskswitch0", &taskswitch0);
	status = DAQmxCreateTask ("Taskswitch1", &taskswitch1); 
	status = DAQmxCreateTask ("Taskswitch2", &taskswitch2); 	  
	 
	status = DAQmxCreateDOChan (taskswitch0, "Dev1/port1/line2", "SWITCH_0", DAQmx_Val_ChanForAllLines);
	status = DAQmxCreateDOChan (taskswitch1, "Dev1/port1/line3", "SWITCH_1", DAQmx_Val_ChanForAllLines);      
	status = DAQmxCreateDOChan (taskswitch2, "Dev1/port1/line4", "SWITCH_2", DAQmx_Val_ChanForAllLines);    
	 
	status = DAQmxStartTask (taskswitch0);
	status = DAQmxStartTask (taskswitch1);
	status = DAQmxStartTask (taskswitch2);
	 
    switch (Goal) {
		case FIBER_OFF: break;
		case FIBER_1: value[0]=1;value[1]=0;value[2]=0; break; 
		case FIBER_2: value[0]=0;value[1]=1;value[2]=0; break; 
		case FIBER_3: value[0]=1;value[1]=1;value[2]=0; break; 
		case FIBER_4: value[0]=0;value[1]=0;value[2]=1; break; 
		default: break;
		}

	status = DAQmxWriteDigitalLines (taskswitch0, 1, 1, 10.0, DAQmx_Val_GroupByChannel, &value[0], &written, NULL);
	status = DAQmxWriteDigitalLines(taskswitch1,1,1,10.0,DAQmx_Val_GroupByChannel,&value[1],&written,NULL); 
	status = DAQmxWriteDigitalLines(taskswitch2,1,1,10.0,DAQmx_Val_GroupByChannel,&value[2],&written,NULL); 

	status = DAQmxStopTask (taskswitch0);     
	status = DAQmxStopTask (taskswitch1);     
	status = DAQmxStopTask (taskswitch2);     

	status = DAQmxClearTask (taskswitch0);  
	status = DAQmxClearTask (taskswitch1);  
	status = DAQmxClearTask (taskswitch2);  

}  
*/


/*MOVE SWITCH 1X4 _ MODIFICA */  
void MoveSwitch1X4(long Goal,char Switch){
     uInt8 value[3]={0, 0, 0};
	 int32 status,written;
	 char chan1[STRLEN],chan2[STRLEN],chan3[STRLEN];
	 int port;
	 
	// NOTE: IMPLEMENTED USING NIDAQmx (e.g. NIDAQmx)
	TaskHandle taskswitch0 = 0;
	TaskHandle taskswitch1 = 0;
	TaskHandle taskswitch2 = 0;	
	 
	status = DAQmxCreateTask ("Taskswitch0", &taskswitch0);
	status = DAQmxCreateTask ("Taskswitch1", &taskswitch1); 
	status = DAQmxCreateTask ("Taskswitch2", &taskswitch2); 	  
	
	Scan (P.Switch[Switch].Port, "%s>%d", &port);
	
	sprintf (chan1, "Dev%d/port%d/line%d", P.Switch[Switch].Board+1, port,P.Switch[Switch].Line0+0);
	sprintf (chan2, "Dev%d/port%d/line%d", P.Switch[Switch].Board+1, port,P.Switch[Switch].Line0+1);
	sprintf (chan3, "Dev%d/port%d/line%d", P.Switch[Switch].Board+1, port,P.Switch[Switch].Line0+2);
	
	
	status = DAQmxCreateDOChan (taskswitch0, chan1, "SWITCH_0", DAQmx_Val_ChanForAllLines);
	status = DAQmxCreateDOChan (taskswitch1, chan2, "SWITCH_1", DAQmx_Val_ChanForAllLines);      
	status = DAQmxCreateDOChan (taskswitch2, chan3, "SWITCH_2", DAQmx_Val_ChanForAllLines);    
	 
	status = DAQmxStartTask (taskswitch0);
	status = DAQmxStartTask (taskswitch1);
	status = DAQmxStartTask (taskswitch2);
	 
    switch (Goal) {
		case FIBER_OFF: break;
		case FIBER_1: value[0]=1;value[1]=0;value[2]=0; break; 
		case FIBER_2: value[0]=0;value[1]=1;value[2]=0; break; 
		case FIBER_3: value[0]=1;value[1]=1;value[2]=0; break; 
		case FIBER_4: value[0]=0;value[1]=0;value[2]=1; break; 
		default: break;
		}

	status = DAQmxWriteDigitalLines (taskswitch0, 1, 1, 10.0, DAQmx_Val_GroupByChannel, &value[0], &written, NULL);
	status = DAQmxWriteDigitalLines(taskswitch1,1,1,10.0,DAQmx_Val_GroupByChannel,&value[1],&written,NULL); 
	status = DAQmxWriteDigitalLines(taskswitch2,1,1,10.0,DAQmx_Val_GroupByChannel,&value[2],&written,NULL); 

	status = DAQmxStopTask (taskswitch0);     
	status = DAQmxStopTask (taskswitch1);     
	status = DAQmxStopTask (taskswitch2);     

	status = DAQmxClearTask (taskswitch0);  
	status = DAQmxClearTask (taskswitch1);  
	status = DAQmxClearTask (taskswitch2);  

}  


// SWITCH 2X2EOL    
	
/* INITIALIZE SWITCH 2X2EOL */
void InitSwitch2X2EOL(char Switch){
	char port[2];
	int il=0;	
	int loop=P.Switch[Switch].Loop;
	short pstatus, data;
	int com, write;
	int open;
	char a[6];
	strcpy(port,P.Switch[Switch].Port);
	for (il=0;il<P.Loop[loop].Num;il++){   /*Controllo sui numeri di canali dello switch*/
		if ((P.Switch[Switch].Pos[il]>1)||(P.Switch[Switch].Pos[il]<0)){
			Failure("Number of fiber unknown");
			return;
			}
		}
	
 	switch (P.Switch[Switch].Type){
		case LPT: SetCtrlVal (hDisplay,DISPLAY_MESSAGE, "Inizializing Parallel Port... \n"); 
			   switch (P.Switch[Switch].Home) {		
			   		case FIBER_II:   data=0x00;break; //Channels parallel
		   	   		case FIBER_X:    data=0x01;break; //Channels crossed		
			   		default:         Failure("Home position unknown");break;
		       }
				pstatus = outpw(LPT1, data);
				Delay(0.006);
				SetCtrlVal (hDisplay,DISPLAY_MESSAGE, "Parallel Port Inizialized \n");
				break;
		case COM: SetCtrlVal (hDisplay,DISPLAY_MESSAGE, "Inizializing Serial Port...\n"); 
			  com=P.Switch[Switch].Line0; 			  
			  open=OpenComConfig(com,"",57600,0,8,1,512,512);
			  a[0]='c'; a[1]='h'; a[2]='0'; a[3]='\r'; a[4]='\n';a[5]='\0';
			  com=P.Switch[Switch].Line0;
			   switch (P.Switch[Switch].Home) {
				    
				  	case FIBER_II:  a[2]='1'; break; //Channels parallel 
					case FIBER_X:   a[2]='2'; break; //Channels crossed
					default:        Failure("Home position unknown");break;
				}
			 write=ComWrt(com,a,6);
     	     Delay (0.006); 
			 SetCtrlVal (hDisplay,DISPLAY_MESSAGE, "Serial Port inizialized: COM\n");
			     
			 break;
		default: break;
 	}

}

/*MOVE SWITCH 2X2EOL:*/  
void MoveSwitch2X2EOL (long Goal, char Switch) {
	short pstatus, data;
	int com,write;
	char a[6];

     switch (P.Switch[Switch].Type){
			case LPT:     		//Porta Parallela
                       	
						if (P.Switch[Switch].Home==0) {
				
						switch (Goal) {		
							case FIBER_II:   data=0x00; break; //Channels parallel
							case FIBER_X:    data=0x01; break; //Channels crossed
							default: break;
										}
   						pstatus = outpw(LPT1, data);
     					Delay (0.006);
						//SetCtrlVal (hDisplay,DISPLAY_MESSAGE, "Switch Moved -----> Ready\n");   
						break;
						}
						
						else {
							switch (Goal) {		
							case FIBER_II:   data=0x01; break; //Channels crossed
							case FIBER_X:    data=0x00; break; //Channels parallel
							default: break;
										}
   						pstatus = outpw(LPT1, data);
     					Delay (0.006);
						break;
						}
						
							
			case COM:  	   //Porta Seriale
     					
						a[0]='c'; a[1]='h'; a[2]='0'; a[3]='\r'; a[4]='\n';a[5]='\0';
						com=P.Switch[Switch].Line0;
						
						if (P.Switch[Switch].Home==0) {
		
     					switch (Goal) {		
							case FIBER_II:   a[2]='1'; break; //Channels parallel     
							case FIBER_X:    a[2]='2'; break; //Channels crossed     
							default: break;
										}
     					write=ComWrt(com,a,6);
     					Delay (0.006);
						//SetCtrlVal (hDisplay,DISPLAY_MESSAGE, "Switch Moved -----> Ready\n"); 
						break;
						}
						
						else {
							switch (Goal) {		
							case FIBER_II:   a[2]='2'; break; //Channels crossed     
							case FIBER_X:    a[2]='1'; break; //Channels parallel     
							default: break;
										}
     					write=ComWrt(com,a,6);
     					Delay (0.006);
						//SetCtrlVal (hDisplay,DISPLAY_MESSAGE, "Switch Moved -----> Ready\n"); 
						break;   
						}
							
							
	     	default:break;
								}   
	
 }
     









/* ########################   SYNC PROCEDURES   ########################### */ 

/* INITIALISE SYNC FUNCTIONS */
void InitSync(void){
    short  pstatus;
	short  off=0x00;
	if(!P.Sync.Sync) return;
	if(P.Sync.Dir==SYNC_INPUT) return;
	SetCtrlVal (hDisplay,DISPLAY_MESSAGE, "Initializing Sync for output ... ");
    pstatus = outpw(LPT1, off);
	Passed();
	}	   


/* START GET/SEND SYNC */
void StartSync(void){
	short  off=0x00;
	short  on=0x01;
	if(!P.Sync.Sync) return;
	switch (P.Sync.Dir) {
		case SYNC_INPUT:
			while(inpw(LPT1)==off);
			break;
		case SYNC_OUTPUT:
			outpw (LPT1,on);
			if(P.Sync.Pattern==SYNC_CONT) break;
			Delay(P.Sync.Width);
			outpw (LPT1,off);
			break;
		}
	}


/* STOP GET/SEND SYNC */
void StopSync(void){
 	short  off=0x00;
	short  on=0x01;
	if(!P.Sync.Sync) return;
	switch (P.Sync.Dir) {
		case SYNC_INPUT:
			switch (P.Sync.Pattern) {
				case SYNC_ONE: break;
				case SYNC_TWO: while(inpw(LPT1)==off); break;
				case SYNC_CONT: while(inpw(LPT1)==on); break;
				}
		case SYNC_OUTPUT:
			switch (P.Sync.Pattern) {
				case SYNC_ONE: break;
				case SYNC_TWO: 
					outpw (LPT1,on);
					Delay(P.Sync.Width);
					outpw (LPT1,off);
					break;
				case SYNC_CONT: outpw (LPT1,off); break;
				}
 		}
	}


/* ########################   OMA PROCEDURES   ########################### */ 

/* Initialize OMA connection */
void InitOma(void){
	char oma_address[OMA_ADDRESS_LENGHT],tempBuf[OMA_BUFFER_LENGHT]={0};
	
	if(!P.Oma.Oma) return;
	P.Oma.DataStored=0;
	P.Oma.Ready=0;
	P.Oma.FileYes=0;
	P.Oma.FileDirOk=0;
	P.Oma.FileNameOk=0;
	if ((P.Oma.File=fopen(OMA_IP_ADDRESS_FILE,"r"))==NULL){
		Failure("Oma IP Address File error.");
		return;
		}
	SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "Initializing TCP/IP communication with OMA USB2000...\n");
	fscanf(P.Oma.File,"%s",oma_address);
    if (ConnectToTCPServer (&P.Oma.g_hconv, OMA_PORT, oma_address, ClientTCPCB,NULL, 5*OMA_WAIT_TIME) < 0){
        Failure("Connection to server failed!");
        return;
    	}
        
    /* We are successfully connected -- gather info */
    GetTCPHostAddr (tempBuf, OMA_BUFFER_LENGHT);
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "Client IP Address: ");
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE, tempBuf);
    
    GetTCPHostName (tempBuf, OMA_BUFFER_LENGHT);
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "\nClient Name: ");
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE, tempBuf);
    
    GetTCPPeerAddr (P.Oma.g_hconv, tempBuf, OMA_BUFFER_LENGHT);
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "\nOmaServer IP Address: ");
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE, tempBuf);
    
    GetTCPPeerName (P.Oma.g_hconv, tempBuf, OMA_BUFFER_LENGHT);
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "\nOmaServer Name: ");
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE, tempBuf);
	SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "\n...");
	Passed();
    //SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "Remember to push 'Start' in OMA before every measure!\n");
	
	
	if (ClientTCPWrite (P.Oma.g_hconv, "FILENAME?",9, OMA_WAIT_TIME) < 0)
		Failure("InitOma error.");
	SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "\nOma, do you want the filename?...");
	
	while((P.Oma.FileYes==0)&&(P.Command.Abort==FALSE))
		ProcessSystemEvents();
	
	
	if(P.Oma.FileYes==1){
		SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "Yes!!\n");
		strcpy(tempBuf,"D");
		strcat(tempBuf,P.File.Dir);
		
		if(ClientTCPWrite(P.Oma.g_hconv,tempBuf,strlen(tempBuf),OMA_WAIT_TIME)<0)
			Failure("FileDir error.");
		//tempBuf[OMA_BUFFER_LENGHT]={0};
		while((P.Oma.FileDirOk==0)&&(P.Command.Abort==FALSE))
		ProcessSystemEvents();
		
		strcpy(tempBuf,"N");
		strcat(tempBuf,P.File.Name);
		if(ClientTCPWrite(P.Oma.g_hconv,tempBuf,strlen(tempBuf),OMA_WAIT_TIME)<0)
			Failure("FileName error.");
		while((P.Oma.FileNameOk==0)&&(P.Command.Abort==FALSE))
		ProcessSystemEvents();
		
	}
	
		
	if(P.Oma.FileYes==2)
		SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "No!!\n");
	
	
	
	
	if (ClientTCPWrite (P.Oma.g_hconv, "READY?",OMA_READY_STRING_LENGHT, OMA_WAIT_TIME) < 0)
		Failure("InitOma error.");			
	SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "\nOma,Ready?...");
	
	

	// Send File Directory & Name
	//**ClientTCPWrite(P.Oma.g_hconv,P.File.Name,strlen(P.File.Name),OMA_WAIT_TIME);
	//**ClientTCPWrite(P.Oma.g_hconv,P.File.Dir,strlen(P.File.Dir),OMA_WAIT_TIME);
	
	while((P.Oma.Ready==0)&&(P.Command.Abort==FALSE))
		ProcessSystemEvents();
	SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "Ready!!\n");
	}
	
/* Start OMA acquisition */
void StartOma(){
	char transmitBuf[2*OMA_BUFFER_LENGHT]={0};
	
	if(!P.Oma.Oma) return;
	strcat(transmitBuf,"OMA_START_ACQUISITION");
	P.Oma.DataStored=0;
	
	if (ClientTCPWrite (P.Oma.g_hconv, transmitBuf,strlen (transmitBuf) + 1, OMA_WAIT_TIME) < 0)
		Failure("StartOma error.");			
	}
	
/* Wait OMA end of acquisition */
void StopOma(){
	
	if(!P.Oma.Oma) return;
	//strcat(transmitBuf,"OMA_STOP_ACQUISITION");
	
	//if (ClientTCPWrite (P.Oma.g_hconv, transmitBuf,strlen (transmitBuf) + 1, OMA_WAIT_TIME) < 0)
		//Failure("StopOma error.");			
	
	while ((P.Oma.DataStored==0)&&(P.Oma.DataStored!=-1))
		ProcessSystemEvents();
	}

/* Close OMA connection */
void CloseOma(){
	char transmitBuf[2*OMA_BUFFER_LENGHT]={0};
	int err;
	
	if(!P.Oma.Oma) return;
	strcat(transmitBuf,"OMA_END_OF_LOOP");
	
	err=ClientTCPWrite (P.Oma.g_hconv, transmitBuf,strlen (transmitBuf) + 1, 5*OMA_WAIT_TIME);	
	if (( err< 0)&&(err!=OMA_NO_CONNECTION))
		Failure("CloseOma error.");			
    DisconnectFromTCPServer (P.Oma.g_hconv);
	}
	

/*---------------------------------------------------------------------------*/
/* This is the TCP client's TCP callback.  This function will receive event  */
/* notification, similar to a UI callback, whenever a TCP event occurs.      */
/* We'll respond to the DATAREADY event and read in the avaiable data from   */
/* the server and display it.  We'll also respond to DISCONNECT events, and  */
/* tell the user when the server disconnects us.                             */
/*---------------------------------------------------------------------------*/
int CVICALLBACK ClientTCPCB (unsigned handle, int event, int error,
                             void *callbackData)
{
    int  dataSize         = OMA_BUFFER_LENGHT;
    int i;
    char *ib,*ip;
    char receiveBuf[OMA_BUFFER_LENGHT] = {0};
    double receivePeak, receiveBaric;

    switch (event)
        {
        case TCP_DATAREADY:
           if ((dataSize = ClientTCPRead (P.Oma.g_hconv, receiveBuf,dataSize, OMA_WAIT_TIME))< 0)
                Failure ("Receive Error\n");
            else{
            	if(strcmp (receiveBuf, "READY!")==0){
            		P.Oma.Ready=1;
            		break;
            	}
            	
            /*ricezione conferma della modalità col nomefile automatico*/	
            	if(strcmp (receiveBuf, "YES!")==0){
            		P.Oma.FileYes=1;
            		break;
            	}
            	if(strcmp (receiveBuf, "NO!")==0){
            		P.Oma.FileYes=2;
            		break;
            	}
            	if(strcmp (receiveBuf, "FILE_DIR_OK!")==0){
            		P.Oma.FileDirOk=1;
            		break;
            	}
            	if(strcmp (receiveBuf, "FILE_NAME_OK!")==0){
            		P.Oma.FileNameOk=1;
            		break;
            	}
            
            /* conversione della stringa in float */
            	i=0;
            	if(receiveBuf[0]=='b'){	
					receiveBaric=strtod (receiveBuf+1, &ib);
					receivePeak=strtod (ib+1, &ip);
				}else
            		Failure ("Data string error");
            	
            /* salvataggio dei dati */   
			P.Oma.Baric=receiveBaric;
			P.Oma.Peak=receivePeak;
			sprintf (receiveBuf, "%.3f", receiveBaric);
			SetCtrlVal (hDisplay, DISPLAY_MESSAGE, receiveBuf);
			SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "\n");
			P.Oma.DataStored=1;
			/***/
			strcpy (receiveBuf, "OMA_DONE");
			if (ClientTCPWrite (P.Oma.g_hconv, receiveBuf,strlen (receiveBuf) + 1, OMA_WAIT_TIME) < 0)
					Failure("OmaDone error");			
            }
            break;
            
        case TCP_DISCONNECT:
            Failure ("Server has closed connection!");
            P.Oma.g_hconv = 0;
            P.Command.Abort=TRUE;
            P.Oma.DataStored=-1;
            break;
    }
    return 0;
}


/* ########################   OPHIR PROCEDURES   ######################## */

/* INITIALIZE OPHIR*/								 
void InitOphir(void) {
	int open;
	char power [255];
	int com=1;
	char *filename;
	long size;
	
	if(!P.Ophir.Ophir) return;
	//sprintf(message,"Initializing Ophir on COM%d...",com);
    //SetCtrlVal (hDisplay, DISPLAY_MESSAGE,message);
	open=OpenComConfig(com,NULL,FPM_BAUDRATE,FPM_PARITY,FPM_DATABITS,FPM_STOPBITS,0,-1);
	FlushInQ (com);
	FlushOutQ (com);
	filename = power;
	strcpy(power, P.File.Dir);
	strcat(power, "\\");
	strcat(power, P.File.Name);
	strcat(power, ".txt");
	SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "Initializing File ");
	SetCtrlVal (hDisplay, DISPLAY_MESSAGE, power);
	SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "...");
	if( GetFileInfo (power, &size))  EnterName();
    P.Ophir.File = fopen(power,"w");
    if(P.Ophir.File == NULL) Failure("Error Creating File Data"); else Passed();
	SetCtrlVal (hDisplay, DISPLAY_MESSAGE," PASSED!\n");
    }
				 

/* CLOSE OPHIR*/
void CloseOphir(void){
	int com=1;
	if(!P.Ophir.Ophir) return;

    fclose(P.Ophir.File);
	FlushInQ (com);
	FlushOutQ (com);
	CloseCom (com);
	}


/* ASK FPM FOR LASER INTENSITY */
void GetOphir(void){
	char loop=P.Ophir.Loop;
    int Com=1;
    int loop_value=P.Loop[loop].First+P.Loop[loop].Actual*P.Loop[loop].Delta;
    char stringa[OPHIR_STRLEN] = "";
	int num;
	int bytes_read;
	if(!P.Ophir.Ophir) return;
	num=ComWrt(Com,"$SP\r",4);
    bytes_read = ComRdTerm(Com, stringa, OPHIR_STRLEN, 13);
    stringa[0] = 32; 
    fprintf(P.Ophir.File, "%i\t", loop_value);  
    fprintf(P.Ophir.File, "%s\n", stringa);
    }  							   
    

/* ########################   STEPPER PROCEDURES   ######################## */

/* START CONTINUOUS MOVEMENT */
void StartCont(char Step, char Status){
	double freq;
	long delta;
	int num_meas=1;
	int imeas,il;
	int iloop = P.Loop[P.Step[Step].Loop].Actual;
	for(il=P.Step[Step].Loop+1;il<MAX_LOOP;il++) num_meas*=P.Loop[il].Num;
	switch (P.Step[Step].Loop) {
		case LOOP3: imeas=1; break;
		case LOOP2: imeas=P.Loop[LOOP3].Actual+1; break;
		case LOOP1: imeas=P.Loop[LOOP3].Actual+1+P.Loop[LOOP2].Actual*P.Loop[LOOP3].Num; break;
		}
	switch (P.Loop[P.Step[Step].Loop].Cont) {
		case CONT_STEP: freq=fabs(P.Step[Step].Stop[iloop]-P.Step[Step].Start[iloop])/(num_meas*P.Spc.TimeM); break;
		case CONT_RANGE: freq=fabs(P.Step[Step].Delta)/(num_meas*P.Spc.TimeM*P.Loop[P.Step[Step].Loop].Num); break;
		}
	SetVel(Step,freq);
	if((P.Wait.Type==WAIT_POS)&&(P.Wait.Step==Step)){
		delta=P.Step[Step].Stop[iloop]-P.Step[Step].Start[iloop];
		P.Wait.Pos=P.Step[Step].Start[iloop]+(imeas*delta/num_meas);
		}
	MoveStep(&P.Step[Step].Actual,P.Step[Step].Stop[iloop],Step,FALSE,Status);
	}


/* WAIT CONTINUOUS MOVEMENT */
void WaitCont(char Step, char Status){
	int iloop = P.Loop[P.Step[Step].Loop].Actual;
	WaitStep(&P.Step[Step].Actual,P.Step[Step].Stop[iloop],Step,Status);
	}


/* INITIALIZE STEPPER MOTOR */
void InitStep(char Step){
	P.Step[Step].Moving = FALSE;
	switch(P.Step[Step].Type){
		case LPT: InitLpt(); break;
		case NEWP: InitNewp(P.Step[Step].Speed,P.Step[Step].Axis,Step); break;
		case MM4005: InitNewp4005(P.Step[Step].Speed,P.Step[Step].Axis,Step); break; //floriano
		case TIO:  InitTio(P.Step[Step].Axis,Step); break;
		case MIO:  InitMio(P.Step[Step].Axis,Step); break;
		case MICRO:  InitMicro(Step); break;
		case PWM:	InitPwm(Step); break;
		case MONO:	InitMono(Step); break;
		case MONO_TCP:	InitMonoTcp(Step); break; 
		case PI:	InitPi(Step); break;
		case FPM:	InitFpm(Step); break;
		case DELAYER:	InitDelayer(Step); break;
		case ADC: InitAdc(); break;
		case AOTF_FREQ:	 break;
		case AOTF_POW: break;
		case NONE: break;
		}
	if(P.Step[Step].Mode==STEP_CONT) SetVel(Step,fabs(P.Step[Step].Delta/(P.Spc.TimeM*P.Loop[P.Step[Step].Loop].Num)));
	else SetVel(Step, P.Step[Step].Freq);
	
	}


/* CLOSE STEPPER MOTOR */
void CloseStep(char Step){
	switch(P.Step[Step].Type){
		case LPT: break;
		case NEWP: break;
		case MM4005: break;
		case TIO:  CloseTio(P.Step[Step].Axis,Step); break;
		case MIO: break;
		case MICRO: CloseMicro(Step); break;
		case PWM: ClosePwm(Step); break;
		case MONO: CloseMono(Step); break;
		case MONO_TCP: CloseMonoTcp(Step); break;   
		case PI: ClosePi(); break;
		case FPM: CloseFpm(Step); break;
		case DELAYER: break;
		case ADC: break;
		case AOTF_FREQ:	break;
		case AOTF_POW:	break; 
		case NONE: break;
		}
	}


/* SET STEPPER VELOCITY */
void SetVel(char Step, double Freq){
	Freq = fabs(Freq);
	switch(P.Step[Step].Type){
		case LPT: break;
		case NEWP: SetVelNewp(Freq); break;
		case MM4005: SetVelNewp4005(Step,Freq); break;
		case TIO:  SetVelTio(Step,Freq); break;
		case MIO: break;
		case MICRO:  SetVelMicro(Step,Freq); break;
		case PWM:  SetVelPwm(Step,Freq); break;
		case MONO:  SetVelMono(Step,Freq); break;
		case MONO_TCP: SetVelMonoTcp(Step,Freq); break;
		case PI:  SetVelPi(Freq); break;
		case FPM: break;	/* Need no velocity setting */
		case DELAYER: break;
		case ADC: break;
		case AOTF_FREQ: break; /* Need no velocity setting */
		case AOTF_POW: break; /* Need no velocity setting */
		case NONE: break;
		}
	P.Step[Step].FreqActual=Freq;
	}

/* INIT INCREMENT POS/NEG VERSION*/
void InitPos(char Step){
	int il,is,ns;
	int sethome = FALSE;
	int numread = 0;
	char set_stop = TRUE;
	long label;
	int loop=P.Step[Step].Loop;
	long num=P.Loop[loop].Num;
	double dpos[2];
	char message[STRLEN];
	char row0[STRLEN],string[3][STRLEN];
	char *row;
	FILE *fpos;

	P.Step[Step].DiffHome=FALSE;
	//**if(P.Loop[P.Step[Step].Loop].Cont != CONT_NONE) num+=1; 
	sprintf(message,"Initializing Array Position for Stepper # %d ... ",Step+1);
	SetCtrlVal (hDisplay,DISPLAY_MESSAGE,message);
    if(strlen(P.Step[Step].FName)==0){
		P.Step[Step].Home = (long)(P.Loop[loop].Home*P.Step[Step].Factor); 
    	for(il=0;il<num;il++){
    		P.Step[Step].Start[il]=(long)(P.Step[Step].Factor*(P.Loop[loop].First+il*P.Loop[loop].Delta));
    		P.Step[Step].Stop[il]=(long)(P.Step[Step].Factor*(P.Loop[loop].First+(il+1)*P.Loop[loop].Delta));
	    	}
    	}
    else {
    	fpos=fopen(P.Step[Step].FPath,"r");
		if(fpos==NULL){
			Failure("Error Loading File Position");
			return;
			}				
	   	while(fgets(row0,STRLEN,fpos)!=NULL){
			row=row0;
			ns=0;
			while(sscanf(row,"%s",string[ns])!=EOF) row+=strlen(string[ns++])+1;
			sscanf(string[0],"%d",&label);
			for(is=1;is<ns;is++) sscanf(string[is],"%lf",&dpos[is-1]);

			if(label==P.Loop[loop].Home)
				if(!sethome){
					P.Step[Step].Home = (long)(dpos[0]*P.Step[Step].Factor+0.5); 
					sethome = TRUE;
					}
				else
					P.Step[Step].DiffHome=TRUE;

	    	set_stop = TRUE;
	    	for(il=0;il<num;il++){
				if(label==(P.Loop[loop].First+il*P.Loop[loop].Delta)){
					P.Step[Step].Start[il]=(long)(dpos[0]*P.Step[Step].Factor+0.5);
					numread++;
					if(!set_stop) P.Step[Step].Stop[il-1]=P.Step[Step].Start[il]; // for il=0,set_stop=TRUE;
					if((ns-1)>1) set_stop = TRUE; else set_stop = FALSE;
					if(set_stop) P.Step[Step].Stop[il]=(long)(dpos[1]*P.Step[Step].Factor+0.5);
					}
				}
			}
		fclose(fpos);
		if(numread<(num-1)){ Failure("Error: Not Enough Points on File Pos"); return;}
		}
	if((P.Step[Step].Type==NEWP)&&(P.Step[Step].Axis==AXIS1)){
	    	for(il=0;il<num;il++)
				P.Step[Step].Start[il] -= P.Step[Step].Home;
			P.Step[Step].Home = 0;
			}
	P.Step[Step].Delta=P.Step[Step].Stop[num-1]-P.Step[Step].Start[0];
	P.Step[Step].Actual=P.Step[Step].Home;
	sprintf(message,"Home=%ld  ",P.Step[Step].Home);
	SetCtrlVal (hDisplay,DISPLAY_MESSAGE,message);
	Passed();
	}


/* INIT BREAK FILE*/
void InitBreak(char Loop){
	int ie;
	char message[STRLEN];
	char row[STRLEN];
	FILE *fbreak;

    if(strlen(P.Loop[Loop].FName)==0) return;
	sprintf(message,"Initializing File Break for Loop # %d ... ",Loop+1);
	SetCtrlVal (hDisplay,DISPLAY_MESSAGE,message);
   	fbreak=fopen(P.Loop[Loop].FPath,"r");
	if(fbreak==NULL){
		Failure("Error Loading File Break");
		return;
		}
	ie=0;
	while(fgets(row,STRLEN,fbreak)!=NULL){
		sscanf(row,"%d%d",&P.Loop[Loop].ExceptLabel[ie],&P.Loop[Loop].ExceptValue[ie]);
		ie++;
		}
	P.Loop[Loop].ExceptNum=ie;
	fclose(fbreak);
	Passed();
	}


/* DEFINE HOME */
void DefineHome(char Step){
	switch(P.Step[Step].Type){
		case LPT: break; 
		case NEWP: DefineHomeNewp(Step); break;
		case MM4005: DefineHomeNewp4005(Step); break;
		case TIO: break;
		case MIO: break;
		case MICRO: DefineHomeMicro(Step); break;
		case PWM: DefineHomePwm(Step); break;
		case MONO: DefineHomeMono(Step); break;
		case MONO_TCP: DefineHomeMonoTcp(Step); break;               
		case PI: DefineHomePi(Step); break;               
		case FPM: break;	/* Need no home definition ! */
		case DELAYER: break;
		case ADC: break;
		case AOTF_FREQ: break;
		case AOTF_POW: break; 
		case NONE: break;
		}
		P.Step[Step].Actual=P.Step[Step].Home;
	}

/* INVERT ARRAY INDEX */
void InvertIndex(void){
	//TODO: DA RIVEDERE
    }


/* CALCULATE GOAL FOR STEPPER */
long CalcGoal(char Step){
	char loop = P.Step[Step].Loop;
	long index;
	index = P.Loop[loop].Actual;
	return(P.Step[Step].Start[index]);
	}


/* MOVE STEPPER MOTOR */
void MoveStep(long *Actual,long Goal,char Step,char Wait,char Status){
	char dir;
	long delta;
	int is;
	char on = FALSE;
	if(Status) SetCtrlVal (hDisplay, DISPLAY_MOVE, ON);
	P.Step[Step].Moving = TRUE;
	delta=Goal-*Actual;
	if(delta>0) P.Step[Step].Dir=1; else P.Step[Step].Dir=-1;
	dir=P.Step[Step].Dir;
	switch (P.Step[Step].Type){
		case NONE: break;
		case LPT:  MoveLpt(Step,abs(delta),dir); break;
		case NEWP: MoveNewp(Step,Goal,delta,P.Step[Step].Axis,P.Step[Step].Speed,Wait); break;
		case MM4005: MoveNewp4005(Step,Goal,delta,P.Step[Step].Axis,P.Step[Step].Speed,Wait); break;
		case TIO:  MoveTio(Step,abs(delta),dir,Wait);break;
		case MIO:  MoveMio(Step,Goal);break;
		case MICRO: MoveMicro(Step,Goal,Wait); break;
		case PWM: MovePwm(Step,Goal,Wait); break;
		case MONO: MoveMono(Step,Goal,Wait); break;
		case MONO_TCP: MoveMonoTcp(Step,Goal,Wait); break;   
		case PI: MovePi(Step,Goal,Wait); break;
		case FPM: MoveFpm(Step, Goal); break;	/* Fiber power monitor: actually read Power  */
		case DELAYER: MoveDelayer(Step, Goal); break;
		case ADC: StartAdc(); break;	/* Analog to digital converter: actually read Power  */
		case AOTF_FREQ: SetFreqNI_USB6229(Step, Goal); break;
		case AOTF_POW: SetVoltNI_USB6221(Step, Goal); break;
		}
	P.Spc.Trash=TRUE;
	if(Wait) return;	
	//if(Status) SetCtrlVal (hDisplay, P.Step[Step].Control, (P.Step[Step].Actual/(1.0*P.Step[Step].Factor)));//TODO: Check for TRIM
	P.Step[Step].Moving = FALSE;
	if(Status){
		for(is=0;is<MAX_STEP;is++)
			if(P.Step[is].Step)
				on |= P.Step[is].Moving;
		if(!on) SetCtrlVal (hDisplay, DISPLAY_MOVE, OFF);
		}
	}

/* STOP STEPPER */
void StopStep(char Step){
	switch (P.Step[Step].Type){
		case NONE: break;
		case LPT:  break;
		case NEWP: break;
		case MM4005: break;
		case TIO:  StopTio(Step);break;
		case MIO:  break;
		case MICRO: StopMicro(Step); break;
		case PWM: StopPwm(Step); break;
		case MONO: break;
		case MONO_TCP: break;
		case PI: StopPi(); break;
		case FPM: StopFpm(Step); break;
		case ADC: StopAdc(); break;
		case DELAYER: break;
		case AOTF_FREQ: break;
		case AOTF_POW: break;
		}
	}

/* TELL POSITION */
void TellPos(char Step,long *Position){
	switch(P.Step[Step].Type){
		case LPT: break;
		case NEWP: TellPosNewp(Step,Position); break;
		case MM4005: TellPosNewp4005(Step,Position); break;
		case TIO: TellPosTio(Step,Position); break;
		case MIO: break;
		case MICRO: TellPosMicro(Step,Position); break;
		case PWM: TellPosPwm(Step,Position); break;
		case MONO: TellPosMono(Step,Position); break;
		case MONO_TCP: TellPosMonoTcp(Step,Position); break;
		case PI: TellPosPi(Step,Position); break;
		case FPM: break;
		case DELAYER: break;
		case ADC: break;
		case NONE: break;
		case AOTF_FREQ: break;
		case AOTF_POW: break;
		}
	}

/* WAIT FOR POSITION */
void WaitPos(char Step,long Goal){
	long pa;
	char is_success, is_timeout, is_first, is_equal;
	double t0, t1, tmax;
	long last=P.Step[Step].Actual;
	if(P.Step[Step].Type==NONE) return;
	is_first=TRUE;
	do{
		TellPos(Step,&pa);
		is_success=((P.Step[Step].Dir==1)?(pa>=Goal):(pa<=Goal));
		is_equal=(pa==last);
		if(!is_equal) is_first=TRUE;
		last=pa;
		is_timeout=is_equal;
		if(is_equal&&!is_first){
			t1=TimerN();
			tmax=1.0/(P.Step[Step].FreqActual/2.0);
			is_timeout=((t1-t0)>(2*tmax));
			}
		if(is_equal&&is_first){
			t0=TimerN();
			is_first=FALSE;
			is_timeout=FALSE;
			}
		}
	while((!is_success)&&(!is_timeout));
	//**SetTableCellAttribute (hDisplay,DISPLAY_T_TRIS,MakePoint(COL_TRIS_STEP,Step+1),ATTR_CTRL_VAL,(double)pa);
	//**ProcessDrawEvents ();

	//**P.Step[Step].Actual=pa;  // Corrected for MAMM, check in TRIM
	}

/* WAIT FOR END STEPPER */
void WaitStep(long *Actual,long Goal,char Step,char Status){
	//if(!P.Step[Step].Started) return;   // modified to comply with delta==0;
	switch (P.Step[Step].Type) {
		case LPT: break;
		case NEWP: /*WaitNewp(Step,Goal);*/ break;
		case MM4005: break;  
		case TIO: WaitTio(Step,abs(Goal-*Actual),P.Step[Step].Dir); break;
		case MIO: break;
		case MICRO: WaitMicro(Step,Goal); break;
		//case PWM: WaitPwm(Step,Goal); break;
		case MONO: WaitMono(Step,Goal); break;
		case MONO_TCP: WaitMonoTcp(Step,Goal); break;     
		case PI: WaitPi(Step,Goal); break;
		case AOTF_FREQ: break;
		case AOTF_POW: break;
		default: break;
		}
	}


// ### STEPPER WITH PARALELL PORT ###

/* INITIALIZE MONO STEP MOTOR BY PARALLEL PORT */
void InitLpt(void) {
    short  pstatus, data;
	SetCtrlVal (hDisplay,DISPLAY_MESSAGE, "Initializing Parallel Port ... ");
    data=0x00;
    pstatus = outpw(LPT1, data);
	Passed();
	}	   


/* MOVE LPT STEPPER */
void MoveLpt(char Step,long Inc,char Dir){
	short pstatus;
	long ic;
	double sleep_mono;
	char dirlevel=(P.Step[Step].Sign==STEP_SIGN_POS?Dir:-Dir);
	char axis = P.Step[Step].Axis;
	char cw = (axis==AXIS1?STEP_LPT_CW_1:STEP_LPT_CW_2);
	char awo = (axis==AXIS1?STEP_LPT_AWO_1:STEP_LPT_AWO_2);
	char on = (axis==AXIS1?STEP_LPT_ON_1:STEP_LPT_ON_2);
    char data = 0x00;
	if (dirlevel==-1)  data&=~cw; else data|=cw;
    data |= ~awo;
    pstatus = outpw(LPT1, data);
	for (ic=0; ic<Inc; ic++){
		sleep_mono=CalcSleepStep(ic,Inc,P.Step[Step].Freq,P.Step[Step].Freq);
		data |= on;
		pstatus =outpw(LPT1, data);
		Delay (sleep_mono/2);
		data &= ~on;  
		pstatus = outpw(LPT1, data);
		Delay (sleep_mono/2);
        }
    data &= awo;
    pstatus = outpw(LPT1, data);
    P.Step[Step].Actual+=Dir*Inc;
	}


/* CALCULATE SLEEP TIME FOR STEPPER RAMP */
double CalcSleepStep(long it, long StepMax, double FreqMax, double FreqMin){
	double SleepMax = 1/FreqMin;
	double SleepMin = 1/FreqMax;
	double half = StepMax*0.5;
	double sleep = (double) (SleepMax*pow(1+(half-fabs(half-it)),-1.0/EXP_STEP));
	sleep = ((sleep>SleepMin) ? sleep : SleepMin);
	return sleep;
	};


// #### NEWPORT STEPPER

/* INITIALIZE NEWPORT */
void InitNewp(double speed, char Axis, char Step){
	long rampvel,maxvel,rampwidth,setvel;
	char saxis[STRLEN];
	char command[STRLEN];
    InitIeee();
    if(Axis==AXIS1) strcpy(saxis,"01"); else strcpy(saxis,"02");
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "Initializing Newport Stepper");
    
    // Initialize Gpib Communication with Newport
   	SendIFC (GPIB0);
    DevClear (GPIB0, 02);
	ibtmo (GPIB0, T100s);

	// Calculate Newport Parameters
	if(P.Step[Step].Speed==FAST){
		rampvel=NEWP_FAST_RV;
		maxvel=NEWP_FAST_XV;
		rampwidth=NEWP_FAST_RW;
		setvel=(unsigned long)(P.Step[Step].Freq*NEWP_VEL_CORR);
		}
	else {
		rampvel=NEWP_SLOW_RV;
		maxvel=NEWP_SLOW_XV;
		rampwidth=NEWP_SLOW_RW;
		setvel=(unsigned long)(P.Step[Step].Freq*NEWP_VEL_CORR);
		}
/*	if(P.Step[Step].Mode==STEP_CONT){
		setvel=(unsigned long)((NEWP_VEL_CORR*P.Step[Step].Delta)/(P.Spc.Time*(P.Loop[P.Step[Step].Loop].Num-1)));
		rampvel=(setvel<NEWP_CONT_RV?setvel:NEWP_CONT_RV);
		maxvel=NEWP_CONT_XV;
		rampwidth=NEWP_CONT_RW; 
		}						*/

	// Send Parameters to Newport
	sprintf(command,"%sRV%d,%sXV%d,%sRW%d,%sRX",saxis,rampvel,saxis,maxvel,saxis,rampwidth,saxis);
    GpibWrite(GPIBNEWP,command);   
    Delay(5);
    sprintf(command,"%sSV%d",saxis,setvel);
    GpibWrite(GPIBNEWP,command);   
   	Delay (5);
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "PASSED\n");
	}


void SetVelNewp(double Freq){
	char command[STRLEN];
    sprintf(command,"01SV%d",(1+(long)(Freq)));
    GpibWrite(GPIBNEWP,command);   
   	Delay (0.2);//0.2
    }


/* DEFINE HOME */
void DefineHomeNewp(char Step){
	char saxis[STRLEN];
	char command[STRLEN];
	if(P.Step[Step].Axis==AXIS2) return;
    if(P.Step[Step].Axis==AXIS1) strcpy(saxis,"01"); else strcpy(saxis,"02");
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "Initializing Newport Home ...");
	sprintf(command, "%sDH",saxis);
    GpibWrite(GPIBNEWP,command);   
    Delay(1);
	TellPos(Step,&P.Step[Step].Actual);
    Passed();
    }
	


/* MOVE NEWPORT */
void MoveNewp(char Step, long Goal, long Delta, char Axis, char Speed, char Wait){
	char answer[STRLEN]; 
	char comstring[STRLEN];
	char saxis[3];
	long pa;
	int iter=0;
	
	saxis[0]='0';
	if(Axis==AXIS1) saxis[1]='1'; else saxis[1]='2';
	saxis[2]='\0';
	if(Wait)
		if(Axis==AXIS1) sprintf(comstring,"01PA%d,WS,SY",Goal);
		else sprintf(comstring,"02PR%d,WS,SY",Delta); // Tell Pos not working on Axis2 => use PR
	else
		if(Axis==AXIS1) sprintf(comstring,"01PA%d",Goal);
		else sprintf(comstring,"02PR%d",Delta);
	if(Wait)
		switch (Speed) {
			case FAST:
			case SLOW:
				GpibWrite(GPIBNEWP,comstring);
				GpibRead(GPIBNEWP,answer,3);
				if(Axis==AXIS1){
					TellPos(Step,&pa);
					P.Step[Step].Actual=pa;
					}
				else
					P.Step[Step].Actual=Goal;
				break;
			case EXACT:
				do {
					GpibWrite(GPIBNEWP,comstring);
					GpibRead(GPIBNEWP,answer,3);
					TellPos(Step,&pa);
					}
				while((pa!=Goal)&&(++iter<MAXITERNEWP));
				P.Step[Step].Actual=pa;
				break;
			}
	else
		GpibWrite(GPIBNEWP,comstring);
}


/* TELL POSITION */
void TellPosNewp(char Step,long *Position){
	char answer[STRLEN];
	char command[STRLEN];
	long pa=0;
	if(P.Step[Step].Axis!=AXIS1) return;
	sprintf(command,"01TP");
	GpibWrite(GPIBNEWP,command);
	GpibRead(GPIBNEWP,answer,16);
	pa=atoi(answer+4);
	*Position=pa;
	}


// #### 4005 NEWPORT STEPPER

/* INITIALIZE MM4005 */ 
void InitNewp4005(double speed, char Axis, char Step){
   // Initialize Gpib Communication with Newport
	NI_PortOpen (2,2,0);
	NI_SetTimeOut(0.1);
	NI_SendCommand ("2SC1,1SC1");
	NI_SendCommand ("MO");
	Delay(2);
    SetVelNewp4005(Step,P.Step[Step].Freq);
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "PASSED\n");
	}


/* SET VEL */
void SetVelNewp4005(char Step,double Freq){
	char command[STRLEN];
	char saxis[3];
    if(P.Step[Step].Axis==AXIS1) strcpy(saxis,"01");
    if(P.Step[Step].Axis==AXIS2) strcpy(saxis,"02");
    if(0.001*Freq*P.Step[Step].Factor>20.0)
    	sprintf(command,"%sVA20,2AC50,1AC50",saxis);
    else sprintf(command,"%sVA%f,2AC50,1AC50",saxis,Freq*P.Step[Step].Factor*0.001);
    NI_SendCommand (command);   
   	Delay (0.1);
    }


/* DEFINE HOME */
void DefineHomeNewp4005(char Step){
	char saxis[STRLEN];
	char command[STRLEN];
	if(P.Step[Step].Axis==AXIS2) strcpy(saxis,"02");
    if(P.Step[Step].Axis==AXIS1) strcpy(saxis,"01");
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "Initializing Newport Home ...");
	sprintf(command, "%sDH",saxis);
    NI_SendCommand (command);   
    Delay(1);
	TellPosNewp4005(Step,&P.Step[Step].Actual);
    Passed();
    }


/* MOVE NEWPORT */
void MoveNewp4005(char Step, long Goal, long Delta, char Axis, char Speed, char Wait){
	char r[128]; 
	char comstring[STRLEN];
	char saxis[3];
	int  err,a;
	
	saxis[0]='0';
	if(Axis==AXIS1) saxis[1]='1'; 
	if(Axis==AXIS2) saxis[1]='2';
	saxis[2]='\0';
	if(Wait) sprintf(comstring,"%sPA%f,WS,RQ00",saxis,Goal/P.Step[Step].Factor); 
	else sprintf(comstring,"%sPA%f",saxis,Goal/P.Step[Step].Factor);
	if(Wait) {
		NI_SendCommand (comstring);
		do err = NI_SendAndWaitResponse ("TS", r, &a);
		while ((r[2]&0xFF) != 0xC0);
		TellPosNewp4005(Step,&P.Step[Step].Actual);
		}
	else
		NI_SendCommand (comstring);
	}


/* TELL POSITION */
void TellPosNewp4005(char Step,long *Position){
	char answer[STRLEN],saxis[3];
	char command[STRLEN];
	long pa=0;
	int a;
	saxis[0]='0';
	if(P.Step[Step].Axis!=AXIS1) saxis[1]='1';
	if(P.Step[Step].Axis!=AXIS2) saxis[1]='2';
	saxis[2]='\0';
	sprintf(command,"%sTP",saxis);
	NI_SendAndWaitResponse (command, answer, &a);
	pa=atof(answer+4);
	*Position=pa;
	}


// #### NATIONAL INSTRUMENTS MIO DAQ ####

/* INITIALIZE MIO */
void InitMio(char Axis, char Step){
	double goal=(double)(1.0*P.Step[Step].Home/STEP_MIO_MV_V);
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "Initializing MIO Board");
	is_auto_on=1;
	P.Step[Step].Mio.Board = STEP_MIO_BOARD1; //MIO's device number
	sprintf (P.Step[Step].Mio.sChann,"%d", Axis); //MIO's channel
	AOUpdateChannel (P.Step[Step].Mio.Board,P.Step[Step].Mio.sChann, goal);
	P.Step[Step].Actual=P.Step[Step].Home;
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE," PASSED\n");
	}

/*MOVE MIO*/
void MoveMio(char Step,long Goal){
	double goal=(double)(1.0*Goal/STEP_MIO_MV_V);
	AOUpdateChannel (P.Step[Step].Mio.Board,P.Step[Step].Mio.sChann, goal);
	P.Step[Step].Actual=Goal;
	}
/*CLOSE MIO*/
void CloseMio(void) {
	int response;
	response=ConfirmPopup("CloseMio", "Do you want to close the MIO board?");
	if (response==1) AOUpdateChannel(STEP_MIO_BOARD1,"0",0);
	}

// #### NATIONAL INSTRUMENTS TIO10 STEPPER ####
	
/* INITIALIZE PC-TIO*/
void InitTio(char Axis, char Step){
	short ret;
	double delay,width;
    double Dactual1, Wactual1,Dutyactual2,Factual2,
    		DutyCycle2,PulseDelay2, PulseDelay1;
    char effAxis = (Axis<=AXIS3?Axis:Axis-3);
    		
	/*variable initialization*/
	P.Step[Step].Tio.Board = (Axis<=AXIS3?STEP_TIO_BOARD1:STEP_TIO_BOARD2);
	strcpy(P.Step[Step].Tio.sPort,STEP_TIO_PORT0);
    P.Step[Step].Tio.lDir = STEP_TIO_LINE_DIR+STEP_TIO_NUM_LINE*effAxis;
	P.Step[Step].Tio.lEnable = STEP_TIO_LINE_ENABLE+STEP_TIO_NUM_LINE*effAxis;
//**P.Step[Step].Tio.lHalf = STEP_TIO_LINE_HALF+STEP_TIO_NUM_LINE*effAxis;
	sprintf (P.Step[Step].Tio.sGate,"%d", (STEP_TIO_COUNT_GATE+STEP_TIO_NUM_COUNT*effAxis));
	sprintf (P.Step[Step].Tio.sClock,"%d",(STEP_TIO_COUNT_CLOCK+STEP_TIO_NUM_COUNT*effAxis));
	sprintf (P.Step[Step].Tio.sCount,"%d",(STEP_TIO_COUNT_COUNT+STEP_TIO_NUM_COUNT*effAxis));
	/**/if(Axis==AXIS1) sprintf(P.Step[Step].Tio.sClock,"%d",10);

    Dactual1=0; 
    Wactual1=0;
    PulseDelay1=0;
    Factual2=0;
    Dutyactual2=0;
    DutyCycle2=0.5;
    PulseDelay2=0.0;

    SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "Initializing PC-TIO Board");
    
	// Init Lines
	
	ret=WriteToDigitalLine (P.Step[Step].Tio.Board, P.Step[Step].Tio.sPort, P.Step[Step].Tio.lDir, 8, 0, LOW_LEVEL);
	ret=WriteToDigitalLine (P.Step[Step].Tio.Board, P.Step[Step].Tio.sPort, P.Step[Step].Tio.lEnable, 8, 0, LOW_LEVEL);
	//**  WriteToDigitalLine (P.Step[Step].Tio.Board, P.Step[Step].Tio.sPort,P.Step[Step].Tio.lHalf, 8, 0, LOW_LEVEL);
	/**/ret=WriteToDigitalLine (P.Step[Step].Tio.Board, P.Step[Step].Tio.sPort, P.Step[Step].Tio.lEnable, 8, 0, HIGH_LEVEL);
		
	// Init Counters
	ret=DelayedPulseGenConfig (P.Step[Step].Tio.Board, P.Step[Step].Tio.sGate, 0.0, 1.0, USE_INTERNAL_TIMEBASE,
						   UNGATED_SOFTWARE_START, POSITIVE_POLARITY,
						   &delay, &width, &P.Step[Step].Tio.tGate);
	ret=CounterEventOrTimeConfig (P.Step[Step].Tio.Board, P.Step[Step].Tio.sCount, ONE_COUNTER,
							  USE_COUNTER_SOURCE, COUNT_CONTINUOUSLY,
							  COUNT_ON_RISING_EDGE,
							  UNGATED_SOFTWARE_START, &P.Step[Step].Tio.tCount);
    
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE," PASSED\n");
	}


/* CLOSE PC-TIO*/
void CloseTio(char Axis, char Step){
	short ret;
	ret=WriteToDigitalLine (P.Step[Step].Tio.Board, P.Step[Step].Tio.sPort, P.Step[Step].Tio.lEnable, 8, 0, LOW_LEVEL);
	}


/* SET FREQUENCY TIO */	
void SetVelTio(char Step, double Freq){
	short ret;
    double Factual=0;
    double Dutyactual=0;
	ret=ContinuousPulseGenConfig (P.Step[Step].Tio.Board, P.Step[Step].Tio.sClock, Freq, 0.5,
							  COUNT_WHILE_GATE_HIGH, POSITIVE_POLARITY,
							  &Factual, &Dutyactual, &P.Step[Step].Tio.tClock);
	}


/*MOVE TIO*/
void MoveTio(char Step,long Delta, char Dir, char Wait){
	short ret;
	double gate,delay,width;
	char dirlevel;
	short board = P.Step[Step].Tio.Board;
	char *sPort = P.Step[Step].Tio.sPort;
	
	if(P.Step[Step].Sign==STEP_SIGN_POS)
		dirlevel=((Dir==1)?HIGH_LEVEL:LOW_LEVEL);
	else
		dirlevel=((Dir==1)?LOW_LEVEL:HIGH_LEVEL);

	//if (Delta==0) // removed by MAMM, test for SPECTR when delta=0
	if(Delta==0){
		if(!Wait) CounterStart(P.Step[Step].Tio.tCount);
		return;
		}	// modified by MAMM, test for SPECTR when delta=0

	// Config Gate
	gate=Delta/P.Step[Step].FreqActual;
	ret=DelayedPulseGenConfig (board, P.Step[Step].Tio.sGate, 0.0, gate, USE_INTERNAL_TIMEBASE,
						   UNGATED_SOFTWARE_START, POSITIVE_POLARITY,
						   &delay, &width, &P.Step[Step].Tio.tGate);

	ret=WriteToDigitalLine (board,sPort,P.Step[Step].Tio.lDir,8,0,dirlevel);
	//**WriteToDigitalLine (board,sPort,P.Step[Step].Tio.lEnable,8,0,HIGH_LEVEL);
//	WriteToDigitalLine (board,sPort,P.Step[Step].Tio.lHalf,8,0,HIGH_LEVEL);
	ret=CounterStart(P.Step[Step].Tio.tCount);
	ret=CounterStart(P.Step[Step].Tio.tClock);
	ret=CounterStart(P.Step[Step].Tio.tGate);
	if(Wait) WaitTio(Step,Delta,Dir);
}

/* WAIT END OF TIO MOVEMENT */
void WaitTio(char Step,long Delta,char Dir){
	short ret;
	short overflow;
	long count;
	if(Delta==0) return;
	do ret=CounterRead(P.Step[Step].Tio.tCount, &count, &overflow); while(count<Delta);
	ret=CounterStop(P.Step[Step].Tio.tClock);
	ret=CounterStop(P.Step[Step].Tio.tGate);
	ret=CounterRead(P.Step[Step].Tio.tCount, &count, &overflow);
	ret=CounterStop(P.Step[Step].Tio.tCount);
	P.Step[Step].Actual+=Dir*count;
	//**WriteToDigitalLine (P.Step[Step].Tio.Board,P.Step[Step].Tio.sPort,P.Step[Step].Tio.lEnable,8,0,LOW_LEVEL);
}

/* TELL POSITION TIO */
void TellPosTio(char Step,long *Position){
	short ret;
	short overflow;
	long count;
	ret=CounterRead(P.Step[Step].Tio.tCount,&count,&overflow);
	*Position=P.Step[Step].Actual+count*P.Step[Step].Dir;
	}


/* STOP TIO */
void StopTio(char Step){
	short ret;
	ret=CounterStop(P.Step[Step].Tio.tGate);
	ret=CounterStop(P.Step[Step].Tio.tClock);
	TellPos(Step,&P.Step[Step].Actual);
	ret=CounterStop(P.Step[Step].Tio.tCount);
	}


// #### MICROCHIP STEPPER ####
	
/* INITIALIZE MICRO */
void InitMicro(char Step){
	int ret,open;
	char message[STRLEN];
	int com=P.Step[Step].Axis+1;
	sprintf(message,"Initializing MICRO Stepper #%d on COM%d",Step+1,com);
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE,message);
	open=OpenComConfig(com,NULL,MICRO_BAUDRATE,MICRO_PARITY,MICRO_DATABITS,MICRO_STOPBITS,0,-1);
	FlushInQ (com);
	FlushOutQ (com);
    
    TalkMicro(com,MICRO_LCD,P.Step[Step].Lcd,&ret);
    TalkMicro(com,MICRO_HOLD,P.Step[Step].Hold,&ret);
    TalkMicro(com,MICRO_FMIN,P.Step[Step].FreqMin,&ret);
	TalkMicro(com,MICRO_VEL,(int) P.Step[Step].Freq,&ret);
	TalkMicro(com,MICRO_FDELTA,P.Step[Step].FreqDelta,&ret);
//**    TalkMicro(com,MICRO_HOME,P.Step[Step].Home,&ret);
    
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE," PASSED\n");
	}


/* CLOSE MICRO */
void CloseMicro(char Step){
	int ret;
	int com=P.Step[Step].Axis+1;
    TalkMicro(com,MICRO_END,0,&ret);
	FlushInQ (com);
	FlushOutQ (com);
	CloseCom (com);
	}


/* SET FREQUENCY MICRO */	
void SetVelMicro(char Step, double Freq){
	int ret;
	int com=P.Step[Step].Axis+1;
    TalkMicro(com,MICRO_VEL,(int) Freq,&ret);
	}


/* MOVE MICRO */
void MoveMicro(char Step,long Goal,char Wait){
	int ret;
	int com=P.Step[Step].Axis+1;
	if(Goal==P.Step[Step].Actual) return;
    TalkMicro(com,MICRO_GOTO,Goal,&ret);
	if(Wait) WaitMicro(Step,Goal);
	}

/* WAIT END OF MICRO MOVEMENT */
/*void WaitMicro(char Step,long Goal){
	long actual;
	do{
		TellPosMicro(Step,&actual);
		Delay(0.1);
		}
	while(actual!=Goal);
	P.Step[Step].Actual=actual;
	} */

/* WAIT END OF MICRO MOVEMENT */
void WaitMicro(char Step,long Goal){
	long actual;
	int com=P.Step[Step].Axis+1;
	if(Goal==P.Step[Step].Actual) return;
	GetMicro(com,&actual);
	P.Step[Step].Actual=actual;
	}


/* TELL POSITION MICRO */
void TellPosMicro(char Step,long *Actual){
	int com=P.Step[Step].Axis+1;
    TalkMicro(com,MICRO_TELL,0,Actual);
	}


/* STOP MICRO */
void StopMicro(char Step){
	int com=P.Step[Step].Axis+1;
    TalkMicro(com,MICRO_STOP,0,&P.Step[Step].Actual);
	}


/* DEFINE HOME MICRO */
void DefineHomeMicro(char Step){
//**	int com=P.Step[Step].Axis+1;
//**    TalkMicro(com,MICRO_HOME,P.Step[Step].Home,&ret);
    }


/* SEND COMMAND TO MICRO AND GET ANSWER */
void TalkMicro(int Com, char Command, long Value, long *Answer){
	char *pChar;
	pChar = (char*) &Value;
	pChar[3] = (char) Command;
	ComWrt(Com,pChar,4);
	GetMicro(Com,Answer);
	}

/* GET ANSWER FROM MICRO */
void GetMicro(int Com,long *Answer){
	char *pChar;
	pChar = (char*) Answer;
	while(ComRd (Com,pChar,4)<4);
	}



// #### PI STEPPER ####
	
/* INITIALIZE PI */
void InitPi(char Step){
	int open,nErr;
	char message[STRLEN];
	int com=P.Step[Step].Axis+1;
	sprintf(message,"Initializing PI Driver #%d on COM%d",Step+1,com);
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE,message);
	//FlushInQ (com);
	//FlushOutQ (com);
	//CloseCom (com);
	MCRS_clear_input();
	//ClosePi();
	open=MCRS_open(com,PI_BAUDRATE);
	nErr = MCRS_set_device(PI_DEVICE);
	if ((open+nErr)!=0){
	    SetCtrlVal (hDisplay, DISPLAY_MESSAGE," PI: INIT COM ERROR\n");
	    return;
	}
	if (MCRS_getPos()>2147483643){
		SetCtrlVal (hDisplay, DISPLAY_MESSAGE," PI: DEVICE NOT CONNECTED\n");
		return;
	}
	
	/*if (MCRS_sendString("SM40")!=0) 
    	SetCtrlVal (hDisplay, DISPLAY_MESSAGE," PI: SET FOLLOWING ERROR FAULT\n");
    if (MCRS_sendString("MN")!=0) 
    	SetCtrlVal (hDisplay, DISPLAY_MESSAGE," PI: SERVO ON ERROR FAULT\n");
	/*if (MCRS_sendString("SA10000")!=0) 
    	SetCtrlVal (hDisplay, DISPLAY_MESSAGE," PI: SERVO ON ERROR FAULT\n"); */
	SetVelPi(P.Step[Step].Freq);
	
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE," PASSED\n");
	}


/* CLOSE PI */
void ClosePi(){
	
	if (MCRS_close()!=0)
		SetCtrlVal (hDisplay, DISPLAY_MESSAGE," PI: CLOSE DEVICE ERROR\n");	   //Chiude la COM aperta prima. Potrebbe creare conflitti se ci fossero più
					 //driver PI su COM differenti. In tal caso conviene sfruttare la possibilità
					 //di collegare i dispositivi in cascata e comandarli da un'unica COM.
	}


/* SET FREQUENCY PI */	
void SetVelPi(double Freq){
    char buffer[STRLEN];
    sprintf(buffer,"%s%d",PI_VEL,(int) Freq);
    
    if (MCRS_sendString(buffer)!=0) 
    	SetCtrlVal (hDisplay, DISPLAY_MESSAGE," PI: SET VELOCITY ERROR\n");
    
}


/* MOVE PI */
void MovePi(char Step,long Goal,char Wait){
	
	if(Goal==P.Step[Step].Actual) return;
    if(MCRS_moveA(PI_DEVICE,(int) Goal)!=0)
       SetCtrlVal (hDisplay, DISPLAY_MESSAGE," PI: MOVE ERROR\n");
    
	WaitPi(Step,Goal);
	}

/* WAIT END OF PI MOVEMENT */
void WaitPi(char Step,long Goal){
	long actual;
	if(Goal==P.Step[Step].Actual) return;
	MCRS_waitStop();
	//while (MCRS_getPosErr()!=0);
	TellPosPi(Step,&actual);
	P.Step[Step].Actual=actual;
	}


/* TELL POSITION PI */
void TellPosPi(char Step,long *Actual){
    *Actual=(long)MCRS_getPos();
}


/* STOP PI */
void StopPi(){
	int nErr;
    nErr = MCRS_sendString("AB1");
}


/* DEFINE HOME PI */
void DefineHomePi(char Step){
//**	int com=P.Step[Step].Axis+1;
//**    TalkPi(com,PI_HOME,P.Step[Step].Home,&ret);
    }



// #### NATIONAL INSTRUMENTS USB-6229 ####



void SetFreqNI_USB6229(char Step,long Goal){
	uInt32 value;
	double freq;
	int32 written;
	uInt8 latch,mod;
	TaskHandle	taskfreq=0;
	TaskHandle	tasklatch=0;
	TaskHandle	taskmoden=0;
	
	
	DAQmxCreateTask ("TaskFreq", &taskfreq);
	DAQmxCreateTask ("TaskLatch", &tasklatch); 
	DAQmxCreateTask ("TaskModEn", &taskmoden); 
	
	
	DAQmxCreateDOChan (taskfreq, "Dev1/port0", "FREQ", DAQmx_Val_ChanForAllLines);
	DAQmxCreateDOChan (tasklatch, "Dev1/port1/line0", "LATCH", DAQmx_Val_ChanForAllLines);
	DAQmxCreateDOChan (taskmoden, "Dev1/port1/line1", "MOD_EN", DAQmx_Val_ChanForAllLines);
	
	DAQmxStartTask (taskmoden);
	mod=1;
	DAQmxWriteDigitalLines(taskmoden,1,1,10.0,DAQmx_Val_GroupByChannel,&mod,NULL,NULL);
	
	DAQmxStartTask (tasklatch);
	latch=1;
	DAQmxWriteDigitalLines(tasklatch,1,1,10.0,DAQmx_Val_GroupByChannel,&latch,NULL,NULL);
	
	
	DAQmxStartTask (taskfreq);
	freq=Goal * pow (2, 31)/AOTF_FREQ_FACTOR;
	value=(int)freq;
	
	DAQmxWriteDigitalU32 (taskfreq, 1, 1, 10.0, DAQmx_Val_GroupByChannel, &value, &written, 0);
	//Delay (1);
	latch=0;
	DAQmxWriteDigitalLines(tasklatch,1,1,10.0,DAQmx_Val_GroupByChannel,&latch,NULL,NULL);
	
	DAQmxStopTask (taskmoden);
	DAQmxStopTask (tasklatch);
	DAQmxStopTask (taskfreq);
	
	DAQmxClearTask (taskfreq);
	DAQmxClearTask (tasklatch);  
	DAQmxClearTask (taskmoden);  
}


void SetVoltNI_USB6229(char Step,long Goal){
	TaskHandle	taskmodpower=0;
	float volt;
	
	volt=(float)Goal/AOTF_VOLT_FACTOR;
	DAQmxCreateTask ("TaskModPower", &taskmodpower);
	DAQmxCreateAOVoltageChan (taskmodpower, "Dev1/ao0", "MOD_POWER", 0, 1, DAQmx_Val_Volts, "");
	DAQmxStartTask (taskmodpower);
	DAQmxWriteAnalogScalarF64 (taskmodpower, 1, 10.0, volt, 0);
	DAQmxStopTask (taskmodpower);
	DAQmxClearTask (taskmodpower);
}


// #### NATIONAL INSTRUMENTS USB-6221 #### 

void SetVoltNI_USB6221(char Step,long Goal){
	TaskHandle	taskmodpower=0;
	double volt;
	
	//volt=(float)Goal/AOTF_VOLT_FACTOR;
	DAQmxCreateTask ("TaskModPower", &taskmodpower);
    DAQmxCreateAIVoltageChan (taskmodpower, "Dev2/ai0", " MOD_POWER ", DAQmx_Val_NRSE, -0.5, 0, DAQmx_Val_Volts, "");
	DAQmxStartTask (taskmodpower);
	DAQmxReadAnalogScalarF64 (taskmodpower, 10.0, &volt, 0);	
	DAQmxStopTask (taskmodpower);
	DAQmxClearTask (taskmodpower);
	P.Step[Step].Actual=(long)(volt*ADC_FACTOR);
}





// #### DELAYER STEPPER ####
	
/* INITIALIZE DELAYER */
void InitDelayer(char Step){
	char message[STRLEN];
	char byte1,byte2;
	short status, code;

	sprintf(message,"Initializing Delayer");
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE,message);
	
	//TRADNIDAQ status = Init_DA_Brds (2, &code);
	//TRADNIDAQ status = DIG_Prt_Config (2, 0, 0, 1);
	//TRADNIDAQ status = DIG_Prt_Config (2, 1, 0, 1);
	
	sprintf(message,"Error Initializing the board #%d, error code %d",code,status);
    if(status!=0) Failure(message); else Passed();
	}


/* MOVE PI */
void MoveDelayer(char Step,long Goal){
	char byte1,byte2;
	short status;
	
	byte2=(char) (Goal/256);
	byte1=(char) (Goal-byte2*256);
	//TRADNIDAQ status = DIG_Out_Prt (2, 0, byte1);
	//TRADNIDAQ status = DIG_Out_Prt (2, 1, byte2);
	P.Step[Step].Actual=Goal;
	}


// #### PWM STEPPER ####
 
 /** PWM ALLOWED COMMANDS:
  * 
  *     [A][+ SIGN][4 digit int][;]     -> Absolute shift
  *     [S][+ SIGN][4 digit int][;]     -> Set voltage changing speed (mV/s)
  *     [R][SIGN(+/-)][4 digit int][;]  -> Relative shift from current pos
  *     [G][+][0][0][0][0][;]           -> Ask current position
  *     [H][+][0][0][0][0][;]           -> Interrupts last command
  * 
  ** PWM RESPONSES:
  *
  *     [R][+][0][0][0][0][;]           -> Ready. Last command succesful
  *     [E][+][0][0][0][0][;]           -> Error. Last command failed
  *     [P][+][4 digit int][;]          -> Current position. Response to G command
  */
 
	
/* INITIALIZE PWM */
void InitPwm(char Step)
{
	int open;
 
	char message[PWM_STRLEN];
	int com=P.Step[Step].Axis + 1;
	sprintf(message,"Initializing PWM Stepper #%d on COM%d",Step+1,com);
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE,message);
	open=OpenComConfig(com,NULL,PWM_BAUDRATE,PWM_PARITY,PWM_DATABITS,PWM_STOPBITS,0,-1);
	FlushInQ (com);
	FlushOutQ (com);
    
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE," PASSED\n");
}


/* CLOSE PWM*/
void ClosePwm(char Step)
{
	int ret;
	int com=P.Step[Step].Axis+1;
    TalkPwm(com, PWM_RESET, 0, &ret);
	FlushInQ (com);
	FlushOutQ (com);
	CloseCom (com);
}


/* SET FREQUENCY PWM */	
void SetVelPwm(char Step, double Freq)
{
    int ret, com;
    unsigned int frq;
	double f;
	/*
	 * NOTE: Freq is in mV/s. PWM controller needs s/mv, so the proper 
	 * conversion is needed. 
	 *
	 * PROPER CONVERSION FACTOR is: [ 1 / 115.2 ]
	 * */

	f = Freq*115.2;
    if ((Freq<=PWM_FREQ_MIN) && (Freq>=PWM_FREQ_MAX))
    {
        if (Freq<=PWM_FREQ_MIN)
            frq = PWM_FREQ_MIN;
        else 
            frq = PWM_FREQ_MAX;
    } else
        frq = RoundRealToNearestInteger(Freq);

    com = P.Step[Step].Axis+1;
    TalkPwm(com, PWM_SETSPEED, frq, &ret);
}


/* MOVE PWM */
void MovePwm(char Step,long Goal,char Wait)
{
    int ret;
    int com = P.Step[Step].Axis+1;

    if(Goal == P.Step[Step].Actual) return;

    TalkPwm(com, PWM_ABS_GOTO, Goal, &ret);
    //if(Wait) WaitPwm(Step, Goal);
}

/* WAIT END OF PWM MOVEMENT 
void WaitPwm(char Step,long Goal)
{
	long actual;
	int com=P.Step[Step].Axis+1;
	GetMicro(com,&actual);
	P.Step[Step].Actual=actual;
}
*/

/* TELL POSITION PWM */
void TellPosPwm(char Step,long *Actual)
{
    int com=P.Step[Step].Axis+1;
    TalkMicro(com, PWM_TELL, 0, Actual);
}


/* STOP PWM */
void StopPwm(char Step)
{
    int ret;
    int com=P.Step[Step].Axis+1;

    TalkMicro(com, PWM_STOP, 0, &ret);
	TellPos(Step, &P.Step[Step].Actual);
}


/* DEFINE HOME PWM */
void DefineHomePwm(unsigned int Step)
{
    int ret;
    int com;
    com = P.Step[Step].Axis+1;

    TalkMicro(com, PWM_SETHOME, P.Step[Step].Home, &ret);
}


/* SEND COMMAND TO PWM AND GET ANSWER */
void TalkPwm(int Com, char Command, long Value, long *Answer)
{
    char string[PWM_STRLEN];

    sprintf(string, "%c%+05d;", Command, Value);
    ComWrt(Com, string, PWM_STRLEN);
    GetPwm(Com, Answer);
}

/* GET POSITION FROM PWM */
void GetPwm(int Com, long *Answer)
{
    char string[PWM_STRLEN];

    while( ComRd(Com, string, PWM_STRLEN) < PWM_STRLEN );
    string[PWM_STRLEN] = '\0';
    Scan(string, "%d", Answer);
}

/* WAIT END OF PWM MOVEMENT */
/*void WaitMicro(char Step,long Goal){
	long actual;
	do{
		TellPosMicro(Step,&actual);
		Delay(0.1);
		}
	while(actual!=Goal);
	P.Step[Step].Actual=actual;
	} */


// #### MONOCROMATOR STEPPER (VIA SERIAL PORT) ####                                                                         
	
/* INITIALIZE MONO */
void InitMono(char Step){   
	
	int ret,open;
	char message[STRLEN];
	int com=P.Step[Step].Axis+1;
	
	sprintf(message,"Initializing MONO Stepper #%d on COM%d",Step+1,com);
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE,message);
    
	open=OpenComConfig(com,NULL,MONO_BAUDRATE,MONO_PARITY,MONO_DATABITS,MONO_STOPBITS,0,-1);
	FlushInQ (com);
	FlushOutQ (com);
    
    //TalkMono(com,MONO_LCD,P.Step[Step].Lcd,&ret);
  
	TalkMono(com,MONO_VEL,(int)(P.Step[Step].Freq)* MONO_SEC_TO_MIN,&ret);
	GetMono(com,&ret); 					
	
	TellPosMono(Step,&P.Step[Step].Actual);
	MoveMono(Step,P.Step[Step].Home,1); 
	
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE," PASSED\n");
	}


/* CLOSE MONO */
void CloseMono(char Step){	   
	int com=P.Step[Step].Axis+1;
      
    MoveMono(Step,P.Step[Step].Home,1); // chiedere a Antonio se gli va bene; probabilmente ridondante
    FlushInQ (com);
	FlushOutQ (com);
	CloseCom (com);
	}


/* SET FREQUENCY MONO */	
void SetVelMono(char Step, double Freq){
	int ret;
	int com=P.Step[Step].Axis+1;
    TalkMono(com,MONO_VEL,(int) (Freq) * MONO_SEC_TO_MIN,&ret);
    GetMono(com,&ret);
	}


/* MOVE MONO */
void MoveMono(char Step,long Goal,char Wait){
	int ret;
	int com=P.Step[Step].Axis+1;
	if(Goal==P.Step[Step].Actual) return;
    TalkMono(com,MONO_GOTO,Goal * MONO_NM_TO_AMG,&ret);
	if(Wait) WaitMono(Step,Goal);
	}



/* WAIT END OF MONO MOVEMENT */
void WaitMono(char Step,long Goal){

    double timeout;
    int ret; 
	int com=P.Step[Step].Axis+1;
	
	timeout=((abs(Goal-P.Step[Step].Actual))/P.Step[Step].Freq)+MONO_TIMEOUT_OFFSET;
	SetComTime(com,timeout);
	GetMono(com,&ret);  
	SetComTime(com,MONO_TIMEOUT);
	TellPosMono (Step,&P.Step[Step].Actual);		 /* chiedere Antonio*/
	}


/* TELL POSITION MONO */
void TellPosMono(char Step,long *Actual){
	int com=P.Step[Step].Axis+1;
	
	int 	bufferOut, 
			bufferWH,
			bufferWL,
			WHint,
			WLint,
			WH,
			WL;
	
	//lettura valore lunghezza d'onda   
	ComWrtByte(com,MONO_READPOS);		 
	bufferOut=ComRdByte(com); 	 
	bufferWH=ComRdByte(com);
	bufferWL=ComRdByte(com);	
	WH = bufferWH << 8; 	 
	WHint = MONO_MASKH & WH;  
	WL = MONO_MASKL & bufferWL;
	WLint = WL;	   
	*Actual = (WHint + WLint)/10;
	bufferOut=ComRdByte(com);    
	}   


/* DEFINE HOME MONO */
void DefineHomeMono(char Step){
	MoveMono(Step,P.Step[Step].Home,1); 
    }


/* SEND COMMAND TO MONO AND GET ECHO   (invio anche i valori)*/
void TalkMono(int Com, int Command, long Value, long *Answer){
	int buffer,
		LowByte,
		HiByte;
	unsigned char ByteLowChar,
				  ByteHiChar; 
	char string;
	
	string=(char)Command;
	ComWrtByte (Com,string); 
	buffer =ComRdByte(Com);
	LowByte =MONO_MASKL & Value;
	HiByte = MONO_MASKH & Value;
	ByteLowChar = (unsigned char)LowByte;
	ByteHiChar = HiByte >> 8; 
	ComWrtByte(Com,ByteHiChar);
	ComWrtByte(Com,ByteLowChar); 
	buffer = ComRdByte(Com); 
	}

/* READ FROM MONO */   
void GetMono(int Com,long *Answer){   
	char string;	 
	string=ComRdByte(Com);
	*Answer=(long)string;   
	}
	

// #### MONOCROMATOR STEPPER (VIA TCPIP PORT) ####                                                                         
	
/* INITIALIZE MONO */
void InitMonoTcp(char Step){   
	
	//int ret,open;
	char message[STRLEN];
	char command[STRLEN];   
	int com=P.Step[Step].Axis+1; 
    FILE	*fid; 
    
	sprintf(message,"Initializing MONO Stepper #%d on COM%d",Step+1,com);
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE,message);
    
    if ((fid=fopen(MONO_IP_ADDRESS_FILE,"r"))==NULL){
		Failure("IP Address File error.");
		return;
		}
	fscanf(fid,"%s",MonoTcp.IpAddress);
	fclose(fid);
	if (ConnectToTCPServer (&MonoTcp.Handle, MONO_TCP_PORT, MonoTcp.IpAddress, Client_MonoTCPCB,NULL, MONO_TCP_WAIT_TIME) < 0){
        Failure("Connection to server failed!");
        return;
        }  			  
    MonoTcp.ServerReady=0;
	sprintf(command,"%c %f %f %f",MONO_TCP_INIT_COMMAND,(float)(P.Step[Step].Home),(float)(P.Step[Step].Freq),(0.0));
	TalkMonoTcp(command);

	while (MonoTcp.ServerReady==0)
		ProcessSystemEvents();
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE," PASSED\n");
    
	}


/* CLOSE MONO */
void CloseMonoTcp(char Step){	   
	 char command[STRLEN];		
	 
	 MonoTcp.ServerReady=0; 
     sprintf(command,"%c %f %f %f", MONO_TCP_CLOSE_COMMAND,(0.0),(0.0),(0.0));
     TalkMonoTcp(command);						  
     
     while (MonoTcp.ServerReady==0)
		ProcessSystemEvents();
     DisconnectFromTCPServer(MonoTcp.Handle);
     
	}


/* SET FREQUENCY MONO */	
void SetVelMonoTcp(char Step, double Freq){
	char command[STRLEN];
	
	MonoTcp.ServerReady=0;    
	sprintf(command,"%c %f %f %f", MONO_TCP_VEL_COMMAND,Freq,(0.0),(0.0));
	TalkMonoTcp(command); 

	while (MonoTcp.ServerReady==0)
		ProcessSystemEvents();
	}


/* MOVE MONO */
void MoveMonoTcp(char Step,long Goal,char Wait){
	char command[STRLEN];
	
	MonoTcp.ServerReady=0;
	sprintf(command,"%c %f %f %f", MONO_TCP_MOVE_COMMAND,(float)(Goal),(0.0),(0.0));
	TalkMonoTcp(command); 
	
	while (MonoTcp.ServerReady==0)
		ProcessSystemEvents();
	}



/* WAIT END OF MONO MOVEMENT */
void WaitMonoTcp(char Step,long Goal){
	char command[STRLEN];	 
	
	sprintf(command,"%c %f %f %f", MONO_TCP_WAIT_COMMAND,(float)Goal,(0.0),(0.0));
	TalkMonoTcp(command);  
	}


/* TELL POSITION MONO */
void TellPosMonoTcp(char Step,long *Actual){
	 char command[STRLEN];
	 
	 sprintf(command,"%c %f %f %f", MONO_TCP_TELL_COMMAND,(0.0),(0.0),(0.0));
     TalkMonoTcp(command);
     ClientTCPRead(MonoTcp.Handle,command,STRLEN,MONO_TCP_WAIT_TIME);
     sscanf(command,"%f",Actual);
	 
	}   


/* DEFINE HOME MONO */
void DefineHomeMonoTcp(char Step){
	char command[STRLEN];
	
	MonoTcp.ServerReady=0;       
	sprintf(command,"%c %f %f %f", MONO_TCP_HOME_COMMAND,(float)(P.Step[Step].Home),(0.0),(0.0));
	TalkMonoTcp(command); 	  
	
	while (MonoTcp.ServerReady==0)
		ProcessSystemEvents();	   
	}


/* SEND COMMAND TO MONO AND GET ECHO   (invio anche i valori)*/
void TalkMonoTcp(char *Command){  
	ClientTCPWrite(MonoTcp.Handle,Command,STRLEN,MONO_TCP_WAIT_TIME); 
	} 	 

	
/*---------------------------------------------------------------------------*/
/* This is the TCP client's TCP callback.  This function will receive event  */
/* notification, similar to a UI callback, whenever a TCP event occurs.      */
/* We'll respond to the DATAREADY event and read in the avaiable data from   */
/* the server and display it.  We'll also respond to DISCONNECT events, and  */
/* tell the user when the server disconnects us.                             */
/*---------------------------------------------------------------------------*/
int CVICALLBACK Client_MonoTCPCB (unsigned handle, int event, int error,
                             void *callbackData)
{
    int  dataSize;
    char receiveBuf[STRLEN] = {0};
    float serverMessage;
    
    
    switch (event)
        {
        case TCP_DATAREADY: 
        	if ((dataSize = ClientTCPRead (handle, receiveBuf,STRLEN, MONO_TCP_WAIT_TIME))< 0)
                Failure ("Receive Error\n");
            else{    
            	sscanf(receiveBuf,"%f", &serverMessage);
            	if (serverMessage==0)
            		MonoTcp.ServerReady=1;
            	else
            		MonoTcp.ServerValue=serverMessage;
            	}
            break;
            
        case TCP_DISCONNECT:
            Failure ("Server has closed connection!");
            break;
    }
    return 0;
}   

/****************************************/
/*										*/
/*	Fiber power monitor procedures		*/
/*										*/
/****************************************/

/* INITIALIZE FPM */
void InitFpm(char Step){
	int open;
	char message[STRLEN];
	int com=P.Step[Step].Axis + 1;
	
	sprintf(message,"Initializing Fiber Power Monitor #%d on COM%d...",Step+1,com);
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE,message);
	open=OpenComConfig(com,NULL,FPM_BAUDRATE,FPM_PARITY,FPM_DATABITS,FPM_STOPBITS,0,-1);
	FlushInQ (com);
	FlushOutQ (com);
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE," PASSED!\n");
	}


/* CLOSE FPM*/
void CloseFpm(char Step){
	long ret;
	int com=P.Step[Step].Axis+1;
    TalkFpm(com, FPM_STOPMEAS, 0, &ret);
	FlushInQ (com);
	FlushOutQ (com);
	CloseCom (com);
	}


/* Tell FPM to stop sending data */
void StopFpm(char Step){
	long answer;
    int com=P.Step[Step].Axis+1;
    TalkFpm(com, FPM_STOPMEAS, 0, &answer);
	
	}


/* ASK FPM FOR LASER INTENSITY */
void MoveFpm(char Step,long Goal){
    int com=P.Step[Step].Axis+1;
    TalkFpm(com, FPM_GETSINGLE, 0, &P.Step[Step].Actual);
	}

/* ASK FPM FOR LASER INTENSITY */
/*void TellPosFpm(char Step,long *Actual){
    int com=P.Step[Step].Axis+1;
    TalkFpm(com, FPM_GETSINGLE, 0, Actual);
	} */


/* SEND COMMAND TO FPM AND GET ANSWER */
void TalkFpm(int Com, char *Command, long Value, long *Answer){
    char stringa[FPM_STRLEN] = "        ";
	//FILE *xf1;

	if (strncmp(Command, FPM_SETSAMPFREQ, 2)==0)
	{
	    sprintf(stringa, "%2s%04d\n", Command, Value);
		stringa[7] = 0;
	}
	else
	{
		sprintf(stringa, "%3s\n\0", Command);
		//stringa[3] = 0;
	}
	
	/* Next 2 lines for debugging porpouses... 
    xf1 = fopen("c:\\tmp\\debug.txt","a");
	fprintf(xf1, "%s", stringa);
	fclose(xf1);*/
	ComWrt(Com, stringa, strlen(stringa));
    GetFpm(Com, Answer);
}


/* GET ANSWERS FROM FPM */
void GetFpm(int Com, long *Answer)
{
    char stringa[FPM_STRLEN] = "        ";
	int _count = 0;
	//FILE *xf1; 

	do 
	{
    	stringa[_count] = ComRdByte(Com);
		_count ++;
	} while ((stringa[_count-1] != '\n') && (_count < FPM_STRLEN));
	stringa[_count] = 0;
    _count = Scan(stringa, "%d", Answer);
	if (_count <= 0) *Answer = 0;
	/* Next 2 lines for debugging porpouses... 
    xf1 = fopen("c:\\tmp\\debug.txt","a");
	fprintf(xf1, "%s", stringa);
	fclose(xf1);*/
}

// #### NATIONAL INSTRUMENTS ADC ####

/* INITIALIZE ADC */
/*void InitAdc(char Axis,char Step){
	double voltage;
	int status;
	char message[STRLEN];
	sprintf(message,"Initializing ADC Board %d on channel %d",STEP_ADC_BOARD,Axis+1);
	P.Step[Step].Adc.Board = STEP_ADC_BOARD; //ADC device number
	sprintf (P.Step[Step].Adc.sChann,"%d", Axis); //ADC channel
	status=AISampleChannel (P.Step[Step].Adc.Board,P.Step[Step].Adc.sChann,10.0,-10.0,&voltage);
	//sprintf(message,"Error initializing ADC board, error code = %d",status);
    if(status<0) Failure(GetDAQErrorString(status)); else Passed();
	}*/

/*MOVE ADC*/
/*void MoveAdc(char Step){
	double voltage;
	int status; 
	status=AISampleChannel (P.Step[Step].Adc.Board,P.Step[Step].Adc.sChann,10.0,-10.0,&voltage);
	P.Step[Step].Actual=(long) (voltage*ADC_FACTOR);
	}*/
	
/* INITIALIZE ADC */
void InitAdc(void){
	//short status;
	//double actualClockRate;
	char message[STRLEN];
	//double actualScanRate;
	sprintf(message,"Initializing ADC Board %d on channel %d",POWER_ADC_BOARD,1);
	//status = AIStartAcquisition (POWER_ADC_BOARD,"1",10*1000,1000.0,10.0,-10.0,&actualScanRate,&P.Power.Adc.Task);
    //if(status!=0) Failure(GetDAQErrorString(status));
	//P.Power.Adc.Board = POWER_ADC_BOARD; //ADC device number
	//EIstatus = nidaqAICreateTask ("daq::4!(1)", kNidaqWaveformCapture, &numChann, &P.Power.Adc.Task);
	
	/*AIAcquireTriggeredWaveforms (POWER_ADC_BOARD,"1",1000,1000.0,10.0,-10.0,actualClockRate,SW_ANALOG_TRIGGER,
                  0,0,"",0,1.0, short fillMode, double EZ_FAR waveform[]);*/
    //if(status!=0) Failure(GetDAQErrorString(status));
	//status = nidaqAIConfigScanClockRate (P.Power.Adc.Task, 1000, &actualClockRate);
    //if(status!=0) Failure(GetDAQErrorString(status));
	//status = nidaqAIConfigBuffer (P.Power.Adc.Task, 10*1000, kNidaqContinuous);
    //if(status!=0) Failure(GetDAQErrorString(status)); else Passed();
    P.Step[P.Power.Step].Actual=0;
	}


/* START ADC ACQUISITION */
void StartAdc(void){
	short status;
	//TaskHandle	taskmodpower=0; 
		
	DAQmxCreateTask ("TaskModPower", &taskmodpower);
    DAQmxCreateAIVoltageChan (taskmodpower, "Dev2/ai0", " MOD_POWER ", DAQmx_Val_NRSE, -0.5, 0, DAQmx_Val_Volts, "");
    //DAQmxCfgSampClkTiming (taskmodpower, "OnboardClock", 1000, DAQmx_Val_Rising, DAQmx_Val_ContSamps, 1000);
    DAQmxStartTask (taskmodpower);
	DAQmxCfgSampClkTiming (taskmodpower, "OnboardClock", 1000, DAQmx_Val_Rising, DAQmx_Val_ContSamps, 1000);
    status = DAQmxReadAnalogF64 (taskmodpower, 1000, 10.0, DAQmx_Val_GroupByScanNumber, P.Power.Adc.Data, 1000, &num_read, 0);
    if(status!=0) Failure(GetDAQErrorString(status));
	//status = AIClearAcquisition (P.Power.Adc.Task);
    //if(status!=0) Failure(GetDAQErrorString(status));
    }
    
    
/* STOP ADC ACQUISITION */
void StopAdc(void){
	short status;
	double stdev,value;
	/**/char message[STRLEN];
	
	//status=nidaqAIStop (P.Power.Adc.Task);
    //if(status!=0) Failure(GetDAQErrorString(status));
	//status = nidaqAIRead (P.Power.Adc.Task, "", 1000, -1.0, P.Power.Adc.Data);
    //if(status!=0) Failure(GetDAQErrorString(status));
	//status = StdDev (P.Power.Adc.Data, 1000, &value, &stdev);
    //if(status!=0) Failure(GetDAQErrorString(status));
    //P.Step[P.Power.Step].Actual=(long)(value*ADC_FACTOR);
    
    status = DAQmxStopTask (taskmodpower);
    if(status!=0) Failure(GetDAQErrorString(status));
	//**sprintf(message,"AICheckAcquisition = %d\n",scanBacklog);
    //**SetCtrlVal (hDisplay, DISPLAY_MESSAGE,message);
    StdDev (P.Power.Adc.Data, num_read, &value, &stdev);
    //P.Step[P.Power.Step].Actual=(long)(value*ADC_FACTOR);
    P.Step[P.Power.Step].Actual=(long)(value*ADC_FACTOR);
	//**sprintf(message,"Status = %d, Data0=%lf, value=%lf\n",status,P.Power.Adc.Data[0],value);
    //**SetCtrlVal (hDisplay, DISPLAY_MESSAGE,message);
    status = DAQmxClearTask (taskmodpower);
    if(status!=0) Failure(GetDAQErrorString(status));
    }


/* STOP ADC ACQUISITION */
/*void CloseAdc(void){
	//long status;
	//status=nidaqAIDestroyTask (P.Power.Adc.Task);
    //if(status!=0) Failure(GetDAQErrorString(status));
	}*/
		
		
/* ########################   SAVE PROCEDURES   ########################### */

/* CLOSE FILE */
void CloseDataFile(void) {
	fclose(P.File.File);
	return;
	}

/* INITIALIZE FILE */
void InitDataFile(void){
    long size;
	
	SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "Initializing File ");
	SetCtrlVal (hDisplay, DISPLAY_MESSAGE, P.File.Path);
	SetCtrlVal (hDisplay, DISPLAY_MESSAGE, " ...");
	if(GetFileInfo (P.File.Path, &size))  EnterName();
	P.File.File = fopen(P.File.Path,"wb");
	if(P.File.File == NULL) Failure("Error Creating File Data"); else Passed();
	CompileHeader();
	while(fwrite(&D.Head,sizeof(D.Head),1,P.File.File)<1);
	fflush(P.File.File);
//	fclose(P.File.File);
	}


/* ENTER FILE NAME */
void EnterName(void){
    int button;
    char message[STRLEN];
    sprintf(message,"ATTENTION! The file %s already exists. Enter new file name without extension",P.File.Name);    
	button = GenericMessagePopup ("Message", message, "OK", "EXIT", 0,P.File.Name ,
								  strlen(P.File.Name), 0, VAL_GENERIC_POPUP_BTN1,
								  VAL_GENERIC_POPUP_BTN1,
								  VAL_GENERIC_POPUP_BTN2);
    if(button==VAL_GENERIC_POPUP_BTN1) sprintf(P.File.Path,"%s\\%s.%s",P.File.Dir,P.File.Name,P.File.Ext); 
	else exit(1);
	}
                 

/* SAVE DATA TO FILE */
void DataSave(void){ 
	int ic,ifr,ip;			
/*
	do {
		P.File.File = fopen(P.File.Path, "ab");
		}
	while(P.File.File == NULL);
*/	
	for(ifr=0;ifr<P.Frame.Num;ifr++)
		for(ip=0;ip<P.Num.Page;ip++){
			if(P.Info.SubHeader) while(fwrite (&D.Sub[ifr][ip], sizeof(T_SUB), 1, P.File.File)<1);
			while(fwrite(D.Data[ifr][ip],sizeof(T_DATA),P.Chann.Num,P.File.File)<P.Chann.Num);
			}
	fflush(P.File.File);
//	fclose(P.File.File);
	for(ifr=0;ifr<P.Frame.Num;ifr++)
		for(ip=0;ip<P.Num.Page;ip++)
			for(ic=0;ic<P.Chann.Num;ic++)
				D.Data[ifr][ip][ic]=0;
	//if(P.Moxy.Moxy) return;
	//P.Frame.Actual=0;
	//P.Ram.Actual++;
	}
    

/* COMPILE HEADER (COMMON PART) */
void CompileHeader(void){
	int id,il;

	// Version Info
	D.Head.Ver[0]=(short)(-VER_DUE);
	D.Head.Ver[1]=(short)(P.Mamm.Mamm?VER_MAMM:VER_GEN);
	D.Head.SubHeadVer=VER_UNO;

	// General Info
	D.Head.SubHeader=P.Info.SubHeader;
	D.Head.SizeHeader=sizeof(D.Head);
	D.Head.SizeSubHeader=sizeof(T_SUB);
	D.Head.SizeData=sizeof(T_DATA);
	D.Head.Kind=P.Info.Kind;
	D.Head.Appl=P.Info.Appl;
	D.Head.Oma=P.Oma.Oma;
	
	// Time Info
	strncpy(D.Head.Date,DateStr(),10+1);
	strncpy(D.Head.Time,TimeStr(),8+1);

	// Loop Info
	for(il=0;il<MAX_LOOP;il++){
		D.Head.LoopHome[il]=P.Loop[il].Home;
		D.Head.LoopFirst[il]=P.Loop[il].First;
		D.Head.LoopLast[il]=P.Loop[il].Last;
		D.Head.LoopDelta[il]=P.Loop[il].Delta;
		D.Head.LoopNum[il]=P.Loop[il].Num;
		}
		
	// Spc Info	
	D.Head.McaChannNum=P.Chann.Num;
	D.Head.McaTime=P.Spc.TimeM;
	D.Head.McaFactor=P.Spc.Factor;
	D.Head.MeasNorm=FALSE;
	
	// Frame Info
	D.Head.PageNum=P.Num.Page;
	D.Head.FrameNum=P.Frame.Num;
	D.Head.RamNum=P.Ram.Num;
	
	// Label Info
	for(il=0;il<LABEL_MAX;il++){
		strncpy(D.Head.LabelName[il],P.Label[il].Name,LABEL_NAMELEN);
		strncpy(D.Head.LabelContent[il],P.Label[il].Content,LABEL_CONTENTLEN);
		}
		
	// Const Info	
	D.Head.Constn=P.Const.N;
	D.Head.ConstRho=P.Const.Rho;
	D.Head.ConstThick=P.Const.Thick;
	
	// Mamm Info
	D.Head.MammHeader=VER_MAMM_HEADER;
	for(id=0;id<D2;id++){
		D.Head.MammIdxFirst[id]=P.Mamm.Idx[id].First;
		D.Head.MammIdxLast[id]=P.Mamm.Idx[id].Last;
		D.Head.MammIdxTop[id]=P.Mamm.Idx[id].Top[MAMM_VIS];
		D.Head.MammRateMid[id]=P.Mamm.Rate.Mid[id];
		D.Head.MammRateHigh[id]=P.Mamm.Rate.High[id];
		}
	}
                 
                 
                                                                                                       	                 
/* ########################   MISCELLANEOUS PROCEDURES   ################## */

/* INITIALIZE IEEE 488 */
void InitIeee(void){
	SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "Initializing IEEE...");
	Passed();
	}


/* INITIALIZE TIO TIMING */
/*void InitTime(void){
	int counter_num=1;
	P.Time.Time=P.Mamm.Mamm;
	if(!P.Time.Time) return;
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "Initializing TIO Timing ...");
	P.Time.Board = STEP_TIO_BOARD1;
	sprintf (P.Time.sCount,"%d", counter_num);  // uses counter 1 and 2.
	CounterEventOrTimeConfig (P.Time.Board, P.Time.sCount, TWO_COUNTERS,
							  1000000, COUNT_CONTINUOUSLY,
							  COUNT_ON_RISING_EDGE,
							  UNGATED_SOFTWARE_START, &P.Time.Counter);
	CounterStart(P.Time.Counter);
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE," PASSED\n");
	}
*/
void InitTime(void){
	int counter_num=1;
	switch(P.Time.Time) {
		case TIME_WIN:
			break;
		case TIME_TIOMAMM:
		    SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "Initializing TIO Timing ...");
			P.Time.Board = STEP_TIO_BOARD1;
			sprintf (P.Time.sCount,"%d", counter_num);  // uses counter 1 and 2.
			CounterEventOrTimeConfig (P.Time.Board, P.Time.sCount, TWO_COUNTERS,
							  1000000, COUNT_CONTINUOUSLY,
							  COUNT_ON_RISING_EDGE,
							  UNGATED_SOFTWARE_START, &P.Time.Counter);
			CounterStart(P.Time.Counter);
    		SetCtrlVal (hDisplay, DISPLAY_MESSAGE," PASSED\n");
			break;
		}
	return;
	}

/* CLOSE TIMING TIO*/
/*void CloseTime(void){
	if(!P.Time.Time) return;
	CounterStop(P.Time.Counter);
	}
*/

void CloseTime(void){
	switch(P.Time.Time) {
		case TIME_WIN:
			break;
		case TIME_TIOMAMM:
			CounterStop(P.Time.Counter);
			break;
		}
	return;
	}


/* NEW TIMER FUNCTION */
/*double TimerN(void){
	double now;
	long nowTio;
	short overflow;
	if(!P.Time.Time) now=Timer();
	else{
		CounterRead (P.Time.Counter, &nowTio, &overflow);
		now=(double) (nowTio/1000000.0);
		}
	return now;
	}
*/

double TimerN(void){
	double now;
	long nowTio;
	short overflow;
	switch(P.Time.Time) {
		case TIME_WIN:
			now=Timer();
			break;
		case TIME_TIOMAMM:
			CounterRead (P.Time.Counter, &nowTio, &overflow);
			now=(double) (nowTio/1000000.0);
			break;
		}
	return now;
	}

	
/* ########################   PROFILING FUNCTIONS   ########################### */

//#ifdef IS_PROFILING
/* INIT TIME PROFILING */
void InitProf(void){
	int ip;
	ProfId=0;
	SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "Initializing PROFILING...");
	for(ip=0;ip<PROF_MAX_ID;ip++){
		ProfT[ip]=0.0;
		CopyString (ProfS[ProfId], 0, "", 0, PROF_MAX_STRLEN);
		}
	}

/* RECORD TIME PROFILING */
void RecProf(char *Label){
	if((IS_PROFILING)&&(ProfId<PROF_MAX_ID)) {
		ProfT[ProfId]=TimerN(); 
		CopyString (ProfS[ProfId], 0, Label, 0, PROF_MAX_STRLEN);
		ProfId++;
		}
	}
	
/* CLOSE TIME PROFILING */
void CloseProf(void){
	int ip;
	FILE *pFile;
	SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "Closing PROFILING...");
	pFile = fopen (PROF_FILE_NAME, "w");
	for(ip=0;ip<ProfId;ip++)
		fprintf (pFile, "%s\t%f\n", ProfS[ip],ProfT[ip]);
	fclose(pFile);
	}
	
//#endif


/* ########################   TOOLS FUNCTIONS   ########################### */


/* WRITE TO GPIB */
void GpibWrite(int Address,char *Command){
	int status;
	switch (Address) {
		case GPIBVARRO:
			status = ibwrt (P.Gpib[Address].hGpib, Command, strlen(Command));
			if(status<0x8000) return;
			status = ibwrt (P.Gpib[Address].hGpib, Command, strlen(Command));
			if(status>=0x8000) Failure("Error: Writing to GPIB");
			break;
		case GPIBNEWP:
			Send (GPIB0, 02, Command, strlen(Command), NLend);
			break;
		}
	}

/* READ FROM GPIB */
void GpibRead(int Address, char *Buffer, int MaxByte){
	int status;
	switch (Address) {
		case GPIBVARRO:
			status = ibrd (P.Gpib[Address].hGpib, Buffer, MaxByte);
			if(status<0x8000) return;
			status = ibrd (P.Gpib[Address].hGpib, Buffer, MaxByte);
			if(status>=0x8000) Failure("Error: Reading from GPIB");
			break;
		case GPIBNEWP:
			Receive (GPIB0, 02, Buffer, MaxByte, 256);
			break;
		}
	}

/* INITIALIZATION FAILURE */
void Failure(char *Error){
    char message[10*STRLEN];
    sprintf(message,"%s\nPress Exit to Return to Main Panel",Error);
	GenericMessagePopup ("FAILURE!", message, "EXIT", 0, 0, 0, 0,
								  0, VAL_GENERIC_POPUP_BTN1,
								  VAL_GENERIC_POPUP_BTN1,
								  VAL_GENERIC_POPUP_BTN1);
	P.Command.Abort=TRUE;
	}


/* INITIALIZATION PASSED */
void Passed(void){
	SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "PASSED\n");
	}


/* FUNCTION CUSTOM INTEGER TO ASCII */
char *NewItoa(int num, char *numstring, int length){
    int i, numzeri;
    char str[STRLEN];
	Fmt (str, "%s<%d", num);
    numzeri=length-strlen(str);
    strcpy(numstring, "\0");
    for(i=0; i<numzeri; i++)
		strcat(numstring, "0");
    strcat(numstring, str);
    return(numstring);
    }
    
    
/* FUNCTION STRING TO NUM*/    
int StringToNum(char *sNum){
	short i;
	int num=0;
	for(i=0;sNum[i++]!='P';);
		num = atoi (&sNum[i]);
	return (num);
} 


/* FUNCTION GENERATE CONTROL BYTES LRC */
void CompLRC(char *pointer, int size){
    unsigned cksum=0;
    int i;
    for(i=0;i<size;i++)
	cksum ^= *pointer++;
    *pointer++ = (char) (cksum | 0x80);
    *pointer++ = (char) (~cksum | 0x80);
    *pointer = '\0';
    }


/* FUNCTION SET TIME ORIGIN */
void SetNow(clock_t *ptimeorigin){
    *ptimeorigin = clock();
    }


/* FUNCTION WAIT FOR FIXED NUMBER OF MICROSECONDS */
void CheckTime(clock_t timeorigin){
    clock_t goal;
    goal = (short)P.Spc.TimeM*100 + timeorigin;  //TODO: CHECK
    while(goal>clock());
    }


/* PRINT ELAPSED TIME SINCE SET NOW (ms) */
void PrintTime(clock_t timeorigin, char *Title){
    long delta;
    delta = (long) (clock()-timeorigin);
    printf("%s = %ld\n",Title,delta);
    }


/* CALIBRATE TIME FOR PROFILER & DELAY */
void CalibrateTime(double TimeDelay){
    Delay(TimeDelay);
    }


/* ERROR HANDLER */
void ErrHandler(int Device, int Code, char* Function){
	char sdevice[STRLEN],serror[STRLEN],smessage[STRLEN];
	switch (Device){
		case ERR_SPC:
			SPC_get_error_string((short)Code,serror,STRLEN);
			strcpy (sdevice, "SPC");
			break;
	
		}
	sprintf(smessage,"Device = %s\nFunction = %s\nMessage = %s",sdevice,Function,serror);
	MessagePopup ("ERROR RETURN FUNCTION", smessage);
	}
	

/* ########################   MEMORY ALLOCATION PROCEDURES   ########################### */

// Allocate 1D Array of T_DATA
T_DATA *DAlloc1D(int Num1){
	T_DATA *d;
	d=(T_DATA*)calloc(Num1, sizeof(T_DATA));
	if(!d) ErrHandler(ERR_MEM,0,"Allocation Failure of 1D Data");
	return d;
	}

// Allocate 2D Array of T_DATA
T_DATA **DAlloc2D(int Num1, int Num2){
	int i1;
	T_DATA **d;
	d=(T_DATA**)calloc(Num1,sizeof(T_DATA*));
	if(!d) ErrHandler(ERR_MEM,0,"Allocation Failure of 2D Data, Stage 1");
	for(i1=0;i1<Num1;i1++){
		d[i1]=(T_DATA*)calloc(Num2,sizeof(T_DATA));
		if(!d[i1]) ErrHandler(ERR_MEM,0,"Allocation Failure of 2D Data, Stage 2");
		}
	return d;
	}

// Allocate 3D Array of T_DATA
T_DATA ***DAlloc3D(int Num1, int Num2, int Num3){
	int i1,i2;
	T_DATA ***d;
	d=(T_DATA***)calloc(Num1,sizeof(T_DATA**));
	if(!d) ErrHandler(ERR_MEM,0,"Allocation Failure of 3D Data, Stage 1");
	for(i1=0;i1<Num1;i1++){
		d[i1]=(T_DATA**)calloc(Num2,sizeof(T_DATA*));
		if(!d[i1]) ErrHandler(ERR_MEM,0,"Allocation Failure of 3D Data, Stage 2");
		for(i2=0;i2<Num2;i2++){
			d[i1][i2]=(T_DATA*)calloc(Num3,sizeof(T_DATA));
			if(!d[i1][i2]) ErrHandler(ERR_MEM,0,"Allocation Failure of 3D Data, Stage 3");
			}
		}
	return d;
	}

// Allocate 2D Array of T_SUB
T_SUB **SAlloc2D(int Num1, int Num2){
	int i1;
	T_SUB **d;
	d=(T_SUB**)calloc(Num1,sizeof(T_SUB*));
	if(!d) ErrHandler(ERR_MEM,0,"Allocation Failure of 2D SubHeader, Stage 1");
	for(i1=0;i1<Num1;i1++){
		d[i1]=(T_SUB*)calloc(Num2,sizeof(T_SUB));
		if(!d[i1]) ErrHandler(ERR_MEM,0,"Allocation Failure of 2D SubHeader, Stage 2");
		}
	return d;
	}

// Free 1D Array of T_DATA
void DFree1D(T_DATA *D){
	free((char*) (D));
	}

// Free 2D Array of T_DATA
void DFree2D(T_DATA **D, int Num1){
	int i1;
	for(i1=Num1-1;i1>=0;i1--)
		free((char*) (D[i1]));
	free((char*) (D));
	}

// Free 3D Array of T_DATA
void DFree3D(T_DATA ***D, int Num1, int Num2){
	int i1,i2;
	for(i1=Num1-1;i1>=0;i1--){
		for(i2=Num2-1;i2>=0;i2--)
			free((char*) (D[i1][i2]));
		free((char**) (D[i1]));
		}
	free((char*) (D));
	}

// Free 2D Array of T_SUB
void SFree2D(T_SUB **D, int Num1){
	int i1;
	for(i1=Num1-1;i1>=0;i1--)
		free((char*) (D[i1]));
	free((char*) (D));
	}


/* ########################   MAMM PROCEDURES   ########################### */

/* MAMM KERNEL */
void KernelMamm(void){
	InitLegend();
	InitMamm();
	Oscilloscope(); if(P.Command.Abort) return;
	FindTop();
	InitDataFile();
	InitRam();
	Oscilloscope(); if(P.Command.Abort) return;
	DoMamm();
	}


/* INITIALIZE LEGEND */
void InitLegend(void){
	int IdName,IdContent,IdThick;
	int it,il;
	if(!P.Mamm.AutoLabel) return;
	for (it=0; it<T.Num; it++){
		if((T.Panel[it]==LABEL)&&(T.Ctrl[it]==LABEL_NAME_1)) IdName=it;
		if((T.Panel[it]==PARM)&&(T.Ctrl[it]==PARM_CONST_THICK)) IdThick=it;
		}
	for(il=0;il<LABEL_MAX;il++)
		if(P.Label[il].Auto)
			AddLabel(IdName+3*il);
	AddThick(IdThick);
	}

/* ADD LABEL */
void AddLabel(int IdName){
	int IdContent=IdName+1;
	char Message[STRLEN];
	char *LabelName=T.Addr[IdName];
	char *LabelContent=T.Addr[IdContent];
	char Answer[LABEL_CONTENTLEN];

	sprintf(Message,"%s\n\n press enter to confirm or edit to modify",LabelContent);
	PromptPopup (LabelName,Message,Answer,LABEL_CONTENTLEN-1);
	if(strlen(Answer)>0) strcpy(LabelContent,Answer);
	SetCtrlAttribute (hPanel[T.Panel[IdContent]],T.Ctrl[IdContent],ATTR_CTRL_VAL,LabelContent);
	}
	

	/* ADD THICK */
void AddThick(int ID){
	char Message[STRLEN];
	double *actualValue=T.Addr[ID];
	char Answer[STRLEN];

	sprintf(Message,"Please Enter THICKNESS in cm, use . (dot)\n   Actual value is %f\n Press Enter to Confirm or Modify",*actualValue);
	PromptPopup ("THICKNESS",Message,Answer,LABEL_CONTENTLEN-1);
	if(strlen(Answer)>0) Scan (Answer,"%f",actualValue);
	SetCtrlAttribute (hPanel[T.Panel[ID]],T.Ctrl[ID],ATTR_CTRL_VAL,*actualValue);
	}


/* INITIALIZE MAMM */
void InitMamm(void) {
	
	int ib, it;

	P.Mamm.Att[MAMM_NIR].IdxMin2 = MAMM_NIR_IDX_MIN_BORDER;
	P.Mamm.Att[MAMM_NIR].IdxMax2 = MAMM_NIR_IDX_MAX_BORDER;
		
	if(P.Mamm.FindTop) {
		for(ib=0; ib<P.Num.Board; ib++) MoveMicro(P.Mamm.Att[ib].Step, P.Mamm.Att[ib].IdxMax, TRUE);
		for(it=0; it<MAX_TRIM; it++)
			if(P.Trim[it].Trim) AutoTrim(it);
		}
	return;
	}
	
/* INITIALIZE RAM SAVING */
void InitRam(void){
	if(P.Meas.Ram!=0) return;
	DataRam0 = calloc (P.Frame.Num*P.Num.Page*P.Chann.Num, sizeof(unsigned short));
	DataRam=DataRam0;
	}

/* DO MAMM */
void DoMamm(void){
	int panel,control;
	int ic,ifr,ip;
	long goal, finalgoal;
	int ilimit;
	char is_within, is_before, is_border_VIS, is_border_NIR;
	char status=(P.Meas.Status==1);
	struct StepS *step[2];
	char stepx=P.Mamm.Step[X];
	char stepy=P.Mamm.Step[Y];
	P.Contest.Function==CONTEST_MEAS;
	
	step[X]=&P.Step[stepx];
	step[Y]=&P.Step[stepy];
	P.Step[stepx].Dir=MAMM_DIR_POS;
	P.Acq.Actual = 0;

	// Clear DATA
	for(ifr=0; ifr<P.Frame.Num; ifr++)
		for(ip=0; ip<P.Num.Page; ip++)
			for(ic=0; ic<P.Chann.Num; ic++)
				D.Data[ifr][ip][ic]=0;
	for(ifr=0; ifr<P.Frame.Num; ifr++)
		for(ip=0; ip<P.Num.Page; ip++)
			CompileSub(P.Ram.Actual, ifr, ip);

	for(P.Mamm.Idx[Y].Actual = P.Mamm.Idx[Y].Top[MAMM_VIS]; P.Mamm.Idx[Y].Actual>=P.Mamm.Idx[Y].First; P.Mamm.Idx[Y].Actual--){
	
		P.Frame.Max = 0;
		P.Frame.Min = MAMM_NUM_ROW-1;
		
		MoveStep(&step[Y]->Actual,P.Step[stepy].Start[P.Mamm.Idx[Y].Actual],stepy,TRUE,status);
		finalgoal=(P.Step[stepx].Dir>0?step[X]->Stop[P.Mamm.Idx[X].Last]:step[X]->Start[P.Mamm.Idx[X].First]);
		is_before=TRUE;
		ilimit = (P.Step[stepx].Dir>0?P.Mamm.Idx[X].Last:P.Mamm.Idx[X].First);
		MoveStep(&step[X]->Actual,finalgoal,stepx,FALSE,status);
		do {
			P.Frame.Actual = P.Mamm.Idx[X].Actual;
			if(P.Frame.Actual<P.Frame.Min) P.Frame.Min=P.Frame.Actual;
			if(P.Frame.Actual>P.Frame.Max) P.Frame.Max=P.Frame.Actual;

			goal = (P.Step[stepx].Dir>0?step[X]->Stop[P.Mamm.Idx[X].Actual]:step[X]->Start[P.Mamm.Idx[X].Actual]);
			SpcReset(status,P.Meas.Clear,P.Meas.Stop);
			WaitPos(stepx,goal);
			if(P.Meas.Stop) SpcStop(status);
			SpcOut(status);
			if((P.Mamm.Idx[Y].Actual==P.Mamm.Idx[Y].Top[MAMM_NIR])&&(P.Mamm.Idx[X].Actual==P.Mamm.Idx[X].Top[MAMM_VIS])) {
				StopStep(stepx);
				MoveMicro(P.Mamm.Att[MAMM_NIR].Step, P.Mamm.Att[MAMM_NIR].IdxMax2, TRUE);
				MoveStep(&goal, finalgoal, stepx, FALSE, status);
				}
			AnalysisMamm();
			is_within = (P.Mamm.Idx[X].Actual!=ilimit);
			is_before &= (P.Mamm.Idx[X].Actual!=P.Mamm.Idx[X].Top[MAMM_VIS]);
			is_border_VIS = IsBorderVIS(is_before);
			is_border_NIR = IsBorderNIR(is_before, is_border_VIS);
			if(is_border_NIR) {
				StopStep(stepx);
				MoveMicro(P.Mamm.Att[MAMM_NIR].Step, P.Mamm.Att[MAMM_NIR].IdxGoal, TRUE);
				MoveStep(&goal, finalgoal, stepx, FALSE, status);
				}
			P.Mamm.Idx[X].Actual += P.Step[stepx].Dir;
			}
		while(is_within&&!is_border_VIS&&!P.Spc.Overflow);
		StopStep(stepx);
		P.Mamm.Idx[X].Actual -= P.Step[stepx].Dir;
		DataSaveMamm();
		P.Ram.Actual++;
		P.Step[stepx].Dir*=-1;
		SetTableCellAttribute (hDisplay, DISPLAY_T_LOOP, MakePoint(1,2), ATTR_CTRL_VAL, P.Mamm.Idx[Y].Actual);
		SetTableCellAttribute (hDisplay, DISPLAY_T_LOOP, MakePoint(1,3), ATTR_CTRL_VAL, P.Mamm.Idx[X].Actual);
		GetUserEvent (0, &panel, &control);
		if(P.Command.Abort) break;
		}
	}

char IsBorderNIR(char is_before, char is_border_VIS) {

	char stepx=P.Mamm.Step[X];
	
	if(is_border_VIS) return(FALSE);
	if(!is_before)
		if(P.Mamm.Rate.Actual[MAMM_NIR]>P.Mamm.Rate.High[MAMM_NIR]) {
			P.Mamm.Idx[X].Border[MAMM_NIR] = P.Mamm.Idx[X].Actual+P.Step[stepx].Dir;
			P.Mamm.Att[MAMM_NIR].IdxGoal = P.Mamm.Att[MAMM_NIR].IdxMin2;
			return(TRUE);
			}

	if(is_before&&(P.Mamm.Idx[X].Actual == P.Mamm.Idx[X].Border[MAMM_NIR])) {
		P.Mamm.Att[MAMM_NIR].IdxGoal = P.Mamm.Att[MAMM_NIR].IdxMax2;
		return(TRUE);
		}		
		
	return(FALSE);	

	}

char IsBorderVIS(char is_before) {

	if((!is_before)&&((P.Mamm.Rate.Actual[MAMM_VIS]>P.Mamm.Rate.High[MAMM_VIS])||
						(P.Mamm.Rate.Actual[MAMM_VIS]<P.Mamm.Rate.Low[MAMM_VIS])))
		return(TRUE);
		
	return(FALSE);	

	}

/* FIND TOP OF MAMM */
void FindTop(void){
	int ib,ipos,ineg,itemp,is,it;
	long half;
	char status=TRUE;
	int stepNIR = P.Mamm.Att[MAMM_NIR].Step;
	int *piy=&P.Mamm.Idx[Y].Actual;
	int *pix=&P.Mamm.Idx[X].Actual;
	struct StepS *stepx=&P.Step[P.Mamm.Step[X]];
	struct StepS *stepy=&P.Step[P.Mamm.Step[Y]];
	double RateMidVIS = P.Mamm.Rate.Mid[MAMM_VIS];
	int num_meas;
	
	P.Contest.Function==CONTEST_OSC;

	if(!P.Mamm.FindTop){
		P.Mamm.Idx[Y].First = 0;
		P.Mamm.Idx[Y].Last = P.Mamm.Idx[Y].Num-1;
		P.Mamm.Idx[Y].Top[MAMM_VIS] = P.Mamm.Idx[Y].Last;
		P.Mamm.Idx[Y].Top[MAMM_NIR] = P.Mamm.Idx[Y].Last;
		P.Mamm.Idx[Y].Actual = P.Mamm.Idx[Y].First;
		P.Mamm.Idx[X].First = 0;
		P.Mamm.Idx[X].Last = P.Mamm.Idx[X].Num-1;
		P.Mamm.Idx[X].Top[MAMM_VIS] = P.Mamm.Idx[X].First;
		P.Mamm.Idx[X].Top[MAMM_NIR] = P.Mamm.Idx[X].First;
		P.Mamm.Idx[X].Actual=P.Mamm.Idx[X].First;
		MoveStep(&stepy->Actual,stepy->Start[P.Mamm.Idx[Y].Top[MAMM_VIS]],P.Mamm.Step[Y],WAIT_TRUE,status);	
		MoveStep(&stepx->Actual,stepx->Start[P.Mamm.Idx[X].Top[MAMM_VIS]],P.Mamm.Step[X],WAIT_TRUE,status);	
		for(ib=0; ib<P.Num.Board; ib++) MoveMicro(P.Mamm.Att[ib].Step, P.Mamm.Att[ib].IdxMax, TRUE);
		for(it=0; it<MAX_TRIM; it++)
			if(P.Trim[it].Trim) AutoTrim(it);
		return;
		}
	
	
	MoveMicro(stepNIR, P.Mamm.Att[MAMM_NIR].IdxMin, TRUE);
	
	for(ib=0;ib<P.Mamm.IterBord;ib++){
		if(P.Command.Abort) {
			CloseMeasure(); 
			return;
			}

		if(!P.Mamm.Shrink[X]) FindBorderVIS(piy, Y, RateMidVIS, MAMM_DIR_POS);
		itemp = *pix;
		ipos = FindBorderVIS(pix, X, P.Mamm.Rate.High[MAMM_VIS], MAMM_DIR_POS);
		MoveStep(&stepx->Actual,stepx->Start[itemp], P.Mamm.Step[X], WAIT_TRUE, status);
		*pix = itemp;
		ineg = FindBorderVIS(pix, X, P.Mamm.Rate.High[MAMM_VIS], MAMM_DIR_NEG);
		*pix = (int)((ipos+ineg)/2);
		half = stepx->Start[*pix];
		MoveStep(&stepx->Actual, half, P.Mamm.Step[X], WAIT_TRUE, status);
		if(P.Mamm.Shrink[X]) FindBorderVIS(piy, Y, RateMidVIS, MAMM_DIR_POS);
		
		RateMidVIS = (RateMidVIS + P.Mamm.Rate.High[MAMM_VIS])/2;
		if(ib==0) P.Mamm.Idx[X].First = (P.Mamm.Shrink[X]?ineg:0);
		if(ib==0) P.Mamm.Idx[X].Last = (P.Mamm.Shrink[X]?ipos:P.Mamm.Idx[X].Num-1);
		}

	P.Mamm.Idx[X].Top[MAMM_VIS] = P.Mamm.Idx[X].Actual;
	P.Mamm.Idx[X].Top[MAMM_NIR] = P.Mamm.Idx[X].Actual;
	FindBorderVIS(piy, Y, P.Mamm.Rate.High[MAMM_VIS], MAMM_DIR_POS);
	P.Mamm.Idx[Y].Top[MAMM_VIS] = P.Mamm.Idx[Y].Actual;
	P.Mamm.Idx[Y].Top[MAMM_NIR] = P.Mamm.Idx[Y].Actual;
	P.Mamm.Idx[Y].First = 0;
	P.Mamm.Idx[Y].Last = (P.Mamm.Shrink[Y]?P.Mamm.Idx[Y].Top[MAMM_VIS]:P.Mamm.Idx[Y].Num-1);
	
//	Find Top NIR
//	Indietreggia di una quantità fissa
	if(P.Mamm.BackTopNIR>0) {
		P.Mamm.Idx[Y].Top[MAMM_NIR] = P.Mamm.Idx[Y].Top[MAMM_NIR]-P.Mamm.BackTopNIR;
		MoveStep(&stepy->Actual,stepy->Start[P.Mamm.Idx[Y].Top[MAMM_NIR]], P.Mamm.Step[Y],WAIT_TRUE, status);
		}
//	Indietreggia finchè conteggi VIS > RateLow
	do {
		P.Mamm.Idx[Y].Top[MAMM_NIR]--;
		MoveStep(&stepy->Actual,stepy->Start[P.Mamm.Idx[Y].Top[MAMM_NIR]], P.Mamm.Step[Y],WAIT_TRUE, status);	
		SpcReset(status, P.Meas.Clear, P.Meas.Stop);
		SpcWait();
		SpcOut(status);
		AnalysisMamm();
		}
	while(P.Mamm.Rate.Actual[MAMM_VIS] < P.Mamm.Rate.Low[MAMM_VIS]);
	
//	Ricerca del top del NIR	
	SetVelMicro(stepNIR, P.Mamm.Att[MAMM_NIR].FreqOpen);
	num_meas = (int)((P.Mamm.Att[MAMM_NIR].IdxMax-P.Mamm.Att[MAMM_NIR].IdxMin+1)/P.Mamm.Att[MAMM_NIR].FreqOpen/P.Spc.TimeM);
	MoveMicro(stepNIR, P.Mamm.Att[MAMM_NIR].IdxMax, FALSE);
	for(is=0; is<=num_meas; is++){
		SpcReset(status, P.Meas.Clear, P.Meas.Stop);
		SpcWait();
		SpcOut(status);
		AnalysisMamm();
		if(P.Mamm.Rate.Actual[MAMM_NIR] > P.Mamm.Rate.High[MAMM_NIR]){
			P.Mamm.Idx[Y].Top[MAMM_NIR]--;
			MoveStep(&stepy->Actual,stepy->Start[P.Mamm.Idx[Y].Top[MAMM_NIR]],P.Mamm.Step[Y],WAIT_TRUE,status);	
			}
		}
	WaitMicro(stepNIR, P.Mamm.Att[MAMM_NIR].IdxMax);
	SetVelMicro(stepNIR, P.Step[stepNIR].Freq);
	MoveMicro(stepNIR, P.Mamm.Att[MAMM_NIR].IdxMin2, TRUE);
	MoveStep(&stepy->Actual,stepy->Start[P.Mamm.Idx[Y].Top[MAMM_VIS]],P.Mamm.Step[Y],WAIT_TRUE,status);	

//		FindBorder(pix, X, P.Mamm.Count.High,MAMM_DIR_NEG);

	}

/* FIND BORDER IN LINEMAMM */

int FindBorderVIS(int *iActual,char Axis,double Rate,char Dir){
	long goal;
	int is_border;
	char status=TRUE;
	char step_issue=P.Mamm.Step[Axis];
	struct StepS *step=&P.Step[P.Mamm.Step[Axis]];
	int ilimit=(Dir>0?P.Mamm.Idx[Axis].Num-1:0);
	long limit=(Dir>0?P.Step[step_issue].Stop[ilimit]:P.Step[step_issue].Start[ilimit]);
	step->Dir=Dir;
	if(Dir>0) *iActual-=Dir;
	MoveStep(&step->Actual,limit,step_issue,WAIT_FALSE,status);
	do{
		*iActual+=Dir;
		goal=(Dir>0?P.Step[step_issue].Stop[*iActual]:P.Step[step_issue].Start[*iActual]);
		SpcReset(status,P.Meas.Clear,P.Meas.Stop);
		WaitPos(step_issue,goal);
		if(P.Meas.Stop) SpcStop(status);
		SpcOut(status);
		AnalysisMamm();
		is_border = (P.Mamm.Rate.Actual[MAMM_VIS]>Rate)||(P.Mamm.Rate.Actual[MAMM_VIS]<P.Mamm.Rate.Low[MAMM_VIS]);
		}
	while(!is_border&&(*iActual!=ilimit)&&!P.Spc.Overflow);
	StopStep(step_issue);
	return *iActual;
	}

/* IS LOWER THEN LEVEL? */
/*int IsLower(long *Count){
	int is_lower_VIS,is_lower_NIR,is_lower;
	is_lower_VIS=(P.Mamm.Count.Actual[MAMM_VIS]<Count[MAMM_VIS])&&(P.Mamm.Count.Actual[MAMM_VIS]>=P.Mamm.Count.Low[MAMM_VIS]);
	is_lower_NIR=(P.Mamm.Count.Actual[MAMM_NIR]<Count[MAMM_NIR]);
	switch (P.Mamm.Border){
		case MAMM_NONE: is_lower=TRUE;
		case MAMM_ONLY_VIS: is_lower=is_lower_VIS; break;
		case MAMM_ONLY_NIR: is_lower=is_lower_NIR; break;
		case MAMM_VIS_AND_NIR: is_lower=(is_lower_VIS||is_lower_NIR); break;
		case MAMM_VIS_OR_NIR: is_lower=(is_lower_VIS&&is_lower_NIR); break;
		}
	return(is_lower);
	}
*/	

/* SAVE DATA TO FILE FOR MAMM */
void DataSaveMamm(void){
	int ic,ifr,ip;
	long numchann=P.Num.Page*P.Chann.Num;
	int numpoint= P.Frame.Num;
	
	
	if(P.Meas.Ram!=0){
//		P.File.File = fopen(P.File.Path, "ab");
		for(ifr=P.Frame.Min; ifr<=P.Frame.Max; ifr++)
			for(ip=0; ip<P.Num.Page; ip++){
				if(P.Info.SubHeader) while(fwrite (&D.Sub[ifr][ip], sizeof(T_SUB), 1, P.File.File)<1);
				while(fwrite(D.Data[ifr][ip],sizeof(T_DATA),P.Chann.Num,P.File.File)<P.Chann.Num);
				}
		fflush(P.File.File);
//		fclose(P.File.File);
		for(ifr=0; ifr<P.Frame.Num; ifr++)
			for(ip=0; ip<P.Num.Page; ip++)
				for(ic=0; ic<P.Chann.Num; ic++)
					D.Data[ifr][ip][ic]=0;
		for(ifr=0; ifr<P.Frame.Num; ifr++)
			for(ip=0; ip<P.Num.Page; ip++)
				CompileSub(P.Ram.Actual, ifr, ip);
		}
	else{ //TODO: suppress
		for(ifr=0;ifr<P.Frame.Num;ifr++)
			for(ip=0;ip<P.Num.Page;ip++)
				for(ic=0;ic<P.Chann.Num;ic++)
					DataRam[ic]=D.Data[ifr][ip][ic];
		DataRam+=numpoint*numchann;
		}
	}

/* ANALYZE SCANS */
void AnalysisMamm(void){
	int ib,ic;
	for(ib=0;ib<MAMM_NUM_BOARD;ib++) P.Mamm.Count.Actual[ib]=0;
	for(ib=0;ib<MAMM_NUM_BOARD;ib++)
		for(ic=0;ic<P.Chann.Num;ic++)
			P.Mamm.Count.Actual[ib]+=D.Buffer[ib][ic]; //TODO: Buffer o Data?
	
	for(ib=0;ib<MAMM_NUM_BOARD;ib++) {
		P.Mamm.Rate.Actual[ib] = P.Mamm.Count.Actual[ib]/P.Spc.EffTime[ib];
		}
	//for(ib=0;ib<P.Num.Board;ib++)
		//SetTableCellAttribute(hDisplay,DISPLAY_T_BOARD,MakePoint(1,ib+1),ATTR_CTRL_VAL,P.Mamm.Count.Actual[ib]);
	//**SetTableCellVal(hDisplay,DISPLAY_T_BOARD,MakePoint(1,0+1),P.Mamm.Count.Actual[0]);
	//if(!status) return;
	//if(status) SetCtrlVal (hDisplay, DISPLAY_SIG_COUNT, (double)P.Mamm.Count.Actual[MAMM_VIS]); //TODO check
	}


/* MOVE ATTENUATOR ON PMTs */
/*void MoveAttMamm(int board){

	int idx_x_act = P.Mamm.Idx[X].Actual;
	int step = P.Mamm.Att[board].Step;

	if(P.Mamm.Att[board].Vel[idx_x_act] == 0) return;
	
		if(IS_PROFILING) RecProf("Pre WaitMicro");
	if(P.Mamm.Att[board].Wait) WaitMicro(P.Mamm.Att[board].Step, P.Mamm.Att[board].IdxWait);
		if(IS_PROFILING) RecProf("Post WaitMicro");
	
		if(IS_PROFILING) RecProf("Pre SetVelMicro");
	SetVelMicro(step, P.Mamm.Att[board].Vel[idx_x_act]);
		if(IS_PROFILING) RecProf("Post SetVelMicro");
		if(IS_PROFILING) RecProf("Pre MoveMicro");
	MoveMicro(step, P.Mamm.Att[board].Idx[idx_x_act], FALSE);
		if(IS_PROFILING) RecProf("Post MoveMicro");
	P.Mamm.Att[board].Wait = TRUE;
	P.Mamm.Att[board].IdxWait = P.Mamm.Att[board].Idx[idx_x_act];
	}
*/
/*
char FindBorderMamm(char is_before) {

	char ret = 0;
	int ib;
	
	for(ib=0; ib<MAMM_NUM_BOARD; ib++)
		ret |= CalcAttMamm(ib, is_before);
	
	return(ret);	

	}
*/

/* CALC ATTENUATOR POSITION AND VELOCITY */
/*char CalcAttMamm(int board, char is_before){
	
	int idx_x_act = P.Mamm.Idx[X].Actual;
	int idx_x_dir = P.Step[P.Mamm.Step[X]].Dir;
	int idx_x_prev = idx_x_act-idx_x_dir;
	int idx_x_next = idx_x_act+idx_x_dir;
	int idx_att_act  = P.Mamm.Att[board].Idx[idx_x_act];
//	int idx_att_prev = P.Mamm.Att[board].Idx[idx_x_prev];
	int step = P.Mamm.Att[board].Step;
	double rate_act  = P.Mamm.Att[board].Rate[idx_x_act];
	double rate_prev;
	double vel, att_next, att_delta, rate_next;	
	int ia;
	
	if(idx_x_prev<0) idx_x_prev=0;
	rate_prev = P.Mamm.Att[board].Rate[idx_x_prev];
	
	if(!is_before) {
	
		if(rate_act<MAMM_THRESH) {
			P.Mamm.Att[board].Vel[idx_x_next] = 0;
	   	 	P.Mamm.Att[board].Idx[idx_x_next] = P.Mamm.Att[board].Idx[idx_x_act];
			P.Mamm.Att[board].Value[idx_x_next] = P.Mamm.Att[board].Value[idx_x_act];
			return(FALSE);
			}
	
		rate_next = exp(2*log(rate_act)-log(rate_prev*P.Mamm.Att[board].Value[idx_x_prev]/P.Mamm.Att[board].Value[idx_x_act]));
		att_delta = rate_next/MAMM_THRESH;
		att_next = P.Mamm.Att[board].Value[idx_x_act]*att_delta;
		for(ia = idx_att_act; ia>P.Mamm.Att[board].IdxMin; ia--)
			if(P.Mamm.Att[board].Calib[ia]>=att_next) break;

		if(ia==P.Mamm.Att[board].IdxMin) {
			P.Mamm.Att[board].Idx[idx_x_next] = 0;
			return(TRUE);
			}
		
		P.Mamm.Att[board].Idx[idx_x_next] = ia;
	
		vel = abs((P.Mamm.Att[board].Idx[idx_x_next]-idx_att_act)/P.Spc.TimeM);
		if(vel>P.Step[step].FreqMax) {
	    	P.Mamm.Att[board].Idx[idx_x_next] = 0;
			return(TRUE);
			}
   	
		P.Mamm.Att[board].Value[idx_x_next] = P.Mamm.Att[board].Calib[P.Mamm.Att[board].Idx[idx_x_next]];
		P.Mamm.Att[board].Vel[idx_x_next] = vel;
	
		return(FALSE);

		}
	
	// if is_before
	
	if((P.Mamm.Att[board].Idx[idx_x_act] == P.Mamm.Att[board].IdxMax)||(P.Mamm.Att[board].Idx[idx_x_prev]==0)||(rate_act>MAMM_THRESH)) {
		P.Mamm.Att[board].Vel[idx_x_next] = 0;
    	P.Mamm.Att[board].Idx[idx_x_next] = P.Mamm.Att[board].Idx[idx_x_act];
    	P.Mamm.Att[board].Value[idx_x_next] = P.Mamm.Att[board].Value[idx_x_act];
		return(FALSE);
		}
	
	rate_next = exp(2*log(rate_act)-log(rate_prev*P.Mamm.Att[board].Value[idx_x_prev]/P.Mamm.Att[board].Value[idx_x_act]));
	att_delta = rate_next/MAMM_THRESH;
	att_next = P.Mamm.Att[board].Value[idx_x_act]*att_delta;

	for(ia = idx_att_act; ia<P.Mamm.Att[board].IdxMax; ia++)
		if(P.Mamm.Att[board].Calib[ia] <= att_next) break;
	
	P.Mamm.Att[board].Idx[idx_x_next] = ia;
	
	vel = abs((P.Mamm.Att[board].Idx[idx_x_next]-idx_att_act)/P.Spc.TimeM);
	
	if(vel>P.Step[step].FreqMax) {
		P.Mamm.Att[board].Vel[idx_x_next] = P.Step[step].FreqMax;
		P.Mamm.Att[board].Idx[idx_x_next] = idx_att_act + (int)(P.Mamm.Att[board].Vel[idx_x_next]*P.Spc.TimeM);
		}
	else P.Mamm.Att[board].Vel[idx_x_next] = vel;
	
	P.Mamm.Att[board].Value[idx_x_next] = P.Mamm.Att[board].Calib[P.Mamm.Att[board].Idx[idx_x_next]];
	
	return(FALSE);
	
	}
 */

/* ########################   MOXY PROCEDURES   ########################### */

// INITIALIZE MICROCONTROLLER FOR OXYM
void InitMoxy(void){
	char string[STRLEN];
	int written,open,is,ia;
	if(!P.Moxy.Moxy) return;
	SetCtrlVal (hDisplay, DISPLAY_MESSAGE, "Initializing Microcontroller for OXYM ... ");
	P.Moxy.TimeMic = (int)(SEC_TO_MICROSEC*P.Spc.TimeM/P.Acq.Frame);
	if (P.Twitch.NoSwitch>0) P.Moxy.TimeSpc = (float) ((P.Spc.TimeM/P.Acq.Frame)-MOXY_SWITCH_DELAY)*(1-MOXY_OVERHEAD);
	else P.Moxy.TimeSpc = (float) (P.Spc.TimeM)/P.Acq.Frame*(1-MOXY_OVERHEAD); 
	sprintf(P.Moxy.Command,"%s",MOXY_SET);
	if (P.Twitch.NoSwitch>0) strcat(P.Moxy.Command,MOXY_SWITCH);
	else strcat(P.Moxy.Command,MOXY_NO_SWITCH);
	Fmt(string,"%d",P.Moxy.PresentationRise);
	strcat(P.Moxy.Command,string);
	Fmt(string,"%d",P.Moxy.ExternalTrigger);
	strcat(P.Moxy.Command,string);
	Fmt(string,"%d[w9p0]",P.Moxy.DisplayDivisor);
	strcat(P.Moxy.Command,string); 
	Fmt(string,"%d[w9p0]",P.Loop[LOOP3].Num*P.Loop[LOOP2].Num*P.Loop[LOOP1].Num);
	strcat(P.Moxy.Command,string);
	Fmt(string,"%d[w9p0]",P.Moxy.TimeMic);
	strcat(P.Moxy.Command,string);
	for(is=0;is<MOXY_NUM_SWITCH;is++){
		for(ia=0;ia<P.Acq.Frame;ia++){
			sprintf(string,"%d",P.Twitch.Chann[ia][is]);
			strcat(P.Moxy.Command,string);
			}
		if(is==0) strcat(P.Moxy.Command,MOXY_END_SWITCH);
		else strcat(P.Moxy.Command,MOXY_END_COMMAND);
		}
	open=OpenComConfig(MOXY_COMPORT,NULL,MOXY_BAUDRATE,MOXY_PARITY,MOXY_DATABITS,MOXY_STOPBITS,0,-1);
	FlushInQ (MOXY_COMPORT);
	FlushOutQ (MOXY_COMPORT);
	written=ComWrt(MOXY_COMPORT,P.Moxy.Command,strlen(P.Moxy.Command));
	if(open!=0) Failure("Error Opening Com Port");
	else if(written<strlen(P.Moxy.Command)) Failure("Error Writing Com Port");
	else Passed();
	}


// CLOSE MICROCONTROLLER FOR OXYM
void CloseMoxy(void){
	if(!P.Moxy.Moxy) return;
	FlushInQ (MOXY_COMPORT);
	FlushOutQ (MOXY_COMPORT);
	CloseCom (MOXY_COMPORT);
	}


// START MICROCONTROLLER FOR OXYM
void StartMoxy(void){
	sprintf(P.Moxy.Command,"%s%s",MOXY_START,MOXY_END_COMMAND);
	ComWrt(MOXY_COMPORT,P.Moxy.Command,strlen(P.Moxy.Command));
	}


// ABORT MICROCONTROLLER FOR OXYM
void AbortMoxy(void){
	sprintf(P.Moxy.Command,"%s%s",MOXY_ABORT,MOXY_END_COMMAND);
	ComWrt(MOXY_COMPORT,P.Moxy.Command,strlen(P.Moxy.Command));
	}


// START MICROCONTROLLER FOR OXYM
void GotoMoxy(int Switch,int Chann){
	sprintf(P.Moxy.Command,"%s%d%d%s",MOXY_GOTO,Switch,Chann,MOXY_END_COMMAND);
	ComWrt(MOXY_COMPORT,P.Moxy.Command,strlen(P.Moxy.Command));
	}


// WAIT END OF MOXY
void WaitMoxy(void){
	int ib;
	char answer[2];
	answer[0]=0;answer[1]=0;
	do ComRd(MOXY_COMPORT,answer,2);
	while(answer[0]!=MOXY_END);
	for (ib=0;ib<P.Num.Board;ib++)
	    SPC_stop_measurement(ib);
	}


// MOXY KERNEL
void KernelMoxy(void){
	int ic;
	int num_cycle=(int)CEIL(P.Acq.Tot,P.Acq.Bank);
	Oscilloscope();
	InitBank();
	StatusBank(0,num_cycle);
	for(ic=0;ic<num_cycle;ic++){
		EnableBank();
		if(ic==0) StartMoxy();
		if(ic==num_cycle-1)	WaitMoxy();
		WaitBank();
		StatusBank(ic,num_cycle);
		GetBank();
		SpcClear();
		CopySaveBank();
		}
	}



// INITIALIZE CONTINUOUS FLOW
void InitBank(void){
	int ib,ibb;
	SPCdata spc_dat;
	short mem_bank,ret;
	for(ibb=0;ibb<P.Num.Board;ibb++){
		ret=SPC_get_parameters(ibb,&spc_dat);
		if(ret<0) ErrHandler(ERR_SPC,ret,"InitBank:SPC_get_parameters");
		}
	mem_bank=spc_dat.mem_bank;	  // NOTE: taken from last SPC module
	SpcTime(P.Moxy.TimeSpc);
	ret=SPC_enable_sequencer(SPC_ALL,1);
	if(ret<0) ErrHandler(ERR_SPC,ret,"InitBank:SPC_enable_sequencer");
	ret=SPC_set_parameter(SPC_ALL, TRIGGER, 0x302); // trigger each curve
	if(ret<0) ErrHandler(ERR_SPC,ret,"InitBank:SPC_set_parameter:TRIGGER");
	for(ib=0;ib<SPC_NUM_BANK;ib++){
		SpcClear();
		mem_bank=mem_bank?0:1;
		ret=SPC_set_parameter(SPC_ALL,MEM_BANK,mem_bank);
		if(ret<0) ErrHandler(ERR_SPC,ret,"InitBank:SPC_set_parameter:MEM_BANK");
		}
	ret=SPC_set_page(SPC_ALL,0);
	if(ret<0) ErrHandler(ERR_SPC,ret,"InitBank:SPC_set_page");
	}


// WAIT FOR FILLED BANK
void WaitBank(void){
	int ib;
	short ret,finished,spc_state,mod_state[MAX_BOARD];
	do{
		spc_state=0;
		for (ib=0;ib<P.Num.Board;ib++){
			ret=SPC_test_state(ib,&mod_state[ib]);
			if(ret<0) ErrHandler(ERR_SPC,ret,"WaitBank:SPC_test_state");
			spc_state |= mod_state[ib];
			}
	    finished = ((spc_state & SPC_ARMED) == 0);
		}
	while(!finished);
	}


// START NEW BANK
void EnableBank(void){
	short ret;
	int ib;
	for (ib=0;ib<P.Num.Board;ib++){
	    ret=SPC_start_measurement(ib);
		if(ret<0) ErrHandler(ERR_SPC,ret,"SPC_start_measurement");
		}
	}


// TRANSFER BANK TO BUFFER
void GetBank(void){
	int ib;
	short ret;
	for (ib=0;ib<P.Num.Board;ib++){
		ret=SPC_read_data_page(ib,0,P.Spc.MaxPage[ib]-1,D.Bank[ib]);
		if(ret<0) ErrHandler(ERR_SPC,ret,"SPC_read_data_page");
		}
	}
	
// DISPLAY STATUS BANK
void StatusBank(int ActBank, int TotBank){
	double timeT=P.Loop[LOOP1].Num*P.Loop[LOOP2].Num*P.Loop[LOOP3].Num*P.Spc.TimeM;
	double timeA=P.Spc.TimeM/P.Acq.Frame;
	double timeB=timeA*P.Acq.Bank;
	SetTableCellAttribute(hDisplay,DISPLAY_T_BANK,MakePoint(1,ROW_BANK_NUM),ATTR_CTRL_VAL,TotBank);
	SetTableCellAttribute(hDisplay,DISPLAY_T_BANK,MakePoint(1,ROW_BANK_ACTUAL),ATTR_CTRL_VAL,ActBank);
	SetTableCellAttribute(hDisplay,DISPLAY_T_BANK,MakePoint(1,ROW_BANK_TIMET),ATTR_CTRL_VAL,timeT);
	SetTableCellAttribute(hDisplay,DISPLAY_T_BANK,MakePoint(1,ROW_BANK_TIMEB),ATTR_CTRL_VAL,timeB);
	SetTableCellAttribute(hDisplay,DISPLAY_T_BANK,MakePoint(1,ROW_BANK_TIMEA),ATTR_CTRL_VAL,timeA);
	ProcessDrawEvents ();
	}
	
// COPY BANK TO FRAME (AND SAVE)
void CopySaveBank(void){
	int ia,ib,id,ic,page,deltaB;
	int num_acq=MIN(P.Acq.Bank,P.Acq.Tot-P.Acq.Counter);
	for(ia=0;ia<num_acq;ia++){
	
		// CopyAcq
		for(ib=0;ib<P.Num.Board;ib++)
			for(id=0;id<P.Num.Det;id++){
				page=P.Filter.Page[P.Acq.Actual][ib][id];
				if(page!=-1){
					P.Page[page].TimeNom=P.Moxy.TimeSpc;
					P.Page[page].TimeEff=P.Moxy.TimeSpc;
					if(P.Info.SubHeader) CompileSub(P.Ram.Actual,P.Frame.Actual,page);
					deltaB=(ia*P.Num.Det+id)*P.Chann.Num;
					for(ic=0;ic<P.Chann.Num;ic++)
						D.Data[P.Frame.Actual][page][ic]=D.Bank[ib][deltaB+ic];
					}
				}
		P.Acq.Counter++;
		P.Acq.Actual++;
		
		// NewFrame
		if(REMINDER(P.Acq.Counter,P.Acq.Frame)==0){
			P.Frame.Actual++;
			P.Acq.Actual=0;
			}
			
		// NewRam
		if((REMINDER(P.Acq.Counter,P.Acq.Frame*P.Frame.Num)==0)||(P.Acq.Counter==P.Acq.Tot)){
			DataSave();
			P.Ram.Actual++;
			P.Frame.Actual=0;
			}
		
		}
	}

/* ######################################################################## */
/* 								END of TRSMEAS.C							*/ 
/* ######################################################################## */
