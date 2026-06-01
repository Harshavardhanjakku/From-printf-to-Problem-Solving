#include<stdio.h>
#include<string.h>
struct admission//using structure
{
    int rank,fees;
    char name[30],b[3];//branch
};
struct library//using pointers
{
    char nob[30],an[30];//name of book and author name
    int nop;
    float rat,price;
};
struct student
{
    int sub[3];
    float tot,avg;
    char name[30],htno[30],gd;
};
struct Organisation 

{
      char on[20];//org nmae
      char ono[20];
      struct Employee 
           {
            int eid;
            char en[20];
            int sal;
           }emp;
     
};
int main()
{
    struct admission a;
    struct library l[10],*p;
    p=&l;
    struct student st[100];
    struct Organisation org;
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
            printf("\nEnter the book Details\n");
                printf("\n\nName of the book:");
                scanf("%s",&p->nob);
                printf("\nName of the Author:");
                scanf("%s",&p->an);
                printf("\nNo of Pages:");
                scanf("%d",&p->nop);
                printf("\nRating for the book:");
                scanf("%f",&p->rat);
                printf("\nPrice the book:");
                scanf("%f",&p->price);
            printf("\nThe details of Bokk are:\n");
                printf("\n\nName of the book:%s",p->nob);
                printf("\nName of the Author:%s",p->an);
                printf("\nNo of Pages:%d",p->nop);
                printf("\nRating for the book:%f",p->rat);
                printf("\nPrice the book:%f",p->price);
  
            break;
        case 3:
            printf("\n\nSTUDENT RESULT MANAGEMENT SYSTEM ");
            printf("\n\nEnter the number of Students :");
            scanf("%d",&n);
            printf("\nEnter the Student Details\n");
           for (i=0; i<n; i++)
           {
               printf("Student:%d",i+1);
               printf("\n\nName:");
               scanf("%s",st[i].name);
               printf("\nHallticket Number:");
               scanf("%s",st[i].htno);
               printf("\nSubject1 marks:");
               scanf("%d",st[i].sub[0]);
            printf("\nSubject1 marks:");
               scanf("%d",st[i].sub[1]);
            printf("\nSubject1 marks:");
               scanf("%d",st[i].sub[2]);
           }
        case 4:
            printf("\n\nEnter the Details:\n");
            printf("Organisation Name :");
            scanf("%s",&org.on);
            printf("\nOrganisation Number : ");
            scanf("%s",&org.ono);
            printf("Employee id :");
            scanf("%d",&org.emp.eid);
            printf("Employee name : ");
            scanf("%s",&org.emp.en);
            printf("Employee Salary : ");
            scanf("%d",&org.emp.sal);
            printf("\n\nThe details of Employee are:\n");
            printf("Organisation Name : %s\n",org.on);
            printf("Organisation Number : %s\n",org.ono);
            printf("Employee id : %d\n",org.emp.eid);
            printf("Employee name : %s\n",org.emp.en);
            printf("Employee Salary : %d\n",org.emp.sal);
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