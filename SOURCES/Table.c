void AddTab(int Type,int Panel,int Control,char *Label,int Tag,void *Addr){
	T.Type[T.Num]=Type;
	T.Panel[T.Num]=Panel;
	T.Ctrl[T.Num]=Control;
	T.Addr[T.Num]=Addr;
	if(Tag==0) sprintf(T.Label[T.Num],"%s",Label);
	else sprintf(T.Label[T.Num],"%s_%d",Label,Tag);
	T.Num++;
	}


void CreateTable(void){
	int il,is,it,ip,id,ic;

	T.Num=0;

	// 8*3
	for(il=0;il<MAX_LOOP;il++){
		AddTab(TINT,LOOP,LOOP_HOME_1+il,"LoopHome",il+1,&P.Loop[il].Home);
		AddTab(TINT,LOOP,LOOP_FIRST_1+il,"LoopFirst",il+1,&P.Loop[il].First);
		AddTab(TINT,LOOP,LOOP_LAST_1+il,"LoopLast",il+1,&P.Loop[il].Last); 
		AddTab(TINT,LOOP,LOOP_DELTA_1+il,"LoopDelta",il+1,&P.Loop[il].Delta); 
		AddTab(TINT,LOOP,LOOP_NUM_1+il,"LoopNum",il+1,&P.Loop[il].Num); 
		AddTab(TSTRING,LOOP,LOOP_FNAME_1+il,"LoopFName",il+1,P.Loop[il].FName); 
		AddTab(TINT,LOOP,LOOP_BREAK_1+il,"LoopBreak",il+1,&P.Loop[il].Break); 
		AddTab(TINT,LOOP,LOOP_INVERT_1+il,"LoopInvert",il+1,&P.Loop[il].Invert);
		}
		
	// 9	
	AddTab(TDOUBLE,PARM,PARM_OSCILL_TIME,"SpcTimeO",0,&P.Spc.TimeO);
	AddTab(TINT,PARM,PARM_OSCILL_SIG_FIRST,"OscillSigFirst",0,&P.Oscill.Sig.First);
	AddTab(TINT,PARM,PARM_OSCILL_SIG_LAST,"OscillSigLast",0,&P.Oscill.Sig.Last);
	AddTab(TDOUBLE,PARM,PARM_OSCILL_SIG_FRACT,"OscillSigFract",0,&P.Oscill.Sig.Fract);
	AddTab(TINT,PARM,PARM_OSCILL_REF_FIRST,"OscillRefFirst",0,&P.Oscill.Ref.First);
	AddTab(TINT,PARM,PARM_OSCILL_REF_LAST,"OscillRefLast",0,&P.Oscill.Ref.Last);
	AddTab(TDOUBLE,PARM,PARM_OSCILL_REF_FRACT,"OscillRefFract",0,&P.Oscill.Ref.Fract);
	AddTab(TINT,PARM,PARM_OSCILL_ZOOM_FIRST,"OscillZoomFirst",0,&P.Oscill.Zoom.First);
	AddTab(TINT,PARM,PARM_OSCILL_ZOOM_LAST,"OscillZoomLast",0,&P.Oscill.Zoom.Last);

	// 5
	AddTab(TSTRING,PARM,PARM_FILE_DIR,"FileDir",0,P.File.Dir);
	AddTab(TSTRING,PARM,PARM_FILE_EXT,"FileExt",0,P.File.Ext); 
	AddTab(TSTRING,PARM,PARM_FILE_PREFIX,"FilePrefix",0,P.File.Prefix); 
	AddTab(TINT,PARM,PARM_FILE_TAG,"FileTag",0,&P.File.Tag); 
	AddTab(TINT,PARM,PARM_FILE_TYPE,"FileType",0,&P.File.Type); 

	// 12
	AddTab(TINT,PARM,PARM_MCA_TYPE,"SpcType",0,&P.Spc.Type);
	AddTab(TINT,PARM,PARM_MCA_SCALE,"SpcScale",0,&P.Spc.Scale);
	AddTab(TDOUBLE,PARM,PARM_MCA_CALIB,"SpcCalib",0,&P.Spc.Calib);
	AddTab(TDOUBLE,PARM,PARM_MCA_FACTOR,"SpcFactor",0,&P.Spc.Factor);
	AddTab(TINT,PARM,PARM_MCA_CONTROL,"SpcControl",0,&P.Spc.Control);
	AddTab(TDOUBLE,PARM,PARM_MCA_TIME,"SpcTimeM",0,&P.Spc.TimeM);
	AddTab(TINT,PARM,PARM_MCA_CHANN_FIRST,"ChannFirst",0,&P.Chann.First);
	AddTab(TINT,PARM,PARM_MCA_CHANN_LAST,"ChannLast",0,&P.Chann.Last);
	AddTab(TINT,PARM,PARM_MCA_CHANN_NUM,"ChannNum",0,&P.Chann.Num);
	AddTab(TINT,PARM,PARM_MCA_CURVE,"Det,Num",0,&P.Num.Det); //TODO: check
	AddTab(TINT,PARM,PARM_MCA_COUNT,"SpcCount",0,&P.Spc.Count);
	AddTab(TDOUBLE,PARM,PARM_MCA_CHRONO,"ChronoDelta",0,&P.Chrono.Delta);

	// 7
	AddTab(TINT,PARM,PARM_MEAS_DISPLAY,"MeasPlot",0,&P.Meas.Plot);
	AddTab(TINT,PARM,PARM_MEAS_STATUS,"MeasStatus",0,&P.Meas.Status);
P.Meas.Roi=P.Meas.Status; //TODO: add
	AddTab(TINT,PARM,PARM_MEAS_MEM,"MeasMem",0,&P.Meas.Ram);
	AddTab(TINT,PARM,PARM_MEAS_CLEAR,"MeasClear",0,&P.Meas.Clear);
	AddTab(TINT,PARM,PARM_MEAS_STOP,"MeasStop",0,&P.Meas.Stop);
	AddTab(TINT,PARM,PARM_MEAS_AUTORUN,"MeasAutorun",0,&P.Meas.Autorun);
	AddTab(TINT,PARM,PARM_MEAS_NORM,"MeasNorm",0,&P.Meas.Norm);

	// 3
	AddTab(TDOUBLE,PARM,PARM_CONST_RHO,"ConstRho",0,&P.Const.Rho);
	AddTab(TDOUBLE,PARM,PARM_CONST_THICK,"ConstThick",0,&P.Const.Thick);
	AddTab(TDOUBLE,PARM,PARM_CONST_N,"ConstN",0,&P.Const.N);

	// 2
	AddTab(TSTRING,PARM,PARM_COMMENT_DATE,"CommentDate",0,P.Comment.Date);
	AddTab(TSTRING,PARM,PARM_COMMENT_TIME,"CommentTime",0,P.Comment.Time);

	// 12*8
	for(is=0;is<MAX_STEP;is++){
		AddTab(TINT,STEP,STEP_TYPE_1+1,"StepType",is+1,&P.Step[is].Type);
		AddTab(TINT,STEP,STEP_AXIS_1+1,"StepAxis",is+1,&P.Step[is].Axis);
		AddTab(TINT,STEP,STEP_LOOP_1+1,"StepLoop",is+1,&P.Step[is].Loop);
		AddTab(TSTRING,STEP,STEP_FNAME_1+1,"StepFName",is+1,P.Step[is].FName);
		AddTab(TINT,STEP,STEP_SIGN_1+1,"StepSign",is+1,&P.Step[is].Sign);
		AddTab(TINT,STEP,STEP_MODE_1+1,"StepMode",is+1,&P.Step[is].Mode);
		AddTab(TDOUBLE,STEP,STEP_MIN_1+1,"StepMinU",is+1,&P.Step[is].MinU);
		AddTab(TDOUBLE,STEP,STEP_MAX_1+1,"StepMaxU",is+1,&P.Step[is].MaxU);
		AddTab(TDOUBLE,STEP,STEP_FREQMIN_1+1,"StepFreqMin",is+1,&P.Step[is].FreqMin);
		AddTab(TDOUBLE,STEP,STEP_FREQMAX_1+1,"StepFreqMax",is+1,&P.Step[is].FreqMax);
		AddTab(TDOUBLE,STEP,STEP_FACTOR_1+1,"StepFactor",is+1,&P.Step[is].Factor);
		AddTab(TINT,STEP,STEP_SORT_1+1,"StepSort",is+1,&P.Step[is].Sort);
		}
  
  	// 9*8
	for(is=0;is<MAX_SWITCH;is++){
		AddTab(TINT,SWITCH,SWITCH_SWITCH_1+is,"SwitchSwitch",is+1,&P.Switch[is].Switch);   
		AddTab(TINT,SWITCH,SWITCH_DEVICE_1+is,"SwitchDevice",is+1,&P.Switch[is].Device);
		AddTab(TINT,SWITCH,SWITCH_TYPE_1+is,"SwitchType",is+1,&P.Switch[is].Type);
		AddTab(TINT,SWITCH,SWITCH_BOARD_1+is,"SwitchBoard",is+1,&P.Switch[is].Board);
		AddTab(TSTRING,SWITCH,SWITCH_PORT_1+is,"SwitchPort",is+1,&P.Switch[is].Port);
		AddTab(TINT,SWITCH,SWITCH_LINE0_1+is,"SwitchLine0",is+1,&P.Switch[is].Line0);
		AddTab(TINT,SWITCH,SWITCH_MODE_1+is,"SwitchMode",is+1,&P.Switch[is].Mode);
		AddTab(TINT,SWITCH,SWITCH_LOOP_1+is,"SwitchLoop",is+1,&P.Switch[is].Loop);
		AddTab(TSTRING,SWITCH,SWITCH_FNAME_1+is,"SwitchFName",is+1,P.Switch[is].FName);
		}

	// 12*8
	for(it=0;it<MAX_TRIM;it++){
		AddTab(TINT,TRIM,TRIM_STEP_1+it,"TrimStep",it+1,&P.Trim[it].Step);
		AddTab(TINT,TRIM,TRIM_TYPE_1+it,"TrimType",it+1,&P.Trim[it].Type);
		AddTab(TINT,TRIM,TRIM_TARGET_1+it,"TrimTarget",it+1,&P.Trim[it].Target);
		AddTab(TDOUBLE,TRIM,TRIM_GOAL_1+it,"TrimGoal",it+1,&P.Trim[it].Goal);
		AddTab(TINT,TRIM,TRIM_SIGN_1+it,"TrimSign",it+1,&P.Trim[it].Sign);
		AddTab(TINT,TRIM,TRIM_REGION_1+it,"TrimRegion",it+1,&P.Trim[it].Region);
		AddTab(TDOUBLE,TRIM,TRIM_FRACT_1+it,"TrimFact",it+1,&P.Trim[it].Fract);
		AddTab(TDOUBLE,TRIM,TRIM_TIME_1+it,"TrimTime",it+1,&P.Trim[it].Time);
		AddTab(TDOUBLE,TRIM,TRIM_DELTA_1+it,"TrimDeltaU",it+1,&P.Trim[it].DeltaU);
		AddTab(TINT,TRIM,TRIM_NUM_1+it,"TrimNum",it+1,&P.Trim[it].Num);
		AddTab(TINT,TRIM,TRIM_DISPLAY_1+it,"TrimDisplay",it+1,&P.Trim[it].Display);
		AddTab(TINT,TRIM,TRIM_STATUS_1+it,"TrimStatus",it+1,&P.Trim[it].Status);
		}

	// 13
	AddTab(TINT,MAMM,MAMM_MAMM,"MammMamm",0,&P.Mamm.Mamm);
	AddTab(TINT,MAMM,MAMM_FINDTOP,"MammFindTop",0,&P.Mamm.FindTop);
	AddTab(TINT,MAMM,MAMM_SHRINK_X,"MammShrinkX",0,&P.Mamm.Shrink[X]);
	AddTab(TINT,MAMM,MAMM_SHRINK_Y,"MammShrinkY",0,&P.Mamm.Shrink[Y]);
	AddTab(TINT,MAMM,MAMM_LOOP_X,"MammLoopX",0,&P.Mamm.Loop[X]);
	AddTab(TINT,MAMM,MAMM_LOOP_Y,"MammLoopY",0,&P.Mamm.Loop[Y]);
	AddTab(TINT,MAMM,MAMM_STEP_X,"MammStepX",0,&P.Mamm.Step[X]);
	AddTab(TINT,MAMM,MAMM_STEP_Y,"MammStepY",0,&P.Mamm.Step[Y]);
	AddTab(TINT,MAMM,MAMM_COUNT_HIGH_VIS,"MammHighVis",0,&P.Mamm.Count.HighU[MAMM_VIS]);
	AddTab(TINT,MAMM,MAMM_COUNT_MID_VIS,"MammMidVis",0,&P.Mamm.Count.MidU[MAMM_VIS]);
	AddTab(TINT,MAMM,MAMM_COUNT_HIGH_NIR,"MammHighNir",0,&P.Mamm.Count.HighU[MAMM_NIR]);
	AddTab(TINT,MAMM,MAMM_COUNT_MID_NIR,"MammMidNir",0,&P.Mamm.Count.MidU[MAMM_NIR]);
	AddTab(TINT,MAMM,MAMM_ITERBORD,"MammIterBoard",0,&P.Mamm.IterBord);
//AddTab(ic++,MAMM,MAMM_TEST,&P.Mamm.Test);
//AddTab(ic++,MAMM,MAMM_TEST_FILE,P.Mamm.TestFile);

	// 2*16
	for(il=0;it<LABEL_MAX;il++){
		AddTab(TSTRING,LABEL,LABEL_NAME_1+il,"LabelName",il+1,P.Label[il].Name);
		AddTab(TSTRING,LABEL,LABEL_CONTENT_1+il,"LabelContent",il+1,P.Label[il].Content);
		}
	
	// 6*3
	for(id=0;id<3;id++){
		AddTab(TINT,DO_STEP,DO_STEP_STEP_1+id,"DoStepStep",id+1,&P.DoStep[id].Step);
		AddTab(TINT,DO_STEP,DO_STEP_HOME_1+id,"DoStepHome",id+1,&P.DoStep[id].Home);
		AddTab(TINT,DO_STEP,DO_STEP_GOAL_1+id,"DoStepGoal",id+1,&P.DoStep[id].Goal);
		AddTab(TINT,DO_STEP,DO_STEP_OSCILL_1+id,"DoStepOscill",id+1,&P.DoStep[id].Oscill);
		AddTab(TINT,DO_STEP,DO_STEP_BREAK_1+id,"DoStepBreak",id+1,&P.DoStep[id].Break);
		AddTab(TINT,DO_STEP,DO_STEP_RETURN_1+id,"DoStepReturn",id+1,&P.DoStep[id].Return);
		}
	
	// 16
	for(ip=0;ip<MAX_PLOT;ip++){
		AddTab(TINT,DISPLAY,DISPLAY_PLOT_1+ip,"PlotPlot",ip+1,&P.Plot.Plot[ip]);
		}
	
	for(ic=0;ic<T.Num;ic++) T.Dimmed[ic]=FALSE;
	}

