#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {

	
	#define ELEM_MACRO(i) i

	int my_arr[] = {
		[3] = ELEM_MACRO(3),
		[1] = ELEM_MACRO(1), 
		[2] = ELEM_MACRO(2),
	};

	int my_arr2[] = { 
		ELEM_MACRO(0), 
		ELEM_MACRO(1),
		ELEM_MACRO(2),
	}; 


	float random = ((float)rand()) / (float)RAND_MAX; 

	float my_float = 120.123456; 
	int my_int = 10; 

	int a = (int)(my_float*100); 
	int c = (int)my_float*100; 
	float b = (float)my_int; 


	int32_t lat = 599086770; 
	float f_lat = (float)lat; 

	return 0; 
}
