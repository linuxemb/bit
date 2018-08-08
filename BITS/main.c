
#include "stdio.h"
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
//void FETsOnBIT(void)
//{
//  static Uint8 failureCounts = 0;
//
//  Uint16 fetsVoltDrop = abs(pack.adcTerminalFuseV - pack.adcStackV);  // mV
//
//  if (fetsVoltDrop > FETS_VOLT_DROP_MAX)
//  {
//    if ((fetCheck(CHG)) && (fetCheck(DSG)))                  // Both FETs must be ON!
//    {
//      if (++failureCounts > 2)
//      {
//        if (OSReadEFlag(EF_EVENTS2_P) & event_chargingActive)
//        {
//          OSSetEFlag(EF_EVENTS2_P, event_dsgFetERR);
//		  LogAlarm( event_dsgFetERR, AlarmON, 0 );
//        }
//        else if (OSReadEFlag(EF_EVENTS2_P) & event_dischargingActive)
//        {
//          OSSetEFlag(EF_EVENTS2_P, event_chgFetERR);
//		  LogAlarm( event_chgFetERR, AlarmON, 0 );
//        }
//        else
//        {
//          failureCounts = 0;
//        }
//      }
//    }
//    else
//    {
//      failureCounts = 0;
//    }
//  }
//     
//  else
//  {
//    failureCounts = 0;
//  }
//}
//
//






//  Heater fuse error
// Short Circuit
//Flash chip error
// Fuse error

// Can error







main (void)

{
	printf("testing \n");
	getchar();
}
