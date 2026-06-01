#include<stdio.h>
#include<string.h>
void main()
{
    char score,P1[20],P2[20],ball,k=1;
    int ts=0,target=16;
    printf("The target is 16 in a over\n");
    printf("\nPlease go through the choice :");
    printf("\nEnter ");
    printf("\nw  for  wide\n");
    printf("o  for out");
    printf("\n.  for no score");
    printf("\nInput scores 1,2,4,6 only\n");
    printf("\nEnter the name of player 1:");
    gets(P1);
    printf("Enter the name of player 2:");
    gets(P2);
    for(ball=1; ball<=6; ball++)
    {
        if(k%2==1)
            printf("\n%s ",P1);
        else
            printf("\n%s ",P2);
        printf("is batting\n");
        printf("\n%d ball score:",ball);
        scanf("%s",&score);
        if(score=='.')
            continue ;
        else if(score=='w')
        {
            ball-=1;
            ts+=1;
        }
        else if (score=='2')
            ts+=2;
        else if (score=='4')
            ts+=4;
        else if (score=='6')
            ts+=6;
        else if (score=='1')
        {
            k+=score;
            ts+=1;
        }
        else if(score='o')
        goto result;
    }
    result:
    {
    if(ts<target)
    printf("Lost by %d runs",target-ts);
    else
printf("Won by %d runs",ts-target);
    }
}