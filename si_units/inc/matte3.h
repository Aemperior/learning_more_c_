#ifndef MATTE3_H
#define MATTE3_H

typedef struct {
	float arr[3]; 
} vector_3; 

typedef struct {
	float mat[3][3]; 
} matrix_33; 

void mv_mult(const matrix_33 *A, const vector_3 *x, vector_3 *v_out); 

void skew(const vector_3 *x, matrix_33 *M_out); 

#endif //MATTE3_H