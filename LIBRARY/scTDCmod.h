/**
  @file
*/

#pragma once

//APADD
//#include <ansi_c.h>
#include <windows.h>




#if defined _WIN32 || defined __CYGWIN__
	#ifdef SCTDC_EXPORTS
		#define SCTDCDLL_PUBLIC __declspec(dllexport)
		#define WIN32_LEAN_AND_MEAN
	#else
		#define SCTDCDLL_PUBLIC __declspec(dllimport)
	#endif
  #define DEPRECATED
#elif __linux__
	#ifdef SCTDC_EXPORTS
		#define SCTDCDLL_PUBLIC __attribute__ ((visibility("default")))
	#else
		#define SCTDCDLL_PUBLIC
	#endif
  #define DEPRECATED __attribute__ ((deprecated))
  #include <sys/types.h>
#else
  #error platform is not supported
#endif

#include "scTDC_types.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


//iface v1

/**
  @brief    Initializes the hardware and loads the initial settings
  @param    ini_filename   Name of the associated initialization file
  @return   int error code

  This function must be called once prior calling other functions of the library.
  The Hardware must be on and connected to the PC. Resources allocated by that
  call must be freed by calling sc_tdc_deinit() after use.

  Returns 0 upon successfull completion. Otherwise an error code is returned.
  Use sc_get_err_msg() function to get a text description of an error.

  @deprecated Use sc_tdc_init_inifile() instead.
 */
SCTDCDLL_PUBLIC int sc_tdc_init(const char *ini_filename) DEPRECATED;

/**
  @brief    Deinitializes the hardware
  @return   int error code

  This function must be called after using the library. It frees all
  resources allocated by sc_tdc_init().

  Returns 0 upon successfull completion. Otherwise an error code is returned.
  Use sc_get_err_msg() function to get a text description of an error.

  @deprecated Use sc_tdc_deinit2() instead.
 */
SCTDCDLL_PUBLIC int sc_tdc_deinit(void) DEPRECATED;

/**
  @brief    Provides the user with the data format description
  @param	format	Address where the function places the sc_tdc_format structure
  @return   int error code

  The members of sc_tdc_format structure are:
	- total_bits_length: total length of the data word which represents a single event.
		Can be 32 or 64 bits. The amount of memory allocated by sc_tdc_alloc_buffer_v()
		function is equal to size*format.total_bits_length bits.
	- channel_offset: position(LSB) of the channel number in the data word.
	- channel_length: number of bits in the data word used for the channel number.
	- time_data_offset: position(LSB) of the time data in the data word.
	- time_data_length: number of bits in the data word used for the time data.
	- time_tag_offset: position(LSB) of the time tag in the data word.
	- time_tag_length: number of bits in the data word used for the time tag.

  Returns 0 upon successfull completion. Otherwise an error code is returned.
  Use sc_get_err_msg() function to get a text description of an error.

  @deprecated Use sc_tdc_get_format2 instead.
 */
SCTDCDLL_PUBLIC int sc_tdc_get_format(struct sc_tdc_format *format) DEPRECATED;

/**
  @brief    Allocates the memory to store the measurement data
  @param    size	Size of the memory space to allocate
  @param	buffer	Address where the function places the pointer to the allocated buffer
  @return   int error code

  This function allocates the memory for storing the measured data. Argument
  @a size specifies the amount of memory to be allocated measured in number
  of events (1 event = unsigned int). The pointer to the allocated memory
  is placed into @a buffer.

  The function is obsolete and should not be used. Use sc_tdc_alloc_buffer_v() function instead.

  Returns 0 upon successfull completion. Otherwise an error code is returned.
  Use sc_get_err_msg() function to get a text description of an error.

  @deprecated Use sc_tdc_open_pipe2() instead.
 */
SCTDCDLL_PUBLIC int sc_tdc_alloc_buffer(int size, unsigned int **buffer_ptr)
DEPRECATED;

