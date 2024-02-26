


#include <stdio.h>
#include <string.h>

#include "orokorrak.h"

#include "diska.h"
#include "diskak.h"
#include "stocka.h"

#include "erabiltzaileak.h"

int ERABILTZAILEAK_sortu_(ERABILTZAILEA erabil[], int kop) {
	
	strcpy(erabil[0].izena, "admin");
	strcpy(erabil[0].password, "qwerty");
	erabil[0].mota = ADMIN;
	erabil[0].dirua = 0;
	//erabil[0].erosketak.zenbat = 0;
	kop++;

	ERABILTZAILEA aux;
	strcpy(aux.izena, "joseba");
	strcpy(aux.password, "123");
	aux.mota = EROSLE;
	aux.dirua = 40;
	aux.erosketak.zenbat = 0;
	erabil[1] = aux;
	kop++;

	strcpy(erabil[2].izena, "irati");
	strcpy(erabil[2].password, "321");
	erabil[2].mota = EROSLE;
	erabil[2].dirua = 25;
	erabil[2].erosketak.zenbat = 0;
	kop++;
	//return 3;
	return kop;
}

int ERABIL_aurkitu(char username[], ERABILTZAILEA erabil[], int kop) {
	int ret = -1;
	int i = 0;
	int aurkitua = FALSE;
	
	while (i < kop && aurkitua == FALSE) {
		if (  strcmp(erabil[i].izena , username) == 0 )  {
			aurkitua = TRUE;
		}else {
			i++;
		}
	}
	if (aurkitua == TRUE) {
		ret = i;
	}
	return ret;
}

MOTA ERABIL_login(char username[], char password[], ERABILTZAILEA erabil[], int kop) {
	int ret = -1;
	int i = 0;
	int aurkitua = FALSE;
	//ERABILTZAILEA user;

	if (strlen(username) > 0 && strlen(password) > 0) {
		while (i < kop && aurkitua == FALSE) {
			if ((strcmp(erabil[i].izena, username) == 0) && ( strcmp(erabil[i].password, password)==0)) {
				aurkitua = TRUE;
			}
			else {
				i++;
			}
		}
		if (aurkitua == TRUE) {
			ret = erabil[i].mota;

		}
	}

	
	return ret;
	//return user;
}

int ERABILTZAILEA_gehituErosketa(ERABILTZAILEA erabil[], int erabilIndex, DISKA_MOTA diska, int zenbat) {
	int ret = FALSE;
	int totala = 0;
	totala = erabil[erabilIndex].erosketak.zenbat;
	if (totala < MAX) {
		erabil[erabilIndex].erosketak.diskak[totala] = diska;
		erabil[erabilIndex].erosketak.diskak[totala].stock = zenbat;
		erabil[erabilIndex].erosketak.zenbat++;
		ret = TRUE;
	}
	return ret;

}

float ERABILTZAILEA_erosketakoPrezioa(ERABILTZAILEA erabiltzaileak[], int erabilIndex) {
	ERABILTZAILEA erabilAux;
	float totala = 0;
	float n = 0;
	float prezioa = 0;
	int  i = 0;
	for (i = 0; i < erabiltzaileak[erabilIndex].erosketak.zenbat; i++) {
		erabilAux = erabiltzaileak[erabilIndex];
		prezioa = erabilAux.erosketak.diskak[i].prezioa;
		n = erabilAux.erosketak.diskak[i].stock;
		//prezioa = erabiltzaileak[erabilIndex].erosketak.diskak[i].prezioa;
		//n = erabiltzaileak[erabilIndex].erosketak.diskak[i].stock;
		totala = totala + (n*prezioa);
	}

	return totala;
}
