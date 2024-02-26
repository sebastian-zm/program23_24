
#include <stdio.h> //printf
#include <string.h> //strcpy
#include "orokorrak.h" //MAX_STR


#include "diska.h"
#include "diskak.h" //DISKA_MOTA -> [MAX_STR]
#include "diskak.h"

#include "stocka.h" //->DISKA_MOTA
#include "stocka.h" //->DISKA_MOTA

int	STOCKA_sortu(DISKA_MOTA diskak[10]) {
	printf("stocka-sortzen\n");

	diskak[0].id = 1;
	diskak[0].prezioa = 11;
	strcpy(diskak[0].autor, "Robert Johnson");
	strcpy(diskak[0].izenburua, "King of Delta Blues");
	diskak[0].estiloa = BLUES;
	strcpy(diskak[0].data, "1936/06/06");
	diskak[0].stock = 0;
	

	diskak[1].id = 2;
	diskak[1].prezioa = 12;
	strcpy(diskak[1].autor, "Jimi Hendrix");
	strcpy(diskak[1].izenburua, "Are you experience?");
	diskak[1].estiloa = ROCK;
	strcpy(diskak[1].data, "1967/05/12");
	diskak[1].stock = 0;

	return 2;
}
STOCKA STOCKA_sortu_v2(){
	STOCKA stock;
	printf("stocka-sortzen\n");

	stock.diskak[0].id = 1;
	stock.diskak[0].prezioa = 11;
	strcpy(stock.diskak[0].autor, "John Coltrane");
	strcpy(stock.diskak[0].izenburua, "Blue Train");
	stock.diskak[0].estiloa = JAZZ;
	strcpy(stock.diskak[0].data, "1965/7/7");
	stock.diskak[0].stock = 7;

	stock.diskak[1].id = 2;
	stock.diskak[1].prezioa = 7;
	strcpy(stock.diskak[1].autor, "The Stooges");
	strcpy(stock.diskak[1].izenburua , "Fun House");
	stock.diskak[1].estiloa = PUNK;
	strcpy(stock.diskak[1].data, "1969/9/9");
	stock.diskak[1].stock = 0;

	stock.diskak[2].id = 3;
	stock.diskak[2].prezioa = 7;
	strcpy(stock.diskak[2].autor, "Paul Collins");
	strcpy(stock.diskak[2].izenburua, "King of power pop");
	stock.diskak[2].estiloa = POP;
	strcpy(stock.diskak[2].data, "2008/8/8");
	stock.diskak[2].stock = 2;

	stock.zenbat = 3;
	return stock;
}

int  STOCKA_diskaBatSartu(DISKA_MOTA diska, DISKA_MOTA stocka[], int zenbat) {
	if (zenbat < 10) {
		stocka[zenbat] = diska;
		zenbat++;
	}
	else {
		printf("Ezin da sartu diska stocka (Limitean gauz).\n");
	}
	return zenbat;
}

STOCKA   STOCKA_diskaBatSartu_v2(STOCKA stock, DISKA_MOTA diska) {
		if (stock.zenbat < 10) {
			stock.diskak[stock.zenbat] = diska;
			stock.zenbat++;
			
		}
		else {
			printf("Ezin da sartu diska stocka (Limitean gauz).\n");
		}
		
		return stock;
}


DISKA_MOTA STOCKA_bilatuDiska(STOCKA stockBat, int id) {
	int i = 0;
	int aurkitua = FALSE;
	DISKA_MOTA ret;
	ret.id = -1;

	while (i < stockBat.zenbat && aurkitua == FALSE) {
		if ( id == stockBat.diskak[i].id ) {
			aurkitua = TRUE;
		}
		else {
			i++;
		}
	}
	if (aurkitua == TRUE) {
		ret = stockBat.diskak[i];
	}
	return ret;
}

STOCKA STOCKA_modifikatuDiska(STOCKA stockBat, int id, int stock){
	int i = 0;
	int aurkitua = FALSE;

	while (i < stockBat.zenbat && aurkitua == FALSE) {
		
		if (id == stockBat.diskak[i].id) {
			aurkitua = TRUE;
		}
		else {
			i++;
		}
	}
	if (aurkitua == TRUE) {
		//HEMEN BUG BAT!!!!!!!!!!!!!!!
		stockBat.diskak[i].stock = stockBat.diskak[i].stock - stock;
	}
	return stockBat;

}
