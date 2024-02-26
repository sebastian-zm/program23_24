/*
 * login.c
 *
 *  Created on: 2024(e)ko ots. 5(a)
 *      Author: joseba
 */
#include <string.h>
#include <stdio.h>
//#include <system.h> windows
#include <stdlib.h>		//linux =>system("clear")

#include "orokorrak.h"		// users.h-ren aurretik
#include "users.h"

int main()
{
	//aldagiak
	int logeatua = 0;

	//USER user1 = {"","",-1,"",-1};
	USER user1;
	// 0- user        1- admin motakoa        2- guest
	USER user_datu_basea[] = {
		{"admin", "qwerty", 1, "admin@mondragon.edu", 1},
		{"idazkiratza", "asdfg", 0, "idaz@mondragon.edu", 2},
		{"joseba", "123456", 2, "jaagirre@mondragon.edu", 3},
		{"irati", "@g1rr3", 2, "iagirre@mondragon.edu", 4},
		{"jon", "yrtyry&$@vnf2", 2, "admin@mondragon.edu", 5},
	};
	int kop_users = 5;
	erabiltzaileak_bistaratu(user_datu_basea, kop_users);
	itxoin();

	/*int i = 0;
	   printf("====================================================\n");
	   //1- erabilztaileak_bistaratu
	   for (i= 0; i < kop_users; i++){
	   //user_datu_basea[i].id = user_datu_basea[i].id +7;
	   //2-erabiltzaile_bat_bistaratu
	   printf("%d. %s %s:%s ", user_datu_basea[i].id,  user_datu_basea[i].email,
	   user_datu_basea[i].izena,  user_datu_basea[i].pasahitza);
	   //3-erabiltzaile_mota_bistaratu
	   switch(user_datu_basea[i].erabiltzailea_mota){
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

	   } */

	int saiakerak = 3;
	//PROGRAM
	do {
		//1-ESKATU username eta password eta utzi user1 aldagian
		//void  password_login_irakurri( char erabiltzaile_izena[],char pasahitza[]);
		//password_login_irakurri( user1.izena , user1.pasahitza);
		//user1 = erabiltzaile_datuak_eskatu( user1);
		user1 = erabiltzaile_datuak_eskatu_ona();

		//2-konprobatu ia admin qwerty
		//logeatua =  login_konprobatu(user1.izena ,user1.pasahitza);
		logeatua = konprobatu_user(user1);

		//5- 3 saiakera
		saiakerak--;
	} while (logeatua == FALSE && saiakerak > 0);

	//3-admin qwerty bakdin bada emon ongi ettoria
	//4-bestela esan soilik desegokia dala
	//menua(logeatua, user1.izena);
	menua_denda(logeatua, user1);

	//bukaera
	agur_mezua();

	return 0;
}
