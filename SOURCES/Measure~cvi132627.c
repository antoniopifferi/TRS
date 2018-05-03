/* ######################################################################## */
/* 									   														*/
/* 		TRS Measure. Time-Resolved Spectroscopy	 Release 14.2  November  2015   */
/* 									   														*/
/* ######################################################################## */


/* ########################   NOTES   ################################## */

// STANDA  (activate #define)
// CEA
// JUMP
// NKT
// DEMO
// MICRO2
// HYDRA HARP (#define and solve conflicts with def.h of TH260
// TIME HARP 260
// SC1000 (TDC Surface Concepts)
// STANDA2
// MAX_LOOP=5
// SPADLAB (TDC elettronici)
// SPCM32x64 bit DLL
// refolding software SC1000
// multichannel TDC

/* ########################   HELP   ################################## */
// Board = Physical TCSPC Board
// Det = Detector channel as determined by the router bits
// Chann = Channel of the MCA (=minimum time division)
// Frame = Data transferred from the boards and effectively stored in RAM
// Page = Curve belonging to a Frame

/* ########################   HEADINGS   ################################## */

#pragma warning(disable : 4996) // Disable warnings about some functions in VS 2005
#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#define NO_STANDA		// Exclude Standa Stepper Motor Library, to include it, please remove //
#define NO_HYDRA		// Exclude conflict in PicoQuant INCLUDE files, to use it, please remove // and resolve conflicts (not done)


#ifndef NO_STANDA 
	/*XYZ*/#include "USMCDLL.h" // STANDA STEPPER MOTOR LIBRARY
#endif

#ifndef NO_HYDRA 	  // for HYDRA
	#include "hhdefin.h"
#else				 // for other, e.g. TH260
	#include "th260defin.h" 
#endif

#include "hhlib.h"
#include "th260lib.h"
#include "errorcodes.h"

#include <windows.h>
#include "MercLib210.h" //PI Driver header file

#include "toolbox.h"
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
#include <cvinetv.h>
#include "measure.h"   
#include "trs.h" 
#include "mbc32.h" 
#include "scTDCmod.h"	 // it must be placed BEFORE spcm_def.h
#include "spcm_def.h"
#include "spc_isa_def.h"
#include "ximc2.h" // Standa2 driver re-saved as ximic2.h since the ximc.h had a truncated line
//#include "thlibc.h"
//#include "thdefin.h"
#include "W32nii3eMOD.h"
#include <NIDAQmx.h>

//#include <DAQmxIOctrl.h>


//#include "MAMM.h"


/* ########################   MEASURE PROCEDURES   ########################### */

//TaskHandle	taskmodpower=0;
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
			case APPL_MAMM: KernelGen(); break;
			case APPL_MOXY: KernelMoxy(); break;
			}
		CloseMeasure();
		CloseDataFile();
		UpdateTag();
		CloseMem();
		TextDisplay();
		
		
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
	
	SpcClose();
	CloseMem();
	CloseTime();
	SetActivePanel(hParm);
	}

/* MEASURE KERNEL */
void KernelGen(){
	int panel,control;
	long il;
	char is,isw,it;
	if(!P.Meas.SkipOscill) Oscilloscope();
	if(P.Command.Abort) return;
	for(is=0;is<MAX_STEP;is++)
		DefineHome(is);
	for(P.Loop[LOOP1].Idx=0;P.Loop[LOOP1].Idx<P.Loop[LOOP1].Num;P.Loop[LOOP1].Idx++){
		if(P.Command.Abort) break;
		for(P.Loop[LOOP2].Idx=0;P.Loop[LOOP2].Idx<P.Loop[LOOP2].Num;P.Loop[LOOP2].Idx++){
			if(P.Command.Abort) break;
			for(P.Loop[LOOP3].Idx=0;P.Loop[LOOP3].Idx<P.Loop[LOOP3].Num;P.Loop[LOOP3].Idx++){
				if(P.Command.Abort) break;
				for(P.Loop[LOOP4].Idx=0;P.Loop[LOOP4].Idx<P.Loop[LOOP4].Num;P.Loop[LOOP4].Idx++){
					if(P.Command.Abort) break;
					for(P.Loop[LOOP5].Idx=0;P.Loop[LOOP5].Idx<P.Loop[LOOP5].Num;P.Loop[LOOP5].Idx++){
						
						SetLoopActual();
						DecideAction();
						if(P.Action.ReadUIR) GetUserEvent (0, &panel, &control);
						if(P.Command.Abort) break;
						if(P.Action.DoJump) if(P.Jump.Break) break;
						/*patch*/
						if(P.Action.DoJumpMamm)	break;
						/**/
						if(P.Action.StartMamm) StartMammot(); //patch
						for(isw=0;isw<MAX_SWITCH;isw++)
				    		if(P.Action.MoveSwitch[isw]) MoveSwitch(CalcGoalSwitch(isw),isw);
						for(is=0;is<MAX_STEP;is++)
							if(P.Action.MoveStep[is])
							MoveStep(&P.Step[is].Actual,CalcGoal(is),is,(char)(P.Step[is].Mode!=STEP_MULTI),P.Action.Status);
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
						if(P.Action.StartAdc) {StartAdc(); P.Time.Start=clock();}		 // se è attivo ADC e power
			    		if(P.Action.StartSync) StartSync();
	                    if(P.Action.SpcReset) 
							SpcReset(P.Action.Status,P.Meas.Clear,P.Meas.Stop);
						/*patch*/
						/*if(P.Mamm.OverTresholdPrevious){
						    P.Mamm.OverTresholdPrevious=0;
							P.Spc.Trash=FALSE;
							int ib,id,ic,ifr;
							if(REMINDER(P.Loop[P.Mamm.Loop[Y]].Idx,2)){
							   P.Loop[P.Mamm.Loop[X]].Idx=P.Loop[P.Mamm.Loop[X]].Num-P.Frame.Actual;
							}
							else {
								P.Loop[P.Mamm.Loop[X]].Idx=P.Frame.Actual;
							}
							SpcRestart();
							
						}*/
						
						if(P.Action.AdjustIndex) AdjustIndex();
						if(P.Action.SpcRestart) SpcRestart();
					
						/**/
						for(is=0;is<MAX_STEP;is++)
							if(P.Action.StartCont[is])
								StartCont(is,P.Action.Status);
						if(P.Action.WaitEnd) WaitEnd(P.Spc.TimeM,P.Wait.Pos,P.Wait.Type,P.Wait.Step);
						if(P.Action.StopSync) StopSync();
						if(P.Action.SpcStop) SpcStop(P.Action.Status);
						if(P.Action.WaitAdc) {P.Time.Stop=clock();WaitAdc();}		 // se è attivo ADC e power
		    		    //if(P.Action.StopAdc) StopAdc();		 // mi da errore...Andrea F
						if(P.Action.StopOma) StopOma();
						if(P.Action.SpcOut) SpcOut(P.Action.Status);
						/**/// patch
                        if(P.Action.CheckMamm) CheckMammot(); 						
						/**/
						if(P.Action.DisplayPlot) DisplayPlot();
						if(P.Action.DisplayRoi) DisplayRoi();
						if(P.Action.DataSave) DataSave();
						for(is=0;is<MAX_STEP;is++)
							if(P.Action.WaitCont[is]) WaitCont(is,P.Action.Status);
						if(P.Action.CheckJump) CheckJump();
						//if(P.Action.StopMamm) StopMamm(); patch
						NewAcq();
						if(P.Mamm.Out) return;   //patch
						
						
	 					}
	 	    		}
	    		}
			}
		}

/*for(int temporaneo=0;temporaneo<timer;temporaneo++) 
			fprintf(fid2,"%.8f\t%.8f\t%.8f\n",now[temporaneo],now2[temporaneo],now2[temporaneo]-now[temporaneo]);
		fclose(fid2);   */ 
						
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
	DefineHome(step);
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
	CloseStep(step);
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
	/*patch*/
	int index=0;
	while(!P.Command.Continue && !P.Command.Abort){
		GetUserEvent (0, &panel, &control);
		SpcReset(status,P.Meas.Clear,P.Meas.Stop);
		WaitEnd(P.Spc.TimeO,0,wait_type,0);
		if(P.Meas.Stop) SpcStop(status);
		SpcOut(status);
		DisplayRoi();
		DisplayPlot();
	    index++;	
	}

	if(P.Contest.Run==CONTEST_MEAS)
		switch(P.Spc.Type){
			case SPC300:
			case SPC630:  
			case SPC130: 
			case HYDRA: 
			case TH260:
				SyncWait (P.Spc.TimeInit, SPC_TIMEDELAY); 
				break;
			default: break;
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
	int regionfile, idxloop;
	long il1 = P.Loop[LOOP1].Idx;
	long il2 = P.Loop[LOOP2].Idx;
	long il3 = P.Loop[LOOP3].Idx;
	long il4 = P.Loop[LOOP4].Idx;
	long il5 = P.Loop[LOOP5].Idx;
	long index=1+il5+il4*P.Loop[LOOP5].Num+il3*P.Loop[LOOP4].Num*P.Loop[LOOP5].Num+il2*P.Loop[LOOP3].Num*P.Loop[LOOP4].Num*P.Loop[LOOP5].Num+il1*P.Loop[LOOP2].Num*P.Loop[LOOP3].Num*P.Loop[LOOP4].Num*P.Loop[LOOP5].Num;
	int first5=(il5==0);
	int first4=(first5&&(il4==0));
	int first3=(first4&&(il3==0));
	int first2=(first3&&(il2==0));
	int first1=(first2&&(il1==0));
	int last5=(il5==(P.Loop[LOOP5].Num-1));
	int last4=(last5&&(il4==(P.Loop[LOOP4].Num-1)));
	int last3=(last4&&(il3==(P.Loop[LOOP3].Num-1)));
	int last2=(last3&&(il2==(P.Loop[LOOP2].Num-1)));
	int last1=(last2&&(il1==(P.Loop[LOOP1].Num-1)));
	int second5=(il5==1);
	int second4=(first5&&(il4==1));
	int second3=(first4&&(il3==1));
	int second2=(first3&&(il2==1));
	int second1=(first2&&(il1==1));
	int new5 = TRUE;
	int new4 = first5;
	int new3 = first4;
	int new2 = first3;
	int new1 = first2;
	int old5 = TRUE;
	int old4 = last5;
	int old3 = last4;
	int old2 = last3;
	int old1 = last2;
	int isw,is,it,il,ie;
	int first[MAX_LOOP],last[MAX_LOOP],second[MAX_LOOP],new[MAX_LOOP],old[MAX_LOOP];
	char action,isbreak;
	first[LOOP1]=first1; first[LOOP2]=first2; first[LOOP3]=first3; first[LOOP4]=first4; first[LOOP5]=first5;
	last[LOOP1]=last1; last[LOOP2]=last2; last[LOOP3]=last3; last[LOOP4]=last4; last[LOOP5]=last5;
	second[LOOP1]=second1; second[LOOP2]=second2; second[LOOP3]=second3; second[LOOP4]=second4; second[LOOP5]=second5;
	new[LOOP1]=new1; new[LOOP2]=new2; new[LOOP3]=new3; new[LOOP4]=new4; new[LOOP5]=new5;
	old[LOOP1]=old1; old[LOOP2]=old2; old[LOOP3]=old3; old[LOOP4]=old4; old[LOOP5]=old5;

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
				case CONT_RANGE: action=P.Loop[P.Step[is].Loop].Invert?first[P.Step[is].Loop-1]:first[P.Step[is].Loop]; break;
				//case CONT_RANGE: action=first[P.Step[is].Loop-1]; break;// action=(first[P.Step[is].Loop]&&first4) || ( P.Loop[3].Num==P.Loop[3].Actual); break;  
				}
		else action=FALSE;
  		P.Action.MoveStep[is]=(P.Step[is].Step&&action);
  		}
	
	// Adc
	P.Action.StartAdc=((P.Power.Power)&&P.Action.MoveStep[P.Power.Step]&&(P.Step[P.Power.Step].Type==13)&&(P.Step[P.Power.Step].Mode==2));
	P.Action.WaitAdc=((P.Power.Power)&&P.Action.MoveStep[P.Power.Step]&&(P.Step[P.Power.Step].Type==13)&&(P.Step[P.Power.Step].Mode==2));
		
   	// Wait Step
   	for(is=0;is<MAX_STEP;is++)
		P.Action.WaitStep[is]=(P.Action.MoveStep[is]&&(P.Step[is].Mode==STEP_MULTI));
		 
		
	// Start Cont 
   	for(is=0;is<MAX_STEP;is++){
   		if(P.Step[is].Step)
			switch (P.Loop[P.Step[is].Loop].Cont) {
				case CONT_NONE: action=FALSE; break;
				case CONT_STEP: action=new[P.Step[is].Loop]; break;
				//case CONT_RANGE: action=first[P.Step[is].Loop]; break; // note: wrong: the step must not start
				case CONT_RANGE: action=first[P.Step[is].Loop]; break; //action=first[P.Step[is].Loop-1]; break;
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
   	for(it=0;it<MAX_TRIM;it++){
   		if(!P.Trim[it].Trim) P.Action.Trim[it]=FALSE;
		else P.Action.Trim[it]=(new[P.Step[P.Trim[it].Step].Loop]&&P.Trim[it].Trim);
		if(P.Trim[it].Trim)
			if(P.Trim[it].FileTrim){
				idxloop=P.Loop[P.Step[P.Trim[it].Step].Loop].Idx;
				regionfile=P.Trim[it].RegionFile[idxloop];
    			if(regionfile==NEG) P.Action.Trim[it]=FALSE;
				}
		}

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
		P.Action.Break[LOOP4]=FALSE;
		P.Action.Break[LOOP5]=FALSE;
		}
	if(P.Action.Break[LOOP2]==TRUE){
		P.Action.Break[LOOP3]=FALSE;
		P.Action.Break[LOOP4]=FALSE;
		P.Action.Break[LOOP5]=FALSE;
		}
	if(P.Action.Break[LOOP3]==TRUE){
		P.Action.Break[LOOP4]=FALSE;
		P.Action.Break[LOOP5]=FALSE;
		}
	if(P.Action.Break[LOOP4]==TRUE){
		P.Action.Break[LOOP5]=FALSE;
		}

	// CheckJump
	if(P.Jump.Jump){
		P.Action.CheckJump=TRUE;
		P.Action.DoJump=TRUE;
		switch (P.Jump.Loop){
			case LOOP1: if(first1) P.Action.DoJump=FALSE; break;
			case LOOP2: if(first2) P.Action.DoJump=FALSE; break;
			case LOOP3: if(first3) P.Action.DoJump=FALSE; break;
			case LOOP4: if(first4) P.Action.DoJump=FALSE; break;
			case LOOP5: if(first5) P.Action.DoJump=FALSE; break;
			default: P.Action.DoJump=FALSE; break;
			}
		}
	else {
		P.Action.DoJump=FALSE;
		P.Action.CheckJump=FALSE;
		}

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
	
	// MAMMOT
	/**/ //patch
	P.Action.CheckEdge=P.Mamm.FindTop;
	if(P.Action.CheckEdge) {
	/*
	if(P.Mamm.OverTresholdPrevious) {
		P.Mamm.OverTresholdPrevious=0;
		P.Action.SpcRestart=1;
		P.Action.AdjustIndex=1;
		P.Action.SpcReset=0;}
	  else {P.Action.SpcRestart=0;P.Action.AdjustIndex=0;}
	if(P.Mamm.OverTreshold) P.Mamm.OverTresholdPrevious=1;
	P.Mamm.OverTreshold=0;
	*/
	P.Action.DoJumpMamm=(P.Mamm.OverTreshold||P.Mamm.IsTop);
	char is_before=(P.Loop[P.Mamm.Loop[X]].Idx<(int) (P.Loop[P.Mamm.Loop[X]].Num)/2);
	int margin_neg=(REMINDER(P.Loop[P.Mamm.Loop[Y]].Idx,2)?(P.Frame.Last-(15/P.Loop[P.Mamm.Loop[X]].Delta)):(P.Frame.Max-1-P.Frame.Last-(15/P.Loop[P.Mamm.Loop[X]].Delta)))<0;
	char is_near=(REMINDER(P.Loop[P.Mamm.Loop[Y]].Idx,2)?P.Loop[P.Mamm.Loop[X]].Idx>(P.Frame.Last-(15/P.Loop[P.Mamm.Loop[X]].Delta)):P.Loop[P.Mamm.Loop[X]].Idx>(P.Frame.Max-1-P.Frame.Last-(15/P.Loop[P.Mamm.Loop[X]].Delta)));
	//int margin_neg=(REMINDER(P.Loop[P.Mamm.Loop[Y]].Idx,2)?P.Frame.Last-15:(P.Frame.Max-1-P.Frame.Last-15))<0;
    //char is_near=(REMINDER(P.Loop[P.Mamm.Loop[Y]].Idx,2)?P.Loop[P.Mamm.Loop[X]].Idx>(P.Frame.Last-15):P.Loop[P.Mamm.Loop[X]].Idx>(P.Frame.Max-1-P.Frame.Last-15));
	/*???*/if(margin_neg) is_near=P.Loop[P.Mamm.Loop[X]].Idx>(P.Frame.Max)/2;/*is_near=(REMINDER(P.Loop[P.Mamm.Loop[Y]].Idx,2)?P.Loop[P.Mamm.Loop[X]].Idx>(P.Frame.Last-5):P.Loop[P.Mamm.Loop[X]].Idx>(P.Frame.Max-1-P.Frame.Last-5));*/					
	char is_within=is_near&&!is_before;
	P.Action.CheckMamm=is_within;
	P.Action.StartMamm=first[P.Mamm.Loop[Y]];
	
	if(P.Mamm.OverTresholdPrevious) {
		P.Mamm.OverTresholdPrevious=0;
		P.Action.SpcRestart=1;
		P.Action.AdjustIndex=1;
		P.Action.SpcReset=0;}
	  else {P.Action.SpcRestart=0;P.Action.AdjustIndex=0;}
	if(P.Mamm.OverTreshold) {P.Mamm.OverTresholdPrevious=1; P.Mamm.OverTreshold=0;}
	
	P.Action.DataSave=last[P.Mamm.Loop[X]]; // così si salva alla fine di ogni riga
	P.Action.MoveStep[P.Mamm.Step[X]]=first[P.Mamm.Loop[Y]]?0:P.Action.MoveStep[P.Mamm.Step[X]];
	}
	/**/
	P.Action.ReadUIR=P.Command.ReadUIR;
	if(P.Info.Appl==APPL_MAMM){
		for(il=0;il<MAX_LOOP;il++)
			if(P.Loop[il].Cont){
				P.Action.ReadUIR=(P.Action.ReadUIR && first[il]);
				P.Action.SpcReset=(P.Action.SpcReset && first[il]);
				}
		}
	}


/* RESTORE INITIAL CONDITIONS */
void CloseMeasure(void){
	char isw,is,it;
	P.Mamm.CloseMeas=1; //patch
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
	int  is,isw,il,it,ir,ips,ipp,nb,ib;
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
   					if (il==LOOP5) P.TPartition.LoopFactor[il]=P.TSequence.FrameTot;
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
   	
	// Jump
	P.Jump.Jump=(P.Jump.Loop!=LOOP_NONE);

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
		//case THARP:break;
		case SPC630:P.Spc.Calib=CALIB_SPC630;break;
		case SPC130:P.Spc.Calib=CALIB_SPC130;break;
		case HYDRA:break;
		case TH260:break;
		case TEST:P.Spc.Calib=TEST_CALIB;
		case DEMO:P.Spc.Calib=TEST_CALIB;
		default: break;
		}
	/* READ INI FROM UIR WITH NO DIR
	if (P.Spc.Type==SPC130) {
		if(P.Num.Board>0) MakePathname (DIR_INI, SPC130_1_INI_FILE, P.Spc.Settings[0]);
		if(P.Num.Board>1) MakePathname (DIR_INI, SPC130_2_INI_FILE, P.Spc.Settings[1]);
		if(P.Num.Board>2) MakePathname (DIR_INI, SPC130_3_INI_FILE, P.Spc.Settings[2]);
		if(P.Num.Board>3) MakePathname (DIR_INI, SPC130_4_INI_FILE, P.Spc.Settings[3]);
		}
	if (P.Spc.Type==TH260) {
		if(P.Num.Board>0) MakePathname (DIR_INI, TH260_1_INI_FILE, P.Spc.Settings[0]);
		if(P.Num.Board>1) MakePathname (DIR_INI, TH260_2_INI_FILE, P.Spc.Settings[1]);
		if(P.Num.Board>2) MakePathname (DIR_INI, TH260_3_INI_FILE, P.Spc.Settings[2]);
		if(P.Num.Board>3) MakePathname (DIR_INI, TH260_4_INI_FILE, P.Spc.Settings[3]);
		}
	if (P.Spc.Type==SPC300) MakePathname (DIR_INI, SPC300_INI_FILE, P.Spc.Settings[0]);
	if (P.Spc.Type==SPC630) MakePathname (DIR_INI, SPC630_INI_FILE, P.Spc.Settings[0]);
	//if (P.Spc.Type==THARP) MakePathname (DIR_INI, THARP_INI_FILE, P.Spc.Settings[0]);
	*/
	for(ib=0;ib<P.Num.Board;ib++) MakePathname (DIR_INI, P.Spc.IniFile[ib], P.Spc.Settings[ib]);
	
	if ((P.Spc.Type==SPC630)||(P.Spc.Type==SPC130))
		 P.Spc.Factor=P.Spc.Calib/P.Spc.Scale;
	else
		P.Spc.Factor = P.Spc.Calib*P.Spc.Scale; 
    
