#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>		//malloc
#include <string.h>
#include "floyd.h"
#include "floyd_view.h"
#include <math.h>
GRAFOA *irakurri_eta_buruan_sartu(FILE * fitx, int *kopurua)
{
	GRAFOA *ptr_hasiera = NULL;
	printf("========= DIJSTRA KODIGOA=========\n");
	ptr_hasiera = irakurri_fitxategitik_erpinak(fitx, kopurua);
	return ptr_hasiera;
}

void irakurri_fitx_izena(char fitx_izena[])
{
	printf("Sartu fitxategiaren izena .txt barne\n");
	fgets(fitx_izena, 128, stdin);
	fitx_izena[strlen(fitx_izena) - 1] = '\0';
} FILE *fitx_ireki(char fitx_izena[])
{
	FILE *fitx = 0;
	fitx = fopen(fitx_izena, "r");
	if (fitx) {
		printf("%s fitxategia ondo irekia\n\n", fitx_izena);
	}

	else {
		printf("[ERROREA] notak.txt ezin izan da zabaldu\n");
	}
	return fitx;
}

GRAFOA *irakurri_fitxategitik_erpinak(FILE * fitx, int *kopurua)
{
	GRAFOA *ptr_berria = NULL;
	GRAFOA *ptr_hasiera = NULL;
	int zenbat_irakurri = 0;
	*kopurua = 0;

	//4. fitxategiarekin lan egin

	do {

		// 2. bistaratu lerroa pantailan
		ptr_berria = sortu_nodo_bat(&zenbat_irakurri, fitx);
		if (zenbat_irakurri == 4) {
			ptr_hasiera = sartu_buruan(ptr_hasiera, ptr_berria);
			++*kopurua;
		}
	} while (zenbat_irakurri > 0);
	if (fitx) {
		return ptr_hasiera;
	}

	else {
		return NULL;
	}
}

GRAFOA *sartu_buruan(GRAFOA * ptr_hasiera, GRAFOA * ptr_berria)
{
	if (ptr_berria != NULL) {
		ptr_berria->ptr_hurrengoa = ptr_hasiera;
		ptr_hasiera = ptr_berria;
	}
	return ptr_hasiera;	//return 0;
}

GRAFOA_ERTZA_NODOA *sartu_buruan_ertza(GRAFOA_ERTZA_NODOA * ptr_hasiera, GRAFOA_ERTZA_NODOA * ptr_berria)
{
	if (ptr_berria != NULL) {
		ptr_berria->ptr_hurrengoa = ptr_hasiera;
		ptr_hasiera = ptr_berria;
	}
	return ptr_hasiera;	//return 0;
}

GRAFOA *sortu_nodo_bat(int *zenbat_irakurri, FILE * fitx)
{
	GRAFOA *ptr_elementua = NULL;
	char lerroa[128];
	ptr_elementua = malloc(sizeof(GRAFOA));
	ptr_elementua->elementua.ertzak = NULL;

	//
	fgets(lerroa, MAX_STR, fitx);
	*zenbat_irakurri =
	    sscanf(lerroa, "%d %s %d %d", &ptr_elementua->elementua.id, ptr_elementua->elementua.izena,
		   &ptr_elementua->elementua.x, &ptr_elementua->elementua.y);
	return ptr_elementua;
}

GRAFOA_ERTZA_NODOA *sortu_nodo_bat_ertza(int *zenbat_irakurri, char izena[], GRAFOA * ptr_hasiera, FILE * fitx)
{
	GRAFOA_ERTZA_NODOA *ptr_elementua = NULL;
	char str[MAX_STR];
	char lerroa[MAX_STR];
	char *fgets_ret;
	ptr_elementua = malloc(sizeof(GRAFOA_ERTZA_NODOA));
	fgets_ret = fgets(lerroa, MAX_STR, fitx);
	if (fgets_ret) {
		*zenbat_irakurri = sscanf(lerroa, "%s %f %s", izena, &ptr_elementua->elementua.pisua, str);
		if (*zenbat_irakurri == 3) {
			ptr_elementua->elementua.nora = aukritu_erpina(str, ptr_hasiera);
		}
	} else {
		*zenbat_irakurri = 0;
	}
	return ptr_elementua;
}

void ertzak_kargatu(GRAFOA * ptr_hasiera, FILE * fitx)
{
	char izena[GRAFOA_MAX_IZENA];
	int zenbat_irakurri;
	GRAFOA_ERTZA_NODOA *ptr_berria_ertza = NULL;
	GRAFOA_ERPINA *ptr_erpina_hasiera = NULL;

	do {

		//1. irakurri lerro bat
		// 2. bistaratu lerroa pantailan
		ptr_berria_ertza = sortu_nodo_bat_ertza(&zenbat_irakurri, izena, ptr_hasiera, fitx);
		if (zenbat_irakurri == 3) {
			ptr_erpina_hasiera = aukritu_erpina(izena, ptr_hasiera);
			ptr_erpina_hasiera->ertzak = sartu_buruan_ertza(ptr_erpina_hasiera->ertzak, ptr_berria_ertza);
		}
	} while (zenbat_irakurri == 3);
}

