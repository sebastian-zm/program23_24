#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#include "erroberak.h"
#include "remote_controller.h"
#include "bluetooth.h"


void bluetooth_nagusia()
{
	int fd;
		char fitx[PATH_MAX];
		printf("Eman fitxategiaren izena: ");
		fgets(fitx, PATH_MAX, stdin);
		*strrchr(fitx, '\n') = '\0';
		fd = init_ble(fitx);

		if (fd > 0) {
			printf("Pigpio Hasieratzen...\n");
			ERROBERA_init();
			FITXATEGIA_main(fd);
			printf("Pigpio Amatatzen...\n");
		}
}
void FITXATEGIA_main(int fd)
{
	char c;
	write(fd, "S", 1);
	while (c != 'B') {
		read(fd, &c, sizeof c);
		switch (c) {
			case 'W':
				printf("Aurrera joaten...\n");
				break;
			case 'A':
				printf("ezkerrera joaten...\n");
				break;
			case 'D':
				printf("eskuinera joaten...\n");
				break;
			case 'S':
				printf("atzera joaten...\n");
				break;
			case 'P':
				printf("gelditzen...\n");
				break;
		}
	}
	write(fd, "B", 1);
}
