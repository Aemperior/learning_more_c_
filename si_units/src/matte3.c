// #include "../inc/matte3.h"
// #include "../inc/SI_units.h"
#include "matte3.h"
#include "SI_units.h"

// v_out = A*x
void mv_mult(const matrix_33 *A, const vector_3 *x, vector_3 *v_out){
	v_out->arr[0] = (A->mat[0][0])*(x->arr[0])+(A->mat[0][1])*(x->arr[1])+(A->mat[0][2])*(x->arr[2]);
	v_out->arr[1] = (A->mat[1][0])*(x->arr[0])+(A->mat[1][1])*(x->arr[1])+(A->mat[1][2])*(x->arr[2]);
	v_out->arr[2] = (A->mat[2][0])*(x->arr[0])+(A->mat[2][1])*(x->arr[1])+(A->mat[2][2])*(x->arr[2]); 
}

// out = skew(x)
void skew(const vector_3 *x, matrix_33 *M_out){
	M_out->mat[0][0] = 0; 
	M_out->mat[1][1] = 0;
	M_out->mat[2][2] = 0;

	M_out->mat[0][1] = -x->arr[2];
	M_out->mat[0][2] = x->arr[2];
	M_out->mat[1][0] = x->arr[2];
	M_out->mat[1][2] = -x->arr[0];
	M_out->mat[2][0] = -x->arr[1];
	M_out->mat[2][1] = x->arr[0];
}

void v_cross(const vector_3 *in1, const vector_3 *in2, vector_3 *out){
	
}