/**
  @brief    Allocates the memory to store the measurement data
  @param    size	Size of the memory space to allocate
  @param	buffer	Address where the function places the pointer to the allocated buffer
  @return   int error code

  This function is deprecated. Please use sc_tdc_alloc_buffer_v instead.

  This function allocates the memory for storing the measured data. Argument
  @a size specifies the amount of memory to be allocated measured in number
  of events. The size of each event is described in the sc_tdc_format structure.
  The pointer to the allocated memory is placed into @a buffer.
  User must call this function before starting first measurement and when
  the buffer size needs to be changed. The buffer pointer is then used to treat
  the measured data. Each event includes several bit fields. Use sc_get_format() function
  to get the number, size and position of the fields which are defined
  in the sc_tdc_format structure.

  Deallocation of previously allocated buffer is done automatically when user
  allocates new buffer or calls sc_tdc_dealloc_buffer() function.

  Returns 0 upon successfull completion. Otherwise an error code is returned.
  Use sc_get_err_msg() function to get a text description of an error.

  @deprecated Use sc_tdc_open_pipe2() instead.
 */
SCTDCDLL_PUBLIC int sc_tdc_alloc_buffer_v(int size, void **buffer_ptr)
DEPRECATED;

/**
  @brief    Deallocates the memory allocated by sc_tdc_alloc_buffer()
  @return   int error code

  This function deallocates the memory allocated by the
  function sc_tdc_alloc_buffer().

  Returns 0 upon successfull completion. Otherwise an error code is returned.
  Use sc_get_err_msg() function to get a text description of an error.

  @deprecated Use sc_tdc_open_pipe2() instead.
 */
SCTDCDLL_PUBLIC int sc_tdc_dealloc_buffer(void)
DEPRECATED;

/**
  @brief    Informs the user about the number of events measured
  @param    count	Address where to put the number of measured events
  @return   int error code

  This function allows the user to know how many events were stored
  into the buffer during the last measurement.

  Returns 0 upon successfull completion. Otherwise an error code is returned.
  Use sc_get_err_msg() function to a get text description of an error.

  @deprecated Use sc_tdc_open_pipe2() instead.
 */
SCTDCDLL_PUBLIC int sc_tdc_get_events_count(int *count)
DEPRECATED;

/**
  @brief    Sets a callback function pointer to be executed when measurement is complete
  @param	owner	First argument of the callback function
  @param	cb		Pointer to the callback function
  @return   int		error code

  This function passes the pointer to the user defined function which
  library calls when user reaction is required. The argument @a owner defines the
  first argument of the callback function which must take two arguments (void *, int).
  This is usefull when the callback function should call a class member.
  In such a case this argument should be a pointer to the class instance.
  The second argument of the callback function (int) is a reason of the call.
  Possible reasons can be:
	- 1 - Measurement is complete because the measurement time is over
	- 2 - Measurement is complete because of the user interrupt
	- 3 - Measurement is complete because the buffer is full
	- -30 - Usb communication error occured (necessary to reinitialize)

  Returns 0 upon successfull completion. Otherwise an error code is returned.
  Use sc_get_err_msg() function to get a text description of an error.

  @deprecated Use sc_pipe_open2() instead.
 */
SCTDCDLL_PUBLIC int sc_tdc_set_complete_callback(void *owner, void (*cb)(void *, int))
DEPRECATED;

/**
  @brief    Starts measurement
  @param	ms Measurement time in milliseconds
  @return   int error code

  This function starts a new measurement. The argument @a ms specifies the
  measurement time in milliseconds. If @a ms is set to 0 the measurement
  can only be completed by calling sc_tdc_interrupt() or when the buffer is full.
  The function returns immediately. The hardware is ready for new measurement
  after the callback function is executed by the library.

  Returns 0 upon successfull completion. Otherwise an error code is returned.
  Use sc_get_err_msg() function to get a text description of an error.

  @deprecated Use sc_tdc_start_measure2() instead.
 */
SCTDCDLL_PUBLIC int sc_tdc_start_measure(int ms)
DEPRECATED;