/*    if((P.Spc.Type==HYDRA)||(P.Spc.Type==TH260)){
		P.Chann.First=0;
		P.Chann.Last=1024*16-1;
		} */
	P.Chann.Num = P.Chann.Last-P.Chann.First+1;
	P.Spc.Started=FALSE;
	P.Spc.Trash=TRUE;
	if((P.Spc.Type==SPC300)||(P.Spc.Type==SPC630)||(P.Spc.Type==SPC130)||(P.Spc.Type==HYDRA)||(P.Spc.Type==TH260)) P.Meas.Stop=TRUE;
	if((P.Spc.Type==SPC300)||(P.Spc.Type==SPC630)||(P.Spc.Type==SPC130)||(P.Spc.Type==HYDRA)||(P.Spc.Type==TH260)||(P.Spc.Type==TEST)||(P.Spc.Type==DEMO)) P.Spc.Format=SPC_SHORT;
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
	P.Acq.Tot=P.Acq.Frame*(P.Loop[LOOP1].Num*P.Loop[LOOP2].Num*P.Loop[LOOP3].Num*P.Loop[LOOP4].Num*P.Loop[LOOP5].Num)/P.Num.LoopxFrame;
	P.Acq.Counter=0;
	P.Acq.Bank=SPC_BANK_DIM/(P.Chann.Num*P.Num.Det);

	
	// Ram
	if(P.Meas.Ram==0) P.Ram.Loop=P.Loop[LOOP1].Num*P.Loop[LOOP2].Num*P.Loop[LOOP3].Num*P.Loop[LOOP4].Num*P.Loop[LOOP5].Num;
	else P.Ram.Loop = MAX(P.Meas.Ram,P.Num.LoopxFrame);
	P.Ram.Num = (P.Loop[LOOP1].Num*P.Loop[LOOP2].Num*P.Loop[LOOP3].Num*P.Loop[LOOP4].Num*P.Loop[LOOP5].Num)/P.Ram.Loop;
	P.Ram.Actual=0;
	
	// Frame
	P.Frame.Num = CEIL(P.Ram.Loop,P.Num.LoopxFrame);
	if (P.Info.Appl==APPL_MAMM) P.Frame.Num = P.Loop[LOOP5].Num;
	//patch
	/*
	if(P.Mamm.FindTop) P.Frame.Num = P.Loop[P.Mamm.Loop[X]].Num;
	*/
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
    		sprintf(P.Trim[it].FPath,"%s\\%s%s",DIRFILETRIM,P.Trim[it].FName,EXTFILETRIM);
    		P.Trim[it].Trim=TRUE;
        	P.Trim[it].Loop=P.Step[P.Trim[it].Step].Loop;
        	P.Trim[it].Delta=(long)(P.Trim[it].DeltaU*P.Step[P.Trim[it].Step].Factor);
        	//P.Trim[it].Roi.First=P.Roi.First[P.Trim[it].Region];
       		//P.Trim[it].Roi.Last=P.Roi.Last[P.Trim[it].Region];
			P.Trim[it].FileTrim=(strlen(P.Trim[it].FName)>0);
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

/* CHECK JUMP */
void CheckJump(void){
	int il,ifr,ip,id,delta;
	unsigned long *DataZero;
	
	
	// check max area
	P.Jump.Area=0;
	for(ic=0;ic<P.Chann.Num;ic++) P.Jump.Area+=D.Buffer[P.Jump.Board][ic];
	if(P.Jump.Area<P.Jump.Max){ P.Jump.Break=FALSE; return;}
	
	// set flags
	P.Jump.Break=TRUE;
	
	// complete data save
	DataZero = calloc (P.Chann.Num, sizeof(unsigned long));
	//do{ P.File.File = fopen(P.File.Path, "ab"); }
	//while(P.File.File == NULL);
	switch (P.Jump.Loop){
		case LOOP1: delta=P.Loop[LOOP2].Num*P.Loop[LOOP3].Num*P.Loop[LOOP4].Num*P.Loop[LOOP5].Num; break;
		case LOOP2: delta=P.Loop[LOOP3].Num*P.Loop[LOOP4].Num*P.Loop[LOOP5].Num; break;
		case LOOP3: delta=P.Loop[LOOP4].Num*P.Loop[LOOP5].Num; break;
		case LOOP4: delta=P.Loop[LOOP5].Num; break;
		case LOOP5: delta=1; break;
		default: delta=0; break;
		}
	for(il=P.Loop[P.Jump.Loop].Actual+1;il<P.Loop[P.Jump.Loop].Num;il++)
		for(id=0;id<delta;id++)
			for(ifr=0;ifr<P.Frame.Num;ifr++)
				for(ip=0;ip<P.Num.Page;ip++){
					if(P.Info.SubHeader) while(fwrite (&D.Sub[ifr][ip], sizeof(T_SUB), 1, P.File.File)<1);
					while(fwrite(DataZero,sizeof(T_DATA),P.Chann.Num,P.File.File)<P.Chann.Num);
					}
	fflush(P.File.File);
	//fclose(P.File.File);
	free(DataZero);
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
	PresentationFile = fopen ("C:\Program Files (x86)\TRS 14.2 - Copy\prova.txt", "w");
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
	int ir,loop1,loop2,loop3,loop4,loop5,loop_steps;
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
	//sub->TimeEff = (double) P.Page[Page].TimeEff;
	sub->TimeEff = (double) (P.Time.Stop-P.Time.Start)/CLOCKS_PER_SEC;
	sub->n = (double) Pad[sub->Pad].Nn;
	loop_steps=Ram*P.Frame.Num+Frame;
	CalcLoopIndex(loop_steps,&loop1,&loop2,&loop3,&loop4,&loop5);
	sub->Loop[LOOP3-2] = (long) loop3;  // NOTE -2 is to keep consistency with 3 LOOP file format for FIT
	sub->Loop[LOOP4-2] = (long) loop4;
	sub->Loop[LOOP5-2] = (long) loop5;
	sub->Acq = (long) P.Page[Page].Acq;
	sub->Page = (long) Page;
	for(ir=0;ir<MAX_ROW_ROI;ir++)
		if((P.Roi.Page[ir]==Page)&&(num_roi<MAX_ROI_SUB)){
			sub->RoiFirst[num_roi] = (short) P.Roi.First[ir];
			sub->RoiLast[num_roi] = (short) P.Roi.Last[ir];
			//sub->RoiLast[num_roi] = (short) P.Step[0].Actual;
			//sub->RoiLambda[num_roi] = (double) (P.Oma.Oma?P.Oma.Baric:P.Roi.Lambda[ir]);
			sub->RoiLambda[num_roi] = (double) InsertMicroPos(Frame,Page,ir);
			sub->RoiPower[num_roi] = (double) CalcPower(Frame, Page, ir);
			num_roi++;
			}
	sub->RoiNum = (char) num_roi;
	}

// CALC POWER
double CalcPower(long Frame, long Page, int Roi){
	double power=0;
	int ic;

	if(P.Oma.Oma) power = P.Oma.Peak;
	//if(P.Power.Power) power = P.Step[P.Power.Step].Actual/FPM_CALIB_FACT;
	if(P.Power.Power) power = (double) (-1.0*P.Step[P.Power.Step].Actual_mean_pow)/ADC_FACTOR;
	if(P.Info.Appl == APPL_MAMM) 
		for(ic=P.Roi.First[Roi]; ic<=P.Roi.Last[Roi]; ic++)
			power += D.Data[Frame][Page][ic];

	return(power);
	}

 // CALC STDEV
double CalcStdev(long Frame, long Page, int Roi){
	double stdev=0;

    stdev = (double) (1.0*P.Step[P.Power.Step].Actual_std)/ADC_FACTOR;

	return(stdev);
	}

// INSERT POSITION OF MICRO
double InsertMicroPos(long Frame, long Page, int Roi){
	double pos=0;
	int count = 0,is=0;
	for(is=0;is<MAX_STEP;is++)
		if((P.Step[is].Step)&&((P.Step[is].Type==MICRO)||(P.Step[is].Type==MICRO2))&&(count==0)){
			pos=P.Step[is].Actual;
            count = count + 1;
			}
	return(pos);
	}
// CALC LOOP INDEX
void CalcLoopIndex(long Steps,long *Loop1,long *Loop2,long *Loop3,long *Loop4,long *Loop5){
	*Loop1=(long) Steps/(P.Loop[LOOP2].Num*P.Loop[LOOP3].Num*P.Loop[LOOP4].Num*P.Loop[LOOP5].Num);
	Steps-=*Loop1*P.Loop[LOOP2].Num*P.Loop[LOOP3].Num*P.Loop[LOOP4].Num*P.Loop[LOOP5].Num;
	*Loop2=(long) Steps/(P.Loop[LOOP3].Num*P.Loop[LOOP4].Num*P.Loop[LOOP5].Num);
	Steps-=*Loop2*P.Loop[LOOP3].Num*P.Loop[LOOP4].Num*P.Loop[LOOP5].Num;
	*Loop3=(long) Steps/(P.Loop[LOOP4].Num*P.Loop[LOOP5].Num);
	Steps-=*Loop3*P.Loop[LOOP4].Num*P.Loop[LOOP5].Num;
	*Loop4=(long) Steps/P.Loop[LOOP5].Num;
	Steps-=*Loop4*P.Loop[LOOP5].Num;
	*Loop5=(long) Steps;
	}


/* ########################   DISPLAY PROCEDURES   ########################### */

/* TEXT OUTPUT */	
void TextDisplay(void){
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
	for(is=0;is<MAX_STEP-1;is++)
		SetTableCellAttribute (hDisplay,DISPLAY_T_TRIS,MakePoint(COL_TRIS_STEP,is+1),ATTR_CTRL_VAL,0.0);
	for(iw=0;iw<MAX_SWITCH;iw++)
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
		//	SetTableCellAttribute (hDisplay,DISPLAY_T_TRIS,MakePoint(COL_TRIS_STEP,is+1),ATTR_CTRL_VAL,(P.Step[is].Actual/(1.0*P.Step[is].Factor)));
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
			P.Spc.CountRate=area;   /*patch*/
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
	if(is_meas?P.Roi.RoiM[P.Value.Roi+1]:P.Roi.RoiO[P.Value.Roi+1]){
		SetTableCellAttribute (hDisplay,DISPLAY_T_VALUE,MakePoint(COL_VALUE_AREA,1),ATTR_CTRL_VAL,P.Roi.Area[P.Value.Roi+1]);
		SetTableCellAttribute (hDisplay,DISPLAY_T_VALUE,MakePoint(COL_VALUE_WIDTH,1),ATTR_CTRL_VAL,P.Roi.Width[P.Value.Roi+1]);
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
	char first = (P.Loop[LOOP1].Idx==0)&&(P.Loop[LOOP2].Idx==0)&&(P.Loop[LOOP3].Idx==0)&&(P.Loop[LOOP4].Idx==0)&&(P.Loop[LOOP5].Idx==0);
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
//THARP		case THARP: InitTimeharp();break;
		case SPC630:  
		case SPC130: for(ib=0;ib<P.Num.Board;ib++) InitSpcm(ib);break;
		case HYDRA: for(ib=0;ib<P.Num.Board;ib++) InitHydra(ib);break;
		case TH260: for(ib=0;ib<P.Num.Board;ib++) InitTH260(ib);break;
		case SPC_SC1000: for(ib=0;ib<P.Num.Board;ib++) InitSC1000(ib);break;
		case SPC_SPADLAB: for(ib=0;ib<P.Num.Board;ib++) InitSpad(ib);break;
		case TEST: break;
		case DEMO: InitDemo(); break;
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
//THARP		case THARP: break;
		case SPC630:  
		case SPC130: CloseSpcm(); break;
		case HYDRA: CloseHydra(); break;
		case TH260: CloseTH260(); break;
		case SPC_SC1000: CloseSC1000(); break;
		case SPC_SPADLAB: CloseSpad(); break;
		case TEST: break;
		case DEMO: CloseDemo(); break;
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
//THARP		case THARP: TH_StopMeas(); break;  //TODO check
		case SPC630:  
		case SPC130: for(ib=0;ib<P.Num.Board;ib++) SPC_pause_measurement(ib); break;
		case HYDRA: HH_StopMeas(HYDRA_DEV0); break;
		case TH260: TH260_StopMeas(TH260_DEV0); break;
		case SPC_SC1000: for(ib=0;ib<P.Num.Board;ib++) sc_tdc_interrupt2(P.Spc.ScBoard[ib]); break;
		case SPC_SPADLAB: for(ib=0;ib<P.Num.Board;ib++) PauseSpad(ib); break;
		case TEST: break;
		case DEMO: break;
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
//THARP		case THARP: TH_ClearHistMem(); break;
		case SPC630:
		case SPC130: ClearSpcm(); break;
		case HYDRA: ClearHydra(); break;
		case TH260: ClearTH260(); break;
		case SPC_SPADLAB: ClearSpad(); break;
		case SPC_SC1000: if(P.Spc.Trash) ClearSC1000(); break; /*patch*/
		case TEST: break;
		case DEMO: break;
		}
	P.Spc.Zero=TimerN();
	P.Spc.Trash=FALSE;
}


/* DATA IN */
void SpcIn(){
	int ib;
	int ret;
	switch(P.Spc.Type){
		case NONE:  break;  
		case VARRO: CharCommVarro('a'); break;
	//	case SILENA: DataInSilena(); break;
		case SPC300: SPCI_start_measurement(); break;
//THARP		case THARP: TH_StartMeas(); break;
		case SPC630: 
		case SPC130: for(ib=0;ib<P.Num.Board;ib++) SPC_start_measurement(ib); break;
		case HYDRA: HH_StartMeas(HYDRA_DEV0,P.Spc.TimeHydra); break;
		case TH260: TH260_StartMeas(TH260_DEV0,P.Spc.TimeTH260); break;
		case SPC_SC1000: for(ib=0;ib<P.Num.Board;ib++){} break;
		case SPC_SPADLAB: for(ib=0;ib<P.Num.Board;ib++) StartSpad(ib); break;
		case TEST: break;
		case DEMO: break;
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
//THARP		case THARP: TH_StartMeas(); break;
		case SPC630: 
		case SPC130: for(ib=0;ib<P.Num.Board;ib++) SPC_restart_measurement(ib); break;
		case HYDRA: HH_StartMeas(HYDRA_DEV0,P.Spc.TimeHydra); break;
		case TH260: TH260_StartMeas(TH260_DEV0,P.Spc.TimeHydra); break;
		case SPC_SC1000: for(ib=0;ib<P.Num.Board;ib++){ sc_tdc_start_measure2(P.Spc.ScBoard[ib],SC1000_TIME_INFINITY);} break;
		case SPC_SPADLAB: for(ib=0;ib<P.Num.Board;ib++) StartSpad(ib); break;
		case TEST: break;
		case DEMO: break;
		}
	}


/* OPTIMIZED DATA CLEAR & DATA IN */
void SpcReset(char Status, char Clear, char Stop){
	if(Clear) SpcClear();
	if(P.Spc.Trash) SpcOut(FALSE);
	//if(P.Spc.Type==SPC_SC1000) ClearSC1000(); 
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
//THARP		case THARP: TH_SetMMode(0,1000*Time); break;
		case SPC630: 
		case SPC130: for(ib=0;ib<P.Num.Board;ib++) SPC_set_parameter(ib,COLLECT_TIME,Time); break;
		case HYDRA: P.Spc.TimeHydra = (int) (Time*SEC_2_MILLISEC); break;
		case TH260: P.Spc.TimeTH260 = (int) (Time*SEC_2_MILLISEC); break;
		case SPC_SC1000: P.Spc.TimeSC1000 = (int) (Time*SEC_2_MILLISEC); break;
		case SPC_SPADLAB: for(ib=0;ib<P.Num.Board;ib++) TimeSpad(ib,Time); break;
		case TEST: break;
		case DEMO: break;
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
//THARP		case THARP: TH_StopMeas();break;
		case SPC630:
		case SPC130: for(ib=0;ib<P.Num.Board;ib++) SPC_stop_measurement(ib);break;
		case HYDRA: HH_StopMeas(HYDRA_DEV0); break;
		case TH260: TH260_StopMeas(TH260_DEV0); break;
		case SPC_SC1000: break;//if(P.Contest.Function = CONTEST_MEAS); for(ib=0;ib<P.Num.Board;ib++) StopSC1000(ib); break;	 /*patch*/
		case SPC_SPADLAB: for(ib=0;ib<P.Num.Board;ib++) StopSpad(ib);break;
		case TEST: break;
		case DEMO: break;
		}
	CalcTime();
	if(Status) SetCtrlVal (hDisplay, DISPLAY_MEASURE, OFF);
	P.Spc.Started=FALSE;
	}


/* WAIT SPC */
void SpcWait(void){
	short mod_state;
	int mod_state2;
	int ib;
    unsigned char statusmeas;
	switch(P.Spc.Type){
		case NONE:  break;  
		case VARRO: while(CheckAcqVarro()); break;  // check !
	//	case SILENA: do _GetMeasInfo(&realtime,&livetime,&deadtime,&statusmeas);
					 while(statusmeas != SILENA_TIMESTOP); break;
		case SPC300: do SPCI_test_state(&mod_state);
					 while((mod_state & SPC_ARMED) != 0);break;
//THARP		case THARP: while(TH_CTCStatus()==0);
//THARP					TH_StopMeas();break; 
		case SPC630:   
		case SPC130: for(ib=0;ib<P.Num.Board;ib++)
    					do SPC_test_state(ib,&mod_state);
						while((mod_state & SPC_ARMED) != 0);break;
		case HYDRA: for(ib=0;ib<P.Num.Board;ib++)
    					do HH_CTCStatus(HYDRA_DEV0,&mod_state2);
						while(mod_state2==0);break;
		case TH260: for(ib=0;ib<P.Num.Board;ib++)
    					do TH260_CTCStatus(TH260_DEV0,&mod_state2);
						while(mod_state2==0);break;
		case SPC_SC1000: break;
/*		case SPC_SC1000: for(ib=0;ib<P.Num.Board;ib++)
    					do  sc_tdc_get_status2(P.Spc.ScBoard[ib],&mod_state2);
						while(mod_state2==0);break; */
 		case SPC_SPADLAB: for(ib=0;ib<P.Num.Board;ib++) WaitSpad(ib); break;
		case DEMO:
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
//THARP		case THARP: GetDataTimeharp();break; 
		case SPC630:   
		case SPC130: GetDataSpcm();break;
		case HYDRA: GetDataHydra();break;
		case TH260: GetDataTH260();break;
		case SPC_SC1000: GetDataSC1000();break;
		case SPC_SPADLAB: GetDataSpad();break;
		case TEST:  GetDataTest();break;
		case DEMO:  GetDataDemo();break;
		}
	}


