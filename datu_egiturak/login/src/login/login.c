#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define USERNAME "erabiltzaile"
#define PASSWORD "pasahitz"

bool login() {
    bool success = false;

    char username[64];
    char password[64];

    fprintf(stdout, "Ongi etorri gure loginera!\n"); 

    fprintf(stdout, "Erabiltzailea: "); 
    fgets(username, sizeof(username), stdin);
    username[strlen(username) - 1] = '\0';

    fprintf(stdout, "Pasahitza: "); 
    fgets(password, sizeof(password), stdin);
    password[strlen(password) - 1] = '\0';

    success = strcmp(password, PASSWORD) == 0 && strcmp(username, USERNAME) == 0;

    return success;
}

void agur_mezua() {
    fprintf(stdout, "Sakatu return amaitzeko...\n");
    getc(stdin);
}
