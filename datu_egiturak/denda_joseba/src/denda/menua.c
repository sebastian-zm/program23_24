
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "orokorrak.h"
#include "diska.h"
#include "diskak.h"
#include "stocka.h"
#include "erabiltzaileak.h"
#include "menua.h"


int  MENUA_admin(DISKA_MOTA stocka[], int zenbat) {
	//TODO
	int aukera = 0;
	char str[MAX_STR];
	printf("************************ADMIN MENUA*********\n");
	printf("|1 - Diska berri bat gehitu stocka			\n");
	printf("|2 - diska bat kendu stocketik				\n"); 
	printf("|3 - Diska bat modifikatu					\n");
	printf("|4 - Bistaratu								\n");
	printf("|	a) - Estilokaka							\n");
	printf("|	b) - Autoreka 							\n"); 
	printf("|	c) - Zigilua							\n");
	printf("|	d) - Datak erabiliz 					\n");
	printf("|	e) - Bat aurkitu	 					\n");
	printf("|0 - Irten 									\n");
	printf("********************************************\n");
	printf("Admin zer nahi dozu?\n");
	fgets(str ,		MAX_STR , stdin);
	//
	sscanf(str , "%i", &aukera);
	//								!!!!!!!!!!!!!!!!!!!!!!	
	zenbat = MENUA_ADMIN_exekutatu(aukera , stocka,  zenbat);
	itxoin();
	return zenbat;
}

int  MENUA_ADMIN_exekutatu(int aukera, DISKA_MOTA stocka[] , int zenbat) {
	//TODO
	garbitu();
	switch(aukera) {
		case SORTU_DISKA:
			zenbat = MENUA_sartuDiska(stocka, zenbat);
			break;
		case EZABATU_DISKA:
			printf("EZBAATU DISKA AUKERATU DUZU\n");
			zenbat = MENUA_ezabatuDiska(stocka, zenbat);
			break;
		case EGUNERATI_DISKA:
			zenbat = MENUA_eguneratu(stocka, zenbat);
			break;
		case BISTARATU:
			MENUA_bistaratu(stocka, zenbat);
			break;
		case IRTEERA:
			MENUA_irten();
			break;
		default:
			printf("Aukera desegokia\n");

	}

	return zenbat;
}

int	MENUA_sartuDiska(DISKA_MOTA stocka[], int zenbat) {
	DISKA_MOTA diskaBerria;
	printf("[INFO]Diska bat sortu aukeratu duzu.\n");
	diskaBerria = DISKA_sortubat();
	zenbat = STOCKA_diskaBatSartu(diskaBerria, stocka, zenbat);
	//stocka = STOCKA_diskaBatSartu_v2(stocka, diskaBerria) {
	return zenbat;
}

int MENUA_ezabatuDiska(DISKA_MOTA stocka[], int zenbat) {
	char str[MAX_STR];
	int pos = -1;
	int zenbatBerria;

	printf("Idatzi ezabatu nahi duzun diskaren izena:\n");
	fgets(str, MAX_STR, stdin);
	str[strlen(str) - 1] = '\0';

	pos = DISKAK_bilatuDiska(stocka, zenbat, str);
	zenbatBerria = DISKAK_ezabatuDiska(stocka, pos, zenbat);

	if (zenbatBerria < zenbat) printf("Diska Ezabatua");
	else printf("Ez da diskarik ezabatu\n");

	return zenbatBerria;
}

int MENUA_eguneratu(DISKA_MOTA stocka[], int zenbat) {
	char str[MAX_STR];
	int pos = -1;

	printf("Idatzi eguneratu nahi duzun diskaren izena:\n");
	fgets(str, MAX_STR, stdin);
	str[strlen(str) - 1] = '\0';
	pos = DISKAK_bilatuDiska(stocka, zenbat, str);
	stocka[pos] = DISKA_modifikatu(stocka[pos]);
	return zenbat;
}
void MENUA_bistaratu_estiloka(DISKA_MOTA stocka[], int zenbat) {
	char str[MAX_STR];
	ESTILOAK estiloa;
	printf("Idatzi diska berriaren estiloa (BLUES=0, ROCK=1, JAZZ=2, POP=3 , ELECTRONICA=4, PUNK=5):");
	fgets(str, MAX_STR, stdin);
	sscanf(str, "%u", &estiloa);
	DISKAK_bistaratu_estiloka(stocka, zenbat, estiloa);

}
void MENUA_bistaratu(DISKA_MOTA stocka[], int zenbat) {
	DISKAK_bistaratuDanak(stocka, zenbat);
	itxoin();
}

