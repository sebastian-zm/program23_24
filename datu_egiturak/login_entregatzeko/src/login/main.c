#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STR 64
#define MAX_ZENBAKIAK 10

typedef struct {
	char izena[MAX_STR];
	char pasahitza[MAX_STR];
	int erabiltzailea_mota;	//0-user, 1-admin 2-guest
	char email[MAX_STR];
} USER;

//FUNZTIOEN BURUALDEEN DEFINIZIOA
void agur_mezua(void);
int logina(void);
void password_login_irakurri(char erabiltzaile_izena[], char pasahitza[],
			     int saiakerak);
int login_konprobatu(char *username, char password[], char *datubasea_izenak[],
		     char *datubasea_pasahitzak[], int kop_username);
void menua(int erabil_mota, char username[]);

int main(int num, char *args[])
{
	//aldagiak
	int logeatua = 0;
	//char* string bat
	//char* [] -> string-en array bat , izen asko , [0], [1]
	//char* datubasea_username[10];
	char *datubasea_izenak[] =
	    { "admin", "joseba", "user", "idazkaritza", "irati", "jon" };
	int kop_username = 6;
	char *datubasea_pasahitzak[] =
	    { "admin", "user", "qwerty", "11111", "@g1rr3", "gshgyf%__%$1525" };
	int kop_pasahitzak = 6;

	USER datubasea[] = {
		{"admin", "admin", 1, "admin@mondragon.edu"},
		{"joseba", "qwerty", 0, "jaagirre@mondragon.edu"},
		{"idazkaritza", "11111", 0, "daz@mondragon.edu"},
		{"irati", "@g1rr3", 2, "irati@gmail.com"},
	};

	int kop_users = 4;

	USER user1;
	USER user2;

	char username[] = "joseba";
	char password[] = "nire super pasahitza";
	int saiakerak = 3;
	//programa
	password_login_irakurri(username, password, saiakerak);

	while (logeatua == 0 && saiakerak > 0) {
		password_login_irakurri(username, password, saiakerak);
		logeatua =
		    login_konprobatu(username, password, datubasea_izenak,
				     datubasea_pasahitzak, kop_username);
		if (logeatua == 0) {
			saiakerak--;	//saiakerak= saiakreak-1;
		}

	}

	menua(logeatua, username);
	//bukaera
	agur_mezua();

	return 0;
}

void menua(int erabil_mota, char izena[])
{
	if (erabil_mota == 1) {
		printf("Ongi etorri aplikazioara %s\n", izena);
	} else {
		printf("Login desegokia. Agur.\n");
	}
}

int login_konprobatu(char *username, char password[], char *datubasea_izenak[],
		     char *datubasea_pasahitzak[], int kop_username)
{
	int ret_logeatua = 0;
	int izenak_berdinak = 1;
	int pasahitzak_berdinak = 1;
	int i = 0;

	do {
		//konoaratu i garren username eta passord
		izenak_berdinak = !strcmp(username, datubasea_izenak[i]);
		pasahitzak_berdinak =
		    !strcmp(password, datubasea_pasahitzak[i]);

		if ((izenak_berdinak == 1) && (pasahitzak_berdinak == 1)) {
			ret_logeatua = 1;	//TRUE
		} else {
			i++;
		}
		//eta igualak baldn badira urten

	}
	while (ret_logeatua == 0 && i < kop_username);

	return ret_logeatua;;

}

void password_login_irakurri(char erabiltzaile_izena[], char pasahitza[],
			     int saiakerak)
{
	printf
	    ("================Subasta aplikazioan sartzeko logina=========================\n");
	printf("%d saiakerak dituzu login eiteko\n", saiakerak);

	printf("Username:");
	fgets(erabiltzaile_izena, 64, stdin);
	erabiltzaile_izena[strlen(erabiltzaile_izena) - 1] = '\0';

	printf("Password:");
	fgets(pasahitza, 64, stdin);
	pasahitza[strlen(pasahitza) - 1] = '\0';
	// system("cls"); =>windows
	system("clear");	// => linux
	// clrscr(); windows
}

void agur_mezua(void)
{
	printf("Sakatu return bukatzeko....");
	getchar();
}
