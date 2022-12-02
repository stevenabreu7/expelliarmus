#ifndef EVENTS_H 
#define EVENTS_H

#include <stdlib.h>
#include <stdint.h>

typedef int64_t timestamp_t;  
typedef int16_t address_t; 
typedef uint8_t polarity_t; 

typedef struct event_s {
	timestamp_t t; 
	address_t x; 
	address_t y; 
	polarity_t p; 
} event_t; 

typedef struct {
	size_t dim; 
	uint8_t is_chunk; 
	uint8_t is_time_window; 
	size_t bytes_done; 
} event_cargo_t; 

#define CHECK_TIMESTAMP_MONOTONICITY(timestamp, prev_timestamp){\
	if ((timestamp) < (prev_timestamp))\
		fprintf(stderr, "WARNING: the timestamps are not monotonic. Current: %ld; previous:%ld.\n", timestamp, prev_timestamp);\
}	

#endif