void MENUA_irten() {
	system("clear");
	printf("Irtetzea erabaki duzu agur.\n");
	jarraitu();
}




void foo() {
	printf("************************EROSLEAREN MENUA*********\n");
	printf("|1 - Diska berri bat gehitu erosketara (Carrito de la compra)	\n");
	printf("|2 - Erosketa burutu						\n");
	printf("|3 - Erosketa karritoa ikusi				\n");
	printf("|4 - Bistaratu	stocka						\n");
	printf("|	a) - Estilokaka							\n");
	printf("|	b) - Autoreka 							\n");
	printf("|	c) - Zigilua							\n");
	printf("|	d) - Datak erabiliz 					\n");
	printf("|	e) - Bat aurkitu	 					\n");
	printf("|0 - Irten 									\n");
	printf("********************************************\n");
}



STOCKA  MENUA_admin_v2(STOCKA stocka) {

	int aukera = 1;
	char str[MAX_STR];

	while (aukera != 0){
		printf("************************ADMIN MENUA*********\n");
		printf("|1 - Diska berri bat gehitu stocka			\n");
		printf("|2 - diska bat kendu stocketik				\n");
		printf("|3 - Diska bat modifikatu					\n");
		printf("|4 - Bistaratu								\n");
		printf("|	a) - Estilokaka							\n");
		printf("|	b) - Autoreka 							\n");
		printf("|	c) - Zigilua							\n");
		printf("|	d) - Datak erabiliz 					\n");
		printf("|	e) - Bat aurkitu	 					\n");
		printf("|0 - Irten 									\n");
		printf("********************************************\n");
		printf("Admin zer nahi dozu?\n");
		fgets(str, MAX_STR, stdin);
		//
		sscanf(str, "%i", &aukera);
		printf("ajkdjkjed: %i\n", aukera);
		//!!!!!!!!!!!!!!!!!!!!!!
		//KONTUZ!!!!!!!!!!!!!!!!!!!!!!!!!
		//HAU HOBETO LEGOKE STOCKA kontzeotua erabilita , baina kodea berriro ere ez idazteko egin dut!!!!!!!!!!!!!!!!!!!!!
		stocka.zenbat = MENUA_ADMIN_exekutatu(aukera, stocka.diskak, stocka.zenbat);
		garbitu();
	}

	return stocka;
}

MOTA MENUA_login(ERABILTZAILEA erabil[], int kop, char username[]) {
	char str[MAX_STR];
	MOTA ret;
	garbitu();
	printf("username:");
	fgets(str, MAX_STR, stdin);
	str[strlen(str) - 1] = '\0';
	strcpy(username, str);

	printf("password:");
	fgets(str, MAX_STR, stdin);
	str[strlen(str) - 1] = '\0';

	ret = ERABIL_login(username, str, erabil, kop);

	return ret;


}


STOCKA  MENUA_erabil(STOCKA stockBat, ERABILTZAILEA erabiltzaileak[], int erabilIndex) {
	char str[MAX_STR];
	int aukera = 0;
	garbitu();
	do {
		printf("----------------------------------------------------------\n");
		printf("%s ongi etorri dendara. Momentuz zure karritoan : %i , eta %f $ dituzu\n",
				erabiltzaileak[erabilIndex].izena,
			erabiltzaileak[erabilIndex].erosketak.zenbat,
			erabiltzaileak[erabilIndex].dirua);
		jarraitu();
		printf("----------------------------------------------------------\n");
		printf("------------------DENDA-----------------------------------");
		DISKAK_bistaratuDanak(stockBat.diskak, stockBat.zenbat);
		printf("---------------------------------------------------------\n");
		printf("*************************MENUA********************************\n");
		printf("*\t1- Gehitu diska bat KARRITORA\n");
		printf("*\t2- Bistaratu KARRITOA\n");
		printf("*\t3- Bistaratu denda\n");
		printf("*\t4- Kendu diska bat karritotik\n");
		printf("*\t5- Erosketa burutu\n");
		printf("*\t0-Irten\n");
		printf("***************************************************************\n");
		printf("Aukera:");
		fgets(str, MAX_STR, stdin);
		//
		sscanf(str, "%i", &aukera);
		//KONTUZ!!!!!!!!!!!!!!!!!!!!!!!
		stockBat = MENUA_exekutatuErabil(stockBat, erabiltzaileak, erabilIndex, aukera);
		jarraitu();


	} while (aukera != 0);
	

	return stockBat;
}


