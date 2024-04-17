#include <stdio.h>
#include <string.h>

#include "ikasle.h"

int main()
{
	ERABILTZAILEA erabiltzaileak[MAX_ERABIL];
	int kop = 0;
	//irakurri N ikaslerern emaila => non gordeko dot? ARRAYA BATEN IKASLEENA

	//BAT IRAKURTZEKO
	erabiltzaileak[kop] = eskatuHelbidea();
	bistaratuErabiltzailea(erabiltzaileak[kop]);
	bistaratuErabiltzaileaPTRgaz(&erabiltzaileak[kop]);
	bistaratuErabiltzaileaPTRgaz(erabiltzaileak + kop);
	kop++;

	//kop = eskatuHainbatHelbide(erabiltzaileak, kop);

	eskatuHainbatHelbidev2(erabiltzaileak, &kop);
	pantailaratu(erabiltzaileak, kop);

	//EMAILETIK IKASLE BAKOITZAREN IZENA ATARA

	//EMAILETIK  IKASLE BAKOITZAREN ABIZENA ATARA

	return 0;
}
