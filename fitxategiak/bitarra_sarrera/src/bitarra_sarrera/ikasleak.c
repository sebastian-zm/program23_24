/*
 * ikasleak.c
 *
 *  Created on: 2024(e)ko mar. 14(a)
 *      Author: joseba
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ikasleak.h"


int ikasleak_sortu_eta_sartu_arraian(int zenbat , IKASLE idazteko[]){
	int i = 0;


	for (i = 0; i < zenbat; i++)
	{
		idazteko[i]=sortu_ikasle_bat();
	}
	return i;
}

IKASLE sortu_ikasle_bat(){
	char str[MAX_STR];
	IKASLE idazteko;

	printf("Sartu ikaslearen izena:");
	fgets(idazteko.izena, 10, stdin);
	idazteko.izena[strlen(idazteko.izena) - 1] = '\0';
	printf("Sartu ikaslearen abizena:");
	fgets(idazteko.abizena, 30, stdin);
	idazteko.abizena[strlen(idazteko.abizena) - 1] = '\0';
	printf("Sartu lehen kontrol puntuko nota:");
	fgets(str, 4, stdin);
	sscanf(str, "%d", &idazteko.kp1);
	printf("Sartu 2. kontrol puntuko nota:");
	fgets(str, 4, stdin);
	sscanf(str, "%d", &idazteko.kp2);

	return idazteko;
}

void ikasleak_idatzi_testu_fitxategia(IKASLE idazteko[], int kop){
	FILE* fp;
	fp = fopen("ikasleak.txt", "wb");
	ikasleak_idatzi_testu_fitxategia_fp(idazteko, kop, fp);

	if (fp)fclose(fp);
}
void idatzi_ikasle_bat(FILE* fitx, IKASLE idazteko){
	if (fitx){
		fprintf(fitx, "%s\t%s\t%d\t%d\n", idazteko.izena, idazteko.abizena,
					idazteko.kp1, idazteko.kp2);
	}
}

void ikasleak_idatzi_testu_bitarrean(IKASLE ikasleak[], int kop)
{
	FILE* fp;
	char fitx[] = "ikasleak.bin";
	fp = fopen(fitx, "wb");

	if (fp) {
		fwrite(ikasleak, sizeof ikasleak[0], kop, fp);
	} else {
		fprintf(stderr, "[ERROREA] %s fitxategia ezin izan da zabaldu.", fitx);
	}
}

void ikasleak_idatzi_testu_bitarrean_banan_banan(IKASLE ikasleak[], int kop)
{
	FILE* fp;
	char fitx[] = "ikasleak_banan_banan.bin";
	int bytes = 0;
	fp = fopen(fitx, "wb");

	if (fp) {
		for (int i = 0; i < kop; ++i) {
			bytes += fwrite(&ikasleak[i], sizeof ikasleak[i], 1, fp) * sizeof ikasleak[i];
		}
	} else {
		fprintf(stderr, "[ERROREA] %s fitxategia ezin izan da zabaldu.", fitx);
	}
}



int ikasleak_irakurri_bitarrean_banan_banan(IKASLE ikasleak[])
{
	FILE* fp;
	char fitx[] = "ikasleak_banan_banan.bin";
	int kop = 0;
	fp = fopen(fitx, "wb");

	if (fp) {
		while (fread(&ikasleak[kop], sizeof ikasleak[kop], 1, fp)) {
			++kop;
		}
	} else {
		fprintf(stderr, "[ERROREA] %s fitxategia ezin izan da zabaldu.", fitx);
	}

	return kop;
}
int ikasleak_irakurri_bitarrean(IKASLE ikasleak[])
{
	FILE* fp;
	char fitx[] = "ikasleak.bin";
	int kop = 0;
	fp = fopen(fitx, "wb");

	if (fp) {
		kop = fread(ikasleak, sizeof ikasleak[0], MAX_IKASLE, fp);
	} else {
		fprintf(stderr, "[ERROREA] %s fitxategia ezin izan da zabaldu.", fitx);
	}

	return kop;
}

void ikasleak_idatzi_testu_fitxategia_fp(IKASLE idazteko[], int kop, FILE* fp)
{
	int i;
	if (fp){
		for (i = 0; i < kop; i++){
			idatzi_ikasle_bat(fp, idazteko[i]);
		}
	}
}
