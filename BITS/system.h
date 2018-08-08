
#ifndef __INCLUDE_System_
#define __INCLUDE_System_

/*****************************
 * Included Header Files     *
 *****************************/
#include <stdlib.h>
#include <time.h>
#include "types.h"

#include "filters.h"

#include <stdbool.h>



/*****************************
 * Preprocessor Macros       *
 *****************************/
// Some system configuration options:



//#define COLD_TEMPERATURE_CHAMBER_TESTING   // Setup special conditions for Eric A's cold-temperature testing: 
                                        // 1. Reduces pack-shutdown voltage to 18V
                                        // 2. Prevents heaters from turning on
                                        // 3. Stops cell-balancing
                                        // 4. Activates "Override" flag to stop auto-shutdown on inactivity detection
#define LOGGING_INCLUDED              // Include/exclude logging
//#define FLASH_TEST                  // Purely for lab development/testing!       
// #define BQ_CRC                     // Define this if "CRC-ed" BQ transactions are desired






#define DIM(a)                        sizeof (a) / sizeof (*(a))
#define debounce(us)                  __delay_cycles((Uint32)us * MASTER_CLK);

#define RESET_PROCESSOR()             WDTCTL = 0          // Unconditional reset!


// Application:

// PORTS                              // See schematics

// Port 1:


// Port 2:

// Port 3:
#define FAULT_I_BAL_OUT_          BIT2
#define FAULT_I_BAL_IN_           BIT3


// Port 4:


// Port 5:


// Ports 6/7: (Analogs)


// Port 8:


// Port 9:




/* SALVO-specific: See the user manual */
#define MAIN_THREAD_P       OSTCBP(1)
#define SCOREBOARD_P        OSTCBP(2)
#define ALERT_SIG_P         OSTCBP(3)
#define PCGUI_P             OSTCBP(4)
#define COMMSMESS_P         OSTCBP(5)
#define DEBUG_P             OSTCBP(6)
#define J1939UPDATE_P       OSTCBP(7)
#define SEND_P              OSTCBP(8)
#define UI_P                OSTCBP(9)
#define CELL_BAL_P          OSTCBP(10)
#define TIMER_ADC_POLL_P    OSTCBP(11)
#define CODE_CRC_P          OSTCBP(12)
#define LOG_DUMP_P          OSTCBP(13)
#define HEATERS_P           OSTCBP(14)
#define SOC_SOH_P           OSTCBP(15)
#define STATES_P            OSTCBP(16)
#define TIMER_LOG_P         OSTCBP(17)
#define LOG_SEND_P          OSTCBP(18)
#define BOOSTER_P           OSTCBP(19)
#define PRODUCTION_P        OSTCBP(20)
#define RTC_P               OSTCBP(21)

#define EF_EVENTS1_P        OSECBP(1)
#define EF_EVENTS2_P        OSECBP(2)

#define BINSEM_CHAR         OSECBP(3)
#define BINSEM_MESS         OSECBP(4)
#define BINSEM_SEND_CHARS   OSECBP(5)
#define BINSEM_BQ_STATUS    OSECBP(6)
#define BINSEM_BQ_UPDATE    OSECBP(7)
#define BINSEM_RTC_ALARM    OSECBP(8)
#define MSG_HEATERS_P       OSECBP(9)
#define BINSEM_GUI          OSECBP(10)
#define MSG_PRODUCTION      OSECBP(11)
#define BINSEM_LOG_DONE     OSECBP(12)

#define EF_EVENTS3_P        OSECBP(13)

#define EF_EVENTS1_CB_P     OSEFCBP(1)
#define EF_EVENTS2_CB_P     OSEFCBP(2)

#define MQCB1_P             OSMQCBP(1)
#define MQCB2_P             OSMQCBP(2)
#define MQCB3_P             OSMQCBP(3)
#define MQCB4_P             OSMQCBP(4)


// Cells & Pack definitions:
#if defined(NewChem)
#define OLD_CELL_CHEMISTRY    0     // (Comment this line for new chemistry - see usages below & in bq76930.c)
#define FULL_AH_PACK          (179UL)    //Ah
#else 
#define OLD_CELL_CHEMISTRY    1
#define FULL_AH_PACK          (185UL)  //Ah
#endif


#define BIT_TEST_EN           0     // Remedy for BIT test Cause DFET False report 

