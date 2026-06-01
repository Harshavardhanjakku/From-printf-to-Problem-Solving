#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL,*temp,*newnode;
int main()
{

    if(start==NULL)
    {
        printf("\nThe list is Empty");
        printf("\nNow you can create a list");
        int n,info,i;
        printf("\nEnter the number of values U want to read:");
        scanf("%d",&n);
        if(n<0)
            printf("Invalid number");
        else
        {
            temp=(struct node*)malloc(sizeof(struct node));
            printf("Enter the value:");
            scanf("%d",&info);
            temp->data=info;
            temp->next=NULL;
            start=temp;
            for(i=2; i<=n; i++)
            {
                newnode=(struct node*)malloc(sizeof(struct node));
                printf("Enter the value:");
                scanf("%d",&info);
                temp->next=newnode;
                newnode->data=info;
                newnode->next=NULL;
                temp=newnode;
            }
        }
    }
    else
    {
        printf("\nThe list has been created");
    }

    if(start==NULL)
    {
        printf("The list is Empty");
    }
    else
    {
        temp=start;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}
