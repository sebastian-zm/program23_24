#ifndef MAGIC_HELPER_H
#define MAGIC_HELPER_H

#define MAGIC_HELPER_CREATE_MAGIC_HEADER(prefix, type) \
	typedef type prefix[1];\
	type prefix##_get(prefix m);\
	void prefix##_set(prefix m, type elem);\

#define MAGIC_HELPER_CREATE_MAGIC(prefix, type) \
	type prefix##_get(prefix m) {\
		return m[0];\
	}\
	void prefix##_set(prefix m, type elem) {\
		m[0] = elem;\
	}\

#endif
