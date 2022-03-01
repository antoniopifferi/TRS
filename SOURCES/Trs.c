/* ######################################################################## */
/* 									   										*/
/* 		TRSInterface.C	Time-Resolved Spectroscopy   Release 18.0  November 2020  */
/* 									   										*/
/* ######################################################################## */


/* ########################   HEADINGS   ################################## */
#include <windows.h>
#include <formatio.h>
#include <cvirte.h>		/* Needed if linking in external compiler; harmless otherwise */
#include <userint.h>
#include <utility.h>
#include <ansi_c.h>
#include <cvinetv.h>
#include "trs.h" 
#include "measure.h"

void AddTab(int Class,int Type,int Panel,int Control,char *Label,int Row,int Col,void *Addr);
void CreateTable(void);

void SaveSet(char *FilePath,int Panel);
void LoadSet(char *FilePath,int Panel);
void InitPanel(void);
void UpdatePanel(void);
void ReadAll(void);


/* ########################   MAIN PROCEDURES   ########################### */

/* MAIN */

int main (int argc, char *argv[])
{   
	if (InitCVIRTE (0, argv, 0) == 0)	/* Needed if linking in external compiler; harmless otherwise */
		return -1;	/* out of memory */
	if ((hTrs = LoadPanel (0, PATH_UIR, TRS)) < 0) return -1;
	if ((hParm = LoadPanel (hTrs, PATH_UIR, PARM)) < 0) return -1;
	if ((hLayout = LoadPanel (hTrs, PATH_UIR, LAYOUT)) < 0) return -1;
	if ((hPresent = LoadPanel (hTrs, PATH_UIR, PRESENT)) < 0) return -1;
	if ((hMoxy = LoadPanel (hTrs, PATH_UIR, MOXY)) < 0) return -1;
	if ((hSwitch = LoadPanel (hTrs, PATH_UIR, SWITCH)) < 0) return -1;
	if ((hTrim = LoadPanel (hTrs, PATH_UIR, TRIM)) < 0) return -1;
	if ((hMamm = LoadPanel (hTrs, PATH_UIR, MAMM)) < 0) return -1;
	if ((hLabel = LoadPanel (hTrs, PATH_UIR, LABEL)) < 0) return -1;
	if ((hDisplay = LoadPanel (hTrs, PATH_UIR, DISPLAY)) < 0) return -1;
	if ((hDoStep = LoadPanel (hTrs, PATH_UIR, DO_STEP)) < 0) return -1;
	if ((hStep = LoadPanel (hTrs, PATH_UIR, STEP)) < 0) return -1;
	if ((hGeom = LoadPanel (hTrs, PATH_UIR, GEOMETRY)) < 0) return -1;//ALE
	if ((hNirs = LoadPanel (hTrs, PATH_UIR, NIRS)) < 0) return -1;
	if ((hLuca = LoadPanel (hTrs, PATH_UIR, LUCA)) < 0) return -1;
	if ((hSwab = LoadPanel (hTrs, PATH_UIR, SWAB)) < 0) return -1;
	if ((hBcd = LoadPanel (hTrs, PATH_UIR, BCD)) < 0) return -1;
	
	CreateTable();
	
	DisplayPanel(hTrs);
	DisplayPanel(hParm);
	InitPanel();
	InitPad();								//ALE
	InitVariable();
	SetSleepPolicy (VAL_SLEEP_MORE);
	RunUserInterface ();
	return 0;
	}

void CVICALLBACK SaveSetting (int menuBar, int menuItem, void *callbackData, int panel){
	int c_panel;
	char fpath[MAX_PATHNAME_LEN];
	int status=FileSelectPopup (DIRSETTINGS, EXTSETTINGS, EXTSETTINGS,"SAVE FILE SETTINGS", VAL_SAVE_BUTTON, 0, 1,1, 1, fpath);
	if(status==VAL_NO_FILE_SELECTED) return;
	switch (menuItem){
		case MENU_FILE_SAVE_ALL: 			c_panel=NEG; break;
		case MENU_FILE_SAVE_DISPLAY:		c_panel=DISPLAY; break;
		case MENU_FILE_SAVE_DOSTEP:			c_panel=DO_STEP; break;
		case MENU_FILE_SAVE_LABEL: 			c_panel=LABEL; break;
		case MENU_FILE_SAVE_LAYOUT:			c_panel=LAYOUT; break;
		case MENU_FILE_LOAD_PRESENT:		c_panel=PRESENT; break;
		case MENU_FILE_LOAD_MOXY:		    c_panel=MOXY; break;
		case MENU_FILE_SAVE_MAMM: 			c_panel=MAMM; break;
		case MENU_FILE_SAVE_PARM: 			c_panel=PARM; break;
		case MENU_FILE_SAVE_TRIM: 			c_panel=TRIM; break;
		case MENU_FILE_SAVE_STEP: 			c_panel=STEP; break;
		case MENU_FILE_SAVE_SWITCH:			c_panel=SWITCH; break;
		case MENU_FILE_SAVE_NIRS:			c_panel=NIRS; break;
		case MENU_FILE_SAVE_LUCA:			c_panel=LUCA; break;
		case MENU_FILE_SAVE_GEOMETRY:		c_panel=GEOMETRY; break;//ALE
		case MENU_FILE_SAVE_SWAB:			c_panel=SWAB; break;
		case MENU_FILE_SAVE_BCD:			c_panel=BCD; break;
		}
	SaveSet(fpath,c_panel);
	}

void SaveSet(char *FilePath,int Panel){
	int it;
	char vchar;
	int vint;
	double vdouble;
	char vstring[STRLEN];
	FILE *pfile;
	if(Panel==NEG) pfile = fopen (FilePath, "w");
	else pfile = fopen (FilePath, "a");
	for(it=0;it<T.Num;it++)
		if((Panel==NEG)||(Panel==T.Panel[it])){
			fprintf(pfile, "%d\t%d\t%s\t",T.Class[it],T.Type[it],T.Label[it]);
			switch (T.Type[it]) {
				case TCHAR:
					if(T.Class[it]==CE) GetCtrlVal(hPanel[T.Panel[it]],T.Ctrl[it],&vchar);
					else GetTableCellVal (hPanel[T.Panel[it]],T.Ctrl[it],MakePoint(T.Col[it],T.Row[it]),&vchar);
					fprintf(pfile,"%d\n",vchar);
					break;
				case TINT:
					if(T.Class[it]==CE) GetCtrlVal(hPanel[T.Panel[it]],T.Ctrl[it],&vint);
					else GetTableCellVal (hPanel[T.Panel[it]],T.Ctrl[it],MakePoint(T.Col[it],T.Row[it]),&vint);
					fprintf(pfile,"%d\n",vint);
					break;
				case TDOUBLE:
					if(T.Class[it]==CE) GetCtrlVal(hPanel[T.Panel[it]],T.Ctrl[it],&vdouble);
					else GetTableCellVal (hPanel[T.Panel[it]],T.Ctrl[it],MakePoint(T.Col[it],T.Row[it]),&vdouble);
					fprintf(pfile,"%lf\n",vdouble);
					break;
				case TSTRING:
					if(T.Class[it]==CE) GetCtrlVal(hPanel[T.Panel[it]],T.Ctrl[it],vstring);
					else GetTableCellVal (hPanel[T.Panel[it]],T.Ctrl[it],MakePoint(T.Col[it],T.Row[it]),vstring);
					fprintf(pfile,"%s\n",vstring);
					break;
				}
			}
	fclose(pfile);
	}

void CVICALLBACK LoadSetting (int menuBar, int menuItem, void *callbackData,int panel){
	int c_panel;
	char fpath[MAX_PATHNAME_LEN];
	int status = FileSelectPopup (DIRSETTINGS, EXTSETTINGS, EXTSETTINGS,"SELECT FILE SETTINGS", VAL_LOAD_BUTTON, 0,0, 1, 0, fpath);
	if(status==VAL_NO_FILE_SELECTED) return;
	switch (menuItem){
		case MENU_FILE_LOAD_ALL: 			c_panel=NEG; break;
		case MENU_FILE_LOAD_DISPLAY:		c_panel=DISPLAY; break;
		case MENU_FILE_LOAD_DOSTEP:			c_panel=DO_STEP; break;
		case MENU_FILE_LOAD_LABEL: 			c_panel=LABEL; break;
		case MENU_FILE_LOAD_LAYOUT:			c_panel=LAYOUT; break;
		case MENU_FILE_LOAD_PRESENT:		c_panel=PRESENT; break;
		case MENU_FILE_LOAD_MOXY:	    	c_panel=MOXY; break;		
		case MENU_FILE_LOAD_MAMM: 			c_panel=MAMM; break;
		case MENU_FILE_LOAD_PARM: 			c_panel=PARM; break;
		case MENU_FILE_LOAD_TRIM: 			c_panel=TRIM; break;
		case MENU_FILE_LOAD_STEP: 			c_panel=STEP; break;
		case MENU_FILE_LOAD_SWITCH:			c_panel=SWITCH; break;
		case MENU_FILE_LOAD_NIRS:			c_panel=NIRS; break;
		case MENU_FILE_LOAD_LUCA:			c_panel=LUCA; break;
		case MENU_FILE_LOAD_GEOMETRY:		c_panel=GEOMETRY; break;//ALE
		case MENU_FILE_LOAD_SWAB:			c_panel=SWAB; break;
		case MENU_FILE_LOAD_BCD:			c_panel=BCD; break;
		}
	LoadSet(fpath,c_panel);
	ReadAll();
	CompleteParmS();
	UpdatePanel();
	}

	
void LoadSet(char *FilePath,int Panel){
	char line[STRLEN],label[STRLEN];
	int type,class,it;
	int vint;
	double vdouble;
	char vstring[STRLEN];
	FILE *pfile;
	pfile = fopen (FilePath, "r");
	if(pfile==NULL) return;
	while(fgets(line,STRLEN,pfile)!=NULL){
		sscanf (line, "%d\t%d\t%s\t",&class,&type,label);
		for(it=0;it<T.Num;it++)
			if(strcmp(label,T.Label[it])==0)
				if((Panel==NEG)||(Panel==T.Panel[it]))
					switch (type) {
						case TCHAR:
						case TINT:
							sscanf(line,"%d%d%s%d",&class,&type,label,&vint);
							if(T.Class[it]==CE) SetCtrlVal(hPanel[T.Panel[it]],T.Ctrl[it],vint);
							else SetTableCellAttribute (hPanel[T.Panel[it]],T.Ctrl[it],MakePoint(T.Col[it],T.Row[it]),ATTR_CTRL_VAL,vint);
							break;
						case TDOUBLE:
							sscanf(line,"%d%d%s%lf",&class,&type,label,&vdouble);
							if(T.Class[it]==CE) SetCtrlVal(hPanel[T.Panel[it]],T.Ctrl[it],vdouble);
							else SetTableCellAttribute (hPanel[T.Panel[it]],T.Ctrl[it],MakePoint(T.Col[it],T.Row[it]),ATTR_CTRL_VAL,vdouble);
							break;
						case TSTRING:
							Scan(line,"%d%d%s%s",&class,&type,label,vstring);
							if(T.Class[it]==CE) SetCtrlVal(hPanel[T.Panel[it]],T.Ctrl[it],vstring);
							else SetTableCellAttribute (hPanel[T.Panel[it]],T.Ctrl[it],MakePoint(T.Col[it],T.Row[it]),ATTR_CTRL_VAL,vstring);
							break;
						}
		} 
	fclose(pfile);
	}

void CVICALLBACK Print(int menuBar, int menuItem, void *callbackData,
		int panel)
{
	PrintPanel (panel, "", 1, VAL_FULL_PANEL, 1);
}


void CVICALLBACK Quit (int menuBar, int menuItem, void *callbackData,int panel){  
	SaveSet(FILESET,NEG);
	int ib;
	for (ib=0;ib<P.Num.Board;ib++){P.Spc.ScDeinit=TRUE;CompleteClosureSC1000(ib);} //EDO	//controllare
	QuitUserInterface (0);
	}


void CVICALLBACK ShowPanel (int menuBar, int menuItem, void *callbackData,
		int panel){
	switch (menuItem) {
		case MENU_WINDOW_PARM:    DisplayPanel (hParm); break;
		case MENU_WINDOW_LAYOUT:  DisplayPanel (hLayout); break;
		case MENU_WINDOW_PRESENT: DisplayPanel (hPresent); break;
		case MENU_DEVICE_MOXY:    DisplayPanel (hMoxy); break;
		case MENU_WINDOW_TRIM:    DisplayPanel (hTrim); break;
		case MENU_WINDOW_STEP:    DisplayPanel (hStep); break;
		case MENU_WINDOW_SWITCH:  DisplayPanel (hSwitch); break;
		case MENU_DEVICE_MAMM:    DisplayPanel (hMamm); break;
		case MENU_WINDOW_LABEL:   DisplayPanel (hLabel); break;
		case MENU_WINDOW_DO_STEP: DisplayPanel (hDoStep); break;
		case MENU_WINDOW_DISPLAY: DisplayPanel (hDisplay); break;
		case MENU_WINDOW_GEOMETRY:DisplayPanel (hGeom); break;//ALE
		case MENU_DEVICE_NIRS:	  DisplayPanel (hNirs); break;
		case MENU_DEVICE_LUCA:	  DisplayPanel (hLuca); break;
		case MENU_DEVICE_SWAB:	  DisplayPanel (hSwab); break;
		case MENU_DEVICE_BCD:	  DisplayPanel (hBcd); break;
		}
	}


void CVICALLBACK About (int menuBar, int menuItem, void *callbackData,
		int panel)
{
	MessagePopup ("ABOUT TRS", MESSAGE_ABOUT); 
}


void InitPanel(void){
	hPanel[PARM]=hParm;
	hPanel[LAYOUT]=hLayout;    
	hPanel[PRESENT]=hPresent;
	hPanel[MOXY]=hMoxy;
	hPanel[TRIM]=hTrim;    
	hPanel[STEP]=hStep;    
	hPanel[SWITCH]=hSwitch;    		
	hPanel[MAMM]=hMamm;
	hPanel[LABEL]=hLabel;    
	hPanel[DO_STEP]=hDoStep;    
	hPanel[DISPLAY]=hDisplay;
	hPanel[GEOMETRY]=hGeom;//ALE
	hPanel[NIRS]=hNirs;
	hPanel[LUCA]=hLuca;
	hPanel[SWAB]=hSwab;
	hPanel[BCD]=hBcd;
	LoadSet(FILESET,NEG);
	ReadAll();
	CompleteParmS();
	UpdatePanel();
	}
	

void ReadAll(void){
	int it;
	for(it=0;it<T.Num;it++)
		if(T.Class[it]==CE)
			GetCtrlVal(hPanel[T.Panel[it]],T.Ctrl[it],T.Addr[it]);
		else
			GetTableCellVal(hPanel[T.Panel[it]],T.Ctrl[it],MakePoint(T.Col[it],T.Row[it]),T.Addr[it]);
	}				

int CVICALLBACK Setting (int panel, int control, int event,void *callbackData, int eventData1, int eventData2){
	int ip,it,rowT,colT,root;
	int panelID;
	int row=eventData1;
	int col=eventData2;
	if(event!=EVENT_COMMIT) return 0;
	for(ip=0;ip<MAX_PANEL;ip++) if(hPanel[ip]==panel) panelID=ip;
	for(it=0;it<T.Num;it++)
		if((T.Panel[it]==panelID)&&(T.Ctrl[it]==control)){
			if(T.Class[it]==CE)
				GetCtrlVal(panel,control,T.Addr[it]);
			else{
				root = FindPattern(T.Label[it],0,-1,"_",1,0);
				sscanf(T.Label[it]+root+1,"%d_%d",&rowT,&colT);
				if((row==rowT)&&(col==colT))
					GetTableCellVal(panel,control,MakePoint(col,row),T.Addr[it]);
				}
			}
//	if(panelID==PARM){
	if(P.Info.Appl!=APPL_SPECTRA) CompleteParmS();
	if(P.Info.Appl!=APPL_SPECTRA) UpdatePanel();
//		}	   //TODO:if Ctrl==LOOP
	return 0;
	}