GRAFOA_ERPINA *aukritu_erpina(char izena[], GRAFOA * ptr_hasiera)
{
	int egoera;
	GRAFOA_ERPINA *erpina = NULL;
	while (ptr_hasiera != NULL && erpina == NULL) {
		egoera = strcmp(ptr_hasiera->elementua.izena, izena);
		if (egoera == 0) {
			erpina = &ptr_hasiera->elementua;
		}

		else {
			ptr_hasiera = ptr_hasiera->ptr_hurrengoa;
		}
	}
	return erpina;
}

GRAFOA_ERPINA *aukritu_erpina_id(int id, GRAFOA * ptr_hasiera)
{
	GRAFOA_ERPINA *erpina = NULL;
	while (ptr_hasiera != NULL && erpina == NULL) {
		if (ptr_hasiera->elementua.id == id) {
			erpina = &ptr_hasiera->elementua;
		}

		else {
			ptr_hasiera = ptr_hasiera->ptr_hurrengoa;
		}
	}
	return erpina;
}

void bilatu_ibilbide_motzena(GRAFOA * ptr_hasiera, float **distantzia, int **matrize_laguntzailea)
{
	GRAFOA_ERPINA *ptr_izena1;
	GRAFOA_ERPINA *ptr_izena2;
	char izena1[MAX_STR];
	char izena2[MAX_STR];
	eskatu_ibilbidea(izena1, izena2);
	ptr_izena1 = aukritu_erpina(izena1, ptr_hasiera);
	ptr_izena2 = aukritu_erpina(izena2, ptr_hasiera);
	IBILBIDEA *ibilbidea = malloc(sizeof(IBILBIDEA));
	ibilbidea->elementua = *ptr_izena1;
	ibilbidea->ptr_hurrengoa = malloc(sizeof(IBILBIDEA));
	ibilbidea->ptr_hurrengoa->elementua = *ptr_izena2;
	ibilbidea->ptr_hurrengoa->ptr_hurrengoa = NULL;
	printf("Distantzia: %f\n", distantzia[ptr_izena1->id][ptr_izena2->id]);
	bilatu_motzena(ptr_hasiera, ibilbidea, matrize_laguntzailea);
	FLOYD_VIEW_main(ptr_hasiera, ibilbidea);
}

void ikusi_ibilbidea(IBILBIDEA * ibilbidea)
{
	IBILBIDEA *hurrengoa = ibilbidea->ptr_hurrengoa;
	float angelua;
	bistaratu_bat(ibilbidea->elementua);
	printf("->");

	do {
		bistaratu_bat(hurrengoa->elementua);
		if (hurrengoa->ptr_hurrengoa != NULL) {
			printf("-> biratu ");
			angelua =
			    calcular_angulo(hurrengoa->elementua, ibilbidea->elementua,
					    hurrengoa->ptr_hurrengoa->elementua);
			printf("%f", angelua);
			printf("->");
		}
		ibilbidea = ibilbidea->ptr_hurrengoa;
		hurrengoa = ibilbidea->ptr_hurrengoa;
	} while (hurrengoa != NULL);
	printf("\n");
}

void bistaratu_bat(GRAFOA_ERPINA ibilbidea)
{
	printf("%s", ibilbidea.izena);
} void bilatu_motzena(GRAFOA * ptr_hasiera, IBILBIDEA * ibilbidea, int **matrize_laguntzailea)
{
	int i = ibilbidea->elementua.id;	// ptr_izena1
	int j = ibilbidea->ptr_hurrengoa->elementua.id;	// ptr_izena2
	if (matrize_laguntzailea[i][j] != j) {
		GRAFOA_ERPINA *erdikoa = aukritu_erpina_id(matrize_laguntzailea[i][j], ptr_hasiera);	// aurkitu ij-ren erpina 
		IBILBIDEA *erdia = malloc(sizeof(IBILBIDEA));
		erdia->elementua = *erdikoa;
		erdia->ptr_hurrengoa = ibilbidea->ptr_hurrengoa;	// erdin ipini erdia
		ibilbidea->ptr_hurrengoa = erdia;
		bilatu_motzena(ptr_hasiera, erdia, matrize_laguntzailea);
		bilatu_motzena(ptr_hasiera, ibilbidea, matrize_laguntzailea);
	}
}

void eskatu_ibilbidea(char izena1[], char izena2[])
{
	printf("Nodo hasiera\n");
	fgets(izena1, 128, stdin);
	izena1[strlen(izena1) - 1] = '\0';
	printf("Nodo amaiera\n");
	fgets(izena2, 128, stdin);
	izena2[strlen(izena2) - 1] = '\0';
} float **distantzia_matrizea_hasieratu(int kopurua)
{
	int i, j;
	float **distantziak = malloc(kopurua * sizeof(float *));

	// seria lo mismo si ponemos distantzia[i][j]
	for (i = 0; i < kopurua; ++i) {
		distantziak[i] = malloc(kopurua * sizeof(float));
		for (j = 0; j < kopurua; ++j) {
			if (i == j) {
				distantziak[i][j] = 0;
			}

			else {
				distantziak[i][j] = INFINITY;
			}
		}
	}
	return distantziak;
}