STOCKA MENUA_exekutatuErabil(STOCKA stockBat, ERABILTZAILEA erabiltzaileak[], int erabilIndex, int aukera) {
	char str[MAX_STR];
	int id;
	int zenbat = 0;
	DISKA_MOTA diska;
	int egoera = FALSE;
	int  i = 0;
	float totala = 0;
	garbitu();
	switch (aukera) {
		case 1:
			printf("Erosketara gehitu nahi duzun diskaren ID:");
			fgets(str, MAX_STR, stdin);
			sscanf(str, "%i", &id);
			diska = STOCKA_bilatuDiska(stockBat, id);
			if (diska.id != -1) {
				printf("Zenbat diska nahi dutuzu:");
				fgets(str, MAX_STR, stdin);
				sscanf(str, "%i", &zenbat);
				if (zenbat <= diska.stock) { //HONEK HOLA EGITEA BUG BAT SORYUI DEZAKE  , ZE BI ALDIZ DISKO BERA KARRITOAN GEHITZERAKOAN EZ DAU  STOCKA - EGITEN
											//BERAZ KONPROBAZIOA BAT BEHAR DU EROSTERAKOAN 
											//BESTE AUKERA BAT ORAIN STOCK KENTZEA DA , erresebar bat moduan eginez
					egoera = ERABILTZAILEA_gehituErosketa(erabiltzaileak, erabilIndex, diska, zenbat);
					if (egoera == TRUE) {
						printf("%s:%s Diska ondo gehituta erosketara.\n " , diska.izenburua , diska.autor);
					}
					else {
						printf("Ezin izan da %s:%s Diska gehitu.\n ", diska.izenburua, diska.autor);
					}
				}
				else {
					printf("[INFO]Ez dira gelditzen hainbeste diska.\n");
				}
				
			}

			break;
		case 2:
			DISKAK_bistaratuDanak(erabiltzaileak[erabilIndex].erosketak.diskak ,
					erabiltzaileak[erabilIndex].erosketak.zenbat);
			totala = ERABILTZAILEA_erosketakoPrezioa(erabiltzaileak , erabilIndex );
			printf("Ersoketa guztira: %f $\n ", totala);
			break;

		case 3:
			printf("------------------STOCKA-----------------------------------");
			DISKAK_bistaratuDanak(stockBat.diskak, stockBat.zenbat);
			break;

		case 4:
			printf("TODO\n");
			break;

		case 5:
			DISKAK_bistaratuDanak(erabiltzaileak[erabilIndex].erosketak.diskak,
				erabiltzaileak[erabilIndex].erosketak.zenbat);
			totala = ERABILTZAILEA_erosketakoPrezioa(erabiltzaileak, erabilIndex);
			printf("Ersoketa guztira: %f $\n ", totala);
			//HEMEN ZIHUR ZAUDE GALDETZEA ONDO LEGOKE
			printf("EROSKA BURUTZERA....\n");
			printf("****************************************\n");
			//hau funztio baten KONTUZ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			//HOLAN TXARTO
			//hemen stock berriro konprobatu beharko zan!!!!!!!!!!!!!!!!!!!!!!!!! EROSI AURRETIK EROSKETA POSIBE DAN IKUSIZ!!!!!!!!!
			if (erabiltzaileak[erabilIndex].dirua > totala) {
				//STOCKA EGUNERATU
				for (i = 0; i < erabiltzaileak[erabilIndex].erosketak.zenbat; i++) {
					stockBat = STOCKA_modifikatuDiska(stockBat,
						erabiltzaileak[erabilIndex].erosketak.diskak[i].id,
						erabiltzaileak[erabilIndex].erosketak.diskak[i].stock);
				}
				erabiltzaileak[erabilIndex].erosketak.zenbat = 0;
				//ETA HEMEN FAKTURA SORTU BEHARKO ZAN
				erabiltzaileak[erabilIndex].dirua = erabiltzaileak[erabilIndex].dirua - totala;
				printf("EROSKETA EGI�A\n");

			}
			else {
				printf("Ezin daiteke erosket aburutu . Ez dekozu dirurik!!!!\n");
			}
			break;
		case 0:
			break;
		default:
			break;
	}
	return stockBat;
}

void jarraitu() {
	printf("Sakatu return jarraitzeko....");
	getchar();
	system("clear");
}
