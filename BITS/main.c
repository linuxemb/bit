
#include "stdio.h"

#include <stdlib.h>

#include <stdbool.h>
#include "ApplicationTypes.h"
#include "BITtestDriver.h"

// User can decide which test to run by set these macros

//#define FETONBIT 1
#define  BIT_IMB_TEST 1
#define PC  1
//define ....


// extern functions

 PUBLIC void runBIT(TestData_t  *data);
 PUBLIC void BitInitialize(TestData_t *data);

// for override simulat
main (void)
{
	
	printf("Testing... \n");
	
	TestData_t data;
	
	TestData_t *pdata = &data;
	
	// global data init
	BitInitialize( &data );
	
	// Run all test cases
	 runBIT( &data );
	
	 // Check test results
	if (data.result_type.FETsONTestResult == FAIL )
	{
		// ... Report results ...
		printf("Bit Test Fail for FETOnBits \n");
	}
	else
	{
		printf("Bit Test passed for FETOnBits \n");
	}
	getchar();
}