/* DATA OUT AND PRE-PROCESSING */
void SpcOut(char Status){
	if(P.Spc.Started) CalcTime();
	SpcGet();
	//if(!P.Action.StartMamm) DataCopy(); // patch
	DataCopy(); //original
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
	double elapsed_time;
	switch (P.Spc.Type){
		case SPC130:
			for(ib=0;ib<P.Num.Board;ib++){
				SPC_test_state(ib,&state);
				SPC_get_actual_coltime(ib, &rem_time);
				SPC_get_parameter(ib, COLLECT_TIME, &meas_time);
				P.Spc.EffTime[ib] = meas_time - rem_time;
				now=TimerN();
			P.Spc.EffTime[0]=now-P.Spc.Zero;
			/*FILE *fid2;
			fid2=fopen("tempo acquisizione.txt","a+");
			fprintf(fid2,"%.8f\t%.8f\t%.8f\n",P.Spc.Zero,now,P.Spc.EffTime[0]);
			fclose(fid2);*/
			P.Spc.Zero=now;
				}
			break;
		case HYDRA:
			HH_GetElapsedMeasTime(HYDRA_DEV0,&elapsed_time);
			for(ib=0;ib<P.Num.Board;ib++) P.Spc.EffTime[ib] = elapsed_time;
			break;
		case TH260:
			TH260_GetElapsedMeasTime(TH260_DEV0,&elapsed_time);
			for(ib=0;ib<P.Num.Board;ib++) P.Spc.EffTime[ib] = elapsed_time;
			break;
		default:
			now=TimerN();
			P.Spc.EffTime[0]=now-P.Spc.Zero;
			P.Spc.Zero=now;
			break;
		}
	//if((P.Spc.Type!=HYDRA)&&(P.Spc.Type!=HYDRA)){
	//	now=TimerN();
	//	P.Spc.EffTime[0]=now-P.Spc.Zero;
	//	P.Spc.Zero=now;
	//	}
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
		
		if(P.Action.CheckEdge){  //patch
		char loopx=P.Mamm.Loop[X];
		char loopy=P.Mamm.Loop[Y];
		if(P.Mamm.OverTreshold||P.Loop[loopx].Idx==P.Loop[loopx].Num-1){ 
		P.Frame.Actual=P.Frame.Actual;
		//P.Frame.Last=P.Frame.Actual; se lo metto non funziona bene 
		}
  			else if((P.Loop[loopx].Invert)&&(REMINDER(P.Loop[loopy].Idx,2)))
			      P.Frame.Actual--;
   		    else P.Frame.Actual++;
		}
			
			
		else P.Frame.Actual++;
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
	char line[STRLEN+1];
	char label[STRLEN];

	FILE *hFile;
	
	sprintf (message, "Initializing SPCM, Module #%d, ...", Board);
	SetCtrlVal (hDisplay, DISPLAY_MESSAGE, message); 
	
	init=SPC_get_init_status(Board);
	if(init!=INIT_OK){
		ret=SPC_init(P.Spc.Settings[Board]);
		if((ret<0)&&(ret!=SPC_IN_USE)) ErrHandler(ERR_SPC,ret,"SPC_Init");
		P.Spc.TimeInit=TimerN();   // era Timer() 
		init=SPC_get_init_status(Board);
		}
#ifdef INIT_MOD_IN_USE
	if((init!=INIT_OK)&&(init!=INIT_MOD_IN_USE)) ErrHandler(ERR_SPC,0,"SPC_get_init_status");
	if(init==INIT_MOD_IN_USE){
#endif
#ifdef INIT_SPC_MOD_IN_USE
	if((init!=INIT_OK)&&(init!=INIT_SPC_MOD_IN_USE)) ErrHandler(ERR_SPC,0,"SPC_get_init_status");
	if(init==INIT_SPC_MOD_IN_USE){
#endif
		ret=SPC_read_parameters_from_inifile(&spc_data,P.Spc.Settings[Board]);
		if(ret<0) ErrHandler(ERR_SPC,ret,"SPC_read_parameters_from_inifile");
		ret=SPC_set_parameters(Board,&spc_data);
		if(ret<0) ErrHandler(ERR_SPC,ret,"SPC_set_parameters");
		}
	
	// load specific parameters of INI FILES
	hFile = fopen (P.Spc.Settings[Board], "r");				 //opens file
	ret=SPC_get_parameters(Board,&spc_data);
	if(ret<0) ErrHandler(ERR_SPC,ret,"SPC_get_parameters");
	while (fgets(line, STRLEN, hFile) != NULL ){
		sscanf(line,"%s", label);	
		if (!strcmp(label,LABEL_CFD_LIMIT_LOW)) sscanf(line, "%*s%*c%*c%*c%f",&spc_data.cfd_limit_low);
		else if (!strcmp(label,LABEL_CFD_ZC_LEVEL)) sscanf(line, "%*s%*c%*c%*c%f",&spc_data.cfd_zc_level);
		else if (!strcmp(label,LABEL_TAC_GAIN)) sscanf(line, "%*s%*c%*c%*c%hd",&spc_data.tac_gain);
		else if (!strcmp(label,LABEL_TAC_OFFSET)) sscanf(line, "%*s%*c%*c%*c%f",&spc_data.tac_offset);
		else if (!strcmp(label,LABEL_TAC_LIMIT_LOW)) sscanf(line, "%*s%*c%*c%*c%f",&spc_data.tac_limit_low);
		else if (!strcmp(label,LABEL_TAC_LIMIT_HIGH)) sscanf(line, "%*s%*c%*c%*c%f",&spc_data.tac_limit_high);
		}
	fclose(hFile);
	ret=SPC_set_parameters(Board,&spc_data);
	if(ret<0) ErrHandler(ERR_SPC,ret,"Read_additional_SPC_set_parameters");

	
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
	

/* ########################   HYDRA HARP FUNCTIONS (Hydra)  ####################### */

/* INIT HYDRA */	
void InitHydra(int Board){
	char message[STRLEN];
	int ret;
	int HistLen;
	char HW_Serial[8];
	double resolution;
	int binsteps;
	
	sprintf (message, "Initializing HydraHarp, Module #%d, ...", Board);
	SetCtrlVal (hDisplay, DISPLAY_MESSAGE, message); 
	
	
	// initialize
	if(Board==0){
		ret=HH_OpenDevice(HYDRA_DEV0,HW_Serial); // Check for Serial Number of Device = 0 (NOTE: Many HydraHarp Devices can be controlled)
		if(ret<0) ErrHandler(ERR_HYDRA,ret,"HH_OpenDevice");
		else{
			sprintf (message, "...Serial Number = %s", HW_Serial); 
			SetCtrlVal (hDisplay, DISPLAY_MESSAGE, message);  
			}
		ret=HH_Initialize(HYDRA_DEV0,MODE_HIST,0); if(ret<0) ErrHandler(ERR_HYDRA,ret,"HH_Initialize");
		ret=HH_Calibrate(HYDRA_DEV0); if(ret<0) ErrHandler(ERR_HYDRA,ret,"HH_Calibrate");
		}

	// set ini parameters
	ret=HH_SetSyncDiv(HYDRA_DEV0,HYDRA_SYNC_DIVIDER); if(ret<0) ErrHandler(ERR_HYDRA,ret,"HH_SetSyncDiv");
	ret=HH_SetSyncCFDLevel(HYDRA_DEV0,HYDRA_SYNC_CFDLEVEL); if(ret<0) ErrHandler(ERR_HYDRA,ret,"HH_SetSyncCFDLevel");
	ret=HH_SetSyncCFDZeroCross(HYDRA_DEV0,HYDRA_SYNC_CFDZEROCROSS); if(ret<0) ErrHandler(ERR_HYDRA,ret,"HH_SetSyncCFDZeroCross");
	ret=HH_SetSyncChannelOffset(HYDRA_DEV0,HYDRA_SYNC_OFFSET); if(ret<0) ErrHandler(ERR_HYDRA,ret,"HH_SetSyncChannelOffset");
	ret=HH_SetInputCFDLevel(HYDRA_DEV0,Board,HYDRA_INPUT_CFDLEVEL); if(ret<0) ErrHandler(ERR_HYDRA,ret,"HH_SetInputCFDLevel");
	ret=HH_SetInputCFDZeroCross(HYDRA_DEV0,Board,HYDRA_INPUT_CFDZEROCROSS); if(ret<0) ErrHandler(ERR_HYDRA,ret,"HH_SetInputCFDZeroCross");
	ret=HH_SetInputChannelOffset(HYDRA_DEV0,Board,HYDRA_INPUT_OFFSET); if(ret<0) ErrHandler(ERR_HYDRA,ret,"HH_SetInputChannelOffset");
	ret=HH_SetInputCFDZeroCross(HYDRA_DEV0,Board,HYDRA_INPUT_CFDZEROCROSS); if(ret<0) ErrHandler(ERR_HYDRA,ret,"HH_SetInputCFDZeroCross");
	ret=HH_SetBinning(HYDRA_DEV0,HYDRA_BINNING); if(ret<0) ErrHandler(ERR_HYDRA,ret,"HH_SetBinning");
//	ret=HH_SetOffset(HYDRA_DEV0,HYDRA_OFFSET); if(ret<0) ErrHandler(ERR_HYDRA,ret,"HH_SetOffset");
	ret=HH_SetHistoLen(HYDRA_DEV0,HYDRA_LENCODE,&HistLen); if(ret<0) ErrHandler(ERR_HYDRA,ret,"HH_SetHistoLen");

	// get temporal scale
	HH_GetBaseResolution (HYDRA_DEV0, &resolution, &binsteps);
	P.Spc.Calib = 1000*resolution;
   P.Spc.Factor = P.Spc.Calib*P.Spc.Scale;

	
	P.Spc.TimeInit=TimerN();   // era Timer() 

	Passed();
	} 


/* CLOSE HYDRA */	
void CloseHydra(void){
	short ret;
	ret=HH_CloseDevice(HYDRA_DEV0);
	} 


/* TRANSFER DATA FROM HYDRA */	
void GetDataHydra(void){
	//short state;
	int ib;
	int ic;
	unsigned int DataHydra[1024*16];
	int ret=0;

	P.Spc.Overflow=FALSE;
	for(ib=0;ib<P.Num.Board;ib++){
		ret=HH_GetHistogram(HYDRA_DEV0,DataHydra,ib,0); if(ret<0) ErrHandler(ERR_HYDRA,ret,"HH_GetHistogram");
		for(ic=0;ic<P.Chann.Num;ic++) D.Buffer[ib][ic] = (unsigned short) DataHydra[ic]; 
		}
	}


/* CLEAR HYDRA */	
void ClearHydra(void){
	short ret;
	int HistLen;
	int i_trial=0;
	do{
		ret=HH_ClearHistMem(HYDRA_DEV0); 
		if(ret<0){
			i_trial++;
			ret=HH_SetHistoLen(HYDRA_DEV0,HYDRA_LENCODE,&HistLen); if(ret<0) ErrHandler(ERR_HYDRA,ret,"HH_SetHistoLen");
			}
		}
	while((ret<0)&&(i_trial<10));
	if(ret<0) ErrHandler(ERR_HYDRA,ret,"HH_ClearHistMem");
	}


/* ########################   TIMEHARP260 FUNCTIONS (TH260)  ####################### */

/* INIT TH260 */	
void InitTH260(int Board){
	char message[STRLEN];
	int ret;
	char HW_Serial[8];
	double resolution;
	int binsteps;
	int sync_divider, sync_cdflevel, sync_cdfzerocross, sync_offset, input_cdflevel, input_cdfzerocross, input_offset, binning;
	char line[STRLEN];
	FILE *pfile;
	
	
	sprintf (message, "Initializing TH260Harp, Module #%d, ...", Board);
	SetCtrlVal (hDisplay, DISPLAY_MESSAGE, message); 
	
	// read settings
	pfile = fopen (P.Spc.Settings[Board], "r");
	if(pfile==NULL) {Failure("Error Initializing TH260: cannot find IniFile for settings"); return;}
	fgets(line,STRLEN,pfile); // First Line TITLE
	fgets(line,STRLEN,pfile); // Second Line WARNINGS
	fgets(line,STRLEN,pfile); sscanf(line,"%d",&sync_divider);
	fgets(line,STRLEN,pfile); sscanf(line,"%d",&sync_cdflevel);
	fgets(line,STRLEN,pfile); sscanf(line,"%d",&sync_cdfzerocross);
	fgets(line,STRLEN,pfile); sscanf(line,"%d",&sync_offset);
	fgets(line,STRLEN,pfile); sscanf(line,"%d",&input_cdflevel);
	fgets(line,STRLEN,pfile); sscanf(line,"%d",&input_cdfzerocross);
	fgets(line,STRLEN,pfile); sscanf(line,"%d",&input_offset);
	fgets(line,STRLEN,pfile); sscanf(line,"%d",&binning);
	fclose(pfile);

	// initialize
	if(Board==0){
		ret=TH260_OpenDevice(TH260_DEV0,HW_Serial); // Check for Serial Number of Device = 0 (NOTE: Many TH260Harp Devices can be controlled)
		if(ret<0) ErrHandler(ERR_TH260,ret,"TH260_OpenDevice");
		else{
			sprintf (message, "...Serial Number = %s", HW_Serial); 
			SetCtrlVal (hDisplay, DISPLAY_MESSAGE, message);  
			}
		ret=TH260_Initialize(TH260_DEV0,MODE_HIST); if(ret<0) ErrHandler(ERR_TH260,ret,"TH260_Initialize");
		}

	// set ini parameters
	ret=TH260_SetSyncDiv(TH260_DEV0,sync_divider); if(ret<0) ErrHandler(ERR_TH260,ret,"TH260_SetSyncDiv");
	ret=TH260_SetSyncCFD(TH260_DEV0,sync_cdflevel,sync_cdfzerocross); if(ret<0) ErrHandler(ERR_TH260,ret,"TH260_SetSyncCFD");
	ret=TH260_SetSyncChannelOffset(TH260_DEV0,sync_offset); if(ret<0) ErrHandler(ERR_TH260,ret,"TH260_SetSyncChannelOffset");
	ret=TH260_SetInputCFD(TH260_DEV0,Board,input_cdflevel,input_cdfzerocross); if(ret<0) ErrHandler(ERR_TH260,ret,"TH260_SetInputCFD");
	ret=TH260_SetInputChannelOffset(TH260_DEV0,Board,input_offset); if(ret<0) ErrHandler(ERR_TH260,ret,"TH260_SetInputChannelOffset");
	ret=TH260_SetBinning(TH260_DEV0,binning); if(ret<0) ErrHandler(ERR_TH260,ret,"TH260_SetBinning");
	ret=TH260_SetHistoLen(TH260_DEV0,MAXLENCODE,&P.Spc.TH260HistLen); if(ret<0) ErrHandler(ERR_TH260,ret,"TH260_SetHistoLen");

	// get temporal scale
	TH260_GetBaseResolution (TH260_DEV0, &resolution, &binsteps);
	P.Spc.Calib = resolution;
    P.Spc.Factor = P.Spc.Calib;

	P.Spc.TimeInit=TimerN();   // era Timer() 

	Passed();
	} 


/* CLOSE TH260 */	
void CloseTH260(void){
	short ret;
	ret=TH260_CloseDevice(TH260_DEV0);
	} 


/* TRANSFER DATA FROM TH260 */	
void GetDataTH260(void){
	//short state;
	int ib;
	int ic;
	unsigned int *DataTH260;
	int ret=0;
	DataTH260=calloc(P.Spc.TH260HistLen,sizeof(*DataTH260));

	P.Spc.Overflow=FALSE;
	for(ib=0;ib<P.Num.Board;ib++){
		ret=TH260_GetHistogram(TH260_DEV0,DataTH260,ib,0); if(ret<0) ErrHandler(ERR_TH260,ret,"TH260_GetHistogram");
		for(ic=0;ic<P.Chann.Num;ic++) D.Buffer[ib][ic] = (unsigned short) DataTH260[ic]; 
		}
	}

void patch2(int ret){
	//ErrHandler(ERR_SC1000,ret,"SC1000 error in getting binsize (factor)");
	for(ret=0;ret<10000;ret++);
}
/* CLEAR TH260 */	
void ClearTH260(void){
	short ret;
	int HistLen;
	int i_trial=0;
	do{
		ret=TH260_ClearHistMem(TH260_DEV0); 
		if(ret<0){
			i_trial++;
			ret=TH260_SetHistoLen(TH260_DEV0,TH260_LENCODE,&HistLen); if(ret<0) ErrHandler(ERR_TH260,ret,"TH260_SetHistoLen");
			}
		}
	while((ret<0)&&(i_trial<10));
	if(ret<0) ErrHandler(ERR_TH260,ret,"TH260_ClearHistMem");
	}


/* ########################   SURFACE CONCEPTS TDC FUNCTIONS (SC1000)  ####################### */

/* INIT SC1000 */	
void InitSC1000(int Board){
	//CVIProfSetCurrentThreadProfiling(1);	/*patch*/
	int ret,id;
	char message[STRLEN];
	char root_DCR_name[STRLEN];
	int linearise=(SC1000_LINEARISE&&(SC1000_REFOLDTYPE!=SC1000_HARDREFOLD));
	
/***PATCH***/	
	Period = (double) (1/10e6)*1e12;
//	Period = (double) (1/40e6)*1e12;
	Modulo = SC1000_MODULO;
	//strcpy(DCR_files[0][0],"BKG_10MHZ_12h_ch0.txt");
	//strcpy(DCR_files[0][0],"BKG_40MHZ_12h_ch0.txt");  	
 //   strcpy(root_DCR_name,"TDC\\OLDTDC\\dark_10MHz_ch");  	//oldtdc
	strcpy(root_DCR_name,"TDC\\NEWTDC\\dark_10MHz_ch");  	//newtdc    
	for(id=0;id<P.Num.Det;id++) sprintf(DCR_files[Board][id],"%s%d.txt",root_DCR_name,id);
/*******/	
	
	
	sprintf (message, "Initializing SC1000, Module #%d\nPlease check TDC programme is running and communication with TRS started ...", Board);
	SetCtrlVal (hDisplay, DISPLAY_MESSAGE, message); 
	
	// read settings
	ret = sc_tdc_init_inifile(P.Spc.Settings[Board]);
	//ret = sc_tdc_init_inifile("tdc_gpx3.ini");
	if (ret < 0) {ErrHandler(ERR_SC1000,ret,"Error initializing SC board"); return;}
	else {P.Spc.ScBoard[Board]=ret; 
	sprintf (message, "\nCommunication set\n");
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE, message);
		 }
	ret = sc_tdc_get_binsize2(P.Spc.ScBoard[Board], &Binsize);
	if(SC1000_REFOLDTYPE==SC1000_HARDREFOLD){
		P.Spc.Calib=ns2ps*Binsize;
		CompleteParmS();
		UpdatePanel();
		}
	if (ret < 0) {ErrHandler(ERR_SC1000,ret,"SC1000 error in getting binsize factor"); return;}
    /*FILE *fid;
	fid=fopen("pipe.txt","w+"); 
	fclose(fid);
	fid=fopen("pipe.txt","a+"); */ //patch
	// initialize pipe
	for(id=0;id<P.Num.Det;id++){
		struct sc_pipe_tdc_histo_params_t params;
		params.depth = SC1000_BINDEPTH; // 32 bit per time channel (bin) in the histogram
		params.channel = id; // pipe for channel #id is requested
		params.modulo = ((SC1000_REFOLDTYPE==SC1000_HARDREFOLD)?((Modulo>1)?Modulo:0):0); // 0=modulo is off
		params.binning = P.Spc.Scale; // histogram binning is set to 1
		params.offset = 0; // histogram starts from the 0 time bins (see sc_tdc_get_binsize2()).
		params.size = SC1000_MAXBIN; // histogram size is SC1000_MAXBIN time bins (but note binning)!
		params.accumulation_ms = (P.Contest.Function==CONTEST_OSC?P.Spc.TimeO:P.Spc.TimeM)*SEC_2_MILLISEC; // 0=accumulation is off
		params.allocator_owner = NULL; // parameter for allocator cbf
		params.allocator_cb = NULL; // internal allocator is used
		ret = sc_pipe_open2(P.Spc.ScBoard[Board], TDC_HISTO, (void *)&params);
		//Delay(0.5);
	    //fprintf(fid,"%d\n",ret);
        //ErrHandler(ERR_SC1000,ret,"SC1000 error in getting binsize (factor)");
		//patch2(ret);
		if (ret < 0) {ErrHandler(ERR_SC1000,ret,"SC1000 error in opening pipe (factor)"); return;}
		else P.Spc.Pipe[Board][id]=ret;
		}
//	 fclose(fid);
	P.Spc.TimeInit=TimerN();   // era Timer() 
	
	// initialize memory
	if(Board==0){ // Only 1 item is needed for all the boards
		LinArray = doubleAlloc1D(P.Chann.Num);
		DCR_raw_count = SC1000Alloc1D(SC1000_MAXBIN);
		DCR_raw_time = doubleAlloc1D(SC1000_MAXBIN);
		IRF_raw_count = SC1000Alloc1D(SC1000_MAXBIN);
		IRF_raw_time = doubleAlloc1D(SC1000_MAXBIN);
		NonLinDt = doubleAlloc3D(P.Num.Board,P.Num.Det,SC1000_MAXBIN);
		}

	// initialise correction coefficients
	if(linearise) CalcNonlinSC1000(); // load BACKGROUND curve and derives coefficients for non-lin correction
	//CalcPeakSC1000();
	
	// start acquisition
	ret=sc_tdc_start_measure2(P.Spc.ScBoard[Board],SC1000_TIME_INFINITY); 
	if (ret < 0) {ErrHandler(ERR_SC1000,ret,"SC1000 error in starting whole acquisition"); return;} 
	Passed();
	
} 


/* CLOSE SC1000 */	
void CloseSC1000(void){
	int ib,id,ret;
	double now,delta;
	int status;
	for(ib=0;ib<P.Num.Board;ib++){
		/*patch*/
		if(P.Mamm.CloseMeas&&(P.Mamm.OverTresholdPrevious||P.Mamm.IsTop)){
		for(id=0;id<P.Num.Det;id++) ret=sc_pipe_close2(P.Spc.ScBoard[ib],P.Spc.Pipe[ib][id]);
		ret=sc_tdc_deinit2(P.Spc.ScBoard[ib]);
		}
		else{
		/**/
		ret=sc_tdc_interrupt2(P.Spc.ScBoard[ib]);
		Delay(6);
		for(id=0;id<P.Num.Det;id++){
			while(sc_pipe_read2(P.Spc.ScBoard[ib],P.Spc.Pipe[ib][id],(void *)&(NonLinArray),1000));
			ret=sc_pipe_close2(P.Spc.ScBoard[ib],P.Spc.Pipe[ib][id]);  // close pipe.
			}
		ret=sc_tdc_deinit2(P.Spc.ScBoard[ib]); // release hardware and resources.
		}
	}
	
	// free memory
	doubleFree1D(LinArray);
	SC1000Free1D(DCR_raw_count);
	doubleFree1D(DCR_raw_time);
	SC1000Free1D(IRF_raw_count);
	doubleFree1D(IRF_raw_time);
	doubleFree3D(NonLinDt,P.Num.Board,P.Num.Det);
	} 
int PipeRead(int ib,int id){
	int ret,fid,it=0;  
	do{
	ret=sc_pipe_read2(P.Spc.ScBoard[ib],P.Spc.Pipe[ib][id],(void *)&(NonLinArray),1000); // 2 ms ; 3 ms
	it++;
	if(ret<0&&it==2){
	if(P.Action.CheckEdge){
	char stepx=P.Mamm.Step[X];
	char loopx=P.Mamm.Loop[X];
	StopStep(stepx);
	ErrHandler(ERR_SC1000,ret,"Ho fermato la movimentazione");
	AnalysisMamm_new();
	FILE *fid;
	fid=fopen("CheckMamm.txt","a+");
	fprintf(fid,"%f\t%d\t%d\t%d\t%d\t%d\t%d - Errore\n",P.Mamm.Rate.Actual[0],P.Step[stepx].Actual,P.Loop[loopx].Idx,P.Loop[P.Mamm.Loop[Y]].Idx,P.Frame.Actual,P.Frame.Last,P.Frame.First);
	fclose(fid);
	/*StopSC1000(0);
	ErrHandler(ERR_SC1000,ret,"OutStopSc1000");
	for(id=0;id<P.Num.Det;id++) ret=sc_pipe_close2(P.Spc.ScBoard[ib],P.Spc.Pipe[ib][id]);
	ret=sc_tdc_deinit2(P.Spc.ScBoard[ib]);
	ErrHandler(ERR_SC1000,ret,"OutCloseSC1000");
	InitSC1000(0);
	double freq=fabs(P.Step[stepx].Delta)/(P.Spc.TimeM*P.Loop[P.Step[stepx].Loop].Num);
	if(freq!=P.Step[stepx].FreqActual) SetVel(stepx,freq);
	char trashmem=P.Spc.Trash;
	MoveStep(&P.Step[stepx].Actual,P.Step[stepx].StopGoal,stepx,FALSE,P.Action.Status);
	P.Spc.Trash=trashmem;*/
	}
	}
	}while(ret<0 && it<5);
	if(ret<0 && it==5) {
      ErrHandler(ERR_SC1000,ret,"PipeRead");
	}
	return ret;
}
/* TRANSFER DATA FROM SC1000 */	
void GetDataSC1000(void){
	unsigned int Counts[P.Num.Det];
	int ib,id,ic,ret,icc;
	int status;
	int linearise=(SC1000_LINEARISE&&(SC1000_REFOLDTYPE!=SC1000_HARDREFOLD));
	for(ib=0;ib<P.Num.Board;ib++)
		for(id=0;id<P.Num.Det;id++){
			ret=PipeRead(ib,id);  /*patch*/
			if(ret<0) {/*P.Mamm.Out=1; return;*/}
			if(linearise){
			  LinRefoldSC1000(SC1000_REFOLDTYPE,ib,id,NonLinArray,LinArray,P.Chann.Num); // 3 ms;0.75 ms
			  for(ic=0;ic<P.Chann.Num;ic++){ D.Buffer[ib][id*P.Chann.Num+ic]=(T_DATA) floor(LinArray[ic]+0.5);}
			}
			else{
				for(ic=0;ic<min(P.Chann.Num,SC1000_MAXBIN);ic++) D.Buffer[ib][id*P.Chann.Num+ic]=(T_DATA) floor(NonLinArray[ic]+0.5);
				for(ic=min(P.Chann.Num,SC1000_MAXBIN);ic<P.Chann.Num;ic++) D.Buffer[ib][id*P.Chann.Num+ic]=0;
				}
			if(ret<0) ErrHandler(ERR_SC1000,ret,"GetDataSC1000");
			
			
		}

}


int SC1000_start_patch(int ib){   /*patch*/
	int ret;
	ret=sc_tdc_start_measure2(P.Spc.ScBoard[ib],SC1000_TIME_INFINITY);
	if(ret<0) ErrHandler(ERR_SC1000,ret,"SC1000_start_patch");
	return ret;
}
/* CLEAR SC1000 */	
void ClearSC1000(void){
	int ic,ib,id,ret;
	int status;
	for(ib=0;ib<P.Num.Board;ib++){
		ret=sc_tdc_interrupt2(P.Spc.ScBoard[ib]);
		//Delay(P.Spc.CountRate<=9e6?3:5);/*patch*/
		P.Spc.CountRate=0;
		 	for(id=0;id<P.Num.Det;id++)
		        for(ic=0;ic<P.Chann.Num;ic++)
					P.Spc.CountRate+=D.Buffer[ib][ic+id*P.Chann.Num];
		P.Spc.CountRate/=P.Spc.TimeM;
		
		Delay(P.Spc.CountRate<=9e6?3:5);/*patch. utilizzare anche un limite per le misure normali*/
		//Delay(5);
		for(id=0;id<P.Num.Det;id++){
			while(sc_pipe_read2(P.Spc.ScBoard[ib],P.Spc.Pipe[ib][id],(void *)&(NonLinArray),1000));
			/*patch*/
			//do{ret=sc_pipe_read2(P.Spc.ScBoard[ib],P.Spc.Pipe[ib][id],(void *)&(NonLinArray),1000);}while(ret>0);
			//ret=sc_pipe_close2(P.Spc.ScBoard[ib],P.Spc.Pipe[ib][id]);  // close pipe.
			}
		//ret=sc_tdc_start_measure2(P.Spc.ScBoard[ib],SC1000_TIME_INFINITY); 
		}
	SC1000_start_patch(0); /*patch*/
	//SpcRestart();
	}
void StopSC1000(int ib){ /*patch*/
	int id,ret,ic;
	int status;
	for(ib=0;ib<P.Num.Board;ib++){
		ret=sc_tdc_interrupt2(P.Spc.ScBoard[ib]);
		P.Spc.CountRate=0;
		 	for(id=0;id<P.Num.Det;id++)
		        for(ic=0;ic<P.Chann.Num;ic++)
					P.Spc.CountRate+=D.Buffer[ib][ic+id*P.Chann.Num];
		P.Spc.CountRate/=P.Spc.TimeM;
		Delay(P.Spc.CountRate<=9e6?3:5);/*patch*/
		//Delay(5);
		for(id=0;id<P.Num.Det;id++)
			while(sc_pipe_read2(P.Spc.ScBoard[ib],P.Spc.Pipe[ib][id],(void *)&(NonLinArray),1000));
		}
	}

void CalcPeakSC1000(void){
	
	// To Be Implemented Later on;
	
	// load IRF
	/*
	FILE *pfile=fopen(IRF_file, "r");
	if(!pfile) {ErrHandler(ERR_GENERIC,0,"Unable to open IRF File"); return;}
	fgets(trash, STRLEN, pfile); // discard first title line
	//Sc1000NumBin=0;
	//while(fscanf(pfile,"%lf\t%d",&DCR_raw_time[Sc1000NumBin],&DCR_raw_count[Sc1000NumBin++])>0);
	for(icc=0;icc<SC1000_MAXBIN;icc++){
		//ret=fscanf(pfile,"%lf\t%d",&DCR_raw_time[Sc1000NumBin],&DCR_raw_count[Sc1000NumBin++]);
		ret=fscanf(pfile,"%lf\t%d",&IRF_raw_time[icc],&IRF_raw_count[icc]);
		if(ret<1) ErrHandler(ERR_GENERIC,ret,"Error loading DCR file");
		}
	fclose(pfile);
	
	// Linearize IRF
	LinRefoldSC1000(FALSE,0,0,IRF_raw_count,LinArray,NumChannLin);
	*/
	
	
	}

/* CALCULATE COEFFICIENTS FOR NON-LIN COMPENSATION */
void CalcNonlinSC1000(void){
	char trash[STRLEN];
	double meanDCR;
	int id,icc,ib;
	
	for(ib=0;ib<P.Num.Board;ib++){
		for(id=0;id<P.Num.Det;id++){
		
			// load DCR file
			FILE *pfile=fopen(DCR_files[ib][id], "r");
			//FILE *pfile=fopen("BKG_40MHZ_12h_ch0.txt", "r");
			if (!pfile) {ErrHandler(ERR_SC1000,0,"Unable to open DCR File"); return;}
			fgets(trash, STRLEN, pfile); // discard first title line
			icc=0;
			while(fscanf(pfile,"%lf\t%d",&DCR_raw_time[icc],&DCR_raw_count[icc++])>0);
			/*for(icc=0;icc<SC1000_MAXBIN;icc++){
				//ret=fscanf(pfile,"%lf\t%d",&DCR_raw_time[Sc1000NumBin],&DCR_raw_count[Sc1000NumBin++]);
				ret=fscanf(pfile,"%lf\t%d",&DCR_raw_time[icc],&DCR_raw_count[icc]);
				if(ret<1) ErrHandler(ERR_GENERIC,ret,"Error loading DCR file");
				}*/
			fclose(pfile);
	
			// calc non-lin coefficients
			meanDCR=0;
			for(icc=SC1000_FIRST;icc<SC1000_LAST;icc++) meanDCR+=DCR_raw_count[icc]; // icc = channel (bin) on the original non-lin TDC data
			meanDCR/=(SC1000_LAST-SC1000_FIRST+1);
			for(icc=SC1000_FIRST;icc<SC1000_LAST;icc++) NonLinDt[ib][id][icc]=ns2ps*Binsize*DCR_raw_count[icc]/meanDCR; // dtt stores the time-width of a bin
			}
		}
	}

/* APPLY LINEARIZATION & REBINNING */
void LinRefoldSC1000(int Refold,int Board,int Det,SC1000_TYPE *NonLinArray, double *LinArray, int NumChannLin){
	int ic,itp;
	int    	itt = SC1000_FIRST;	// index that scans over the original non-linear time scale
	int    	it = 0; 					// index that scans over the new linear time-scale
	int 		ntt = SC1000_LAST+1; // last chann of the Non-Lin Array
	int 		nt = NumChannLin; 	// length of the Lin Array
	double 	*dtt = NonLinDt[Board][Det]; 		// array with NonLin Delta;
	double   dt=P.Spc.Factor;				// lin delta
	double   rtt = NonLinDt[Board][Det][SC1000_FIRST];   //	remainder of the non-lin channel
	double  	rt = dt;  			// remainder of the new linerized time-interval that need to be filled with photons
	double 	T=Period; 				// full Period (ps) of the signal (take it exact for rebinning)
	double 	tt=0;						// absolute time of the actual non-lin channel (ps)
	int		numrep=1;				// number of replica so far, to be incremented every time you surpass T

	for(ic=0;ic<P.Chann.Num;ic++) LinArray[ic]=0;
	while(itt<(ntt)){
		if(((Refold==1)||(Refold==3)) && tt>T){  // if REBIN, both t & tt have surpassed the Period, then reset
			tt-=T;
			rt=dt-tt;
			it=0;
			numrep++;
			}
		if(rt >= rtt)  { // the receiving linear channel is large enough to accomodate the remaining of the original non-linear channel
			if(it<nt) LinArray[it] += (double)((NonLinArray[itt]/(dtt[itt])))*(rtt);
			if(Refold==1) tt+=rtt;
			if(Refold==3) tt+=ns2ps*Binsize;
			itt++;	  
			rt -= rtt;
			rtt = dtt[itt];
			}
		else{		      // the receiving linear channel is smaller than the remaining of the original non-linear channel
			if(it<nt) LinArray[it] += (double)((NonLinArray[itt]/(dtt[itt])))*(rt);
			if(Refold==1) tt+=rt;
			it++;
			rtt -= rt;
			rt = dt;
			}
   	}
	if(Refold==2){
		it=0;
		for(itt=(T/dt);itt<P.Chann.Num;itt++){
			LinArray[it]+=LinArray[itt];
			it++;
			if(it*dt>T) it=0;
			}
		for(itt=(T/dt);itt<P.Chann.Num;itt++) LinArray[itt]=0;
		}
	
	for (itp=it+1;itp<nt;itp++) LinArray[itp]*=(numrep/max(numrep-1,1));  // complete filling the LinArray and normalize for lower number of replica in the last part

	}

/* ########################   DEIB SPADLAB TDC FUNCTIONS (SPADLAB)  ####################### */

/* INIT SPADLAB */	
void InitSpad(int Board){
	int ret;
	char message[STRLEN];
	//P.Spc.Spad[Board].WriterTRS=0;
	//P.Spc.Spad[Board].SubscriberTDC=0;
	//P.Spc.Spad[Board].DataTRS=0;
	//P.Spc.Spad[Board].DataTDC=0;
	//unsigned int *buffer;
	
	sprintf (message, "Initializing SPADLAB, Module #%d, ...", Board);
	SetCtrlVal (hDisplay, DISPLAY_MESSAGE, message); 
	P.Spc.Spad[Board].Buffer = (unsigned int *) calloc (P.Num.Det*P.Chann.Num, sizeof(unsigned int));
	
	// initialise communication
	//ret = CNVCreateWriter(SPADLAB_TRS_WRITE,0, 0, 100000, 0, &P.Spc.Spad[Board].WriterTRS);
	//ret = CNVCreateScalarDataValue(&P.Spc.Spad[Board].DataTRS, CNVInt32, 0);
	ret = CNVCreateBufferedSubscriber(SPADLAB_TDC_WRITE, 0, 0, 1000, 5000, 0, &P.Spc.Spad[Board].SubscriberTDC);
	

	P.Spc.TimeInit=TimerN();   // era Timer() 
	if(ret<0) Failure("Error in Initializing SpadLab"); else Passed();
	} 


/* SET TIME SPADLAB */	
void TimeSpad(int Board, double Time){
	P.Spc.Spad[Board].Time = (Time*SEC_2_MILLISEC);
	// INSERT HERE FUNCTION TO DEFINE ACQUISITION TIME OR IN SpadStart;
	}

/* CLOSE SPADLAB */	
void CloseSpad(void){
	int ib, ret;
	for(ib=0;ib<P.Num.Board;ib++){
		//if(P.Spc.Spad[ib].DataTRS) ret = CNVDisposeData(P.Spc.Spad[ib].DataTRS);
		if(P.Spc.Spad[ib].DataTDC) ret = CNVDisposeData(P.Spc.Spad[ib].DataTDC);
		if(P.Spc.Spad[ib].SubscriberTDC) ret = CNVDispose(P.Spc.Spad[ib].SubscriberTDC);
		//if(P.Spc.Spad[ib].WriterTRS) ret = CNVDispose(P.Spc.Spad[ib].WriterTRS);
		free(P.Spc.Spad[ib].Buffer);
		CNVFinish();
		}
	} 


/* TRANSFER DATA FROM SPADLAB */	
void GetDataSpad(void){
	int ib,id,ic,ret;
	//size_t sizedata=P.Num.Det*P.Chann.Num*sizeof(unsigned int);
	size_t sizedata=P.Num.Det*P.Chann.Num;
	for(ib=0;ib<P.Num.Board;ib++){
		ret = CNVGetArrayDataValue (P.Spc.Spad[ib].DataTDC,CNVUInt32,(void*)P.Spc.Spad[ib].Buffer,sizedata);
		for(id=0;id<P.Num.Det;id++)
			for(ic=0;ic<P.Chann.Num;ic++) D.Buffer[ib][id*P.Chann.Num+ic]=(T_DATA) P.Spc.Spad[ib].Buffer[ic+id*P.Num.Det];
		if(P.Spc.Spad[ib].DataTDC) ret = CNVDisposeData(P.Spc.Spad[ib].DataTDC);
		}
	}


/* CLEAR SPADLAB */	
void ClearSpad(void){
	}


/* PAUSE SPADLAB */	
void PauseSpad(int Board){
	}


/* PAUSE SPADLAB */	
void StartSpad(int Board){
	//int ret;
	//ret = CNVSetScalarDataValue(P.Spc.Spad[Board].DataTRS, CNVInt32, SPADLAB_DATAIN);
	//ret = CNVWrite(P.Spc.Spad[Board].WriterTRS,P.Spc.Spad[Board].DataTRS,SPADLAB_MAXTIME);
	}


/* STOP SPADLAB */	
void StopSpad(int Board){
	}


/* WAIT SPADLAB */	
void WaitSpad(int Board){
	int ret;
	CNVBufferDataStatus	status;
	do ret = CNVGetDataFromBuffer(P.Spc.Spad[Board].SubscriberTDC, &P.Spc.Spad[Board].DataTDC, &status); // Get next data available in client buffer
	while(!(status == CNVNewData || status == CNVDataWasLost)); // Check for new data; ignore empty buffer (CNVNoData) and stale data (CNVStaleData)
	}


/* ########################   THARP SPC FUNCTIONS   ####################### */


/* INITIALIZE THARP */
/*
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
*/

/* TRANSFER DATA FROM THARP */	
/*
void GetDataTimeharp(void){
	int retcode;
	short ic;
	unsigned long tempData[BLOCKSIZE];
	retcode = TH_GetBlock(tempData);
	for(ic=0;ic<P.Chann.Num;ic++) D.Buffer[0][ic]=(T_DATA) tempData[ic+P.Chann.First];
	}
*/	


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


/* ########################   TEST DATA SIMULATING SPC   ######################## */

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
	

/* ########################   DEMO MODE   ######################## */

void InitDemo(void){
	}
void CloseDemo(void){
	}
void GetDataDemo(void){
	}
	

/* ########################   TRIMMER PROCEDURES   ######################## */


/* READ FILE TRIM */
void InitTrim(char Trim){
	int il;
	int numread = 0;
	long label;
	int roi;
	int loop=P.Step[P.Trim[Trim].Step].Loop;
	long num=P.Loop[loop].Num;
	char message[STRLEN];
	char row0[STRLEN];
	FILE *fpos;

    if(!P.Trim[Trim].FileTrim) return;
	
	sprintf(message,"Reading ROI Selection (ONE BASED) for Trimmer # %d ... ",Trim+1);
	SetCtrlVal (hDisplay,DISPLAY_MESSAGE,message);
   	fpos=fopen(P.Trim[Trim].FPath,"r");
	if(fpos==NULL){
		Failure("Error Loading File Trimmer");
		return;
		}				
	while(fgets(row0,STRLEN,fpos)!=NULL){
		sscanf(row0,"%d%d",&label,&roi);
	    for(il=0;il<num;il++){
			if(label==(P.Loop[loop].First+il*P.Loop[loop].Delta))
				P.Trim[Trim].RegionFile[il]=roi-1;	  // transform 1-based in 0-based
				numread+=1;
			}
		if(numread<(num-1)){ Failure("Error: Not Enough Points on File Trim"); return;}
		}
	fclose(fpos);
	Passed();
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
	char is_any_SPC = ((P.Spc.Type==SPC300)||(P.Spc.Type==SPC630)||(P.Spc.Type==SPC130)||(P.Spc.Type==HYDRA)||(P.Spc.Type==TH260));
	short page;
	
	// Actions for FileTrimmer
	if(P.Trim[Trim].FileTrim)
		T->RegionActual=T->RegionFile[P.Loop[loop].Actual];
	else
		T->RegionActual=T->Region;

	// Initialize
	//P.Contest.Function=CONTEST_TRIM;
	page=P.Roi.Page[T->RegionActual];
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
		if((T->Stop)&&((P.Step[si].Type==MICRO)||(P.Step[si].Type==MICRO2))) GetMicro(P.Step[si].Com,&P.Step[si].Actual); //WaitStep()????!
		else StopStep(si);
	
//	if(T->Type==CONT) 	WaitMicro(si,Origin+versus*T->Num*T->Delta);

	
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
void CheckTrimGoal(int Trim){
	long max, peak;
	int ib;
	struct TrimS *T = &P.Trim[Trim];
	double Treshold,area,width;
	short board=P.Page[P.Roi.Page[T->RegionActual]].Board;
	
	if(T->Target==TARGET_AREAWIDTH){
		T->Success=FALSE;
		GetRange(P.Roi.First[T->RegionActual],P.Roi.Last[T->RegionActual],T->Fract,&max,&peak,&T->Range.First,&T->Range.Last,&Treshold);
		area=CalcArea(P.Roi.First[T->RegionActual],P.Roi.Last[T->RegionActual]);
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
	GetRange(P.Roi.First[T->RegionActual],P.Roi.Last[T->RegionActual],T->Fract,&max,&peak,&T->Range.First,&T->Range.Last,&Treshold);
	switch (T->Target) {
		case TARGET_WIDTH: T->Value = CalcWidth(T->Range.First,T->Range.Last,Treshold);break;
		//case TARGET_AREA: T->Value = CalcArea(T->Roi.First,T->Roi.Last);break;
		case TARGET_AREA: T->Value = CalcArea(P.Roi.First[T->RegionActual],P.Roi.Last[T->RegionActual]);break;
		case TARGET_MAX_BOARD_AREA:	// Take max of all Pages
			T->Value=0;
			for(ib=0;ib<P.Num.Board;ib++){
				D.Curve=D.Osc[P.Roi.Page[2*ib+T->RegionActual]];
				area=CalcArea(P.Roi.First[T->RegionActual],P.Roi.Last[T->RegionActual]);
				if(area>T->Value) T->Value=area;
				}
				//area/=P.Spc.TimeO;
			
			break;
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
	long delta,stopgoal;
	int num_meas=1;
	int imeas,il;
	int loop = P.Step[Step].Loop;
	int iloop = P.Loop[loop].Actual;
	long start[MAXPOS];
	long stop[MAXPOS];
	char TrashMemory;
	
	char invert=(P.Loop[loop].Invert)&&REMINDER(P.Loop[loop-1].Idx,2);
	for(il=P.Step[Step].Loop+1;il<MAX_LOOP;il++) num_meas*=P.Loop[il].Num;
	
	for(il=0;il<P.Loop[loop].Num;il++){
		stop[il]=(invert?P.Step[Step].Start[P.Loop[loop].Num-1-il]:P.Step[Step].Stop[il]);
		start[il]=(invert?P.Step[Step].Stop[P.Loop[loop].Num-1-il]:P.Step[Step].Start[il]);
		}
	
	switch (P.Step[Step].Loop) {		// CHECK: MAYBE THERE IS AN ERROR IN THE PRODUCT OF .NUM
		case LOOP5: imeas=1; break;
		case LOOP4: imeas=1+P.Loop[LOOP5].Actual; break;
		case LOOP3: imeas=1+P.Loop[LOOP5].Actual+P.Loop[LOOP4].Actual*P.Loop[LOOP5].Num; break;
		case LOOP2: imeas=1+P.Loop[LOOP5].Actual+P.Loop[LOOP4].Actual*P.Loop[LOOP5].Num+P.Loop[LOOP3].Actual*P.Loop[LOOP4].Num*P.Loop[LOOP5].Num; break;
		case LOOP1: imeas=1+P.Loop[LOOP5].Actual+P.Loop[LOOP4].Actual*P.Loop[LOOP5].Num+P.Loop[LOOP3].Actual*P.Loop[LOOP4].Num*P.Loop[LOOP5].Num+P.Loop[LOOP2].Actual*P.Loop[LOOP3].Num*P.Loop[LOOP4].Num*P.Loop[LOOP5].Num; break;
		}
	switch (P.Loop[P.Step[Step].Loop].Cont) {
		case CONT_STEP:
			freq=fabs(stop[iloop]-start[iloop])/(num_meas*P.Spc.TimeM);
			stopgoal=stop[iloop];
			break;
		case CONT_RANGE:
			freq=fabs(P.Step[Step].Delta)/(num_meas*P.Spc.TimeM*P.Loop[P.Step[Step].Loop].Num);
			stopgoal=stop[P.Loop[P.Step[Step].Loop].Num-1];
			break;
		}
	if(freq!=P.Step[Step].FreqActual) SetVel(Step,freq);
	if((P.Wait.Type==WAIT_POS)&&(P.Wait.Step==Step)){
		delta=stop[iloop]-start[iloop];
		P.Wait.Pos=start[iloop]+(imeas*delta/num_meas);
		}
	//MoveStep(&P.Step[Step].Actual,stop[iloop],Step,FALSE,Status);	// TO CHECK: it was like this, but it looks wrong: replaced by the following
	TrashMemory=P.Spc.Trash;
	MoveStep(&P.Step[Step].Actual,stopgoal,Step,FALSE,Status);
	P.Spc.Trash=TrashMemory;   /*patch*/ //dopo aver fatto muovere il motorino continuo lui vede trash e nel ciclo succ pulisce, interrompendo la misura. fixed utilizzando trashmemory 
    P.Step[Step].StopGoal=stopgoal; //patch	
}


/* WAIT CONTINUOUS MOVEMENT */
void WaitCont(char Step, char Status){
	int il;
	int loop = P.Step[Step].Loop;
	int iloop = P.Loop[loop].Actual;
	long start[MAXPOS];
	long stop[MAXPOS];
	long stopgoal;
	
	char invert=(P.Loop[loop].Invert)&&REMINDER(P.Loop[loop-1].Idx,2);
	for(il=0;il<P.Loop[loop].Num;il++){
		stop[il]=(invert?P.Step[Step].Start[P.Loop[loop].Num-1-il]:P.Step[Step].Stop[il]);
		start[il]=(invert?P.Step[Step].Stop[P.Loop[loop].Num-1-il]:P.Step[Step].Start[il]);
		}
	switch (P.Loop[P.Step[Step].Loop].Cont) {
		case CONT_STEP:
			stopgoal=stop[iloop];
			break;
		case CONT_RANGE:
			stopgoal=stop[P.Loop[P.Step[Step].Loop].Num-1];
			break;
		}
	WaitStep(&P.Step[Step].Actual,stopgoal,Step,Status);
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
		case MICRO2:
		case MICRO:  InitMicro(Step); break;
		case PWM:	InitPwm(Step); break;
		case MONO:	InitMono(Step); break;
		case MONO_TCP:	InitMonoTcp(Step); break; 
		case PI1:	InitPi(Step); break;
		case FPM:	InitFpm(Step); break;
		case DELAYER:	InitDelayer(Step); break;
		//case ADC: InitAdc(); break;
		case AOTF_FREQ:	 break;
		case AOTF_POW: break;
		case DELAYER_GATE: InitDelayerGate(Step); break;
		/*XYZ*/case STANDA: InitStanda(Step); break;
		case NKT_LAMBDA: InitNKTLambda(Step);break;
		case NKT_POW:	 InitNKTPow(Step);break;
		case ESP300:  InitEsp300(Step); break;
		case LT900:  InitLt900(Step); break;
		case CHAMALEON:  InitCham(Step); break;
		case STEP_STANDA2: InitStanda2(Step); break;
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
		case MICRO2:
		case MICRO: CloseMicro(Step); break;
		case PWM: ClosePwm(Step); break;
		case MONO: CloseMono(Step); break;
		case MONO_TCP: CloseMonoTcp(Step); break;   
		case PI1: ClosePi(); break;
		case FPM: CloseFpm(Step); break;
		case DELAYER: break;
		case ADC: break;
		case AOTF_FREQ:	break;
		case AOTF_POW:	break; 
		/*XYZ*/case STANDA: CloseStanda(Step); break;
		case NKT_LAMBDA: CloseNKTLambda(Step);break;
		case NKT_POW:	 CloseNKTPow(Step);break;
		case ESP300: CloseEsp300(Step); break;
		case LT900: CloseLt900(Step); break;
		case CHAMALEON: CloseCham(Step); break;
		case STEP_STANDA2: CloseStanda2(Step); break;
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
		case MICRO2:
		case MICRO:  SetVelMicro(Step,Freq); break;
		case PWM:  SetVelPwm(Step,Freq); break;
		case MONO:  SetVelMono(Step,Freq); break;
		case MONO_TCP: SetVelMonoTcp(Step,Freq); break;
		case PI1:  SetVelPi(Freq); break;
		case FPM: break;	/* Need no velocity setting */
		case DELAYER: break;
		case ADC: break;
		case AOTF_FREQ: break; /* Need no velocity setting */
		case AOTF_POW: break; /* Need no velocity setting */
		/*XYZ*/case STANDA: SetVelStanda(Step,Freq); break;
		case NKT_LAMBDA: break;
		case NKT_POW:	 break;
		case ESP300: SetVelEsp300(Step,Freq); break;
		case LT900: break;
		case CHAMALEON: SetVelCham(Step,Freq); break;
		case STEP_STANDA2: SetVelStanda2(Step,Freq); break;
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
		case MICRO2:
		case MICRO: DefineHomeMicro(Step); break;
		case PWM: DefineHomePwm(Step); break;
		case MONO: DefineHomeMono(Step); break;
		case MONO_TCP: DefineHomeMonoTcp(Step); break;               
		case PI1: DefineHomePi(Step); break;               
		case FPM: break;	/* Need no home definition ! */
		case DELAYER: break;
		case ADC: break;
		case AOTF_FREQ: break;
		case AOTF_POW: break; 
		/*XYZ*/case STANDA: DefineHomeStanda(Step); break;
		case NKT_LAMBDA: break;
		case NKT_POW:	 break;
		case ESP300: DefineHomeEsp300(Step); break;
		case LT900: DefineHomeLt900(Step); break;
		case CHAMALEON: DefineHomeCham(Step); break;
		case STEP_STANDA2: DefineHomeStanda2(Step); break;
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
	//index = P.Loop[loop].Idx;
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
		case MICRO2:
		case MICRO: MoveMicro(Step,Goal,Wait); break;
		case PWM: MovePwm(Step,Goal,Wait); break;
		case MONO: MoveMono(Step,Goal,Wait); break;
		case MONO_TCP: MoveMonoTcp(Step,Goal,Wait); break;   
		case PI1: MovePi(Step,Goal,Wait); break;
		case FPM: MoveFpm(Step, Goal); break;	/* Fiber power monitor: actually read Power  */
		case DELAYER: MoveDelayer(Step, Goal); break;
		//case ADC: StartAdc(); break;	/* Analog to digital converter: actually read Power, already in kernel  */
		case AOTF_FREQ: SetFreqNI_USB6229(Step, Goal); break;
		case AOTF_POW: SetVoltNI_USB6221(Step, Goal); break;
		case DELAYER_GATE: MoveDelayerGate(Step, Goal); break;
		case STANDA: MoveStanda(Step,Goal,Wait); break;
		case NKT_LAMBDA: SetNKTLambda(Step,Goal);break;
		case NKT_POW:	 SetNKTPow(Step,Goal);break;
		case ESP300: MoveEsp300(Step,Goal,Wait); break;
		case LT900: MoveLt900(Step,Goal); break;
		case CHAMALEON: MoveCham(Step,Goal,Wait); break;
		case STEP_STANDA2: MoveStanda2(Step,Goal,Wait); break;
		}
	P.Spc.Trash=TRUE;
	P.Step[Step].StopGoal=Goal;
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
		case MICRO2:
		case MICRO: StopMicro(Step); break;
		case PWM: StopPwm(Step); break;
		case MONO: break;
		case MONO_TCP: break;
		case PI1: StopPi(); break;
		case FPM: StopFpm(Step); break;
		//case ADC: StopAdc(); break;
		case DELAYER: break;
		case AOTF_FREQ: break;
		case AOTF_POW: break;
		case STANDA: StopStanda(Step); break;
		case NKT_LAMBDA: break;
		case NKT_POW:	 break;
		case ESP300: StopEsp300(Step); break;
		case LT900: break;
		case CHAMALEON: StopCham(Step); break;
		case STEP_STANDA2: StopStanda2(Step); break;
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
		case MICRO2:
		case MICRO: TellPosMicro(Step,Position); break;
		case PWM: TellPosPwm(Step,Position); break;
		case MONO: TellPosMono(Step,Position); break;
		case MONO_TCP: TellPosMonoTcp(Step,Position); break;
		case PI1: TellPosPi(Step,Position); break;
		case FPM: break;
		case DELAYER: break;
		case ADC: break;
		case NONE: break;
		case AOTF_FREQ: break;
		case AOTF_POW: break;
		case STANDA: TellPosStanda(Step,Position); break;
		case NKT_LAMBDA: break;
		case NKT_POW:	 break;
		case ESP300: TellPosEsp300(Step,Position); break;
		case LT900: break;
		case CHAMALEON: TellPosCham(Step,Position); break;
		case STEP_STANDA2: TellPosStanda2(Step,Position); break;
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
		case MICRO2:
		case MICRO: WaitMicro(Step,Goal); break;
		//case PWM: WaitPwm(Step,Goal); break;
		case MONO: WaitMono(Step,Goal); break;
		case MONO_TCP: WaitMonoTcp(Step,Goal); break;     
		case PI1: WaitPi(Step,Goal); break;
		case AOTF_FREQ: break;
		case AOTF_POW: break;
		//case ADC: WaitAdc(); break;
		case STANDA: WaitStanda(Step,Goal); break;
		case NKT_LAMBDA: break;
		case NKT_POW:	 break;
		case ESP300: WaitEsp300(Step,Goal); break;
		case LT900: break;
		case CHAMALEON: WaitCham(Step,Goal); break;
		case STEP_STANDA2: WaitStanda2(Step,Goal); break;
		default: break;
		}
	}


// ### STEPPER WITH PARALELL PORT ###

/* INITIALIZE MONO STEP MOTOR BY PARALLEL PORT */
void InitLpt(void) {
    short  pstatus, data;
	SetCtrlVal (hDisplay,DISPLAY_MESSAGE, "Initializing Parallel Port ...\n");
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
	P.Step[Step].Mio.Board = P.Step[Step].Com;; //MIO's device number
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
void CloseMio(char Step) {
	int response;
	response=ConfirmPopup("CloseMio", "Do you want to close the MIO board?");
	if (response==1) AOUpdateChannel(P.Step[Step].Mio.Board,"0",0);
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
	int com=P.Step[Step].Com;
	int micro_baudrate=(P.Step[Step].Type==MICRO2?MICRO2_BAUDRATE:MICRO_BAUDRATE);
	sprintf(message,"Initializing MICRO Stepper #%d on COM%d",Step+1,com);
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE,message);
	open=OpenComConfig(com,NULL,micro_baudrate,MICRO_PARITY,MICRO_DATABITS,MICRO_STOPBITS,0,-1);
	FlushInQ (com);
	FlushOutQ (com);
    
    TalkMicro(Step,MICRO_LCD,P.Step[Step].Lcd,&ret);
    TalkMicro(Step,MICRO_HOLD,P.Step[Step].Hold,&ret);
    TalkMicro(Step,MICRO_FMIN,P.Step[Step].FreqMin,&ret);
	TalkMicro(Step,MICRO_VEL,(int) P.Step[Step].Freq,&ret);
	TalkMicro(Step,MICRO_FDELTA,P.Step[Step].FreqDelta,&ret);
//**    TalkMicro(com,MICRO_HOME,P.Step[Step].Home,&ret);
    
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE," PASSED\n");
	}


/* CLOSE MICRO */
void CloseMicro(char Step){
	int ret;
	int com=P.Step[Step].Com;
    TalkMicro(Step,MICRO_END,0,&ret);
	FlushInQ (com);
	FlushOutQ (com);
	CloseCom (com);
	}


/* SET FREQUENCY MICRO */	
void SetVelMicro(char Step, double Freq){
	int ret;
//	int com=P.Step[Step].Com;
    TalkMicro(Step,MICRO_VEL,(int) Freq,&ret);
	}


/* MOVE MICRO */
void MoveMicro(char Step,long Goal,char Wait){
	int ret;
	int com=P.Step[Step].Com;
	if(Goal==P.Step[Step].Actual) return;
    TalkMicro(Step, MICRO_GOTO, Goal,&ret);
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
/*void WaitMicro(char Step,long Goal){
	long actual;
	int com=P.Step[Step].Com;
	if(Goal==P.Step[Step].Actual) return;
	GetMicro(com,&actual);
	P.Step[Step].Actual=actual;
	}*/ 

/* WAIT END OF MICRO MOVEMENT */
/* NEW */
/*void WaitMicro(char Step,long Goal){
	long actual;
	if(Goal==P.Step[Step].Actual) return;
	do TellPosMicro(Step, &actual); 
	while(Goal!=actual);
	P.Step[Step].Actual=actual;
	} */


/* WAIT END OF MICRO MOVEMENT */
void WaitMicro(char Step,long Goal){
	long actual;
	int com=P.Step[Step].Com;
	if(Goal==P.Step[Step].Actual) return;
	switch (P.Step[Step].Type) {
		case MICRO:
			GetMicro(com,&actual);
			break;
		case MICRO2:
			do TellPosMicro(Step, &actual);
			while(Goal!=actual);
			break;
		}
	P.Step[Step].Actual=actual;
	return;
	} 


/* TELL POSITION MICRO */
void TellPosMicro(char Step,long *Actual){
//	int com=P.Step[Step].Com;
    TalkMicro(Step,MICRO_TELL,0,Actual);
	}


/* STOP MICRO */
void StopMicro(char Step){
//	int com=P.Step[Step].Com;
    TalkMicro(Step, MICRO_STOP,0,&P.Step[Step].Actual);
	}


/* DEFINE HOME MICRO */
void DefineHomeMicro(char Step){
//**	int com=P.Step[Step].Com;
//**    TalkMicro(com,MICRO_HOME,P.Step[Step].Home,&ret);
    }


/* SEND COMMAND TO MICRO AND GET ANSWER */
void TalkMicro(char Step, char Command, long Value, long *Answer){
	unsigned char *pChar;
	unsigned char Command4Char[4];
	unsigned short shortValue=(unsigned short)Value;

	char *pChar2;
	
	int com=P.Step[Step].Com;

	switch (P.Step[Step].Type) {
		case MICRO:
			pChar = (unsigned char*) &shortValue;
			Command4Char[0]=pChar[0];
			Command4Char[1]=pChar[1];
			Command4Char[2]=0;
			Command4Char[3]=(unsigned char) Command;
			ComWrt(com,(const char*)Command4Char,4);
			GetMicro(com,Answer);
			break;
		case MICRO2:
			pChar2 = (char*) &Value;
			pChar2[3] = (char) Command;
			ComWrt(com,pChar2,4);
			GetMicro(com,Answer);
			break;
		}
	return;	
	}

/* GET ANSWER FROM MICRO */
void GetMicro(int Com,long *Answer){
	char *pChar;
	pChar = (char*) Answer;
	while(ComRd (Com,pChar,4)<4);
	}


// #### ESP300 STEPPER ####
// Controller to drive both CEA XYZ stages and CEA variable attenuator
	
/* INITIALIZE ESP300 */
void InitEsp300(char Step){
	int open;
	char message[STRLEN];
	char answer[STRLEN];
	int com=P.Step[Step].Com;
	int axis=P.Step[Step].Axis+1;
	sprintf(message,"Initializing ESP300 Stepper #%d on COM%d",Step+1,com);
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE,message);
	open=OpenComConfig(com,NULL,ESP300_BAUDRATE,ESP300_PARITY,ESP300_DATABITS,ESP300_STOPBITS,0,-1);
	FlushInQ (com);
	FlushOutQ (com);
	
	TalkEsp300b(com,axis,ESP300_VER); 
	GetEsp300(com,answer);
	TalkEsp300b(com,axis,ESP300_STATUS); 
	GetEsp300(com,answer);
	TalkEsp300b(com,axis,ESP300_STAGE); 
	GetEsp300(com,answer);
	TalkEsp300b(com,axis,ESP300_QUITPROG); 
	TalkEsp300b(com,axis,ESP300_TRAJTRAP); 
    
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE," PASSED\n");
	}


