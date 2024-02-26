#ifndef _MENUA_
#define _MENUA_
typedef enum Admin_Aukera{  IRTEERA ,  
							SORTU_DISKA, 
							EZABATU_DISKA,
							EGUNERATI_DISKA,
							BISTARATU }
			ADMIN_AUKERAK;



/*** 
DESKURIPZIOA :ADMIN MENUA  (CRUD , Create Read , Update , Delete)
				1- Diska berri bat gehitu stocka (CREATE)
				2- diska bat kendu stocketik (DELETE)
				3- Diska bat modifikatu (UPDATE)
				4- Bistaratu
					4.0-Danak
					4.1- Estilokaka
					4.2- Autoreka
					4.3- Zigilua
					4.4- Datak erabiliz
					4.5- Aurkitu
				0- Irten

SARRERA:stocka, zenbatb,
irteera: zenbat, stocka
*/


int  MENUA_admin(DISKA_MOTA stocka[], int zenbat);

int  MENUA_ADMIN_exekutatu(int aukera, DISKA_MOTA stocka[], int zenbat);
int	MENUA_sartuDiska(DISKA_MOTA stocka[], int zenbat);


//TODO
STOCKA  MENUA_admin_v2(STOCKA stocka);
int	MENUA_sartuDiska(DISKA_MOTA stocka[], int zenbat);
int MENUA_ezabatuDiska(DISKA_MOTA stocka[], int zenbat);
int MENUA_eguneratu(DISKA_MOTA stocka[], int zenbat);
void MENUA_bistaratu(DISKA_MOTA stocka[], int zenbat);
void MENUA_bistaratu_estiloka(DISKA_MOTA stocka[], int zenbat);
void MENUA_irten();


MOTA MENUA_login(ERABILTZAILEA erabil[], int kop, char username[]);
STOCKA  MENUA_erabil(STOCKA stockBat,  ERABILTZAILEA erabiltzaileak[] , int erabilIndex);
STOCKA MENUA_exekutatuErabil(STOCKA stockBat, ERABILTZAILEA erabiltzaileak[], int erabilIndex, int aukera);



void jarraitu();







#endif
