/**
 @file
*/

#pragma once

#ifndef ssize_t
#ifdef __linux__
  #include <sys/types.h>
#elif _WIN32
  #ifdef _MSC_VER
    #include <BaseTsd.h>
    typedef SSIZE_T ssize_t;
  #elif __MINGW32__
    #include <sys/types.h>
  #endif
#endif
#endif

/**
 * @brief Used in sc_tdc_format::flow_control_flags
 * @details Start and Beginning of statistics is placed in the tdc event stream
 * if this flag is on.
 */
#define SEPARATORS_TO_FLOW 0x01

/**
 * @brief Used in sc_tdc_format::flow_control_flags
 * @details 1024 bytes of raw statistics is placed in the endo of tdc event stream
 * if this flag is on.
 */
#define STATISTICS_TO_FLOW 0x02

/**
 * @brief Used in sc_tdc_format::flow_control_flags
 * @details Millisecond signs are placed in the tdc event stream
 * if this flag is on.
 */
#define MILLISECONDS_TO_FLOW 0x04

/**
 * @brief Used in sc_tdc_set_flim_scanner2ex()
 * @details Both way scanning mode is active
 * if this flag is on.
 */

#define FLIM_BOTH_WAY_SCAN 0x01

/**
 * @brief Used in sc_tdc_set_flim_scanner2ex()
 * @details Image data are swapped
 * if this flag is on.
 */
#define FLIM_XY_SWAP 0x02


/**
 * @struct sc3d_t
 * @brief Signed 3d point.
 */
struct sc3d_t
{
  int x; /**< x coordinate. */
  int y; /**< y coordinate. */
	long long time; /**< time coordinate. */
};

/**
 * @struct sc3du_t
 * @brief Unsigned 3d point
 */
struct sc3du_t
{
	unsigned int x; /**< x coordinate. */
	unsigned int y; /**< y coordinate. */
	unsigned long long time; /**< time coordinate. */
};

/**
 * @struct roi_t
 * @brief Description of region of interest to be used.
 * @note The size of the roi is used for buffer allocation. User must be sure that size of the allocated buffer does not
 * exceed 2GB on 32 bit platform. Behaviour is undefined if this requirement is not satisfied.
 */
struct roi_t
{
	struct sc3d_t offset; /**< Roi offset */
	struct sc3du_t size; /**< Roi size */
};

/**
 * @struct statistics_t
 * @brief Measure statistics.
    First array index corresponds to device number in a component device.
 */
struct statistics_t
{
  /** Tdc data per channel recognized by fpga. */
	unsigned int counts_read[4][16];
  /** Tdc data per channel transferred from fpga to cpu. */
	unsigned int counts_received[4][16];
  /** Dld events recognized in fpga. */
	unsigned int events_found[4];
  /** Dld events recognized in fpga which fits in hardware roi. */
	unsigned int events_in_roi[4];
  /** Dld events transferred from fpga to cpu. */
	unsigned int events_received[4];
	unsigned int counters[4][16];
	unsigned int reserved[52];
};

/**
 * @brief Size of the pixel for images or one histogram element in time histograms.
 */
enum bitsize_t
{
  BS8 = 0, /**< One byte length. */
  BS16 = 1, /**< Two bytes length. */
  BS32 = 2, /**< Four bytes length. */
  BS64= 3 /**< Eight bytes length. */
};

/**
 * @struct sc_tdc_format
 * @brief Contains sizes and offsets of data bitfields.
 * @details Zero value of the field means that field is not present in the event.
 */