/* CLOSE ESP300 */
void CloseEsp300(char Step){
	int com=P.Step[Step].Com;
    //TODO TalkEsp300(com,ESP300_END,0,&ret);
	FlushInQ (com);
	FlushOutQ (com);
	CloseCom (com);
	}


/* SET FREQUENCY ESP300 */	
void SetVelEsp300(char Step, double Freq){
	int com=P.Step[Step].Com;
	int axis=P.Step[Step].Axis+1;
    //TalkEsp300a(com,axis,ESP300_MAXVEL,(int) Freq);
    TalkEsp300a(com,axis,ESP300_VEL,(int) Freq);
	}


/* MOVE ESP300 */
void MoveEsp300(char Step,long Goal,char Wait){
	int com=P.Step[Step].Com;
	int axis=P.Step[Step].Axis+1;
	if(Goal==P.Step[Step].Actual) return;
    TalkEsp300a(com,axis,ESP300_GOTO,Goal);
	if(Wait) WaitEsp300(Step,Goal);
	}

/* WAIT END OF ESP300 MOVEMENT */
void WaitEsp300(char Step,long Goal){
	int com=P.Step[Step].Com;
	int axis=P.Step[Step].Axis+1;
	if(Goal==P.Step[Step].Actual) return;
    TalkEsp300b(com,axis,ESP300_WAIT);
	TellPosEsp300(Step,&P.Step[Step].Actual);
	}


