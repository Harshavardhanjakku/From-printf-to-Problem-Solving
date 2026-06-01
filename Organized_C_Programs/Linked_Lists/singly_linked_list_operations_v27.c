#include<stdio.h>
#include<stdlib.h>
struct node
{
    int id,age;
    char name[30],b[5];
    float att;
    struct node *next;
};
struct node *start=NULL,*temp,*newnode;
void create();
void display();
void insert();
void search();
int main()
{
    printf("STUDENT REGISTRATION SYSTEM");
    int ch;
    while(1)
    {
        printf("\n\n\n1.Create");
        printf("\n2.Display Student Details");

        printf("\n3.Search Student Details");
        printf("\n4.Insert Student Details");
        printf("\n5.Exit");
        printf("\n\nEnter the choice :");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            insert();
            break;

        case 5:
            exit(0);
            break;
        default:
            printf("\nInvalid Number");
        }
    }
}
void create()
{

    if(start==NULL)
    {
        printf("\nNo Students Registerd . Register Now...");
        int n,info,i;
        printf("\n\nEnter the Number of students to Register:");
        scanf("%d",&n);
        if(n<0)
            printf("Invalid number");
        else
        {   i=1;
            printf("\n\nEnter the Details of student %d:\n",i);
            temp=(struct node*)malloc(sizeof(struct node));
            printf("Enter the ID:");
            scanf("%d",&temp->id);
            printf("Enter Full name:");
            scanf("%s",&temp->name);
            printf("Enter the Branch:");
            scanf("%s",&temp->b);
            printf("Enter the age:");
            scanf("%d",&temp->age);
            printf("Enter the attendance:");
            scanf("%f",&temp->att);
            temp->next=NULL;
            start=temp;
            for(i=2; i<=n; i++)
            {   printf("\n\nEnter the Details of student %d:\n",i);
                newnode=(struct node*)malloc(sizeof(struct node));
                printf("Enter the ID:");
                scanf("%d",&newnode->id);
                printf("Enter Full name:");
                scanf("%s",&newnode->name);
                printf("Enter the Branch:");
                scanf("%s",&newnode->b);
                printf("Enter the age:");
                scanf("%d",&newnode->age);
                printf("Enter the attendance:");
                scanf("%f",&newnode->att);
                temp->next=newnode;
                newnode->next=NULL;
                temp=newnode;
            }
        }
    }
    else
    {
        printf("\nThe list has been created");
    }
}
void search()
{
    int roll,flag=0;
    printf("Enter the ID to Search:");
    scanf("%d",&roll);
    temp=start;
    while(temp!=NULL)
    {
        if(temp->id==roll)
        {
            flag=1;
            break;
        }
        temp=temp->next;
    }
    if(flag==0||temp==NULL)
        printf("\nNO Student Registered With I'd %d",roll);
    else
    {
        printf("\n\nDetails of Student are...");
        printf("\n\nID:%d",temp->id);
        printf("\nFull name:%s",temp->name);
        printf("\nBranch:%s",temp->b);
        printf("\nAge:%d",temp->age);
        printf("\nAttendance:%.2f",temp->att);
    }
}
void insert()
{
    printf("\n\nEnter the Details of student :\n");
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the ID:");
    scanf("%d",&newnode->id);
    printf("Enter Full name:");
    scanf("%s",&newnode->name);
    printf("Enter the Branch:");
    scanf("%s",&newnode->b);
    printf("Enter the age:");
    scanf("%d",&newnode->age);
    printf("Enter the attendance:");
    scanf("%f",&newnode->att);
    if(start==NULL)
    {
        newnode->next=NULL;
        start=newnode;
    }
    else
    {
        temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=NULL;
    }
    printf("\nStudent is Successfully Registered.");
}
void display()
{

    if(start==NULL)
    {
        printf("\nNo Students Registerd ");
    }
    else
    {
        printf("\n\n\nDisplaying Students information...");
        temp=start;
        while(temp!=NULL)
        {
            printf("\n\nID:%d",temp->id);
            printf("\nFull name:%s",temp->name);
            printf("\nBranch:%s",temp->b);
            printf("\nAge:%d",temp->age);
            printf("\nAttendance:%.2f",temp->att);
            temp=temp->next;
        }
    }
}