#include "dlist.h"
#include "stdlib.h"
#include "list.h"

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

dlist createDlist(dlistValueType type){
    list_t *newlist = malloc(sizeof(list_t));
    if (newlist==NULL) return NULL;
    ll_init(newlist,(type_t)type);
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
	int (*cmps[LL_VALUE_TYPES])(void *a,void *b) = {int_cmp,double_cmp,string_cmp};
	if ((LL_INT<=t)&&(LL_STRING>=t)) return cmps[t](a,b);
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
	void (*cpys[LL_VALUE_TYPES])(void **dst,void *src) = {int_cpy,double_cpy,string_cpy};
	if ((LL_INT<=t)&&(LL_STRING>=t)) {
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
	node_t *flag = L->head;
	while ((flag)&&(ll_cmp(flag->value,v,L->type)>=0)) flag = flag->next;
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


void ll_remove(list_t *L,int k,FILE *stream){
	node_t *flag = L->head;
	for (int i=0;i<k;i++) flag = flag->next;
	fprintf(stream,"%s=",flag->key);
	switch (L->type){
		case LL_INT:
			fprintf(stream,"%d\n",*((int*)flag->value));
			break;
		case LL_DOUBLE:
			fprintf(stream,"%f\n",*((double*)flag->value));
			break;
		default:
			fprintf(stream,"%s\n",(char*)flag->value);
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
	char fname[100] = {0};
	char *prefixes[LL_PRINT_TYPES] = {"inc","dec","rand"};
	char *postfixes[LL_VALUE_TYPES] = {"_int.txt","_double.txt","_string.txt"};
	strcpy(fname,prefixes[L->pr]);
	strcat(fname,postfixes[L->type]);
	printf("writing %s\n",fname);
	FILE *fout = fopen(fname,"w+");
	if (L->pr==LL_INC){
		node_t *flag = L->tail;
		while (flag){
			fprintf(fout,"%s=",flag->key);
			switch (L->type){
				case LL_INT:
					fprintf(fout,"%d\n",*((int*)flag->value));
					break;
				case LL_DOUBLE:
					fprintf(fout,"%f\n",*((double*)flag->value));
					break;
				default:
					fprintf(fout,"%s\n",(char*)flag->value);
					break;
			}
			flag = flag->prev;
		}
	}
	else if (L->pr==LL_DEC){
		node_t *flag = L->head;
		while (flag){
			fprintf(fout,"%s=",flag->key);
			switch (L->type){
				case LL_INT:
					fprintf(fout,"%d\n",*((int*)flag->value));
					break;
				case LL_DOUBLE:
					fprintf(fout,"%f\n",*((double*)flag->value));
					break;
				default:
					fprintf(fout,"%s\n",(char*)flag->value);
					break;
			}
			flag = flag->next;
		}
	}
	else {
		while (!ll_isempty(L)){
			int randk = rand()%(L->size);
			ll_remove(L,randk,fout);
		}
	}
	fclose(fout);
}

void dlistSort(dlist_const dl, dlist listDst, dlistSortMethod method){
    list_t *src = (list_t*)dl;
    list_t *dst = (list_t*)listDst;
    ll_clean(dst);
    dst->pr = (print_t)method;
    for (node_t *flag=src->head;flag!=NULL;flag = flag->next)
        ll_insert(dst,flag->key,flag->value);
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