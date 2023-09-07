#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

float F(float l, float l_min, float l1, float l2, float q){
	float P = (q*exp(-(l-l_min)/l1) + (1-q)*exp(-(l-l_min)/l2)); //P as per P(l) according to paper eq (1)
	return 1-P; 
}

float gen_mixt_expo_value(float l_min, float l1, float l2, float q){

	float randNum = (float)rand() / RAND_MAX; 

	float min_value = l_min; 
	float max_value = 500.0; 

	float left = min_value; 
	float right = max_value; 

	float epsilon = 1.0; 

	while (right - left > epsilon){
		float mid = (left+right)/2; 
		if (F(mid, l_min, l1, l2, q) > randNum) {
			right = mid; 
		}else{
			left = mid; 
		}
	}

	return (left + right)/2; 
}

int main(void) {

	srand(0); 

	FILE *file = fopen("random_nums.txt", "w"); 
	if (file == NULL){
		printf("Error opening file\n"); 
		return 1; 
	}

	for (int i = 0; i < 100000; i++)
	{
		float x = gen_mixt_expo_value(5.0, 17.23, 82.36, 0.44); 
		fprintf(file, "%f\n", x); 
	}
	
	fclose(file); 

	return 0; 
}