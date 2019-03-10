#include "singleListOper.h"

int main() {
    char option[10];
    singleListOper *slo = new singleListOper;
    slo->sp_Head = (student *)malloc(sizeof(student));
    slo->sp_Head->next = NULL;
    while(1) {
        printf("\n");
        printf("*******************\n");
        printf("  1. insert\n");
        printf("  2. delete\n");
        printf("  3. modify\n");
        printf("  4. quit\n");
        printf("*******************\n");
        printf("\n");
        gets(option);

        int select = atoi(option);

        switch (select) {
        case 1:
            slo->insertFunc();
            slo->displayFunc();
            break;
        case 2:
            slo->deleteFunc();
            slo->displayFunc();
            break;
        case 3:
            slo->modifyFunc();
            slo->displayFunc();
            break;
        case 4:
            printf("\n");
            return 0;
        default:
            printf(" Please try again !\n");
            break;
        }
    }
}