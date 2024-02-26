#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "user.h"
#include "console_helper.h"

#define UNUSED(x) do (void) x; while (0)

#define SAIAKERAK 3

int main(int num, char *args[])
{
	UNUSED(num);
	UNUSED(args);

	USER user_datu_basea[] = {
		{.izena = "admin",.pasahitza = "qwerty",.erabiltzailea_mota = 1,.email = "admin@example.invalid"},
		{.izena = "irati",.pasahitza = "@g1rr3",.erabiltzailea_mota = 2,.email = "irati@example.invalid"},
		{.izena = "joseba",.pasahitza = "123456",.erabiltzailea_mota = 2,.email = "jaagirre@example.invalid"},
		{.izena = "jon",.pasahitza = "vf4P-8k",.erabiltzailea_mota = 2,.email = "jon@example.invalid"}
	};

	int erabiltzaile_id;

	erabiltzaileak_bistaratu(user_datu_basea, sizeof(user_datu_basea) / sizeof(user_datu_basea[0]));
	CONSOLE_HELPER_itxaron("Sakatu return jarraitzeko....");

	if (loginSaiatu
	    (user_datu_basea, sizeof(user_datu_basea) / sizeof(user_datu_basea[0]), SAIAKERAK, &erabiltzaile_id)) {
		ongiEtorri(user_datu_basea[erabiltzaile_id]);
	} else {
		saiakeraGehiegi();
	}

	//programa
	//1-ESKATU username eta password
	//2-konprobatu admin qwerty
	//3-admin qwerty bada emon ongi etorria
	//4-bestela esan desegokia dela
	//5-3 saiakera

	//bukaera
	CONSOLE_HELPER_itxaron("Sakatu return bukatzeko....");

	return 0;
}
