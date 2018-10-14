#include "ex3_sorter.h"

void sorter(char* argv[]){
    list_t L;
    char *filename = argv[1];
    char *modename = argv[2];
    strtok(filename,"_");
    char *tname = strtok(NULL,".");
    type_t vtype = (strcmp(tname,"int")==0)?LL_INT:((strcmp(tname,"double")==0)?LL_DOUBLE:LL_STRING);
    print_t ptype = (strcmp(modename,"inc")==0)?LL_INC:LL_DEC;
    ll_init(&L,vtype);
    char k[STRING_MAX_LENGTH] = {0};
    void *v;
    printf("reading %s\n",filename);
    FILE *fin = fopen(filename,"r+");
    printf("sorting elements\n");
    while (1){
        int end = 0;
        switch(vtype){
            case LL_INT:
                v = malloc(sizeof(int));
                if (fscanf(fin,"%s=%d",k,(int*)v)!=2) end = 1;
                break;
            case LL_DOUBLE:
                v = malloc(sizeof(double));
                if (fscanf(fin,"%s=%d",k,(double*)v)!=2) end = 1;
                break;
            default:
                v = malloc(STRING_MAX_LENGTH*sizeof(int));
                if (fscanf(fin,"%s=%d",k,(char*)v)!=2) end = 1;
                break;
        }
        if (end==1){
            free(v);
            break;
        }
        ll_insert(&L,k,v);
        free(v);
    }
    fclose(fin);
    ll_print(&L,ptype);
}