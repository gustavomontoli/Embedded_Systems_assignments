#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

#define N 50000

long int avg_vetor(long int *v, int tam)
{
	long int v_avg, sum;
	int i;
	for(v_avg=v[0], i=1; i<tam; i++)
	{
		sum = sum + v[i];
        v_avg = sum/tam;
	}
	return v_avg;
}

struct avg_thread_parms
{
	long int *v_int;
	long int v_avg_int;
	int tam; 
};

void* avg_thread(void* parameters)
{
	struct avg_thread_parms* p = (struct avg_thread_parms*) parameters;
	p->v_avg_int = avg_vetor(p->v_int, p->tam);
	return NULL;
}

int main(void)
{
	long int v[N], v_avg, v_avg_threads;
	int i;
	struct avg_thread_parms mtp0, mtp1, mtp2, mtp3;
	pthread_t thread0_id, thread1_id, thread2_id, thread3_id;

	srandom(time(NULL));
	for(i=0; i<N; i++)
	{
		v[i] = random();
		if(i<10)
		{
			printf("v[%d] = %ld\n", i, v[i]);
		}
	}

	v_avg = avg_vetor(v, N);
	printf("avg(v[]) = %ld\n", v_avg);

	mtp0.v_int = &(v[0*N/4]); // Endereço de v[0] 
	mtp0.tam   = N/4;         // Percorrer 12500 posições
	mtp1.v_int = &(v[1*N/4]); // Endereço de v[12500]
	mtp1.tam   = N/4;         // Percorrer 12500 posições
	mtp2.v_int = &(v[2*N/4]); // Endereço de v[25000]
	mtp2.tam   = N/4;         // Percorrer 12500 posições
	mtp3.v_int = &(v[3*N/4]); // Endereço de v[37500]
	mtp3.tam   = N/4;         // Percorrer 12500 posições

	pthread_create(&thread0_id, NULL, &avg_thread, &mtp0);
	pthread_create(&thread1_id, NULL, &avg_thread, &mtp1);
	pthread_create(&thread2_id, NULL, &avg_thread, &mtp2);
	pthread_create(&thread3_id, NULL, &avg_thread, &mtp3);

	pthread_join(thread0_id, NULL);
	pthread_join(thread1_id, NULL);
	pthread_join(thread2_id, NULL);
	pthread_join(thread3_id, NULL);

	return 0;
}