#include <stdio.h>
#include <string.h>
#include <limits.h>


int main()
{
	char filename[PATH_MAX];
	printf("Eman fitxategiaren izena: ");
	fgets(filename, PATH_MAX, stdin);
	*strrchr(filename, '\n') = '\0';

	FILE* fd = fopen(filename, "w");
	
	for (char c = 'a'; c <= 'z'; ++c) {
		fputc(c, fd);
	}

	fputc('\n', fd);

	for (char c = 'A'; c <= 'Z'; ++c) {
		fputc(c, fd);
	}

	fputc('\n', fd);

	fclose(fd);
}
