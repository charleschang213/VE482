#include "ex3_ll.h"

void ll_init(list_t *L,type_t t){
	L->size = 0;
	L->type = t;
	L->head = L->tail = NULL;
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

void ll_insert(list_t *L,char *k,void *v){
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

void ll_print(list_t *L,print_t t){
	char fname[100] = {0};
	char *prefixes[LL_PRINT_TYPES] = {"inc","dec"};
	char *postfixes[LL_VALUE_TYPES] = {"_int.txt","_double.txt","_string.txt"};
	strcpy(fname,prefixes[t]);
	strcat(fname,postfixes[L->type]);
	printf("writing %s\n",fname);
	FILE *fout = fopen(fname,"w+");
	if (t==LL_INC){
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
	else{
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
	fclose(fout);
}
