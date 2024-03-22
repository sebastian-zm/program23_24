#include <stdio.h>
#include "elur_datu.h"
#include "elur_datu_db.h"

ELUR_DATUAK ELUR_DATU_DB_datua_jaso(FILE * fd, ELUR_DATUAK datuak)
{
	ELUR_DATU datu;
	int fscanf_return;

	datu.id = ELUR_DATUAK_id_sortu(datuak);
	fscanf_return = fscanf(fd, "herria: %[^,], elurra: %lf\n", datu.herria, &datu.elurra);

	if (fscanf_return == 2) {
		datuak = ELUR_DATUAK_add(datuak, datu);
	}

	return datuak;
}

ELUR_DATUAK ELUR_DATU_DB_datuak_jaso(FILE * fd, ELUR_DATUAK datuak)
{
	int prev_len;

	do {
		prev_len = datuak.len;
		datuak = ELUR_DATU_DB_datua_jaso(fd, datuak);
	} while (prev_len != datuak.len);

	return datuak;
}
