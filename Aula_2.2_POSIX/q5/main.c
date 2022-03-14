#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1000

int contarOccorrencia(FILE *fp, const char *palavra);

int main(int argc, const char *argv[])
{
    char filename[100];
    char palavra[50];
    int count;

    printf("Digite o nome do arquivo: ");
    fflush(stdout);
    gets(filename);
    printf("Digite a palavra que você deseja pesquisar no arquivo: ");
    fflush(stdout);
    gets(palavra);
    int fp = open(filename, O_RDONLY|O_CREAT);

    if(!fp)
    {
        printf("Erro na abertura do arquivo!\n");
        exit(-1);
    }
   
    count = contarOccorrencia(fp, palavra);

    printf("'%s' ocorre %d vezes no arquivo %s.", palavra, count, filename);
    close(fp);
    return 0;
}

int contarOccorrencia(FILE *fp, const char *palavra)
{
    char str[BUFFER_SIZE]; // armazena o que está escrito em cada linha do arquivo-texto
    char *pos; //ponteiro para o caractere

    int indice, count;
   
    count = 0;

    while ((fgets(str, BUFFER_SIZE, fp)) != NULL) // ler inha por linha do arquivo até o fim
    {
        indice = 0;
        // Retornamos o ponteiro para a primeira ocorrência da palavra em uma string.
        // Para encontrar a primeira ocorrência da palavra na linha str, usamos
        // a função strstr
        while ((pos = strstr(str + indice, palavra)) != NULL)
        {
            // pos apontará para a primeira ocorrência da palavra em str se existir,
            //caso contrário aponta para NULL.
            indice = (pos - str) + 1;
            count++;
        }
    }
    return count;
}