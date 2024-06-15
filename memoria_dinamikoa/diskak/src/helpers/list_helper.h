#ifndef LIST_HELPER_H
#define LIST_HELPER_H

typedef struct LIST_HELPER_NODE_s {
	void *data;
	struct LIST_HELPER_NODE_s *next;
} LIST_HELPER_NODE;

int LIST_HELPER_create(LIST_HELPER_NODE **list, void *data, LIST_HELPER_NODE *next);
void *LIST_HELPER_shift(LIST_HELPER_NODE **list);
void LIST_HELPER_each(LIST_HELPER_NODE *list, void egin(void *));
void LIST_HELPER_eachWith(LIST_HELPER_NODE *list, void egin(void *, void *), void *data);
void *LIST_HELPER_find(LIST_HELPER_NODE *list, int test(void *));
void *LIST_HELPER_findWith(LIST_HELPER_NODE *list, int test(void *, void *), void *data);
void LIST_HELPER_findEach(LIST_HELPER_NODE *list, int test(void *), void egin(void *));
void LIST_HELPER_findWithEachWith(LIST_HELPER_NODE *list, int test(void *, void *), void *testData, void egin(void *, void *), void *eginData);
void LIST_HELPER_sortAsc(LIST_HELPER_NODE **list, int cmp(void *, void *));
void LIST_HELPER_sortDesc(LIST_HELPER_NODE **list, int cmp(void *, void *));
void LIST_HELPER_free(LIST_HELPER_NODE *list, void freeData(void *));
void LIST_HELPER_keepIf(LIST_HELPER_NODE **list, int test(void *), void freeData(void *));

#endif
