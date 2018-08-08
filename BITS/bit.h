#include "stdint.h"
#include "stdbool.h"


typedef uint16_t  Voltage_t;
typedef int16_t   temperature_t;
typedef uint8_t  soc_t;
typedef uint8_t  index_t;

// Using array of functions
typedef bool(*fp) ();

void FETsOnBIT();
void cellImb();


typedef enum  {
	FETON,
	FETOFF,
	CELLIMB,
	BQCHIP
	
} testCase;

struct FETsOnBit {
	Voltage_t adcTerminalFuseV;
	Voltage_t adcStackV;
};
struct cellImbalnace
{
	uint16_t cellVmin;
	uint16_t cellVmax;
};

typedef struct 
{
	struct FETsOnBit fetonbit;
	bool result;
} bitData;



