#ifndef LIST_HELPER_H
#define LIST_HELPER_H

typedef struct LIST_HELPER_NODE_s {
	void *data;
	struct LIST_HELPER_NODE_s *next;
} LIST_HELPER_NODE;

int LIST_HELPER_create(LIST_HELPER_NODE **list, void *data, LIST_HELPER_NODE *next);
void *LIST_HELPER_shift(LIST_HELPER_NODE **list);

#endif
