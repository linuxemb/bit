#include "types.h"

/* ************************** */
/* Preprocessor Macros        */
/* ************************** */
#define BQ_ADDR		0x10

#define SYS_STAT	0x00
#define CELLBAL1	0x01
#define CELLBAL2	0x02
#define CELLBAL3	0x03
#define SYS_CTRL1	0x04
#define SYS_CTRL2	0x05
#define PROTECT1	0x06
#define PROTECT2	0x07
#define PROTECT3	0x08
#define OV_TRIP		0x09
#define UV_TRIP		0x0A
#define CC_CFG		0x0B
#define VC1   		0x0C
#define VC1_HI		0x0C
#define VC1_LO		0x0D
#define VC2   		0x0E
#define VC2_HI		0x0E
#define VC2_LO		0x0F
#define VC3   		0x10
#define VC3_HI		0x10
#define VC3_LO		0x11
#define VC4   		0x12
#define VC4_HI		0x12
#define VC4_LO		0x13
#define VC5   		0x14
#define VC5_HI		0x14
#define VC5_LO		0x15
#define VC6   		0x16
#define VC6_HI		0x16
#define VC6_LO		0x17
#define VC7   		0x18
#define VC7_HI		0x18
#define VC7_LO		0x19
#define VC8   		0x1A
#define VC8_HI		0x1A
#define VC8_LO		0x1B
#define VC9   		0x1C
#define VC9_HI		0x1C
#define VC9_LO		0x1D
#define VC10		  0x1E
#define VC10_HI		0x1E
#define VC10_LO		0x1F
#define BAT_HI		0x2A
#define BAT_LO		0x2B
#define TS1_HI		0x2C
#define TS1_LO		0x2D
#define TS2_HI		0x2E
#define TS2_LO		0x2F
#define CC_HI		  0x32
#define CC_LO		  0x33
#define ADCGAIN1	0x50
#define ADCOFFSET	0x51
#define ADCGAIN2	0x59




/* ************************** */
/* Data Structures            */
/* ************************** */


/**************************************
	BQ Register and bit defines
**************************************/
typedef struct
{
  Uint8 OCD           : 1;
  Uint8 SCD           : 1;
  Uint8 OV            : 1;
  Uint8 UV            : 1;
  Uint8 OVRD_ALERT    : 1;
  Uint8 DEV_XREADY    : 1;
  Uint8 RSVD          : 1;
  Uint8 CC_READY      : 1;
} sysStat;

typedef struct
{
  union
  {
    sysStat bits;
    Uint8   data8;
  };
} sysStatus;


typedef struct
{
  Uint8 SHUT_B      : 1;
  Uint8 SHUT_A      : 1;
  Uint8 RSVD        : 1;
  Uint8 TEMP_SEL    : 1;
  Uint8 ADC_EN      : 1;
  Uint8 UNUSED      : 2;
  Uint8 LOAD_PRES   : 1;
} sysCtrl1;

typedef struct
{
  union
  {
    sysCtrl1 bits;
    Uint8    data8;
  };
} sysControl1;


typedef struct
{
  Uint8 CHG_ON      : 1;
  Uint8 DSG_ON      : 1;
  Uint8 RSVD        : 3;
  Uint8 CC_1_SHOT   : 1;
  Uint8 CC_EN       : 1;
  Uint8 DELAY_DIS   : 1;
} sysCtrl2;

typedef struct
{
  union
  {
    sysCtrl2 bits;
    Uint8    data8;
  };
} sysControl2;



typedef struct
{
  Uint8 SCD_T0   : 1;
  Uint8 SCD_T1   : 1;
  Uint8 SCD_T2   : 1;
  Uint8 SCD_D0   : 1;
  Uint8 SCD_D1   : 1;
  Uint8 RSVD     : 2;
  Uint8 RSNS     : 1;
} protect1;

typedef struct
{
  union
  {
    protect1 bits;
    Uint8    data8;
  };
} protect_1;

typedef struct
{
  Uint8 OCD_T0   : 1;
  Uint8 OCD_T1   : 1;
  Uint8 OCD_T2   : 1;
  Uint8 OCD_T3   : 1;
  Uint8 OCD_D0   : 1;
  Uint8 OCD_D1   : 1;
  Uint8 OCD_D2   : 1;
  Uint8 RSVD     : 1;
} protect2;

typedef struct
{
  union
  {
    protect2 bits;
    Uint8    data8;
  };
} protect_2;

typedef struct
{
  Uint8 RSVD   : 4;
  Uint8 OV_D0  : 1;
  Uint8 OV_D1  : 1;
  Uint8 UV_D0  : 1;
  Uint8 UV_D1  : 1;
} protect3;

typedef struct
{
  union
  {
    protect3 bits;
    Uint8    data8;
  };
} protect_3;


typedef enum
{
  BQ_ERR,
  BQ_OK
} bqResult;


typedef enum
{
  UV,
  OV,
  I,
  ALL
} bqFault;

  

