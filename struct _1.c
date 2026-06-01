#include<stdio.h>
    struct admission//using structure 
    {
        int rank,fees;
        char name[30],b[3];//branch
    };
    struct library//using pointers
    {
        int nop;
        char nob[30],an[30];//name of book and author name
        float rat,price;
    };
    struct student
    {
        int sub[10];
        float tot,avg;
        char name[30],res[10],gd;
    };
    struct employee
    {
        int id;
        char d[20],name[30];
        float bsal,nsal,hra,da,tax;
    };
int main()
{
    struct admission a;
    struct library l[10],*p;
    p=l;
    struct student st[100];
    struct employee e[5];
    int m,n,i=0,ch;
    printf("SR UNIVERSITY MANAGEMENT SYSTEM");
    while(i<6)
    {
        printf("\n\nPlease go through the choice\n");
        printf("\n1.Student Admission System");
        printf("\n2.Library Management System");
        printf("\n3.Student Result Management System");
        printf("\n4.Employee Salary Management System");
        printf("\n5.Exit");
        printf("\n\nEnter the Choice :");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\n\nSTUDENT ADMISSION SYSTEM ");
            printf("\n\nEnter the name of the student: ");
            scanf("%s",a.name);
            printf("Enter the branch:");
            scanf("%s",a.b);
            printf("Enter the Eamcet Rank:");
            scanf("%d",&a.rank);
            if(a.rank<10000)
                a.fees=0;
            else if(a.rank<15000)
                a.fees=95000;
            else if(a.rank<25000)
                a.fees=125000;
            else if(a.rank<35000)
                a.fees=150000;
            else
                a.fees=200000;
            printf("\n\nAdmission Details\n");
            printf("\nName:%s",a.name);
            printf("\nBranch:%s",a.b);
            printf("\nRank:%d",a.rank);
            printf("\nFees:%d",a.fees);
            break;
        case 2:
            printf("\n\nLIBRARY MANAGEMENT SYSTEM ");
            printf("\n\nEnter how many books u want to store:");
            scanf("%d",&n);
            printf("\nEnter the book Details\n");
            for (i=0; i<n; i++)
            {
                printf("Book:%d",i+1);
                printf("\n\nName of the book:");
                scanf("%s",p->nob+i);
                printf("\nName of the Author:");
                scanf("%s",p->an+i);
                printf("\nRating for the book:");
                scanf("%f",&p->rat+i);
                printf("\nNo of Pages:");
                scanf("%d",&p->nop+i);
                printf("\nPrice the book:");
                scanf("%f",&p->price+i);
            }
            for (i=0; i<n; i++)
            {
                printf("Book:%d",i+1);
                printf("\n\nName of the book:%s",p->nob+i);
                printf("\nName of the Author:%s",p->an+i);
                printf("\nRating for the book:%f",p->rat+i);
                printf("\nNo of Pages:%d",p->nop+i);
                printf("\nPrice the book:%f",p->price+i);
            }
            break;
        case 3:
            printf("\n\nSTUDENT RESULT MANAGEMENT SYSTEM ");
            printf("\n\nEnter the number of Students :");
            scanf("%d",&n);
            printf("\n\nEnter the number of Subjects :");
            scanf("%d",&m);
            printf("\nEnter the Student Details\n");
            for (i=0; i<n; i++)
            {
                printf("Student:%d",i+1);
                printf("\n\nName:");
                scanf("%s",p->nob+i);
                printf("\nHallticket Number:");
                scanf("%s",p->an+i);
                printf("\nRating for the book:");
                scanf("%f",&p->rat+i);
                printf("\nNo of Pages:");
                scanf("%d",&p->nop+i);
                printf("\nPrice the book:");
                scanf("%f",&p->price+i);
            }
            for (i=0; i<n; i++)
            {
                printf("Book:%d",i+1);
               printf("\n\nName of the book:%s",p->nob+i);
               printf("\nName of the Author:%s",p->an+i);
                printf("\nRating for the book:%f",p->rat+i);
                printf("\nNo of Pages:%d",p->nop+i);
                printf("\nPrice the book:%f",p->price+i);
            }
            break;
        case 5:
            goto exit;
        default:
            printf("\nInvalid Choice");
        }
    }
exit:
    {
        printf("\n\nTHANK YOU");
    }
}
void res(struct student s[100])
{


}