void distantzia_hasieratu(GRAFOA * ptr_hasiera, float **distantziak)
{
	GRAFOA_ERTZA_NODOA *ptr_ertzak_hasiera;
	while (ptr_hasiera != NULL) {	// ptr_hasiera.elememtnua.id --> kolumna erreferentia
		ptr_ertzak_hasiera = ptr_hasiera->elementua.ertzak;	// ptr_ertzak_hasiera->elementua.nora->id --> fila erreferentia
		while (ptr_ertzak_hasiera != NULL) {
			distantziak[ptr_hasiera->elementua.id][ptr_ertzak_hasiera->elementua.nora->id] =
			    ptr_ertzak_hasiera->elementua.pisua;
			printf("%f ", distantziak[ptr_hasiera->elementua.id][ptr_ertzak_hasiera->elementua.nora->id]);
			ptr_ertzak_hasiera = ptr_ertzak_hasiera->ptr_hurrengoa;
		}
		printf("\n");
		ptr_hasiera = ptr_hasiera->ptr_hurrengoa;
	}
}

void floyd_warsall(int **matrize_laguntzailea, float **distantziak, int kopurua)
{
	int k, j, i;
	for (k = 0; k < kopurua; k++) {
		printf("%d Aldia\n", k);
		for (i = 0; i < kopurua; i++) {
			for (j = 0; j < kopurua; j++) {
				if (distantziak[i][k] + distantziak[k][j] < distantziak[i][j]) {
					distantziak[i][j] = distantziak[i][k] + distantziak[k][j];
					matrize_laguntzailea[i][j] = k;
				}
				printf("%d ", matrize_laguntzailea[i][j]);
			}
			printf("\n");
		}
		printf("\n\n");
	}
}

int **matrize_laguntzailea_hasieratu(int kopurua)
{
	int **matrize_laguntzailea = malloc(kopurua * sizeof(int *));
	int z, t;
	for (t = 0; t < kopurua; t++) {	// fila 
		matrize_laguntzailea[t] = malloc(kopurua * sizeof(int));
		for (z = 0; z < kopurua; z++) {	// zutabe 
			matrize_laguntzailea[t][z] = z;
			printf("%d ", matrize_laguntzailea[t][z]);
		}
		printf("\n");
	}
	printf("\n");
	return matrize_laguntzailea;
}

int jarraitu_nahi()
{
	char str[MAX_STR];
	int ret;
	printf("Jarraitu nahi duzu? (B/e): ");
	fgets(str, MAX_STR, stdin);
	switch (*str) {
	case 'B':
	case 'b':
	case '\n':
		ret = 1;
		break;
	case 'e':
	case 'E':
		ret = 0;
		break;
	default:
		printf("Ez dizut ulertu. Saiatu berriro.\n");
		ret = jarraitu_nahi();
	}
	return ret;
}

void matrizea_askatu(float **matrizea, int kopurua)
{
	int i;
	for (i = 0; i < kopurua; ++i) {
		free(matrizea[i]);	//  liberar las filas de la matriz
	}
	free(matrizea);		// liberar la matriz grande
}

float calcular_angulo(GRAFOA_ERPINA punto1, GRAFOA_ERPINA punto2, GRAFOA_ERPINA punto3)
{

	// Calcular los vectores entre los puntos
	int vector1_x = punto1.x - punto2.x;
	int vector1_y = punto1.y - punto2.y;
	int vector2_x = punto1.x - punto3.x;
	int vector2_y = punto1.y - punto3.y;
	int vector3_x = punto2.x - punto3.x;
	int vector3_y = punto2.y - punto3.y;

	// Calcular el producto punto entre los vectores
	int producto_cruzado = vector1_x * vector2_y - vector1_y * vector2_x;

	// Calcular las magnitudes de los vectores
	float magnitud_cuadrada_vector1 = vector1_x * vector1_x + vector1_y * vector1_y;
	float magnitud_cuadrada_vector2 = vector2_x * vector2_x + vector2_y * vector2_y;
	float magnitud_cuadrada_vector3 = vector3_x * vector3_x + vector3_y * vector3_y;
	float magnitud_vector1 = sqrtf(magnitud_cuadrada_vector1);
	float magnitud_vector2 = sqrtf(magnitud_cuadrada_vector2);

	// Calcular el ángulo entre los vectores usando la fórmula del producto punto
	float coseno_theta =
	    (magnitud_cuadrada_vector1 + magnitud_cuadrada_vector2 -
	     magnitud_cuadrada_vector3) / (2 * magnitud_vector1 * magnitud_vector2);

	// Calcular el ángulo en radianes
	float angulo_radianes = acosf(coseno_theta);

	// Convertir el ángulo a grados
	float angulo_grados = 180.0f - angulo_radianes * (180.0f / PI);

	// Convertir en positivo / negativo
	angulo_grados = producto_cruzado > 0 ? angulo_grados : -angulo_grados;
	return angulo_grados;
}
