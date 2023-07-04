#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {

	int nvert = 10; 
	for (int i = 0, j = nvert-1; i < nvert; j = i++){
		printf("(i, j) = (%i, %i)\n", i, j); 
	}

	return 0; 
}