#define NUM_CELLS             7                                                   // #
#define CELL_NOMINAL_V        3.65                                                // V
#define CELL_FULL_V           4200U                                               // mV
#define CELL_UV_LEVEL1        2850U                                               // mV
#define CELL_UV_LEVEL2        2450U                                               // mV
#define CELL_OV_LEVEL1        4200U // 4150U                                               // mV
#define CELL_OV_LEVEL2        4210U                                               // mV
#define TERM_VOLTAGE_LOW      20000U                                              // mV 
#define PACK_BOOST_CUT_OFF    29500U                                              // mV
#ifdef COLD_TEMPERATURE_CHAMBER_TESTING
#define PACK_SHUTDOWN         17000U                                              // mV
#else
#define PACK_SHUTDOWN         19000U                                              // mV
#endif
#define HEATERS_OFF           22000U                                              // mV
#define CURRENT_OVER_DSG      -10000                                              // 10mA
#define CURRENT_OVER_CHG      7000                                                // 10mA
#define TEMP_AMBIENT_MAX      90                                                  // degC

//#define TEMP_AMBIENT_MIN      0                                                   // degC           // NEW! For boosterless operation...

#define TEMP_AMBIENT_MIN      -41                                                   // degC 

#define TEMP_FETS_MAX         100                                                 // degC
#define TEMP_CELL_MAX         90                                                  // degC
#define TEMP_BOOST_MAX        100                                                 // degC
#define BOOST_ERR_MIN_CURRENT  100                                                // 10mA
#define BOOST_MAX_CURRENT     2000                                                // 10mA
#define BOOST_MAX_VIN_DELTA    100                                                // mV

#define FETS_VOLT_DROP_MAX     700                                                // mV

#define NOMINAL_VOLTAGE_PACK  (CELL_NOMINAL_V*NUM_CELLS)                          // V
#define FULL_VOLTAGE_PACK     (CELL_FULL_V*NUM_CELLS)                             // mV

#define FULL_COULOMBS_PACK    (FULL_AH_PACK*3600) // C

#define FULL_MCOULOMBS_PACK   (FULL_COULOMBS_PACK*1000.0)                         // mC
#define FULL_ENERGY_PACK      (FULL_COULOMBS_PACK*NOMINAL_VOLTAGE_PACK)           // J
#define COULOMBS_PER_CYCLE    (FULL_COULOMBS_PACK * 4)/5                          // C/cycle (definition)

#define NUM_HEATERS           5                                                   // # Heaters
#define NUM_SENSORS           11                                                  // # thermistors

#define HEATER(N)             (Uint8)(BIT0 << (N-1))
#define ALL_HEATERS()         (HEATER(1) + HEATER(2) + HEATER(3) + HEATER(4) + HEATER(5))

#define BUFSIZE               2500U             // log database size (bytes)
#define LOGLEN                20                // Fixed bytes length per log message
#define MAX_ENTRIES           BUFSIZE/LOGLEN    // Max. # messages



/* ***************************
 * Data Structures           *
 * ***************************/

enum EVENTS1                // For LEDs indicator: = [bit-position below + 1]
{
  // This group includes modes, states, signals, used by local pack logic:
  
  event_wakeActive          = 1UL << 0,   // WAKE signal
  event_canActive           = 1UL << 1,   // CAN bus  
  event_cbActive            = 1UL << 2,   // Cell-Balancing
  event_boostActive         = 1UL << 3,   // Boost charge
  
  event_packBalActive       = 1UL << 4,   // Pack balancing
  event_buttonActive        = 1UL << 5,   // Pushbutton
  event_ledsActive          = 1UL << 6,   // LEDs
  event_logActive           = 1UL << 7,   // Logging
  
  event_inactivity          = 1UL << 8,   // Inactivity period
  event_cmdGoActive         = 1UL << 9,   // Comms. command received  
  event_cmdGoStandby        = 1UL << 10,  // Comms. command received
  event_cmdGoForceActive    = 1UL << 11,  // Comms. command received
  
  event_cmdStorageMode      = 1UL << 12,  // Comms. command received
  event_ledFaultActive      = 1UL << 13,  // NOT a locally registered fault - induced by SMS CAN command for test purposes!
  event_scbAvailable        = 1UL << 14,  // Scoreboard thread cycle completed
  event_adcAvailable        = 1UL << 15,  // ADC cycle completed

  event_cmdBIT_fetDSG       = 1UL << 16,  // Comms. command received  
  event_cmdBIT_fetCHG       = 1UL << 17,  // Comms. command received  

  event_cmdEnterOOS         = 1UL << 18,  // Comms. command received (out-of-service)
  event_cmdExitOOS          = 1UL << 19,  // Comms. command received (out-of-service)
  
