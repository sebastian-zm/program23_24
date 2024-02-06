#ifndef LOGIN_LOGIN_H
#define LOGIN_LOGIN_H

#include <stdbool.h>

bool LOGIN_main(char* erabiltzaile_path);
bool LOGIN_find_user(char* username, char* password, char* erabiltzaile_path);

#endif
