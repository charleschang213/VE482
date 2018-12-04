#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "dlist.h"

int main() {
//    freopen("case0.in", "r", stdin);
//    freopen("case0.ans", "w", stdout);

    char buffer[100], buffer2[100];
    int n;
    scanf("%d %s", &n, buffer);
    fprintf(stderr, "%d %s\n", n, buffer);

    // parse dlist type
    dlistValueType valueType = DLIST_UNKOWN;
    if (strcmp(buffer, "int") == 0) {
        valueType = DLIST_INT;
    } else if (strcmp(buffer, "str") == 0) {
        valueType = DLIST_STR;
    } else if (strcmp(buffer, "double") == 0) {
        valueType = DLIST_DOUBLE;
    } else {
        assert(0);
    }

    // init dlist
    dlist list1 = createDlist(valueType);
    dlist list2 = createDlist(valueType);

    for (int i = 0; i < n; i++) {
        scanf("%s", buffer);
        printf("%d\n", i);
        fprintf(stderr, "%d ", i);
        if (strcmp(buffer, "append") == 0) {
            scanf("%s %s", buffer, buffer2);
            dlistValue value;
            switch (valueType) {
                case DLIST_INT:
                    value.intValue = (int) strtol(buffer2, NULL, 10);
                    break;
                case DLIST_STR:
                    value.strValue = buffer2;
                    break;
                case DLIST_DOUBLE:
                    value.doubleValue = strtod(buffer2, NULL);
                    break;
                default:
                    assert(0);
            }
            fprintf(stderr, "append %s %s\n", buffer, buffer2);
            dlistAppend(list1, buffer, value);
        } else if (strcmp(buffer, "sort") == 0) {
            scanf("%s", buffer);
            dlistSortMethod sortMethod = DLIST_SORT_UNKOWN;
            if (strcmp(buffer, "inc") == 0) {
                sortMethod = DLIST_SORT_INC;
            } else if (strcmp(buffer, "dec") == 0) {
                sortMethod = DLIST_SORT_DEC;
            } else if (strcmp(buffer, "rand") == 0) {
                sortMethod = DLIST_SORT_RAND;
            } else {
                assert(0);
            }
            fprintf(stderr, "sort %s\n", buffer);
            dlistSort(list1, list2, sortMethod);
            dlistPrint(list1);
            dlistPrint(list2);
        } else if (strcmp(buffer, "empty") == 0) {
            int result = dlistIsEmpty(list1);
            fprintf(stderr, "empty\n");
            if (result == 0) {
                printf("false\n");
            } else {
                printf("true\n");
            }
        } else if (strcmp(buffer, "print") == 0) {
            fprintf(stderr, "print\n");
            dlistPrint(list1);
            dlistPrint(list2);
        } else {
            assert(0);
        }
    }
    dlistFree(list1);
    dlistFree(list2);
    return 0;
}
