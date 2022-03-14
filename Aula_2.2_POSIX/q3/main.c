#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, const char * argv[])
{
    /*FILE *fp;*/
    char name[100];
    char filename[100];
    char age[100];
    char nome[120] = "Nome: ";
    char idade[120] = "Idade: ";
    printf("Digite seu nome: \n");
    fflush(stdout); // utilizado para corrigir o gets vindo antes do printf
    gets(name);
    printf("Digite sua idade: \n");
    fflush(stdout);
    gets(age);
    sprintf(filename, "%s.txt", name); // sprintf utilizado para nomear o arquivo txt com o nome de entrada
    int fp = open(filename, O_RDWR|O_CREAT);
    strcat(nome, name);
    strcat(idade, age);
    if (!fp)
    {
        printf("Erro na abertura do arquivo!\n");
        exit(-1);      
    }
    write(fp, nome,1);
    write (fp, "\n", 1);
    write(fp, idade, 1);
    close(fp);
    return 0;
}