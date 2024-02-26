#ifndef PRODUCT_H
#define PRODUCT_H

#include "vector_helper.h"

typedef struct {
	char *name;
	char *desc;
	int stock;
} PRODUCT;

VECTOR_HELPER_CREATE_VECTOR_HEADER(PRODUCT_VECTOR, PRODUCT)
#endif				// PRODUCT_H
