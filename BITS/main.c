
#include "stdio.h"

#include <stdlib.h>
#include "system.h"
#include <stdbool.h>
#include "bit.h"
#define FETONBIT 1
#define TESTCASES 2

extern swatPack pack;
extern bitData data;


main (void)

{
	
	printf("Testing... \n");
	// global data init
	initScoreboard();

	// Run all test cases

	for (uint8_t i = 0; i < TESTCASES; i++)
	{
		runBIT(i);
	}
	//showResult();
	getchar();
}
