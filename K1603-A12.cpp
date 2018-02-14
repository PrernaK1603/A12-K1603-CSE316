	#include<stdio.h>
	#include<pthread.h>
	#include<time.h>
    #include<assert.h>
	
	#define MIN_PID 100
	#define MAX_PID 1000
	
	pthread_mutex_t Lock;
	
	struct process 
           {
		int pid, isAllocated;
	            }obj[MAX_PID-MIN_PID];
				      
    int main() 
	{
 	if(allocate_map()) 
           {
		srand(time(0));
		createProcess();
		}
		return 0;
	}
