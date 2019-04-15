#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>


#define THREADS_NUM 5
#define RESOURCES 100 

sem_t mutex;

void* thread(void* arg)
{
	//wait
	sem_wait(&mutex);
	printf("Entro");
	
	int randomTime = rand() %5 +1;

	sleep(randomTime);	
	
	printf("Salio");
	sem_post(&mutex);
}


int main()
{
	FILE *fp;
	FILE *fptr;

	fptr = fopen("sim1.txt", "r");
	fp = fopen("sim1.txt", "w");

	fprintf(fp, "Iniciando programa! \n");

	sem_init(&mutex, 0, 1);	
	
	pthread_t my_thread[THREADS_NUM];
	pthread_create(&my_thread[0], NULL, thread, NULL);
	sleep(2);

	pthread_exit(NULL);
	sem_destroy(&mutex);
	return 0;
}
