

#ifndef _DISKA_H
#define _DISKA_H


typedef enum  {BLUES, ROCK, JAZZ, POP , ELECTRONICA, PUNK}ESTILOAK;


typedef struct Diska_Mota {
	int id;
	float prezioa;
	int stock;
	char izenburua[MAX_STR];
	char autor[MAX_STR];//taldea , solista
	ESTILOAK estiloa;
	char data[MAX_STR];

}DISKA_MOTA;

//DISKA BATEN FUNZTIOAK
DISKA_MOTA DISKA_sortubat();
void DISKA_bistaratuBat(DISKA_MOTA diska);
void DISKA_bistaratuEstiloa(int estiloa);
DISKA_MOTA DISKA_modifikatu(DISKA_MOTA diska);





#endif










