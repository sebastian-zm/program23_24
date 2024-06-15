#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct {
	int saiakerak;
	char hitz_ezkutua[32];
	char hizkiak[32];
	int letra_kopurua;
	int egoera;
} DATU_EGITURA;

void saiatu(DATU_EGITURA *eg);
void inizializatu(DATU_EGITURA *eg);
void ezkutua_bistaratu(DATU_EGITURA *eg);
void hizkia_galdetu(DATU_EGITURA *eg);
void saiakera(DATU_EGITURA *eg, char hizkia);
void irabazi_galdu(DATU_EGITURA *eg);

int main()
{
	DATU_EGITURA eg;
	inizializatu(&eg);
	saiatu(&eg);
}

void inizializatu(DATU_EGITURA *eg)
{
	eg->saiakerak = 9;
	strcpy(eg->hitz_ezkutua, "zuhaitza");
	eg->letra_kopurua = strlen(eg->hitz_ezkutua);
}