void UpdatePanel(void){
	int it;
	char *pchar;
	int *pint;
	double *pdouble;
	for(it=0;it<T.Num;it++)
		switch (T.Type[it]) {	   
			case TCHAR:
				pchar=T.Addr[it];
				if(T.Class[it]==CE) SetCtrlAttribute (hPanel[T.Panel[it]],T.Ctrl[it],ATTR_CTRL_VAL,*pchar);
				else SetTableCellAttribute (hPanel[T.Panel[it]],T.Ctrl[it],MakePoint(T.Col[it],T.Row[it]),ATTR_CTRL_VAL,*pchar);
				break;
			case TINT:
				pint=T.Addr[it];
				if(T.Class[it]==CE) SetCtrlAttribute (hPanel[T.Panel[it]],T.Ctrl[it],ATTR_CTRL_VAL,*pint);
				else SetTableCellAttribute (hPanel[T.Panel[it]],T.Ctrl[it],MakePoint(T.Col[it],T.Row[it]),ATTR_CTRL_VAL,*pint);
				break;
			case TDOUBLE:
				pdouble=T.Addr[it];
				if(T.Class[it]==CE) SetCtrlAttribute (hPanel[T.Panel[it]],T.Ctrl[it],ATTR_CTRL_VAL,*pdouble);
				else SetTableCellAttribute (hPanel[T.Panel[it]],T.Ctrl[it],MakePoint(T.Col[it],T.Row[it]),ATTR_CTRL_VAL,*pdouble);
				break;
			case TSTRING:
				if(T.Class[it]==CE) SetCtrlAttribute (hPanel[T.Panel[it]],T.Ctrl[it],ATTR_CTRL_VAL,T.Addr[it]);
				else SetTableCellAttribute (hPanel[T.Panel[it]],T.Ctrl[it],MakePoint(T.Col[it],T.Row[it]),ATTR_CTRL_VAL,T.Addr[it]);
				break;
			}
	ProcessDrawEvents ();

	SetCtrlVal (hParm, PARM_CHANN_NUM, P.Chann.Num);
	SetCtrlVal (hParm, PARM_SPC_CALIB, P.Spc.Calib);
	SetCtrlVal (hParm, PARM_SPC_FACTOR, P.Spc.Factor);

	SetCtrlVal (hParm, PARM_LOOP_NUM_1, P.Loop[0].Num);
	SetCtrlVal (hParm, PARM_LOOP_NUM_2, P.Loop[1].Num);
	SetCtrlVal (hParm, PARM_LOOP_NUM_3, P.Loop[2].Num);
	SetCtrlVal (hParm, PARM_LOOP_NUM_4, P.Loop[3].Num);
	SetCtrlVal (hParm, PARM_LOOP_NUM_5, P.Loop[4].Num);
	
	
	/*SetCtrlAttribute(hParm,PARM_OSCILL_REF_FIRST,ATTR_MAX_VALUE,P.Chann.Num-1);
	SetCtrlAttribute(hParm,PARM_OSCILL_REF_LAST,ATTR_MAX_VALUE,P.Chann.Num-1);
	SetCtrlAttribute(hParm,PARM_OSCILL_SIG_FIRST,ATTR_MAX_VALUE,P.Chann.Num-1);
	SetCtrlAttribute(hParm,PARM_OSCILL_SIG_LAST,ATTR_MAX_VALUE,P.Chann.Num-1);
	SetCtrlAttribute(hParm,PARM_OSCILL_ZOOM_FIRST,ATTR_MAX_VALUE,P.Chann.Num-1);
	SetCtrlAttribute(hParm,PARM_OSCILL_ZOOM_LAST,ATTR_MAX_VALUE,P.Chann.Num-1);*/
	}

int CVICALLBACK ClosePanel (int panel, int event, void *callbackdata, int eventdata1, int eventdata2) {
	if(event!=EVENT_CLOSE) return(0);
    if(panel==hTrs) {SaveSet(FILESET,NEG);QuitUserInterface (0); return(0);}
    HidePanel(panel);
    return(0);
    }

/// TABLE
void AddTab(int Class,int Type,int Panel,int Control,char *Label,int Row,int Col,void *Addr){
	/**/int aaa;
	T.Class[T.Num]=Class;
	T.Type[T.Num]=Type;
	T.Panel[T.Num]=Panel;
	T.Ctrl[T.Num]=Control;
	T.Row[T.Num]=Row;
	T.Col[T.Num]=Col;
	T.Addr[T.Num]=Addr;
	if(Row==0) sprintf(T.Label[T.Num],"%s",Label);
	else if(Col==0) sprintf(T.Label[T.Num],"%s_%d",Label,Row);
	else sprintf(T.Label[T.Num],"%s_%d_%d",Label,Row,Col);
	T.Num++;
	}