/**
  @brief    Interrupts running measurement
  @return   int error code

  This function allows the user to interrupt a running measurement before it
  is completed. The function returns immediately. The hardware is ready for a
  new measurement after the callback function is executed by the library.

  Returns 0 upon successfull completion. Otherwise an error code is returned.
  Use sc_get_err_msg() function to get a text description of an error.

  @deprecated Use sc_tdc_interrupt2() instead.
 */
SCTDCDLL_PUBLIC int sc_tdc_interrupt(void)
DEPRECATED;

/**
  @brief    Informs the user about the time measurement binsize in nanoseconds
  @param    binsize_ns	Address where to put the binsize
  @return   int error code

  This function allows the user to know the binsize of time measurement
  expressed in nanoseconds.

  Returns 0 upon successfull completion. Otherwise an error code is returned.
  Use sc_get_err_msg() function to a get text description of an error.

  @deprecated Use sc_tdc_get_binsize2() instead.
 */
SCTDCDLL_PUBLIC int sc_tdc_get_binsize(double *binsize_ns)
DEPRECATED;

/**
  @brief    Informs the user about the current status of the tdc
  @param    status	Address where to put the status
  @return   int error code

  This function allows the user to know the current status code of the tdc.
  This function is usefull when using the callback function is not possible.
  In this case polling the current tdc status can be used to recognize the
  end of the measurement. Zero value status means that measure is running.

  Returns 0 upon successfull completion. Otherwise an error code is returned.
  Use sc_get_err_msg() function to a get text description of an error.

  @deprecated Use sc_tdc_get_status2() instead.
 */
SCTDCDLL_PUBLIC int sc_tdc_get_status(int *status)
DEPRECATED;

/**
  @brief    Gives an error description in a text form
  @param    err_code	Integer error code
  @param   err_msg		Pointer to put a text description.

  @note The err_msg array must be not shorted then ERRSTRLEN constant.

 */
SCTDCDLL_PUBLIC void sc_get_err_msg(int err_code, char *err_msg);

/**
  @brief    Provides the user with statistics data
  @param    stat	Pointer to the user declared statistics_t structure
  @return   int error code

  Provides the user with different kind of statistics data collected during
  the last measurement.

  Returns 0 upon successfull completion. Otherwise an error code is returned.
  Use sc_get_err_msg() function to a get text description of an error.

  @deprecated Use sc_pipe_open2 with STATISTICS parameter instead.
 */
SCTDCDLL_PUBLIC int sc_tdc_get_statistics(struct statistics_t *stat)
DEPRECATED;

/**
  @brief    Writes a sequence of bytes using two wire interface (TWI) in master mode
  @param    address	TWI address of the slave device
  @param    data	Pointer to the byte sequence to be written
  @param    size	Number of byte to be written
  @param    stop	Defines whether the transmission must be followed by the stop condition
  @return   int error code

  Writes a sequence of bytes to an external device connected by TWI in master mode.
  The address of the slave device must be in the range from 0 to 127.
  To hold the line between transmissions set @a stop to 0, else to 1.

  Returns 0 upon successfull completion. Otherwise an error code is returned.
  Use sc_get_err_msg() function to a get text description of an error.

  @deprecated Use sc_twi_write2() instead.
 */
SCTDCDLL_PUBLIC int sc_twi_write(unsigned char address, unsigned char *data, int size, int stop)
DEPRECATED;

/**
  @brief    Reads a sequence of bytes using two wire interface (TWI) in master mode
  @param    address	TWI address of the slave device
  @param    data	Pointer where to place read data
  @param    size	Number of byte to be read
  @param    stop	Defines whether reading must be followed by the stop condition
  @return   int error code

  Reads a sequence of bytes from an external device connected by TWI in master mode.
  The address of the slave device must be in the range from 0 to 127.
  To hold the line between transmissions set @a stop to 0, else to 1.

  Returns 0 upon successfull completion. Otherwise an error code is returned.
  Use sc_get_err_msg() function to a get text description of an error.

  @deprecated Use sc_twi_read2() instead.
 */
SCTDCDLL_PUBLIC int sc_twi_read(unsigned char address, unsigned char *data, int size, int stop)
DEPRECATED;

