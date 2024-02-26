#ifndef LOGIN_USERS_H
#define LOGIN_USERS_H

//1- Konstanteak #define
#define USERNAME "admin"
#define PASSWORD "qwerty"

#define MAX_USERS 10

//2- Datu mota berriak struct eta enum
typedef struct {
	char izena[MAX_STR];
	char pasahitza[MAX_STR];
	int erabiltzailea_mota;	//0-user, 1-admin 2-guest
	char email[MAX_STR];
	int id;
} USER;

//3- Funtzuioen definizioak , burualdeak bakarrik
//

//FUNZTIOEN BURUALDEEN DEFINIZIOA
void password_login_irakurri(char erabiltzaile_izena[], char pasahitza[]);
USER erabiltzaile_datuak_eskatu(USER erabiltzaile_bat);
USER erabiltzaile_datuak_eskatu_ona();

int login_konprobatu(char *username, char password[]);
int konprobatu_user(USER erabiltzaile_bat);

void menua(int erabil_mota, char username[]);
void menua_denda(int erabil_mota, USER user);

void erabiltzaileak_bistaratu(USER users[], int kop);
void erabiltzaile_bat_bistartu(USER user);
void erabiltzaile_mota_bistaratu(int mota);

#endif // LOGIN_USERS_H