void CreateTable(void){
	int il,is,it,ip,id,ic,ib,iff,ir,ips;

	T.Num=0;

	// ITEMS  721 = 27+3+5+17+7+3+9+2+6+1+154+90+150+30+48+18+33+4+1
	
	// 9*5
	for(il=0;il<MAX_LOOP;il++){
		AddTab(CE,TINT,PARM,PARM_LOOP_HOME_1+il,"LoopHome",il+1,0,&P.Loop[il].Home);
		AddTab(CE,TINT,PARM,PARM_LOOP_FIRST_1+il,"LoopFirst",il+1,0,&P.Loop[il].First);
		AddTab(CE,TINT,PARM,PARM_LOOP_LAST_1+il,"LoopLast",il+1,0,&P.Loop[il].Last); 
		AddTab(CE,TINT,PARM,PARM_LOOP_DELTA_1+il,"LoopDelta",il+1,0,&P.Loop[il].Delta); 
		AddTab(CE,TINT,PARM,PARM_LOOP_NUM_1+il,"LoopNum",il+1,0,&P.Loop[il].Num); 
		AddTab(CE,TSTRING,PARM,PARM_LOOP_FNAME_1+il,"LoopFName",il+1,0,P.Loop[il].FName); 
		AddTab(CE,TCHAR,PARM,PARM_LOOP_BREAK_1+il,"LoopBreak",il+1,0,&P.Loop[il].Break); 
		AddTab(CE,TCHAR,PARM,PARM_LOOP_INVERT_1+il,"LoopInvert",il+1,0,&P.Loop[il].Invert);
		AddTab(CE,TCHAR,PARM,PARM_LOOP_CONT_1+il,"LoopCont",il+1,0,&P.Loop[il].Cont);
		}
		
	// 3	
	AddTab(CE,TDOUBLE,PARM,PARM_OSCILL_TIME,"SpcTimeO",0,0,&P.Spc.TimeO);
	AddTab(CE,TCHAR,PARM,PARM_TIME_BASE,"TimeBase",0,0,&P.Time.Time);
	AddTab(CE,TCHAR,PARM,PARM_READ_UIR,"ReadUIR",0,0,&P.Command.ReadUIR);
	
	// 5
	AddTab(CE,TSTRING,PARM,PARM_FILE_DIR,"FileDir",0,0,P.File.Dir);
	AddTab(CE,TSTRING,PARM,PARM_FILE_EXT,"FileExt",0,0,P.File.Ext); 
	AddTab(CE,TSTRING,PARM,PARM_FILE_PREFIX,"FilePrefix",0,0,P.File.Prefix); 
	AddTab(CE,TINT,PARM,PARM_FILE_TAG,"FileTag",0,0,&P.File.Tag); 
	AddTab(CE,TCHAR,PARM,PARM_FILE_TYPE,"FileType",0,0,&P.File.Type); 

	// 19+4
	AddTab(CE,TCHAR,PARM,PARM_SPC_TYPE,"SpcType",0,0,&P.Spc.Type);
	AddTab(CE,TCHAR,PARM,PARM_SPC_SCALE,"SpcScale",0,0,&P.Spc.Scale);
	AddTab(CE,TDOUBLE,PARM,PARM_SPC_CALIB,"SpcCalib",0,0,&P.Spc.Calib);
	AddTab(CE,TDOUBLE,PARM,PARM_SPC_FACTOR,"SpcFactor",0,0,&P.Spc.Factor);
	AddTab(CE,TCHAR,PARM,PARM_SPC_WAIT,"SpcWait",0,0,&P.Wait.Type);
	AddTab(CE,TDOUBLE,PARM,PARM_SPC_TIME,"SpcTimeM",0,0,&P.Spc.TimeM);
	AddTab(CE,TINT,PARM,PARM_SPC_COUNT,"SpcCount",0,0,&P.Spc.Count);
	AddTab(CE,TDOUBLE,PARM,PARM_CHRONO_DELTA,"ChronoDelta",0,0,&P.Chrono.Delta);
	AddTab(CE,TINT,PARM,PARM_CHANN_FIRST,"ChannFirst",0,0,&P.Chann.First);
	AddTab(CE,TINT,PARM,PARM_CHANN_LAST,"ChannLast",0,0,&P.Chann.Last);
	AddTab(CE,TINT,PARM,PARM_CHANN_NUM,"ChannNum",0,0,&P.Chann.Num);
	AddTab(CE,TCHAR,PARM,PARM_SPC_BOARDS,"NumBoard",0,0,&P.Num.Board);
	AddTab(CE,TCHAR,PARM,PARM_SPC_ROUTINGBITS,"SpcRoutingBits",0,0,&P.Spc.RoutingBits);
	AddTab(CE,TINT,PARM,PARM_SPC_REFOLDING,"SpcRefolding",0,0,&P.Spc.Refolding);
	AddTab(CE,TDOUBLE,PARM,PARM_SPC_REPRATE,"SpcRepRate",0,0,&P.Spc.RepRate);
	AddTab(CE,TINT,PARM,PARM_SC_SEL_REP_NUM,"SelRepNum",0,0,&P.Spc.SelRepNum);
	AddTab(CE,TINT,PARM,PARM_SC1000_FIRST,"ScFirstBin",0,0,&P.Spc.ScFirstBin);
	AddTab(CE,TINT,PARM,PARM_SC1000_LAST,"ScLastBin",0,0,&P.Spc.ScLastBin);
	AddTab(CE,TSTRING,PARM,PARM_DCR_FILE_ROOT_TDC,"DcrFile",0,0,&P.Spc.TdcDcrFileRoot);
	for(ib=0;ib<MAX_BOARD;ib++)
		AddTab(CE,TSTRING,PARM,PARM_SPC_INIFILE_1+ib,"SpcIniFile",ib+1,0,P.Spc.IniFile[ib]);

	// 8
	AddTab(CE,TINT,PARM,PARM_MEAS_DISPLAY,"MeasPlot",0,0,&P.Meas.Plot);
	AddTab(CE,TINT,PARM,PARM_MEAS_STATUS,"MeasStatus",0,0,&P.Meas.Status);
	AddTab(CE,TINT,PARM,PARM_MEAS_ROI,"MeasRoi",0,0,&P.Meas.Roi);
	AddTab(CE,TINT,PARM,PARM_MEAS_MEM,"MeasMem",0,0,&P.Meas.Ram);
	AddTab(CE,TCHAR,PARM,PARM_MEAS_CLEAR,"MeasClear",0,0,&P.Meas.Clear);
	AddTab(CE,TCHAR,PARM,PARM_MEAS_STOP,"MeasStop",0,0,&P.Meas.Stop);
	AddTab(CE,TCHAR,PARM,PARM_MEAS_AUTORUN,"MeasAutorun",0,0,&P.Meas.Autorun);
	AddTab(CE,TCHAR,PARM,PARM_MEAS_SKIPOSCILL,"MeasSkipOscill",0,0,&P.Meas.SkipOscill);

	// 3
	AddTab(CE,TDOUBLE,PARM,PARM_CONST_RHO,"ConstRho",0,0,&P.Const.Rho);
	AddTab(CE,TDOUBLE,PARM,PARM_CONST_THICK,"ConstThick",0,0,&P.Const.Thick);
	AddTab(CE,TDOUBLE,PARM,PARM_CONST_N,"ConstN",0,0,&P.Const.N);

	// 12
	AddTab(CE,TCHAR,PARM,PARM_JUMP_LOOP,"JumpLoop",0,0,&P.Jump.Loop);
	AddTab(CE,TCHAR,PARM,PARM_JUMP_BOARD,"JumpBoard",0,0,&P.Jump.Board);
	AddTab(CE,TINT,PARM,PARM_JUMP_MAX,"JUmpMax",0,0,&P.Jump.Max);
	AddTab(CE,TCHAR,PARM,PARM_INFO_KIND,"InfoKind",0,0,&P.Info.Kind);
	AddTab(CE,TCHAR,PARM,PARM_INFO_APPL,"InfoAppl",0,0,&P.Info.Appl);
	AddTab(CE,TCHAR,PARM,PARM_INFO_GEOM,"InfoGeom",0,0,&P.Info.Geom);
	AddTab(CE,TCHAR,PARM,PARM_OMA_LOOP,"OmaLoop",0,0,&P.Oma.Loop);
	AddTab(CE,TCHAR,PARM,PARM_OPHIR_LOOP,"OphirLoop",0,0,&P.Ophir.Loop);
	AddTab(CE,TCHAR,PARM,PARM_INFO_SUBHEADER,"InfoSubHeader",0,0,&P.Info.SubHeader);
	AddTab(CE,TINT,PARM,PARM_LAYOUT,"LayoutLayout",0,0,&P.Layout.Layout);
	AddTab(CE,TINT,PARM,PARM_FLAGPRESENT,"PresentFlagPresent",0,0,&P.Presentation.Flag);
	AddTab(CE,TCHAR,PARM,PARM_INFO_MONITOR,"InfoMonitor",0,0,&P.Info.Monitor);

	// 7
	AddTab(CE,TCHAR,PARM,PARM_SYNC_SYNC,"SyncSync",0,0,&P.Sync.Sync);
	AddTab(CE,TCHAR,PARM,PARM_SYNC_TYPE,"SyncType",0,0,&P.Sync.Type);
	AddTab(CE,TCHAR,PARM,PARM_SYNC_COM,"SyncCom",0,0,&P.Sync.Com);
	AddTab(CE,TCHAR,PARM,PARM_SYNC_LOOP,"SyncLoop",0,0,&P.Sync.Loop);
	AddTab(CE,TCHAR,PARM,PARM_SYNC_PATTERN,"SyncPattern",0,0,&P.Sync.Pattern);
	AddTab(CE,TCHAR,PARM,PARM_SYNC_DIR,"SyncDir",0,0,&P.Sync.Dir);
	AddTab(CE,TDOUBLE,PARM,PARM_SYNC_WIDTH,"SyncWidth",0,0,&P.Sync.Width);
	AddTab(CE,TINT,PARM,PARM_SYNC_BAUD,"SyncBaud",0,0,&P.Sync.Baud);

	// 1
	AddTab(CE,TCHAR,PARM,PARM_POWER_STEP,"PowerStep",0,0,&P.Power.Step);


	// 17*11
	for(is=0;is<MAX_STEP;is++){
		AddTab(CE,TCHAR,STEP,STEP_TYPE_1+is,"StepType",is+1,0,&P.Step[is].Type);
		AddTab(CE,TCHAR,STEP,STEP_COM_1+is,"StepCom",is+1,0,&P.Step[is].Com);
		AddTab(CE,TCHAR,STEP,STEP_AXIS_1+is,"StepAxis",is+1,0,&P.Step[is].Axis);
		AddTab(CE,TCHAR,STEP,STEP_MODE_1+is,"StepMode",is+1,0,&P.Step[is].Mode);
		AddTab(CE,TCHAR,STEP,STEP_SIGN_1+is,"StepSign",is+1,0,&P.Step[is].Sign);
		AddTab(CE,TCHAR,STEP,STEP_LOOP_1+is,"StepLoop",is+1,0,&P.Step[is].Loop);
		AddTab(CE,TCHAR,STEP,STEP_HOLD_1+is,"StepHold",is+1,0,&P.Step[is].Hold);
		AddTab(CE,TCHAR,STEP,STEP_LCD_1+is,"StepLcd",is+1,0,&P.Step[is].Lcd);
		AddTab(CE,TSTRING,STEP,STEP_FNAME_1+is,"StepFName",is+1,0,P.Step[is].FName);
		AddTab(CE,TINT,STEP,STEP_MIN_1+is,"StepMin",is+1,0,&P.Step[is].Min);
		AddTab(CE,TINT,STEP,STEP_MAX_1+is,"StepMax",is+1,0,&P.Step[is].Max);
		AddTab(CE,TDOUBLE,STEP,STEP_FREQMIN_1+is,"StepFreqMin",is+1,0,&P.Step[is].FreqMin);
		AddTab(CE,TDOUBLE,STEP,STEP_FREQMAX_1+is,"StepFreqMax",is+1,0,&P.Step[is].FreqMax);
		AddTab(CE,TDOUBLE,STEP,STEP_FREQ_1+is,"StepFreq",is+1,0,&P.Step[is].Freq);
		AddTab(CE,TDOUBLE,STEP,STEP_FREQDELTA_1+is,"StepFreqDelta",is+1,0,&P.Step[is].FreqDelta);
		AddTab(CE,TDOUBLE,STEP,STEP_FACTOR_1+is,"StepFactor",is+1,0,&P.Step[is].Factor);
		AddTab(CE,TCHAR,STEP,STEP_SORT_1+is,"StepSort",is+1,0,&P.Step[is].Sort);
		}
  
  	// 10*10
	for(is=0;is<MAX_SWITCH;is++){
		AddTab(CE,TCHAR,SWITCH,SWITCH_SWITCH_1+is,"SwitchSwitch",is+1,0,&P.Switch[is].Switch);   
		AddTab(CE,TCHAR,SWITCH,SWITCH_DEVICE_1+is,"SwitchDevice",is+1,0,&P.Switch[is].Device);
		AddTab(CE,TCHAR,SWITCH,SWITCH_TYPE_1+is,"SwitchType",is+1,0,&P.Switch[is].Type);
		AddTab(CE,TINT,SWITCH,SWITCH_COM_1+is,"SwitchCom",is+1,0,&P.Switch[is].Com);
		AddTab(CE,TINT,SWITCH,SWITCH_BOARD_1+is,"SwitchBoard",is+1,0,&P.Switch[is].Board);
		AddTab(CE,TSTRING,SWITCH,SWITCH_PORT_1+is,"SwitchPort",is+1,0,&P.Switch[is].Port);
		AddTab(CE,TCHAR,SWITCH,SWITCH_LINE0_1+is,"SwitchLine0",is+1,0,&P.Switch[is].Line0);
		AddTab(CE,TCHAR,SWITCH,SWITCH_MODE_1+is,"SwitchMode",is+1,0,&P.Switch[is].Mode);
		AddTab(CE,TCHAR,SWITCH,SWITCH_LOOP_1+is,"SwitchLoop",is+1,0,&P.Switch[is].Loop);
		AddTab(CE,TSTRING,SWITCH,SWITCH_FNAME_1+is,"SwitchFName",is+1,0,P.Switch[is].FName);
		}

	// 20*10
	for(it=0;it<MAX_TRIM;it++){
		AddTab(CE,TCHAR,TRIM,TRIM_STEP_1+it,"TrimStep",it+1,0,&P.Trim[it].Step);
		AddTab(CE,TCHAR,TRIM,TRIM_LOOP_1+it,"TrimLoop",it+1,0,&P.Trim[it].Loop);
		AddTab(CE,TCHAR,TRIM,TRIM_TYPE_1+it,"TrimType",it+1,0,&P.Trim[it].Type);
		AddTab(CE,TCHAR,TRIM,TRIM_WAIT_1+it,"TrimWait",it+1,0,&P.Trim[it].Wait);
		AddTab(CE,TCHAR,TRIM,TRIM_TARGET_1+it,"TrimTarget",it+1,0,&P.Trim[it].Target);
		AddTab(CE,TDOUBLE,TRIM,TRIM_LOW_1+it,"TrimLow",it+1,0,&P.Trim[it].Low);
		AddTab(CE,TDOUBLE,TRIM,TRIM_GOAL_1+it,"TrimGoal",it+1,0,&P.Trim[it].Goal);
		AddTab(CE,TDOUBLE,TRIM,TRIM_HIGH_1+it,"TrimHigh",it+1,0,&P.Trim[it].High);
		AddTab(CE,TCHAR,TRIM,TRIM_SIGN_1+it,"TrimSign",it+1,0,&P.Trim[it].Sign);
		AddTab(CE,TCHAR,TRIM,TRIM_REGION_1+it,"TrimRegion",it+1,0,&P.Trim[it].Region);
		AddTab(CE,TDOUBLE,TRIM,TRIM_FRACT_1+it,"TrimFact",it+1,0,&P.Trim[it].Fract);
		AddTab(CE,TDOUBLE,TRIM,TRIM_TIME_1+it,"TrimTime",it+1,0,&P.Trim[it].Time);
		AddTab(CE,TDOUBLE,TRIM,TRIM_DELTA_1+it,"TrimDeltaU",it+1,0,&P.Trim[it].DeltaU);
		AddTab(CE,TINT,TRIM,TRIM_NUM_1+it,"TrimNum",it+1,0,&P.Trim[it].Num);
		AddTab(CE,TCHAR,TRIM,TRIM_SCAN_1+it,"TrimScan",it+1,0,&P.Trim[it].Scan);
		AddTab(CE,TCHAR,TRIM,TRIM_BREAK_1+it,"TrimBreak",it+1,0,&P.Trim[it].Break);
		AddTab(CE,TCHAR,TRIM,TRIM_DISPLAY_1+it,"TrimDisplay",it+1,0,&P.Trim[it].Display);
		AddTab(CE,TCHAR,TRIM,TRIM_STATUS_1+it,"TrimStatus",it+1,0,&P.Trim[it].Status);
		AddTab(CE,TCHAR,TRIM,TRIM_PROMPT_1+it,"TrimPrompt",it+1,0,&P.Trim[it].Prompt);
		AddTab(CE,TSTRING,TRIM,TRIM_FNAME_1+it,"TrimFName",it+1,0,P.Trim[it].FName);
		}

	// 25+7
	AddTab(CE,TCHAR,MAMM,MAMM_AUTOLABEL,"MammAutoLabel",0,0,&P.Mamm.AutoLabel);
	AddTab(CE,TCHAR,MAMM,MAMM_FINDTOP,"MammFindTop",0,0,&P.Mamm.FindTop);
	AddTab(CE,TINT,MAMM,MAMM_ITERBORD,"MammIterBoard",0,0,&P.Mamm.IterBord);
	AddTab(CE,TDOUBLE,MAMM,MAMM_FREQOPEN_NIR,"MammFreqOpenNIR",0,0,&P.Mamm.Att[MAMM_NIR].FreqOpen);
	AddTab(CE,TDOUBLE,MAMM,MAMM_BACKTOP_NIR,"MammBackTopNIR",0,0,&P.Mamm.BackTopNIR);
	AddTab(CE,TCHAR,MAMM,MAMM_SHRINK_X,"MammShrinkX",0,0,&P.Mamm.Shrink[X]);
	AddTab(CE,TCHAR,MAMM,MAMM_SHRINK_Y,"MammShrinkY",0,0,&P.Mamm.Shrink[Y]);
	AddTab(CE,TCHAR,MAMM,MAMM_LOOP_X,"MammLoopX",0,0,&P.Mamm.Loop[X]);
	AddTab(CE,TCHAR,MAMM,MAMM_LOOP_Y,"MammLoopY",0,0,&P.Mamm.Loop[Y]);
	AddTab(CE,TCHAR,MAMM,MAMM_STEP_X,"MammStepX",0,0,&P.Mamm.Step[X]);
	AddTab(CE,TCHAR,MAMM,MAMM_STEP_Y,"MammStepY",0,0,&P.Mamm.Step[Y]);
	AddTab(CE,TCHAR,MAMM,MAMM_STEP_VIS,"MammAttStepVIS",0,0,&P.Mamm.Att[MAMM_VIS].Step);
	AddTab(CE,TINT,MAMM,MAMM_IDXMIN_VIS,"MammIdxMinVIS",0,0,&P.Mamm.Att[MAMM_VIS].IdxMin);
	AddTab(CE,TINT,MAMM,MAMM_IDXMAX_VIS,"MammIdxMaxVIS",0,0,&P.Mamm.Att[MAMM_VIS].IdxMax);
	AddTab(CE,TDOUBLE,MAMM,MAMM_RATE_HIGH_VIS,"MammRateHighVis",0,0,&P.Mamm.Rate.High[MAMM_VIS]);
	AddTab(CE,TDOUBLE,MAMM,MAMM_RATE_MID_VIS,"MammRateMidVis",0,0,&P.Mamm.Rate.Mid[MAMM_VIS]);
	AddTab(CE,TDOUBLE,MAMM,MAMM_RATE_LOW_VIS,"MammRateLowVis",0,0,&P.Mamm.Rate.Low[MAMM_VIS]);
	AddTab(CE,TCHAR,MAMM,MAMM_STEP_NIR,"MammAttStepNIR",0,0,&P.Mamm.Att[MAMM_NIR].Step);
	AddTab(CE,TINT,MAMM,MAMM_IDXMIN_NIR,"MammIdxMinNIR",0,0,&P.Mamm.Att[MAMM_NIR].IdxMin);
	AddTab(CE,TINT,MAMM,MAMM_IDXMAX_NIR,"MammIdxMaxNIR",0,0,&P.Mamm.Att[MAMM_NIR].IdxMax);
	AddTab(CE,TDOUBLE,MAMM,MAMM_RATE_HIGH_NIR,"MammRateHighNIR",0,0,&P.Mamm.Rate.High[MAMM_NIR]);
	AddTab(CE,TDOUBLE,MAMM,MAMM_RATE_MID_NIR,"MammRateMidNIR",0,0,&P.Mamm.Rate.Mid[MAMM_NIR]);
	AddTab(CE,TDOUBLE,MAMM,MAMM_RATE_LOW_NIR,"MammRateLowNIR",0,0,&P.Mamm.Rate.Low[MAMM_NIR]);
	AddTab(CE,TDOUBLE,MAMM,MAMM_NEG_PER_VAR_COUNTS,"NegativeTreshold",0,0,&P.Mamm.NegativeTreshold);
	AddTab(CE,TCHAR,MAMM,MAMM_STATUS,"Status",0,0,&P.Mamm.Status);
	AddTab(CE,TINT,MAMM,MAMM_SHIFT_BACK,"ShiftBack",0,0,&P.Mamm.ShiftBack);
	AddTab(CE,TINT,MAMM,MAMM_TAKE_REF_MEAS,"Ref_Meas",0,0,&P.Mamm.IsRefMeas);
	for(il=0;il<MAMM_NUM_LAMBDA;il++)
		AddTab(CE,TDOUBLE,MAMM,MAMM_LAMBDA_1+il,"MammLambda",il+1,0,&P.Mamm.Lambda[il]);

	// 3*16
	for(il=0;il<LABEL_MAX;il++){
		AddTab(CE,TSTRING,LABEL,LABEL_NAME_1+il,"LabelName",il+1,0,P.Label[il].Name);
		AddTab(CE,TSTRING,LABEL,LABEL_CONTENT_1+il,"LabelContent",il+1,0,P.Label[il].Content);
		AddTab(CE,TINT,LABEL,LABEL_AUTO_1+il,"LabelAuto",il+1,0,&P.Label[il].Auto);
		}
	
	// 6*3
	for(id=0;id<3;id++){
		AddTab(CE,TCHAR,DO_STEP,DO_STEP_STEP_1+id,"DoStepStep",id+1,0,&P.DoStep[id].Step);
		AddTab(CE,TINT,DO_STEP,DO_STEP_HOME_1+id,"DoStepHome",id+1,0,&P.DoStep[id].Home);
		AddTab(CE,TINT,DO_STEP,DO_STEP_GOAL_1+id,"DoStepGoal",id+1,0,&P.DoStep[id].Goal);
		AddTab(CE,TCHAR,DO_STEP,DO_STEP_OSCILL_1+id,"DoStepOscill",id+1,0,&P.DoStep[id].Oscill);
		AddTab(CE,TCHAR,DO_STEP,DO_STEP_BREAK_1+id,"DoStepBreak",id+1,0,&P.DoStep[id].Break);
		AddTab(CE,TCHAR,DO_STEP,DO_STEP_RETURN_1+id,"DoStepReturn",id+1,0,&P.DoStep[id].Return);
		}
	
	// 16*2+1
	AddTab(CE,TCHAR,DISPLAY,DISPLAY_ROI_WINDOW,"RoiWindow",0,0,&P.Roi.Window);
	for(ip=0;ip<MAX_PLOT;ip++){
		AddTab(CE,TINT,DISPLAY,DISPLAY_PLOT_PLOT_1+ip,"PlotPlot",ip+1,0,&P.Plot.Plot[ip]);
		AddTab(CE,TINT,DISPLAY,DISPLAY_PLOT_PAGE_1+ip,"PlotPageU",ip+1,0,&P.Plot.PageU[ip]);
		}
	
	// 4
	AddTab(CE,TCHAR,DISPLAY,DISPLAY_GRAPH_TYPE,"GraphType",0,0,&P.Graph.Type);
	AddTab(CE,TCHAR,DISPLAY,DISPLAY_GRAPH_TYPE,"GraphType",0,0,&P.Graph.Scale);
	AddTab(CE,TINT,DISPLAY,DISPLAY_OSCILL_ZOOM_FIRST,"OscillZoomFirst",0,0,&P.Oscill.Zoom.First);
	AddTab(CE,TINT,DISPLAY,DISPLAY_OSCILL_ZOOM_LAST,"OscillZoomLast",0,0,&P.Oscill.Zoom.Last);

	// 1
	AddTab(CE,TCHAR,LAYOUT,LAYOUT_ORDER,"LayoutOrder",0,0,&P.Layout.Order);	
	

	// TABLES  438 = 1+6+96+64+48+48+144+18+9+1+3

	// 1
	AddTab(CT,TCHAR,DISPLAY,DISPLAY_T_VALUE,"ValueRoi",1,COL_VALUE_ROI,&P.Value.Roi);
	
	// 2*3
	for(ir=0;ir<MAX_ROW_OSCILL;ir++){
		AddTab(CT,TINT,DISPLAY,DISPLAY_T_OSCILL,"OscillFirst",ir+1,COL_OSCILL_FIRST,&P.Oscill.First[ir]);
		AddTab(CT,TINT,DISPLAY,DISPLAY_T_OSCILL,"OscillLast",ir+1,COL_OSCILL_LAST,&P.Oscill.Last[ir]);
		AddTab(CT,TDOUBLE,DISPLAY,DISPLAY_T_OSCILL,"OscillFract",ir+1,COL_OSCILL_FRACT,&P.Oscill.Fract[ir]);
		}

	// 32*3
	for(ir=0;ir<MAX_ROW_ROI;ir++){
		AddTab(CT,TINT,DISPLAY,DISPLAY_T_ROI,"RoiPage",ir+1,COL_ROI_PAGE,&P.Roi.Page[ir]);
		AddTab(CT,TINT,DISPLAY,DISPLAY_T_ROI,"RoiFirst",ir+1,COL_ROI_FIRST,&P.Roi.First[ir]);
		AddTab(CT,TINT,DISPLAY,DISPLAY_T_ROI,"RoiLast",ir+1,COL_ROI_LAST,&P.Roi.Last[ir]);
		}
		
	// 16*4	
	for(ip=0;ip<MAX_ROW_PROT;ip++){
		AddTab(CT,TCHAR,LAYOUT,LAYOUT_T_PROT,"ProtSource",ip+1,COL_PROT_SOURCE,&P.TProt.Source[ip]);
		AddTab(CT,TSTRING,LAYOUT,LAYOUT_T_PROT,"ProtFibers",ip+1,COL_PROT_FIBERS,P.TProt.Fibers[ip]);
		AddTab(CT,TINT,LAYOUT,LAYOUT_T_PROT,"ProtAcqStart",ip+1,COL_PROT_ACQSTART,&P.TProt.AcqStart[ip]);
		AddTab(CT,TINT,LAYOUT,LAYOUT_T_PROT,"ProtAcqStop",ip+1,COL_PROT_ACQSTOP,&P.TProt.AcqStop[ip]);
		}
		
	// 16*3	
	for(iff=0;iff<MAX_ROW_FIBER;iff++){
		AddTab(CT,TCHAR,LAYOUT,LAYOUT_T_FIBER,"FiberBoard",iff+1,COL_FIBER_BOARD,&P.TFiber.Board[iff]);
		AddTab(CT,TCHAR,LAYOUT,LAYOUT_T_FIBER,"FiberDet",iff+1,COL_FIBER_DET,&P.TFiber.Det[iff]);
		AddTab(CT,TSTRING,LAYOUT,LAYOUT_T_FIBER,"FiberFibers",iff+1,COL_FIBER_FIBERS,P.TFiber.Fibers[iff]);
		}
		
	// 16*3	
	for(is=0;is<MAX_ROW_SOURCE;is++){
		AddTab(CT,TCHAR,LAYOUT,LAYOUT_T_SOURCE,"SourceSource",is+1,COL_SOURCE_SOURCE,&P.TSource.Source[is]);
		AddTab(CT,TCHAR,LAYOUT,LAYOUT_T_SOURCE,"SourceSwitch",is+1,COL_SOURCE_SWITCH,&P.TSource.Switch[is]);
		AddTab(CT,TCHAR,LAYOUT,LAYOUT_T_SOURCE,"SourceChann",is+1,COL_SOURCE_CHANN,&P.TSource.Chann[is]);
		}	
	
	// 18*8
	for(ips=0;ips<MAX_ROW_PRES_BLOCK;ips++){
		AddTab(CT,TINT,PRESENT,PRESENT_TBLOCK_DEF,"BlockBlock",ips+1,COL_BLOCK_DEF_BLOCK,&P.TBlock.Num[ips]);
		AddTab(CT,TINT,PRESENT,PRESENT_TBLOCK_DEF,"BlockType",ips+1,COL_BLOCK_DEF_TYPE,&P.TBlock.Type[ips]);
    	AddTab(CT,TINT,PRESENT,PRESENT_TBLOCK_DEF,"BlockStartFrame",ips+1,COL_BLOCK_DEF_START_FRAME,&P.TBlock.StartFrame[ips]);
    	AddTab(CT,TINT,PRESENT,PRESENT_TBLOCK_DEF,"BlockStopFrame",ips+1,COL_BLOCK_DEF_STOP_FRAME,&P.TBlock.StopFrame[ips]);
    	AddTab(CT,TINT,PRESENT,PRESENT_TBLOCK_DEF,"BlockParam2",ips+1,COL_BLOCK_DEF_PARAM2,&P.TBlock.Param2[ips]);
    	AddTab(CT,TINT,PRESENT,PRESENT_TBLOCK_DEF,"BlockParam3",ips+1,COL_BLOCK_DEF_PARAM3,&P.TBlock.Param3[ips]);
    	AddTab(CT,TINT,PRESENT,PRESENT_TBLOCK_SEQUENCE,"SequenceBlock",ips+1,COL_BLOCK_SEQUENCE_BLOCK,&P.TSequence.BlockUsed[ips]);
    	AddTab(CT,TINT,PRESENT,PRESENT_TBLOCK_SEQUENCE,"SequenceBlock",ips+1,COL_BLOCK_SEQUENCE_REPEAT,&P.TSequence.Repeat[ips]);
    	}
    
    // 18
    for(ips=0;ips<MAX_ROW_PRES_BLOCK;ips++){   
    	AddTab(CT,TSTRING,PRESENT,PRESENT_TBLOCK_DEF,"BlockParam1",ips+1,COL_BLOCK_DEF_PARAM1,&P.TBlock.Param1[ips]);
		}    	
    
    // 6+5
    for(ips=0;ips<MAX_ROW_PRES_LOOP;ips++){
    	AddTab(CT,TINT,PRESENT,PRESENT_TLOOP_PARTITION,"PartitionLoop",ips+1,1,&P.TPartition.LoopFactor[ips]); 
		}	
	AddTab(CE,TSTRING,PRESENT,PRESENT_FSTIMULI,"PresentFileStimuli",0,0,&P.Presentation.FStimuliName);
	AddTab(CE,TSTRING,PRESENT,PRESENT_DSTIMULI,"PresentDirStimuli",0,0,&P.Presentation.FStimuliDir);
	AddTab(CE,TSTRING,PRESENT,PRESENT_FPRESENT,"PresentFileInitPresentation",0,0,&P.Presentation.FInitPresentationName);
	AddTab(CE,TSTRING,PRESENT,PRESENT_DPRESENT,"PresentDirInitPresentation",0,0,&P.Presentation.FInitPresentationDir);
	AddTab(CE,TINT,PRESENT,PRESENT_SHUFFLE,"SequenceShuffle",0,0,&P.TSequence.Shuffle);
	AddTab(CE,TINT,PRESENT,PRESENT_ALIGN,"LoopPartitionAlign",0,0,&P.TPartition.Align);
		
   	// 1																						//ALE
   	AddTab(CE,TSTRING,GEOMETRY,GEOMETRY_GEO_FNAME,"GeomFname",0,0,&P.Layout.FGeometry);			//ALE 

	//3
	AddTab(CE,TINT,MOXY,MOXY_DISP_DIV,"DisplayDivisor",0,0,&P.Moxy.DisplayDivisor);
	AddTab(CE,TINT,MOXY,MOXY_PRES_EDGE,"PresentationRise",0,0,&P.Moxy.PresentationRise);
	AddTab(CE,TINT,MOXY,MOXY_EXT_TRIG,"ExternalTrigger",0,0,&P.Moxy.ExternalTrigger);
	
	//3
	AddTab(CE,TINT,NIRS,NIRS_FREQ,"NirsFreq",0,0,&P.Spc.Nirs[0].Freq);
	AddTab(CE,TINT,NIRS,NIRS_TIME,"NirsTime",0,0,&P.Spc.Nirs[0].UirTime);
	AddTab(CE,TINT,NIRS,NIRS_LAMBDA,"NirsLambda",0,0,&P.Spc.Nirs[0].Lambda);
	
	//1
	AddTab(CE,TINT,LUCA,LUCA_FREQ,"LucaFreq",0,0,&P.Spc.Luca[0].Freq);
	
	
	// SWAB PANEL
	// 8*3+4+2	
	for(id=0;id<SWAB_MAX_DET;id++){
		AddTab(CE,TINT,SWAB,SWAB_DETTYPE_1+id,"SwabDetType",id+1,0,&P.Spc.Swab[0].DetType[id]);
		AddTab(CE,TDOUBLE,SWAB,SWAB_LEVEL_1+id,"SwabLevel",id+1,0,&P.Spc.Swab[0].Level[id]);
		AddTab(CE,TINT,SWAB,SWAB_DELAY_1+id,"SwabDelay",id+1,0,&P.Spc.Swab[0].Delay[id]);
		}	
	AddTab(CE,TINT,SWAB,SWAB_TYPE,"SwabType",0,0,&P.Spc.Swab[0].Type);
	AddTab(CE,TINT,SWAB,SWAB_MEAS,"SwabMeas",0,0,&P.Spc.Swab[0].Meas);
	AddTab(CE,TINT,SWAB,SWAB_SAVETAGS,"SwabSaveTags",0,0,&P.Spc.Swab[0].SaveTags);
	AddTab(CE,TSTRING,SWAB,SWAB_FNAMEVIRT,"SwabFNameVirt",0,0,P.Spc.Swab[0].FNameVirt);
	AddTab(CE,TINT,SWAB,SWAB_FREQDIV,"SwabFreqDiv",0,0,&P.Spc.Swab[0].FreqDiv);
	AddTab(CE,TINT,SWAB,SWAB_FREQMULT,"SwabFreqMult",0,0,&P.Spc.Swab[0].FreqMult);

	// BCD PANEL
	// 6+3+2=11	
	AddTab(CE,TDOUBLE,BCD,BCD_VDD_CORE,"BcdVddCore",0,0,&P.Spc.Bcd[0].VDD_CORE);
	AddTab(CE,TDOUBLE,BCD,BCD_VDDD_CORE,"BcdVdddCore",0,0,&P.Spc.Bcd[0].VDDD_CORE);
	AddTab(CE,TDOUBLE,BCD,BCD_VDD_CK,"BcdVddCk",0,0,&P.Spc.Bcd[0].VDD_CK);
	AddTab(CE,TDOUBLE,BCD,BCD_VHIGH,"BcdVhigh",0,0,&P.Spc.Bcd[0].VHIGH);
	AddTab(CE,TCHAR,BCD,BCD_RSTDuration,"BcdRSTDuration",0,0,&P.Spc.Bcd[0].RSTDuration);
	AddTab(CE,TCHAR,BCD,BCD_LOWPower,"BcdLOWPower",0,0,&P.Spc.Bcd[0].LOWPower);

	AddTab(CE,TINT,BCD,BCD_OPEN0,"BcdOpen0",0,0,&P.Spc.Bcd[0].Open0);
	AddTab(CE,TINT,BCD,BCD_WIDTH0,"BcdWidth0",0,0,&P.Spc.Bcd[0].Width0);
	AddTab(CE,TINT,BCD,BCD_SYNC0,"BcdSync0",0,0,&P.Spc.Bcd[0].Sync0);

	AddTab(CE,TSTRING,BCD,BCD_PIXELSORDER,"BcdPixelsorder",0,0,P.Spc.Bcd[0].PixelsOrder);
	AddTab(CE,TSTRING,BCD,BCD_CALIBRATION,"BcdCalibration",0,0,P.Spc.Bcd[0].Calibration);

	AddTab(CE,TINT,BCD,BCD_PIXEL_DEFAULT,"BcdPixelDefault",0,0,&P.Spc.Bcd[0].PixelDefault);
	AddTab(CE,TCHAR,BCD,BCD_PIXEL_SINGLE,"BcdPixelSingle",0,0,&P.Spc.Bcd[0].PixelSingle);

	for(ic=0;ic<T.Num;ic++) T.Dimmed[ic]=FALSE;
	}

