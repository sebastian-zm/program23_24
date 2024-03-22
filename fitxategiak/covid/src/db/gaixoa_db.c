#include <stdio.h>
#include "gaixoa.h"
#include "gaixoa_db.h"

GAIXOA GAIXOA_DB_gaixoa_kargatu(FILE* gaixoak, FILE* emaitzak)
{
	int ondo;
	int chr; // fgetc() int bat bueltatzen du, EOF bueltatu ahal izateko.
	GAIXOA gaixoa;

	chr = fgetc(emaitzak);

	ondo = chr == 'z' || chr == 'n' || chr == 'p';

	if (ondo) {
		gaixoa.emaitza = chr;

		ondo = ondo && 5 == fscanf(gaixoak, "%d %s %s %d %s\n", &gaixoa.id, gaixoa.izena, gaixoa.abizena, &gaixoa.adina, gaixoa.herria);
	}

	if (!ondo) {
		gaixoa.id = -1;
	}

	return gaixoa;
}

int GAIXOA_DB_gaixoa_lotuta_idatzi(FILE* lotura, GAIXOA gaixoa)
{
	return 0 > fprintf(lotura, "%d,%c\n", gaixoa.id, gaixoa.emaitza);
}
