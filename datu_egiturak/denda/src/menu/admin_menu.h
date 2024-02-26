#ifndef ADMIN_MENU_H
#define ADMIN_MENU_H

#include "user.h"

int ADMIN_MENU_main(USER_VECTOR * users);
USER ADMIN_MENU_erabiltzailea_eskatu();
void ADMIN_MENU_sortu(USER_VECTOR * users);
void ADMIN_MENU_aldatu(USER_VECTOR * users);
void ADMIN_MENU_kendu(USER_VECTOR * users);
void ADMIN_MENU_guztiak_ikusi(USER_VECTOR * users);

#endif				// ADMIN_MENU_H
