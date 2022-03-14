#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, char *argv[ ])
{
    int i;
    pid_t pid_filho = fork();

    if(pid_filho == 0)
    {
        printf("Processo filho: \n");
    }

    else
    {
        printf("Processo pai: \n");
        
        for ( i = 1; i < argc; i++)
        {
            char a[255];
            execvp(argv[i], argv);
        }
    }
    return 0;
}