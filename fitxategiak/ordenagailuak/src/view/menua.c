#include "eskaera.h"
#include "eskaera_view.h"
#include "aginduak.h"

ESKAERAK MENUA(ESKAERAK eskk)
{
	const int buffer_kop = 100;
	char buffer[buffer_kop];
	do {
		printf("---MENUA---\n");
		printf("0. Irten\n");
		printf("1. Eskaera gehitu\n");
		printf("2. Eskaera aldatu\n");
		printf("3. Fabrikazio aginduak ikusi\n");

		printf("\nEman aukeraren zenbakia: ");
		fgets(buffer, buffer_kop, stdin);

		switch (buffer[0]) {
			case '0':
				break;
			case '1':
				ESKAERA esk = ESKAERA_VIEW_berria_eskatu();
				eskk = ESKAERAK_add(eskk, esk);
				break;
			case '2':
				int idx = ESKAERA_VIEW_idz_eskatu(eskk);
				if (idx != -1) {
					ESKAERA esk = ESKAERA_VIEW_berria_eskatu();
					eskk = ESKAERAK_set(eskk, esk, idx);
				} else {
					printf("Ez dago id hori duen eskaerarik.\n\n");
				}
			default:
				printf("Ez dizut ulertu. Saiatu berriro.\n\n");
		}

	} while (buffer[0] != '0');
}
