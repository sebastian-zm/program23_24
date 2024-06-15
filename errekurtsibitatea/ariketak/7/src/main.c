#include <stdlib.h>
#include <stdio.h>
#include <string.h>

float expon(float x);

int main(int argc, char **argv)
{
	if (argc != 2) {
		printf("Usage: %s n\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	float x = atoi(argv[1]);
	x = expon(x);
	printf("%f", x);
}

float expon(float x)
{
	if (x < 0.001) return 1 + x;
	float h = expon(x / 2);
	return h * h;
}
