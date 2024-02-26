#include "vector_helper.h"
#include "product.h"

VECTOR_HELPER_CREATE_VECTOR(PRODUCT_VECTOR, PRODUCT)

void PRODUCT_destroy(PRODUCT product)
{
	free(product.name);
	free(product.desc);
}

void PRODUCT_VECTOR_destroy_full(PRODUCT_VECTOR * products)
{
	PRODUCT p;
	int len = PRODUCT_VECTOR_length(products);
	for (int i = 0; i < len; ++i) {
		p = PRODUCT_VECTOR_get(products, i);
		PRODUCT_destroy(p);
	}
}
