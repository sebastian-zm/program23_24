/*
 * users.c
 */

//kodea idazten hasi aurreik #includeak
//lehen eta bizi incude ofizialak < >
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//eta azkniek nire inlcudeak , fitxategi honetako , users.c-n banago azkenego
#include "orokorrak.h"
//include izan behrako zan users.h
#include "users.h"

void erabiltzaileak_bistaratu(USER users[], int kop)
{
	int i = 0;
	printf("====================================================\n");
	//1- erabilztaileak_bistaratu
	for (i = 0; i < kop; i++) {
		erabiltzaile_bat_bistartu(users[i]);
	}
}

void erabiltzaile_bat_bistartu(USER user)
{
	//user_datu_basea[i].id = user_datu_basea[i].id +7;
	//2-erabiltzaile_bat_bistaratu
	printf("%d. %s %s:%s ", user.id, user.email, user.izena, user.pasahitza);
	erabiltzaile_mota_bistaratu(user.erabiltzailea_mota);
}

void erabiltzaile_mota_bistaratu(int mota)
{
	//3-erabiltzaile_mota_bistaratu
	switch (mota) {
	case 0:
		printf("Privileges: user\n");
		break;
	case 1:
		printf("Privileges:admin\n");
		break;
	case 2:
		printf("Privileges:guest\n");
		break;
	default:
		printf("Privileges: None\n");

	}

}

void menua(int erabil_mota, char izena[])
{
	if (erabil_mota == 1) {
		printf("Ongi etorri aplikazioara %s\n", izena);
	} else {
		printf("Login desegokia. Agur.\n");
	}
}

void menua_denda(int erabil_mota, USER user)
{
	if (erabil_mota == 1) {
		printf("Ongi etorri aplikazioara %s\n", user.izena);
	} else {
		printf("Login desegokia. Agur.\n");
	}
}

int login_konprobatu(char *username, char password[])
{
	int ret_logeatua = FALSE;
	int izenak_berdinak = FALSE;
	int pasahitzak_berdinak = FALSE;

	izenak_berdinak = !strcmp(username, USERNAME);
	pasahitzak_berdinak = !strcmp(password, PASSWORD);
	if ((izenak_berdinak == TRUE) && (pasahitzak_berdinak == TRUE)) {
		ret_logeatua = TRUE;
	}

	return ret_logeatua;

}

int konprobatu_user(USER erabiltzaile_bat)
{
	int ret_logeatua = FALSE;
	int izenak_berdinak = FALSE;
	int pasahitzak_berdinak = FALSE;

	izenak_berdinak = !strcmp(erabiltzaile_bat.izena, USERNAME);
	pasahitzak_berdinak = !strcmp(erabiltzaile_bat.pasahitza, PASSWORD);
	if ((izenak_berdinak == TRUE) && (pasahitzak_berdinak == TRUE)) {
		ret_logeatua = TRUE;
	}

	return ret_logeatua;

}

void password_login_irakurri(char erabiltzaile_izena[], char pasahitza[])
{
	printf("================Subasta aplikazioan sartzeko logina=========================\n");

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

USER erabiltzaile_datuak_eskatu_ona()
{
	USER erabiltzaile_bat;
	printf("================Subasta aplikazioan sartzeko logina=========================\n");
	char str[MAX_STR];
	//====================================================
	printf("Username:");
	fgets(str, 64, stdin);
	str[strlen(str) - 1] = '\0';
	strcpy(erabiltzaile_bat.izena, str);

	printf("Password:");
	fgets(erabiltzaile_bat.pasahitza, 64, stdin);
	erabiltzaile_bat.pasahitza[strlen(erabiltzaile_bat.pasahitza) - 1] = '\0';
	// system("cls"); =>windows
	system("clear");	// => linux
	// clrscr(); windows

	return erabiltzaile_bat;

}

USER erabiltzaile_datuak_eskatu(USER erabiltzaile_bat)
{
	printf("================Subasta aplikazioan sartzeko logina=========================\n");
	char str[MAX_STR];
	//====================================================
	printf("Username:");
	fgets(str, 64, stdin);
	str[strlen(str) - 1] = '\0';
	strcpy(erabiltzaile_bat.izena, str);

	printf("Password:");
	fgets(erabiltzaile_bat.pasahitza, 64, stdin);
	erabiltzaile_bat.pasahitza[strlen(erabiltzaile_bat.pasahitza) - 1] = '\0';
	// system("cls"); =>windows
	system("clear");	// => linux
	// clrscr(); windows

	return erabiltzaile_bat;
}
