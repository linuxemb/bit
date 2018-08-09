
#include "stdio.h"

#include <stdlib.h>

#include <stdbool.h>
#include "bitData.h"


// User can decide which test to run by set these macros
#define FETONBIT 1
#define  BIT_IMB_TEST 1
//define ....


#define TESTCASES 2
#define DEFAULT 0xffffffff



// extern functions

extern void setTestData(TestData_t data);
extern void runBIT(TestData_t data);



// for override simulat
main (void)
{
	
	printf("Testing... \n");
	// global data init

	TestData_t data;

	data.fetonbit.adcStackV = (Voltage_t)DEFAULT;
	data.fetonbit.adcTerminalFuseV = (Voltage_t)DEFAULT;
	data.cellimb.cellVmax = (Voltage_t)DEFAULT;
	data.cellimb.cellVmin = (Voltage_t)DEFAULT;
	
	data.result_type.canTestResult = 0 ;
	data.result_type.cellImbanceTestResult = 0;
	data.result_type.crctestResult = 0;
	data.result_type.FETsONTestResult = 0;
	data.result_type.heaterTestResult = 0;
			

	// Set up user test data 
	
	setTestData(data);

	// Run all test cases

	for (uint8_t i = 0; i < TESTCASES; i++)
	{
		runBIT(data);
	}
	
	getchar();
}
