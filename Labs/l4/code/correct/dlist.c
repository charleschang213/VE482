#include "dlist.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define type_t int
#define LL_INT 0
#define LL_STRING 1
#define LL_DOUBLE 2
#define LL_VALUE_TYPES 3

#define print_t int
#define LL_INC 1
#define LL_DEC 2
#define LL_RAND 0
#define LL_PRINT_TYPES 3

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

void ll_init(list_t *L,type_t t){
	L->size = 0;
	L->type = t;
	L->head = L->tail = NULL;
	L->pr = LL_INC;
}
void ll_clean(list_t *L){
	node_t *tmp = L->head;
	while (tmp){
		node_t *ttmp = tmp->next;
		free(tmp->value);
		free(tmp->key);
		free(tmp);
		tmp = ttmp;
	}
	ll_init(L,L->type);
}

int ll_isempty(list_t *L){
	return (L->size==0);
}

int int_cmp(void *a,void *b){
	int *inta = (int*)a;
	int *intb = (int*)b;
	int c = *inta-*intb;
	return (c<0)?-1:((c==0)?0:1);
}
int double_cmp(void *a,void *b){
	double *doublea = (double*)a;
	double *doubleb = (double*)b;
	double c = *doublea-*doubleb;
	return (c<0)?-1:((c==0)?0:1);
}
int string_cmp(void *a,void *b){
	char *chara = (char*)a;
	char *charb = (char*)b;
	int c =  strcmp(chara,charb);
	return (c<0)?-1:((c==0)?0:1);
}
int ll_cmp(void *a,void *b,type_t t){
	int (*cmps[LL_VALUE_TYPES])(void *a,void *b) = {int_cmp,string_cmp,double_cmp};
	if ((LL_INT<=t)&&(LL_DOUBLE>=t)) return cmps[t](a,b);
	return -2;
}

void int_cpy(void **dst,void *src){
	(*dst) = malloc(sizeof(int));
	memcpy(*dst,src,sizeof(int));
}
void double_cpy(void **dst,void *src){
	(*dst) = malloc(sizeof(double));
	memcpy(*dst,src,sizeof(double));
}
void string_cpy(void **dst,void *src){
	int len = strlen(src);
	(*dst) = malloc((len+1)*sizeof(char));
	strcpy((char*)(*dst),(char*)(src));
}
int value_cpy(void **dst,void *src,type_t t){
	void (*cpys[LL_VALUE_TYPES])(void **dst,void *src) = {int_cpy,string_cpy,double_cpy};
	if ((LL_INT<=t)&&(LL_DOUBLE>=t)) {
		cpys[t](dst,src);
		return 0;
	}
	return -2;
}


node_t *ll_search(list_t *L,void *v){
	node_t *flag = L->head;
	while ((flag)&&(ll_cmp(v,flag->value,L->type)!=0)) flag = flag->next;
	return flag;
}

void ll_insert(list_t *L,const char *k,void *v){
	node_t *newnode = malloc(sizeof(node_t));
	newnode->key = malloc((strlen(k)+1)*sizeof(char));
	strcpy(newnode->key,k);
	value_cpy(&(newnode->value),v,L->type);
	L->size++;
	if (L->size==1){
		newnode->prev = newnode->next=NULL;
		L->head = L->tail = newnode;
		return;
	}
	//node_t *flag = L->head;
    
    newnode->prev=L->tail;
    newnode->next=NULL;
    L->tail->next=newnode;
    L->tail = newnode;
	/*while ((flag)&&(ll_cmp(flag->value,v,L->type)>=0)) flag = flag->next;
	if (flag==L->head){
		newnode->prev = NULL;
		newnode->next=L->head;
		L->head->prev = newnode;
		L->head = newnode;
	}
	else if (flag==NULL){
		newnode->prev=L->tail;
		newnode->next=NULL;
		L->tail->next=newnode;
		L->tail = newnode;
	}
	else {
		newnode->prev = flag->prev;
		newnode->next = flag;
		flag->prev->next = newnode;
		flag->prev=newnode;
	}*/
	return;
}

