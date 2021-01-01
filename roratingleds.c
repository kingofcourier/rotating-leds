/*
 * Author:
 * Student Number:
 * Lab Section:
 * Date:             11/18/2020 12:41:50 AM
 *
 * Purpose:
 *
 */
#define _CRT_SECURE_NO_WARNINGS

 /* rotateLEDs.c
 * Rotates a lighted LED to the right, wrapping around, with a reset button. */
#include <DAQlib.h>
#include <Windows.h>
#include <stdio.h>
 /* symbolic constants */
#define SIMULATOR 2
#define ON 1
#define OFF 0
#define RESET 0
#define LED0 0
#define LED5 5
#define NUM_LEDS 6
#define ONE_SECOND 1000
/* function prototypes */
void rotateLEDs(void);
/* main function */
int main(void)
{
	/* initialize simulator and run control loop */
	if (setupDAQ(SIMULATOR)) {
		rotateLEDs();
	}
	else {
		printf("Cannot initialize the DAQ\n");
	}
	return 0;
}

/*
	void rotateLEDs(void)
	{
		int led = 0;

		while (continueSuperLoop()) {
			int button0 = OFF;
			int i = 0;

			digitalWrite(led - 1, OFF);
			digitalWrite(led, ON);

			led++;

			if (digitalRead(RESET) == 1)
			{
				digitalWrite(led-1,OFF);
				led = 0;
			}

			Sleep(ONE_SECOND);

		}
	}


	void rotateLEDs(void) {
		int led = 0;
		while (continueSuperLoop()) {
			int button0 = OFF;
			int i = 0;
			digitalWrite(led - 1, OFF);
			digitalWrite(led, ON);

			led++;

			for (i = 0; i < 100; i++)
			{
				if (digitalRead(RESET) == 1)
				{
					digitalWrite(led-1, OFF);
					led = 0;
				}

				Sleep(10);
			}
		}
	}
	*/

void rotateLEDs(void)
{
	int led = 0; /* initialize LED index */
	int time;
	int time2;
	/* initialize timing variable */
	while (continueSuperLoop()) {
		int button0 = OFF; /* button state */
		int i = 0; /* loop counter */
		/* get current time */
		for (led = 0; led < 6; led++)
		{
			time2 = millis();
			while ((millis() - time2) < 1000)
			{
				if (led==0)
				{
					digitalWrite(LED5, OFF);
					digitalWrite(4, OFF);
					digitalWrite(3, OFF);
					digitalWrite(2, OFF);
					digitalWrite(1, OFF);
					digitalWrite(LED0, ON);
				}
				else
				{
					digitalWrite(led - 1, OFF);
					digitalWrite(led, ON);
				}
				/* implement timing and update */
					/* check reset button */

				button0 = digitalRead(RESET);
				if (button0 == ON)
				{
					led = 0;
					button0 = OFF;
				}
				
			}



		}
	}
}

