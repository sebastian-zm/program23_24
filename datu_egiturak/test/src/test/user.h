#ifndef TEST_USER_H
#define TEST_USER_H

#include "cart.h"

struct User {
	char* izena;
	char* erabiltzailea;
	int zentimoak;
};

struct User carts_user(struct Cart cart);

#endif // TEST_USER_H
