#ifndef BITTESTDRIVER_H__		
#define BITTESTDRIVER_H__

#include "bitData.h"

// User can decide which test to run by set these macros

#define CFETONBIT 1
#define  IMBBIT 1
#define DFETONBIT 1

#define FAIL 1

#define PCSIM 1   // runnimg on PC simulation

// User can play with these input data for runBIT () function

#define STACKV  26000
#define TERMINALV 26500
#define CELLVMIN 2800
#define CELLVMAX 4200

// extern functions

PUBLIC void runBIT(TestData_t data);
PUBLIC void BitInitialize(TestData_t *data);


#endif
