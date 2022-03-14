#include <stdio.h>

int main() {
        int i;

        FILE * fp;

        char filename[50];

        char str[] = "Olá mundo!\n";

        fp = fopen("ola_mundo.txt", "w"); 

        for (i = 0; str[i] != '\n'; i++) 
        {
            fputc(str[i], fp);
        }

        fclose(fp);

        return 0;
    }