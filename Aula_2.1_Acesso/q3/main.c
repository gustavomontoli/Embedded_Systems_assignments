#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{	
	FILE *p;
    char nome[120] = "Nome: ";
    char idade[120] = "Idade: ";
    char filename[100];
    sprintf(filename, "%s.txt", argv[1]);
	p = fopen(filename, "w");
    if (!p)
    {
        printf("Erro na abertura do arquivo!\n");
        exit(-1);      
    }
    fprintf(p, "%s", nome);
	fputs(argv[1], p);
	putc('\n', p);
    fprintf(p, "%s", idade);
	fputs(argv[2], p);
	fclose(p);
	return 0;
}