/* ################### NIRS BOX SECTION ################ */

/* NIRS BOX PRESSED (ON or OFF) */
int CVICALLBACK NirsBoxCbk(int panel,int control,int event,void *callbackData,int eventData1,int eventData2){
	int start;
	GetCtrlVal(panel,control,&start);
	switch (event){
		case EVENT_COMMIT:
			if(!NirsBox(start))
				SetCtrlVal (panel, control, !start); // undo action on press button
			break;
		}
	return 0;
	}

/* NIRS LASER PRESSED (ON or OFF) */
int CVICALLBACK NirsLasersCbk(int panel,int control,int event,void *callbackData,int eventData1,int eventData2){
	int start;
	GetCtrlVal(panel,control,&start);
	switch (event){
		case EVENT_COMMIT:
			if(!NirsLasers(start))
				SetCtrlVal (panel, control, !start); // undo action on press button
			break;
		}
	return 0;
	}


/* ################### LUCA BOX SECTION ################ */

/* LUCA BOX PRESSED (ON or OFF) */
int CVICALLBACK LucaBoxCbk(int panel,int control,int event,void *callbackData,int eventData1,int eventData2){
	int start;
	GetCtrlVal(panel,control,&start);
	switch (event){
		case EVENT_COMMIT:
			if(!LucaBox(start))
				SetCtrlVal (panel, control, !start); // undo action on press button
			break;
		}
	return 0;
	}

/* LUCA LASER PRESSED (ON or OFF) */
int CVICALLBACK LucaLasersCbk(int panel,int control,int event,void *callbackData,int eventData1,int eventData2){
	int start;
	GetCtrlVal(panel,control,&start);
	switch (event){
		case EVENT_COMMIT:
			if(!LucaLasers(start))
				SetCtrlVal (panel, control, !start); // undo action on press button
			break;
		}
	return 0;
	}


/* ################### GEOMETRY SECTION ################ */ //ALE

void InitPad (void)
{
	int pi,si,fi,oi;
	
	for (pi=0;pi<MAX_PAD;pi++){
		
		Pad[pi].hPad = NOT_AVAILABLE;
		Pad[pi].NearNeigh[0]= ON;
		for (oi=1;oi<NEAR_NEIGH;oi++) Pad[pi].NearNeigh[oi]= OFF;
		Pad[pi].LatticeType = 0;
		Pad[pi].LatticeCtrl = 0;
		Pad[pi].LatticeStepX = 0.0;
		Pad[pi].LatticeStepY = 0.0;
		Pad[pi].LatticeDiagonal = 0.0;
		Pad[pi].Rf = 0.0;
		Pad[pi].Rs = 0.0;
		strcpy(Pad[pi].Label,"\0");
		strcpy(Pad[pi].Name,"\0");
		
		for (fi=0;fi<MAX_FIBER;fi++) Pad[pi].Fiber[fi].status = OFF;
		for (si=0;si<MAX_SOURCE;si++) Pad[pi].Source[si].status = OFF;			
		}
	//P.Num.Fiber = MAX_FIBER;	// da TRS 
	//P.Num.Source = MAX_SOURCE;// da TRS 
}

