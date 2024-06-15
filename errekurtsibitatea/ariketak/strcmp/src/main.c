#include <stdlib.h>
#include <stdio.h>

int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);

int main(int argc, char **argv)
{
	if (argc != 4) {
		printf("Usage: %s str1 str2 x\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	printf(
			"%d\n%d\n",
			strcmp(argv[1], argv[2]),
			strncmp(argv[1], argv[2], atoi(argv[3]))
	      );

}

int strcmp(const char *s1, const char *s2)
{
	if (*s1 > *s2) {
		return 1;
	} else if (*s1 < *s2) {
		return -1;
	} else if (*s1 == '\0') {
		return 0;
	} else {
		return strcmp(s1 + 1, s2 + 1);
	}
}

int strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0) {
		return 0;
	} else if (*s1 > *s2) {
		return 1;
	} else if (*s1 < *s2) {
		return -1;
	} else if (*s1 == '\0') {
		return 0;
	} else {
		return strncmp(s1 + 1, s2 + 1, n - 1);
	}
}
