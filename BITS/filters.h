
#ifndef __INCLUDE_Filters_
#define __INCLUDE_Filters_
/* ************************** */
/* Included Header Files      */
/* ************************** */



/* ************************** */
/* Preprocessor Macros        */
/* ************************** */
#define SOH_FILTER_SIZE                5
#define QEFF_FILTER_SIZE               4
#define BOOST_CURRENT_FILTER_SIZE      5
#define PACK_CURRENT_FILTER_SIZE      12



/*****************************
 * Data Structures           *
 *****************************/
struct MOVING_AVERAGE_FILTER {
  Uint8 num_samples;
  Uint8 next_sample;
  Uint8 box_size;
  Int16* samples;
};


/*****************************
 * Functions Prototypes      *
 *****************************/
void setupSOHFilters(Int16 val);
void setupQEFFilters(Int16 val);
void setupBoostCurrentFilters(Int16 val);
void setupPackCurrentFilters(Int16 val);
Int16 filterMovingAverage(Int16 new_value, struct MOVING_AVERAGE_FILTER* filter);



extern struct MOVING_AVERAGE_FILTER sohFilter;
extern struct MOVING_AVERAGE_FILTER qefFilter;
extern struct MOVING_AVERAGE_FILTER boostCurrentFilter;
extern struct MOVING_AVERAGE_FILTER packCurrentFilter;

#endif