/**
  @brief    Sets a value of electronic potentiometer
  @param    epot	Index of electronic potentiometer
  @param    value_number	Defines which value to set
  @param    value	Potentiometer value
  @return   int error code

  Sets a value of an electronic potentiometer connected via TWI.
  Parameter  @a epot is an index of the potentiometer in the list starting from 0.
  Parameter  @a value_number is an index of the sub-potentiometer in starting from 0.

  Returns 0 upon successfull completion. Otherwise an error code is returned.
  Use sc_get_err_msg() function to a get text description of an error.

  @deprecated Use sc_twi_set_epot2() instead.
 */
SCTDCDLL_PUBLIC int sc_twi_set_epot(unsigned int epot, unsigned int value_number, unsigned char value)
DEPRECATED;

/**
  @brief    Creates a FIFO buffer for the measurement data
  @param    bytes	Size of the buffer in bytes
  @return   int error code

  Creates a FIFO buffer (pipe) which can be used as a data transfer
  channel between the dll and the user. The dll puts the data into the
  pipe on one end and the user gets the data on the other end.
  When the pipe is open and the measurement is started, the
  sc_tdc_get_next_data() function must be used to get data from the pipe.
  Parameter  @a bytes defines the size of the buffer in bytes and
  must be a multiple of 8. The size must be appropriate for the expected data rate
  and the reading speed. Not sufficient size of the pipe can lead to the data loss.
  Data in the range from 0xFFFFFFF0 to 0xFFFFFFFF (from 0xFFFFFFFFFFFFFFF0ULL
  to 0xFFFFFFFFFFFFFFFFULL for 64 bits data format) are reserved to have special
  meanings:
  0xFFFFFFFA (0xFFFFFFFFFFFFFFFAULL) - milliseconds ticks.
  0xFFFFFFFC (0xFFFFFFFFFFFFFFFCULL) - in multiple measurement mode separates
  the data corresponding to different measurements.
  0xFFFFFFFB (0xFFFFFFFFFFFFFFFBULL) - in multiple measurement mode separates
  the statistics data. 256 (128 for 64 bits format) calls of the reading function
  sc_tdc_get_next_data() after 0xFFFFFFFB contain the statistics_t structure
  which belongs to the current measurement.

  Returns 0 upon successfull completion. Otherwise an error code is returned.
  Use sc_get_err_msg() function to a get text description of an error.

  @deprecated Use sc_tdc_pipe_open2() instead.
 */
SCTDCDLL_PUBLIC int sc_tdc_open_pipe(int bytes)
DEPRECATED;

/**
  @brief    Destroyes the pipe
  @return   int error code

  Destroyes the pipe previously opened by the sc_tdc_open_pipe() function
  and deallocates all the memory that belongs to it.

  Returns 0 upon successfull completion. Otherwise an error code is returned.
  Use sc_get_err_msg() function to a get text description of an error.

  @deprecated Use sc_tdc_pipe_close2() instead.
 */
SCTDCDLL_PUBLIC int sc_tdc_close_pipe(void)
DEPRECATED;

/**
  @brief    Reads the measurement data from the pipe
  @param    data	Address where the function places the read data.
  @return   int available bytes

  Call this function to read the data from the pipe previously open by the
  sc_tdc_open_pipe() function after the measurement has been started and until
  the pipe is empty when the measurement is complete. The function must be called
  offen enough to avoid the pipe overflow.


  Returns the number of occupied bytes in the pipe after the reading.
  Negative value means that the reading has been done from the empty
  pipe and the read data are invalid.

  @deprecated Use sc_tdc_pipe_read2() instead.
 */
SCTDCDLL_PUBLIC int sc_tdc_get_next_data(void *data)
DEPRECATED;

//v1.4.0
/**
  @brief    Reads the measurement data from the pipe
  @param    data	Address where the function places the read data.
  @return   int available bytes

  Call this function to read the data from the pipe previously open by the
  sc_tdc_open_pipe() function after the measurement has been started and until
  the pipe is empty when the measurement is complete. The function must be called
  offen enough to avoid the pipe overflow.


  Returns the number of occupied bytes in the pipe after the reading.
  Negative value means that the reading has been done from the empty
  pipe and the read data are invalid.

  @deprecated Use sc_tdc_pipe_read2() instead.
 */
