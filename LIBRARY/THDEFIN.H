#define LIB_VERSION "3.0"

#define BLOCKSIZE	4096	/* Words */
#define CURVES		32
#define BANKSIZE	CURVES*BLOCKSIZE
#define RANGES		6

#define FLAG_OVERFLOW 0x1

#define ZCMIN		0
#define ZCMAX		40
#define DISCRMIN	0
#define DISCRMAX	400
#define SYNCMIN		-1300
#define SYNCMAX		400
#define OFFSETMIN	0
#define OFFSETMAX	2000	
#define ACQTMIN		1   // = 1ms
#define ACQTMAX		36000000 //10*60*60*1000 = 10h 
