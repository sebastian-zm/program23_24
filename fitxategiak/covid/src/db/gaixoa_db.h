#ifndef GAIXOA_DB_H
#define GAIXOA_DB_H

#include <stdio.h>
#include "gaixoa.h"

GAIXOA GAIXOA_DB_gaixoa_kargatu(FILE* gaixoak, FILE* emaitzak);
int GAIXOA_DB_gaixoa_lotuta_idatzi(FILE* lotura, GAIXOA gaixoa);

#endif
