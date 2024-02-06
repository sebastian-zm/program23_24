#include <stdio.h>
#include <stdbool.h>
#include "login.h"
#include "params.h"
#include "console.h"

int main(int argc, char** argv) {
    char* erabiltzaile_path;

    read_params(argc, argv, &erabiltzaile_path);

    while (!LOGIN_main(erabiltzaile_path)) {
        fprintf(stdout, "Erabiltzaile ala pasahitza okerra!\n\n");
    }

    fprintf(stdout, "Ongi etorri aplikaziora!\n");

    HELPERS_CONSOLE_return_amaitzeko();

    return 0;
}