/* TELL POSITION ESP300 */
void TellPosEsp300(char Step,long *Actual){
	double value;
	char answer[STRLEN];
	int com=P.Step[Step].Com;
	int axis=P.Step[Step].Axis+1;
    TalkEsp300b(com,axis,ESP300_TELL);
	GetEsp300(com,answer);
	Scan (answer, "%s>%f", &value);
	*Actual=(long) value;	
	}


/* STOP ESP300 */
void StopEsp300(char Step){
	int com=P.Step[Step].Com;
	int axis=P.Step[Step].Axis+1;
    TalkEsp300b(com,axis,ESP300_STOP);
	TellPosEsp300(Step,&P.Step[Step].Actual);
	}


/* DEFINE HOME ESP300 */
void DefineHomeEsp300(char Step){
	//int com=P.Step[Step].Com;
	//int axis=P.Step[Step].Axis+1;
    //TalkEsp300a(com,axis,ESP300_HOME,P.Step[Step].Home);   // NO: Use Internal ESP300 HOME
    }


/* SEND COMMAND TO ESP300 WITH VALUE */
void TalkEsp300a(int Com, int Axis, char *Command, long Value){
	char sInstruction[STRLEN];
	int numchar;
	int ret;
	numchar = sprintf (sInstruction,"%d%s%d%c",Axis,Command,Value,ESP300_TERM);
	ret = ComWrt (Com, sInstruction, numchar);
	if(ret<0) Failure("Error on Comunicating with COM under TalkEsp300a function");
	if(ret<numchar) Failure("TIMEOUT on COM under TalkEsp300a function");
	}

/* SEND COMMAND TO ESP300 WITHOUT VALUE */
void TalkEsp300b(int Com, int Axis, char *Command){
	char sInstruction[STRLEN];
	int numchar;
	int ret;
	numchar = sprintf (sInstruction,"%d%s%c",Axis,Command,ESP300_TERM);
	ret = ComWrt(Com, sInstruction, numchar);
	if(ret<0) Failure("Error on Comunicating with COM under TalkEsp300b function");
	if(ret<numchar) Failure("TIMEOUT on COM under TalkEsp300b function");
	}

/* GET ANSWER FROM ESP300 */
void GetEsp300(int Com,char *Answer){
	int numchar;
	do numchar=ComRdTerm(Com, Answer, STRLEN, ESP300_TERM); 
	while(numchar<=0);
	Answer[numchar]=0;
	}



// #### LT900 STEPPER ####
// Controller to drive LT900 SWITCH from CEA
	
/* INITIALIZE LT900 */
void InitLt900(char Step){
	int open;
	char message[STRLEN];
	char answer[STRLEN];
	int com=P.Step[Step].Com;
	sprintf(message,"Initializing LT900 Stepper #%d on COM%d",Step+1,com);
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE,message);
	open=OpenComConfig(com,NULL,LT900_BAUDRATE,LT900_PARITY,LT900_DATABITS,LT900_STOPBITS,0,-1);
	FlushInQ (com);
	FlushOutQ (com);
	TalkLt900(com,LT900_RESET,answer);
	if(CompareStrings (answer, 0, LT900_ANS_RESET, 0, 0)==0) Passed(); else Failure("Error on Reset");
	}


