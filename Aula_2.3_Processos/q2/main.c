#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[ ]) 
{
    int i; 

    for ( i = 1; i < argc; i++)
    {
        char a[255];
        sprintf(a, "%s", argv[i]);
        system(a);
    }

    return 0;
}