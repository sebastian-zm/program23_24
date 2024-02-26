#include <stdio.h>
#include "puntua.h"
#include "menua.h"
#include "ibilbidea.h"
#include "user.h"

int main()
{
	USER u1 = {.id = 1, .name = "joseba", .password = "123"};
	USER u2 = {.id = 2, .name = "admin", .password = "qwerty"};

	USERS users = USERS_create();

	users = USERS_add(users, u1);
	users = USERS_add(users, u2);

	PUNTUA p1 = { .x = 1.0, .y = 0.0 };
	PUNTUA p2 = { .x = 2.0, .y = 0.0 };
	PUNTUA p3 = { .x = 3.0, .y = 1.0 };

	PUNTUAK pk1 = PUNTUAK_create();

	pk1 = PUNTUAK_add(pk1, p1);
	pk1 = PUNTUAK_add(pk1, p2);
	pk1 = PUNTUAK_add(pk1, p1);

	PUNTUAK pk2 = PUNTUAK_create();

	pk2 = PUNTUAK_add(pk2, p1);
	pk2 = PUNTUAK_add(pk2, p2);
	pk2 = PUNTUAK_add(pk2, p3);

	IBILBIDEA ibi1 = {.id = 1234567890, .izena = "Arrate", .herria = "Eibar", .puntuak = pk1, .user_id = 1};
	IBILBIDEA ibi2 = {.id = 1357908642, .izena = "Kalamua", .herria = "Eibar", .puntuak = pk2, .user_id = 2};

	IBILBIDEAK ibik = IBILBIDEAK_create();

	ibik = IBILBIDEAK_add(ibik, ibi1);
	ibik = IBILBIDEAK_add(ibik, ibi2);

	ibik = MENUA_menua(ibik, u1);

	return 0;
}
