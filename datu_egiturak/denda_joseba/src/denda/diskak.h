/*
	int id;
	float prezioa;
	int stock;
	char izenburua[MAX_STR];
	char autor[MAX_STR];//taldea , solista
	int estiloa;
	char data[MAX_STR];
*/


#ifndef _DISKAK_H
#define _DISKAK_H




//DISKA ASKOREN FUNZTIOAK
void DISKAK_bistaratuDanak(DISKA_MOTA diskak[], int zenbat);
void DISKAK_bistaratu_estiloka(DISKA_MOTA diskak[], int zenbat,ESTILOAK estiloa);

int  DISKAK_diskaBatSartu(DISKA_MOTA diska, DISKA_MOTA stocka[], int zenbat);
int	 DISKAK_sortu(DISKA_MOTA diskak[]);
int  DISKAK_bilatuDiska(DISKA_MOTA diskak[], int kop, char izena[]);
int DISKAK_ezabatuDiska(DISKA_MOTA diskak[], int pos, int zenbat);



#endif










