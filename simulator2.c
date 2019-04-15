#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>


#define THREADS_NUM 5
#define resources 100 

sem_t mutex;

void* thread(void* arg)
{
	//wait
	sem_wait(&mutex);

	
	int randomTime = rand() %5 +1;

	sleep(randomTime);	
	

}


int main()
{
	pthread_t my_thread[THREADS_NUM];

	pthread_exit(NULL);
	sem_destroy(&mutex);
	return 0;
}
