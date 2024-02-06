#ifndef HELPERS_CONSOLE_H
#define HELPERS_CONSOLE_H

#include <string.h>
#include <stdio.h>

void HELPERS_CONSOLE_return_amaitzeko() {
    fprintf(stdout, "Sakatu return amaitzeko...\n");
    getc(stdin);
}

void HELPERS_CONSOLE_eskatu_str(char* buffer, int n) {
    fgets(buffer, n, stdin);
    buffer[strlen(buffer) - 1] = '\0';
}

#endif
