#include <stdio.h>

int aurkitu(int val, int *zerrenda, int kop);

int main()
{
	int zerrenda[40] = {12, 13, 21, 31, 43, 51, 52, 55, 57};
	int kop = 9;
	int emaitzak[6] = {
		aurkitu(12, zerrenda, kop),
		aurkitu(-1, zerrenda, kop),
		aurkitu(32, zerrenda, kop),
		aurkitu(43, zerrenda, kop),
		aurkitu(57, zerrenda, kop),
		aurkitu(59, zerrenda, kop),
	};

	for (int i = 0; i < 6; ++i) {
		printf("%d\n", emaitzak[i]);
	}
	return 0;
}

int aurkitu(int val, int *zerrenda, int kop)
{
	int pos;
	int erdia = kop / 2;
	if (kop <= 0) {
		pos = -1;
	} else if (val == zerrenda[erdia]) {
		pos = erdia;
	} else if (val < zerrenda[erdia]) {
		pos = aurkitu(val, zerrenda, erdia);
	} else {
		pos = aurkitu(val, zerrenda + erdia + 1, kop - erdia - 1);
		if (pos > -1) pos = erdia + 1 + pos;
	}
	return pos;

}
