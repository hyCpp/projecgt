#include "doubleList.h"

doubleList::doubleList()
{

}

doubleList::~doubleList()
{

}

void doubleList::initialize()
{
    ptr = (student *)malloc(sizeof(student));
    strcpy(ptr->name, "0");
    ptr->Left = ptr;
    ptr->right = ptr;
    head = ptr;
    tail = ptr;
}

void doubleList::deleteFunc()
{
    char delName[20],ans[4];

    if (head->right == head) {
        printf("\n No Student record\n");
    }
    else {
        printf("\n Delete student name : ");
        gets(delName);
        prev = head;
        current = head->right;

        while ((current != head) && (strcmp(current->name, delName) != 0)) {
            prev = current;
            current = current->right;
        }

        if(current != head) {
            printf(" Are you sure ? \n");
            gets(ans);
            if (strcmp(ans,"Y") || strcmp(ans, "y")) {
                prev->right = current->right;
                current->right->Left = prev;
                free(current);
                printf("\n Student %s has been deleted\n", delName);
            }
        }
        else {
            printf("\n Student %s not found\n", delName);
        }
    }
}

void doubleList::displayFunc()
{
    int count = 0;

    if (head->right == head) {
        printf("\n No student record\n");
    }
    else {
        printf("\n\n Name        Score\n");
        printf("----------------------------------\n");
        current = head->right;

        while (current != head) {
            printf("  %-10s  %3d\n", current->name, current->score);
            count++;
            current = current->right;
        }
        printf("-----------------------------------\n");
        printf(" Total %d record(s) found\n", count);
    }
}

void doubleList::insertFunc()
{
    char temp[4];
    ptr = (student *)malloc(sizeof(student));
    printf("\n Student name  : ");
    gets(ptr->name);
    printf(" Student score : ");
    gets(temp);
    ptr->score = atoi(temp);

    prev = head;
    current = head->right;

    while ((current != head) && (current->score >= ptr->score))
    {
        prev = current;
        current = current->right;
    }

    ptr->right = current;
    ptr->Left = prev;
    prev->right = ptr;
    current->Left = ptr;
}

void doubleList::modifyFunc()
{
    char score[20], name[20];
    if (head->right == head) {
        printf("\n No student record\n");
    }
    else {
        printf("Please input modify student name : \n");

        gets(name);
        prev = head;
        current = head->right;
        while ((current != NULL) && (strcmp(current->name, name) != 0)) {
            prev = current;
            current = current->right;
        }

        if (current != head) {
            printf("\n ***********************\n");
            printf(" Student name  : %s\n", current->name);
            printf(" Student score : %d\n", current->score);
            printf("\n ***********************\n");
            printf(" Please enter new score : ");
            gets(score);
            current->score = atoi(score);
            printf("\n %s student record(s) modified\n", score);
        }
        else {
            printf(" No found student record !\n");
        }
    }
}
