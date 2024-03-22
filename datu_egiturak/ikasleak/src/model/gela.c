#include <stdbool.h>
#include <stdlib.h>
#include "ikaslea.h"
#include "gela.h"

double GELA_otsaileko_batazbestekoa(GELA g)
{
	double batura = 0.0;
	double ikasle_nota;
	int i;

	for (i = 0; i < g.ikasle_kop; ++i) {
		ikasle_nota = IKASLEA_otsaileko_nota(g.ikasleak[i]);
		batura += ikasle_nota;
	}

	return batura / g.ikasle_kop;
}

double GELA_ekaineko_batazbestekoa(GELA g)
{
	double batura = 0.0;
	double ikasle_nota;
	int i;

	for (i = 0; i < g.ikasle_kop; ++i) {
		ikasle_nota = IKASLEA_ekaineko_nota(g.ikasleak[i]);
		batura += ikasle_nota;
	}

	return batura / g.ikasle_kop;
}

double GELA_batazbesteko_finala(GELA g)
{
	double batura = 0.0;
	double ikasle_nota;
	int i;

	for (i = 0; i < g.ikasle_kop; ++i) {
		ikasle_nota = IKASLEA_nota_finala(g.ikasleak[i]);
		batura += ikasle_nota;
	}

	return batura / g.ikasle_kop;
}

double GELA_gaindituen_ehunekoa(GELA g)
{
	double ikasle_nota;
	int gaindituak = 0;
	int i;

	for (i = 0; i < g.ikasle_kop; ++i) {
		ikasle_nota = IKASLEA_nota_finala(g.ikasleak[i]);
		if (ikasle_nota >= GELA_GAINDITZEKO_NOTA) {
			++gaindituak;
		}
	}

	return 100.0 * (double)gaindituak / (double)g.ikasle_kop;
}

int GELA_ikaslea_aurkitu(GELA g, int ik_id)
{
	int i = 0;

	while (i < g.ikasle_kop && g.ikasleak[i].id != ik_id) {
		++i;
	}

	if (i >= g.ikasle_kop) {
		i = -1;
	}

	return i;
}

int GELA_id_sortu(GELA g)
{
	int ret;

	do {
		ret = rand();
	} while (GELA_ikaslea_aurkitu(g, ret) != -1);

	return ret;
}

int GELA_gainditutako_ikasleak(GELA g, IKASLEA gaindituak[], int max_gaindituak)
{
	IKASLEA ikaslea;
	double ikasle_nota;
	int ikasle_idx = 0;
	int ikasle_gainditu_len = 0;

	while (ikasle_idx < g.ikasle_kop && ikasle_gainditu_len < max_gaindituak) {
		ikaslea = g.ikasleak[ikasle_idx];
		ikasle_nota = IKASLEA_nota_finala(ikaslea);

		if (ikasle_nota >= GELA_GAINDITZEKO_NOTA) {
			gaindituak[ikasle_gainditu_len] = ikaslea;
			++ikasle_gainditu_len;
		}
		++ikasle_idx;
	}

	return ikasle_gainditu_len;
}

GELA GELA_ikaslea_gehitu(GELA g, IKASLEA ik)
{
	if (g.ikasle_kop < GELA_MAX_IKASLEAK) {
		g.ikasleak[g.ikasle_kop] = ik;
		++g.ikasle_kop;
	}

	return g;
}