SCTDCDLL_PUBLIC int sc_tdc_get_next_data_b(void *data)
DEPRECATED;

/**
  @brief    Creates a FIFO buffer for the histogram pointers
  @param    time_offset		Histogram offset in bins
  @param    histo_length	Histogram length in bins
  @param    ch_mask			Channel mask
  @param    accumulation_ms	Accumulation time in ms
  @return   int error code

  Creates a FIFO buffer (pipe) which can be used as a histogram pointers transfer
  channel between the dll and the user. The dll puts the pointers into the
  pipe on one end and the user gets the pointers on the other end.
  When the pipe is open and the measurement is started, the
  sc_tdc_get_next_histo() function must be used to get pointers from the pipe.
  Parameter  @a time_offset defines the time offset of the histogram in bins.
  Parameter  @a histo_length defines the length of the histogram in bins.
  Parameter  @a ch_mask defines the channels for which the histogram is to be built.
  Parameter  @a accumulation_ms defines the acculmulation time of the histogram in ms.
  The amount of memory allocated for each buffer is given as number of ones in the
  channel mask times histogram length in unsigned int. The offset (not time offset)
  of the histogram corresponing to particular channel in the buffer is given by the number
  of less significant ones in the channel mask times histogram length in unsigned int.
  Example: Histogram length is 1000. Channel mask equal to 0x23 sets the dll to build
  histograms for the channels 0, 1 and 5. The buffer size in this case is then
  3*1000 unsigned int. The offsets for these channels are 0, 1000 and 2000 unsigned int.

  Returns 0 upon successfull completion. Otherwise an error code is returned.
  Use sc_get_err_msg() function to a get text description of an error.

  @deprecated Use sc_pipe_open2() with TDC_HISTO parameter type instead.
 */
SCTDCDLL_PUBLIC int sc_tdc_open_histo_pipe_a
(unsigned long long time_offset,
unsigned int histo_length,
unsigned long long ch_mask,
unsigned int accumulation_ms,
void *allocator_owner,
int (*allocator_cb)(void *, unsigned int **))
DEPRECATED;

SCTDCDLL_PUBLIC int sc_tdc_open_histo_pipe
(unsigned long long time_offset,
unsigned int histo_length,
unsigned long long ch_mask,
unsigned int accumulation_ms)
DEPRECATED;

/**
  @brief    Destroyes the histo pipe
  @return   int error code

  Destroyes the histo pipe previously opened by the sc_tdc_open_histo_pipe() function
  and deallocates all the memory that belongs to it.

  Returns 0 upon successfull completion. Otherwise an error code is returned.
  Use sc_get_err_msg() function to a get text description of an error.

  @deprecated Use sc_pipe_close2() instead.
 */
SCTDCDLL_PUBLIC int sc_tdc_close_histo_pipe(void)
DEPRECATED;

/**
  @brief    Reads the pointer to the histogram buffer from the histo pipe
  @param    histo	Address where the function places the pointer.
  @param blocking Nonblocking operation control.
  @return   int Available bytes

  Call this function to read the pointer to the ready histogram from the histo pipe
  previously open by the sc_tdc_open_histo_pipe() function after the measurement
  has been started and until the pipe is empty when the measurement is complete.
  The pointer given by the previous call becomes invalid and is not alowed to use.
  The function must be called offen enough to avoid the pipe overflow.


  Returns the number of occupied entries in the histo pipe after the reading.
  Negative value means that the reading has been done from the empty
  pipe and the read pointer is invalid.

  @deprecated Use sc_pipe_open2() instead.
 */
SCTDCDLL_PUBLIC int sc_tdc_get_next_histo_b
(unsigned int **histo, int blocking)
DEPRECATED;

/**
 * @brief Reads the pointer to the histogram buffer from the histo pipe
 * @param histo Address where the function places the pointer.
 * @return int Available bytes.
 *
 * Variant of sc_tdc_get_next_histo() but with blocking set to zero
 * (nonblocking).
 *
 * @deprecated Use sc_pipe_open2() instead.
 */
