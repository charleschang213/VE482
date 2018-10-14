#include "ex3_sorter.h"

void sorter(char* argv[]){
    list_t L;
    char fname[STRING_MAX_LENGTH] = {0};
	char *filename = argv[1];
	strcpy(fname,filename);
    char *modename = argv[2];
    strtok(filename,"_");
    char *tname = strtok(NULL,".");
    type_t vtype = (strcmp(tname,"int")==0)?LL_INT:((strcmp(tname,"double")==0)?LL_DOUBLE:LL_STRING);
    print_t ptype = (strcmp(modename,"inc")==0)?LL_INC:LL_DEC;
    ll_init(&L,vtype);
    printf("reading %s\n",filename);
    FILE *fin = fopen(fname,"r+");
    printf("sorting elements\n");
    while (1){
	    char *k;
		unsigned long int msize = STRING_MAX_LENGTH;
   		void *v;
        int end = 0;
        switch(vtype){
            case LL_INT:
                v = malloc(sizeof(int));
				getdelim(&k,&msize,'=',fin);
				if (fscanf(fin,"%d\n",(int*)v)!=1) end = 1;
                break;
            case LL_DOUBLE:
                v = malloc(sizeof(double));
				getdelim(&k,&msize,'=',fin);
                if (fscanf(fin,"%lf\n",(double*)v)!=1) end = 1;
                break;
            default:
                v = malloc(STRING_MAX_LENGTH*sizeof(int));		
				getdelim(&k,&msize,'=',fin);
				if (fscanf(fin,"%s\n",(char*)v)!=1) end = 1;
                break;
        }
        if (end==1){
            free(v);
            break;
        }
		k[strlen(k)-1] = 0;
        ll_insert(&L,k,v);
        free(v);
    }
    fclose(fin);
    ll_print(&L,ptype);
}
