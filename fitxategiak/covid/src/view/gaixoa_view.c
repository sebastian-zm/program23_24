#include <stdio.h>
#include "gaixoa.h"
#include "gaixoa_view.h"

int GAIXOA_VIEW_izen_osoa_idatzi(GAIXOA gaixoa)
{
	return 0 > fprintf(stdout, "%s %s\n", gaixoa.izena, gaixoa.abizena);
}
