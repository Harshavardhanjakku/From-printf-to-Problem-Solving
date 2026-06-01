#include<stdio.h> 
void main()
{
char name[50],rollno[10];
int q1,q2,q3,q4,q5,score,w,crt,wrg,k,n;
score=0;
n=100;
crt=0;
wrg=0;
printf("\n              ONLINE TEST");
printf("\n *************************************");
printf("\nNAME:");
scanf("%s",name);
printf("ROLL NO:");
scanf("%s",rollno);
printf("\n EACH QUESTION IS ALLOTED 4 MARKS FOR CORRECT RESPONSE AND 1 MARK WILL BE DEDUCTED FOR EVERY WRONG ANSWER");
printf("\n\nA.C LANGUAGE WAS DEVELOPED BY");
printf("\n1.DENNIS RITCHE\n2.BILLGATES\n3.KEN THOMPSON\n4.NONE");
printf("\nENTER UR ANSWER:");
scanf("%d",&q1);
    if(q1==1)
    {
    crt=crt+1;
    score=score+4;
    }
    else
    {
    wrg=wrg+1;
    score=score-1;
    }
printf("\nB.C WAS DEVELOPED IN THE YEAR:");
printf("\n1.1970\n2.1972\n3.1976\n4.1980");
printf("\nENTER UR ANSWER:");
scanf("%d",&q2);
    if(q2==2)
    {
    crt=crt+1;
    score=score+4;
    }
    else
    {
    wrg=wrg+1;
    score=score-1;
    }
printf("\nC.C IS A___LANGUAGE:");
printf("\n1.HIGH LEVEL\n2.LOW LEVEL\n3.MIDDLE LEVEL\n4.MACHINE LEVEL");
printf("\nENTER UR ANSWER:");
scanf("%d",&q3);
    if(q3==3)
    {
    crt=crt+1;
    score=score+4;
    }
    else
    {
    wrg=wrg+1;
    score=score-1;
    }
printf("\nD.WHAT IS THE MAXIMUM SIZE OF FLOAT VARIABLE:");
printf("\n1.1 byte\n2.2 bytes\n3.4 bytes\n4.8 bytes");
printf("\nENTER UR ANSWER:");
scanf("%d",&q4);
    if(q4==3)
    {
    crt=crt+1;
    score=score+4;
    }
    else
    {
    wrg=wrg+1;
    score=score-1;
    }
printf("\nE.WHICH OPERATOR IS CALLED A TERNARY OPERATOR");
printf("\n1.++\n2.&&\n3.?:\n4.()");
printf("\nENTER UR ANSWER:");
scanf("%d",&q5);
    if(q5==3)
    {
    crt=crt+1;
    score=score+4;
    }
    else
    {
    wrg=wrg+1;
    score=score-1;
    }
printf("\nYOUR RESPONSE IS SUBMITTED\n");
for(k=0;k<n;k++)
{
printf("\n\n1.VIEW RESULT\n2.KEY\n0.EXIT");
printf("\nENTER UR CHOICE:");
scanf("%d",&w);
    if(w==1) 
    {
    printf("\nCORRECT ANSWERS:%d",crt);
    printf("\nWRONG ANSWERS:%d",wrg);
    printf("\nSCORE = %d",score);
    }
    else if(w==2)
    {
    printf("\nA.1\nB.2\nC.3\nD.3\nE.3");
    }
    else if(w==0)
    {
    exit(0);
    }
    else
    {
    printf("ENTER NUMBER BETWEEN O AND 2");
    }
}
}