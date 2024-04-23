#ifndef GASOLINDEGIA_H
#define GASOLINDEGIA_H

#include "kp1_helper.h"

typedef enum GASOLINDEGIA_EGOERA_e {
	GASOLINDEGIA_ZABALIK = 'z',
	GASOLINDEGIA_ITXITA = 'i'
} GASOLINDEGIA_EGOERA;

typedef struct GASOLINDEGIA_ERREGAIA_s {
	double erosi;
	double saldu;
	double litro;
	
} GASOLINDEGIA_ERREGAIA;

typedef struct GASOLINDEGIA_s {
	int id;
	char izena[KP1_HELPER_MAX_STR];
	char konpainia[KP1_HELPER_MAX_STR];
	char kokapena[KP1_HELPER_MAX_STR];
	GASOLINDEGIA_EGOERA egoera;
	GASOLINDEGIA_ERREGAIA gasolina;
	GASOLINDEGIA_ERREGAIA gasoila;
	
} GASOLINDEGIA;

KP1_HELPER_CREATE_HEADER(
		GASOLINDEGIAK,
		GASOLINDEGIA,
		struct GASOLINDEGIA_s
)

double GASOLINDEGIAK_batazbeste_gasolina(GASOLINDEGIAK gasolindegiak);
double GASOLINDEGIAK_batazbeste_gasoila(GASOLINDEGIAK gasolindegiak);
void GASOLINDEGIAK_VIEW_batazbeste_saldu(FILE* fp, GASOLINDEGIAK gasolindegiak);
GASOLINDEGIAK GASOLINDEGIAK_VIEW_osatu(GASOLINDEGIAK gasolindegiak);
int GASOLINDEGIA_zabalik(void *g);
GASOLINDEGIAK GASOLINDEGIAK_osatu_zabalik(FILE *fp, GASOLINDEGIAK gasolindegiak);
int GASOLINDEGIAK_idz_aurkitu(int id, GASOLINDEGIAK gasolindegiak);

#endif