void ll_insert_ordered(list_t *L,const char *k,void *v,print_t method){
	node_t *newnode = malloc(sizeof(node_t));
	newnode->key = malloc((strlen(k)+1)*sizeof(char));
	strcpy(newnode->key,k);
	value_cpy(&(newnode->value),v,L->type);
	L->size++;
	if (L->size==1){
		newnode->prev = newnode->next=NULL;
		L->head = L->tail = newnode;
		return;
	}
	node_t *flag = L->head;
    if (method==LL_INC)
	    while ((flag)&&(ll_cmp(flag->value,v,L->type)<=0)) flag = flag->next;
    else if (method==LL_DEC)
        while ((flag)&&(ll_cmp(flag->value,v,L->type)>=0)) flag = flag->next;
    else{
        int times = rand()%L->size;
        for (int i=0;i<times;i++) flag = flag->next;
    } 
	if (flag==L->head){
		newnode->prev = NULL;
		newnode->next=L->head;
		L->head->prev = newnode;
		L->head = newnode;
	}
	else if (flag==NULL){
		newnode->prev=L->tail;
		newnode->next=NULL;
		L->tail->next=newnode;
		L->tail = newnode;
	}
	else {
		newnode->prev = flag->prev;
		newnode->next = flag;
		flag->prev->next = newnode;
		flag->prev=newnode;
	}
	return;
}


void ll_remove(list_t *L,int k){
	node_t *flag = L->head;
	for (int i=0;i<k;i++) flag = flag->next;
	printf("%s=",flag->key);
	switch (L->type){
		case LL_INT:
			printf("%d\n",*((int*)flag->value));
			break;
		case LL_DOUBLE:
			printf("%f\n",*((double*)flag->value));
			break;
		default:
			printf("%s\n",(char*)flag->value);
			break;
	}
	L->size--;
	if (L->size==0){
		L->head = L->tail = NULL;
	}
	else if (flag==L->head){
		L->head = flag->next;
		L->head->prev = NULL;
	}
	else if (flag==L->tail){
		L->tail = flag->prev;
		L->tail->next = NULL;
	}
	else {
		flag->prev->next = flag->next;
		flag->next->prev = flag->prev;
	}
	free(flag->value);
	free(flag->key);
	free(flag);
	return;
}

void ll_print(list_t *L){
	/*if (L->pr==LL_INC){
		node_t *flag = L->tail;
		while (flag){
			printf("%s=",flag->key);
			switch (L->type){
				case LL_INT:
					printf("%d\n",*((int*)flag->value));
					break;
				case LL_DOUBLE:
					printf("%f\n",*((double*)flag->value));
					break;
				default:
					printf("%s\n",(char*)flag->value);
					break;
			}
			flag = flag->prev;
		}*/
	//}
	//else if (L->pr==LL_DEC){
		node_t *flag = L->head;
		while (flag){
			printf("%s=",flag->key);
			switch (L->type){
				case LL_INT:
					printf("%d\n",*((int*)flag->value));
					break;
				case LL_DOUBLE:
					printf("%f\n",*((double*)flag->value));
					break;
				default:
					printf("%s\n",(char*)flag->value);
					break;
			}
			flag = flag->next;
		}
	/*}
	else {
		while (!ll_isempty(L)){
			int randk = rand()%(L->size);
			ll_remove(L,randk);
		}
	}*/
}


dlist createDlist(dlistValueType type){
    list_t *newlist = malloc(sizeof(list_t));
    if (newlist==NULL) return NULL;
    ll_init(newlist,(type_t)type-1);
    return (dlist)newlist;
}
int dlistIsEmpty(dlist_const dl){
    list_t *thelist = (list_t*)dl;
    return ll_isempty(thelist);
}

void dlistAppend(dlist dl, const char *key, dlistValue value){
    list_t *thelist = (list_t*)dl;
    switch (thelist->type){
        case LL_INT:
            ll_insert(thelist,key,(void*)&value.intValue);
            break;
        case LL_DOUBLE:
            ll_insert(thelist,key,(void*)&value.doubleValue);
            break;
        default:
            ll_insert(thelist,key,(void*)value.strValue);
            break;
    }   
}


void dlistSort(dlist_const dl, dlist listDst, dlistSortMethod method){
    list_t *src = (list_t*)dl;
    list_t *dst = (list_t*)listDst;
    ll_clean(dst);
    dst->pr = (print_t)method;
    for (node_t *flag=src->head;flag!=NULL;flag = flag->next)
        ll_insert_ordered(dst,flag->key,flag->value,(print_t)method-1);
}

void dlistPrint(dlist_const dl){
    list_t *thelist = (list_t*)dl;
    ll_print(thelist);
}

void dlistFree(dlist dl){
    list_t *thelist = (list_t*)dl;
    ll_clean(thelist);
    free(dl);
}
