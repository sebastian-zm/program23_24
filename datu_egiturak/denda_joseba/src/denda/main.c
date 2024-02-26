#include <stdio.h>
#include <stdlib.h>
/*
PROGRAMA: Disken denda
DESKRIPZIOA: Disken denda
			- Dendaria -> stock sortu eta administrau,  bezeroak kudeatu 
			- Diskoa
			- Bezeroa -> bilatu diskak eta Erosi
			0. stock-a sortu (diskak)
			1.Login (Nor zara )
			2.Bezeroarren menua
				2.1-Diska gehitu
				2.2- Bilatu (estilos , por titulo , por fecha , por autor)
				2.3- Erosketa burutu
			3.Dendariaren menua
				3.1-Diskak gehitu
				3.2- Diskak modifikatu (stock , prezioa,)
				3.3- Bezeroak kudeatu
					-gehitu
					- kendu
					- modifikatu
					- dirua emon

*/
#include "orokorrak.h"
#include "diska.h"
#include "diskak.h"
#include "stocka.h"
#include "erabiltzaileak.h"

#include "menua.h"



int main() {
	//opcion1)
	int zenbatBilbo = 0;
	DISKA_MOTA stocka[10]; //BILBO-ko DENDA magikoa da
	//******************************
	//opcion2)
	STOCKA dendakoStocka; //DENDA hau ez da magikoa

	//diska berria  barruan sortzen du
	 //zenbatBilbo= STOCK_diska_bat_gehitu_opcion1( stocka, zenbatBilbo);
	 //ERRRRORRRRRRRRRRRRRRRRRRRRRRRR
	 //STOCK_diska_bat_gehitu_opcion1( stocka, zenbatBilbo);
	//
	 //DISKA_MOTA diska_bat;
	 //strcpy ( diska_bat.izenburua, "Electric Ladylan ");
	 //zenbatBilbo= STOCK_diska_bat_gehitu_opcion11( diska_bat , stocka, zenbatBilbo);

	 //dendakoStocka = STOCK_diska_bat_gehitu_opcion2(  dendakoStocka);
	 //ERRORRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
	  //STOCK_diska_bat_gehitu_opcion2(  dendakoStocka);

	  //opcion3)
	  //STOCKA dendakoStocka; //DENDA hau ez da magikoa

	  //zenbatBilbo           =  STOCK_diska_bat_gehitu_opcion11(  stocka,             zenbatBilbo);
	  //dendakoStocka.zenbat  = STOCK_diska_bat_gehitu_opcion1( dendakoStocka.diskak, dendakoStocka.zenbat);



	MOTA mota = 0;
	char username[MAX_STR];
	int erabilIndex = 0;
	int bukatu = 0;
	
	ERABILTZAILEA erabil[5];
	int kopErabil = 0;


	//ERABILTZAILEAK SORTU
	kopErabil =  ERABILTZAILEAK_sortu_(erabil, kopErabil);
	
	//PROGRANA
	//0. stock - a sortu(diskak)
	printf("[INFO]->Bilboko Stocka kargetan ....\n");
	zenbatBilbo = STOCKA_sortu(stocka); //arraya
	printf("[INFO]->Bilboko Stocka kargatuta ....\n");
	printf("[INFO]...\n]");

	DISKAK_bistaratuDanak(stocka, zenbatBilbo);
	jarraitu();
	printf("Orain best era bate kudeatuko ditugu stocka, zenbat eta diskak elkarrekin ;-)\n");
	dendakoStocka = STOCKA_sortu_v2();

	printf("------------------Bigarren  stocka-----------------------------------");
	DISKAK_bistaratuDanak(dendakoStocka.diskak, dendakoStocka.zenbat);
	printf("------------------------------------DISKA DENDA-----------------------------------------------------\n");
	
	while( bukatu != -1){
		//ESKATU USERNAME ETA PASSWORD ETA GERO PASAU FUNTZIOARI
		mota = MENUA_login(erabil, kopErabil, username);
		switch (mota) {
			case ADMIN:
				dendakoStocka = MENUA_admin_v2(dendakoStocka);
				//BALIKOIDEA
				//dendakoStocka.zenbat = MENUA_admin_v1(dendakoStocka.diskak, dendakoStocka.zenbat);

				break;
			case EROSLE:
				//AURKITU ERABITZAILEAREN POSIZIOA ARRAIAN
				erabilIndex= ERABIL_aurkitu(username, erabil, kopErabil);
				if (erabilIndex >= 0) {         //opcion 2 STOCK -  MAGIA
					dendakoStocka = MENUA_erabil(dendakoStocka,   erabil, erabilIndex);
					//ERABILTZAILEA user;
					//user = erabil[erabilIndex];
					//donostikoStocka = MENUA_erabil(donostikoStocka, &user);
					//donostikoStocka = MENUA_erabil(donostikoStocka, &erabil[erabilIndex]);
	
				}
				break;
			case NONE:
				bukatu = -1;
				break;
			default:
				bukatu = -1;
				break;
		}
	}
	
	
	
	//BUKAERA
	agur_mezua();
	return 0;
}


