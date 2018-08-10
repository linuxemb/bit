
/*******************************************************************
BitTest.c

DESCRIPTION:-the bit test functions and algorithms, include only 2 public 
functions: BitInitialize(TestData_t *data) and runBit( TestData_t *data) 
and  lots of private functions to run different BIT tests.

PROJECT:  6T

*******************************************************************/

#include "bitData.h"
#include "BITtestConf.h"
#include "BITtestDriver.h"

#include "stdbool.h"
#include <stdint.h>
#include "stdio.h"
#include "discretes.h"
#include "ApplicationTypes.h"
#include <math.h>
#include <assert.h>
#include "ADC.h"

PUBLIC OnOff_t DiscreteRead(DiscreteChannel_t channel); 

PRIVATE  void setTestData(TestData_t  *data)
{
#ifdef DFETONBIT

	data->fetonbit.adcStackV = PCSIM ? STACKV : ADCReadVoltage(TerminalVSense);
	data->fetonbit.adcTerminalFuseV = PCSIM ? TERMINALV : ADCReadVoltage(VStackVSense);
	// retrieve the state of FET
	data->fetonbit.state = PCSIM ? discharge : DiscreteRead(MSP_DSG); ;  // for DSG BITC ON test
			
#endif

 #ifdef CFETONBIT

	data->fetonbit.adcStackV = PCSIM ? STACKV : ADCReadVoltage(TerminalVSense);
	data->fetonbit.adcTerminalFuseV = PCSIM ? TERMINALV : ADCReadVoltage(VStackVSense);
	// retrieve the state of FET
	data->fetonbit.state = PCSIM ? charge : DiscreteRead(MSP_CHG);  // for CFG BIT ON  test

#endif 
#ifdef IMBBIT
	data->cellimb.cellVmin = CELLVMIN; 
	data->cellimb.cellVmax = CELLVMAX;
#endif

#ifdef BIT_CELLCALIBRATION_TEST

#endif

#ifdef BIT_OVERHEAT_POWER_COMP_TEST

#endif
#ifdef BIT_OVERHEAT_POWER_COMP_TEST

#endif
#ifdef BIT_SELF_DISCHARGE_TEST
	
#endif
}


 // Framework======================================================
PUBLIC void BitInitialize(TestData_t *data)
{
	data->fetonbit.adcStackV = (Voltage_t)DEFAULT;
	data ->fetonbit.adcTerminalFuseV = (Voltage_t)DEFAULT;
	data ->cellimb.cellVmax = (Voltage_t)DEFAULT;
	data ->cellimb.cellVmin = (Voltage_t)DEFAULT;
	// set all test result to be pass at init
	data ->result_type.canTestResult = 0;
	data ->result_type.cellImbanceTestResult = 0;
	data->result_type.crctestResult = 0;
	data->result_type.FETsONTestResult = 0;
	data->result_type.heaterTestResult = 0;


}

 

 /*********************************************************************
* Function:        FETsOnBIT
*
* Side Effects:    None
*
* Overview:        Part of CBit, sanity tests for FETs ON operation during charging
*                  or discharging, by detection of FET body-diode volt-drops. Depending
*                  on whether charging or discharging, determines which FET is tested.

********************************************************************/



 

PRIVATE  void  FETsON(TestData_t *data )
 {
	printf("FETsOn \n");

	// Make sure the user has set up the necessary test input data, this will seperate the failure cased by improper usage of BITtest module
	
	assert(data->fetonbit.adcStackV != (voltage_t)DEFAULT);
	//printf("assert failed \n");
  static uint8_t failureCounts = 0;

  voltage_t fetsVoltDrop = abs(data-> fetonbit.adcTerminalFuseV - data -> fetonbit.adcStackV);  // mV

  if (fetsVoltDrop > FETS_VOLT_DROP_MAX)
  {
    //if ((fetCheck(charge)) && (fetCheck(discharge)))                  // Both FETs must be ON!
	  if ((data->fetonbit.state == charge) && (data ->fetonbit.state = discharge))
	  {
      if (++failureCounts > 2)
      {
		  data -> result_type.FETsONTestResult = 1;
      }
        else
        {
          failureCounts = 0; 
		}
      }
    }
    else
    {
      failureCounts = 0;	  
    }
  
  }
 

PUBLIC void runBIT( TestData_t *data )
{
	  printf("top runBIT   \n");
	  setTestData( data );


	// Configurable by add or remove the function pointer in the array 
	//fp func[2] = { &FETsOn, &cellImb };
   
	//FETsON( data );

	/*for (uint8_t i = 0; i < 2; i++)
	{
	printf("travel all func array _ %d \n", i);
	func[i](data);

	}*/
}




//Cell Imbalnace check
PRIVATE  void cellImb(TestData_t data)
{


}



// FET OFF test

//  Heater fuse error
// Short Circuit
//Flash chip error
// Fuse error

// Can error

//
//Cell Calibration check

//chargeEffieiencyERR
