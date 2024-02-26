#include <stdbool.h>
#include "vector_helper.h"
#include "user.h"

VECTOR_HELPER_CREATE_VECTOR(USER_VECTOR, USER)
char *USER_type2str(USER_TYPE type)
{
	char *ret = "unknown";
	switch (type) {
	case USER_ADMIN:
		ret = "admin";
		break;
	case USER_RETAIL:
		ret = "dendari";
		break;
	case USER_CLIENT:
		ret = "kliente";
		break;
	}
	return ret;
}

int USER_password_match(USER user, char *passwd)	// In the future this function should use hashes
{
	return !strcmp(user.password, passwd);
}

int USER_login(USER_VECTOR * users, USER * user)
{
	int len = USER_VECTOR_length(users);
	int i = 0;
	bool user_match;
	bool password_match;
	bool found = false;
	USER curr_user;
	while (i < len && !found) {
		curr_user = USER_VECTOR_get(users, i);
		user_match = !strcmp(curr_user.name, user->name);
		password_match = !strcmp(curr_user.password, user->password);
		if (user_match && password_match) {
			found = true;
			memcpy(user, &curr_user, sizeof(curr_user));
		} else {
			++i;
		}
	}
	return found;
}

void USER_destroy(USER user)
{
	free(user.name);
	free(user.password);
}

void USER_VECTOR_destroy(USER_VECTOR * users)
{
	USER u;
	int len = USER_VECTOR_length(users);
	for (int i = len - 1; i >= 0; --i) {
		u = USER_VECTOR_get(users, i);
		USER_destroy(u);
		USER_VECTOR_remove(users, i);
	}
}
