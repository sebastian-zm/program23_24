#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include "filesystem_helper.h"

bool FILESYSTEM_HELPER_get_base_path(char path[], int size)
{
	bool success = true;
	char *ptr = NULL;
	ssize_t nbytes = 0;
	// I have only tested this under GNU/Linux.
#ifdef __linux__
        nbytes = readlink("/proc/self/exe", path, size);
#elif defined(__FreeBSD__)
        nbytes = readlink("/proc/curproc/file", path, size);
#elif defined(__NetBSD__)
        nbytes = readlink("/proc/curproc/exe", path, size);
#elif defined(__sun)
        nbytes = readlink("/proc/self/path/a.out", path, size);
#endif 

	success = 0 < nbytes && nbytes < size;

	if (success) {
		path[nbytes] = '\0';
		ptr = strrchr(path, '/');

		if (ptr) {
			ptr[1] = '\0';
		}
	}

	return success;
}

bool FILESYSTEM_HELPER_cd_base_path()
{
	char path[PATH_MAX];
	bool ret = FILESYSTEM_HELPER_get_base_path(path, PATH_MAX);

	if (ret) {
		ret = 0 == chdir(path);
	}

	return ret;
}
