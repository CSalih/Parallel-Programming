#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include <pthread.h>
#include <time.h>


#define TOTAL 500000000
int sums[8] = {0};
unsigned int seed[8];
int threads_num;
//sources
// #https://github.com/ishanthilina/Pthreads-Monte-Carlo-Pi-Calculation
// #Parallel Programming Part 3
// https://stackoverflow.com/questions/5248915/execution-time-of-c-program


void* thrfunc(void* arg){
	int threadNum = *(int*)arg;

	int localsum=0;
	unsigned int seed=time(NULL);
	for(int i=0;i<(TOTAL/threads_num);i++){
      		float x = rand_r(&seed)/ (float) RAND_MAX;
      		float y = rand_r(&seed)/ (float) RAND_MAX;
		int res = sqrt((x*x) + (y*y));
		if (res < 1 )
			localsum++;
	}

	sums[threadNum]=localsum;
	
}

	
// Compile gcc MonteCarlo-para.c -lm -lpthread
int main(int argc, char* argv[]){
	if (argc!=2) return 1;
	threads_num=atoi(argv[1]);


	pthread_t thread[threads_num];
	pthread_attr_t attr;

	int arg[] = {0,1,2,3,4,5,6,7,8};
	int i;
	// setup joinable threads with system scope
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
	// create N threads
	for(i=0; i<threads_num; i++)
		pthread_create(&thread[i], &attr, thrfunc, (void*)&arg[i]);
	// wait for the N threads to finish
	for(i=0; i<threads_num; i++)
		pthread_join(thread[i], NULL);

	int sum=0;
	for(int i=0;i<threads_num;i++)
		sum+=sums[i];

	float pi=4*sum/(float)TOTAL;
	printf("Pi is : %f\n",pi);
	return 0;
}
