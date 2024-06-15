#include <stdio.h>
#include <stdlib.h>

#include "teklak.h"
#include "jarraitzailea.h"
#include "erroberak.h"

int ezkerra_beltzean_dago(float sentsorearen_balioa)
{
    return sentsorearen_balioa > BELTZA_DEFAULT_EZKERRA ? 0 : 1;
}

int eskuma_beltzean_dago(float sentsorearen_balioa)
{
    return sentsorearen_balioa < BELTZA_DEFAULT_ESKUMA ? 0 : 1;
}

int ezkerreko_sentsorea_irakurri()
{
    return 0;
}

int eskumako_sentsorea_irakurri()
{
    return 0;
}

void lerro_jarraitzailea()
{
    int sents_ezkerra, sents_eskuma, ezkerreko_balorea, eskumako_balorea, amaituta = 0;

    printf("pigpio hasieratzen...\n");

    init_hw();

    while (amaituta == 0)
    {
        ezkerreko_balorea = ezkerreko_sentsorea_irakurri();
        eskumako_balorea = eskumako_sentsorea_irakurri();

        sents_ezkerra = ezkerra_beltzean_dago(ezkerreko_balorea);
        sents_eskuma = eskuma_beltzean_dago(eskumako_balorea);

        if (sents_ezkerra == 0 && sents_eskuma == 0)
        {
            ERROBERA_aurrera(200);
        }
        else if (sents_ezkerra == 1 && sents_eskuma == 0)
        {
            ERROBERA_ezkerrera(250);
        }
        else if (sents_ezkerra == 0 && sents_eskuma == 1)
        {
            ERROBERA_eskumara(250);
        }
        else if (sents_ezkerra == 1 && sents_eskuma == 1)
        {
            ERROBERA_gelditu();
        }

    }

    printf("pigpio amatatzen...\n");
}
