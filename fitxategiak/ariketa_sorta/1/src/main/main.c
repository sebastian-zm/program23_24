#include <stdio.h>
#include <string.h>
#include <limits.h>


int main()
{
	char filename[PATH_MAX];
	printf("Eman fitxategiaren izena: ");
	fgets(filename, PATH_MAX, stdin);
	*strrchr(filename, '\n') = '\0';

	FILE* fd = fopen(filename, "r");
	int kop = 0;
	int chr;

	while ((chr = getc(fd)) != EOF) {
		if (chr == 'a') {
			++kop;
		}
	}

	printf("'a' kopurua: %d\n", kop);

	fclose(fd);
}
