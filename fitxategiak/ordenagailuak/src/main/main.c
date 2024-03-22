#include <stdlib.h>
#include "eskaera.h"
#include "filesystem_helper.h"

#define ESKAERAK_PATH "assets/db/eskaerak.txt"
#define AGINDUAK_PATH "assets/db/fabrikazioa_aginduak.txt"

ESKAERAK ariketa1(void);

int main()
{
	FILESYSTEM_HELPER_cd_base_path();


	ariketa1();


	return EXIT_SUCCESS;
}

ESKAERAK ariketa1(void)
{
	FILE* eskk_fp = fopen(ESKAERAK_PATH, "r");
	ESKAERAK eskk;

	if (eskk_fp) {
		eskk = ESKAERAK_irakurri(eskk_fp);
	} else {
		eskk = ESKAERAK_create();
		fprintf(stderr, "Ezin izan da %s fitxategia ireki.", ESKAERAK_PATH);
	}

	return eskk;
}
