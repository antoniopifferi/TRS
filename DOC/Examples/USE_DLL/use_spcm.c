/*--------------------------------------------------------
   USE_SPCM.C -- Simple example of using SPC DLL library spcm32.dll
                 (c) Becker &Hickl GmbH, 2000
  --------------------------------------------------------*/

#include <windows.h>
#ifdef _CVI_
#include <utility.h> // only in LabWindows environment (Timer() function)
#endif
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//#include "spc_isa_def.h"
#include "spcm_def.h"


int mod_active[MAX_NO_OF_SPC],total_no_of_spc, no_of_active_spc;
SPCModInfo mod_info[MAX_NO_OF_SPC];

short spc_error,force_use,act_mod;
SPCdata spc_dat;
SPC_EEP_Data eep;
SPCMemConfig  spc_mem_info;
short work_mode,meas_page,block_length,no_of_routing_bits;
int cycles,max_page,max_curve,max_block_no;
short spc_state,armed, init_status,module_type;
short sync_state[MAX_NO_OF_SPC], mod_state[MAX_NO_OF_SPC];
short collection_paused[MAX_NO_OF_SPC];
float ovfl_time,new_time,old_time,disp_time,mem_bank,last_gap[MAX_NO_OF_SPC];

unsigned short offset_value,*buffer;
rate_values rates[MAX_NO_OF_SPC];

short test_fill_state(void);


#pragma argsused

