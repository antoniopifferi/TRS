short _InitMbcPortAddress(unsigned short address);
short _GetCardConfig(unsigned char *swstatus,unsigned short *mbcmodel,
    unsigned char *bootfwrel,unsigned char *maxmem,unsigned char *maxtask);
short _SetMemory_ActiveTask(unsigned short taskmemory,char activetaskmap[4]);
short _SelectCurrentTask(unsigned char currtask);
short _SelectMemoryRangeGroup(unsigned short range,unsigned char group);
short _PresetPhaParameter(char collmode,char extsync);
short _SelectStopMode(char stopmode[3]);
short _PresetTime(unsigned long timevalue);
short _SelectTimeMode(char timemode);
short _SelectTimeUnit(char timeunit);
short _SetRoi(unsigned short roistart,unsigned short roistop);
short _GetRoi(unsigned short * roistart,unsigned short * roistop);
short _PresetPeakIntegral(unsigned long integralvalue);
short _PresetAreaParameter(float areavalue,float conflevel,short chanaverage);
short _StartStopDataIn(char status[4]);
short _GetMeasInfo(unsigned long *realtime,unsigned long *livetime,
                 unsigned char *deadtime,unsigned char *statusmeas);
short _DumpTime(unsigned long realtime,unsigned long livetime);
short _ClearMemory(unsigned short startchan,unsigned short endchan);
short _TransferData(unsigned short startchan,unsigned short stopchan,
                  char direction,unsigned char *spectraptr);
short _TransferMemory(unsigned short startchan,unsigned short stopchan,
                    char direction,unsigned char *spectraptr);
short _FwLoader(unsigned char loadflag,unsigned char resetflag);
short _GetLibRev(unsigned char *rev);
short _SetAdcGainInput(unsigned short convgain,unsigned char adcinput);
short _SetAdcLLD(unsigned char adclld);
short _SetAdcOffset(unsigned char adcoffset);
short _SetAmplParameter(unsigned char polarity,unsigned char shapetime,
                      unsigned char pur,unsigned char blr,unsigned char fastch);
short _SetAmplCoarse(unsigned short coarse);
short _SetAmplProbeFineGain(unsigned short finegain);
short _SetHVOnOff(unsigned char hvstat);
short _GetProbeCorrFactor(char *voltsign,unsigned char *voltvalue);
short _GetInstrParameter(unsigned char *hvstatus,unsigned char *hvpol,
      unsigned char *LN2allarm,unsigned char *ovfstab,unsigned char *halfcoarse);
short _SetLN2Buzzer(unsigned char buzonoff);
short _ResetLN2Allarm(void);
