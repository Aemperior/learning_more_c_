#include <stdio.h>
#include <signal.h>
#include <setjmp.h>
#include <pthread.h>
#include <unistd.h>

jmp_buf main_env;
jmp_buf thread_env; 

void *thread_print_func(void *str){

	int thread_counter = 0; 
	if(setjmp(thread_env) == 0){ 
	}else{
		thread_counter = 0; 
	}

	while(1){
		printf("Thread %s counter = %i\n", (char *)str, thread_counter);
		thread_counter++; 
		if(thread_counter%10==0){
			printf("Resetting thread, lonjmp :)\n"); 
			longjmp(thread_env, 0); 
		} 
		sleep(2); 
	}
}

int main(void) {

	pthread_t thread1; 

	char *thread_1_msg = "1"; 
	pthread_create(& thread1, NULL, thread_print_func, (void*)thread_1_msg); 

	int main_counter = 0; 
	setjmp(main_env); 
	if(setjmp(main_env) == 0){ 
	}else{
		main_counter = 0; 
	}

	while(1){
		//printf("Started\n");
		sleep(1); 
		printf("main thread counter = %i\n", main_counter);
		main_counter++; 
		if(main_counter%10==0){
			printf("Resetting main, lonjmp :)\n"); 
			longjmp(main_env, 0); 
		} 
	}

	return 0; 
}

// https://pubs.opengroup.org/onlinepubs/9699919799/functions/longjmp.html

// I am having a hard time interpreting the documentation, I understand that if I start using longjmp with a jmp_buff set by another thread, then thinks start getting funky, both the documentation and the stackoverflow thread I found say as much.

// However, I don't see clearly what'll happen if longjmp() is used normally with a jmp_buf modified only by the thread calling lonjump? The documentation specifies that the environment of the same process 