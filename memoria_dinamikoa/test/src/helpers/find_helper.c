#include <stddef.h>
#include "find_helper.h"

int FIND_HELPER_find(const void* findme, const void* arr, size_t len, size_t size, int eq(const void*, const void*))
{
	const char* arr_c = (const char *) arr;
	size_t i = 0;

	while (i < len && !eq(findme, arr_c)) {
		++i;
		arr_c += size;
	}

	if (i == len) i = -1;

	return i;
}
