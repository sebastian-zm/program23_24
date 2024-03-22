/*
 * ikasleak.h
 *
 *  Created on: 2024(e)ko mar. 14(a)
 *      Author: joseba
 */

#ifndef IKASLEAK_H_
#define IKASLEAK_H_

#define MAX_IKASLE 10
#define MAX_STR 64

typedef struct s_ikasle
{
	int kp1;
	int kp2;
	char izena[10];
	char abizena[30];
} IKASLE;


int ikasleak_sortu_eta_sartu_arraian(int zenbat , IKASLE ikasleak[]);
IKASLE sortu_ikasle_bat();

void ikasleak_idatzi_testu_fitxategia(IKASLE ikasleak[], int kop);
void idatzi_ikasle_bat(FILE* fitx, IKASLE ikasleak);


void ikasleak_idatzi_testu_bitarrean(IKASLE ikasleak[], int kop);
void ikasleak_idatzi_testu_bitarrean_banan_banan(IKASLE ikasleak[], int kop);

void ikasleak_erakutsi(IKASLE ikasleak[], int kop);
void ikasleak_idatzi_testu_fitxategia_fp(IKASLE idazteko[], int kop, FILE* fp);
int ikasleak_irakurri_bitarrean(IKASLE ikasleak[]);
int ikasleak_irakurri_bitarrean_banan_banan(IKASLE ikasleak[]);

#endif /* IKASLEAK_H_ */
