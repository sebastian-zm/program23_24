#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int palindromo_n(const char *ini, int n);
int palindromoaDa(const char *ini);

int main(int argc, char **argv)
{
	if (argc != 2) {
		printf("Usage: %s str\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	printf("%d", palindromoaDa(argv[1]));
}

int palindromoaDa(const char *ini)
{
	return palindromo_n(ini, strlen(ini));
}

int palindromo_n(const char *ini, int n)
{
	if (n <= 1) {
		return 1;
	} else if (ini[0] == ini[n-1]) {
		return palindromo_n(ini + 1, n - 2);
	} else {
		return 0;
	}
}
