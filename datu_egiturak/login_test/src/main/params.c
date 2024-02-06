#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void read_params(int argc, char** argv, char** erabiltzaile_path) {

    *erabiltzaile_path = NULL;

    for (int i = 2; i < argc; i+=2) {
        if (strcmp(argv[i - 1], "-ep") == 0) {
            *erabiltzaile_path = argv[i];
        }
    }

    if (!*erabiltzaile_path) {
        fprintf(stdout, "Erabiltzaileen fitxategiaren kokapena behar dut.");
        exit(EXIT_FAILURE);
    }
}