struct sc_tdc_format
{
	unsigned char total_bits_length; /**< Length of one event in bits.
                                  Currently can be only 8, 16, 32 and 64*/
	unsigned char channel_offset; /**< Offset of channel field. Mostly used
                                    in tdc mode */
	unsigned char channel_length; /**< Length of channel field. Mostly used
                                    in tdc mode. Channel field contains information
                                    in which channel of TDC event occured. */
	unsigned char time_data_offset; /**< Offset of time data data field. Mostly used
                                    in tdc mode */
	unsigned char time_data_length; /**< Length of time_data field. Mostly used
                                    in tdc mode. time_data field contains
                                    information about time when event occurs [binsize] */
	unsigned char time_tag_offset;
	unsigned char time_tag_length;
	unsigned char start_counter_offset; /**< Offset of start_counter data field */
	unsigned char start_counter_length; /**< Length of start_counter data field.
                                    start_counter data field contains information
                                    about start counter value. See documentation
                                    to the device for more info about start counter
                                    value */
	unsigned char dif1_offset; /**< Offset of x coordinate of the event */
	unsigned char dif1_length; /**< Length of x coordinate of the event. Mostly
                            used in dld mode.*/
	unsigned char dif2_offset; /**< Offset of y coordinate of the event */
	unsigned char dif2_length; /**< Length of y coordinate of the event. Mostly
                            used in dld mode.*/
	unsigned char sum_offset; /**< Offset of time coordinate data field
                            of the event in dld mode */
	unsigned char sum_length; /**< Length of time coordinate data field
                            of the event in dld mode. */
	unsigned char sign_counter_offset;
	unsigned char sign_counter_length;
	unsigned char reserved[14]; /**< Reserved fields. Must not be used. */
	unsigned char flow_control_flags; /**< Flow control flag data field. */
};

/**
 * @brief Pipe type.
 */
enum sc_pipe_type_t
{
	TDC_HISTO = 0, /**< Used to get pipe with tdc histo data. */
	DLD_IMAGE_XY = 1, /**< Used to get 2d image data. */
	DLD_IMAGE_XT = 2, /**< Used to get x-t image data. */
	DLD_IMAGE_YT = 3, /**< Used to get y-t image data. */
	DLD_IMAGE_3D = 4, /**< Used to get 3d (x,y,t cube) image data. */
	DLD_SUM_HISTO = 5, /**< Used to get dld time histogram data. */
	STATISTICS = 6 /**< Used to get statistics for last exposure. */
};

/**
 * @brief Parameters for DLD_IMAG_XY pipe type.
 *
 * The size of the data unit is roi.x * roi.y * depth bytes.
 */
struct sc_pipe_dld_image_xy_params_t
{
	enum bitsize_t depth; /**< Bits per pixel in memory. */
	int channel; /**< Channel is used to build image. (-1 for normal detector).*/
	unsigned long long modulo; /**< Modulo. */
	struct sc3du_t binning; /**< Image binning. */
	struct roi_t roi; /**< Region of interest from which image will be built. */
	unsigned int accumulation_ms; /**< Accumulation time. */
	void *allocator_owner; /**< Parameter for the allocator_cb function. */
  /**
   * Used to allocate memory for data. If NULL - direct memory allocation.
   * allocator_owner field will used as first argument during the call.
   */
	int (*allocator_cb)(void *, void **);
};

/**
 * @brief Parameters for DLD_IMAG_XT pipe type.
 *
 * The size of the data unit is roi.x * roi.t * depth bytes.
 */
struct sc_pipe_dld_image_xt_params_t
{
	enum bitsize_t depth; /**< Bits per pixel in memory. */
	int channel; /**< */
	unsigned long long modulo;
	struct sc3du_t binning;
	struct roi_t roi;
	unsigned int accumulation_ms;
	void *allocator_owner;
  /**
   * Used to allocate memory for data. If NULL - direct memory allocation.
   * allocator_owner field will used as first argument during the call.
   */
	int (*allocator_cb)(void *, void **);
};

/**
 * @brief Parameters for DLD_IMAG_YT pipe type.
 *
 * The size of the data unit is roi.y * roi.t* depth bytes.
 */
struct sc_pipe_dld_image_yt_params_t
{
	enum bitsize_t depth;
	int channel;
	unsigned long long modulo;
	struct sc3du_t binning;
	struct roi_t roi;
	unsigned int accumulation_ms;
	void *allocator_owner;
  /**
   * Used to allocate memory for data. If NULL - direct memory allocation.
   * allocator_owner field will used as first argument during the call.
   */
	int (*allocator_cb)(void *, void **);
};

/**
 * @brief Parameters for DLD_IMAG_3D pipe type.
 *
 * The size of the data unit is roi.x * roi.y * roi.t * depth bytes.
 * Please note, that modulo, binning and roi settings are applied in the same
 * order like set in the structure. e.g. first modulo is applied,
 * then binning and then roi.
 */
