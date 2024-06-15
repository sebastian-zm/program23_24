#include <stdlib.h>
#include <stdio.h>
#include "console_helper.h"
#include "kafe.h"

KAFE *KAFE_sortu()
{
	KAFE *kaf = malloc(sizeof *kaf);
	CONSOLE_HELPER_osoa_eskatu(&kaf->data.year, "Eman urtea: ", KAFE_GAIZKI);
	CONSOLE_HELPER_osoa_tartean_eskatu(&kaf->data.month, 1, 12, "Eman hilabetea (1-12): ", KAFE_GAIZKI);
	CONSOLE_HELPER_osoa_tartean_eskatu(&kaf->data.day, 1, 31, "Eman eguna (1-31): ", KAFE_GAIZKI);
	CONSOLE_HELPER_float_eskatu(&kaf->kiloak, "Eman kiloak: ", "Ez dizut ulertu. Saiatu berriro.");
	CONSOLE_HELPER_float_tartean_eskatu(&kaf->kafeina, 0.0f, 100.0f, "Eman kafeina (0-100): ", "Ez dizut ulertu. Saiatu berriro.");

	return kaf;
}

void KAFE_bistaratu(KAFE *kaf)
{
	printf("Eguna: %d/%d/%d Kiloak: %f Kafeina: %f%%\n",
			kaf->data.year, kaf->data.month, kaf->data.day, kaf->kiloak, kaf->kafeina);
}