/* CLOSE LT900 */
void CloseLt900(char Step){
	char answer[STRLEN];
	int com=P.Step[Step].Com;
	TalkLt900(com,LT900_GO0,answer);
	FlushInQ (com);
	FlushOutQ (com);
	CloseCom (com);
	}


/* MOVE LT900 */
void MoveLt900(char Step,long Goal){
	char scommand[STRLEN];
	char answer[STRLEN];
	//double now,delta;
	int com=P.Step[Step].Com;
	if(Goal==P.Step[Step].Actual) return;
	sprintf (scommand, "SWITCH:%d", Goal);
	//now = Timer ();
    TalkLt900(com,scommand,answer);
	//delta=Timer ()-now;
	P.Step[Step].Actual=Goal;
	}


/* DEFINE HOME LT900 */
void DefineHomeLt900(char Step){
	MoveLt900(Step,P.Step[Step].Home);
    }


/* SEND COMMAND TO LT900 WITHOUT VALUE */
void TalkLt900(int Com, char *Command, char *Answer){
	char sInstruction[STRLEN];
	int numchar;
	int ret;
	numchar = sprintf (sInstruction,"%s%c",Command,LT900_TERM);
	ret = ComWrt(Com, sInstruction, numchar);
	if(ret<0) Failure("Error on Comunicating with COM under TalkLt900b function");
	if(ret<numchar) Failure("TIMEOUT on COM under TalkLt900b function");
	GetLt900(Com,Answer);
	}

/* GET ANSWER FROM LT900 */
void GetLt900(int Com,char *Answer){
	int numchar;
	do numchar=ComRdTerm(Com, Answer, STRLEN, LT900_TERM); 
	while(numchar<=0);
	Answer[numchar]=0;
	}


// #### CHAM STEPPER ####
// Controller to drive both CEA XYZ stages and CEA variable attenuator
	
/* INITIALIZE CHAM */
void InitCham(char Step){
	int open;
	char message[STRLEN];
	int com=P.Step[Step].Com;
	sprintf(message,"Initializing CHAM Stepper #%d on COM%d",Step+1,com);
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE,message);
	open=OpenComConfig(com,NULL,CHAM_BAUDRATE,CHAM_PARITY,CHAM_DATABITS,CHAM_STOPBITS,0,-1);
	FlushInQ (com);
	FlushOutQ (com);
    
    //TalkCham(com,CHAM_LCD,P.Step[Step].Lcd,&ret);
    //TalkCham(com,CHAM_HOLD,P.Step[Step].Hold,&ret);
    //TalkCham(com,CHAM_FMIN,P.Step[Step].FreqMin,&ret);
	//TalkCham(com,CHAM_VEL,(int) P.Step[Step].Freq,&ret);
	//TalkCham(com,CHAM_FDELTA,P.Step[Step].FreqDelta,&ret);
//**    TalkCham(com,CHAM_HOME,P.Step[Step].Home,&ret);
    
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE," PASSED\n");
	}


/* CLOSE CHAM */
void CloseCham(char Step){
	int com=P.Step[Step].Com;
    //TODO TalkCham(com,CHAM_END,0,&ret);
	FlushInQ (com);
	FlushOutQ (com);
	CloseCom (com);
	}


/* SET FREQUENCY CHAM */	
void SetVelCham(char Step, double Freq){
	int com=P.Step[Step].Com;
	int axis=P.Step[Step].Axis+1;
    TalkChama(com,axis,CHAM_VEL,(int) Freq);
	}


/* MOVE CHAM */
void MoveCham(char Step,long Goal,char Wait){
	int com=P.Step[Step].Com;
	int axis=P.Step[Step].Axis+1;
	if(Goal==P.Step[Step].Actual) return;
    TalkChama(com,axis,CHAM_GOTO,Goal);
	if(Wait) WaitCham(Step,Goal);
	}

/* WAIT END OF CHAM MOVEMENT */
void WaitCham(char Step,long Goal){
	int com=P.Step[Step].Com;
	int axis=P.Step[Step].Axis+1;
	if(Goal==P.Step[Step].Actual) return;
    TalkChamb(com,axis,CHAM_WAIT);
	TellPosCham(Step,&P.Step[Step].Actual);
	}


/* TELL POSITION CHAM */
void TellPosCham(char Step,long *Actual){
	float answer;
	int com=P.Step[Step].Com;
	int axis=P.Step[Step].Axis+1;
    TalkChamb(com,axis,CHAM_TELL);
	GetCham(com,&answer);
	*Actual=(long) answer;	
	}


/* STOP CHAM */
void StopCham(char Step){
	int com=P.Step[Step].Com;
	int axis=P.Step[Step].Axis+1;
    TalkChamb(com,axis,CHAM_STOP);
	TellPosCham(Step,&P.Step[Step].Actual);
	}


/* DEFINE HOME CHAM */
void DefineHomeCham(char Step){
	//int com=P.Step[Step].Com;
	//int axis=P.Step[Step].Axis+1;
    //TalkChama(com,axis,CHAM_HOME,P.Step[Step].Home);   // NO: Use Internal CHAM HOME
    }


/* SEND COMMAND TO CHAM WITH VALUE */
void TalkChama(int Com, int Axis, char Command[2], long Value){
	char sInstruction[STRLEN];
	int numchar;
	int ret;
	numchar = sprintf (sInstruction,"%d%c%c%d%c",Axis,Command[1],Command[2],Value,CHAM_TERM);
	ret = ComWrt (Com, sInstruction, numchar);
	if(ret<0) Failure("Error on Comunicating with COM under TalkChama function");
	if(ret<numchar) Failure("TIMEOUT on COM under TalkChama function");
	}

/* SEND COMMAND TO CHAM WITHOUT VALUE */
void TalkChamb(int Com, int Axis, char Command[2]){
	char sInstruction[STRLEN];
	int numchar;
	int ret;
	numchar = sprintf (sInstruction,"%d%c%c%c",Axis,Command[1],Command[2],CHAM_TERM);
	ret = ComWrt(Com, sInstruction, numchar);
	if(ret<0) Failure("Error on Comunicating with COM under TalkChamb function");
	if(ret<numchar) Failure("TIMEOUT on COM under TalkChamb function");
	}

/* GET ANSWER FROM CHAM */
void GetCham(int Com,float *Answer){
	char sAnswer[STRLEN];
	while(ComRdTerm (Com, sAnswer, INT_MAX, CHAM_TERM)<0);
	Scan (sAnswer, "%s>%d", *Answer);
	}




// #### PI STEPPER ####
	
/* INITIALIZE PI */
void InitPi(char Step){
	int open,nErr;
	char message[STRLEN];
	int com=P.Step[Step].Com;
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
//**	int com=P.Step[Step].Com;
//**    TalkPi(com,PI_HOME,P.Step[Step].Home,&ret);
    }



// #### STANDA STEPPER BY MICROSMC ####

#ifndef NO_STANDA 		  // check if Standa is used or not

// Function that prints last error information
void PrintError(void)
{
	char er[101];
	USMC_GetLastErr(er,100);
	er[100] = '\0';
	//printf("\n%s",er);
}



/* INITIALIZE STANDA */
void InitStanda(char Step){
	char message[STRLEN];
	USMC_Devices DVS;
	USMC_Parameters Prms;
	USMC_Mode Mode;
	USMC_State State;
	DWORD dev=P.Step[Step].Axis;
	sprintf(message,"Initializing STANDA Driver #%d on AXIS%d",Step+1,dev);
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE,message);
	//if(USMC_Init(&DVS)) PrintError();
	if(USMC_Init(&DVS)) Failure("ERROR INITIALIZING");

	// Uncomment those parameters you want to override
	if(USMC_GetParameters(dev,&Prms)) Failure("ERROR GETTING PARAMETRS FROM STANDA");
	//Prms.MaxTemp = STANDA_MaxTemp;
	//Prms.AccelT = STANDA_AccelT;
	//Prms.DecelT = STANDA_DecelT;
	//Prms.BTimeout1 = STANDA_BTimeout1;
	//Prms.BTimeout2 = STANDA_BTimeout2;
	//Prms.BTimeout3 = STANDA_BTimeout3;
	//Prms.BTimeout4 = STANDA_BTimeout4;
	//Prms.BTO1P = STANDA_BTO1P;
	//Prms.BTO2P = STANDA_BTO2P;
	//Prms.BTO3P = STANDA_BTO3P;
	//Prms.BTO4P = STANDA_BTO4P;
	//Prms.MinP = STANDA_MinP;
	//Prms.BTimeoutR = STANDA_BTimeoutR;
	//Prms.LoftPeriod = STANDA_LoftPeriod;
	//Prms.RTDelta = STANDA_RTDelta;
	//Prms.RTMinError = STANDA_RTMinError;
	//Prms.EncMult = STANDA_EncMult;
	//Prms.MaxLoft = STANDA_MaxLoft;
	//Prms.PTimeout = STANDA_PTimeout;
	//Prms.SynOUTP = STANDA_SynOUTP;
	if(USMC_SetParameters(dev,&Prms)) Failure("ERROR SETTING PARAMETRS TO STANDA");
	if(USMC_GetParameters(dev,&Prms)) Failure("ERROR GETTING PARAMETRS FROM STANDA");
	
	// DISABLE LIMITS AND TURN ON POWER
	if(USMC_GetMode(dev,&Mode)) Failure("ERROR GETTING MODE FROM STANDA");   
	Mode.Tr1En = FALSE;
	Mode.Tr2En = FALSE;
	Mode.ResetD = FALSE; // Turn power on 
	if(USMC_SetMode(dev,&Mode)) Failure("ERROR SETTING MODE TO STANDA");   
	
	SetVelStanda(Step,P.Step[Step].Freq);
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE," PASSED\n");

	// Print Status Information
	if(USMC_GetState(dev,&State)) Failure("ERROR GETTING STATE FROM STANDA");   
	sprintf(message, "STANDA STATUS Axis=%d,Loop=%d,Temp=%f,Volt=%f\n",P.Step[Step].Axis+1,P.Loop[P.Step[Step].Loop].Actual,State.Temp,State.Voltage);
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE,message);
	}


/* CLOSE STANDA */
void CloseStanda(char Step){
	USMC_Parameters Prms;
	USMC_Mode Mode;
	USMC_State State;
	DWORD dev=P.Step[Step].Axis;
	if( USMC_GetParameters(dev,&Prms)) Failure("ERROR GETTING PARAMETRS FROM STANDA");   
	if( USMC_GetMode(dev,&Mode)) Failure("ERROR GETTING MODE FROM STANDA");   
	// Go to Full Step (automaticaly), then Turn Off
	Mode.ResetD = TRUE;
	if(USMC_SetMode(dev,&Mode)) Failure("ERROR SETTING MODE TO STANDA");   
	// Wait until Previous Comand is Done
	do{
		Sleep(50);
		if(USMC_GetState(dev,&State)) Failure("ERROR GETTING STATE FROM STANDA");  
		}
	while(State.Power==TRUE);
 	}


/* SET FREQUENCY STANDA */	
void SetVelStanda(char Step,double Freq){
	/*if(USMC_GetParameters(Dev,Prms)) SetCtrlVal (hDisplay, DISPLAY_MESSAGE,"ERROR READING PARAMETERS FROM STANDA\n");
	Prms.MinP = (float)Freq;
	Prms.BTO1P = (float)Freq;
	Prms.BTO2P = (float)Freq;
	Prms.BTO3P = (float)Freq;
	Prms.BTO4P = (float)Freq;
	if(!USMC_SetParameters(Dev,Prms))
 		SetCtrlVal (hDisplay, DISPLAY_MESSAGE,"ERROR SETTING PARAMETERS TO STANDA\n");  */
	}


/* MOVE STANDA */
void MoveStanda(char Step,long Goal,char Wait){
	float speed=(float)P.Step[Step].Freq;
	long goal_standa=(long)(Goal+P.Step[STEP].Standa.Home/STANDA_TICSxSTEP);
	USMC_StartParameters StPrms;
	DWORD dev=P.Step[Step].Axis;
	char message[STRLEN];
	USMC_State State;
	//if(Goal==P.Step[Step].Actual) return;

	// Reinitialize if ERROR ON POWER
	if(USMC_GetState(dev,&State)) Failure("ERROR GETTING STATE FROM STANDA");   
	if(!State.Power){
		sprintf(message, "POWER FAIL Axis=%d,Loop=%d,Temp=%f,Volt=%f\n",P.Step[Step].Axis+1,P.Loop[P.Step[Step].Loop].Actual,State.Temp,State.Voltage);
		//MessagePopup ("STATE", message); 
    	SetCtrlVal (hDisplay, DISPLAY_MESSAGE,message);
		InitStanda(Step);
		}

	if(USMC_GetStartParameters(dev,&StPrms)) Failure("ERROR GETTING START PARAMETERS TO STANDA");   
	StPrms.SlStart = TRUE;
	StPrms.SDivisor = 1;
	if(USMC_Start(dev,goal_standa,&speed,&StPrms)) Failure("ERROR STARTING STANDA");  
	if(Wait) WaitStanda(Step,Goal);
	}

/* WAIT END OF STANDA MOVEMENT */
void WaitStanda(char Step,long Goal){
	long actual;
	USMC_State State;
	DWORD dev=P.Step[Step].Axis;
	if(Goal==P.Step[Step].Actual) return;
	
	// wait until movement completed
	do{
		Sleep(50);
		if(USMC_GetState(dev,&State)) Failure("ERROR GETTING STATE FROM STANDA");   
		}
	while(State.RUN!=FALSE);
					   
	TellPosStanda(Step,&actual);
	P.Step[Step].Actual=(long)actual;
	}


/* TELL POSITION STANDA */
void TellPosStanda(char Step,long *Actual){
	USMC_State State;
	DWORD dev=P.Step[Step].Axis;
	if(USMC_GetState(dev,&State)) Failure("ERROR GETTING STATE FROM STANDA");   
	*Actual=(long)((State.CurPos-P.Step[Step].Standa.Home)/STANDA_TICSxSTEP);
	}


/* STOP STANDA */
void StopStanda(char Step){
	DWORD dev=P.Step[Step].Axis;
	if(USMC_Stop(dev)) Failure("ERROR STOPPING STANDA");   
	}


/* DEFINE HOME STANDA */
void DefineHomeStanda(char Step){
	USMC_State State;
	DWORD dev=P.Step[Step].Axis;
	if(USMC_GetState(dev,&State)) Failure("ERROR GETTING STATE FROM STANDA"); 
	P.Step[Step].Standa.Home=State.CurPos; // ACTUAL POSITIONS IN TICS (Steps = Ticks x STANDA_TICSxSTEP)
	}

#else	 // create void functions if STANDA is not defined

void PrintError(void){}
void InitStanda(char Step){
	char message[STRLEN];
	sprintf(message,"STANDA functions not active. Please recompile TRS deleting #def NO_STANDA option in Measure.c");
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE,message);
	Failure("STANDA NOT PRESENT");
 	}
void CloseStanda(char Step){}
void SetVelStanda(char Step,double Freq){}
void MoveStanda(char Step,long Goal,char Wait){}
void WaitStanda(char Step,long Goal){}
void TellPosStanda(char Step,long *Actual){}
void StopStanda(char Step){}
void DefineHomeStanda(char Step){}

#endif


// #### STANDA2 STEPPER ####
	
/* INITIALIZE STANDA2 */
void InitStanda2(char Step){
	device_t device;
	char message[STRLEN];
	engine_settings_t engine_settings;
	status_t state;
	result_t result;
	char device_name[STRLEN];
	int com=P.Step[Step].Com;

	sprintf(message,"Initializing STANDA2 Stepper #%d on Com%d",Step+1,com);
   	SetCtrlVal (hDisplay, DISPLAY_MESSAGE,message);
	
 	sprintf(device_name,"%s%d","\\\\.\\Com",com);
	device = open_device( device_name );
	if ((result = get_status( device, &state )) != result_ok)  Failure("Failure on getting status\n");
	P.Step[Step].Standa2.Device=device;
	if ((result = get_engine_settings( device, &engine_settings )) != result_ok) Failure("Failure on engine settings\n");
    
	SetCtrlVal (hDisplay, DISPLAY_MESSAGE," PASSED\n");
	}


/* CLOSE STANDA2 */
void CloseStanda2(char Step){
	device_t device=P.Step[Step].Standa2.Device;
	result_t result;
	if ((result = close_device( &device )) != result_ok) Failure("Error closing Standa2\n");
	}


/* SET FREQUENCY STANDA2 */	
void SetVelStanda2(char Step, double Freq){
	device_t device=P.Step[Step].Standa2.Device;
	move_settings_t move_settings;
	get_move_settings(device, &move_settings);
	move_settings.Speed=Freq;
	set_move_settings(device, &move_settings);
	}


/* MOVE STANDA2 */
void MoveStanda2(char Step,long Goal,char Wait){
	device_t device=P.Step[Step].Standa2.Device;
	result_t result;

	if(Goal==P.Step[Step].Actual) return;
   	if ((result = command_move(device,Goal-P.Step[Step].Standa2.DeltaHome,0)) != result_ok) Failure("Error Movement\n");
	if(Wait) WaitStanda2(Step,Goal); 
	}


/* WAIT END OF STANDA2 MOVEMENT */
void WaitStanda2(char Step,long Goal){
	//device_t device=P.Step[Step].Standa2.Device;
	//status_t status;
	//int moving;

	/*do{
		get_status(device,&status);
		//moving=(status.MoveSts&MOVE_STATE_MOVING);
		moving=(status.MvCmdSts&MVCMD_RUNNING);
		}
	while(moving);*/
	do TellPosStanda2(Step,&P.Step[Step].Actual);
	while(P.Step[Step].Actual!=Goal);
	} 


/* TELL POSITION STANDA2 */
void TellPosStanda2(char Step,long *Actual){
	device_t device=P.Step[Step].Standa2.Device;
	result_t result;
	get_position_t positionS;
   	if ((result = get_position(device,&positionS))!=result_ok) Failure("Error Tell Pos\n");
	*Actual=positionS.Position+P.Step[Step].Standa2.DeltaHome;  // it returns the position in terms of position used in TRS, not internal absolute value of standa
	}


/* STOP STANDA2 */
void StopStanda2(char Step){
	device_t device=P.Step[Step].Standa2.Device;
	result_t result;
   	if ((result = command_sstp(device)) != result_ok) Failure("Error Soft Stop\n");
	TellPosStanda2(Step,&P.Step[Step].Actual);
	}


/* DEFINE HOME STANDA2 */
void DefineHomeStanda2(char Step){
	long actualStanda2;
	P.Step[Step].Standa2.DeltaHome=0;
	TellPosStanda2(Step,&actualStanda2);
	P.Step[Step].Standa2.DeltaHome=P.Step[Step].Home-actualStanda2;  // it rapresents the shift to be given to the internal Standa2 position to obtain the absolute TRS position
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
	//DAQmxCreateTask ("TaskModPower", &taskmodpower);
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
	//DAQmxCreateTask ("TaskModPower", &taskmodpower);
    DAQmxCreateAIVoltageChan (taskmodpower, "Dev1/ai0", " MOD_POWER ", DAQmx_Val_NRSE, -0.5, 0, DAQmx_Val_Volts, "");
	DAQmxStartTask (taskmodpower);
	DAQmxReadAnalogScalarF64 (taskmodpower, 10.0, &volt, 0);	
	DAQmxStopTask (taskmodpower);
	DAQmxClearTask (taskmodpower);
	P.Step[Step].Actual=(long)(volt*ADC_FACTOR);
}

//#### DELAYER_GATE STEPPER ####


/* INITIALIZE DELAYER BY PARALLEL PORT */
void InitDelayerGate(char Step){
	//char message[STRLEN],data;
	//char pstatus, data;
	//short status=0; short code=0;
	SetCtrlVal (hDisplay,DISPLAY_MESSAGE, "Initializing Parallel Port ... ");
	OpenComConfig (P.Step[Step].Com, "", 9600, 0, 8, 1, 512, 512);
	//data=0x00;
    //pstatus = outpw(DELAYER_GATE_COM, data);
	//sprintf(message,"Error Initializing the board #%d, error code %d",code,status);
    //if(status!=0) Failure(message); else Passed();
	Passed();
	}	   
	