SCTDCDLL_PUBLIC int sc_tdc_get_next_histo(unsigned int **histo)
DEPRECATED;

SCTDCDLL_PUBLIC int sc_tdc_set_flim_scanner
(unsigned short pixel_interval,
unsigned short pixel_count,
unsigned short line_count,
unsigned int line_delay_interval,
unsigned int multiline_count,
double *corr_table)
DEPRECATED;

/**
 * @brief Check type of event data.
 * @param type Event type for comparison.
 * @param event Event under testing.
 * @param event_len_bytes Length of event in bytes.
 * @return int Result of comparison.
 *
 * Call this function to test whether event is special sign or not.
 *
 * Returns non zero value if event is of requested type otherwise returns zero.
 */
SCTDCDLL_PUBLIC int
sc_tdc_is_event
(const enum sc_event_type_index type,
const void *event,
const unsigned event_len_bytes);

/**
 * @brief Set external logger mechanism.
 * @details If sc_Logger was already set, it is substituted by the new value.
 * To switch external logger off call the function with NULL argument.
 * @see sc_Logger
 * @return int Error code
 *
 * @note Do not use this function. It is only for internal use.
 */
SCTDCDLL_PUBLIC int sc_dbg_set_logger(struct sc_Logger *) DEPRECATED;

/**
 * @brief Set logger message filtering level.
 * @note Do not use this function. It is only for internal use.
 */
SCTDCDLL_PUBLIC int sc_dbg_set_logger_filter(enum sc_LoggerFacility) DEPRECATED;



// -------------------------- api vmaj2 -----------------------------------------

/**
 * @brief Initializes the hardware and loads the initial settings reading
 *  it from ini file.
 * @param ini_filename Name of the inifile used for initialization.
 * @return int device descriptor or error code if less then zero.
 *
 * The function must be called before any other operation and associates
 * an positive integer number (device descriptor) with the device. Device
 * descriptor must be used to identify hardware for any other operation.
 *
 * Hardware with the same serial number cannot be opened twice. Call
 * sc_tdc_deinit2() to close and deinitialize hardware.
 */
SCTDCDLL_PUBLIC int sc_tdc_init_inifile(const char *ini_filename);

/**
 * @brief Initializes the hardware and loads the initial settings taken
 * from array of sc_ConfigLine structures.
 * @param confline_array Array of sc_ConfigLine structures which contains
 * configuration needed.
 * @return int device descriptor or error code if less then zero.
 *
 * The function must be called before any other operation and associates an
 * positive integer number (device destriptor) with the device. Device
 * descriptor must be used to identify hardware for any other operation.
 *
 * Hardware with the same serial number cannot be opened twice. Call
 * sc_tdc_deinit2() to close and deinitialize hardware.
 *
 * Last structure of the array must contain sc_ConfigLine::section equal NULL.
 */
SCTDCDLL_PUBLIC int
sc_tdc_init_with_config_lines(const struct sc_ConfigLine *confline_array);

/**
 * @brief Deinitialize the hardware
 * @param dev_desc Device descriptor of the hardware to be deinitialized.
 * @return int 0 or error code.
 *
 * Call this function to release device and resources allocated to operate.
 * Hardware is deinitialized after the call.
 */
SCTDCDLL_PUBLIC int sc_tdc_deinit2(const int dev_desc);

/**
 * @brief Get data format of the tdc events.
 * @param dev_desc Device descriptor.
 * @param format Pointer on the structure where format should be placed.
 * @return int 0 or error code.
 *
 * Call this function to get event format got from tdc pipe.
 * See sc_tdc_pipe_open2() for details.
 */
SCTDCDLL_PUBLIC int
sc_tdc_get_format2(const int dev_desc, struct sc_tdc_format *format);

SCTDCDLL_PUBLIC int sc_tdc_get_events_count2(const int, int *count);

SCTDCDLL_PUBLIC int sc_tdc_set_complete_callback2
  (const int, void *owner, void (*cb)(void *, int));

