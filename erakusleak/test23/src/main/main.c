#include <stdio.h>
#include <string.h>

typedef struct {
	int id;
	char izena[10];
	double marks;

} PERTSONA;

int PERTSONA_kenduArraitik(PERTSONA p, PERTSONA * pertsonak, int kop);
int PERTSONA_eq(PERTSONA p1, PERTSONA p2, double epsilon);

int main()
{
	PERTSONA p1 = { 2, "Iker", 8.7 };

	PERTSONA pertsonak[] = {
		{1, "Jon", 6.7},
		{2, "Iker", 7.7},
		{3, "Oier", 8.7},
		{4, "Iratxe", 6.9},
	};

	int kop = 4;

//Bukatu main-a
	puts(pertsonak[0].izena);
	puts(pertsonak[1].izena);
	printf("%d", kop);

	kop = PERTSONA_kenduArraitik(p1, pertsonak, kop);

	puts(pertsonak[0].izena);
	puts(pertsonak[1].izena);
	printf("%d", kop);

	return 0;
}

int PERTSONA_kenduArraitik(PERTSONA p, PERTSONA * pertsonak, int kop)
{
//Funtzio honetan ezin da []-rik erabili

//gauzatu funtzioa

	int aurkitua = 0;
	for (int i = 0; i < kop; ++i) {
		if (aurkitua) {
			*(pertsonak + i) = *(pertsonak + i + 1);
		} else {
			aurkitua = PERTSONA_eq(p, *(pertsonak + i), 0);
			if (aurkitua) {
				--i;
				--kop;
			}
		}
	}

	return kop;
}

int PERTSONA_eq(PERTSONA p1, PERTSONA p2, double epsilon)
{
	int eq = p1.id == p2.id;
	if (eq) {
		int mark_ratio = p1.marks / p2.marks;
		eq = mark_ratio <= 1 + epsilon && mark_ratio >= 1 - epsilon;
	}
	eq = eq && !strcmp(p1.izena, p2.izena);

	return eq;
}
