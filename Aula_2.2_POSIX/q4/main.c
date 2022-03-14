#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, const char * argv[])
{  
    char nome[100] = "Nome: ";
    char idade[100] = "Idade: ";
    char filename[100];
    sprintf(filename, "%s.txt", argv[1]);
    int p = open(filename, O_RDWR|O_CREAT);
    if (!p)
    {
        printf("Erro na abertura do arquivo!\n");
        exit(-1);      
    }
    write(p, nome, 1);
    write(p, argv[1], 1);
    write(p, "\n", 1);
    write(p, idade, 1);
    write(p, argv[2], 1);
    close(p);
    return 0;
}