/*
 * ikasle.c
 *
 *  Created on: 2024(e)ko mar. 1(a)
 *      Author: joseba
 */

#include <stdio.h>
#include "ikasle.h"

IKASLE irakurri_fitxategitik_ikasle_bat(FILE * fitx_tuberia)
{
	IKASLE ikasle_berria;
	int egoera = 0;

	egoera = fscanf(fitx_tuberia, "%i %s %s %f %f %f %f\n", &ikasle_berria.ID,
			ikasle_berria.izena,
			ikasle_berria.abizena,
			&ikasle_berria.notak.KP[0],
			&ikasle_berria.notak.KP[1], &ikasle_berria.notak.KP[2], &ikasle_berria.notak.KP[3]);
	//ez bada ondo irakurri ID -1 jartzen dugu , gero kanpoan jakiteko gaizki irakurri dela ikaslea eta horrea
	//ez dogu erabiliko edo arrayan sartuko
	if (egoera != 7) {
		printf("Ez da ikaslea ondo irakurri edo fitxagieraen bukaera da.\n");
		ikasle_berria.ID = -1;
	}
	return ikasle_berria;

}

int irakurri_fitxategitik_ikasleak_fscanf(IKASLE ikasleak[], int kop, char fitxIzena[])
{
	FILE *fitx = 0;
	int egoera = 0;
	int i = 0;
	i = kop;		//sartu datu berriak , azken posiziotik aurrera
	fitx = fopen(fitxIzena, "r");
	if (fitx) {

		do {

			IKASLE berria;
			berria = irakurri_fitxategitik_ikasle_bat(fitx);
			egoera = berria.ID;
			if (egoera > 0) {	//hemen ere egoera == 7 egin daiteke zuzenago izateko
				ikasleak[i] = berria;
				i++;
				printf("%d. lerroa irakurrita datu egokiekin.\n", i);
			}

		} while (egoera > 0);
		fclose(fitx);
		//return i;
	} else {
		printf("Errorea fitxategia zabalzterakoan");
		i = -1;
		//return -1;
	}
	return i;
}

int irakurri_fitxategitik_ikasleak(IKASLE ikasleak[], int kop, char fitxIzena[])
{
	char lerroa[128];
	FILE *fitx = 0;
	int egoera = 0;
	int i = 0;
	i = kop;		//sartu datu berriak , azken posiziotik aurrera
	fitx = fopen(fitxIzena, "r");
	if (fitx) {

		do {
			//1- irakurri fitxategitik lerro bat
			fgets(lerroa, 128, fitx);
			sscanf(lerroa, "%i %s %s %f %f %f %f\n", &ikasleak[i].ID,
			       ikasleak[i].izena,
			       ikasleak[i].abizena,
			       &ikasleak[i].notak.KP[0],
			       &ikasleak[i].notak.KP[1], &ikasleak[i].notak.KP[2], &ikasleak[i].notak.KP[3]);
			i++;
			egoera = feof(fitx);
			printf("%d. lerroa irakurrita.\n", i);
		} while (egoera == 0);
		fclose(fitx);
		//return i;
	} else {
		printf("Errorea fitxategia zabalzterakoan");
		i = -1;
		//return -1;
	}
	return i;
}

void bistaratu_ikasleak(IKASLE ikasleak[], int kop)
{
	int i = 0;
	for (i = 0; i < kop; i++) {
		bistaratu_ikaslea(ikasleak[i]);
	}

}

void bistaratu_ikaslea(IKASLE ikaslea)
{
	int i = 0;
	printf("-----------------------%d. ikaslea------------------------\n", ikaslea.ID);
	printf("IZENA: %s\n", ikaslea.izena);
	printf("ABIZENA: %s\n", ikaslea.abizena);
	printf("Notak:\n");
	for (i = 0; i < 4; i++) {
		printf("Nota%i:%f ", i + 1, ikaslea.notak.KP[i]);
	}
	printf("\n");

}
