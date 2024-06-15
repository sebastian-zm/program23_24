#ifndef ERROBERAK_H
#define ERROBERAK_H

typedef enum ERROBERA_e {
	ERROBERA_AURREKO_EZKERRA,
	ERROBERA_AURREKO_ESKUMA,
	ERROBERA_ATZEKO_EZKERRA,
	ERROBERA_ATZEKO_ESKUMA,
} ERROBERA;

typedef enum ERROBERA_NORANZKOA_e {
	ERROBERA_AURRERA,
	ERROBERA_ATZERA
} ERROBERA_NORANZKOA;

void ERROBERA_init(void);
void ERROBERA_mugitu(ERROBERA e, ERROBERA_NORANZKOA n, unsigned speed);
void ERROBERA_eskumakoak(ERROBERA_NORANZKOA n, unsigned speed);
void ERROBERA_ezkerrekoak(ERROBERA_NORANZKOA n, unsigned speed);
void ERROBERA_aurrera(unsigned speed);
void ERROBERA_atzera(unsigned speed);
void ERROBERA_eskumara(unsigned speed);
void ERROBERA_ezkerrera(unsigned speed);
void ERROBERA_gelditu();



#endif
