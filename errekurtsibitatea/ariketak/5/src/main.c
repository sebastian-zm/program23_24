#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int nire_strlen(const char *str);

int main(int argc, char **argv)
{
	if (argc != 2) {
		printf("Usage: %s str\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	int len;
	len = nire_strlen(argv[1]);
	printf("%d", len);
}

int nire_strlen(const char *str)
{
	if (*str == '\0') return 0;
	else return 1 + nire_strlen(str + 1);
}
