/*
 * ikasle.h
 *
 *  Created on: 2024(e)ko api. 15(a)
 *      Author: joseba
 */

#ifndef IKASLE_H_
#define IKASLE_H_

#define MAX_ERABIL 10
#define MAX_STR 64

typedef struct {
	char emaila[MAX_STR];
	char izena[MAX_STR];
	char abizena[MAX_STR];

} ERABILTZAILEA;

//funtzio minimoak
ERABILTZAILEA eskatuHelbidea();
void eskatuHainbatHelbidev2(ERABILTZAILEA * erabiltzaileak, int *kop);
void ateraIzena(ERABILTZAILEA * erak);
void ateraAbizena(ERABILTZAILEA * erak);
void pantailaratu(ERABILTZAILEA * erak, int kop);
//funztio extrak

void bistaratuErabiltzailea(ERABILTZAILEA erabil);
void bistaratuErabiltzaileaPTRgaz(ERABILTZAILEA * ptr_erabil);

#endif				/* IKASLE_H_ */
