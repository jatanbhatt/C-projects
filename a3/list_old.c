#include "assignment3.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int randint(int min, int max) {
    return rand()%(max*2 -1) + (min+1);
}

SLnodePtr newNode(int key, SLnodePtr next)
{
    SLnodePtr newNode = (SLnodePtr)malloc(sizeof(SLnode));
    newNode->key = key;
    newNode->next = next;
    return newNode;
}

SLnodePtr merge(SLnodePtr A, SLnodePtr B)
{
    SLnodePtr sort = NULL;
    SLnodePtr head = NULL;
    if (A == NULL) return head;
    if (B == NULL) return head;

    if (A->key <= B->key)
    {
        head = A;
        A = A->next;
    }
    else
    {
        head = B;
        B = B->next;
    }
    sort = head;
    while (A != NULL && B != NULL)
    {
        if (A->key <= B->key)
        {
            sort->next = A;
            sort = A;
            A = sort->next;
        }
        else
        {
            sort->next = B;
            sort = B;
            B = sort->next;
        }
    }
    if (A == NULL) sort->next = B;
    if (B == NULL) sort->next = A;
    return head;
}

void freeSLlist(SLnodePtr L)
{
    SLnodePtr temp;
    while ((temp = L) != NULL)
    {
        L = L->next;
        free(temp);
    }
}
void freeHBlist(HBnodePtr L)
{
    HBnodePtr temp1;
    SLnodePtr temp2;

    while ((temp1 = L) != NULL)
    {
        while((temp2 = L->bottom) != NULL)
        {
            L->bottom = L->bottom->next;
            free(temp2);
        }
        L = L->next;
        free(temp1);
    }
}

void printHBlist(const HBnodePtr L)
{
    HBnodePtr currHorizontal = L; // FIGURE OUT HOW TO NAVIGATE DOWN
    while (currHorizontal != NULL)
    {
        printf("%d",currHorizontal->key);
        SLnodePtr currBottom = currHorizontal->bottom;
        while (currBottom != NULL)
        {
            printf(" -> %d",currBottom->key);
            currBottom = currBottom->next;
        }
        currHorizontal = currHorizontal->next;
        printf("\n|\n");
    }
}

void printSLlist(const SLnodePtr L)
{
    SLnodePtr curr = L;
    while (curr != NULL)
    {
        printf("%d -> ",curr->key);
        curr = curr->next;
    }
}

HBnodePtr createHBlist(int n, int m)
{
    HBnodePtr head1,newHorizontal;
    SLnodePtr head2,newBottom;

    head1 = NULL;

    for (int i = 0; i < n; i++)
    {
        head2 = NULL;
        newHorizontal = (HBnodePtr)malloc(sizeof(HBnode));
        newHorizontal->key = i;

        //GENERATE RANDOM # 0 to M
        for (int j = m; j > 0; j--)
        {
            head2 = newNode(j,head2);
        }
        newHorizontal->bottom = head2;
        newHorizontal->next = head1;
        head1 = newHorizontal;
    }
    return head1;
}

SLnodePtr flattenList(const HBnodePtr L)
{
    HBnodePtr temp;
    if (L == NULL) return NULL;
    while ((temp = L->next) != NULL)
    {
        temp = temp->next;
        L->bottom = merge(L->bottom,L->next->bottom);
        L->next = temp;
    }
    return L->bottom;
}

int main(void)
{
    HBnodePtr head = createHBlist(3,4);
    printHBlist(head);
    SLnodePtr sorted = flattenList(head);
    printSLlist(sorted);
    freeHBlist(head);
    freeSLlist(sorted);
}
