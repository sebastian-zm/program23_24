
#ifndef ERABILTZAILEAK
#define ERABILTZAILEAK
typedef enum {ADMIN, EROSLE,NONE}MOTA;

typedef struct Erabil {
	char izena[MAX_STR];
	char password[MAX_STR];
	MOTA mota;
	//KARRITO karrito;
	STOCKA  erosketak; // DISKA erositakoak[10];
	float dirua;
	char helbidea[MAX_STR];
	char fakturen_historikoa[MAX][MAX_STR];

}ERABILTZAILEA;


int ERABILTZAILEAK_sortu_(ERABILTZAILEA erabil[], int kop);

//TODO

int ERABIL_aurkitu(char username[], ERABILTZAILEA erabil[], int kop);
MOTA ERABIL_login(char username[], char password[], ERABILTZAILEA erabil[], int kop);
int ERABILTZAILEA_gehituErosketa(ERABILTZAILEA erabil[] , int erabilIndex, DISKA_MOTA diska, int zenbat);
float ERABILTZAILEA_erosketakoPrezioa(ERABILTZAILEA erabiltzaileak[], int erabilIndex);
#endif
