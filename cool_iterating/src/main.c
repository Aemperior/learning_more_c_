#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {

	//For example iterate through pairs of verteces thus 
	//iterating through edges (i, j)
	int nvert = 10; 
	for (int i = 0, j = nvert-1; i < nvert; j = i++){
		printf("(i, j) = (%i, %i)\n", i, j); 
	}

	int n = 10; //assume >=3

	for (int i=0, j=(i+1)%n, k=(i+2)%n; i < n; i=i+1, j=(j+1)%n, k=(k+1)%n){


		printf("(i, j, k) = (%i, %i, %i)\n", i, j, k); 

		// i+=1; 
		// j=(j+1)%n; 
		// k=(k+1)%n; 
	}


	return 0; 
}
