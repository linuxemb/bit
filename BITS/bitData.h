/*******************************************************************
Name   bitData.h
DESCRIPTION:   

PROJECT:

*******************************************************************/
#ifndef BITDATA_H__		
#define BITDATA_H__

#include "stdint.h"
#include "stdbool.h"
#include "ApplicationTypes.h"

#define DEFAULT 0xffffffff

typedef uint16_t  Voltage_t;
typedef int16_t   temperature_t;
typedef uint8_t  soc_t;
typedef uint8_t  index_t;

// Using array of functions
//typedef bool(*fp) ();



typedef struct 
//typedef union
{
	
	struct  FETsOnBit {
		Voltage_t adcTerminalFuseV;
		Voltage_t adcStackV;
		state_t   state;
	} fetonbit;

	struct cellImbalnace
	{
		Voltage_t cellVmin;
		Voltage_t cellVmax;
	} cellimb;
	
		

	struct {
		uint8_t FETsONTestResult : 1;
		uint8_t cellImbanceTestResult : 1;
		uint8_t	canTestResult : 1;
		uint8_t	heaterTestResult : 1;
		uint8_t crctestResult : 1;
	} result_type;
	

} TestData_t;


// Initializer function that clears out the test data.
PUBLIC void  BitInitialize( TestData_t *data);

// Set up user test data 

PRIVATE void setTestData(TestData_t data);

// Run all test cases

PUBLIC void runBIT(TestData_t data);



// test funcs

PRIVATE void FETsOn(TestData_t data);
PRIVATE void cellImb(TestData_t data);

#endif