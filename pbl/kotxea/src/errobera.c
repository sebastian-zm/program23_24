#include <stdio.h>
#include "erroberak.h"

/*
void ERROBERA_kontrolatu(ERROBERA_NORANZKOA n, unsigned aurrera, unsigned atzera, unsigned speed)
{
	switch (n) {
	case ERROBERA_AURRERA:
		gpioPWM(aurrera, speed);
		gpioWrite(atzera, 0);
		break;
	case ERROBERA_ATZERA:
		gpioWrite(aurrera, 0);
		gpioPWM(atzera, speed);
		break;
	default:
		gpioWrite(aurrera, 0);
		gpioWrite(atzera, 0);

	}
}
*/

void ERROBERA_init()
{
	printf("GPIO hasieratzen...");
}

/*
void ERROBERA_mugitu(ERROBERA e, ERROBERA_NORANZKOA n, unsigned speed)
{
	switch (e) {
	case ERROBERA_AURREKO_EZKERRA:
		ERROBERA_kontrolatu(n, 18, 23, speed);
		break;
	case ERROBERA_AURREKO_ESKUMA:
		ERROBERA_kontrolatu(n, 24, 25, speed);
		break;
	case ERROBERA_ATZEKO_EZKERRA:
		ERROBERA_kontrolatu(n, 12, 16, speed);
		break;
	case ERROBERA_ATZEKO_ESKUMA:
		ERROBERA_kontrolatu(n, 20, 21, speed);
		break;
	}
}

void ERROBERA_ezkerrekoak(ERROBERA_NORANZKOA n, unsigned speed) // eskubira juteko ezkerrekoak aurrera eta eskumakoak atzera
{															// ezkerrera juteko eskubikoak aurrera eta ezkerrekoak atzera
	ERROBERA_mugitu(ERROBERA_AURREKO_EZKERRA, n, speed);   // aurrera biak aurrera
	ERROBERA_mugitu(ERROBERA_ATZEKO_EZKERRA, n, speed);
}

void ERROBERA_eskumakoak(ERROBERA_NORANZKOA n, unsigned speed)
{
	ERROBERA_mugitu(ERROBERA_AURREKO_ESKUMA, n, speed);
	ERROBERA_mugitu(ERROBERA_ATZEKO_ESKUMA, n, speed);
}
*/

void ERROBERA_aurrera(unsigned speed)
{
	printf("aurrera joaten %u abiadurarekin...\n", speed);
}

void ERROBERA_atzera(unsigned speed)
{
	printf("atzera joaten %u abiadurarekin...\n", speed);
}

void ERROBERA_eskumara(unsigned speed)
{
	printf("eskumara joaten %u abiadurarekin...\n", speed);
}

void ERROBERA_ezkerrera(unsigned speed)
{
	printf("ezkerrera joaten %u abiadurarekin...\n", speed);
}
void ERROBERA_gelditu()
{
	printf("gelditzen...\n");

}

