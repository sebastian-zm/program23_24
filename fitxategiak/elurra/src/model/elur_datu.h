#ifndef ELUR_DATU_H
#define ELUR_DATU_H

#define ELUR_DATU_MAX_STR 63
#define ELUR_DATUAK_MAX 63

typedef struct ELUR_DATU_s {
	int id;
	char herria[ELUR_DATU_MAX_STR + 1];
	double elurra;		// zentimetrotan
} ELUR_DATU;

typedef struct ELUR_DATUAK_s {
	ELUR_DATU arr[ELUR_DATUAK_MAX];
	int len;
} ELUR_DATUAK;

int ELUR_DATUAK_idz_aurkitu(ELUR_DATUAK datuak, int id);
int ELUR_DATUAK_id_sortu(ELUR_DATUAK datuak);
ELUR_DATUAK ELUR_DATUAK_add(ELUR_DATUAK datuak, ELUR_DATU datu);

#endif