/* CREATE PAD */
int CVICALLBACK CreatePad (int panel, int control, int event,void *callbackData, int eventData1, int eventData2){
	char px;
	char *py;
	char ctrlname[STRLEN];
	int fi,si,pi,oi;
	int valctrl;
	int xpos, ypos;
	
	switch (event){
		case EVENT_VAL_CHANGED:
	
			/* SET PAD NUM */
			GetCtrlAttribute (panel, control, ATTR_CONSTANT_NAME, ctrlname);
			if(StringLength (ctrlname) < 12){ //RING_PAD_1, ...,RING_PAD_9  
				py = &ctrlname[9];
				pa = atoi(py);
				}
			else{  //RING_PAD_10, ...,RING_PAD_16
				py = &ctrlname[10];
				pa = atoi(py);
				pa += 10;
				}
			pa--; //base 0
			
			Pad[pa].Name[0]='P';
			Pad[pa].Name[1]='A';
			Pad[pa].Name[2]='D';
			Pad[pa].Name[3]='_';
			if (pa<9){
				Pad[pa].Name[4]='0';
				px = (char) (pa+1);
				}
			else{
				Pad[pa].Name[4]='1';
				px = (char) (pa+1-10);
				}
			Pad[pa].Name[5]=ASCII+px;
			Pad[pa].Name[6]='\0';
			SetCtrlVal(hGeom,GEOMETRY_PADACTUAL,pa+1);
			
			
	
			GetCtrlVal(panel,control,&valctrl);
			if ((valctrl != NONE)&&(Pad[pa].hPad > 0)){
				SetCtrlVal(panel,control,0);
				}
			
			GetCtrlVal(hGeom,GEOMETRY_RING_PAD_1+pa,&Pad[pa].LatticeType);
			switch (Pad[pa].LatticeType){
				
				case NONE:
					if (Pad[pa].Pad != 0){
					DiscardPanel (Pad[pa].hPad);
					if (totpad>0) SetCtrlVal(hGeom,GEOMETRY_NUMPAD,--totpad);
					if (totfiber-Pad[pa].numfiber>=0){
						totfiber -= Pad[pa].numfiber;
						SetCtrlVal(hGeom,GEOMETRY_NUMFIBER,totfiber);
						}
					if (totsource-Pad[pa].numsource>=0){
						totsource -= Pad[pa].numsource;
						SetCtrlVal(hGeom,GEOMETRY_NUMSOURCE,totsource);
						}
					SetTableCellVal (hGeom, GEOMETRY_TABLE_PAD, MakePoint(1,pa+1), 0);
					SetTableCellVal (hGeom, GEOMETRY_TABLE_PAD, MakePoint(2,pa+1), 0);
					SetTableCellVal (hGeom, GEOMETRY_TABLE_PAD, MakePoint(3,pa+1), 0);
					Pad[pa].numsource = 0;
					Pad[pa].numfiber = 0;
					for (fi=0;fi<MAX_FIBER;fi++)
						if (Pad[pa].Fiber[fi].status == ON)
							for (pi=0;pi<MAX_PAD;pi++) Pad[pi].Fiber[fi].status = OFF;
					for (si=0;si<MAX_SOURCE;si++)
						if (Pad[pa].Source[si].status == ON)
							for (pi=0;pi<MAX_PAD;pi++) Pad[pi].Source[si].status = OFF;
								
					Pad[pa].hPad = NOT_AVAILABLE;
					Pad[pa].Pad = OFF;
					Pad[pa].LatticeStepX = 0.0;
					Pad[pa].LatticeStepY = 0.0;
					Pad[pa].LatticeDiagonal = 0.0;
					Pad[pa].Rf = 0.0;
					Pad[pa].Rs = 0.0;
					Pad[pa].Nn = 0.0;
					for (oi=0;oi<NEAR_NEIGH;oi++) Pad[pa].NearNeigh[oi] = 0;
					Pad[pa].NearNeigh[0] = 1;
					strcpy(Pad[pa].Label,"\0");
					SetCtrlVal (panel, GEOMETRY_PAD_LABEL_1+pa, Pad[pa].Label);
					
					SetCtrlVal(hGeom,GEOMETRY_LATTICE_CTRL,Pad[pa].LatticeCtrl);
					SetCtrlVal(hGeom,GEOMETRY_PAD_STEP_ROW,Pad[pa].LatticeStepX);
					SetCtrlVal(hGeom,GEOMETRY_PAD_STEP_COL,Pad[pa].LatticeStepY);
					SetCtrlVal(hGeom,GEOMETRY_PAD_DIAG,Pad[pa].LatticeDiagonal);
					SetCtrlVal(hGeom,GEOMETRY_FIBER_RADIUS,Pad[pa].Rf);
					SetCtrlVal(hGeom,GEOMETRY_SOURCE_RADIUS,Pad[pa].Rs);
					SetCtrlVal(hGeom,GEOMETRY_PAD_REFINDEX,Pad[pa].Nn);
					for (oi=0;oi<NEAR_NEIGH;oi++) 
						SetCtrlVal(hGeom,GEOMETRY_NEIGH_1+oi,Pad[pa].NearNeigh[oi]);
					SetCtrlVal(hGeom,GEOMETRY_BS_PAD_1+pa,0);
					for (pi=0;pi<MAX_PAD;pi++){
						if(Pad[pi].hPad != NOT_AVAILABLE){
							pa = pi;
							break;
							}
						}
					if (Pad[pa].hPad != NOT_AVAILABLE){
						DisplayPanel(Pad[pa].hPad);
						SetCtrlVal(hGeom,GEOMETRY_PADACTUAL,pa+1);
						SetCtrlVal(hGeom,GEOMETRY_LATTICE_CTRL,Pad[pa].LatticeCtrl);
						SetCtrlVal(hGeom,GEOMETRY_PAD_STEP_ROW,Pad[pa].LatticeStepX);
						SetCtrlVal(hGeom,GEOMETRY_PAD_STEP_COL,Pad[pa].LatticeStepY);
						SetCtrlVal(hGeom,GEOMETRY_PAD_DIAG,Pad[pa].LatticeDiagonal);
						SetCtrlVal(hGeom,GEOMETRY_FIBER_RADIUS,Pad[pa].Rf);
						SetCtrlVal(hGeom,GEOMETRY_SOURCE_RADIUS,Pad[pa].Rs);
						for (oi=0;oi<NEAR_NEIGH;oi++) 
							SetCtrlVal(hGeom,GEOMETRY_NEIGH_1+oi,Pad[pa].NearNeigh[oi]);
						}
					else{
						DisplayPanel(hGeom);
						SetCtrlVal(hGeom,GEOMETRY_PADACTUAL,0);
						}
						}
				break;
					
				case SQUARE:
					/* CREATE NEW PAD */
					Pad[pa].hPad = NewPanel (hGeom, Pad[pa].Name, PAD_TOP, PAD_LEFT, PAD_HEIGHT, PAD_WIDTH);
					SetActivePanel (Pad[pa].hPad);
					SetPanelAttribute (Pad[pa].hPad, ATTR_MOVABLE, OFF);
					SetPanelAttribute (Pad[pa].hPad, ATTR_SIZABLE, OFF);
					
					step_row = STEP_ROW;
					step_col = step_row;
					for (ir=0;ir<MAX_PAD_ROW;ir++)
						for (ic=0;ic<MAX_PAD_COL;ic++){
						
							/* SET CELL LABEL */
							Pad[pa].Cell[ir][ic].Label[0]='R';
							Pad[pa].Cell[ir][ic].Label[1]='_';
							if (ir<10){
								Pad[pa].Cell[ir][ic].Label[2]='0';
								Pad[pa].Cell[ir][ic].Label[3]=ASCII+ir;
								}
							else{
								Pad[pa].Cell[ir][ic].Label[2]='1';
								px = (char) (ir+1-10);
								Pad[pa].Cell[ir][ic].Label[3]=ASCII+px;
								}
								
							Pad[pa].Cell[ir][ic].Label[4]='_';
							Pad[pa].Cell[ir][ic].Label[5]='C';
							Pad[pa].Cell[ir][ic].Label[6]='_';
							if (ic<10){
								Pad[pa].Cell[ir][ic].Label[7]='0';
								Pad[pa].Cell[ir][ic].Label[8]=ASCII+ic;
								}
							else{
								Pad[pa].Cell[ir][ic].Label[7]='1';
								px = (char) (ic+1-10);
								Pad[pa].Cell[ir][ic].Label[8]=ASCII+px;
								}
							Pad[pa].Cell[ir][ic].Label[9]='\0';
							
							/* CREATE CTRL */
							xpos = TOP +ir*step_row;
							ypos = LEFT + ic*step_col;
							cid[pa][ir][ic] = NewCtrl (Pad[pa].hPad, CTRL_NUMERIC, Pad[pa].Cell[ir][ic].Label, xpos,ypos);
							SetCtrlAttribute (Pad[pa].hPad, cid[pa][ir][ic], ATTR_WIDTH, WIDTH);
							SetCtrlAttribute (Pad[pa].hPad, cid[pa][ir][ic], ATTR_DATA_TYPE, VAL_INTEGER);
							SetCtrlAttribute (Pad[pa].hPad, cid[pa][ir][ic], ATTR_SHOW_INCDEC_ARROWS, 0);
							SetCtrlAttribute (Pad[pa].hPad, cid[pa][ir][ic], ATTR_TEXT_COLOR, VAL_PANEL_GRAY);
							SetCtrlAttribute (Pad[pa].hPad, cid[pa][ir][ic], ATTR_TEXT_BGCOLOR,VAL_PANEL_GRAY);
							SetCtrlAttribute (Pad[pa].hPad, cid[pa][ir][ic],ATTR_LABEL_VISIBLE, 0);
							InstallCtrlCallback (Pad[pa].hPad, cid[pa][ir][ic], SetType, 0);

							Pad[pa].Cell[ir][ic].status = 0;

							}
					DisplayPanel (Pad[pa].hPad);
					SetCtrlVal(hGeom,GEOMETRY_NUMPAD,++totpad);
				break;
					
				case RECTANGULAR:
					/* CREATE NEW PAD */
					Pad[pa].hPad = NewPanel (hGeom, Pad[pa].Name, PAD_TOP, PAD_LEFT, PAD_HEIGHT, PAD_WIDTH);
					SetActivePanel (Pad[pa].hPad);
					SetPanelAttribute (Pad[pa].hPad, ATTR_MOVABLE, OFF);
					SetPanelAttribute (Pad[pa].hPad, ATTR_SIZABLE, OFF);
					
					step_row = RECT_FACT_ROW*STEP_ROW;
					step_col = RECT_FACT_COL*STEP_COL;
					for (ir=0;ir<MAX_PAD_ROW;ir++)
						for (ic=0;ic<MAX_PAD_COL;ic++){
						
							/* SET CELL LABEL */
							Pad[pa].Cell[ir][ic].Label[0]='R';
							Pad[pa].Cell[ir][ic].Label[1]='_';
							if (ir<10){
								Pad[pa].Cell[ir][ic].Label[2]='0';
								Pad[pa].Cell[ir][ic].Label[3]=ASCII+ir;
								}
							else{
								Pad[pa].Cell[ir][ic].Label[2]='1';
								px = (char) (ir+1-10);
								Pad[pa].Cell[ir][ic].Label[3]=ASCII+px;
								}
								
							Pad[pa].Cell[ir][ic].Label[4]='_';
							Pad[pa].Cell[ir][ic].Label[5]='C';
							Pad[pa].Cell[ir][ic].Label[6]='_';
							if (ic<10){
								Pad[pa].Cell[ir][ic].Label[7]='0';
								Pad[pa].Cell[ir][ic].Label[8]=ASCII+ic;
								}
							else{
								Pad[pa].Cell[ir][ic].Label[7]='1';
								px = (char) (ic+1-10);
								Pad[pa].Cell[ir][ic].Label[8]=ASCII+px;
								}
							Pad[pa].Cell[ir][ic].Label[9]='\0';
							
							/* CREATE CTRL */
							xpos = TOP +ir*step_row;
							ypos = LEFT + ic*step_col;
							cid[pa][ir][ic] = NewCtrl (Pad[pa].hPad, CTRL_NUMERIC, Pad[pa].Cell[ir][ic].Label, xpos,ypos);
							SetCtrlAttribute (Pad[pa].hPad, cid[pa][ir][ic], ATTR_WIDTH, WIDTH);
							SetCtrlAttribute (Pad[pa].hPad, cid[pa][ir][ic], ATTR_DATA_TYPE, VAL_INTEGER);
							SetCtrlAttribute (Pad[pa].hPad, cid[pa][ir][ic], ATTR_SHOW_INCDEC_ARROWS, 0);
							SetCtrlAttribute (Pad[pa].hPad, cid[pa][ir][ic], ATTR_TEXT_COLOR, VAL_PANEL_GRAY);
							SetCtrlAttribute (Pad[pa].hPad, cid[pa][ir][ic], ATTR_TEXT_BGCOLOR,VAL_PANEL_GRAY);
							SetCtrlAttribute (Pad[pa].hPad, cid[pa][ir][ic],ATTR_LABEL_VISIBLE, 0);
							InstallCtrlCallback (Pad[pa].hPad, cid[pa][ir][ic], SetType, 0);

							Pad[pa].Cell[ir][ic].status = 0;

							}
					DisplayPanel (Pad[pa].hPad);
					SetCtrlVal(hGeom,GEOMETRY_NUMPAD,++totpad);
				break;
					
				case HESAGONAL:
					/* CREATE NEW PAD */
					Pad[pa].hPad = NewPanel (hGeom, Pad[pa].Name, PAD_TOP, PAD_LEFT, PAD_HEIGHT, PAD_WIDTH);
					SetActivePanel (Pad[pa].hPad);
					SetPanelAttribute (Pad[pa].hPad, ATTR_MOVABLE, OFF);
					SetPanelAttribute (Pad[pa].hPad, ATTR_SIZABLE, OFF);
			
					step_row = STEP_ROW*(0.5)*pow(3,0.5);//0.87 = (0.5)*[(3)^(0.5)]
					step_col = STEP_ROW;
					for (ir=0;ir<MAX_PAD_ROW;ir++)
						for (ic=0;ic<MAX_PAD_COL;ic++){
						
							/* SET CELL LABEL */
							Pad[pa].Cell[ir][ic].Label[0]='R';
							Pad[pa].Cell[ir][ic].Label[1]='_';
							if (ir<10){
								Pad[pa].Cell[ir][ic].Label[2]='0';
								Pad[pa].Cell[ir][ic].Label[3]=ASCII+ir;
								}
							else{
								Pad[pa].Cell[ir][ic].Label[2]='1';
								px = (char) (ir+1-10);
								Pad[pa].Cell[ir][ic].Label[3]=ASCII+px;
								}
								
							Pad[pa].Cell[ir][ic].Label[4]='_';
							Pad[pa].Cell[ir][ic].Label[5]='C';
							Pad[pa].Cell[ir][ic].Label[6]='_';
							if (ic<10){
								Pad[pa].Cell[ir][ic].Label[7]='0';
								Pad[pa].Cell[ir][ic].Label[8]=ASCII+ic;
								}
							else{
								Pad[pa].Cell[ir][ic].Label[7]='1';
								px = (char) (ic+1-10);
								Pad[pa].Cell[ir][ic].Label[8]=ASCII+px;
								}
							Pad[pa].Cell[ir][ic].Label[9]='\0';
							
							/* CREATE CTRL */
							xpos = TOP +ir*step_row;
							ypos = LEFT + ic*step_col+fmod (ir, 2)*step_col/2;
							cid[pa][ir][ic] = NewCtrl (Pad[pa].hPad, CTRL_NUMERIC, Pad[pa].Cell[ir][ic].Label, xpos,ypos);
							SetCtrlAttribute (Pad[pa].hPad, cid[pa][ir][ic], ATTR_WIDTH, WIDTH);
							SetCtrlAttribute (Pad[pa].hPad, cid[pa][ir][ic], ATTR_DATA_TYPE, VAL_INTEGER);
							SetCtrlAttribute (Pad[pa].hPad, cid[pa][ir][ic], ATTR_SHOW_INCDEC_ARROWS, 0);
							SetCtrlAttribute (Pad[pa].hPad, cid[pa][ir][ic], ATTR_TEXT_COLOR, VAL_PANEL_GRAY);
							SetCtrlAttribute (Pad[pa].hPad, cid[pa][ir][ic], ATTR_TEXT_BGCOLOR,VAL_PANEL_GRAY);
							SetCtrlAttribute (Pad[pa].hPad, cid[pa][ir][ic],ATTR_LABEL_VISIBLE, 0);
							InstallCtrlCallback (Pad[pa].hPad, cid[pa][ir][ic], SetType, 0);

							Pad[pa].Cell[ir][ic].status = 0;

							}
					DisplayPanel (Pad[pa].hPad);
					SetCtrlVal(hGeom,GEOMETRY_NUMPAD,++totpad);
				break;
				}
		break;
			}
			
		return 0;
}


/* SET TYPE (SOURCE OR FIBER)*/
int CVICALLBACK SetType (int panel, int control, int event,void *callbackData, int eventData1, int eventData2)
{
	char *p1,*p2,*p3,*p4;
	char ctrlname[STRLEN],label[STRLEN],label1[STRLEN],label2[STRLEN],label3[STRLEN],label4[STRLEN];
	int fi,si,pi;
	int ir, ic;
	
	
	GetCtrlVal(hGeom,GEOMETRY_PADACTUAL,&pa);
	pa--;//zero base
	GetCtrlVal(hGeom,GEOMETRY_NUMFIBER,&totfiber);
	GetCtrlVal(hGeom,GEOMETRY_NUMSOURCE,&totsource);
	GetTableCellVal (hGeom, GEOMETRY_TABLE_PAD, MakePoint(2,pa+1),&Pad[pa].numsource);
	GetTableCellVal (hGeom, GEOMETRY_TABLE_PAD, MakePoint(3,pa+1),&Pad[pa].numfiber);
	sourcex = Pad[pa].numsource;
	fiberx = Pad[pa].numfiber;
	
	SetActivePanel (panel);
	GetCtrlAttribute (panel, control, ATTR_CTRL_VAL, &valctrl);
	GetCtrlAttribute (panel, control, ATTR_TEXT_BGCOLOR, &colctrl);
	
	/* IDENTIFY CONTROL */
	GetCtrlAttribute (panel, control, ATTR_LABEL_TEXT, label);
	strcpy(label1,label);
	p1 = &label1[2];p1[1]='\0';
	
	strcpy(label2,label);
	p2 = &label2[3];p2[1]='\0';
	
	ir = 10*atoi(p1)+atoi(p2);
	
	strcpy(label3,label);
	p3 = &label3[7];p3[1]='\0';
	
	strcpy(label4,label);
	p4 = &label4[8];p4[1]='\0';
	
	ic = 10*atoi(p3)+atoi(p4);
	
	
	switch (event){
		case EVENT_LEFT_DOUBLE_CLICK:
		case EVENT_LEFT_CLICK:
			if (valctrl==0){// from NOT_USED to FIBER 
				if((totfiber) < P.Num.Fiber){
					++fiberx;++totfiber;
					for (fi=0;fi<MAX_FIBER;fi++){ if(Pad[pa].Fiber[fi].status == NOT_USED) break;}
					SetCtrlAttribute (panel, control, ATTR_TEXT_BGCOLOR, VAL_GREEN);
					SetCtrlAttribute (panel, control, ATTR_CTRL_VAL, fi+1);
					SetCtrlAttribute (panel, control, ATTR_TEXT_COLOR, VAL_BLACK);
					Pad[pa].Fiber[fi].status = ON;
					Pad[pa].Fiber[fi].row = ir;
					Pad[pa].Fiber[fi].col = ic;
					for (pi=0;pi<MAX_PAD;pi++) if(pi!=pa) Pad[pi].Fiber[fi].status = NOT_AVAILABLE;// NOT AVAILABLE TO OTHER PADS
					Pad[pa].Cell[ir][ic].status = FIBER;
					Pad[pa].Cell[ir][ic].Name = fi+1;
					}
				else
					MessagePopup ("WARNING", "YOU HAVE REACHED THE MAXIMUM NUMBER OF FIBERS!");
				}
			if ((valctrl!=0)&(colctrl == VAL_GREEN)){// from FIBER to NOT_USED
				--fiberx;--totfiber;
				SetCtrlAttribute (panel, control, ATTR_TEXT_BGCOLOR, VAL_PANEL_GRAY);
				SetCtrlAttribute (panel, control, ATTR_CTRL_VAL, 0);
				SetCtrlAttribute (panel, control, ATTR_TEXT_COLOR, VAL_PANEL_GRAY);
				for (pi=0;pi<MAX_PAD;pi++) Pad[pi].Fiber[valctrl-1].status = OFF; // AVAILABLE TO ALL PADS
				Pad[pa].Cell[ir][ic].status = NOT_USED;
				Pad[pa].Cell[ir][ic].Name = NOT_USED;
				}
			if ((valctrl!=0)&(colctrl == VAL_RED)){// from SOURCE to NOT_USED
				--sourcex;--totsource;
				SetCtrlAttribute (panel, control, ATTR_TEXT_BGCOLOR, VAL_PANEL_GRAY);
				SetCtrlAttribute (panel, control, ATTR_CTRL_VAL, 0);
				SetCtrlAttribute (panel, control, ATTR_TEXT_COLOR, VAL_PANEL_GRAY);
				for (pi=0;pi<MAX_PAD;pi++) Pad[pi].Source[valctrl-1].status = OFF;// AVAILABLE TO ALL PADS
				Pad[pa].Cell[ir][ic].status = NOT_USED;
				Pad[pa].Cell[ir][ic].Name = NOT_USED;
				} 
			GetCtrlAttribute (panel, control, ATTR_LABEL_TEXT, ctrlname);
			break;
	 	
		case EVENT_RIGHT_DOUBLE_CLICK:
		case EVENT_RIGHT_CLICK:
			if (valctrl==0){// from NOT_USED to SOURCE
				if((totsource) < P.Num.Source){
					++sourcex;++totsource;
					for (si=0;si<MAX_SOURCE;si++){ if(Pad[pa].Source[si].status == NOT_USED) break;}
					SetCtrlAttribute (panel, control, ATTR_TEXT_BGCOLOR, VAL_RED);
					SetCtrlAttribute (panel, control, ATTR_CTRL_VAL, si+1);
					SetCtrlAttribute (panel, control, ATTR_TEXT_COLOR, VAL_BLACK);
					Pad[pa].Source[si].status = ON;
					Pad[pa].Source[si].row = ir;
					Pad[pa].Source[si].col = ic;
					for (pi=0;pi<MAX_PAD;pi++) if(pi!=pa) Pad[pi].Source[si].status = NOT_AVAILABLE;// NOT AVAILABLE TO OTHER PADS
					Pad[pa].Cell[ir][ic].status = SOURCE;
					Pad[pa].Cell[ir][ic].Name = si+1;
					}
				else
					MessagePopup ("WARNING", "YOU HAVE REACHED THE MAXIMUM NUMBER OF SOURCES!");
				}
			if ((valctrl!=0)&(colctrl == VAL_GREEN)){// from FIBER to SOURCE 
				if((totsource) < P.Num.Source){
					++sourcex;--fiberx;--totfiber;++totsource;
					for (si=0;si<MAX_SOURCE;si++){ if(Pad[pa].Source[si].status == NOT_USED) break;}
					SetCtrlAttribute (panel, control, ATTR_TEXT_BGCOLOR, VAL_RED);
					SetCtrlAttribute (panel, control, ATTR_CTRL_VAL, si+1);
					SetCtrlAttribute (panel, control, ATTR_TEXT_COLOR, VAL_BLACK);
					for (pi=0;pi<MAX_PAD;pi++) Pad[pi].Fiber[valctrl-1].status = OFF; // AVAILABLE TO ALL PADS
					Pad[pa].Source[si].status = ON;
					Pad[pa].Source[si].row = ir;
					Pad[pa].Source[si].col = ic;
					for (pi=0;pi<MAX_PAD;pi++) if(pi!=pa) Pad[pi].Source[si].status = NOT_AVAILABLE;// NOT AVAILABLE TO OTHER PADS
					Pad[pa].Cell[ir][ic].status = SOURCE;
					Pad[pa].Cell[ir][ic].Name = si+1;
					}
				else
					MessagePopup ("WARNING", "YOU HAVE REACHED THE MAXIMUM NUMBER OF SOURCES!");
				}
			if ((valctrl!=0)&(colctrl == VAL_RED)){// from SOURCE to FIBER 
				if((totfiber) < P.Num.Fiber){
					--sourcex;--totsource;++fiberx;++totfiber;
					for (fi=0;fi<MAX_FIBER;fi++){ if(Pad[pa].Fiber[fi].status == NOT_USED) break;}
					SetCtrlAttribute (panel, control, ATTR_TEXT_BGCOLOR, VAL_GREEN);
					SetCtrlAttribute (panel, control, ATTR_CTRL_VAL, fi+1);
					SetCtrlAttribute (panel, control, ATTR_TEXT_COLOR, VAL_BLACK);
					Pad[pa].Fiber[fi].status = ON;
					Pad[pa].Fiber[fi].row = ir;
					Pad[pa].Fiber[fi].col = ic;
					for (pi=0;pi<MAX_PAD;pi++) if(pi!=pa) Pad[pi].Fiber[fi].status = NOT_AVAILABLE;// NOT AVAILABLE TO OTHER PADS
					for (pi=0;pi<MAX_PAD;pi++) Pad[pi].Source[valctrl-1].status = OFF; // AVAILABLE TO ALL PADS
					Pad[pa].Cell[ir][ic].status = FIBER;
					Pad[pa].Cell[ir][ic].Name = fi+1;
					}
				else
					MessagePopup ("WARNING", "YOU HAVE REACHED THE MAXIMUM NUMBER OF FIBERS!");
		 		}
			break;
		 	}

	SetCtrlVal (hGeom, GEOMETRY_NUMSOURCE, totsource);
	SetCtrlVal (hGeom, GEOMETRY_NUMFIBER, totfiber);
		 	
	SetTableCellVal (hGeom, GEOMETRY_TABLE_PAD, MakePoint(1,pa+1), 1);
	SetTableCellVal (hGeom, GEOMETRY_TABLE_PAD, MakePoint(2,pa+1), sourcex);
	SetTableCellVal (hGeom, GEOMETRY_TABLE_PAD, MakePoint(3,pa+1), fiberx);
	Pad[pa].numsource = sourcex;
	Pad[pa].numfiber = fiberx;

	return 0;
}


