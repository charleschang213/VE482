#include "api.h"
#include "stdlib.h"
#include "list.h"

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