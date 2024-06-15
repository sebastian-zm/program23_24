#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>//malloc

#include "menua.h"
#include "erroberak.h"
#include "mugimendu_aurrekonfig.h"
#include "orokorrak.h"


void mugimendu_aurrekonfig_programa() {
	int aukera1;

	do {
		printf("AUKERAK:\n 0)eskailera_eskuin\n 1)eskailera_ezker\n, 2)borobila\n");
		aukera1 = aukera();
		switch (aukera1) {


		case ESKAILERA_ESKUBI:
			printf("=========== Eskailera eskubiren programa =================\n");
			eskailera_eskubi_programa();

			break;
		case ESKAILERA_EZKER:
			printf("=========== Eskailera eskubiren programa =================\n");
			eskailera_ezker_programa();

			break;
		case BOROBIL:
			printf("=========== Eskailera eskubiren programa =================\n");
			borobil_programa();
			break;
		}

	} while (aukera1!=IRTEN_2);

}

void eskailera_eskubi_programa() {
	int aukera1;
	char fitx_izena[MAX_STR];
	char fitx1[MAX_STR]={"eskailera_eskubi_255.txt"};
	char fitx2[MAX_STR]={"eskailera_eskubi_100.txt"};

	ERPINAK* ptr_hasiera = NULL;

	printf("Zein abiaduratan egin nahi dezu? 1) 200 2) 100\n");
	aukera1 = aukera();
	abiadura_aukeratu(fitx1,fitx2,fitx_izena,aukera1);

	ptr_hasiera=mugimendua_gauzatu(fitx_izena, ptr_hasiera);

}



ERPINAK* mugimendua_gauzatu(char fitx_izena[], ERPINAK* ptr_hasiera) {
	FILE* fitx;

	fitx = fitx_ireki(fitx_izena);

	ptr_hasiera = irakurri_fitxategitik_erpinak(fitx, ptr_hasiera);
	while (ptr_hasiera != NULL) {
		mugimendua(ptr_hasiera->mugimendua, ptr_hasiera->mili_segunduak, ptr_hasiera->abiadura);
		ptr_hasiera = ptr_hasiera->ptr_hurrengoa;

	}
	return ptr_hasiera;
}

void eskailera_ezker_programa() {
	char fitx_izena[MAX_STR];
	char fitx1[MAX_STR]={"eskailera_ezker_255.txt"};
	char fitx2[MAX_STR]={"eskailera_ezker_100.txt"};
	int aukera1=0;
	ERPINAK* ptr_hasiera = NULL;

	printf("Zein abiaduratan egin nahi dezu? 1) 200 2) 100\n");
	aukera1 = aukera();
	abiadura_aukeratu(fitx1,fitx2,fitx_izena,aukera1);
	ptr_hasiera= mugimendua_gauzatu(fitx_izena, ptr_hasiera);

}

void aurrera(int duration_ms, int speed) {
	printf("FORWARD for %u ms with speed %u\n", duration_ms, speed);
	ERROBERA_aurrera(speed);

}

void atzera(int duration_ms, int speed) {
	printf("BACKWARD for %u ms with speed %u\n", duration_ms, speed);
	ERROBERA_atzera(speed);
}

void ezkerra(int duration_ms, int speed) {
	printf("LEFT for %u ms with speed %u\n", duration_ms, speed);
	ERROBERA_ezkerrera(speed);
}

void eskubi(int duration_ms, int speed) {
	printf("RIGHT for %u ms with speed %u\n", duration_ms, speed);
	ERROBERA_eskumara(speed);
}

void stop(int duration_ms, int speed) {
	printf("STOP for %u ms with speed %u\n", duration_ms, speed);
	ERROBERA_aurrera(0);
}

void hasieratu_gpio(){
	printf("GPIO hasieratzen...\n");

}
void mugimendua( char  mugimendu[], int denbora, int abiadura) {
	if (strcmp(mugimendu, "AURRERA") == 0) {
		aurrera(denbora, abiadura);
	}
	else if (strcmp(mugimendu, "BACKWARD") == 0) {
		atzera(denbora, abiadura);
	}
	else if (strcmp(mugimendu, "EZKERRERA") == 0) {
		ezkerra(denbora, abiadura);
	}
	else if (strcmp(mugimendu, "ESKUBI") == 0) {
		eskubi(denbora, abiadura);
	}
	else if (strcmp(mugimendu, "STOP") == 0) {
		stop(denbora, abiadura);
	}
}



ERPINAK* irakurri_fitxategitik_erpinak(FILE* fitx, ERPINAK* ptr_hasiera) {

	ERPINAK* ptr_berria = NULL;

	int kopurua=0;
	int zenbat_irakurri = 3;

	kopurua = 0;

	while (zenbat_irakurri == 3)
	{
		ptr_berria = sortu_nodo_bat(&zenbat_irakurri, fitx);
		if (ptr_berria!=NULL) {
			ptr_hasiera = sartu_bukaeran(ptr_hasiera, ptr_berria);
			++kopurua;
		}
	}
	if (fitx) {
		return ptr_hasiera;
	}
	else {
		return NULL;
	}
}


void borobil_programa() {
	char fitx_izena[MAX_STR] = { "borobila.txt" };
	ERPINAK* ptr_hasiera = NULL;

	ptr_hasiera = mugimendua_gauzatu(fitx_izena, ptr_hasiera);
}




ERPINAK* sortu_nodo_bat(int* zenbat_irakurri, FILE* fitx) {
		ERPINAK* ptr_elementua = malloc(sizeof(ERPINAK));
		if (!ptr_elementua) {
			*zenbat_irakurri = 0; // Indica que no se pudo asignar memoria
			return NULL;
		}

		ptr_elementua->ptr_hurrengoa = NULL;
		char lerroa[MAX_STR];

		if (fgets(lerroa, sizeof(lerroa), fitx)) {
			*zenbat_irakurri = sscanf(lerroa, "%s %u %d", ptr_elementua->mugimendua, &ptr_elementua->mili_segunduak, &ptr_elementua->abiadura);
		}
		else {
			*zenbat_irakurri = 0; // Indica que no se pudo leer la línea
			return NULL;
		}

		if (*zenbat_irakurri == 3) {
			return ptr_elementua;

		}
		else{
			return NULL;
		}
	}

ERPINAK* sartu_bukaeran(ERPINAK* ptr_hasiera, ERPINAK* ptr_berria) {
	ERPINAK* ptr_aux = NULL;
	ptr_aux = ptr_hasiera;

	if (ptr_hasiera == NULL) {
		//ZERRENDA HUTSIK DAGO
		ptr_hasiera = ptr_berria;
		ptr_berria->ptr_hurrengoa = NULL;
	}
	else {
		while (ptr_aux->ptr_hurrengoa != NULL) {
			ptr_aux = ptr_aux->ptr_hurrengoa;
		}
		ptr_aux->ptr_hurrengoa = ptr_berria;//azkenari berria kateatzen diogu
		ptr_berria->ptr_hurrengoa = NULL;//berria azkena bihurtzen dugu
	}
	return ptr_hasiera;
}

int aukera() {
	char str[MAX_STR];
	int aukera = 0;
	printf("aukera bat sartu");
	fgets(str, MAX_STR, stdin);
	sscanf(str, "%d", &aukera);

	return aukera;
}
void abiadura_aukeratu(char fitxategi_1[], char fitx_2[],char fitx_izena[], int aukera1){
	if (aukera1 == 1) {
		strcpy(fitx_izena, fitxategi_1);

	}
	else {
		strcpy(fitx_izena, fitx_2);
	}
}
