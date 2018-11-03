#ifndef EX3_LL_H
#define EX3_LL_H

#define type_t int
#define LL_INT 0
#define LL_DOUBLE 1
#define LL_STRING 2
#define LL_VALUE_TYPES 3

#define print_t int
#define LL_INC 0
#define LL_DEC 1
#define LL_RAND 2
#define LL_PRINT_TYPES 3

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct _node_ {
	char *key;
	void *value;
	struct _node_ *next,*prev;
}node_t;

typedef struct _list_t_ {
	int size;
	type_t type;
	print_t pr;
	node_t *head,*tail;
}list_t;

void ll_init(list_t *L,type_t t);
void ll_clean(list_t *L);

int ll_isempty(list_t *L);

int int_cmp(void *a,void *b);
int double_cmp(void *a,void *b);
int string_cmp(void *a,void *b);
int ll_cmp(void *a,void *b,type_t t);

void int_cpy(void **dst,void *src);
void double_cpy(void **dst,void *src);
void string_cpy(void **dst,void *src);
int value_cpy(void **dst,void *src,type_t t);

node_t *ll_search(list_t *L,void *v);

void ll_insert(list_t *L,const char* k,void* v);
void ll_remove(list_t *L,int k,FILE *stream);

void ll_print(list_t *L);

#endif