  events_shutdown           = (~(event_wakeActive+event_inactivity+event_cmdStorageMode) & 0x0000ffff)       // Shutdown state flags to be cleared
};



enum EVENTS2
{
  // This group includes general alerts, states and permanent errors:
  
  event_bmsCOV1             = 1UL << 0,   // Cell Over Voltage Level 1: Alert only
  event_bmsCOV2             = 1UL << 1,   // Cell Over Voltage Level 2: FET Off
  event_bmsCUV1             = 1UL << 2,   // Cell Under Voltage Level 1: Alert only
  event_bmsCUV2             = 1UL << 3,   // Cell under Voltage Level 2: FET off
  
  event_bmsOCD1             = 1UL << 4,   // Over Current Discharge Level 1: Alert only
  event_bmsOCD2             = 1UL << 5,   // Over Current Discharge Level 2: FET off
  event_bmsSCD              = 1UL << 6,   // Short Current Discharge: FET off 
  event_bmsOCC              = 1UL << 7,   // Over Current Charge: FET off
  
  event_bmsUT               = 1UL << 8,   // (Battery Management System) Under Temperature: Info only
  event_bmsOT               = 1UL << 9,   // Over Temperature: Info only
  event_termVoltagelow      = 1UL << 10,  // Terminal Voltage Low: Alert only, issued 60 seconds prior to pack-voltage shutdown
  event_bmsERR              = 1UL << 11,  // Error: BMS
  
  event_fuseERR             = 1UL << 12,  // Error: Fuse
  event_heaterERR           = 1UL << 13,  // Error: Heater
  event_canERR              = 1UL << 14,  // Error: CAN bus
  event_loggingERR          = 1UL << 15,  // Error: Flash/logging

  event_cellImbalanceERR    = 1UL << 16,  // Error: Cell Imbalance
  event_cellTabOverHeat     = 1UL << 17,  // Error: Cell-tabs heat differential 
  event_powerCompOverHeat   = 1UL << 18,  // Error: Power Components over-heated //FET overT
  event_lifetimeValueWARN   = 1UL << 19,  // Warning: Lifetime data

  event_lifetimeValueERR    = 1UL << 20,  // Error: Lifetime data
  event_chgFetERR           = 1UL << 21,  // Error: Charge FET
  event_dsgFetERR           = 1UL << 22,  // Error: Discharge FET
  event_selfDischargeERR    = 1UL << 23,  // Error: Cell self-discharge

  event_codeCRCERR          = 1UL << 24,  // Error: Code CRC
  event_chargeEfficiencyERR = 1UL << 25,  // Error: Charge efficiency
  event_boosterERR          = 1UL << 26,  // Error: Booster
  event_cellCalibrationERR  = 1UL << 27,  // Error: Cell voltage calibration
  
  event_chargingActive      = 1UL << 28,  // State: Charging
  event_dischargingActive   = 1UL << 29,  // State: Discharging
  event_busConnected        = 1UL << 30,  // State: On the power bus
  event_cmdHeaterActive     = 1UL << 31,  // State: Heater/s on

  // ##########################################################

  // Other mask definitions or bit combos:
  event_alertsFailMask      = 0x0fffffffUL,   // All 28x alert/fail bits
  event_LEDfaultOn          = event_bmsERR +  // Permanent conditions for solid "FAULT" LED:
                              event_fuseERR +        
                              event_canERR +        
                              event_cellImbalanceERR +
                              event_lifetimeValueERR +   
                              event_chgFetERR +          
                              event_dsgFetERR +          
                              event_selfDischargeERR +   
                              event_codeCRCERR +         
                              event_chargeEfficiencyERR +
                              event_cellCalibrationERR +
                              event_loggingERR,
  event_LEDfaultFlash       = event_bmsCOV2 +   // (Transient) conditions for flashing "FAULT" LED
                              event_bmsCUV2 +
                              event_bmsOCD2 +
                              event_bmsSCD + 
                              event_bmsOCC + 
                              event_termVoltagelow +
                              event_powerCompOverHeat +
                              event_cellTabOverHeat +  
                              event_boosterERR +         
                              event_heaterERR,     
};                          



enum EVENTS3                // For cell OT
 
