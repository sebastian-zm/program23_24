#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void bistaratuAlderantziz(const char *str);
void bueltaAlderantziz(const char *str, char *strAlderantziz);

int main(int argc, char **argv)
{
	if (argc != 2) {
		printf("Usage: %s str\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	char kopia[strlen(argv[1]) + 1];

	bueltaAlderantziz(argv[1], kopia);
	puts(kopia);
	bistaratuAlderantziz(argv[1]);
}

void bistaratuAlderantziz(const char *str)
{
	if (*str == '\0') {
		return;
	} else {
		bistaratuAlderantziz(str + 1);
		printf("%c", *str);
	}
}

void bueltaAlderantziz(const char *str, char *strAlderantziz)
{
	size_t len = strlen(str);
	if (len == 0) {
		*strAlderantziz = '\0';
	}
	else {
		char str_cpy[len];
		strncpy(str_cpy, str, len);
		*strAlderantziz = str_cpy[len - 1];
		str_cpy[len - 1] = '\0';
		bueltaAlderantziz(str_cpy, strAlderantziz + 1);
	}
}
