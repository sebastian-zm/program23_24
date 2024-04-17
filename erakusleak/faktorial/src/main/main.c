#include <stdio.h>

#define TRUE 1
#define FALSE 0

int faktoriala(int zenb, int *hel_emaitza);

int main()
{
	int zenbakia = 5;	// 5*4*3*2*1
	int egoera = FALSE;	//zenbakia < 0 FALSE  zenbakia  >= 0 TRUE ETA EMAITZA ONDO
	int emaitza = 0;

	egoera = faktoriala(zenbakia, &emaitza);
	if (egoera == TRUE)
		printf("%d! = %d\n", zenbakia, emaitza);
	else
		printf("[WARNING] %d ez dauka faktorialarik.\n ");

	egoera = faktoriala(-4, &emaitza);
	if (egoera == TRUE)
		printf("%d! = %d\n", zenbakia, emaitza);
	else
		printf("[WARNING] %d ez dauka faktorialarik.\n ");

	return 0;
}

int faktoriala(int zenb, int *hel_emaitza)
{
	int i = 0;
	int faktoriala = 1;
	int ret = FALSE;
	if (zenb >= 0) {
		ret = TRUE;
		for (i = 2; i <= zenb; i++) {
			//faktoriala = faktoriala*i;
			//ezin da faktorial aladagaia hel_emaitza
			faktoriala *= i;
		}
		*hel_emaitza = faktoriala;
		//return faktoriala;

	} else {
		ret = FALSE;
		faktoriala = 0;
		//*hel_emaitza = faktoriala;
		*hel_emaitza = 0;
	}

}