struct sc_pipe_dld_image_3d_params_t
{
	enum bitsize_t depth;
	int channel;
	unsigned long long modulo;
	struct sc3du_t binning;
	struct roi_t roi;
	unsigned int accumulation_ms;
	void *allocator_owner;
  /**
   * Used to allocate memory for data. If NULL - direct memory allocation.
   * allocator_owner field will used as first argument during the call.
   */
	int (*allocator_cb)(void *, void **);
};

/**
 * @brief Parameters for DLD_SUM_HISTO pipe type.
 *
 * The size of the data unit is roi.t * depth bytes.
 */
struct sc_pipe_dld_sum_histo_params_t
{
	enum bitsize_t depth; /**< Bits per histogram element in memory. */
	int channel; /**< Channel is used to build histogram (-1 for normal detector). */
	unsigned long long modulo; /**< Histogram modulo. */
	struct sc3du_t binning; /**< Histogram binning. */
	struct roi_t roi; /**< Region of interest from which histogram will be built. */
	unsigned int accumulation_ms; /**< Accumulation time. */
	void *allocator_owner; /**< Parameter for the allocator_cb function. */
  /**
   * Used to allocate memory for data. If NULL - direct memory allocation.
   * allocator_owner field will used as first argument during the call.
   */
	int (*allocator_cb)(void *, void **);
};

/**
 * @brief Parameters for TDC_HISTO pipe type.
 *
 * The size of the data unit is size * depth bytes.
 */
struct sc_pipe_tdc_histo_params_t
{
	enum bitsize_t depth; /**< Bits per histogram element in memory. */
	unsigned int channel; /**< Channel is used to build histogram. */
	unsigned long long modulo; /**< Histogram modulo. */
	unsigned int binning; /**< Histogram time binning. */
	unsigned long long offset; /**< Histogram start offset in time bins (see sc_tdc_get_binsize2()). */
	unsigned int size; /**< Histogram size in time bins (see above). */
	unsigned int accumulation_ms; /**< Accumulation time. */
	void *allocator_owner; /** Parameter for the allocator_cb function. */
  /**
   * Used to allocate memory for data. If NULL - direct memory allocation.
   * allocator_owner field will used as first argument during the call.
   */
	int (*allocator_cb)(void *, void **);
};

/**
 * @brief Parameters for STATISTICS pipe type.
 *
 * The size of the data unit is sizeof(@ref statistics_t) (1k).
 */
struct sc_pipe_statistics_params_t
{
	void *allocator_owner;
  /**
   * Used to allocate memory for data. If NULL - direct memory allocation.
   * allocator_owner field will used as first argument during the call.
   */
	int (*allocator_cb)(void *, void **);
};

/**
 * @var sc_mask64
 * @brief Used to help user to extract data fields from the event.
 * @details Used in case of 64 bit event length.
 */
