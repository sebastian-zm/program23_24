#include <stdio.h>
#include <stdbool.h>
#include "ikaslea.h"
#include "gela.h"
#include "gela_view.h"

int GELA_VIEW_ikaslea_bilatu(GELA g)
{
	int id = -1, idx = -1;
	char buffer[GELA_MAX_STR];

	printf("Eman ikaslearen id-a: ");
	fgets(buffer, GELA_MAX_STR, stdin);
	sscanf(buffer, "%i", &id);
	idx = GELA_ikaslea_aurkitu(g, id);

	return idx;
}

GELA GELA_VIEW_ikaslea_aldatu(GELA g, int idx)
{
	IKASLEA ik = g.ikasleak[idx];
	char buffer[GELA_MAX_STR];
	bool bukatu;
	ik.kp_kop = 0;

	printf("Eman ikaslearen izena: ");
	fgets(ik.izena, IKASLEA_MAX_STR, stdin);

	
	bukatu = false;
	ik.kp_kop = 0;
	while (ik.kp_kop < IKASLEA_KP_KOP && !bukatu) {
		printf("Eman kp%i nota (E bukatzeko): ", ik.kp_kop + 1);
		fgets(buffer, GELA_MAX_STR, stdin);
		if (buffer[0] == 'E' || buffer[0] == 'e') {
			bukatu = true;
		} else {
			sscanf(buffer, "%lf", &ik.kp[ik.kp_kop]);
			++ik.kp_kop;
		}
	}

	g.ikasleak[idx] = ik;

	return g;
}

GELA GELA_VIEW_ikaslea_jaso(GELA g)
{
	IKASLEA ik;
	char buffer[GELA_MAX_STR];
	bool bukatu;
	ik.kp_kop = 0;
	ik.id = GELA_id_sortu(g);

	printf("Eman ikaslearen izena: ");
	fgets(ik.izena, IKASLEA_MAX_STR, stdin);

	
	bukatu = false;
	ik.kp_kop = 0;
	while (ik.kp_kop < IKASLEA_KP_KOP && !bukatu) {
		printf("Eman kp%i nota (E bukatzeko): ", ik.kp_kop + 1);
		fgets(buffer, GELA_MAX_STR, stdin);
		if (buffer[0] == 'E' || buffer[0] == 'e') {
			bukatu = true;
		} else {
			sscanf(buffer, "%lf", &ik.kp[ik.kp_kop]);
			++ik.kp_kop;
		}
	}

	g = GELA_ikaslea_gehitu(g, ik);

	printf("Id: %d\n", ik.id);
	return g;
}
