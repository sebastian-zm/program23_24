

#ifndef _STOCKA_H
#define _STOCKA_H

#define MAX_STOCK 5

typedef struct Stocka {
	int id;
	DISKA_MOTA diskak[MAX_STOCK];
	int zenbat;
	char dendaren_izena[MAX_STR];
	char url[MAX_STR];
}STOCKA;

int  STOCKA_diskaBatSartu( DISKA_MOTA diska, DISKA_MOTA stocka[], int zenbat);
int	 STOCKA_sortu(DISKA_MOTA diskak[10]);

STOCKA STOCKA_sortu_v2();
STOCKA   STOCKA_diskaBatSartu_v2(STOCKA stock, DISKA_MOTA diska );

DISKA_MOTA STOCKA_bilatuDiska(STOCKA stockBat, int id);
STOCKA STOCKA_modifikatuDiska(STOCKA stockBat,
	int id,
	int stock);






#endif
