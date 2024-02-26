#include <stdbool.h>
#include <string.h>
#include "array_helper.h"
#include "user.h"

ARRAY_HELPER_CREATE_ARRAY(USERS, USER, USER_MAX_USERS)

int USER_password_match(USER user, char passwd[])	// In the future this function should use hashes
{
	return !strcmp(user.password, passwd);
}

int USER_login(USERS users, char name[], char passwd[])
{
	int len = USERS_length(users);
	bool user_match;
	bool match = false;
	USER curr_user;
	int i = 0;
	while (i < len && !match) {
		curr_user = USERS_get(users, i);
		user_match = !strcmp(curr_user.name, name);
		match = user_match && USER_password_match(curr_user, passwd);
		if (!match) {
			++i;
		}
	}
	if (i == len) {
		i = -1;
	}
	return i;
}
