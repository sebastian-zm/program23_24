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
#include "orokorrak.h"


#include "diska.h"




void DISKA_bistaratuEstiloa(int estiloa) {
	switch (estiloa) {
		case ROCK: 
			printf("Rock\n");
			break;
		case BLUES:
			printf("Blues\n");
			break;
		case ELECTRONICA:
			printf("Electronica\n");
			break;
		case JAZZ:
			printf("Jazz\n");
			break;
		case POP:
			printf("Pop\n");
			break;
		case PUNK:
			printf("Punk\n");
			break;
		default:
			printf("Ezezaguna\n");
			break;
	}

}


void DISKA_bistaratuBat(DISKA_MOTA diska) {
	printf("_______________DISKA  %i_________________________\n", diska.id);
	printf("DISKA %s ( %s ) \n%2.2f euro ,  %s \t  stock:%i\n", diska.izenburua,
		diska.autor, diska.prezioa,
		diska.data,
		diska.stock);
	DISKA_bistaratuEstiloa(diska.estiloa);
}


DISKA_MOTA DISKA_sortubat() {
	//1-DISKA BAT SORTU
	DISKA_MOTA diska;
	char str[128];
	//diskari baloreak emon fgets , printf sscanf
	printf("Idatzi diska berriaren ida:");
	fgets(str, 128, stdin);
	sscanf(str, "%i", &diska.id);
	//1- Izneburua 
	printf("Idatzi diska berriaren izenburua:");
	fgets(str, 128, stdin);
	str[strlen(str) - 1] = '\0';
	strcpy(diska.izenburua , str);
	//2-autorea
	printf("Idatzi diska berriaren autorea/taldea:");
	fgets(str, 128, stdin);
	str[strlen(str) - 1] = '\0';
	strcpy(diska.autor, str);
	//3-data 
	printf("Idatzi diska berriaren data(2020/2/7):");
	fgets(str, 128, stdin);
	str[strlen(str) - 1] = '\0';
	strcpy(diska.data, str);
	//4-estiloa
	printf("Idatzi diska berriaren estiloa (BLUES=0, ROCK=1, JAZZ=2, POP=3 , ELECTRONICA=4, PUNK=5):");
	fgets(str, 128, stdin);
	sscanf(str, "%u", &diska.estiloa);
	//5-prezioa
	printf("Idatzi diska berriaren prezioa:");
	fgets(str, 128, stdin);
	sscanf(str, "%f", &diska.prezioa);
	//diska bueltatu
	return diska;
}



//int STOCKA_modifikatuDiska(DISKA_MOTA diskak[], int pos, int kop) {
DISKA_MOTA DISKA_modifikatu(DISKA_MOTA diska) {
	int zenbat = 0;
	char str[MAX_STR];

	printf("%s diskaren stock zenbatera eguneratu nahi duzu?\n", diska.izenburua);
	fgets(str, MAX_STR, stdin);
	sscanf(str, "%i", &zenbat);
	diska.stock = zenbat;
	

	return diska;
}




