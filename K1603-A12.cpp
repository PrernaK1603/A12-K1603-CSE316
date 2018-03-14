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
	
	int allocate_map() 
   {
		int i=MIN_PID;
		while(i<=MAX_PID)
           {
			obj[i-MIN_PID].pid=i;
			obj[i-MIN_PID].isAllocated=0;
			i++;
		}
		return 1;
	}
	
	int allocate_pid()
   {
		int i=0;
		while(i<MAX_PID)
        {
			if (obj[i]. isAllocated==0) 
                       {
				pthread_mutex_lock(&Lock);
				obj[i]. isAllocated=1;
				pthread_mutex_unlock(&Lock);
				return obj[i].pid;
			}
			i++;
		}
		return -1;
	}
	
	void release_pid(int pid) 
{
		int i=0;
		while(i<MAX_PID) 
          {
			if(obj[i]. pid==pid) 
                       {
				int res=pthread_mutex_lock(&Lock);
                                    if(res==0)
                                   {
                                    printf(“Aborting the process as res==0”);
                                    } 
            				assert(res==0);
				obj[i]. isAllocated=0;
				res=pthread_mutex_unlock(&Lock);
				break;
			}
			i++;
		}
	}
	
				      
    int main() 
	{
 	if(allocate_map()) 
           {
		srand(time(0));
		createProcess();
		}
		return 0;
	}