void MoveDelayerGate(char Step,long Goal){
	int n = 0, is = 0;
	int num_read_actual1,num_read_actual2 ;
	const char *FILEPATH_CALIB = "C:\\Documents and Settings\\Laboratorio\\Desktop\\devTrs\\POS\\DELAYER_GATE.TXT";
	const char *FILEPATH_CALIB2 = "C:\\Documents and Settings\\Laboratorio\\Desktop\\devTrs\\POS\\DELAYER_GATE_Factor.TXT";
	const char *mode = "r";
	const char *type = "%f";
	float Goal_Delayer;
	FILE *fid, *fid2;
	P.Step[Step].Delay_Gate.Value = 0;
	fid = fopen(FILEPATH_CALIB, mode);
	fid2 = fopen(FILEPATH_CALIB2, mode);
	for (is = 0; is<N_BIT_DELAYER_GATE; is++){
	    num_read_actual1 = fscanf (fid2, type, &P.Step[Step].Delay_Gate.Calib_Factor[is]);
	}
	for (is = 0; is<N_BIT_DELAYER_GATE; is++){ 
	    num_read_actual2 = fscanf (fid, type, &P.Step[Step].Delay_Gate.Calib_Calib[is]);
	}
	Goal_Delayer = (float)Goal/1000;
	CalcStr(Goal_Delayer,Step,n);
	P.Step[Step].Actual=Goal;
	TalkDelayerStep(Step);
	Delay (SLEEP_DELAYER_GATE);
	fclose(fid); fclose(fid2); 	   
}
	
	
void CalcStr (float Goal, char Step, int n){
	if(Goal/(P.Step[Step].Delay_Gate.Calib_Calib[N_BIT_DELAYER_GATE-n-1])>=0.999){
		P.Step[Step].Delay_Gate.Str[n]=1;
		P.Step[Step].Delay_Gate.Value = P.Step[Step].Delay_Gate.Value + STEP_DELAYER_GATE*(P.Step[Step].Delay_Gate.Calib_Factor[N_BIT_DELAYER_GATE-n-1]);
		Goal = Goal - P.Step[Step].Delay_Gate.Calib_Calib[N_BIT_DELAYER_GATE-n-1];
	}
	else{
		P.Step[Step].Delay_Gate.Str[n]=0;
	}
	n = n + 1;
	if(n<N_BIT_DELAYER_GATE){
	CalcStr(Goal,Step,n);}
}
	
		
		
/* SEND COMMAND TO DELAYER_GATE*/
void TalkDelayerStep(char Step){
	char temp_string[50];
											  
    /* allocate a new string */
	//sprintf (temp_string,"%f",(float)P.Step[Step].Delay_Gate.Value/1000);
	sprintf (temp_string,"%f",(float)P.Step[Step].Delay_Gate.Value/100);
	sprintf (P.Step[Step].Delay_Gate.pChar, "XB");
	P.Step[Step].Delay_Gate.pChar[2]=temp_string[0];
	P.Step[Step].Delay_Gate.pChar[3]=temp_string[1];
	P.Step[Step].Delay_Gate.pChar[4]=temp_string[2];
	P.Step[Step].Delay_Gate.pChar[5]=temp_string[3];
	P.Step[Step].Delay_Gate.pChar[6]=temp_string[4];
	P.Step[Step].Delay_Gate.pChar[7]= 'Y';
    //string = StrDup("XY"); 
	//error = sprintf (temp_string, "%f", P.Step[Step].Delay_Gate.Value);
	//error = AppendString (&string, temp_string, -1);
	//strcpy (P.Step[Step].Delay_Gate.pChar, string);
	//P.Step[Step].Delay_Gate.pChar[7]='Y';
	ComWrt(P.Step[Step].Com,P.Step[Step].Delay_Gate.pChar,8);
	}

// #### NKT COMMUNICATION ####


void InitNKTLambda(char Step){
	char message[STRLEN];
	int com=P.Step[Step].Com;
	long WaveShort,WaveLong;
	sprintf(message,"Initializing NKTLambda Communication #%d on COM%d\n",Step+1,com);
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE,message);
	if(OpenComConfig (com, "", NKT_BAUDRATE, NKT_PARITY, NKT_DATABITS, NKT_STOPBITS, 4096, 4096)<0)
		SetCtrlVal (hDisplay, DISPLAY_MESSAGE,"Init Com Error\n");
	
	//SetComTime (ComNum, 0.05);
	//SetCTSMode (ComNum, LWRS_HWHANDSHAKE_OFF);
	ReadNKTLimits(Step, &WaveShort, &WaveLong);
//	if(LoopFirst.....)
//		Failure("NKT AOTF works from %i nm to %i nm");
	FlushInQ (com);
	FlushOutQ (com);
}
	
void InitNKTPow(char Step){
	char message[STRLEN];
	int com=P.Step[Step].Com;
	
	sprintf(message,"Initializing NKTPower Communication #%d on COM%d\n",Step+1,com);
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE,message);
	if(OpenComConfig (com, "", NKT_BAUDRATE, NKT_PARITY, NKT_DATABITS, NKT_STOPBITS, 4096, 4096)<0)
		SetCtrlVal (hDisplay, DISPLAY_MESSAGE,"Init Com Error\n");
	
	//SetComTime (ComNum, 0.05);
	//SetCTSMode (ComNum, LWRS_HWHANDSHAKE_OFF);
	FlushInQ (com);
	FlushOutQ (com);
}
	
void CloseNKTLambda(char Step){
	int com=P.Step[Step].Com;
	
	FlushInQ (com);
	FlushOutQ (com);
	CloseCom(com);
}
	

void CloseNKTPow(char Step){
	int com=P.Step[Step].Com;
	
	FlushInQ (com);
	FlushOutQ (com);
	CloseCom(com);
}

unsigned short calcCRC16(unsigned char data, unsigned short crc) 
{
        crc  = (unsigned short)((crc >> 8) | (crc << 8));
        crc ^= data;
        crc ^= (unsigned char)((crc & 0xff) >> 4);
        crc ^= (unsigned short)((crc << 8) << 4);
        crc ^= (unsigned short)(((crc & 0xff) << 4) << 1);
return crc;
}

void addToTxMsgData(unsigned char *txBuffer,int *txBufferSize,unsigned short *txCRC,unsigned char data, unsigned int escParse, unsigned int updCRC)
{
	if (updCRC)
		*txCRC=calcCRC16(data,*txCRC);
	if (escParse)
	{
		if(data == NKT_SOT || data == NKT_EOT || data == NKT_SOE)
     	{
		    txBuffer[*txBufferSize]=NKT_SOE;
			if(*txBufferSize<NKT_TXBUFFERSIZE) (*txBufferSize)++;
			
		 	data += NKT_ECC;
		}
	}
	txBuffer[*txBufferSize]=data;
	if(*txBufferSize<NKT_TXBUFFERSIZE) (*txBufferSize)++; 
		
	 
} 

void rx(char Step, unsigned char *rxBuffer){
	int com=P.Step[Step].Com;
	char ch=-94;
	short TelegramReady, Inframe, Escape_seq1=0; // boolean
	unsigned char rx_counter, *rxPtr;//, RcBuffer[260], *RcInPtr1;
	unsigned short crc1;
	//while(ReturnRS232Err ()>-1)
	while(ch!=NKT_EOT)
	{
		ch = ComRdByte (com); // Get byte from UART
		switch(ch)
		{
			case NKT_SOT: 							 // New telegram
				rx_counter = 0;
				Inframe=1;
				crc1 = 0;
				rxPtr = &rxBuffer[0];
				TelegramReady = 0;
			break;
			
			case NKT_EOT: 							 // End of telegram
				Inframe=0;
				if(crc1 == 0) TelegramReady = 1; // CRC ok and telegram is ready
			break;

			case NKT_SOE: 							 // start of escape sequence
				Escape_seq1 = 1;
			break;

			default: 							 // Data byte
				if(Inframe==1)
				{
					if(Escape_seq1 == 1)
					{
						Escape_seq1 = 0;
						ch -= NKT_ECC;
					}
					crc1 = calcCRC16(ch, crc1);
					*rxPtr = ch;
					if(rx_counter < NKT_TXBUFFERSIZE+20)
					{
						rxPtr++;
						rx_counter++;
					}
				}
			break;
		}
	}
}	

void NKTSendMessage(char Step,void *Value, unsigned char Dest, unsigned char Source, unsigned char Type,unsigned char Register, unsigned int DataType){
	int com=P.Step[Step].Com;
	int txBufferSize=0;
	unsigned char txBuffer[NKT_TXBUFFERSIZE];
	unsigned short txCRC=0;
	long *p_U32;
	int *p_U16;
	
	addToTxMsgData(txBuffer,&txBufferSize,&txCRC,NKT_SOT,0,0);					// Start of Telegram
	
	addToTxMsgData(txBuffer,&txBufferSize,&txCRC,Dest,1,1);						// Destination
	addToTxMsgData(txBuffer,&txBufferSize,&txCRC,Source,1,1);					// Source
	addToTxMsgData(txBuffer,&txBufferSize,&txCRC,Type,1,1);			 			// Transmitting type
	
	addToTxMsgData(txBuffer,&txBufferSize,&txCRC,Register,1,1);					// Register
	
	switch (DataType)
	{
		case NKT_U32:
			
			p_U32=(long *)Value;
			addToTxMsgData(txBuffer,&txBufferSize,&txCRC,(*p_U32) & 0xFF,1,1);				// Wavelength (pm)
			addToTxMsgData(txBuffer,&txBufferSize,&txCRC,((*p_U32)>>8) & 0xFF,1,1);
			addToTxMsgData(txBuffer,&txBufferSize,&txCRC,((*p_U32)>>16) & 0xFF,1,1);
			addToTxMsgData(txBuffer,&txBufferSize,&txCRC,((*p_U32)>>24) & 0xFF,1,1);
			
			
		break;
		case NKT_U16:
			p_U16=(int *)Value;
			addToTxMsgData(txBuffer,&txBufferSize,&txCRC,(*p_U16) & 0xFF,1,1);				// Power
			addToTxMsgData(txBuffer,&txBufferSize,&txCRC,((*p_U16)>>8) & 0xFF,1,1);
		break;
			
			
			
		default:
			break;
	}
	
	
	
	addToTxMsgData(txBuffer,&txBufferSize,&txCRC,(txCRC>>8) & 0xFF,1,0);		// CRC high byte
	addToTxMsgData(txBuffer,&txBufferSize,&txCRC,txCRC & 0xFF, 1, 0);			// CRC low byte
	
	addToTxMsgData(txBuffer,&txBufferSize,&txCRC,NKT_EOT,0,0);					// End of Telegram 
				 
	if (ComWrt (com, (const char*)txBuffer, txBufferSize)!=txBufferSize)
		 {
			SetCtrlVal (hDisplay, DISPLAY_MESSAGE,"NKTLambda Telegram Transmission Error\n");		 
		 }
	
}	
	
void SetNKTLambda(char Step,long Goal){
	
	unsigned char rxBuffer[NKT_TXBUFFERSIZE+20];
	
	Goal=(unsigned long)(Goal*1000);											// nanometers to picometers
	NKTSendMessage(Step,&Goal, NKT_DESTINATION, NKT_SOURCE, NKT_WRITE_REG,NKT_LAMBDA_REG,NKT_U32);
	rx(Step,rxBuffer);
}

void SetNKTPow(char Step,long Goal){
	
	unsigned char rxBuffer[NKT_TXBUFFERSIZE+20];
	
	Goal=(unsigned int) Goal;
	NKTSendMessage(Step,&Goal, NKT_DESTINATION, NKT_SOURCE, NKT_WRITE_REG,NKT_POW_REG,NKT_U16);				 
	rx(Step,rxBuffer);
}
	
void ReadNKTLimits(char Step, long *WaveShort, long *WaveLong){
	unsigned char rxBuffer[NKT_TXBUFFERSIZE+20];
	
	NKTSendMessage(Step,NULL, NKT_DESTINATION, NKT_SOURCE, NKT_READ_REG,NKT_LAMBDA_MIN,NONE);
	rx(Step,rxBuffer);
	*WaveShort=0;
	(*WaveShort)|=rxBuffer[7] & 0xFF;    //MSB
	(*WaveShort)<<=8;
	(*WaveShort)|=rxBuffer[6] & 0xFF;
	(*WaveShort)<<=8;
	(*WaveShort)|=rxBuffer[5] & 0xFF;
	(*WaveShort)<<=8;
	(*WaveShort)|=rxBuffer[4] &0xFF;
	*WaveShort=(unsigned long)((*WaveShort)/1000);
	
	NKTSendMessage(Step,NULL, NKT_DESTINATION, NKT_SOURCE, NKT_READ_REG,NKT_LAMBDA_MAX,NONE);
	rx(Step,rxBuffer);
	*WaveLong=0;
	(*WaveLong)|=rxBuffer[7] & 0xFF;    //MSB
	(*WaveLong)<<=8;
	(*WaveLong)|=rxBuffer[6] & 0xFF;
	(*WaveLong)<<=8;
	(*WaveLong)|=rxBuffer[5] & 0xFF;
	(*WaveLong)<<=8;
	(*WaveLong)|=rxBuffer[4] &0xFF;
	*WaveLong=(unsigned long)((*WaveLong)/1000);
				 
}

	
	

// #### DELAYER STEPPER ####
	
/* INITIALIZE DELAYER */
void InitDelayer(char Step){
	char message[STRLEN];
	char *byte1="/0";
	short status=0;
	short open;
	int pos=0;
	int com=P.Step[Step].Com;
	
	sprintf(message,"Initializing DELAYER #%d on COM %d",Step+1,com);
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE,message);
	
	sprintf(byte1,"%c",(char)pos);
	
	open=OpenComConfig(com,NULL,DELAYER_BAUDRATE,DELAYER_PARITY,DELAYER_DATABITS,DELAYER_STOPBITS,0,-1);
	FlushInQ (com);
	FlushOutQ (com);
	status+=ComWrt(com,"XA",2);
	status+=ComWrt(com,byte1,1);
	status+=ComWrt(com,"Y",1);
	//TRADNIDAQ status = Init_DA_Brds (2, &code);
	//TRADNIDAQ status = DIG_Prt_Config (2, 0, 0, 1);
	//TRADNIDAQ status = DIG_Prt_Config (2, 1, 0, 1);
	
	sprintf(message,"Error Initializing the DELAYER #%d, error code %d",Step+1,status);
	//P.Step[Step].Actual=9999999; //Just to let it move
	//MoveDelayer(Step,P.Step[Step].Home);
    if(status==0) Failure(message); else Passed();
	}


/* MOVE DELAYER */
void MoveDelayer(char Step,long Goal){
	char *byte1="/0";
	short status=0;
	int pos;
	//int open;
	int com=P.Step[Step].Com;
	
	if(P.Step[Step].Actual==Goal) return;
	
	pos=(Goal/25);
	sprintf(byte1,"%c",(char)pos);
	
	//open=OpenComConfig(com,NULL,DELAYER_BAUDRATE,DELAYER_PARITY,DELAYER_DATABITS,DELAYER_STOPBITS,0,-1);
	//FlushInQ (com);
	//FlushOutQ (com);
	
	status+=ComWrt(com,"XA",2);
	status+=ComWrt(com,byte1,1);
	status+=ComWrt(com,"Y",1);
	
	
	//byte2=(char) (Goal/256);
	//byte1=(char) (Goal-byte2*256);
	//TRADNIDAQ status = DIG_Out_Prt (2, 0, byte1);
	//TRADNIDAQ status = DIG_Out_Prt (2, 1, byte2);
	Delay(3);
	P.Step[Step].Actual=Goal;
	
	   
	}

void CloseDelayer(char Step){
	int com=P.Step[Step].Com;
    
	
	FlushInQ (com);
	FlushOutQ (com);
	CloseCom (com);
	}



// #### DELAYER STEPPER ####
	
/* INITIALIZE DELAYER */
/*void InitDelayer(char Step){
	char message[STRLEN];
	char *byte1="/0";
	short status=0;
	short open;
	int pos=0;
	int com=P.Step[Step].Com;
	
	
	sprintf(message,"Initializing DELAYER #%d on COM %d",Step+1,com);
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE,message);
	sprintf(byte1,"%c",(char)pos);
	open=OpenComConfig(com,NULL,DELAYER_BAUDRATE,DELAYER_PARITY,DELAYER_DATABITS,DELAYER_STOPBITS,0,-1);
	FlushInQ (com);
	FlushOutQ (com);
	status+=ComWrt(com,"XA",2);
	status+=ComWrt(com,byte1,1);
	status+=ComWrt(com,"Y",1);
	sprintf(message,"Error Initializing the DELAYER #%d, error code %d",Step+1,status);
    if(status==0) Failure(message); else Passed();
	sprintf(message,"Moving DELAYER to Home=%d\n",P.Step[Step].Home);
    SetCtrlVal (hDisplay, DISPLAY_MESSAGE,message);
	P.Step[Step].Actual=P.Step[Step].Home+DELAYER_JUMP*DELAYER_DELTA;
	MoveDelayer(Step,P.Step[Step].Home);
	}
*/

/* MOVE DELAYER */
/*void MoveDelayer(char Step,long Goal){
	char *byte1="/0";
	short status=0;
	int pos;
	int com=P.Step[Step].Com;
	
	if(P.Step[Step].Actual==Goal) return;
	pos=(Goal/DELAYER_DELTA);
	sprintf(byte1,"%c",(char)pos);
	status+=ComWrt(com,"XA",2);
	status+=ComWrt(com,byte1,1);
	status+=ComWrt(com,"Y",1);
	Delay(DELAYER_WAIT);
	P.Step[Step].Actual=Goal;
	}
*/
/* CLOSE DELAYER */
/*void CloseDelayer(char Step){
	int com=P.Step[Step].Com;
	
	FlushInQ (com);
	FlushOutQ (com);
	CloseCom (com);
	}
*/


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
	int com=P.Step[Step].Com;
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
	int com=P.Step[Step].Com;
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

	com=P.Step[Step].Com;
    TalkPwm(com, PWM_SETSPEED, frq, &ret);
}


/* MOVE PWM */
void MovePwm(char Step,long Goal,char Wait)
{
    int ret;
	int com=P.Step[Step].Com;

    if(Goal == P.Step[Step].Actual) return;

    TalkPwm(com, PWM_ABS_GOTO, Goal, &ret);
    //if(Wait) WaitPwm(Step, Goal);
}

/* WAIT END OF PWM MOVEMENT 
void WaitPwm(char Step,long Goal)
{
	long actual;
	int com=P.Step[Step].Com;
	GetMicro(com,&actual);
	P.Step[Step].Actual=actual;
}
*/

/* TELL POSITION PWM */
void TellPosPwm(char Step,long *Actual)
{
	int com=P.Step[Step].Com;
    TalkMicro(com, PWM_TELL, 0, Actual);
}


/* STOP PWM */
void StopPwm(char Step)
{
    int ret;
	int com=P.Step[Step].Com;

    TalkMicro(com, PWM_STOP, 0, &ret);
	TellPos(Step, &P.Step[Step].Actual);
}


/* DEFINE HOME PWM */
void DefineHomePwm(unsigned int Step)
{
    int ret;
	int com=P.Step[Step].Com;

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
	int com=P.Step[Step].Com;
	
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
	int com=P.Step[Step].Com;
      
    MoveMono(Step,P.Step[Step].Home,1); // chiedere a Antonio se gli va bene; probabilmente ridondante
    FlushInQ (com);
	FlushOutQ (com);
	CloseCom (com);
	}


/* SET FREQUENCY MONO */	
void SetVelMono(char Step, double Freq){
	int ret;
	int com=P.Step[Step].Com;
    TalkMono(com,MONO_VEL,(int) (Freq) * MONO_SEC_TO_MIN,&ret);
    GetMono(com,&ret);
	}


/* MOVE MONO */
void MoveMono(char Step,long Goal,char Wait){
	int ret;
	int com=P.Step[Step].Com;
	if(Goal==P.Step[Step].Actual) return;
    TalkMono(com,MONO_GOTO,Goal * MONO_NM_TO_AMG,&ret);
	if(Wait) WaitMono(Step,Goal);
	}



/* WAIT END OF MONO MOVEMENT */
void WaitMono(char Step,long Goal){

    double timeout;
    int ret; 
	int com=P.Step[Step].Com;
	
	timeout=((abs(Goal-P.Step[Step].Actual))/P.Step[Step].Freq)+MONO_TIMEOUT_OFFSET;
	SetComTime(com,timeout);
	GetMono(com,&ret);  
	SetComTime(com,MONO_TIMEOUT);
	TellPosMono (Step,&P.Step[Step].Actual);		 /* chiedere Antonio*/
	}


/* TELL POSITION MONO */
void TellPosMono(char Step,long *Actual){
	int com=P.Step[Step].Com;
	
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
	int com=P.Step[Step].Com;
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
	int com=P.Step[Step].Com;
	
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
	int com=P.Step[Step].Com;
    TalkFpm(com, FPM_STOPMEAS, 0, &ret);
	FlushInQ (com);
	FlushOutQ (com);
	CloseCom (com);
	}


/* Tell FPM to stop sending data */
void StopFpm(char Step){
	long answer;
	int com=P.Step[Step].Com;
    TalkFpm(com, FPM_STOPMEAS, 0, &answer);
	
	}


/* ASK FPM FOR LASER INTENSITY */
void MoveFpm(char Step,long Goal){
	int com=P.Step[Step].Com;
    TalkFpm(com, FPM_GETSINGLE, 0, &P.Step[Step].Actual);
	}

