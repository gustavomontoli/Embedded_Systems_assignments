#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int v_global = 0; 

void Incrementa_Variavel_Global(pid_t id_atual)
{
	v_global++;
	printf("ID do processo que executou esta funcao = %d\n", id_atual);
	printf("v_global = %d\n", v_global);
}

int main (void)
{
    int pid_filho0, pid_filho1, pid_filho2;

    pid_filho0 = fork();

    if (pid_filho0 == 0)
    {
        sleep(3);
        Incrementa_Variavel_Global;
    }
   
    else
    {
        pid_filho1 = fork();

        if (pid_filho1 == 0)
        {
            sleep(2);
            Incrementa_Variavel_Global;
        }
       
        else
        {
            pid_filho2 = fork();

            if (pid_filho2 == 0)
            {
                Incrementa_Variavel_Global;
            }
                   
            else
            {
                sleep(3);
            }
        }
    }
    return 0;
}