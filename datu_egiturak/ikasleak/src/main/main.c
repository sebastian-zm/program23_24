#include <stdlib.h>
#include "menu.h"

int main() {
	int auk;
	IKASLEA ik1 = { .id = 1, .izena = "Asier", .kp = {6.5, 4.6, 1.2, 9.99}, .kp_kop = 4};
	IKASLEA ik2 = { .id = 1, .izena = "Lander", .kp = {8.5, 5.6}, .kp_kop = 2};

	GELA g = { .ikasle_kop = 2, .ikasleak = {ik1, ik2} };


	while ((auk = MENU_aukera_eskatu())) {
		g = MENU_menu(g, auk);
	}

	return EXIT_SUCCESS;
}
