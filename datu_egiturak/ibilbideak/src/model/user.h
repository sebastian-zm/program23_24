#ifndef USER_H
#define USER_H

#include "array_helper.h"

#define USER_MAX_STR 127
#define USER_MAX_USERS 128

typedef struct {
	int id;
	char name[USER_MAX_STR];
	char password[USER_MAX_STR];
} USER;

ARRAY_HELPER_CREATE_ARRAY_HEADER(USERS, USER, USER_MAX_USERS)

int USER_password_match(USER user, char passwd[]);
int USER_login(USERS users, char name[], char passwd[]);

#endif				// USER_H
