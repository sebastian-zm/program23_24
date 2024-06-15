#ifndef FIND_BY_HELPER_H
#define FIND_BY_HELPER_H

#include <stddef.h>

int FIND_BY_HELPER_find(void* arr, size_t len, size_t size, int cmp(void*, void*));


#endif
