#include <stdio.h>
#include <stdlib.h>

int konbinazio(int m, int n);

int main(int argc, char **argv)
{
	if (argc != 3) {
		printf("Usage: %s m n\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	int m = atoi(argv[1]);
	int n = atoi(argv[2]);

	printf("%d", konbinazio(m, n));
}

int konbinazio(int m, int n)
{
	if (n == 0 || m == n) {
		return 1;
	} else {
		return konbinazio(m - 1, n - 1) + konbinazio(m - 1, n);
	}
}
