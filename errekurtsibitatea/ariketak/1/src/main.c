#include <stdio.h>
#include <stdlib.h>

int batura(int n);

int main(int argc, char** argv)
{
	if (argc != 2) {
		printf("Usage: %s n", argv[0]);
		exit(EXIT_FAILURE);
	}
	int n = atoi(argv[1]);
	printf("%d", batura(n));
}

int batura(int n)
{
	return n > 0 ? n + batura(n - 1) : 0;
}
