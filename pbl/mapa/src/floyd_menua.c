#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>		//malloc
#include <string.h>
#include <math.h>
#include "floyd.h"
#include "floyd_view.h"
int main(void)
{
	FILE *fitx = 0;
	GRAFOA *ptr_hasiera;
	float **distantzia;
	int **matrize_laguntzailea;
	char fitx_izena[MAX_STR];
	int kopurua = 0;
	irakurri_fitx_izena(fitx_izena);
	fitx = fitx_ireki(fitx_izena);
	ptr_hasiera = irakurri_eta_buruan_sartu(fitx, &kopurua);
	ertzak_kargatu(ptr_hasiera, fitx);
	matrize_laguntzailea = matrize_laguntzailea_hasieratu(kopurua);
	distantzia = distantzia_matrizea_hasieratu(kopurua);
	distantzia_hasieratu(ptr_hasiera, distantzia);
	floyd_warsall(matrize_laguntzailea, distantzia, kopurua);


	do {
		bilatu_ibilbide_motzena(ptr_hasiera, distantzia, matrize_laguntzailea);
	} while (jarraitu_nahi());
}
