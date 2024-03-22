#include <stdio.h>
#include "elur_datu.h"
#include "elur_datu_db.h"
#include "elur_datu_view.h"
#include "filesystem_helper.h"

int main()
{
	FILESYSTEM_HELPER_cd_base_path();
	ELUR_DATUAK datuak = {.len = 0 };

	FILE *fd = fopen("assets/datuak/datuak.txt", "r");

	datuak = ELUR_DATU_DB_datuak_jaso(fd, datuak);

	ELUR_DATU_VIEW_datuak_ikusi(datuak);

	fclose(fd);
}
