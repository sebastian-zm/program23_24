#include <stdio.h>

int nire_strcat(char *dst, char *src);

int main() {
	char esaldi[100] = "Hau esaldi bat da.";
	nire_strcat(esaldi, " Eta hau beste bat.");

	puts(esaldi);
	return 0;
}

int nire_strcat(char *dst, const char *src)
{
	int len = nire_strlen(dst);
	dst += len;

	while (*src != '\0') {
		*dst = *src;
		++dst;
		++src;
		++len;
	}

	*dst = '\0';
	return len;
}

int nire_strlen(const char *str)
{
	int len = 0;

	while (*dst != '\0') {
		++dst;
		++len;
	}

	return len;
}
