#include <stdio.h>
#include "kp1_helper.h"
#include "console_helper.h"
#include "gasolindegia.h"

KP1_HELPER_CREATE(
		GASOLINDEGIAK,
		GASOLINDEGIA,
		struct GASOLINDEGIA_s,
		(
			"GASOLINDEGIA: id: %d; izena: %s; kokapena: %s; konpainia: %s; egoera: %c; gasolina: (erosi: %f, saldu: %f, litro: %f); gasoila: (erosi: %f, saldu: %f, litro: %f);\n",
			ins.id,
			ins.izena,
			ins.kokapena,
			ins.konpainia,
			ins.egoera,
			ins.gasolina.erosi,
			ins.gasolina.saldu,
			ins.gasolina.litro,
			ins.gasoila.erosi,
			ins.gasoila.saldu,
			ins.gasoila.litro
		),
		(
			"%d %s %lf %lf %lf %lf %lf %lf\n",
			&ins.id,
			ins.izena,
			&ins.gasolina.erosi,
			&ins.gasolina.saldu,
			&ins.gasolina.litro,
			&ins.gasoila.erosi,
			&ins.gasoila.saldu,
			&ins.gasoila.litro
		)
)


double GASOLINDEGIAK_batazbeste_gasolina(GASOLINDEGIAK gasolindegiak)
{
	size_t i;
	double gasolina_prezioa = 0.0;
	for (i = 0; i < gasolindegiak.length; ++i) {
		gasolina_prezioa += gasolindegiak.data[i].gasolina.saldu;
	}

	return gasolina_prezioa / gasolindegiak.length;
}


double GASOLINDEGIAK_batazbeste_gasoila(GASOLINDEGIAK gasolindegiak)
{
	size_t i;
	double gasoila_prezioa = 0.0;
	for (i = 0; i < gasolindegiak.length; ++i) {
		gasoila_prezioa += gasolindegiak.data[i].gasoila.saldu;
	}

	return gasoila_prezioa / gasolindegiak.length;
}


void GASOLINDEGIAK_VIEW_batazbeste_saldu(FILE* fp, GASOLINDEGIAK gasolindegiak)
{
	double gasoila_prezioa = GASOLINDEGIAK_batazbeste_gasolina(gasolindegiak);
	double gasolina_prezioa = GASOLINDEGIAK_batazbeste_gasoila(gasolindegiak);

	fprintf(fp, "gasolinaren batazbestekoa %f\n", gasolina_prezioa);
	fprintf(fp, "gasoilaren batazbestekoa %f\n", gasoila_prezioa);
}


GASOLINDEGIA GASOLINDEGIA_VIEW_osatu(GASOLINDEGIA g)
{
	GASOLINDEGIA_print(stdout, g);
	CONSOLE_HELPER_string_eskatu(g.kokapena, KP1_HELPER_MAX_STR, "Eman aurreko gasolindegiaren kokapena: ");
	CONSOLE_HELPER_string_eskatu(g.konpainia, KP1_HELPER_MAX_STR, "Eman aurreko gasolindegiaren konpainia: ");

	g.egoera = GASOLINDEGIA_ZABALIK;
	CONSOLE_HELPER_itxaron("Sakatu return jarraitzeko...");
	return g;
}


GASOLINDEGIAK GASOLINDEGIAK_VIEW_osatu(GASOLINDEGIAK gasolindegiak)
{
	size_t i;
	GASOLINDEGIA g;
	for (i = 0; i < gasolindegiak.length; ++i) {
		g = GASOLINDEGIA_VIEW_osatu(gasolindegiak.data[i]);
		gasolindegiak.data[i] = g;
	}
	return gasolindegiak;
}


int GASOLINDEGIA_zabalik(void *g)
{
	GASOLINDEGIA *gas = (GASOLINDEGIA *) g;
	return gas->egoera == GASOLINDEGIA_ZABALIK;
}


GASOLINDEGIAK GASOLINDEGIAK_osatu_zabalik(FILE *fp, GASOLINDEGIAK gasolindegiak)
{
	size_t i;
	for (i = 0; i < gasolindegiak.length; ++i)
	{
		switch (fgetc(fp)) {
			case 'z':
				gasolindegiak.data[i].egoera = GASOLINDEGIA_ZABALIK;
				break;
			default:
				gasolindegiak.data[i].egoera = GASOLINDEGIA_ITXITA;
				break;
		}
	}
	return gasolindegiak;
}

int GASOLINDEGIAK_idz_aurkitu(int id, GASOLINDEGIAK gasolindegiak)
{
	size_t i = 0;

	while (i < gasolindegiak.length && gasolindegiak.data[i].id != id) {
		++i;
	}

	return i >= gasolindegiak.length ? -1 : (int) i;
}
