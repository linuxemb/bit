#include "bqdata.h"
#include "bit.h"
#include "system.h"

 swatPack pack; 
 
 bitData data;

 initScoreboard()
 {
	 bms_ bms;         
	 bms.ASOC = 88;// Above
	 pack.heaters = 0;                   // bitfield ON/OFF (see schematic mapping)
	 //pack.tempSensor[NUM_SENSORS] = {B 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	 pack.adcStackV  = 27;                 // mV
	 pack.adcTerminalFuseV =27 ;          // mV
	 pack.adcPackV =27;                  // mV
	 pack.adcHeaterFuseV1 = 0;           // mV
	 pack.adcBOOSTImon =0;              // mA
	 pack.adcDSGmon = 39;                 // mV
	 pack.adc3_3pigmon =5;              // mV
	 pack.adc5_0mon =0 ;                 // mV
	 pack.adc3_3linmon =0 ;              // mV
	 pack.adcHeaterFuseV2 =2;           // mV
	 pack.systemDateTimeSeconds = 3;     // This means Midnight, Jan 1, 1970 (Unix Epoch)
	 pack.initControl =0;               // If this fixed pattern changes (Eg loss of power during maintenance etc), it forces a "swatPack" structure reinitialization.
	
 }
// for override simulat