int CVICALLBACK PropPad (int panel, int control, int event,void *callbackData, int eventData1, int eventData2){

	int oi,fi,si;
	int valctrl;

	switch (event)
		{
		case EVENT_COMMIT:
			GetCtrlVal(hGeom,GEOMETRY_PADACTUAL,&valctrl);
			pa = valctrl-1;
			GetCtrlVal(panel,GEOMETRY_FIBER_RADIUS,&Pad[pa].Rf);
			GetCtrlVal(panel,GEOMETRY_SOURCE_RADIUS,&Pad[pa].Rs);
			GetCtrlVal(panel,GEOMETRY_PAD_REFINDEX,&Pad[pa].Nn);
			for (oi=0;oi<NEAR_NEIGH;oi++) 
				GetCtrlVal(panel,GEOMETRY_NEIGH_1+oi,&Pad[pa].NearNeigh[oi]);
			GetCtrlVal(panel,GEOMETRY_LATTICE_CTRL,&Pad[pa].LatticeCtrl);
			switch (Pad[pa].LatticeType){
				case SQUARE:
					if (Pad[pa].LatticeCtrl == STEP_CTRL){
						GetCtrlVal(panel,GEOMETRY_PAD_STEP_ROW,&Pad[pa].LatticeStepX);
						Pad[pa].LatticeStepY = Pad[pa].LatticeStepX;
						Pad[pa].LatticeDiagonal = pow(2,0.5)*Pad[pa].LatticeStepX;
						SetCtrlVal(panel,GEOMETRY_PAD_STEP_COL,Pad[pa].LatticeStepY);
						SetCtrlVal(panel,GEOMETRY_PAD_DIAG,Pad[pa].LatticeDiagonal);
						SetCtrlAttribute (panel, GEOMETRY_PAD_STEP_ROW, ATTR_TEXT_BGCOLOR,VAL_WHITE);
						SetCtrlAttribute (panel, GEOMETRY_PAD_STEP_COL, ATTR_TEXT_BGCOLOR,VAL_PANEL_GRAY);
						SetCtrlAttribute (panel, GEOMETRY_PAD_DIAG, ATTR_TEXT_BGCOLOR,VAL_PANEL_GRAY);
						}
					if (Pad[pa].LatticeCtrl == DIAG_CTRL){
						GetCtrlVal(panel,GEOMETRY_PAD_DIAG,&Pad[pa].LatticeDiagonal);
						Pad[pa].LatticeStepX = Pad[pa].LatticeDiagonal/pow(2,0.5);
						Pad[pa].LatticeStepY = Pad[pa].LatticeStepX;
						SetCtrlVal(panel,GEOMETRY_PAD_STEP_ROW,Pad[pa].LatticeStepX);
						SetCtrlVal(panel,GEOMETRY_PAD_STEP_COL,Pad[pa].LatticeStepY);
						SetCtrlAttribute (panel, GEOMETRY_PAD_STEP_ROW, ATTR_TEXT_BGCOLOR,VAL_PANEL_GRAY);
						SetCtrlAttribute (panel, GEOMETRY_PAD_STEP_COL, ATTR_TEXT_BGCOLOR,VAL_PANEL_GRAY);
						SetCtrlAttribute (panel, GEOMETRY_PAD_DIAG, ATTR_TEXT_BGCOLOR,VAL_WHITE);
						}
					for (ir=0;ir<MAX_PAD_ROW;ir++){
						for (ic=0;ic<MAX_PAD_COL;ic++){
							/* SET CELL COORDINATES */
							Pad[pa].Cell[ir][ic].x = ir*Pad[pa].LatticeStepX;
							Pad[pa].Cell[ir][ic].y = ic*Pad[pa].LatticeStepY;
							Pad[pa].Cell[ir][ic].z = 0;
							}
						}
					break;
				case RECTANGULAR:
					if (Pad[pa].LatticeCtrl == STEP_CTRL){
						GetCtrlVal(panel,GEOMETRY_PAD_STEP_ROW,&Pad[pa].LatticeStepX);
						GetCtrlVal(panel,GEOMETRY_PAD_STEP_COL,&Pad[pa].LatticeStepY);
						Pad[pa].LatticeDiagonal = Pad[pa].LatticeDiagonal = pow((pow(Pad[pa].LatticeStepX,2)+pow(Pad[pa].LatticeStepY,2)),0.5);
						SetCtrlVal(panel,GEOMETRY_PAD_DIAG,Pad[pa].LatticeDiagonal);
						SetCtrlAttribute (panel, GEOMETRY_PAD_STEP_ROW, ATTR_TEXT_BGCOLOR,VAL_WHITE);
						SetCtrlAttribute (panel, GEOMETRY_PAD_STEP_COL, ATTR_TEXT_BGCOLOR,VAL_WHITE);
						SetCtrlAttribute (panel, GEOMETRY_PAD_DIAG, ATTR_TEXT_BGCOLOR,VAL_PANEL_GRAY);
						}
					if (Pad[pa].LatticeCtrl == DIAG_CTRL){
						GetCtrlVal(panel,GEOMETRY_PAD_STEP_ROW,&Pad[pa].LatticeStepX);
						GetCtrlVal(panel,GEOMETRY_PAD_DIAG,&Pad[pa].LatticeDiagonal);
						Pad[pa].LatticeStepY = pow((pow(Pad[pa].LatticeDiagonal,2)-pow(Pad[pa].LatticeStepX,2)),0.5);
						SetCtrlVal(panel,GEOMETRY_PAD_STEP_COL,Pad[pa].LatticeStepY);
						SetCtrlAttribute (panel, GEOMETRY_PAD_STEP_ROW, ATTR_TEXT_BGCOLOR,VAL_WHITE);
						SetCtrlAttribute (panel, GEOMETRY_PAD_STEP_COL, ATTR_TEXT_BGCOLOR,VAL_PANEL_GRAY);
						SetCtrlAttribute (panel, GEOMETRY_PAD_DIAG, ATTR_TEXT_BGCOLOR,VAL_WHITE);
						}
					for (ir=0;ir<MAX_PAD_ROW;ir++){
						for (ic=0;ic<MAX_PAD_COL;ic++){
							/* SET CELL COORDINATES */
							Pad[pa].Cell[ir][ic].x = ir*Pad[pa].LatticeStepX;
							Pad[pa].Cell[ir][ic].y = ic*Pad[pa].LatticeStepY;
							Pad[pa].Cell[ir][ic].z = 0;
							}
						}
					break;
				case HESAGONAL:
					SetCtrlVal(panel,GEOMETRY_LATTICE_CTRL,DIAG_CTRL);
					GetCtrlVal(panel,GEOMETRY_PAD_DIAG,&Pad[pa].LatticeDiagonal);
					Pad[pa].LatticeStepX = Pad[pa].LatticeDiagonal*(0.5)*pow(3,0.5);
					Pad[pa].LatticeStepY = Pad[pa].LatticeDiagonal;
					SetCtrlVal(panel,GEOMETRY_PAD_STEP_ROW,Pad[pa].LatticeStepX);
					SetCtrlVal(panel,GEOMETRY_PAD_STEP_COL,Pad[pa].LatticeStepY);
					SetCtrlAttribute (panel, GEOMETRY_PAD_STEP_ROW, ATTR_TEXT_BGCOLOR,VAL_PANEL_GRAY);
					SetCtrlAttribute (panel, GEOMETRY_PAD_STEP_COL, ATTR_TEXT_BGCOLOR,VAL_PANEL_GRAY);
					SetCtrlAttribute (panel, GEOMETRY_PAD_DIAG, ATTR_TEXT_BGCOLOR,VAL_WHITE);
					for (ir=0;ir<MAX_PAD_ROW;ir++){
						for (ic=0;ic<MAX_PAD_COL;ic++){
							/* SET CELL COORDINATES */
							Pad[pa].Cell[ir][ic].x = ir*Pad[pa].LatticeStepX;
							Pad[pa].Cell[ir][ic].y = (ic+fmod(ir, 2)/2)*Pad[pa].LatticeStepY;
							Pad[pa].Cell[ir][ic].z = 0;
							}
						}
					break;
				}
				for (fi=0;fi<MAX_FIBER;fi++){
					for (ir=0;ir<MAX_PAD_ROW;ir++){
						for (ic=0;ic<MAX_PAD_COL;ic++){
							if((Pad[pa].Cell[ir][ic].status == FIBER)&&(Pad[pa].Cell[ir][ic].Name == fi+1)){
								Pad[pa].Fiber[fi].x = Pad[pa].Cell[ir][ic].x;
								Pad[pa].Fiber[fi].y = Pad[pa].Cell[ir][ic].y;
								Pad[pa].Fiber[fi].z = Pad[pa].Cell[ir][ic].z;
								}
							}
						}
					}
				for (si=0;si<MAX_SOURCE;si++){
					for (ir=0;ir<MAX_PAD_ROW;ir++){
						for (ic=0;ic<MAX_PAD_COL;ic++){
							if((Pad[pa].Cell[ir][ic].status == SOURCE)&&(Pad[pa].Cell[ir][ic].Name == si+1)){
								Pad[pa].Source[si].x = Pad[pa].Cell[ir][ic].x;
								Pad[pa].Source[si].y = Pad[pa].Cell[ir][ic].y;
								Pad[pa].Source[si].z = Pad[pa].Cell[ir][ic].z;
								}
							}
						}
					}
				
			break;
		}
	return 0;
}

int CVICALLBACK ShowPad (int panel, int control, int event,void *callbackData, int eventData1, int eventData2)
{
	int pi,oi;
	int valctrl;
	
	switch (event){
		case EVENT_COMMIT:
			
			GetCtrlVal(hGeom,GEOMETRY_PADACTUAL,&valctrl);
			if ((valctrl>0)&&(valctrl<=MAX_PAD)){
				pa = valctrl - 1;
				}
			else{
				for (pi=0;pi<MAX_PAD;pi++){
					if(Pad[pi].hPad != NOT_AVAILABLE){
						pa = pi;
						SetCtrlVal(hGeom,GEOMETRY_PADACTUAL,pa+1);
						break;
						}
					}
			}
			if(Pad[pa].hPad != NOT_AVAILABLE){
				SetPanelAttribute (Pad[pa].hPad, ATTR_VISIBLE, ON);
				DisplayPanel(Pad[pa].hPad);
				}
			else{
				for (pi=0;pi<MAX_PAD;pi++){
					if(Pad[pi].hPad != NOT_AVAILABLE){
						SetPanelAttribute (Pad[pi].hPad, ATTR_VISIBLE, OFF);
						HidePanel(Pad[pi].hPad);
						}
					}
				DisplayPanel(hGeom);				
				}
			/* READ ALL BINARY SWITCHES */
			for (pi=0;pi<MAX_PAD;pi++){
				GetCtrlVal(hGeom,GEOMETRY_BS_PAD_1+pi,&bs_pad[pi]);
				Pad[pi].Pad = bs_pad[pi];///
				GetCtrlVal(hGeom,GEOMETRY_RING_PAD_1+pi,&ring_pad[pi]);
				bs_pad_name[pi]=GEOMETRY_BS_PAD_1+pi;
				GetCtrlVal (panel, GEOMETRY_PAD_LABEL_1+pi, Pad[pi].Label);
				}
			
			/* DISPLAY OR HIDE PAD */
			for (pi=0;pi<MAX_PAD;pi++){
				if  (ring_pad[pi] == NONE){
					SetCtrlVal(hGeom,bs_pad_name[pi],0);
					bs_pad[pi] = 0;
					Pad[pi].Pad = 0;
					}
				}
			
	for (oi=0;oi<NEAR_NEIGH;oi++) 
		SetCtrlVal(panel,GEOMETRY_NEIGH_1+oi,Pad[pa].NearNeigh[oi]);
	SetCtrlVal(panel,GEOMETRY_LATTICE_CTRL,Pad[pa].LatticeCtrl);
	SetCtrlVal(panel,GEOMETRY_PAD_STEP_ROW,Pad[pa].LatticeStepX);
	SetCtrlVal(panel,GEOMETRY_PAD_STEP_COL,Pad[pa].LatticeStepY);
	SetCtrlVal(panel,GEOMETRY_PAD_DIAG,Pad[pa].LatticeDiagonal);
	SetCtrlVal(panel,GEOMETRY_FIBER_RADIUS,Pad[pa].Rf);
	SetCtrlVal(panel,GEOMETRY_SOURCE_RADIUS,Pad[pa].Rs);
	SetCtrlVal(panel,GEOMETRY_PAD_REFINDEX,Pad[pa].Nn);
	for (pi=0;pi<MAX_PAD;pi++)
		SetCtrlVal (panel, GEOMETRY_PAD_LABEL_1+pi, Pad[pi].Label);

	break;
	}
	return 0;
}



