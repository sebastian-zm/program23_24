#ifndef USER_H
#define USER_H

#include "vector_helper.h"

typedef enum {
	USER_ADMIN,
	USER_CLIENT,
	USER_RETAIL
} USER_TYPE;

typedef struct {
	char *name;
	char *password;
	USER_TYPE type;
} USER;

VECTOR_HELPER_CREATE_VECTOR_HEADER(USER_VECTOR, USER)
char *USER_type2str(USER_TYPE type);
int USER_password_match(USER user, char *passwd);
int USER_login(USER_VECTOR * users, USER * user);

#endif				// USER_H
