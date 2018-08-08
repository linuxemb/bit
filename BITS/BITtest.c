#include "bit.h"
#include "types.h"
#include "stdbool.h"
#include <stdint.h>
#include "bqdata.h"
#include "system.h"
#include "stdio.h"

 bitData data;
 swatPack pack;
//============================
// PBIT -- Power-up BIT

//=============================
// FET OFF test


//
//Cell Calibration check
//Cell Imbalnace check
//
//chargeEffieiencyERR


//==================================
//       CBIT--

//==================================
/*********************************************************************
* Function:        FETsOnBIT
*
* PreCondition:    None
*
* Input:           None
*
*
* Output:          None
*
* Side Effects:    None
*
* Overview:        Part of CBit, sanity tests for FETs ON operation during charging
*                  or discharging, by detection of FET body-diode volt-drops. Depending
*                  on whether charging or discharging, determines which FET is tested.
*
* Note:            Schematics!
*
********************************************************************/
void FETsOnBIT(void)
{
  //static Uint8 failureCounts = 0;

  //Uint16 fetsVoltDrop = abs(pack.adcTerminalFuseV - pack.adcStackV);  // mV

  //if (fetsVoltDrop > FETS_VOLT_DROP_MAX)
  //{
  //  if ((fetCheck(CHG)) && (fetCheck(DSG)))                  // Both FETs must be ON!
  //  {
  //    if (++failureCounts > 2)
  //    {
  //      if (OSReadEFlag(EF_EVENTS2_P) & event_chargingActive)
  //      {
  //        OSSetEFlag(EF_EVENTS2_P, event_dsgFetERR);
		//  LogAlarm( event_dsgFetERR, AlarmON, 0 );
  //      }
  //      else if (OSReadEFlag(EF_EVENTS2_P) & event_dischargingActive)
  //      {
  //        OSSetEFlag(EF_EVENTS2_P, event_chgFetERR);
		//  LogAlarm( event_chgFetERR, AlarmON, 0 );
  //      }
  //      else
  //      {
  //        failureCounts = 0;
  //      }
  //    }
  //  }
  //  else
  //  {
  //    failureCounts = 0;
  //  }
  //}
  //   
  //else
  //{
  //  failureCounts = 0;
  //}
}
void cellImb() {


}


populateData(uint8_t testCase) {
	 
	printf("populatedata %d \n", testCase);
	switch (testCase)
	{
	case FETON:
		data.fetonbit.adcStackV = pack.adcStackV;
		data.fetonbit.adcTerminalFuseV = pack.adcTerminalFuseV;
		break;
	case CELLIMB:
		//init(CELLIMB);
		break;
	default :
		break;
	}

}




//  Heater fuse error
// Short Circuit
//Flash chip error
// Fuse error

// Can error



void showResult(uint8_t bitIdx)
{

	if (data.result == false)
	{
		printf("Test of %d , failed \n", bitIdx);
	}
	else
		printf("Test of %d , passed \n", bitIdx);
}


void runBIT(uint8_t testcase)
{
    printf("top runBIT  %d \n", testcase);
	populateData(testcase);
	// Configurable by add or remove the function pointer in the array 
	fp func[2] = { &FETsOnBIT, &cellImb };

	for (int i = 0; i < 2; i++)
		{
		printf("travel all func array _ %d \n", i);
		func[i]();	
		showResult(i);
		}
}
