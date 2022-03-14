#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int pid;	// PID do processo filho
	int fd[2];	// Descritores do pipe
	char mensagem1[100];
	char mensagem2[100];
	pipe(fd); // Cria o pipe
	pid = fork(); // Cria o processo
	if(pid == 0) // Codigo do filho
	{
		if(read(fd[0], mensagem1, 30) < 0)
			printf("Erro na leitura do pipe\n");
		else
			printf("PAI: Não façais nada violento, praticai somente aquilo que é justo e equilibrado.\n");
		
		strcpy(mensagem2, "FILHO: Mas até uma criança de três anos sabe disso!");	
	    if (write(fd[1], mensagem2, 30) < 0)
			printf("Erro na escrita do pipe\n");
		printf("%s\n", mensagem2);
		sleep(1);
	}
	else // Codigo do pai
	{
		strcpy(mensagem1, "FILHO: Pai, qual é a verdadeira essência da sabedoria?");
		if (write(fd[1], mensagem1, 30) < 0)
			printf("Erro na escrita do pipe\n");
		printf("%s\n", mensagem1);
		sleep(1);
		
		if(read(fd[0], mensagem2, 30) < 0)
			printf("Erro na leitura do pipe\n");
		else
			printf("PAI: Sim, mas é uma coisa difícil de ser praticada até mesmo por um velho como eu...");
	}
	return 0;
}