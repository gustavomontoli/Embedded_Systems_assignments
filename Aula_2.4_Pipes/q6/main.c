#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int pid1, pid2;	// PID do processo filho
	int fd[3];	// Descritores do pipe
	char mensagem[100];
	char mensagem2[100];
	pipe(fd); // Cria o pipe
	pid1, pid2 = fork(); // Cria o processo
	if(pid1 != 0) // Codigo do pai
	{
		if(read(fd[0], mensagem2, 30) < 0) 
			printf("Erro na leitura do pipe\n");
		else
			printf("PAI: Os dois se enganam. É a mente dos senhores que se move.\n");
	}
	else if (pid2 != 0) // Codigo do filho 2
	{
		strcpy(mensagem2, "FILHO2: Não, é o vento que se move.\n");
		if (write(fd[1], mensagem2, 30) < 0)
			printf("Erro na escrita do pipe\n");
		printf("%s", mensagem2);
        sleep(1);
	}
	else // Codigo do filho 1
	{
	    strcpy(mensagem, "FILHO1: Quando o vento passa, é a bandeira que se move.\n");
		if (write(fd[2], mensagem, 30) < 0)
			printf("Erro na escrita do pipe\n");
		printf("%s", mensagem);
        sleep(1);
	}