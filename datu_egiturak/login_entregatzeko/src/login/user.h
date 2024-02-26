#ifndef LOGIN_USERS_H
#define LOGIN_USERS_H

typedef struct {
	char *izena;
	char *pasahitza;
	int erabiltzailea_mota;	//0-user 1-admin 2-guest
	char *email;
} USER;

int loginSaiatu(USER user_datu_basea[], int erabiltzaile_kop, int saiakerak, int *erabiltzaile_id);
int loginSaiakera(USER user_datu_basea[], int erabiltzaile_kop, int *erabiltzaile_id);
void ongiEtorri(USER erabiltzaile);
void saiakeraGehiegi(void);

void erabiltzaileak_bistaratu(USER user_datu_basea[], int erabiltzaile_kop);
void erabiltzaile_bat_bistaratu(USER erabiltzaile);
void erabiltzaile_mota_bistaratu(int mota);
char *erabiltzaile_mota_itzuli(int mota);


#endif // LOGIN_USERS_H
