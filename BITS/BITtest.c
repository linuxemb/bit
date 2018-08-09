#include "bitData.h"

#include "stdbool.h"
#include <stdint.h>
#include "stdio.h"
#include "discretes.h"
#include "ApplicationTypes.h"
TestData_t data;

void setTestData(TestData_t data)
{
#ifdef BIT_FETON_TEST
	data.fetonbit.adcStackV = 26;
	data.fetonbit.adcTerminalFuseV = 27;
#endif

#ifdef BIT_IMB_TEST
	data.cellImbalance.cellVmin = 3.1;
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

// helper function prototype in 6T
PUBLIC OnOff_t DiscreteRead(DiscreteChannel_t channel)
{
	return On;
}
 // Framework======================================================

 




 /*********************************************************************
* Function:        FETsOnBIT
*
* Side Effects:    None
*
* Overview:        Part of CBit, sanity tests for FETs ON operation during charging
*                  or discharging, by detection of FET body-diode volt-drops. Depending
*                  on whether charging or discharging, determines which FET is tested.

********************************************************************/


 uint8_t fetCheck(state_t which)
 {
	 uint8_t ret;

	 if (which == discharge)
	 {
		ret =  DiscreteRead(MSP_DSG); 
	 }
	 else
	 {
		 ret = DiscreteRead(MSP_CHG);

	 }

	 return (ret);
 }
 

void  FETsON(TestData_t data)
 {
	printf("FETsOn \n");
  static uint8_t failureCounts = 0;

  uint8_t fetsVoltDrop = abs(data.fetonbit.adcTerminalFuseV - data.fetonbit.adcStackV);  // mV

  if (fetsVoltDrop > FETS_VOLT_DROP_MAX)
  {
    if ((fetCheck(charge)) && (fetCheck(discharge)))                  // Both FETs must be ON!
    {
      if (++failureCounts > 2)
      {

		  data.result_type.FETsONTestResult = 1;
      /*  if (OSReadEFlag(EF_EVENTS2_P) & event_chargingActive)
        {
          OSSetEFlag(EF_EVENTS2_P, event_dsgFetERR);
		 // LogAlarm( event_dsgFetERR, AlarmON, 0 );
        }
		*/
        /*else if (OSReadEFlag(EF_EVENTS2_P) & event_dischargingActive)
        {
          OSSetEFlag(EF_EVENTS2_P, event_chgFetERR);
		//  LogAlarm( event_chgFetERR, AlarmON, 0 );
      */  }
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
 



void runBIT(TestData_t data)
{
	  printf("top runBIT   \n");
	
	// Configurable by add or remove the function pointer in the array 
	//fp func[2] = { &FETsOn, &cellImb };
   
	FETsON(data);

	/*for (uint8_t i = 0; i < 2; i++)
	{
	printf("travel all func array _ %d \n", i);
	func[i](data);

	}*/
}





void cellImb(TestData_t data)
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
//Cell Imbalnace check
//
//chargeEffieiencyERR