{
  event_cell1OT         = 1UL << 0,   // cell 1
  event_cell2OT         = 1UL << 1,   // cell 2  
  event_cell3OT         = 1UL << 2,   // Cell 3
  event_cell4OT         = 1UL << 3,   // cell 4
  event_cell5OT         = 1UL << 4,   // cell 5
  event_cell6OT         = 1UL << 5,   // Cell 6 
  event_cell7OT         = 1UL << 6,   // Cell 7
} ;






typedef struct
{
  Uint32 covLevel1          : 1;
  Uint32 covLevel2          : 1;
  Uint32 cuvLevel1          : 1;
  Uint32 cuvLevel2          : 1;
  Uint32 ocdLevel1          : 1;
  Uint32 ocdLevel2          : 1;
  Uint32 scd                : 1;
  Uint32 occ                : 1;
  
  Uint32 underTemp          : 1;
  Uint32 overTemp           : 1;
  Uint32 terminalVoltageLow : 1;
  Uint32 bms                : 1;
  Uint32 fuse               : 1;
  Uint32 heater             : 1;
  Uint32 canbus             : 1;
  Uint32 packBalance        : 1;
  
  Uint32 cellImbalance      : 1;
  Uint32 cellTabOverTemp    : 1;
  Uint32 powerCompOverTemp  : 1;
  Uint32 lifetimeWarn       : 1;
  Uint32 lifetimeErr        : 1;
  Uint32 CHGfet             : 1;
  Uint32 DSGfet             : 1;
  Uint32 selfDischarge      : 1;
  
  Uint32 codeCRC            : 1;
  Uint32 chargeEfficiency   : 1;
  Uint32 booster            : 1;
  Uint32 cellCalibrate      : 1;
  
  Uint32 future             : 4;
} alertFail_bits_t;

typedef struct
{
  union
  {
    alertFail_bits_t bits;
    Uint32 all; 
  };
} alertFail_t;


typedef void (*function)(void);

//typedef struct
//{
//  OStypeTFP tFP;
//  OStypeTcbP tcbP;
//  OStypePrio prio;
//  Uint8 watchdogMask;
//} threadDefn;

typedef enum
{
  LEDS_OFF,
  LEDS_ON,
  LEDS_SOC,
  LEDS_STATUS
} disp;

typedef enum
{
  _3_3V,
  _5_0V,
  _HI_PS

} PS_TYPE;

typedef enum
{
  OFF,
  ON,
  BOOST_ON,
  BOOST_OFF,
  LPM,
  QUERY
} POWER;

typedef enum
{
  RESET_INACTIVE,
  RESET_ACTIVE
} SYS_RESET;


typedef enum
{
  WD_ENABLE,
  WD_DISABLE,
  WD_TIMER_ENABLE
} WDOG;


typedef enum
{
  SLEEP_SYS,
  WAKE_SYS
} sysCtl;

enum
{
  DISABLE,
  ENABLE
};


typedef enum
{
  NONE,
  CHG,
  DSG
} fet;


typedef struct          // Describes "Temperature" dependency tables:
{
  Int8 temp;            // degC
  Int16 var;            // some temperature-dependent entity
} Ttable;


enum WATCHDOG_THREADS
{
  WATCHDOG_THREAD1 = 0x01,      // OS
  WATCHDOG_THREAD2 = 0x02,      
  WATCHDOG_THREAD3 = 0x04,      
  WATCHDOG_THREAD4 = 0x08,      
  WATCHDOG_THREAD5 = 0x10,      
  WATCHDOG_THREAD6 = 0x20,      
  WATCHDOG_THREAD7 = 0x40,
  WATCHDOG_THREAD8 = 0x80,

  WATCHDOG_CHECK = (WATCHDOG_THREAD1 + WATCHDOG_THREAD2 + WATCHDOG_THREAD3 + WATCHDOG_THREAD4 + WATCHDOG_THREAD5 + WATCHDOG_THREAD6)
};


typedef enum
{
  DOWNLOAD_LED_FLASH,
  DOWNLOAD_LED_DONE,
  DOWNLOAD_LED_REBOOT
} downloadLEDs;


enum externalTempSensors
{
  T_CELL1,
  T_CELL2,
  T_CELL3,
  T_CELL4,
  T_CELL5,
  T_CELL6,
  T_CELL7,
  T_AMBIENT,
  T_FETS,
  T_SENSE_RES,
  T_BOOSTER
};



typedef enum {
	PS_STORAGE,
	PS_SMART_STANDBY,
	PS_SMART_ACTIVE,
	PS_STANDALONE,
	PS_OUT_OF_SERVICE
} pack_state;


