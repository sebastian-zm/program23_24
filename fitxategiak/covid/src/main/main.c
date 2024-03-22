#include <math.h>
#include <stdio.h>
#include "gaixoa.h"
#include "herriak.h"
#include "gaixoa_db.h"
#include "gaixoa_view.h"
#include "filesystem_helper.h"

#define GAIXOAK_DB "assets/db/gaixoak.txt"
#define EMAITZAK_DB "assets/db/emaitzak.txt"
#define ARIKETA1_DB "assets/db/ariketa1.txt"
#define ARIKETA2_DB "assets/db/ariketa2.txt"
#define ARIKETA3_DB "assets/db/ariketa3.txt"

void ariketa3_printeatu(HERRIAK herriak);

int main()
{
	GAIXOA gaixoa;
	FILE* gaixoak = fopen(GAIXOAK_DB, "r");
	FILE* emaitzak = fopen(EMAITZAK_DB, "r");
	FILE* ariketa1_fitx;
	FILE* ariketa2_fitx;
	HERRIAK herriak = { .hiru = 0, .bi = 0, .bat = 0 };

	double karratuen_batura = 0.0;
	double batura = 0.0;
	double media;
	double desbiazio_estandarra;
	int n = 0; // Deitu positibo kopurua

	FILESYSTEM_HELPER_cd_base_path();

	ariketa1_fitx = fopen(ARIKETA1_DB, "w");

	do {
		gaixoa = GAIXOA_DB_gaixoa_kargatu(gaixoak, emaitzak);
		if (gaixoa.id != -1) {
			if (gaixoa.emaitza == GAIXOA_POSITIBOA) {
				batura += (double) gaixoa.adina;
				karratuen_batura += (double) gaixoa.adina * (double) gaixoa.adina;
				++n;
				GAIXOA_VIEW_izen_osoa_idatzi(gaixoa);
				herriak = HERRIAK_add(herriak, gaixoa.herria);
			} else {
				herriak = HERRIAK_add_zero(herriak, gaixoa.herria);
			}
			GAIXOA_DB_gaixoa_lotuta_idatzi(ariketa1_fitx, gaixoa);
		}
	} while (gaixoa.id != -1);

	fclose(ariketa1_fitx);
	fclose(emaitzak);
	fclose(gaixoak);

	if (n > 0) {
		media = batura / (double) n;
		desbiazio_estandarra = sqrt(karratuen_batura / (double) n - media * media);

		fprintf(stdout, "media: %f, desbiazio estandarra: %f\n", media, desbiazio_estandarra);

		ariketa2_fitx = fopen(ARIKETA2_DB, "w");
		fprintf(ariketa2_fitx, "media: %f, desbiazio estandarra: %f\n", media, desbiazio_estandarra);
		fclose(ariketa2_fitx);
	}

	ariketa3_printeatu(herriak);

	return 0;
}

void ariketa3_printeatu(HERRIAK herriak)
{
	int i = 0;
	FILE* fd = fopen(ARIKETA3_DB, "w");

	fputs("Gune beroa:\n", fd);
	fputs("Gune beroa:\n", stdout);

	while (i < herriak.lau) {
		fprintf(stdout, "%s\n", herriak.datuak[i]);
		fprintf(fd, "%s\n", herriak.datuak[i]);
		++i;
	}

	fputs("Abisu maila:\n", fd);
	fputs("Abisu maila:\n", stdout);

	while (i < herriak.bi) {
		fprintf(stdout, "%s\n", herriak.datuak[i]);
		fprintf(fd, "%s\n", herriak.datuak[i]);
		++i;
	}

	fputs("Maila berdea:\n", fd);
	fputs("Maila berdea:\n", stdout);

	while (i < herriak.zero) {
		fprintf(stdout, "%s\n", herriak.datuak[i]);
		fprintf(fd, "%s\n", herriak.datuak[i]);
		++i;
	}
}