/**
 * @brief Start measure.
 * @param dev_desc Device destriptor.
 * @param ms Exposure time in milliseconds.
 * @return int 0 or error code.
 *
 * Start measurement.
 */
SCTDCDLL_PUBLIC int sc_tdc_start_measure2(const int dev_desc, const int ms);

/**
 * @brief Stop measure.
 * @param dev_desc Device descriptor.
 * @return int 0 or error code.
 *
 * Stops started exposure.
 */
SCTDCDLL_PUBLIC int sc_tdc_interrupt2(const int dev_desc);

/**
 * @brief Get binning.
 * @param dev_desc Device descriptor.
 * @param binsize_ns Pointer where time binning should be stored.
 * @return int 0 or error code.
 */
SCTDCDLL_PUBLIC int sc_tdc_get_binsize2(const int dev_desc, double *binsize_ns);

/**
 * @brief Get running status.
 * @param dev_desc Device descriptor.
 * @param status Pointer where status info must be stored.
 * @return int 0 or error code.
 *
 * The function could be used to get status of hardware.
 * status 0 means idle state, 1 means that exposure is running.
 */
SCTDCDLL_PUBLIC int sc_tdc_get_status2(const int dev_desc, int *status);

/**
 * @brief Get statistics.
 * @param dev_desc Device descriptor.
 * @param stat Pointer where statistics must be stored.
 * @return int 0 or error code.
 */
SCTDCDLL_PUBLIC int
sc_tdc_get_statistics2(const int dev_desc, struct statistics_t *stat);

SCTDCDLL_PUBLIC int sc_twi_write2
(const int,
const unsigned char address,
const unsigned char *data,
const size_t size,
const int stop);

SCTDCDLL_PUBLIC int sc_twi_read2
(const int,
const unsigned char address,
unsigned char *data,
const size_t size,
const int stop);

SCTDCDLL_PUBLIC int sc_twi_set_epot2
(const int, unsigned int epot, unsigned int value_number, unsigned char value);

/**
 * @brief Open data pipe.
 * @param dev_desc Device descriptor
 * @param type Pipe type.
 * @param params Pipe parameters.
 * @return Positive integer number which is pipe id, or error code.
 * @see enum sc_pipe_type_t
 * @see struct sc_pipe_dld_image_xy_params_t
 * @see struct sc_pipe_dld_image_xt_params_t
 * @see struct sc_pipe_dld_image_yt_params_t
 * @see struct sc_pipe_dld_image_3d_params_t
 * @see struct sc_pipe_dld_sum_histo_params_t
 * @see struct sc_pipe_tdc_histo_params_t
 * @see struct sc_pipe_statistics_params_t
 *
 * User can get as many pipes as required. It is not error to get two or more
 * pipes of the same type, but for example with different roi or binning
 * setting.
 * @note In case of internal memory allocation if data is not read from
 * the pipe after every exposure memory consumption of the application
 * will grow up. Please be sure that data is read.
 */
SCTDCDLL_PUBLIC int sc_pipe_open2
(const int dev_desc, const enum sc_pipe_type_t type, const void *params);

/**
 * @brief Close data pipe.
 * @param dev_desc Device descriptor.
 * @param pipe_id Pipe id.
 * @return 0 or error code.
 */
SCTDCDLL_PUBLIC int sc_pipe_close2(const int dev_desc, const int pipe_id);

/**
 * @brief Read data from pipe.
 * @param dev_desc Device descriptor.
 * @param pipe_id Pipe id.
 * @param buffer Pointe to pointer where data block must be stored.
 * @param timeout Timeout in millisecond.
 *
 * This function allocates memory with allocator callback from pipe
 * parameters structure if callback function was installed or allocates
 * memory internally. Then copies data from the last exposure and returns the
 * memory block in buffer. If memory was allocated internally it will be
 * deallocated when next call to the function will be performed or pipe will
 * be closed. If memory allocation callback function was installed in the
 * pipe parameters no any deallocation of the memory will be performed. User
 * must manage memory by him-/her- self.
 *
 * Function returns when: data is available or timeout or pipe is closed.
 */
