#include <sys/time.h>
#include <stdio.h>
#include "NIRS_DLL.h"

uint32_t Handle;
uint32_t Registers_Out[128];
int32_t Registers_Out_Length = 128;
uint32_t IntTime = 500;
uint32_t Freq = 40;
uint32_t AcqNumber = 50;
uint32_t Hist[8192] = {0};
uint32_t Hist_Length = 8192;
uint32_t Stats[3];
uint32_t Stats_Length = 3;
uint32_t Bank = 0;
uint32_t i,j = 0;
long long int current_timestamp_var, previous_timestamp = 0;
double mean_time = 0.0;
char Acq_Run = 'y';

void plot_hist(uint32_t *);
long long current_timestamp(void);

// Entry point
int main(void)
{
  system("clear");
  printf("fNIRS-Box Test Program \n\n");
    
  if (NIRS_OPEN(&Handle, Registers_Out, Registers_Out_Length))
    printf("Device connected\n");
  else
  {
    printf("Connection error\n");
    return 1;
  }
  
  printf("Handle is: %u\n", Handle);
  
  if (NIRS_ON(&Handle, Registers_Out, Registers_Out, Registers_Out_Length, Registers_Out_Length))
    printf("Device is ON\n");
  else
  {
    printf("Turn-ON error\n");
    return 1;
  }
  
  while(Acq_Run == 'y')
  {
  
    printf("Acquisition time (ms)? ");
    scanf("%u", &IntTime);
    
    if (NIRS_SET(&Handle, Registers_Out, Registers_Out, Registers_Out_Length, Registers_Out_Length, Freq, IntTime))
      printf("Set parameters done\n");
    else
      printf("Set parameters error\n");

    printf("Acquisition cycles number? ");
    scanf("%u", &AcqNumber);
  
    for(j=0; j<AcqNumber; j++)
    {
    
      while (!(NIRS_ACQ(&Handle, Hist, Stats, Hist_Length, Stats_Length, &Bank)))
      {}
      
      system("clear");
      current_timestamp_var = current_timestamp();
      printf("\n%u\t%u\t%u\t%u\t%lli\t", j, Stats[0], Stats[1], Stats[2], current_timestamp_var-previous_timestamp);
      
      if (j>=1)
      {
	mean_time = mean_time*(double)(j-1)/((double)(j)) + (double)(current_timestamp_var - previous_timestamp)/(double)(j);
	printf("%f\n\n", mean_time);
      }
      else
	printf("\n\n");
      
      plot_hist(Hist);
      previous_timestamp = current_timestamp_var;
    }
    
    printf("\n\n\n\n");
    
    printf("Continue acquisition? (y/n) ");
    scanf("\n%c", &Acq_Run);
    if (Acq_Run == 'Y')
      Acq_Run = 'y';
  }
    
  if (NIRS_OFF(&Handle, Registers_Out, Registers_Out, Registers_Out_Length, Registers_Out_Length))
    printf("Device is OFF\n");
  else
  {
    printf("Turn-OFF error\n");
    return 1;
  }
  
  if (NIRS_CLOSE(&Handle))
    printf("Device disconnected\n");
  else
  {
    printf("Connection error\n");
    return 1;
  }
  
  return 0;
}

// Simplified graphical plot of the histogram
void plot_hist(uint32_t *Hist)
{
	// bla bla...
}

// Time reference (for benchmark)
long long current_timestamp(void) 
{
   // bla bla...
}