int WINAPI  WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
                     LPSTR lpCmdLine,  int nShowCmd )
{
char fname[80]="d:\\spcm\\lib\\spcm.ini";
char dest_inifile[80] = "spcm_test.ini";

short i,j;
short ret;

      /* initialization must be done always at the beginning*/
if((ret=SPC_init(fname)) <0){
  if(-ret < SPC_WRONG_ID || -ret == SPC_LICENSE_ERR)
    return ret;   // fatal error, maybe wrong ini file   or DLL not registered
  }

total_no_of_spc = no_of_active_spc= 0;
for( i = 0; i < MAX_NO_OF_SPC; i++){
  SPC_get_module_info( i,(SPCModInfo *)&mod_info[i]);
  if(mod_info[i].module_type != M_WRONG_TYPE)
    total_no_of_spc++;
  if(mod_info[i].init == INIT_OK){
    no_of_active_spc++; mod_active[i] = 1;
    act_mod = i;
    }
    else
      mod_active[i] = 0;
  }
if( !total_no_of_spc){
  // no modules found at all
  // if you want to work in simulation mode there are two ways :
  //    1 - change item simulation in .ini file to required sim. mode
  //    2 - use SPC_set_mode function

            /* SPC130 simulation mode for 4 modules */
  for( i =0 ; i < MAX_NO_OF_SPC; i++)
    mod_active[i] = 1;
  force_use = 0;
  spc_error = SPC_set_mode( SPC_SIMUL130, force_use, mod_active);
  work_mode = SPC_get_mode();
  if( work_mode != SPC_SIMUL130)
    return -1;
  //  check modules once more

  total_no_of_spc = no_of_active_spc= 0;
  for( i = 0; i < MAX_NO_OF_SPC; i++){
    SPC_get_module_info( i, (SPCModInfo *)&mod_info[i]);
    if(mod_info[i].module_type != M_WRONG_TYPE)
      total_no_of_spc++;
    if(mod_info[i].init == INIT_OK){
      no_of_active_spc++; mod_active[i] = 1;
      act_mod = i;
      }
      else
        mod_active[i] = 0;
    }
  }


if( total_no_of_spc != no_of_active_spc){
  // it is possible when some SPC modules:
  //   1 - are already used by other applications
  //        mod_info[i].init == INIT_MOD_IN_USE, mod_info[i].in_use == -1
  //   2 - didn't pass correctly through the initialisation procedure
  //        (e.g. wrong EEPROM checksum, hardware test failed )
  // it is still possible ( but not recommended) to use such module,
  //   if you call SPC_set_mode  with force_use parameter = 1
  //   e.g. SPC_set_mode(SPC_HARD, 1 , mod_active);

  }

// furthermore you can have in your system SPC modules of different types
//  (it applies only for the PCI bus modules - SPC modules on ISA bus  
//       are not affected by spcm32.dll)
//  It is not recommended (can lead to strange results) to start the same 
//    measurement on SPC modules of different types ( measurement modes can
//     have different meaning or can operate in a different way )

// assumption is done here that we work with SPC-130 modules
module_type = M_SPC130;
work_mode = SPC_get_mode(); 
for( i = 0; i < MAX_NO_OF_SPC; i++){
  if(mod_active[i]){
    if(mod_info[i].module_type != module_type){
      mod_active[i] = 0;
      no_of_active_spc--;
      }
    } 
  }

 // this will deactivate unused modules in DLL
SPC_set_mode( work_mode, 0 , mod_active);  

if( !no_of_active_spc)
  return -1;

for( i = 0; i < MAX_NO_OF_SPC; i++){
  if(mod_active[i]){
    act_mod = i;
    break;
    }
  } 

ret = SPC_get_parameters(act_mod, &spc_dat);
// directly after initialisation parameters in all modules are equal
//  but later if needed you can equalize the settings as shown below
for( i = act_mod + 1; i < MAX_NO_OF_SPC; i++){
  if(mod_active[i]){
    SPC_set_parameters( i, &spc_dat);
    }
  } 
/////////////////

init_status = SPC_get_init_status(act_mod);


/* during SPC initialization all hardware parameters are set to values
   taken from ini file ( or to default values )
   This parameter set can be overwritten by using
     SPC_set_parameters or SPC_set_parameter function.
   After setting the parameter  check return value and
   read the parameter again to get the value which was sent to the hardware */

   /* change collection time on all modules */
ret = SPC_set_parameter(-1, COLLECT_TIME, 1.0); 
SPC_get_parameter( act_mod, COLLECT_TIME, &spc_dat.collect_time);

ret = SPC_set_parameter( -1, TAC_RANGE, 100.);
SPC_get_parameter( act_mod, TAC_RANGE, &spc_dat.tac_range);

/* it is also possible to save current module parameters to selected ini file
          or/and restore it from ini file
*/
     // save parameters from spc_dat to dest_inifile using base settings and 
     //  comments from the ini file used in SPC_init call 
     //        ( parameter source_inifile = NULL) 
ret = SPC_save_parameters_to_inifile( &spc_dat, dest_inifile, NULL, 1 );

       // read module paraneters from dest_inifile file to spc_dat
       //  and then send the settings to the hardware
ret = SPC_read_parameters_from_inifile( &spc_dat, dest_inifile );
ret = SPC_set_parameters(act_mod, &spc_dat);


/* before the measurement  : */

     /*  1 - SPC memory must be configured */
no_of_routing_bits = 0;  /* simple 1 dimensional measurement */
         // configure memory on all modules
ret = SPC_configure_memory( -1, spc_dat.adc_resolution,no_of_routing_bits,
                            &spc_mem_info);

max_block_no = spc_mem_info.max_block_no;
max_page = spc_mem_info.maxpage;
max_curve = max_block_no/max_page;
block_length = spc_mem_info.block_length;

buffer = (unsigned short *)malloc(block_length * sizeof(unsigned short));

     /*  2 - measured blocks in SPC memory must be filled (cleared ) */
meas_page = 0;
offset_value = 0;
//ret=SPC_fill_memory(-1, 0, meas_page, offset_value);
ret = SPC_fill_memory(-1,-1,meas_page,offset_value);
if(ret > 0){
  // fill started but not yet finished
  ret= test_fill_state();
  }
if(ret < 0)  // errors during memory fill
  return -1;

     /*  3 - measurement  page must be set on all modules*/
SPC_set_page( -1, meas_page);

     /*  4 - rates should  be cleared ,sync state can be checked */
for( i = 0; i < MAX_NO_OF_SPC; i++){
  if(mod_active[i]){
    SPC_clear_rates(i);  /* it is needed one time only */
    SPC_get_sync_state( i, &sync_state[i]);
    }
  }
  
   /*  now measurement can be started on all used modules */
new_time = old_time = 0.0;
disp_time = 1.0;
  /* remember that measurement start can really be synchronous,
           if you use external trigger */
for( i = 0; i < MAX_NO_OF_SPC; i++){
  if(!mod_active[i]) continue;
  if(( ret = SPC_start_measurement(i)) < 0){
    break;
    }
  }  
if(!ret){
  /* now test SPC state to check whether measurement is finished */
  armed = 1;
  while(armed){
    spc_state = 0;
    for( i = 0; i < MAX_NO_OF_SPC; i++){
      if(!mod_active[i]) continue;
      SPC_test_state( i, &mod_state[i]);
      spc_state |= mod_state[i];
      }
    if(spc_state & SPC_ARMED){  /* 1 - still armed */
      /* if required , time from start can be tested ,
                rates and intermediate results can be read */
      SPC_get_time_from_start( act_mod, &new_time);
      if( new_time - old_time > disp_time){
        for( i = 0; i < MAX_NO_OF_SPC; i++){
          if(!mod_active[i]) continue;
          SPC_read_rates( i, &rates[i]);
          collection_paused[i] = SPC_pause_measurement(i);
          /* collection can be paused to read intermediate results  */
          /*  or stopped using SPC_stop_measurement */
          if(collection_paused[i] > 0 ){
             /* read  intermediate results */
            SPC_read_data_block(i, 0 ,meas_page, 1, 0,(short)(block_length-1), buffer);
             /* possibly display intermediate results if required */
            }
          }
             /* now restart measurement */
        for( i = 0; i < MAX_NO_OF_SPC; i++){
          if(!mod_active[i]) continue;
          if(collection_paused[i])
            if(( ret = SPC_restart_measurement(i)) != 0)
              break;
          }
        if(ret < 0)  
          armed = 0;
        }
      }
      else{
        armed = 0;
        if(spc_state & SPC_OVERFL){   /* overflow  */
          for( i= 0; i < MAX_NO_OF_SPC; i++){
            if(!mod_active[i]) continue;
            if(mod_state[i] & SPC_OVERFL){
              SPC_get_break_time( i, &ovfl_time);
              break;
              }
            }
          }
        }
    }

    /* measurement finished - read results */
  for( i = 0; i < MAX_NO_OF_SPC; i++){
    if(!mod_active[i]) continue;
    for( j = 0; j < max_curve; j++){  // here - max_curve = 1
      SPC_read_data_block( i, (short)j, meas_page, 1, 0, 
                            (short)(block_length-1), buffer);
      }
    // or use SPC_read_data_page - in this case 'buffer' must be allocated with
    //     spc_mem_info.blocks_per_frame * spc_mem_info.frames_per_page *
    //        * spc_mem_info.block_length  16-bit words
    //     SPC_read_data_page(i,meas_page,meas_page,buffer);
    }          

  }
  
  
/*  example of single molecule flow measurement     - not for SPC700 (730)
    before measurement at first enable sequencer by calling SPC_enable_sequencer
*/

if( module_type < M_SPC700){
  SPC_set_parameter( -1, COLLECT_TIME, 0.001); /* change collection time */
  SPC_get_parameter( act_mod, COLLECT_TIME, &spc_dat.collect_time);
  cycles = 3;
  mem_bank = spc_dat.mem_bank;
  SPC_enable_sequencer( -1, 1);
  ret = SPC_fill_memory( -1, -1, -1, offset_value); /* clear whole bank */
  if(ret > 0)
  // fill started but not yet finished
    ret= test_fill_state();
  if(ret < 0)  // errors during memory fill
    return -1;
  if(cycles > 1){
    mem_bank = mem_bank?0:1; /* reverse memory bank */
    SPC_set_parameter( -1, MEM_BANK, mem_bank);
    ret = SPC_fill_memory( -1, -1, -1, offset_value); /* clear second bank */
    if(ret > 0) 
      ret = test_fill_state();
    if(ret < 0)  // errors during memory fill
      return -1;
    mem_bank = mem_bank ? 0 : 1; /* reverse memory bank again */
    SPC_set_parameter( -1, MEM_BANK, mem_bank);
    }
  SPC_set_page( -1, 0);
  while(cycles){
    for( i = 0; i < MAX_NO_OF_SPC; i++){
      if(!mod_active[i]) continue;
      if(( ret = SPC_start_measurement(i)) < 0)
        break;
      }  
    if(!ret){
      /* now test SPC state to check whether measurement is finished */
      armed=1;
      while(armed){
        spc_state = 0;
        for( i = 0; i < MAX_NO_OF_SPC; i++){
          if(!mod_active[i]) continue;
          SPC_test_state( i,& mod_state[i]);
          spc_state |= mod_state[i];
          }
        if((spc_state & SPC_ARMED) == 0){  /*  finished */
          for( i = 0; i < MAX_NO_OF_SPC; i++){
            if(!mod_active[i]) continue;
            SPC_read_gap_time( i, &last_gap[i]);
            }
          armed = 0;
          /* now read the whole actual bank and save results */
          //  e.g. read whole bank :
          //    SPC_read_data_page(mod_no,0,max_page-1,buffer);
          //  - in this case 'buffer' must be allocated with
          //     spc_mem_info.blocks_per_frame * spc_mem_info.frames_per_page *
          //   * spc_mem_info.maxpage  * spc_mem_info.block_length  16-bit words
          //
          }
        }
      if(cycles > 1){    /* clear memory for next cycle results */
          /* warning - in flow mode memory bank  changes on DLL level
                        in SPC_start_measurement procedure */
        ret = SPC_fill_memory( -1,-1,-1, offset_value);
        if(ret > 0) 
          ret = test_fill_state();
        if(ret < 0)  // errors during memory fill
          return -1;
        }
        else{
          /* last cycle for flow mode
             don't arm actual bank , only reverse memory bank */
          /* warning - in flow mode memory bank  changes on DLL level
                        in SPC_start_measurement procedure */
          SPC_get_parameter( act_mod, MEM_BANK, &mem_bank);
          mem_bank = mem_bank ? 0 : 1; /* reverse memory bank */
          SPC_set_parameter( -1, MEM_BANK, mem_bank);
          }
      }
      else
        break;
    cycles--;
    }
  }
  
return 0 ;
}



short test_fill_state(void)
{
short i,ret,state;
//double stime;
time_t starttime,endtime;
// Timer() function available in LabWindows environment
// with other compiler use similar function which delivers time value
for( i = 0; i < MAX_NO_OF_SPC; i++){
  if(mod_active[i]){
    time( &starttime);
//  stime = Timer();
    while(1){
      ret = SPC_test_state( i, &state);
      if(ret < 0) return ret;
      if( (state & SPC_HFILL_NRDY) == 0) 
        break;  // fill finished
      time( &endtime);
      if(difftime( endtime, starttime) > 2.5){
//    if(Timer() - stime > 2.5 ){   // 0.5 for SPC600 ,2.5 for SPC700
        ret = -SPC_FILL_TOUT;  
        return ret;
        }
      }
    }
  }
return 0;  
}