SCTDCDLL_PUBLIC int sc_pipe_read2
(const int dev_desc, const int pipe_id, void **buffer, unsigned int timeout);

SCTDCDLL_PUBLIC int
sc_tdc_set_flim_scanner2
(const int dd,
unsigned short pixel_interval,
unsigned short pixel_count,
unsigned short line_count,
unsigned int line_delay_interval,
unsigned int multiline_count,
double *corr_table);

SCTDCDLL_PUBLIC int
sc_tdc_set_flim_scanner2ex
(const int dd,
unsigned short pixel_interval,
unsigned short pixel_count,
unsigned short line_count,
unsigned int line_delay_interval,
unsigned int multiline_count,
double *corr_table,
unsigned int flags);

SCTDCDLL_PUBLIC int
sc_tdc_is_event2
(const enum sc_event_type_index type,
const void *event,
const unsigned event_len_bytes);

SCTDCDLL_PUBLIC int sc_dbg_set_logger2(const int, struct sc_Logger *);
SCTDCDLL_PUBLIC int sc_dbg_set_logger_filter2(const int, enum sc_LoggerFacility);
SCTDCDLL_PUBLIC int sc_tdc_set_corrections2(const int, const int *, const unsigned int);
SCTDCDLL_PUBLIC int sc_tdc_set_modulo2(const int, const unsigned int);
SCTDCDLL_PUBLIC int sc_tdc_get_modulo2(const int, unsigned int *);
/**
 * @brief Open data pipe for tdc events.
 * @param dd Device descriptor.
 * @param internal_pipe_size Size of internal data buffer for events in bytes.
 * @param pipe_warning 90% pipe level callback function.
 * @param pipe_alert 99% pipe level callback function.
 * @return int 0 or error code.
 */
SCTDCDLL_PUBLIC int sc_tdc_pipe_open2
(const int dd, size_t internal_pipe_size,
const struct sc_PipeCbf *pipe_warning,
const struct sc_PipeCbf *pipe_alert);

/**
 * @brief Close data pipe for tdc events.
 * @param dd Device descriptor.
 * @return int 0 or error code.
 */
SCTDCDLL_PUBLIC int sc_tdc_pipe_close2(const int dd);

/**
 * @brief Read tdc events from the pipe.
 * @param dd Device descriptor.
 * @param buffer Space for events.
 * @param buffer_size_bytes Size of the buffer in bytes.
 * @param timeout Timeout in milliseconds.
 * @return ssize_t Amount of bytes were copied to the buffer or error code.
 * @see sc_tdc_get_format2(), sc_tdc_is_event2(), sc_tdc_is_event()
 */
SCTDCDLL_PUBLIC ssize_t sc_tdc_pipe_read2
(const int dd, void *buffer, size_t buffer_size_bytes, unsigned timeout);

/**
 * @brief Get configuration data.
 * @param dd Device descriptor.
 * @param key Configuration key in form 'section:key'
 * @param buf Space for configuration value as a string.
 * @param buf_size Size of buf in bytes.
 * @param def Default value.
 */
SCTDCDLL_PUBLIC int sc_tdc_config_get_key
(const int dd, const char *key, char *buf, size_t buf_size, const char *def);

/**
 * @brief Get scTDC version.
 */
SCTDCDLL_PUBLIC void sc_tdc_config_get_library_version(unsigned [3]);

//v1.1405

/**
 * @brief Get Device Properties.
 * @param dd Device descriptor.
 * @param params_num Number of properties structure.
 * @param params Properties structure casted to void pointer.
 *
 * params_num 1 corespond to sc_DeviceProperties1 structure.
 */
SCTDCDLL_PUBLIC int sc_tdc_get_device_properties
(const int dd, int params_num, void *params);



//v1.1406.1
SCTDCDLL_PUBLIC int sc_dld_set_hardware_binning
(const int dd, const struct sc3du_t_const *binning);


#ifdef __cplusplus
}
#endif // __cplusplus

#define ERRSTRLEN				256