typedef struct 
{
	Uint16	lotNumber;
	Uint32	serialNumber;
	Uint16	softwareVersion;
} Identification_t;


struct lifetimeData
{
	Int16 maxTemp[NUM_SENSORS];   // degC
	Int16 minTemp[NUM_SENSORS];   // degC
	Uint16 maxCellVoltage[NUM_CELLS];        // 100mV
	Uint16 minCellVoltage[NUM_CELLS];        // 100mV
	Int16 aveTemp;                // degC
	Uint16 OverTempCount;         // #
	Uint16 OverTempDuration;      // s
	Uint16 maxPackVoltage;        // 100mV
	Uint16 minPackVoltage;        // 100mV
	Uint16 OverVoltageCount;      // #
	Uint16 OverVoltageDuration;   // s
	Int16 maxChargeCurrent;       // 10mA
	Int16 maxDischargeCurrent;    // 10mA
	Int16 maxChargePower;         // W
	Int16 maxDischargePower;      // W
	Uint32 timeOperational;       // s
	Uint32 timeStandby;           // s
	Uint32 timeStorage;           // s
};



typedef struct
{
  struct lifetimeData lifetime; // Above
  struct MOVING_AVERAGE_FILTER sohFilter;
  Int16 sohFilterSamples[SOH_FILTER_SIZE];
  struct MOVING_AVERAGE_FILTER qefFilter;
  Int16 qefFilterSamples[QEFF_FILTER_SIZE];
  Uint64 mCCin;                 // mC (lifetime accumulation)
  Uint64 mCCout;                // mC (lifetime accumulation)
  Uint32 mCCfull;               // mC (the current tank size)
  Int32 mCC;                    // mC (the current tank fullness)
  Int16 SOH;                    // %
  Int16 Qeff;                   // %
  Int8 socVMax, socVMin;        // SOH variable
  Int32 socCCMax, socCCMin;     // SOH variable
  Int32 CCin, CCout;            // Q efficiency variables
  Int32 tempSum;                // Summation of ambient temperatures (lifetime calculation)
  Int32 tempSamples;            // Accumulated # temperature samples (lifetime calculation)
  Uint32 relaxTimer;            // SOH variable
  Bool updateCCflag;            // SOH variable
  Uint16 cycles;                // #
  pack_state state;             // Above
  Int32 currentmA;              // mA
  Int16 current;                // 10mA
  Int16 ASOC;                   // %
  Int16 ASOCref;                // % (Q efficiency variable)
  Uint16 ASOCpM;                // per milleage
  Int16 RSOC;                   // %
  Uint16 stackVoltage;          // mV
  Uint16 cellVoltage[NUM_CELLS]; // mV
  Uint16 maxCellVoltage;        // mV
  Uint16 minCellVoltage;        // mV
  Int16 dieTemp;                // deg C
  Int8 minCellTemp;             // deg C
  Int8 maxCellTemp;             // deg C
  Uint32 status;                // Various bits as defined in Spec sheet: For debug/display purposes only!
  Uint16 cellBal;               // Bits 0 -> 6 = cells 1 -> 7
  Uint8 cellBalanceControl;     // 1 = ON, 0 = OFF
  Uint16 prot1;                 // See BQ registers
  Uint16 prot2;                 // See BQ registers
  Uint16 prot3;                 // See BQ registers

  Uint16 ovTrip;                // BQ Reg (debug only)            
  Uint16 uvTrip;                // BQ Reg (debug only)

  Uint16 sysCtrl1;              // See BQ registers
  Uint16 sysCtrl2;              // See BQ registers
} bms_;


typedef struct
{
  bms_ bms;                         // Above
  Uint16 heaters;                   // bitfield ON/OFF (see schematic mapping)
  Int16 tempSensor[NUM_SENSORS];    // degC
  Uint16 adcStackV;                 // mV
  Uint16 adcTerminalFuseV;          // mV
  Uint16 adcPackV;                  // mV
  Uint16 adcHeaterFuseV1;           // mV
  Uint16 adcBOOSTImon;              // mA
  Uint16 adcDSGmon;                 // mV
  Uint16 adc3_3pigmon;              // mV
  Uint16 adc5_0mon;                 // mV
  Uint16 adc3_3linmon;              // mV
  Uint16 adcHeaterFuseV2;           // mV
  time_t systemDateTimeSeconds;     // This means Midnight, Jan 1, 1970 (Unix Epoch)
  Uint32 initControl;               // If this fixed pattern changes (Eg loss of power during maintenance etc), it forces a "swatPack" structure reinitialization.
} swatPack;

