#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char * argv[]) 
{
    int i;
    char str[100] = "Olá mundo!\n";

    int fp = open("ola_mundo.txt", O_RDWR|O_CREAT);

    if(fp==-1)
	{
		printf("Erro na abertura do arquivo.\n");
		exit(-1);
	}

    for (i = 0; str[i] != '\n'; i++)
    {
        write(fp, &(str[i]), 1);
    }

    write (fp, "\n", 1);
    close(fp);
    return 0;
}
