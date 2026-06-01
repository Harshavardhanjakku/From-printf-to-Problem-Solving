#include <stdio.h>
#include <stdlib.h>
struct Node {
    int info;
    struct Node* prev;
    struct Node* next;
};
struct Node * start = NULL,*temp,*newnode;
void create()
{
    int total, item;
    printf("Enter the no of nodes");
    scanf("%d", &total);
    temp = (struct Node*)malloc(sizeof(struct Node));
    scanf("%d", &item);
    temp->info = item;
    temp->next = temp;
    temp->prev = temp;
    start = temp;

    for (int i=2; i<=total; i++) {
        newnode = (struct Node*)malloc(sizeof(struct Node));

        scanf("%d",&item);

        newnode->info=item;
        temp->next = newnode;
        newnode->next=start;
        newnode->prev=temp;

        temp = newnode;
    }

}

void disp()
{
    if (start == NULL) {
        printf("No element present");

    }

    temp = start;
    do
    {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    while (temp !=start) ;

}

void delete_end()
{
    struct Node *temp,*pr;
    if(start==NULL) {
        return;
    }
    if (start->next== NULL) {
        start=NULL;
    }
    else
    {
        temp=start;
        while(temp->next!=NULL) {
            pr=temp;
            temp=temp->next;
        }
        pr->next=NULL;
    }
}
void revdisp()
{printf("__________");
    temp = start;
    do
    {

        temp = temp->next;
    }
    while (temp->next !=start);
    do
    {
        printf("%d ", temp->info);
        temp = temp->prev;
    }
    while(temp!=start);
}
int main()
{
    create();
    disp();
    revdisp();
}