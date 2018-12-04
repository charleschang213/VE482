#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "dlist.h"

typedef struct list_node{
	char *name;
	dlistValue value;
	struct list_node *next;
} ListNode;

typedef struct list{
	ListNode * first;
	ListNode * last;
	size_t length;
	dlistValueType type;
} List;

//Free
int list_Free(List *list){
	if(list->first){
		ListNode *tmp1 = list->first;
		ListNode *tmp2 = NULL;
		while(tmp1){
			if(list->type == DLIST_STR){
				free(tmp1->value.strValue);
			}
			tmp2 = tmp1->next;
			free(tmp1->name);
			free(tmp1);
			tmp1 = tmp2;
		}
	}
	list->first = NULL;
	list->length = 0;
	list->last = NULL;
	return 0;
}

int list_Free_all(List *list){
	list_Free(list);
	free(list);
	return 0;
}

static int int_inc(const void *e1, const void *e2) {
    int e1_tmp = ((ListNode *) e1)->value.intValue;
    int e2_tmp = ((ListNode *) e2)->value.intValue;
    return e1_tmp-e2_tmp;
}

static int int_dec(const void *e1, const void *e2) {
    return int_inc(e2, e1);
}

static int double_inc(const void *e1, const void *e2) {
    double e1_tmp = ((ListNode *) e1)->value.doubleValue;
    double e2_tmp = ((ListNode *) e2)->value.doubleValue;
    if (e1_tmp > e2_tmp) return 1;
    if (e1_tmp < e2_tmp) return -1;
    return 0;
}

static int double_dec(const void *e1, const void *e2) {
    return double_inc(e2, e1);
}

static int string_inc(const void *e1, const void *e2) {
    return strcmp(((ListNode *) e1)->value.strValue, ((ListNode *) e2)->value.strValue);
}

static int string_dec(const void *e1, const void *e2) {
    return strcmp(((ListNode *) e2)->value.strValue, ((ListNode *) e1)->value.strValue);
}

static int all_rand(const void *a, const void *b) {
    return (rand() % 3) - 1;
}

//Compare Method
static int (*const mode[3][3])(const void *, const void *) = {
        {all_rand, int_inc,    int_dec},
        {all_rand, string_inc, string_dec},
        {all_rand, double_inc, double_dec},
};

//Initalize the list
List *create_list(dlistValueType type){
	List *list = NULL;
	list = (List *)calloc(1, sizeof(List));
	list->type = type;
	list->first = NULL;
	list->last = NULL;
	list->length = 0;
	return list;
}

//Initiate the node
static ListNode * Node_Init(List *list, const char * str, dlistValue data){
	ListNode * new_node = malloc(sizeof(ListNode));
	new_node->next = NULL;
	//Copy the name
	char *name = malloc(strlen(str)+1);
	strcpy(name, str);
	new_node->name = name;
	if(list->type == DLIST_STR){
		char *new_value = malloc(strlen(data.strValue)+1);
		strcpy(new_value, data.strValue);
		new_node->value.strValue = new_value;
	}
	else{
		new_node->value = data;
	}
	return new_node;
}

//Add node and Append to the list
int add_Node(List *list, ListNode *ListNode){
	if(list->first == NULL){
		list->first = ListNode;
		list->last = ListNode;
	}
	else{
		list->last->next = ListNode;
		list->last = ListNode;
	}
    list->length++;
	return 0;
}

int append_Node(List *list, const char *str, dlistValue data){
	ListNode *new_node = Node_Init(list, str, data);
	add_Node(list, new_node);
	return 0;
}

//Sort Implementation
static void Sort_List(const List *list, List *new_list, int (*cmp)(const void *, const void *)){
	ListNode * tmp_Node_List = malloc(list->length * sizeof(ListNode));
	ListNode * head  = list->first;
	int i = 0;
	for(ListNode *tmp1 = head; tmp1!=NULL; tmp1 = tmp1->next){
		memcpy(tmp_Node_List + (i), tmp1, sizeof(ListNode));
	}
	qsort(tmp_Node_List, list->length, sizeof(ListNode), cmp);
	for(int i = 0; i < list->length; i++){
		append_Node(new_list, tmp_Node_List[i].name, tmp_Node_List[i].value);
	}
}

//Print the list to the file
void list_Print(const List *list, FILE *file){
	ListNode * head  = list->first;
	for(ListNode *tmp1 = head; tmp1!=NULL; tmp1 = tmp1->next){
		fprintf(file, "%s=", tmp1->name);
		switch(list->type){
			case DLIST_STR:
				fprintf(file, "%s\n", tmp1->value.strValue);
				break;
			case DLIST_INT:
				fprintf(file, "%d\n", tmp1->value.intValue);
				break;
			case DLIST_DOUBLE:
				fprintf(file, "%lf\n", tmp1->value.doubleValue);
				break;
			default:
				assert(0);
		}
	}
}

//Interface
dlist createDlist(dlistValueType type){
	if(type > DLIST_UNKOWN && type <= DLIST_DOUBLE){
		List *list = create_list(type);
		return list;
	}
	return NULL;
}

int dlistIsEmpty(dlist_const this){
	return ((const List *) this)->length == 0;
}

void dlistAppend(dlist this, const char *key, dlistValue value){
	append_Node(this, key, value);
}

void dlistSort(dlist_const this, dlist listDst, dlistSortMethod method){
	list_Free(listDst);
	dlistValueType type = ((const List *) (this))->type;
	if (type <= DLIST_UNKOWN || type > DLIST_DOUBLE) {
        return;
    }
    if (method <= DLIST_SORT_UNKOWN || method > DLIST_SORT_DEC) {
        return;
    }
	//Decide the method
    Sort_List(this, listDst, mode[type - 1][method - 1]);
}

void dlistPrint(dlist_const this){
	list_Print(this, stdout);
}

void dlistFree(dlist this){
	list_Free_all(this);
}
