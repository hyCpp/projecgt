#include "singleListOper.h"

singleListOper::singleListOper()
{

}

singleListOper::~singleListOper()
{

}

void singleListOper::insertFunc(void)
{
    char temp[4];
    sp_Ptr = (student *)malloc(sizeof(student));
    printf(" Student name  : ");
    gets(sp_Ptr->name);
    printf(" Student score : ");
    gets(temp);
    sp_Ptr->score = atoi(temp);

    sp_Prev = sp_Head;
    sp_Current = sp_Head->next;

    while ((sp_Current != NULL) && (sp_Current->score > sp_Ptr->score)) {
        sp_Prev = sp_Current;
        sp_Current = sp_Current->next;
    }

    sp_Ptr->next = sp_Current;
    sp_Prev->next = sp_Ptr;
}

void singleListOper::deleteFunc(void)
{
    char del[20], ans[10];
    printf(" Delete student name : ");
    gets(del);
    sp_Prev = sp_Head;
    sp_Current = sp_Head->next;

    while((sp_Current != NULL) && (strcmp(sp_Current->name, del) != 0))
    {
        sp_Prev = sp_Current;
        sp_Current = sp_Current->next;
    }

    if (sp_Current != NULL) {
        printf(" Are you sure ? \n");
        gets(ans);
        if (strcmp(ans, "Y") ==0 || strcmp(ans, "y") ==0) {
            sp_Prev->next = sp_Current->next;
            free(sp_Current);
            printf(" Student \"%s\" has been deleted\n", del);
        }
    }
    else {
        printf(" Student %s not found\n",del);
    }
}

void singleListOper::modifyFunc(void)
{
    char n_temp[20], s_temp[4];
    printf(" Modify student name : ");
    gets(n_temp);
    sp_Current = sp_Head->next;

    while ((sp_Current != NULL) && (strcmp(sp_Current->name, n_temp) != 0))
    {
        sp_Prev = sp_Current;
        sp_Current = sp_Current->next;
    }

    if (sp_Current != NULL) {
        printf("*******************\n");
        printf(" Student name  : %s\n", sp_Current->name);
        printf(" Student score : %d\n", sp_Current->score);
        printf("*******************\n");
        printf(" Please enter new score : ");
        gets(s_temp);
        sp_Current->score = atoi(s_temp);
        printf(" Student \"%s\" has been modified\n", n_temp);
    }
    else {
        printf(" Student \"%s\" has been modified\n", n_temp);
    }
}

void singleListOper::sortFunc(void)
{

}

void singleListOper::anyKeyFunc(void)
{

}

void singleListOper::displayFunc(void)
{
    int count = 0;
    if (sp_Head->next == NULL) {
        printf(" NO Student record\n");
    }
    else {
        printf("\n");
        printf("  Name         Score\n");
        printf(" -------------------------\n");
        sp_Current = sp_Head->next;
        while (sp_Current != NULL) {
            printf("  %-10s %5d\n", sp_Current->name, sp_Current->score);
            count++;
            sp_Current = sp_Current->next;
        }
        printf(" -------------------------\n");
        printf(" Total %d record(s) found\n", count);
    }
}
