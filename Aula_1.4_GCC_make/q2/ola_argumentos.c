#include <stdio.h>

int main(int argc, char **argv)

{
	int counter = 0;

	for (counter=0; counter<argc; ++counter)

		printf("%s ", argv[counter]);

	return 0;	
}