// for override simulation
typedef enum {

  SIM_CURRENT,          // 10mA
    SIM_CELL_VOLTAGES,    // mV
    SIM_CELL_VOLTAGE,     // mV
    SIM_CELL_TEMPS,       // C
    SIM_CELL_TEMP,        // C
    SIM_FET_TEMP,         // C
    SIM_AMB_TEMP,         // C
    SIM_SOC,              // %
    SIM_SOH,              // %
    SIM_HEATER_REQ,       // --
	SIM_ERASEFLASH = 222,	// Erase Flash Restart.
	SIM_REPROVISION = 223,	// Reprovisioning Restart.
    SIM_RESET = 224       // Restart!

} SIM_CMD;


typedef struct
{
  Uint8 type;
  Uint32 startRecord;
  Uint16 numberRecords;
} logReq;

#define SIMCMD_CURRENT			0x0001
#define SIMCMD_CELL_VOLTAGES	0x0002
#define SIMCMD_CELL_VOLTAGE		0x0004
#define SIMCMD_CELL_TEMPS		0x0008
#define SIMCMD_CELL_TEMP		0x0010
#define SIMCMD_FET_TEMP			0x0020
#define SIMCMD_AMB_TEMP			0x0040
#define SIMCMD_SOC				0x0080
#define SIMCMD_SOH				0x0100
#define SIMCMD_HEATER			0x0200

// for override  simultion
typedef struct
{ 

  bms_ bms;
  Uint8 command;
  Uint16  overrideCmd;
  Bool overrideSim;
  Uint16  ambnt;
  Uint16  AdcStackV;
  Int16  tempSensor[NUM_SENSORS];  
  Uint16  adcStackV;                 // mV
  Uint16  adcTerminalFuseV;          // mV
  Uint16  adcPackV;                  // mV
  Uint16  adcHeaterFuseV1;           // mV
  Uint16  adcBOOSTImon;              // mA
  Uint16  adcDSGmon;                 // mV
  Uint16  adc3_3pigmon;              // mV
  Uint16  adc5_0mon;                 // mV
  Uint16  adc3_3linmon;              // mV
  Uint16 adcHeaterFuseV2;           // mV
  
  
} tempPack;

  

/*****************************
 * Externs                   *
 *****************************/
extern Uint8 logData[];
extern const Int8 shapVer[];
extern SYS_RESET reset;
extern const Int8 svnId[];
extern Uint8 override;
extern Bool newBoosterHW;
extern Uint8 CANmodeDebugCounter;
extern Uint8 CANeiDebugCounter;
extern Uint8 CANdupAddrCounter;
extern Uint16 logCounter;
extern char bufCAN[BUFSIZE];

/*****************************
 * Public Functions          *
 *****************************/
void SCHED_IDLE(void);
void watchdog(WDOG wd);
void watchdogKick(void);
void watchdogCheckIn(Uint8 which);
extern void display(disp mode, Uint8 status);
extern void setPort(Uint16 whichPort, Uint8 whichBit, Uint8 val);
extern Uint32 getSOC_CC_J(void);
extern Uint32 getSOCfull_CC_J(void);

extern void stateChange(pack_state which);
extern Bool PScontrol(PS_TYPE which, POWER ctl);
extern void shutdown(void);
extern void setupDiscretes(void);
extern void entering_isr (void);
extern void leaving_isr (void);
extern Uint8 crc8(Uint8 inCrc, Uint8 inData);
extern void writeINFOx(Uint8 *source, Uint8 *dest, Uint8 size);
extern void toggleHeater(Uint8 which);
extern void pigRail(POWER ctl);
extern void showFlashErasing(Uint8 which);
extern void prepareReboot(void);
extern POWER packBalance(POWER ctl);
extern void setHeater(Uint8 which, POWER enable);
extern void toggleDSG(void);
extern void toggleCHG(void);
extern POWER chargeControl(POWER req);
extern void DAC12trim(Uint8 which, Uint16 mV);
extern POWER fetCtrl(fet which, POWER ctl);
extern Uint8 fetCheck(fet which);
extern void checkFETsOn(void);
extern void busConnectedCheck(void);
extern void setLEDpermanentFault(void);
extern void setLEDtransientFault(void);
extern void commandGoStorage(void);
extern void boosterLatchClear(void);


extern void flashResp(void);

extern   swatPack pack;


static bool heaterFlag;

// SOC related
static bool needSyncSOC;
static Uint8 overrideSOCLimit;

#endif
