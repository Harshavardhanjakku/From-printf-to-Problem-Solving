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
        if(n<=0)
            printf("");
        else
        {
            temp=(struct node*)malloc(sizeof(struct node));
            
            printf("Enter the value:");
            scanf("%d",&info);
            temp->data=info;
            temp->next=temp;
            
            start=temp;
            
            for(i=2; i<=n; i++)
            {
                newnode=(struct node*)malloc(sizeof(struct node));
                printf("Enter the value:");
                scanf("%d",&info);
                temp->next=newnode;
                newnode->data=info;
                newnode->next=start;
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
        printf("");
    }
    else
    {
        temp=start;
        
        do
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }while(temp!=start);
    }
}