const unsigned long long sc_mask64[] = {
	0x0000000000000000ULL,
	0x0000000000000001ULL,
	0x0000000000000003ULL,
	0x0000000000000007ULL,
	0x000000000000000FULL,
	0x000000000000001FULL,
	0x000000000000003FULL,
	0x000000000000007FULL,
	0x00000000000000FFULL,
	0x00000000000001FFULL,
	0x00000000000003FFULL,
	0x00000000000007FFULL,
	0x0000000000000FFFULL,
	0x0000000000001FFFULL,
	0x0000000000003FFFULL,
	0x0000000000007FFFULL,
	0x000000000000FFFFULL,
	0x000000000001FFFFULL,
	0x000000000003FFFFULL,
	0x000000000007FFFFULL,
	0x00000000000FFFFFULL,
	0x00000000001FFFFFULL,
	0x00000000003FFFFFULL,
	0x00000000007FFFFFULL,
	0x0000000000FFFFFFULL,
	0x0000000001FFFFFFULL,
	0x0000000003FFFFFFULL,
	0x0000000007FFFFFFULL,
	0x000000000FFFFFFFULL,
	0x000000001FFFFFFFULL,
	0x000000003FFFFFFFULL,
	0x000000007FFFFFFFULL,
	0x00000000FFFFFFFFULL,
	0x00000001FFFFFFFFULL,
	0x00000003FFFFFFFFULL,
	0x00000007FFFFFFFFULL,
	0x0000000FFFFFFFFFULL,
	0x0000001FFFFFFFFFULL,
	0x0000003FFFFFFFFFULL,
	0x0000007FFFFFFFFFULL,
	0x000000FFFFFFFFFFULL,
	0x000001FFFFFFFFFFULL,
	0x000003FFFFFFFFFFULL,
	0x000007FFFFFFFFFFULL,
	0x00000FFFFFFFFFFFULL,
	0x00001FFFFFFFFFFFULL,
	0x00003FFFFFFFFFFFULL,
	0x00007FFFFFFFFFFFULL,
	0x0000FFFFFFFFFFFFULL,
	0x0001FFFFFFFFFFFFULL,
	0x0003FFFFFFFFFFFFULL,
	0x0007FFFFFFFFFFFFULL,
	0x000FFFFFFFFFFFFFULL,
	0x001FFFFFFFFFFFFFULL,
	0x003FFFFFFFFFFFFFULL,
	0x007FFFFFFFFFFFFFULL,
	0x00FFFFFFFFFFFFFFULL,
	0x01FFFFFFFFFFFFFFULL,
	0x03FFFFFFFFFFFFFFULL,
	0x07FFFFFFFFFFFFFFULL,
	0x0FFFFFFFFFFFFFFFULL,
	0x1FFFFFFFFFFFFFFFULL,
	0x3FFFFFFFFFFFFFFFULL,
	0x7FFFFFFFFFFFFFFFULL,
	0xFFFFFFFFFFFFFFFFULL,
};

/**
 * @var sc_mask32
 * @brief Used to help user to extract data fields from the event
 * @details Used in case of 32 bit event length
 */
const unsigned int sc_mask32[] = {
	0x00000000,
	0x00000001,
	0x00000003,
	0x00000007,
	0x0000000F,
	0x0000001F,
	0x0000003F,
	0x0000007F,
	0x000000FF,
	0x000001FF,
	0x000003FF,
	0x000007FF,
	0x00000FFF,
	0x00001FFF,
	0x00003FFF,
	0x00007FFF,
	0x0000FFFF,
	0x0001FFFF,
	0x0003FFFF,
	0x0007FFFF,
	0x000FFFFF,
	0x001FFFFF,
	0x003FFFFF,
	0x007FFFFF,
	0x00FFFFFF,
	0x01FFFFFF,
	0x03FFFFFF,
	0x07FFFFFF,
	0x0FFFFFFF,
	0x1FFFFFFF,
	0x3FFFFFFF,
	0x7FFFFFFF,
	0xFFFFFFFF,
};


/**
 * @brief Used to find out type of event.
 * @see sc_tdc_is_event()
 */
enum sc_event_type_index {
  SC_TDC_SIGN_START = 0, /**< Tdc event is start sign. */
  SC_TDC_SIGN_MILLISEC = 1, /**< Tdc event is millisecond sign. */
  SC_TDC_SIGN_STAT = 2 /**< Tdc event is beginning of statistics sign. */
};

/**
 * @brief Logging level.
 * @see sc_dbg_set_logger()
 * @deprecated Is not used anymore.
 */
enum sc_LoggerFacility {UNUSED}; //TODO: Remove

/**
 * @struct sc_Logger
 * @brief Logger descriptor used for debug.
 * @details The structure
 * @see sc_dbg_set_logger()
 */
struct sc_Logger
{
  void *private_data; /**< Private data of the external logger. */
  /**
   * @brief Logger callback function.
   * @param pd private_data field.
   * @param sender Sender of the debug message to be logger.
   * @param msg Message itself.
   */
  void (*do_log)(void *pd, const char *sender, const char *msg);
};

struct sc_PipeCbf
{
  void (*cb)(void *);
  void *private_data;
};

struct sc_ConfigLine
{
  const char *section;
  const char *key;
  const char *value;
};

/**
 * @brief Device Properties version 1.
 *
 * If mentioned below parameters not available they set to 0.
 */
struct sc_DeviceProperties1
{
  struct sc3du_t detector_size; /**< Physical detector size in pixels */

  double pixel_size_x; /**< Pixel size in x direction in mm */
  double pixel_size_y; /**< Pixel size in y direction in mm */
  double pixel_size_t; /**< Pixel size in time direction in ns */
};

