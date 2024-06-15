#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#include "teklak.h"
#include "erroberak.h"

void teklak_nagusia ()
{
    char tekla;

    printf("[ Kotxearen mugimendu kontrola ordenagailuko teklen bitartez : PC BERTSIOA ]\n");

    printf("GPIO hasieratzen...\n");
    init_hw();
    printf("[GALDERA] Mugitzeko sakatu (W,A,S,D), gelditzeko (X) edo amaitzeko (B): ");
    system("stty raw");
    do
    {
        tekla = fgetc(stdin);

        kotxearen_kontrola(tekla);

    } while (tekla != 'B' && tekla != 'b');
    system("stty cooked");
    printf("gpio amatatzen...\n");
}
// Raspberry Pi-an hasierako konfigurazioa
void init_hw()
{
    printf("Pinak konfiguratzen...\n");
}

void kotxearen_kontrola(char tekla)
{
    printf("[INFO] Kotxearen kontrola aktibatu da.\n");

    switch (tekla)
    {
    case 'w':
    case 'W':
        ERROBERA_aurrera(255);
        break;
    case 'a':
    case 'A':
        ERROBERA_ezkerrera(255);
        break;
    case 's':
    case 'S':
        ERROBERA_atzera(255);
        break;
    case 'd':
    case 'D':
        ERROBERA_eskumara(255);
        break;
    case 'x':
    case 'X':
        ERROBERA_gelditu();
        break;
    case 'b':
    case 'B':
        printf("[INFO] Kotxearen kontrola amaitzea erabaki da.\n");
	break;
    default:
        printf("[INFO] Tekla ez egokia.\n");
        break;
    }
}


void wait_seg(int seg)
{
	int i = 0;

	printf("Segundo %i itxoitera...\n", seg);

	for (i = 0; i < (50000 * seg); i++)
	{
	}
	printf("Denbora igarora %i itxoitera...\n", seg);

}
