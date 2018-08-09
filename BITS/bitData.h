#include "stdint.h"
#include "stdbool.h"



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

typedef enum {
	  FETsONTestResult ,
           cellImbanceTestResult ,
			canTestResult ,
			heaterTestResult ,
			 crctestResult 
}result;


typedef uint16_t  Voltage_t;
typedef int16_t   temperature_t;
typedef uint8_t  soc_t;
typedef uint8_t  index_t;

// Using array of functions
typedef bool(*fp) ();

typedef enum { FAIL, PASS } result_t;	// for event logging


typedef struct 
//typedef union
{
	//struct FETsOnBit fetonbit;
	struct  FETsOnBit {
		Voltage_t adcTerminalFuseV;
		Voltage_t adcStackV;
	} fetonbit;

	struct cellImbalnace
	{
		Voltage_t cellVmin;
		Voltage_t cellVmax;
	} cellimb;
	
		
	struct {
		uint8_t FETsONTestResult : 1;
		uint8_t cellImbanceTestResult : 1;
		uint8_t	canTestResult : 1;
		uint8_t	heaterTestResult : 1;
		uint8_t crctestResult : 1;
	} result_type;
	

} TestData_t;



// Globle data init for simulate data retrived from Hw
void initScoreboard();

// Set up user test data 

void setTestData(TestData_t data);

// Run all test cases

void runBIT(TestData_t data);



// test funcs

uint8_t FETsOn(TestData_t data);
uint8_t cellImb(TestData_t data);
