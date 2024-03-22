#ifndef GELA_H
#define GELA_H

#include "ikaslea.h"

#define GELA_MAX_IKASLEAK 30
#define GELA_MAX_STR 64
#define GELA_GAINDITZEKO_NOTA 5.0

typedef struct GELA_s {
	int ikasle_kop;
	IKASLEA ikasleak[GELA_MAX_IKASLEAK];
} GELA;

double GELA_otsaileko_batazbestekoa(GELA g);
double GELA_ekaineko_batazbestekoa(GELA g);
double GELA_batazbesteko_finala(GELA g);
double GELA_gaindituen_ehunekoa(GELA g);
int GELA_ikaslea_aurkitu(GELA g, int ik_id);
int GELA_id_sortu(GELA g);
int GELA_gainditutako_ikasleak(GELA g, IKASLEA gaindituak[], int max_gaindituak);
GELA GELA_ikaslea_gehitu(GELA g, IKASLEA ik);

#endif
