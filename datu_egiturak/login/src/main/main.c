#include "login.h"
#include <stdio.h>
#include <stdbool.h>

#define UNUSED(x) do (void) x; while (0)

int main(int argc, char** argv) {

    UNUSED(argc);
    UNUSED(argv);

    while (!login()) {
        fprintf(stdout, "Erabiltzaile ala pasahitza okerra!\n\n");
    }

    fprintf(stdout, "Ongi etorri aplikaziora!\n");

    agur_mezua();

    return 0;
}
