/*
	int id;
	float prezioa;
	int stock;
	char izenburua[MAX_STR];
	char autor[MAX_STR];//taldea , solista
	int estiloa;
	char data[MAX_STR];
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "orokorrak.h"

#include "diska.h"
#include "diskak.h"



void DISKAK_bistaratu_estiloka(DISKA_MOTA diskak[], int zenbat, ESTILOAK estiloa) {
	int i = 0;
	system("clear");
	printf("------------------------------------------------------------------\n");
	printf("------------");
	DISKA_bistaratuEstiloa(estiloa);
	printf("------------------------------------------------------------------\n");
	
	for (i = 0; i < zenbat; i++) {
		if (diskak[i].estiloa == estiloa){
				DISKA_bistaratuBat(diskak[i]);
		}
		

	}
}
void DISKAK_bistaratuDanak(DISKA_MOTA diskak[], int zenbat) {
	//BISTARATU ARRAYA
	int i = 0;
	printf("[INFO]Diska danak bistaratzen\n");
	for (i = 0; i < zenbat; i++) {
		/*printf("%.dika = %s %s %d€ %d stock\n", diskak[i].id,
												diskak[i].izenburua
												....
												....
												....);*/
		DISKA_bistaratuBat(diskak[i]);
	}

}



int  DISKAK_diskaBatSartu(DISKA_MOTA diska, DISKA_MOTA stocka[], int zenbat) {
		if (zenbat < 10) {
			stocka[zenbat] = diska;
			zenbat++;
		}
		else {
			printf("Ezin da sartu diska stocka (Limitean gauz).\n");
		}
		return zenbat;
}

int	 DISKAK_sortu(DISKA_MOTA diskak[]) {
	printf("stocka-sortzen\n");

	diskak[0].id = 1;
	diskak[0].prezioa = 11;
	strcpy(diskak[0].autor, "Robert Johnson");
	strcpy(diskak[0].izenburua, "King of Delta Blues");
	diskak[0].estiloa = BLUES;
	strcpy(diskak[0].data, "1936/06/06");


	diskak[1].id = 2;
	diskak[1].prezioa = 12;
	strcpy(diskak[1].autor, "Jimi Hendrix");
	strcpy(diskak[1].izenburua, "Are you experience?");
	diskak[1].estiloa = ROCK;
	strcpy(diskak[1].data, "1967/05/12");

	return 2;
}


int  DISKAK_bilatuDiska(DISKA_MOTA diskak[], int kop, char izena[]) {
	int i = 0;
	int aurkitua = FALSE;
	int ret;
	ret = -1;

	while (i < kop && aurkitua == FALSE) {
		if (strcmp(diskak[i].izenburua, izena) == 0) {
			aurkitua = TRUE;
		}
		else {
			i++;
		}
	}
	if (aurkitua == TRUE) {
		ret = i;
	}
	return ret;
}





int DISKAK_ezabatuDiska(DISKA_MOTA diskak[], int pos, int zenbat) {
	int i = 0;
	if ((pos >= 0) && (pos < zenbat)) {
		//ezabatzeko soilik elementuak posizio baten mugitzeko ditugu eta zenbat--
		for (i = pos; i < zenbat - 1; i++) {
			diskak[i] = diskak[i + 1];
		}
		zenbat--;
	}

	return zenbat;
}