/* ASK FPM FOR LASER INTENSITY */
/*void TellPosFpm(char Step,long *Actual){
    int com=P.Step[Step].Com;
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
    P.Step[P.Power.Step].Actual_mean_pow=0;
	P.Step[P.Power.Step].Actual_std=0;
	}


/* START ADC ACQUISITION */
void StartAdc(void){
	//TaskHandle	taskmodpower=0; 
	short status = 0;
	status = DAQmxCreateTask ("", &P.Power.Adc.taskmodpower_diode);
    if(status!=0) Failure(GetDAQErrorString(status));
	status = DAQmxCreateAIVoltageChan (P.Power.Adc.taskmodpower_diode, "Dev1/ai0", "", DAQmx_Val_RSE, -0.3, 0.0, DAQmx_Val_Volts, NULL);
    if(status!=0) Failure(GetDAQErrorString(status));
    status = DAQmxSetChanAttribute (P.Power.Adc.taskmodpower_diode, NULL, DAQmx_AI_DataXferReqCond,DAQmx_Val_OnBrdMemNotEmpty);    
    if(status!=0) Failure(GetDAQErrorString(status));
	status = DAQmxSetChanAttribute (P.Power.Adc.taskmodpower_diode, NULL, DAQmx_AI_DataXferMech,DAQmx_Val_USBbulk);
	if(status!=0) Failure(GetDAQErrorString(status));
	//status = DAQmxCfgSampClkTiming (P.Power.Adc.taskmodpower_diode, "OnboardClock", 5000, DAQmx_Val_Rising, DAQmx_Val_ContSamps,10000*P.Spc.TimeM);
    status = DAQmxCfgSampClkTiming (P.Power.Adc.taskmodpower_diode, "", 20000, DAQmx_Val_Rising, DAQmx_Val_ContSamps,100000);
    if(status!=0) Failure(GetDAQErrorString(status));
	//status = DAQmxCfgInputBuffer (taskmodpower, 10000);
	//DAQmxSetTimingAttribute (P.Power.Adc.taskmodpower_diode, DAQmx_SampClk_UnderflowBehavior,DAQmx_Val_PauseUntilDataAvailable);
	DAQmxSetReadAttribute (P.Power.Adc.taskmodpower_diode, DAQmx_Read_ReadAllAvailSamp, TRUE);
	DAQmxSetReadAttribute (P.Power.Adc.taskmodpower_diode, DAQmx_Read_AutoStart, FALSE);
	DAQmxSetReadAttribute (P.Power.Adc.taskmodpower_diode, DAQmx_Read_RelativeTo, DAQmx_Val_CurrReadPos);
	DAQmxSetReadAttribute (P.Power.Adc.taskmodpower_diode, DAQmx_Read_WaitMode, DAQmx_Val_Yield);
	//if(status!=0) Failure(GetDAQErrorString(status));
	//OpenComConfig (1, "", 110, 0, 7, 1, 10, 10);
	status=DAQmxStartTask (P.Power.Adc.taskmodpower_diode);
	if(status!=0) Failure(GetDAQErrorString(status));
	//status = DAQmxReadAnalogF64 (P.Power.Adc.taskmodpower_diode, 10000, 10, DAQmx_Val_GroupByChannel, P.Power.Adc.Data, 50000*P.Spc.TimeM, &num_read, 0);
	//**sprintf(message,"AICheckAcquisition = %d\n",scanBacklog);
    //**SetCtrlVal (hDisplay, DISPLAY_MESSAGE,message);
    //P.Step[P.Power.Step].Actual=(long)(value*ADC_FACTOR);
	//**sprintf(message,"Status = %d, Data0=%lf, value=%lf\n",status,P.Power.Adc.Data[0],value);
    //**SetCtrlVal (hDisplay, DISPLAY_MESSAGE,message);
    //status = AIClearAcquisition (P.Power.Adc.Task);
    //if(status!=0) Failure(GetDAQErrorString(status));
    }
    
    
/* STOP ADC ACQUISITION */
void WaitAdc(void){
	short status;
	double stdev,value;
	int num_read = 0;
	//double stdev,value;
	//status = DAQmxStopTask (P.Power.Adc.taskmodpower_diode);
	//if(status!=0) Failure(GetDAQErrorString(status));
	//status = DAQmxReadAnalogF64 (taskmodpower, P.Spc.TimeM*120, 10.0, DAQmx_Val_GroupByScanNumber, P.Power.Adc.Data, P.Spc.TimeM*200, &num_read, 0);
	status = DAQmxReadAnalogF64 (P.Power.Adc.taskmodpower_diode, -1, 0, DAQmx_Val_GroupByChannel, P.Power.Adc.Data, 100000, &num_read, 0);
	if(status!=0) Failure(GetDAQErrorString(status));
	status = DAQmxStopTask (P.Power.Adc.taskmodpower_diode);
    if(status!=0) Failure(GetDAQErrorString(status));
	//status = DAQmxStopTask (taskmodpower);
    //if(status!=0) Failure(GetDAQErrorString(status));
	StdDev (P.Power.Adc.Data, num_read, &value, &stdev);
	P.Step[P.Power.Step].Actual_mean_pow=(long)(value*ADC_FACTOR);
	P.Step[P.Power.Step].Actual_std=(long)(stdev*ADC_FACTOR);
	P.Step[P.Power.Step].Actual=(long)(value*ADC_FACTOR);
	status = DAQmxClearTask (P.Power.Adc.taskmodpower_diode);
    if(status!=0) Failure(GetDAQErrorString(status));
	//status=nidaqAIStop (P.Power.Adc.Task);
    //if(status!=0) Failure(GetDAQErrorString(status));
	//status = nidaqAIRead (P.Power.Adc.Task, "", 1000, -1.0, P.Power.Adc.Data);
    //if(status!=0) Failure(GetDAQErrorString(status));
	//status = StdDev (P.Power.Adc.Data, 1000, &value, &stdev);
    //if(status!=0) Failure(GetDAQErrorString(status));
    //P.Step[P.Power.Step].Actual=(long)(value*ADC_FACTOR);
    
    }


/* STOP ADC ACQUISITION */
void StopAdc(void){
	//short status;
	//double stdev,value;
	//char message[STRLEN];
	
	//status=nidaqAIStop (P.Power.Adc.Task);
    //if(status!=0) Failure(GetDAQErrorString(status));
	//status = nidaqAIRead (P.Power.Adc.Task, "", 1000, -1.0, P.Power.Adc.Data);
    //if(status!=0) Failure(GetDAQErrorString(status));
	//status = StdDev (P.Power.Adc.Data, 1000, &value, &stdev);
    //if(status!=0) Failure(GetDAQErrorString(status));
    //P.Step[P.Power.Step].Actual=(long)(value*ADC_FACTOR);
    
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
	int ic,ifr,ip,id,ib;			
/*
	do {
		P.File.File = fopen(P.File.Path, "ab");
		}
	while(P.File.File == NULL);
*/	
	if(!P.Action.CheckEdge){
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
	else {
	// patch
    	P.Frame.Last=P.Frame.Actual; //non eliminare
	
	
	
	if(P.Mamm.Shrink[X]){
	for(ifr=P.Frame.First;ifr<P.Frame.Last+1||ifr>P.Frame.Last-1;ifr=ifr+(REMINDER(P.Loop[P.Mamm.Loop[Y]].Idx,2)?-1:1))
		for(ip=0;ip<P.Num.Page;ip++){
			if(REMINDER(P.Loop[P.Mamm.Loop[Y]].Idx,2)==0){
			if(P.Info.SubHeader) while(fwrite (&D.Sub[ifr][ip], sizeof(T_SUB), 1, P.File.File)<1);
			while(fwrite(D.Data[ifr][ip],sizeof(T_DATA),P.Chann.Num,P.File.File)<P.Chann.Num);
			}
			else {
			if(P.Info.SubHeader) while(fwrite (&D.Sub[P.Frame.Max-ifr-1][ip], sizeof(T_SUB), 1, P.File.File)<1);
			while(fwrite(D.Data[P.Frame.Max-ifr-1][ip],sizeof(T_DATA),P.Chann.Num,P.File.File)<P.Chann.Num);
			}
		}
	FILE *fid;
	char path[STRLEN];
	sprintf(path, "%s\\%s.%s",P.File.Dir,P.File.Name,"txt");
	fid=fopen(path,"a+");
	fprintf(fid,"%d\t%d\%d",P.Frame.First+1,P.Frame.Last+1,P.Loop[P.Mamm.Loop[Y]].Idx);
	fclose(fid);
	
	}
	else{
		for(ifr=0;ifr<P.Frame.Max;ifr++)
		for(ip=0;ip<P.Num.Page;ip++){
			if(REMINDER(P.Loop[P.Mamm.Loop[Y]].Idx,2)==0){
			if(P.Info.SubHeader) while(fwrite (&D.Sub[ifr][ip], sizeof(T_SUB), 1, P.File.File)<1);
			while(fwrite(D.Data[ifr][ip],sizeof(T_DATA),P.Chann.Num,P.File.File)<P.Chann.Num);
			}
			else {
			if(P.Info.SubHeader) while(fwrite (&D.Sub[P.Frame.Max-ifr-1][ip], sizeof(T_SUB), 1, P.File.File)<1);
			while(fwrite(D.Data[P.Frame.Max-ifr-1][ip],sizeof(T_DATA),P.Chann.Num,P.File.File)<P.Chann.Num);
			
			}
		}
	}
	
	fflush(P.File.File);
//	fclose(P.File.File);
	for(ifr=0;ifr<P.Frame.Max;ifr++)
		for(ip=0;ip<P.Num.Page;ip++)
			for(ic=0;ic<P.Chann.Num;ic++)
				D.Data[ifr][ip][ic]=0;

	P.Frame.First=P.Frame.Last; //si può anche eliminare... non me ne faccio nulla
	
		
	}
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
	for(il=0;il<MAX_LOOP-2;il++){
		D.Head.LoopHome[il]=P.Loop[il+2].Home;
		D.Head.LoopFirst[il]=P.Loop[il+2].First;
		D.Head.LoopLast[il]=P.Loop[il+2].Last;
		D.Head.LoopDelta[il]=P.Loop[il+2].Delta;
		D.Head.LoopNum[il]=P.Loop[il+2].Num;
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


/* INITIALIZATION FAILURE */
void PrintValue(double value, char* Text){
    char message[10*STRLEN];
    sprintf(message,"%s=%f\n",Text,value);
	SetCtrlVal (hDisplay, DISPLAY_MESSAGE, message);
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
		case ERR_HYDRA:
			HH_GetErrorString(serror, Code);
			strcpy (sdevice, "HYDRA");
			break;
		case ERR_TH260:
			TH260_GetErrorString(serror, Code);
			strcpy (sdevice, "TH260");
			break;
		case ERR_SC1000:
			sc_get_err_msg(Code, serror); 
			strcpy (sdevice, "SC1000");
			break;
		case ERR_GENERIC:
			strcpy (serror, Function); 
			strcpy (sdevice, "GENERIC ERROR");
			break;
		}
	/*patch*///sprintf(smessage,"Device = %s\nFunction = %s\nMessage = %s",sdevice,Function,serror);
	sprintf(smessage,"Device = %s\nFunction = %s\nMessage = %s\nContest = %d\nTrash = %d",sdevice,Function,serror,P.Contest.Function,P.Spc.Trash); 
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

// Allocate 1D Array of SC1000_TYPE
SC1000_TYPE *SC1000Alloc1D(int Num1){
	SC1000_TYPE *d;
	d=(SC1000_TYPE*)calloc(Num1, sizeof(SC1000_TYPE));
	if(!d) ErrHandler(ERR_MEM,0,"Allocation Failure of 1D SC1000");
	return d;
	}

// Allocate 1D Array of double
double *doubleAlloc1D(int Num1){
	double *d;
	d=(double*)calloc(Num1, sizeof(double));
	if(!d) ErrHandler(ERR_MEM,0,"Allocation Failure of 1D double");
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

// Allocate 3D Array of double
double ***doubleAlloc3D(int Num1, int Num2, int Num3){
	int i1,i2;
	double ***d;
	d=(double***)calloc(Num1,sizeof(double**));
	if(!d) ErrHandler(ERR_MEM,0,"Allocation Failure of 3D double, Stage 1");
	for(i1=0;i1<Num1;i1++){
		d[i1]=(double**)calloc(Num2,sizeof(double*));
		if(!d[i1]) ErrHandler(ERR_MEM,0,"Allocation Failure of 3D double, Stage 2");
		for(i2=0;i2<Num2;i2++){
			d[i1][i2]=(double*)calloc(Num3,sizeof(double));
			if(!d[i1][i2]) ErrHandler(ERR_MEM,0,"Allocation Failure of 3D double, Stage 3");
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

// Free 1D Array of SC1000
void SC1000Free1D(SC1000_TYPE *D){
	free((char*) (D));
	}

// Free 1D Array of double
void doubleFree1D(double *D){
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

// Free 3D Array of double
void doubleFree3D(double ***D, int Num1, int Num2){
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
	int IdName,IdThick;
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


/*Patch checkmamm*/

void AnalysisMamm_new(void){
	int ib,id,ic;
	for(ib=0;ib<P.Num.Board;ib++) P.Mamm.Count.Actual[ib]=0; 
	for(ib=0;ib<P.Num.Board;ib++)
		for(id=0;id<P.Num.Det;id++)
		 	for(ic=0;ic<P.Chann.Num;ic++)
			  P.Mamm.Count.Actual[ib]+=D.Buffer[ib][ic+id*P.Chann.Num];
	
	for(ib=0;ib<P.Num.Board;ib++){
			P.Mamm.Rate.Actual[ib]=P.Mamm.Count.Actual[ib]/P.Spc.TimeM; //Antonio. P.Spc.TimeM o P.Spc.EffTime[ib]
			P.Spc.CountRate=P.Mamm.Rate.Actual[ib];
	        P.Mamm.OverTreshold=P.Mamm.OverTreshold||P.Mamm.Rate.Actual[ib]>P.Mamm.Rate.High[ib]||P.Mamm.Rate.Actual[ib]<P.Mamm.Rate.Low[ib];
	}


}
void StartMammot(void){
	int stepx=P.Mamm.Step[X];
	int loopx=P.Mamm.Loop[X];
	int is,ifr,ic,ib,id;
	
	P.Mamm.PhysicalBorder=70;
	//pulisci memoria TDC
	P.Spc.Trash=1;
	SpcReset(P.Action.Status,P.Meas.Clear,P.Meas.Stop);
    //sposta il probe alla prima posizione	
	double freq=fabs(P.Step[stepx].Delta)/(P.Spc.TimeM*P.Loop[P.Step[stepx].Loop].Num);
	if(freq!=P.Step[stepx].FreqActual) SetVel(stepx,freq);
	long stopgoal=P.Loop[loopx].First*P.Step[stepx].Factor;
	MoveStep(&P.Step[stepx].Actual,stopgoal,stepx,FALSE,P.Action.Status);
	
		
	for(is=0;is<(int) abs(P.Loop[loopx].First/P.Loop[loopx].Delta);is++){
       SpcOut(P.Action.Status);
	   //if(P.Mamm.OverTreshold&&(is> (int) abs(P.Loop[loopx].First/P.Loop[loopx].Delta)/2)){
	   if(is> (abs(P.Mamm.PhysicalBorder) -(10/P.Loop[loopx].Delta))){	   //(int) abs(P.Loop[loopx].First/P.Loop[loopx].Delta)/2 è per evitare che si blocchi
		   AnalysisMamm_new();
		   // quando trova un qualcosa di assorbente lungo la prima riga. da sost con
		   // abs(P.Loop[loopx].First/P.Loop[loopx].Delta)-15?
		   if(P.Mamm.OverTreshold){
		   StopStep(stepx);
	   	   break;
		   }
	       } 
    	}
	
	 long posx;
	 TellPos(stepx,&posx);
	 is=/*floor?*/abs(posx/P.Step[stepx].Factor);
	 
	 //preparo la fila di dati e compilo correttamente i sub
	 // necessaria? si, perchè se mi fermo prima con il bordo, i dati rimanenti nella linea non sono compilati bene
	 // non è necessaria nella modalità shrink
	 for(ib=0;ib<P.Num.Board;ib++){
		 for(id=0;id<P.Num.Det;id++){
			 for(ic=0;ic<P.Chann.Num;ic++){ 
		        D.Buffer[ib][ic+id*P.Chann.Num]=0;
	            D.Data[P.Frame.Actual][id][ic]=0;
				
			 }
			if(P.Info.SubHeader) CompileSub(P.Ram.Actual,P.Frame.Actual,id);
		 }
	 }
				
	
	 for(ifr=0;ifr<P.Loop[loopx].Num;ifr++){//se lo lascio così posso mettere in data save da 0 a frame.max
		 P.Frame.Actual=ifr;		  // funziona bene per NON shrink
		 DataCopy();
	 }
	 // p.frame.num è p.loop.num se attivo APPL_MAMM in compileparams
	 P.Frame.First=abs(P.Loop[loopx].First)-is;  //0 based 
	
	 	if(P.Mamm.OverTreshold){
		P.Mamm.ShiftBack=0;
		if(P.Mamm.ShiftBack){
		stopgoal=P.Step[stepx].StopGoal<0?posx+P.Mamm.ShiftBack*P.Step[stepx].Factor*P.Loop[loopx].Delta:posx-P.Mamm.ShiftBack*P.Step[stepx].Factor*P.Loop[loopx].Delta;
		MoveStep(&P.Step[stepx].Actual,stopgoal,stepx,1,P.Action.Status);
		P.Frame.First=P.Frame.First+P.Mamm.ShiftBack;
		}
		}
	 
    P.Frame.Last=P.Frame.First;			 //0 based
	 P.Frame.Actual=P.Frame.First;				 //0 based
	 P.Frame.Max=P.Loop[loopx].Num;				 // da usare per i cicli for
	 P.Loop[loopx].Idx=P.Frame.Actual;			 //riposizionamento dei cicli
	 P.Mamm.OverTreshold=0;
	 
    
	 
	FILE *fid;
	fid=fopen("CheckMamm.txt","w+");
	fprintf(fid,"CountRate\tTellPos\tIdxX\tIdxY\tFActual\tFLast\tFFirst\n");
	fprintf(fid,"%f\t%d\t%d\t%d\t%d\t%d\t%d\n",P.Mamm.Rate.Actual[0],posx,P.Loop[loopx].Idx,P.Loop[P.Mamm.Loop[Y]].Idx,P.Frame.Actual,P.Frame.Last,P.Frame.First);
	fclose(fid);
	
	
}
void StopMammot(void){
	
}

void AdjustIndex(void){
	P.Spc.Trash=FALSE;
	if(REMINDER(P.Loop[P.Mamm.Loop[Y]].Idx,2))
	   P.Loop[P.Mamm.Loop[X]].Idx=P.Loop[P.Mamm.Loop[X]].Num-P.Frame.Actual;
	else 
    	P.Loop[P.Mamm.Loop[X]].Idx=P.Frame.Actual;
}

void CheckMammot(void){
		P.Mamm.OverTreshold=0;   
        AnalysisMamm_new();			
		if(P.Mamm.OverTreshold){
			char stepx=P.Mamm.Step[X];
			char loopx=P.Mamm.Loop[X];
			char loopy=P.Mamm.Loop[Y];
			StopStep(stepx);
			
			int ib;
			for(ib=0;ib<P.Num.Board;ib++) StopSC1000(ib);
			FILE *fid;
			fid=fopen("CheckMamm.txt","a+");
			fprintf(fid,"%f\t%d\t%d\t%d\t%d\t%d\t%d\n",P.Mamm.Rate.Actual[0],P.Step[stepx].Actual,P.Loop[P.Mamm.Loop[X]].Idx,P.Loop[P.Mamm.Loop[Y]].Idx,P.Frame.Actual,P.Frame.Last,P.Frame.First);
			fclose(fid);
			
			if(P.Mamm.ShiftBack){
			int ShiftBack=P.Mamm.ShiftBack;
			long stopgoal=P.Step[stepx].StopGoal<0?P.Step[stepx].Actual+ShiftBack*P.Step[stepx].Factor*P.Loop[loopx].Delta:P.Step[stepx].Actual-ShiftBack*P.Step[stepx].Factor*P.Loop[loopx].Delta;
			char trashmem=P.Spc.Trash;
			MoveStep(&P.Step[stepx].Actual,stopgoal,stepx,1,P.Action.Status);
			P.Spc.Trash=trashmem;
			int ic,id,iframe;
			ShiftBack=ShiftBack*(REMINDER(P.Loop[loopy].Idx,2)?1:-1);
			for(ib=0;ib<P.Num.Board;ib++)
		 		for(id=0;id<P.Num.Det;id++)
			 		for(ic=0;ic<P.Chann.Num;ic++){ 
	            		for(iframe=P.Frame.Actual;P.Frame.Actual-(ShiftBack)<iframe&&iframe<P.Frame.Actual+(ShiftBack);iframe=iframe+(REMINDER(P.Loop[loopy].Idx,2)?1:-1)){
								D.Data[iframe][id][ic]=0;
								if(P.Info.SubHeader) CompileSub(P.Ram.Actual,iframe,id);
						}
			 }
			P.Frame.Actual=P.Frame.Actual+ShiftBack;
			}
			
			P.Mamm.IsTop=abs(P.Frame.Actual-P.Frame.Last)<=(4/P.Loop[P.Mamm.Loop[X]].Delta);
			P.Frame.Last=P.Frame.Actual;/*forse da eliminare perchè c'è già in datasave*/ 
			P.Action.DataSave=1;
			
			/*
			if(P.Mamm.Shrink[X]){
			P.Loop[P.Mamm.Loop[X]].Idx
			P.Loop[P.Mamm.Loop[Y]].Idx
			P.Step[stepx].Dir}
			*/
													 
			
	   
			
	}
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
	Fmt(string,"%d[w9p0]",P.Loop[LOOP5].Num*P.Loop[LOOP4].Num*P.Loop[LOOP3].Num*P.Loop[LOOP2].Num*P.Loop[LOOP1].Num);
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
	double timeT=P.Loop[LOOP1].Num*P.Loop[LOOP2].Num*P.Loop[LOOP3].Num*P.Loop[LOOP4].Num*P.Loop[LOOP5].Num*P.Spc.TimeM;
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

