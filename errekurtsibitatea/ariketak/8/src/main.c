#include <stdlib.h>
#include <stdio.h>

float nire_sin(float x);
float nire_cos(float x);

int main(int argc, char **argv)
{
	if (argc != 2) {
		printf("Usage: %s n\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	float x = atof(argv[1]);
	float y;
	y = nire_sin(x);
	x = nire_cos(x);
	printf("%f %f", x, y);
}

float nire_sin(float x)
{
	if (x < 0.0001) return x;
	float s = nire_sin(x / 2);
	float c = nire_cos(x / 2);
	return 2 * s * c;
}

float nire_cos(float x)
{
	if (x < 0.0001) return 1 - 0.5 * x * x;
	float s = nire_sin(x / 2);
	float c = nire_cos(x / 2);
	return c * c - s * s;
}
