#include <stdio.h>
#include <signal.h>
#include <setjmp.h>
 
jmp_buf env_sigsegv;

void sigsegv_handler(){
	printf("Woops, manage your memory better next time\n");  
	longjmp(env_sigsegv, 2); 
}

int main(void) {

	signal(SIGSEGV, sigsegv_handler); 

	int* ptr = NULL; 

	setjmp(env_sigsegv); 
	if (setjmp(env_sigsegv) == 0){
		*ptr = 42; 
	}else{
		printf("We had to skip that memory access\n"); 
	}


	return 0; 
}
