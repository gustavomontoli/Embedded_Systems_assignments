#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/poll.h>

struct pollfd pfd;
int pin_led = 0;

void f_ctrlc(int i)
{
    close(pfd.fd);
    system("echo 4 > /sys/class/gpio/unexport");
    digitalWrite(pin_led, LOW);
    exit(0);
}

int main(void)
{
    int freq = 50, duty_cyc = 0;
    int pid_filho;
    int periodo_us;
    int periodo_alto;
    int periodo_baixo;
    char buffer;

    wiringPiSetup();
    pinMode(pin_led, OUTPUT);
    system("echo 4       > /sys/class/gpio/export");
    system("echo falling > /sys/class/gpio/gpio4/edge");
    system("echo in      > /sys/class/gpio/gpio4/direction");
    pfd.fd = open("/sys/class/gpio/gpio4/value", O_RDONLY);
    pfd.events = POLLPRI | POLLERR;
    pfd.revents = 0;
    signal(SIGINT, f_ctrlc);
    while (1)
    {
        printf("Duty Cycle = %d %\n", duty_cyc);
        pid_filho = fork();
        if (pid_filho == 0)
        {
            while (1)
            {
                digitalWrite(pin_led, HIGH);
                usleep(periodo_alto);
                digitalWrite(pin_led, LOW);
                usleep(periodo_baixo);
            }
        }
        else
        {
            lseek(pfd.fd, 0, SEEK_SET);
            read(pfd.fd, &buffer, 1);
            poll(&pfd, 1, -1);
            do
            {
                lseek(pfd.fd, 0, SEEK_SET);
                read(pfd.fd, &buffer, 1);
            } while (buffer == '0');

            periodo_us = (int)(1.0e6 / freq);
            periodo_alto = (int)(periodo_us * duty_cyc / 100);
            periodo_baixo = periodo_us - periodo_alto;
            wiringPiSetup();
            pinMode(pin, OUTPUT);
            usleep(300000);
            duty_cyc += 25;
            if (duty_cyc < 100)
                kill(pid_filho, SIGKILL);
        }
    }
}