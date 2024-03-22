#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>

#define NUMBERS_MAX 100
#define STR_MAX 13

int int64cmp(const void* p1, const void* p2)
{
	int64_t i1 = *(int64_t *) p1;
	int64_t i2 = *(int64_t *) p2;

	return i1 < i2 ? -1 :
		i1 == i2 ? 0 :
		1;
}

int main()
{
	char filename[PATH_MAX];
	char buffer[STR_MAX];
	int64_t numbers[NUMBERS_MAX];
	int numbers_kop = 0;
	int i;
	printf("Eman fitxategiaren izena: ");
	fgets(filename, PATH_MAX, stdin);
	*strrchr(filename, '\n') = '\0';

	FILE* fd = fopen(filename, "r");
	int64_t num;
	
	while (numbers_kop < NUMBERS_MAX && fgets(buffer, STR_MAX, fd)) {
		num = 0;
		sscanf(buffer, "%ld", &num);
		numbers[numbers_kop] = num;
		++numbers_kop;
	}

	fclose(fd);

	qsort(numbers, numbers_kop, sizeof(numbers[0]), int64cmp);

	fd = fopen(filename, "w");

	for (i = 0; i < numbers_kop; ++i) {
		printf("%ld\n", numbers[i]);
		fprintf(fd, "%ld\n", numbers[i]);
	}

	fclose(fd);
}
