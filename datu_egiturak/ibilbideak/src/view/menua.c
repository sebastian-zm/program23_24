#include <stdio.h>
#include <stdbool.h>
#include "ibilbidea.h"
#include "ibilbidea_view.h"
#include "user.h"
#include "menua.h"

#define MENUA_MAX_STR 127

int MENUA_aukera_eskatu()
{
	char buffer[MENUA_MAX_STR + 1];
	int aukera = -1;

	printf("-----MENUA-----\n");
	printf("0. Irten\n");
	printf("1. Nire ibilbideak ikusi\n");
	printf("2. Ibilbideak ikusi\n");
	printf("3. Nire ibilbidea sortu\n");
	//printf("4. Nire ibilbidea aldatu\n");
	printf("5. Nire ibilbidea ezabatu\n");
	printf("Eman zure aukera: ");

	fgets(buffer, MENUA_MAX_STR + 1, stdin);
	sscanf(buffer, "%i", &aukera);

	return aukera;
}

int MENUA_aukera_ona_konprobatu(int aukera)
{
	return aukera >= 0 && aukera <= 5;
}

int MENUA_aukera_ona_konprobatu_mezuarekin(int aukera)
{
	bool ona = MENUA_aukera_ona_konprobatu(aukera);
	if (!ona) {
		printf("Aukera desegokia. Saiatu berriro.\n");
	}

	return ona;
}

int MENUA_aukera_zuzena_eskatu()
{
	int aukera;
	do {
		aukera = MENUA_aukera_eskatu();
	} while (!MENUA_aukera_ona_konprobatu_mezuarekin(aukera));

	return aukera;
}


IBILBIDEAK MENUA_menua(IBILBIDEAK ibik, USER user)
{
	int aukera;

	while ((aukera = MENUA_aukera_zuzena_eskatu())) {
		switch (aukera) {
			case 1:
				IBILBIDEAK_erabiltzailearenak_ikusi(ibik, user);
				break;
			case 2:
				IBILBIDEAK_ikusi(ibik);
				break;
			case 3:
				ibik = IBILBIDEA_eskatu_eta_gehitu(ibik, user);
				break;
			case 5:
				ibik = IBILBIDEAK_ezabatzeko_eskatu(ibik, user);
				break;
		}
	}

	return ibik;
}
