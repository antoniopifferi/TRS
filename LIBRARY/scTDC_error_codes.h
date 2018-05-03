#pragma once

/**
  @file
*/

/**
  General error.
*/
#define SC_TDC_ERR_DEFAULT                                -1
/**
  @deprecated never returned
*/
#define SC_TDC_ERR_INIFILE                                -2
/**
  @deprecated never returned
*/
#define SC_TDC_ERR_TDCOPEN                                -3
/**
  System has not enough memory to perform operation.
*/
#define SC_TDC_ERR_NOMEM                                  -4
/**
  @deprecated never returned
*/
#define SC_TDC_ERR_SERIAL                                 -5
/**
  @deprecated never returned
*/
#define SC_TDC_ERR_TDCOPEN2                               -6
/**
  @deprecated never returned
*/
#define SC_TDC_ERR_PARAMETER                              -7
/**
  @deprecated never returned
*/
#define SC_TDC_ERR_SMALLBUFFER                            -8
/**
  Inifile cannot be found or has incorrect syntax.
*/
#define SC_TDC_ERR_BADCONFI                               -9
/**
  Device is not initialized or bad device descriptor.
*/
#define SC_TDC_ERR_NOTINIT                                -10
/**
  @deprecated never returned
*/
#define SC_TDC_ERR_NOTRDY                                 -11
/**
  Could not load device class library. Insure that it is present, has
  correct architecture string and dependencies.
*/
#define SC_TDC_ERR_DEVCLS_LD                              -12
/**
  Device class library has unsupported version. Update or use appropriate
  version.
*/
#define SC_TDC_ERR_DEVCLS_VER                             -13
/**
  Could not initialize device class library. Insure that firmware file is
  present.
*/
#define SC_TDC_ERR_DEVCLS_INIT                            -14
/**
  Could not initialize fpga. Insure that firmware file is present and correct.
*/
#define SC_TDC_ERR_FPGA_INIT                              -15
/**
  Subsystem is already initialized. To reinitialize deinitialize first.
*/
#define SC_TDC_ERR_ALRDYINIT                              -16
/**
  Timeout during data read.
*/
#define SC_TDC_ERR_TIMEOUT                                -17
/**
  No simulation data file found. Insure that it is present and correct.
*/
#define SC_TDC_ERR_NOSIMFILE                              -18
/**
  Spurious wakeup.
*/
#define SC_TDC_ERR_SPURIOUS_WAKEUP                        -19
/**
  Synchronisation error.
*/
#define SC_TDC_ERR_SYNC                                   -20
/**
  Could not reset GPX. Communication with GPX broken.
*/
#define SC_TDC_ERR_GPX_RST                                -21
/**
  Could not lock PLL.
*/
#define SC_TDC_ERR_GPX_PLL_NLOCK                          -22
/**
  @deprecated never returned
*/
#define SC_TDC_ERR_USB_COMM                               -30
/**
  @deprecated never returned
*/
#define SC_TDC_ERR_CORR_SET                                -40
#define SC_TDC_ERR_BIN_SET                                -41
/**
  @deprecated never returned
*/
#define SC_TDC_ERR_ROI_SET                                -42
/**
  @deprecated never returned
*/
#define SC_TDC_ERR_FMT_SET                                -43
/**
  @deprecated never returned
*/
#define SC_TDC_ERR_FMT_UNSUPPORT                          -44
/**
  @deprecated never returned
*/
#define SC_TDC_ERR_ROI_BAD                                -45
/**
  @deprecated never returned
*/
#define SC_TDC_ERR_ROI_TOOBIG                             -46
#define SC_TDC_ERR_BUFSIZE                                -47
#define SC_TDC_ERR_GPX_FMT_UNSUPPORT                      -48
#define SC_TDC_ERR_GPX_FMT_SET                            -49
#define SC_TDC_ERR_FMT_NDEF                               -50
#define SC_TDC_ERR_FIFO_ADDR_SET                          -60
#define SC_TDC_ERR_MODE_SET                               -61
#define SC_TDC_ERR_START_FAIL                             -62
#define SC_TDC_ERR_TIMER_SET                              -63
#define SC_TDC_ERR_TIMER_EX_SET                           -64
#define SC_TDC_ERR_STRT_FREQ_DIV_SET                      -65
#define SC_TDC_ERR_STRT_FREQ_PERIOD_GET                   -66
#define SC_TDC_ERR_STRT_FREQ_PERIOD_VALUE                 -67
#define SC_TDC_ERR_MODULO_VALUE_SET                       -68
#define SC_TDC_ERR_TWI_NO_MODULE                          -70
#define SC_TDC_ERR_TWI_FAIL                               -71
#define SC_TDC_ERR_TWI_NACK                               -72
#define SC_TDC_ERR_POT_NO                                 -73
#define SC_TDC_ERR_POT_SET                                -74
#define SC_TDC_ERR_FLIM_PARM_SET                          -80
#define SC_TDC_ERR_OPEN_LINE_CORR_FILE                    -81
#define SC_TDC_ERR_WRONG_LINE_CORR_FILE                   -82
#define SC_TDC_ERR_CONNLOST                               -90
#define SC_TDC_ERR_SYSTEM                                 -1000
#define SC_TDC_ERR_NOT_IMPL                               -9000

//used only for callback
#define SC_TDC_INFO_MEAS_COMPLETE                         1
#define SC_TDC_INFO_USER_INTERRUPT                        2
#define SC_TDC_INFO_BUFFER_FULL                           3
