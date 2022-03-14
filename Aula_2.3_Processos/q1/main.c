#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main (void)
{
	int pid_filho0, pid_filho1, pid_filho2;

	pid_filho0 = fork();

	if (pid_filho0 == 0) 
	{
		sleep(3);
		printf("pid filho 0 = %d e ppid filho 0 = %d\n",
		getpid(), getppid());
	}
    
    else 
	{
        pid_filho1 = fork();

        if (pid_filho1 == 0) 
        {
            sleep(2);
            printf("pid filho 1 = %d e ppid filho 1 = %d\n",
            getpid(), getppid());
        }
        
        else 
		{
            pid_filho2 = fork();

            if (pid_filho2 == 0) 
            {
               	printf("pid filho 2 = %d e ppid filho 2 = %d\n",
                getpid(), getppid());
            }
            		
            else 
			{
                sleep(3);
                printf("pid pai = %d\n", getpid());
            }
        }
    }
    return 0;
}