#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

#define N 50000

double multiplica_vetor(double *v, int tam)
{
	double v_mult, x = random();
	int i;
	for(v_mult=v[0], i=1; i<tam; i++)
	{
		v_mult = x*v[i];
	}
	return v_mult;
}

struct thread_params
{
  double *v_int;
  double v_mult_int;
  int tam;
};

void* mult_thread(void* parameters)
{
	struct thread_params* p = (struct thread_params*) parameters;
	p->v_mult_int = multiplica_vetor(p->v_int, p->tam);
	return NULL;
}

int main(void)
{
	double v[N], v_mult, x;
	int i;
	struct thread_params tp0, tp1, tp2, tp3;
	pthread_t thread0_id, thread1_id, thread2_id, thread3_id;

	srandom(time(NULL));
	for(i=0; i<N; i++)
	{
		v[i] = random();
        v_mult = multiplica_vetor(v, N);
	    printf("v[%d] = {%lf}", i, v_mult);
	}
	
	tp0.v_int = &(v[0*N/4]); 
	tp0.tam   = N/4;         
	tp1.v_int = &(v[1*N/4]); 
	tp1.tam   = N/4;         
	tp2.v_int = &(v[2*N/4]); 
	tp2.tam   = N/4;        
	tp3.v_int = &(v[3*N/4]); 
	tp3.tam   = N/4;         

	pthread_create(&thread0_id, NULL, &mult_thread, &tp0);
	pthread_create(&thread1_id, NULL, &mult_thread, &tp1);
	pthread_create(&thread2_id, NULL, &mult_thread, &tp2);
	pthread_create(&thread3_id, NULL, &mult_thread, &tp3);

	pthread_join(thread0_id, NULL);
	pthread_join(thread1_id, NULL);
	pthread_join(thread2_id, NULL);
	pthread_join(thread3_id, NULL);

	
	return 0;