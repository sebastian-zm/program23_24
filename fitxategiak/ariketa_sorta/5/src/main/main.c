#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main()
{
	char filename[PATH_MAX];
	long len = 0;
	printf("Eman fitxategiaren izena: ");
	fgets(filename, PATH_MAX, stdin);
	*strrchr(filename, '\n') = '\0';

	FILE* fd = fopen(filename, "r");
	
	while (fgetc(fd) != EOF) {
		++len;
	}

	printf("%s fitxategiak %ld byteko luzera du.\n", filename, len);

	fclose(fd);
}
