#include "interface.h"
void user(){
    int ex = 0;
    while (ex==0){
        char *argv[3] = {malloc(STRING_MAX_LENGTH*sizeof(char)),malloc(STRING_MAX_LENGTH*sizeof(char)),malloc(STRING_MAX_LENGTH*sizeof(char))};
        strcpy(argv[0],"./cli");
        printf("Input the name of file(input exit to exit):\n> ");
        scanf("%s",argv[1]);
		if (strcmp(argv[1],"exit")==0){
			for (int i=0;i<3;i++) free(argv[i]);
			break;
		}
        printf("Input the sorting method:\n> ");
        scanf("%s",argv[2]);
        cli(3,argv);
        for (int i=0;i<3;i++) free(argv[i]);
    }
    printf("Bye!\n");
}
void cli(int argc,char *argv[]){
    dlist L,sortedL;
    char fname[STRING_MAX_LENGTH] = {0};
	char *filename = argv[1];
	strcpy(fname,filename);
    char *modename = argv[2];
    strtok(filename,"_");
    char *tname = strtok(NULL,".");
    dlistValueType vtype = (strcmp(tname,"int")==0)?DLIST_INT:((strcmp(tname,"double")==0)?DLIST_DOUBLE:DLIST_STR);
    dlistSortMethod ptype = (strcmp(modename,"inc")==0)?DLIST_SORT_INC:((strcmp(modename,"dec")==0)?DLIST_SORT_DEC:DLIST_SORT_RAND);
    L = createDlist(vtype);
	sortedL = createDlist(vtype);
    printf("reading %s\n",fname);
    FILE *fin = fopen(fname,"r+");
    printf("sorting elements\n");
    while (1){
	    char *k = malloc(STRING_MAX_LENGTH*sizeof(char));
		unsigned long int msize = STRING_MAX_LENGTH;
   		dlistValue v;
        int end = 0;
        switch(vtype){
            case DLIST_INT:
				getdelim(&k,&msize,'=',fin);
				if (fscanf(fin,"%d\n",&(v.intValue))!=1) end = 1;
                break;
            case DLIST_DOUBLE:
				getdelim(&k,&msize,'=',fin);
                if (fscanf(fin,"%lf\n",&(v.doubleValue))!=1) end = 1;
                break;
            default:	
				getdelim(&k,&msize,'=',fin);
				if (fscanf(fin,"%s\n",(v.strValue))!=1) end = 1;
                break;
        }
        if (end==1){
            free(k);
			break;
        }
		k[strlen(k)-1] = 0;
		dlistAppend(L,k,v);
		free(k);
    }
    fclose(fin);
	dlistSort(L,sortedL,ptype);
    dlistPrint(sortedL);
	dlistFree(L);
	dlistFree(sortedL);
}
