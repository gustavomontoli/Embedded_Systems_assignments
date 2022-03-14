#include <wiringPi.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int pin = 7;
	int periodo_us = 1000000; //período em microssegundos para que a frequência da onda seja de 1 Hz.
	int periodo_alto = 500000;
	int periodo_baixo = periodo_us - periodo_alto;

	wiringPiSetup();
	pinMode(pin, OUTPUT);
	while(1)
	{
		digitalWrite(pin, HIGH);
		usleep(periodo_alto);
		digitalWrite(pin, LOW);
		usleep(periodo_baixo);
	}
	return 0;
}