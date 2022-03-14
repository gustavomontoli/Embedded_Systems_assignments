#include <stdio.h>

#include <stdlib.h>

#include "ola.h"



int main(int argc, char**argv)

{

	if(argc<2) return -1;

	ola_mundo(argv[1]);

	return 0;

}