int CVICALLBACK SaveGeom (int panel, int control, int event,void *callbackData, int eventData1, int eventData2)
{
	int fi,si,ni,oi,pi;
	int neigh_num,source_name,fiber_name;
	FILE *fid;
	double mindist,last_dist,distx;
	char source_exist[MAX_PAD],fiber_exist[MAX_PAD];
	char fo,ff;

	switch (event){
		case EVENT_COMMIT:

	SetActivePanel (panel);
	
	for (pi=0;pi<MAX_PAD;pi++)
		GetCtrlVal (panel, GEOMETRY_PAD_LABEL_1+pi, Pad[pi].Label);

	for (pi=0;pi<MAX_PAD;pi++){
		source_exist[pi]=0;
		fiber_exist[pi]=0;
		}
	for (pi=0;pi<MAX_PAD;pi++){
		if (Pad[pi].Pad == ON){
			/* CHECK SOURCE NUMBER */
			for (si=0;si<MAX_SOURCE;si++)
				if (Pad[pi].Source[si].status == ON){
					source_exist[pi] = 1;
					break;
					}
			if (!source_exist[pi]){
				MessagePopup ("WARNING", "THE PAD MUST HAVE AT LEAST ONE SOURCE");
				pa = pi;
				DisplayPanel(Pad[pa].hPad);
				SetCtrlVal(hGeom,GEOMETRY_PADACTUAL,pa+1);
				return -1;
				}
	
			/* CHECK FIBER NUMBER */
			for (fi=0;fi<MAX_FIBER;fi++)
				if (Pad[pi].Fiber[fi].status == ON){
					fiber_exist[pi] = 1;
					break;
					}
			if (!fiber_exist[pi]){
				MessagePopup ("WARNING", "THE PAD MUST HAVE AT LEAST ONE FIBER");
				pa = pi;
				DisplayPanel(Pad[pa].hPad);
				SetCtrlVal(hGeom,GEOMETRY_PADACTUAL,pa+1);
				return -1;
				}
		
		/* CALC SOURCE NEAREST NEIGHBORS */
		for (oi=0;oi<NEAR_NEIGH;oi++){
			for (si=0;si<MAX_SOURCE;si++){
				for (ni=0;ni<MAX_NEIGH;ni++) Pad[pi].Source[si].Neigh[oi][ni]=0;
				Pad[pi].Dist[oi] = 0.0;
				}
			}
		for (ir=0;ir<MAX_PAD_ROW;ir++){
			for (ic=0;ic<MAX_PAD_COL;ic++){
				if (Pad[pi].Cell[ir][ic].status == SOURCE){// is SOURCE
					source_name = Pad[pi].Cell[ir][ic].Name-1;
					last_dist = 0.0;
					for (oi=0;oi<NEAR_NEIGH;oi++){
						// CALC NEIGHBOR DISTANCES FROM ORDER 1 TO NEAR_NEIGH
						mindist = MAXDIST;
						for (jr=0;jr<MAX_PAD_ROW;jr++){
							for (jc=0;jc<MAX_PAD_COL;jc++){
								if (Pad[pi].Cell[jr][jc].status == FIBER){// is FIBER	
									distx = pow((pow((Pad[pi].Cell[jr][jc].x-Pad[pi].Cell[ir][ic].x),2)+pow((Pad[pi].Cell[jr][jc].y-Pad[pi].Cell[ir][ic].y),2)),0.5);
									if (((distx - last_dist)>DIST_TOLL) && (distx < mindist)) mindist = distx;
									}
								}
							}
						last_dist = mindist;
						Pad[pi].Dist[oi] = mindist;
						}
					for (oi=0;oi<NEAR_NEIGH;oi++){	
						// SET NEAREST NEIGHBORS
						neigh_num = 0;
						for (jr=0;jr<MAX_PAD_ROW;jr++){
							for (jc=0;jc<MAX_PAD_COL;jc++){
								if (Pad[pi].Cell[jr][jc].status == FIBER){// is FIBER	
									fiber_name = Pad[pi].Cell[jr][jc].Name;
									distx = pow((pow((Pad[pi].Cell[jr][jc].x-Pad[pi].Cell[ir][ic].x),2)+pow((Pad[pi].Cell[jr][jc].y-Pad[pi].Cell[ir][ic].y),2)),0.5);
									if (fabs(distx - Pad[pi].Dist[oi])<DIST_TOLL){
										Pad[pi].Source[source_name].Neigh[oi][neigh_num] = fiber_name;
										neigh_num++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	/* COPY PAD FIBERS AND SOURCES TO PARM STRUCT FOR FIBERS AND SOURCES */
	for (pi=0;pi<MAX_PAD;pi++){
		for (fi=0;fi<MAX_FIBER;fi++){
			if (Pad[pi].Fiber[fi].status == ON){
				P.Fiber[fi].Pad = pi+1;
				P.Fiber[fi].Xf = Pad[pi].Fiber[fi].x;
				P.Fiber[fi].Yf = Pad[pi].Fiber[fi].y;
				P.Fiber[fi].Zf = Pad[pi].Fiber[fi].z;
				P.Fiber[fi].Rf = Pad[pi].Rf;
				P.Fiber[fi].Nf = Pad[pi].Nn;
				P.Fiber[fi].row = Pad[pi].Fiber[fi].row;
				P.Fiber[fi].col = Pad[pi].Fiber[fi].col;
				}
			}
		for (si=0;si<MAX_SOURCE;si++){			
			if (Pad[pi].Source[si].status == ON){
				P.Source[si].Pad = pi+1;
				P.Source[si].Xs = Pad[pi].Source[si].x;
				P.Source[si].Ys = Pad[pi].Source[si].y;
				P.Source[si].Zs = Pad[pi].Source[si].z;
				P.Source[si].Rs = Pad[pi].Rs;
				P.Source[si].Ns = Pad[pi].Nn;
				P.Source[si].row = Pad[pi].Source[si].row;
				P.Source[si].col = Pad[pi].Source[si].col;
				}
			}
		}
	
	/* COPY NEIGHBORS TO PARM STRUCT FOR SOURCE NEIGHBORS */
	for (si=0;si<MAX_SOURCE;si++){
		for (pi=0;pi<MAX_PAD;pi++){
			if ((Pad[pi].Pad == ON)&&(P.Source[si].Pad == pi+1)){
				for (oi=0;oi<NEAR_NEIGH;oi++){
					if (Pad[pi].Dist[oi] != MAXDIST){
						for (ni=0;ni<MAX_NEIGH;ni++)
							P.Source[si].Neigh[oi][ni] = Pad[pi].Source[si].Neigh[oi][ni];
						}
					}
				}
			}
		}


	/* COPY NEIGHBORS INFO TO PROTOCOL LAYOUT */
	for (si=0;si<MAX_SOURCE;si++) strcpy(P.TProt.Fibers[si], "");
	for (pi=0;pi<MAX_PAD;pi++){
		if (Pad[pi].Pad == ON){// PAD is USED 
			for (si=0;si<MAX_SOURCE;si++){
				if (Pad[pi].Source[si].status == ON){ // SOURCE is USED
					P.TProt.Source[si]=si+1;
					fo = 1;
					for (oi=0;oi<NEAR_NEIGH;oi++){
						if(Pad[pi].NearNeigh[oi] == ON){
							if (!fo) strcat(P.TProt.Fibers[si], ",");
							ff = 1;
							for (ni=0;ni<MAX_NEIGH;ni++){
								if ((Pad[pi].Dist[oi] != MAXDIST)&&(Pad[pi].Source[si].Neigh[oi][ni] != 0)){
									if (!ff) strcat(P.TProt.Fibers[si], ",");
									Fmt (strtemp, "%s<%d", Pad[pi].Source[si].Neigh[oi][ni]);
									strcat(P.TProt.Fibers[si], strtemp);
									ff = 0;
									}
								}
							fo = 0;
							}
						}
					}
				}
			}
		}

	UpdatePanel();
	
	/* SAVE GEOMETRY FILE */
	GetCtrlVal (panel, GEOMETRY_GEO_FNAME, P.Layout.FGeometry);
	if (strcmp(P.Layout.FGeometry,"")==0) strcpy(P.Layout.FGeometry,GEO_FNAME);
	strcpy(fname,GEO_FDIR);
	strcat (fname, P.Layout.FGeometry);
	strcat (fname, GEO_FEXT);
	
	fid = fopen (fname, "w");
	fprintf(fid,"Type\tId\tCoord\tPad\tX\tY\tZ\tR\tRow\tCol\t");
	for (oi=0;oi<NEAR_NEIGH;oi++){
		fprintf(fid,"%d_NeighActive\t",oi+1);
		fprintf(fid,"%d_NeighDist\t",oi+1);
		for (ni=0;ni<MAX_NEIGH;ni++)
			fprintf(fid,"%d_Neigh%d\t",oi+1,ni+1);
		}
	fprintf(fid,"\n");
	
	for (si=0;si<MAX_SOURCE;si++){
		fprintf(fid,"S\t");
		if ((P.Source[si].Pad !=0)&&(Pad[P.Source[si].Pad-1].Pad != 0)){
			fprintf(fid,"%d\t%d\t%d\t",si+1,P.Source[si].Coord,P.Source[si].Pad);
			fprintf(fid,"%f\t%f\t%f\t%f\t",P.Source[si].Xs,P.Source[si].Ys,P.Source[si].Zs,P.Source[si].Rs);
			fprintf(fid,"%d\t%d\t",Pad[P.Source[si].Pad-1].Source[si].row,Pad[P.Source[si].Pad-1].Source[si].col);
			}
		else{
			fprintf(fid,"%d\t%d\t%d\t",0,0,0);
			fprintf(fid,"%f\t%f\t%f\t%f\t",0.0,0.0,0.0,0.0);
			fprintf(fid,"%d\t%d\t",-1,-1);
			}
		
			
		for (oi=0;oi<NEAR_NEIGH;oi++){
			if ((P.Source[si].Pad != 0)&&((Pad[P.Source[si].Pad-1].Pad != 0)))
				fprintf(fid,"%d\t",Pad[P.Source[si].Pad-1].NearNeigh[oi]);
			else
				fprintf(fid,"%d\t",0);
			if ((P.Source[si].Pad != 0)&&((Pad[P.Source[si].Pad-1].Pad != 0)))
				fprintf(fid,"%f\t",Pad[P.Source[si].Pad-1].Dist[oi]);
			else
				fprintf(fid,"%d\t",0);
			for (ni=0;ni<MAX_NEIGH;ni++)
				if ((P.Source[si].Pad !=0)&&(Pad[P.Source[si].Pad-1].Pad != 0))
					fprintf(fid,"%d\t",P.Source[si].Neigh[oi][ni]);
				else
					fprintf(fid,"%d\t",0);
			}
		fprintf(fid,"\n");
		}
	for (fi=0;fi<MAX_FIBER;fi++){
		fprintf(fid,"F\t");
		if ((P.Fiber[fi].Pad !=0)&&(Pad[P.Fiber[fi].Pad-1].Pad != 0)){
			fprintf(fid,"%d\t%d\t%d\t",fi+1,P.Fiber[fi].Coord,P.Fiber[fi].Pad);
			fprintf(fid,"%f\t%f\t%f\t%f\t",P.Fiber[fi].Xf,P.Fiber[fi].Yf,P.Fiber[fi].Zf,P.Fiber[fi].Rf);
			fprintf(fid,"%d\t%d\t",Pad[P.Fiber[fi].Pad-1].Fiber[fi].row,Pad[P.Fiber[fi].Pad-1].Fiber[fi].col);
			}
		else{
			fprintf(fid,"%d\t%d\t%d\t",0,0,0);
			fprintf(fid,"%f\t%f\t%f\t%f\t",0.0,0.0,0.0,0.0);
			fprintf(fid,"%d\t%d\t",-1,-1);
			}
		
		fprintf(fid,"\n");
		}
	fprintf(fid,"\nPAD LAYOUT");
	for (pi=0;pi<MAX_PAD;pi++){
		if (Pad[pi].Pad == ON){// PAD is USED	
			fprintf(fid,"\nPad\t%d\n",pi+1);
			fprintf(fid,"PadName\t%s\n",Pad[pi].Name);
			fprintf(fid,"PadLabel\t%s\n",Pad[pi].Label);
			fprintf(fid,"LatticeType\t%d\n",Pad[pi].LatticeType);
			fprintf(fid,"LatticeCtrl\t%d\n",Pad[pi].LatticeCtrl);
			fprintf(fid,"LatticeStepX\t%f\n",Pad[pi].LatticeStepX);
			fprintf(fid,"LatticeStepY\t%f\n",Pad[pi].LatticeStepY);
			fprintf(fid,"LatticeDiagonal\t%f\n",Pad[pi].LatticeDiagonal);
			fprintf(fid,"PadRefrIndex\t%f\n",Pad[pi].Nn);
			for (ir=0;ir<MAX_PAD_ROW;ir++){
				for (ic=0;ic<MAX_PAD_COL;ic++) fprintf(fid,"%d\t",Pad[pi].Cell[ir][ic].status);
				fprintf(fid,"\n");
				}
			}
		}
	fclose(fid);

	break;
	}
	return 0;
}


void ReadGeom(void){
	int fi,si,oi,ni,pi,tp,ir,ic;
	int id,coord,pad;
	char type;
	double x,y,z,r;
	FILE *file;
	char row[4*STRLEN];
	
	strcpy(fname,GEO_FDIR);
	strcat (fname, P.Layout.FGeometry);
	strcat (fname, GEO_FEXT);
	file=fopen(fname,"r");
	fgets(row,4*STRLEN,file);//skip header
	for (si=0;si<MAX_SOURCE;si++){
		fscanf (file, "%c\t%d\t%d\t%d\t%lf\t%lf\t%lf\t%lf\t%d\t%d",&type,&id,&coord,&pad,&x,&y,&z,&r,&ir,&ic);
		if (id !=0 ){
			P.Source[id-1].Coord=coord;
			P.Source[id-1].Pad=pad;
			P.Source[id-1].Xs=x;
			P.Source[id-1].Ys=y;
			P.Source[id-1].Zs=z;
			P.Source[id-1].row=ir;
			P.Source[id-1].col=ic;
			Pad[pad-1].Pad = ON;
			Pad[pad-1].Source[id-1].status = ON;
			Pad[pad-1].Cell[ir][ic].Name = id;
			Pad[pad-1].Rs=r;
				
			for (oi=0;oi<NEAR_NEIGH;oi++){
				fscanf (file, "\t%d",&Pad[pad-1].NearNeigh[oi]);
				fscanf (file, "\t%lf",&Pad[pad-1].Dist[oi]);
				for (ni=0;ni<MAX_NEIGH;ni++)
					fscanf (file, "\t%d",&Pad[pad-1].Source[id-1].Neigh[oi][ni]);
				}
			fscanf (file, "\n");//read new line
			}
		else
			fgets(row,4*STRLEN,file);//skip null sources
			
		}
	
	for (fi=0;fi<MAX_FIBER;fi++){
		fscanf (file, "%c\t%d\t%d\t%d\t%lf\t%lf\t%lf\t%lf\t%d\t%d\n",&type,&id,&coord,&pad,&x,&y,&z,&r,&ir,&ic);
		if (id !=0 ){
			P.Fiber[id-1].Coord=coord;
			P.Fiber[id-1].Pad=pad;
			P.Fiber[id-1].Xf=x;
			P.Fiber[id-1].Yf=y;
			P.Fiber[id-1].Zf=z;
			P.Fiber[id-1].Rf=r;
			P.Fiber[id-1].row=ir;
			P.Fiber[id-1].col=ic;
			Pad[pad-1].Fiber[id-1].status = ON;
			Pad[pad-1].Cell[ir][ic].Name = id;
			Pad[pad-1].Rf=r;
			}
		}
	fscanf (file, "\n");//read new line
	fgets(row,4*STRLEN,file);//skip header PAD LAYOUT
	for (pi=0;pi<MAX_PAD;pi++){
		if (Pad[pi].Pad == ON){// PAD is USED	
			fscanf(file,"%s\t%d\n",row, &tp);
			fscanf(file,"%s\t%s\n",row, Pad[pi].Name);
			fscanf(file,"%s\t%s\n",row, Pad[pi].Label);
			fscanf(file,"%s\t%d\n",row, &Pad[pi].LatticeType);
			fscanf(file,"%s\t%d\n",row, &Pad[pi].LatticeCtrl);
			fscanf(file,"%s\t%lf\n",row, &Pad[pi].LatticeStepX);
			fscanf(file,"%s\t%lf\n",row, &Pad[pi].LatticeStepY);
			fscanf(file,"%s\t%lf\n",row, &Pad[pi].LatticeDiagonal);
			fscanf(file,"%s\t%lf\n",row, &Pad[pi].Nn);
			for (ir=0;ir<MAX_PAD_ROW;ir++)
				for (ic=0;ic<MAX_PAD_COL;ic++){
					fscanf(file,"%d",&Pad[pi].Cell[ir][ic].status);
					if (ic < MAX_PAD_COL-1)
						fscanf(file,"\t");
					else
						fscanf(file,"\n");
				}
			}
		}
	fclose(file);
}


int CVICALLBACK LoadGeom (int panel, int control, int event,void *callbackData, int eventData1, int eventData2)
{
	int fi,si,ni,oi,pi;
	char fo,ff;

	switch (event)
		{
		case EVENT_COMMIT:
			
			ReadGeom();
			
			/* COPY PARM STRUCT FOR FIBERS AND SOURCES TO PAD */
			for (pi=0;pi<MAX_PAD;pi++){
				for (fi=0;fi<MAX_FIBER;fi++){
						Pad[pi].Fiber[fi].x = P.Fiber[fi].Xf;
						Pad[pi].Fiber[fi].y = P.Fiber[fi].Yf;
						Pad[pi].Fiber[fi].z = P.Fiber[fi].Zf;
						Pad[pi].Fiber[fi].row = P.Fiber[fi].row;
						Pad[pi].Fiber[fi].col = P.Fiber[fi].col;
					}
				for (si=0;si<MAX_SOURCE;si++){			
						Pad[pi].Source[si].x = P.Source[si].Xs;
						Pad[pi].Source[si].y = P.Source[si].Ys;
						Pad[pi].Source[si].z = P.Source[si].Zs;
						Pad[pi].Source[si].row = P.Source[si].row;
						Pad[pi].Source[si].col = P.Source[si].col;
					}		
				}
	
			/* COPY NEIGHBORS TO PARM STRUCT FOR SOURCE NEIGHBORS */
			for (si=0;si<MAX_SOURCE;si++){
				for (pi=0;pi<MAX_PAD;pi++){
					if ((Pad[pi].Pad == ON)&&(P.Source[si].Pad == pi+1)){
						for (oi=0;oi<NEAR_NEIGH;oi++){
							if (Pad[pi].Dist[oi] != MAXDIST){
								for (ni=0;ni<MAX_NEIGH;ni++)
									P.Source[si].Neigh[oi][ni] = Pad[pi].Source[si].Neigh[oi][ni];
								}
							}
						}
					}
				}


			/* COPY NEIGHBORS INFO TO PROTOCOL LAYOUT */
			for (si=0;si<MAX_SOURCE;si++) strcpy(P.TProt.Fibers[si], "\0");
			for (pi=0;pi<MAX_PAD;pi++){
				if (Pad[pi].Pad == ON){// PAD is USED 
					for (si=0;si<MAX_SOURCE;si++){
						if (Pad[pi].Source[si].status == ON){ // SOURCE is USED
							P.TProt.Source[si]=si+1;
							fo = 1;
							for (oi=0;oi<NEAR_NEIGH;oi++){
								if(Pad[pi].NearNeigh[oi] == ON){
									if (!fo) strcat(P.TProt.Fibers[si], ",");
									ff = 1;
									for (ni=0;ni<MAX_NEIGH;ni++){
										if ((Pad[pi].Dist[oi] != MAXDIST)&&(Pad[pi].Source[si].Neigh[oi][ni] != 0)){
											if (!ff) strcat(P.TProt.Fibers[si], ",");
											Fmt (strtemp, "%s<%d", Pad[pi].Source[si].Neigh[oi][ni]);
											strcat(P.TProt.Fibers[si], strtemp);
											ff = 0;
											}
										}
									fo = 0;
									}
								}
							}
						}
					}
				}

			ReCreatePad();
			UpdatePanel();
		break;
		}
	return 0;
}


void ReCreatePad (void){
	char px;
	int pi,oi,pj;
	int xpos, ypos;
	int totsource, totfiber, totpad, fiberx,sourcex;
	
	totsource = 0;
	totfiber = 0;
	totpad = 0;
	for(pi=0;pi<MAX_PAD;pi++){
		
		if (Pad[pi].Pad == ON){
			sourcex = 0;
			fiberx = 0;

			SetCtrlVal(hGeom,GEOMETRY_PADACTUAL,pi+1);
			switch (Pad[pi].LatticeType){
				
				case NONE:
					break;
					
				case SQUARE:
					/* RECREATE NEW PAD */
					Pad[pi].hPad = NewPanel (hGeom, Pad[pi].Name, PAD_TOP, PAD_LEFT, PAD_HEIGHT, PAD_WIDTH);
					SetActivePanel (Pad[pi].hPad);
					SetPanelAttribute (Pad[pi].hPad, ATTR_MOVABLE, OFF);
					SetPanelAttribute (Pad[pi].hPad, ATTR_SIZABLE, OFF);
					
					
					step_row = STEP_ROW;
					step_col = step_row;
					for (ir=0;ir<MAX_PAD_ROW;ir++)
						for (ic=0;ic<MAX_PAD_COL;ic++){
							
							/* SET CELL LABEL */
							Pad[pi].Cell[ir][ic].Label[0]='R';
							Pad[pi].Cell[ir][ic].Label[1]='_';
							if (ir<10){
								Pad[pi].Cell[ir][ic].Label[2]='0';
								Pad[pi].Cell[ir][ic].Label[3]=ASCII+ir;
								}
							else{
								Pad[pi].Cell[ir][ic].Label[2]='1';
								px = (char) (ir+1-10);
								Pad[pi].Cell[ir][ic].Label[3]=ASCII+px;
								}
								
							Pad[pi].Cell[ir][ic].Label[4]='_';
							Pad[pi].Cell[ir][ic].Label[5]='C';
							Pad[pi].Cell[ir][ic].Label[6]='_';
							if (ic<10){
								Pad[pi].Cell[ir][ic].Label[7]='0';
								Pad[pi].Cell[ir][ic].Label[8]=ASCII+ic;
								}
							else{
								Pad[pi].Cell[ir][ic].Label[7]='1';
								px = (char) (ic+1-10);
								Pad[pi].Cell[ir][ic].Label[8]=ASCII+px;
								}
							Pad[pi].Cell[ir][ic].Label[9]='\0';
						
							
							/* CREATE CTRL */
							xpos = TOP +ir*step_row;
							ypos = LEFT + ic*step_col;
							cid[pi][ir][ic] = NewCtrl (Pad[pi].hPad, CTRL_NUMERIC, Pad[pi].Cell[ir][ic].Label, xpos,ypos);
							SetCtrlAttribute (Pad[pi].hPad, cid[pi][ir][ic], ATTR_WIDTH, WIDTH);
							SetCtrlAttribute (Pad[pi].hPad, cid[pi][ir][ic], ATTR_DATA_TYPE, VAL_INTEGER);
							SetCtrlAttribute (Pad[pi].hPad, cid[pi][ir][ic], ATTR_SHOW_INCDEC_ARROWS, 0);
							SetCtrlAttribute (Pad[pi].hPad, cid[pi][ir][ic], ATTR_TEXT_COLOR, VAL_PANEL_GRAY);
							SetCtrlAttribute (Pad[pi].hPad, cid[pi][ir][ic], ATTR_TEXT_BGCOLOR,VAL_PANEL_GRAY);
							SetCtrlAttribute (Pad[pi].hPad, cid[pi][ir][ic],ATTR_LABEL_VISIBLE, 0);
							InstallCtrlCallback (Pad[pi].hPad, cid[pi][ir][ic], SetType, 0);

							if (Pad[pi].Cell[ir][ic].status == FIBER){
								SetCtrlAttribute (Pad[pi].hPad, cid[pi][ir][ic], ATTR_TEXT_BGCOLOR, VAL_GREEN);
								SetCtrlVal (Pad[pi].hPad, cid[pi][ir][ic],Pad[pi].Cell[ir][ic].Name);
								SetCtrlAttribute (Pad[pi].hPad, cid[pi][ir][ic],ATTR_TEXT_COLOR, VAL_BLACK);	
								for (pj=0;pj<MAX_PAD;pj++) if(pj!=pi) Pad[pj].Fiber[Pad[pi].Cell[ir][ic].Name-1].status = NOT_AVAILABLE;
								fiberx++;totfiber++;
								}
							if (Pad[pi].Cell[ir][ic].status == SOURCE){
								SetCtrlAttribute (Pad[pi].hPad, cid[pi][ir][ic], ATTR_TEXT_BGCOLOR, VAL_RED);
								SetCtrlVal (Pad[pi].hPad, cid[pi][ir][ic],Pad[pi].Cell[ir][ic].Name);
								SetCtrlAttribute (Pad[pi].hPad, cid[pi][ir][ic],ATTR_TEXT_COLOR, VAL_BLACK);
								for (pj=0;pj<MAX_PAD;pj++) if(pj!=pi) Pad[pj].Source[Pad[pi].Cell[ir][ic].Name-1].status = NOT_AVAILABLE;
								sourcex++;totsource++;
								}
							

							}
					for (ir=0;ir<MAX_PAD_ROW;ir++){
						for (ic=0;ic<MAX_PAD_COL;ic++){
							/* SET CELL COORDINATES */
							Pad[pa].Cell[ir][ic].x = ir*Pad[pi].LatticeStepX;
							Pad[pa].Cell[ir][ic].y = ic*Pad[pi].LatticeStepY;
							Pad[pa].Cell[ir][ic].z = 0;
							}
						}
					DisplayPanel (Pad[pi].hPad);
					SetCtrlVal(hGeom,GEOMETRY_NUMPAD,++totpad);
				break;
					
				case RECTANGULAR:
					/* RECREATE NEW PAD */
					Pad[pi].hPad = NewPanel (hGeom, Pad[pi].Name, PAD_TOP, PAD_LEFT, PAD_HEIGHT, PAD_WIDTH);
					SetActivePanel (Pad[pi].hPad);
					SetPanelAttribute (Pad[pi].hPad, ATTR_MOVABLE, OFF);
					SetPanelAttribute (Pad[pi].hPad, ATTR_SIZABLE, OFF);
					
					
					step_row = RECT_FACT_ROW*STEP_ROW;
					step_col = RECT_FACT_COL*STEP_COL;
					for (ir=0;ir<MAX_PAD_ROW;ir++)
						for (ic=0;ic<MAX_PAD_COL;ic++){
							
							/* SET CELL LABEL */
							Pad[pi].Cell[ir][ic].Label[0]='R';
							Pad[pi].Cell[ir][ic].Label[1]='_';
							if (ir<10){
								Pad[pi].Cell[ir][ic].Label[2]='0';
								Pad[pi].Cell[ir][ic].Label[3]=ASCII+ir;
								}
							else{
								Pad[pi].Cell[ir][ic].Label[2]='1';
								px = (char) (ir+1-10);
								Pad[pi].Cell[ir][ic].Label[3]=ASCII+px;
								}
								
							Pad[pi].Cell[ir][ic].Label[4]='_';
							Pad[pi].Cell[ir][ic].Label[5]='C';
							Pad[pi].Cell[ir][ic].Label[6]='_';
							if (ic<10){
								Pad[pi].Cell[ir][ic].Label[7]='0';
								Pad[pi].Cell[ir][ic].Label[8]=ASCII+ic;
								}
							else{
								Pad[pi].Cell[ir][ic].Label[7]='1';
								px = (char) (ic+1-10);
								Pad[pi].Cell[ir][ic].Label[8]=ASCII+px;
								}
							Pad[pi].Cell[ir][ic].Label[9]='\0';
						
							
							/* CREATE CTRL */
							xpos = TOP +ir*step_row;
							ypos = LEFT + ic*step_col;
							cid[pi][ir][ic] = NewCtrl (Pad[pi].hPad, CTRL_NUMERIC, Pad[pi].Cell[ir][ic].Label, xpos,ypos);
							SetCtrlAttribute (Pad[pi].hPad, cid[pi][ir][ic], ATTR_WIDTH, WIDTH);
							SetCtrlAttribute (Pad[pi].hPad, cid[pi][ir][ic], ATTR_DATA_TYPE, VAL_INTEGER);
							SetCtrlAttribute (Pad[pi].hPad, cid[pi][ir][ic], ATTR_SHOW_INCDEC_ARROWS, 0);
							SetCtrlAttribute (Pad[pi].hPad, cid[pi][ir][ic], ATTR_TEXT_COLOR, VAL_PANEL_GRAY);
							SetCtrlAttribute (Pad[pi].hPad, cid[pi][ir][ic], ATTR_TEXT_BGCOLOR,VAL_PANEL_GRAY);
							SetCtrlAttribute (Pad[pi].hPad, cid[pi][ir][ic],ATTR_LABEL_VISIBLE, 0);
							InstallCtrlCallback (Pad[pi].hPad, cid[pi][ir][ic], SetType, 0);

							if (Pad[pi].Cell[ir][ic].status == FIBER){
								SetCtrlAttribute (Pad[pi].hPad, cid[pi][ir][ic], ATTR_TEXT_BGCOLOR, VAL_GREEN);
								SetCtrlVal (Pad[pi].hPad, cid[pi][ir][ic],Pad[pi].Cell[ir][ic].Name);
								SetCtrlAttribute (Pad[pi].hPad, cid[pi][ir][ic],ATTR_TEXT_COLOR, VAL_BLACK);	
								for (pj=0;pj<MAX_PAD;pj++) if(pj!=pi) Pad[pj].Fiber[Pad[pi].Cell[ir][ic].Name-1].status = NOT_AVAILABLE;
								fiberx++;totfiber++;
								}
							if (Pad[pi].Cell[ir][ic].status == SOURCE){
								SetCtrlAttribute (Pad[pi].hPad, cid[pi][ir][ic], ATTR_TEXT_BGCOLOR, VAL_RED);
								SetCtrlVal (Pad[pi].hPad, cid[pi][ir][ic],Pad[pi].Cell[ir][ic].Name);
								SetCtrlAttribute (Pad[pi].hPad, cid[pi][ir][ic],ATTR_TEXT_COLOR, VAL_BLACK);
								for (pj=0;pj<MAX_PAD;pj++) if(pj!=pi) Pad[pj].Source[Pad[pi].Cell[ir][ic].Name-1].status = NOT_AVAILABLE;
								sourcex++;totsource++;
								}
							

							}
					for (ir=0;ir<MAX_PAD_ROW;ir++){
						for (ic=0;ic<MAX_PAD_COL;ic++){
							/* SET CELL COORDINATES */
							Pad[pa].Cell[ir][ic].x = ir*Pad[pi].LatticeStepX;
							Pad[pa].Cell[ir][ic].y = ic*Pad[pi].LatticeStepY;
							Pad[pa].Cell[ir][ic].z = 0;
							}
						}
					DisplayPanel (Pad[pi].hPad);
					SetCtrlVal(hGeom,GEOMETRY_NUMPAD,++totpad);
				break;
					
				case HESAGONAL:
					/* RECREATE NEW PAD */
					Pad[pi].hPad = NewPanel (hGeom, Pad[pi].Name, PAD_TOP, PAD_LEFT, PAD_HEIGHT, PAD_WIDTH);
					SetActivePanel (Pad[pi].hPad);
					SetPanelAttribute (Pad[pi].hPad, ATTR_MOVABLE, OFF);
					SetPanelAttribute (Pad[pi].hPad, ATTR_SIZABLE, OFF);
					
					
					step_row = STEP_ROW*(0.5)*pow(3,0.5);//0.87 = (0.5)*[(3)^(0.5)]
					step_col = STEP_ROW;
					for (ir=0;ir<MAX_PAD_ROW;ir++)
						for (ic=0;ic<MAX_PAD_COL;ic++){
							
							/* SET CELL LABEL */
							Pad[pi].Cell[ir][ic].Label[0]='R';
							Pad[pi].Cell[ir][ic].Label[1]='_';
							if (ir<10){
								Pad[pi].Cell[ir][ic].Label[2]='0';
								Pad[pi].Cell[ir][ic].Label[3]=ASCII+ir;
								}
							else{
								Pad[pi].Cell[ir][ic].Label[2]='1';
								px = (char) (ir+1-10);
								Pad[pi].Cell[ir][ic].Label[3]=ASCII+px;
								}
								
							Pad[pi].Cell[ir][ic].Label[4]='_';
							Pad[pi].Cell[ir][ic].Label[5]='C';
							Pad[pi].Cell[ir][ic].Label[6]='_';
							if (ic<10){
								Pad[pi].Cell[ir][ic].Label[7]='0';
								Pad[pi].Cell[ir][ic].Label[8]=ASCII+ic;
								}
							else{
								Pad[pi].Cell[ir][ic].Label[7]='1';
								px = (char) (ic+1-10);
								Pad[pi].Cell[ir][ic].Label[8]=ASCII+px;
								}
							Pad[pi].Cell[ir][ic].Label[9]='\0';
						
							
							/* CREATE CTRL */
							xpos = TOP +ir*step_row;
							ypos = LEFT + ic*step_col+fmod (ir, 2)*step_col/2;
							cid[pi][ir][ic] = NewCtrl (Pad[pi].hPad, CTRL_NUMERIC, Pad[pi].Cell[ir][ic].Label, xpos,ypos);
							SetCtrlAttribute (Pad[pi].hPad, cid[pi][ir][ic], ATTR_WIDTH, WIDTH);
							SetCtrlAttribute (Pad[pi].hPad, cid[pi][ir][ic], ATTR_DATA_TYPE, VAL_INTEGER);
							SetCtrlAttribute (Pad[pi].hPad, cid[pi][ir][ic], ATTR_SHOW_INCDEC_ARROWS, 0);
							SetCtrlAttribute (Pad[pi].hPad, cid[pi][ir][ic], ATTR_TEXT_COLOR, VAL_PANEL_GRAY);
							SetCtrlAttribute (Pad[pi].hPad, cid[pi][ir][ic], ATTR_TEXT_BGCOLOR,VAL_PANEL_GRAY);
							SetCtrlAttribute (Pad[pi].hPad, cid[pi][ir][ic],ATTR_LABEL_VISIBLE, 0);
							InstallCtrlCallback (Pad[pi].hPad, cid[pi][ir][ic], SetType, 0);

							if (Pad[pi].Cell[ir][ic].status == FIBER){
								SetCtrlAttribute (Pad[pi].hPad, cid[pi][ir][ic], ATTR_TEXT_BGCOLOR, VAL_GREEN);
								SetCtrlVal (Pad[pi].hPad, cid[pi][ir][ic],Pad[pi].Cell[ir][ic].Name);
								SetCtrlAttribute (Pad[pi].hPad, cid[pi][ir][ic],ATTR_TEXT_COLOR, VAL_BLACK);	
								for (pj=0;pj<MAX_PAD;pj++) if(pj!=pi) Pad[pj].Fiber[Pad[pi].Cell[ir][ic].Name-1].status = NOT_AVAILABLE;
								fiberx++;totfiber++;
								}
							if (Pad[pi].Cell[ir][ic].status == SOURCE){
								SetCtrlAttribute (Pad[pi].hPad, cid[pi][ir][ic], ATTR_TEXT_BGCOLOR, VAL_RED);
								SetCtrlVal (Pad[pi].hPad, cid[pi][ir][ic],Pad[pi].Cell[ir][ic].Name);
								SetCtrlAttribute (Pad[pi].hPad, cid[pi][ir][ic],ATTR_TEXT_COLOR, VAL_BLACK);
								for (pj=0;pj<MAX_PAD;pj++) if(pj!=pi) Pad[pj].Source[Pad[pi].Cell[ir][ic].Name-1].status = NOT_AVAILABLE;
								sourcex++;totsource++;
								}
							

							}
					for (ir=0;ir<MAX_PAD_ROW;ir++){
						for (ic=0;ic<MAX_PAD_COL;ic++){
							/* SET CELL COORDINATES */
							Pad[pa].Cell[ir][ic].x = ir*Pad[pi].LatticeStepX;
							Pad[pa].Cell[ir][ic].y = (ic+fmod(ir, 2)/2)*Pad[pi].LatticeStepY;
							Pad[pa].Cell[ir][ic].z = 0;
							}
						}
					DisplayPanel (Pad[pi].hPad);
					SetCtrlVal(hGeom,GEOMETRY_NUMPAD,++totpad);
				break;
				}
			SetCtrlVal (hGeom, GEOMETRY_NUMSOURCE, totsource);
			SetCtrlVal (hGeom, GEOMETRY_NUMFIBER, totfiber);
		 	
			SetTableCellVal (hGeom, GEOMETRY_TABLE_PAD, MakePoint(1,pi+1), 1);
			SetTableCellVal (hGeom, GEOMETRY_TABLE_PAD, MakePoint(2,pi+1), sourcex);
			SetTableCellVal (hGeom, GEOMETRY_TABLE_PAD, MakePoint(3,pi+1), fiberx);
			Pad[pi].numsource = sourcex;
			Pad[pi].numfiber = fiberx;
			for (oi=0;oi<NEAR_NEIGH;oi++) 
				SetCtrlVal(hGeom,GEOMETRY_NEIGH_1+oi,Pad[pi].NearNeigh[oi]);
			SetCtrlVal(hGeom,GEOMETRY_RING_PAD_1+pi,Pad[pi].LatticeType);
			SetCtrlVal(hGeom,GEOMETRY_LATTICE_CTRL,Pad[pi].LatticeCtrl);
			SetCtrlVal(hGeom,GEOMETRY_PAD_STEP_ROW,Pad[pi].LatticeStepX);
			SetCtrlVal(hGeom,GEOMETRY_PAD_STEP_COL,Pad[pi].LatticeStepY);
			SetCtrlVal(hGeom,GEOMETRY_PAD_DIAG,Pad[pi].LatticeDiagonal);
			SetCtrlVal(hGeom,GEOMETRY_FIBER_RADIUS,Pad[pi].Rf);
			SetCtrlVal(hGeom,GEOMETRY_SOURCE_RADIUS,Pad[pi].Rs);
			SetCtrlVal(hGeom,GEOMETRY_PAD_REFINDEX,Pad[pi].Nn);
			SetCtrlVal(hGeom, GEOMETRY_PAD_LABEL_1+pi, Pad[pi].Label);

			}			
		}			
}




/* END GEOMETRY SECTION */


