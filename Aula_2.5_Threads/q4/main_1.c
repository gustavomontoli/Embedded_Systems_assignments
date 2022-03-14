#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_random(long int array[], long int length, long int max);

int main(void)
{
  // fornece o gerador de números aleatórios com um valor diferente 
  // cada vez que o programa é executado para garantir que obtenhamos diferentes números aleatórios cada
  // tempo que o programa roda
  srand( time(NULL) );
  
  // criar um long int array de tamanho 50000
  long int a[50000];
  
  long int n = sizeof(a)/sizeof(a[0]);
  
  long int sum=0, avg=0;

  // preencher array com numeros aleatorios
  fill_random(a, 50000, rand());
  
  // verificar a saída dos numeros
  for (long int i = 0; i < 50000; i++)
    printf("a[%ld]=%ld\n", i, a[i]);
    
    // armazenar o valor médio em arr[0]
  for (long int i = 1; i < n; i++) 
  {
    sum = sum + a[i] ;
    avg = sum / n ;
  }

  printf("Valor médio = %ld", avg);
  
  return 0;
}

// preenche o array com valores aleatórios entre 1 e o valor máximo definido
void fill_random(long int array[], long int length, long int max)
{
  // faz um loop por cada indice do array... rand() % max resulta em 
  // um valor aleatorio entre 0 - (max-1), adicionando 1 desloca em 1 - max
  for (long int i = 0; i < length; i++)
    array[i] = (rand() % max) + 1;
}