#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "user.h"
#include "ibilbidea.h"
#include "menua.h"
#include "puntua_view.h"
#include "ibilbidea_view.h"

void IBILBIDEA_erakutsi(IBILBIDEA i)
{
	printf("Ibilbidea:\n");
	printf("id: %i\n", i.id);
	printf("izena: %s\n", i.izena);
	printf("herria: %s\n", i.herria);
	PUNTUAK_erakutsi(i.puntuak);
}

int IBILBIDEA_aurkitu(IBILBIDEAK ibik)
{
	int id;
	int idx;
	char buffer[IBILBIDEA_MAX_STR + 1];

	printf("Eman ibilbideraren id: ");

	fgets(buffer, IBILBIDEA_MAX_STR + 1, stdin);
	sscanf(buffer, "%i", &id);

	idx = IBILBIDEAK_aurkitu_id(ibik, id);

	if (idx < 0) {
		printf("Ez dago id hori duen ibilbiderik.\n");
	}

	return idx;
}

IBILBIDEAK IBILBIDEA_eskatu_eta_gehitu(IBILBIDEAK ibik, USER user)
{
	IBILBIDEA berria;
	char buffer[IBILBIDEA_MAX_STR + 1];
	PUNTUA curr_puntua;
	int puntuak_len;
	bool amaitu_da;

	berria.id = IBILBIDEA_id_sortu(ibik);
	berria.user_id = user.id;
	
	printf("Eman ibilbidearen izena: ");
	fgets(berria.izena, IBILBIDEA_MAX_STR + 1, stdin);
	berria.izena[strlen(berria.izena) - 1] = '\0';
	
	printf("Eman ibilbidearen herria: ");
	fgets(berria.herria, IBILBIDEA_MAX_STR + 1, stdin);
	berria.herria[strlen(berria.herria) - 1] = '\0';

	printf("Orain puntuak banan banan sartuko dituzu.\n");
	berria.puntuak = PUNTUAK_create();
	do {
		puntuak_len = PUNTUAK_length(berria.puntuak);

		printf("Eman %i. puntuaren x: ", puntuak_len - 1);
		fgets(buffer, IBILBIDEA_MAX_STR + 1, stdin);
		sscanf(buffer, "%lf", &curr_puntua.x);

		printf("Eman %i. puntuaren y: ", puntuak_len - 1);
		fgets(buffer, IBILBIDEA_MAX_STR + 1, stdin);
		sscanf(buffer, "%lf", &curr_puntua.y);

		berria.puntuak = PUNTUAK_add(berria.puntuak, curr_puntua);
		
		printf("Amaitu duzu? [b/E] ");
		fgets(buffer, IBILBIDEA_MAX_STR + 1, stdin);

		amaitu_da = buffer[0] == 'b' || buffer[0] == 'B';
	} while (!amaitu_da);

	ibik = IBILBIDEAK_add(ibik, berria);

	return ibik;
}

void IBILBIDEAK_erabiltzailearenak_ikusi(IBILBIDEAK ibik, USER user)
{
	int len = IBILBIDEAK_length(ibik);
	int i;

	printf("%s erabiltzailearen ibilbideak:\n", user.name);

	for (i = 0; i < len; ++i) {
		IBILBIDEA ibi = IBILBIDEAK_get(ibik, i);
		if (IBILBIDEA_belongs_to_user(ibi, user)) {
			IBILBIDEA_erakutsi(ibi);
		}
	}
}

void IBILBIDEAK_ikusi(IBILBIDEAK ibik)
{
	int len = IBILBIDEAK_length(ibik);
	int i;

	printf("Ibilbide guztiak:\n");

	for (i = 0; i < len; ++i) {
		IBILBIDEA ibi = IBILBIDEAK_get(ibik, i);
		IBILBIDEA_erakutsi(ibi);
	}
}

IBILBIDEAK IBILBIDEAK_ezabatzeko_eskatu(IBILBIDEAK ibik, USER user)
{
	int idx = IBILBIDEA_aurkitu(ibik);
	IBILBIDEA ibi;
	if (idx >= 0) {
		ibi = IBILBIDEAK_get(ibik, idx);
		if (ibi.user_id == user.id) {
			ibik = IBILBIDEAK_remove(ibik, idx);
		} else {
			printf("Errorea: ibilbide hori ez da zurea.\n");
		}
	} else {
		printf("Errorea: ez da ibilbidea aurkitu.\n");
	}
	return ibik;
}
