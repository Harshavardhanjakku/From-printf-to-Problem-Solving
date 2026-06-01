#include<stdio.h>
#include<string.h>
#include<conio.h>
void dm();//display function
void di();//display instructions
void dr();//display read
void dn();
int comp(char opt[3]);
int menu();
void key();
void review (int total);
int main()
{
FILE *ptr;//File pointer
    int val,i,ts=0,j;//total score
    char name[30],ch[3],option[20]="nnnnnnnnnnnnnnnnnnnn";
    printf("Enter the Name:");
    gets(name);
    ptr=fopen("file1","w");
    fprintf(ptr,"Name:%s\n",name);
    printf("\n    A Warm Welcome to u %s\n",name);
    dm();
    dr();
    gets(ch);
    val=comp(ch);
    clrscr();
    if(val==0)
    {
        di();
        dr();
        gets(ch);
        val=comp(ch);
        clrscr();
        if(val==0)
        {
            for(i=0; i<=20; i++)
            {
                switch(i)
                {
                case 0:
                    printf("Quetsion %d:\n",i+1);
                    printf("\nWho is the Father of Computer?",i+1);
                    printf("\n\n a)Dennis Ritchie\tb)Charles babbage\n");
                    printf("\n\n c)Adolph\t \td)Van Son\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);
                    if(option[i]=='s')
                        goto submit;
                    clrscr();
                    break;
                case 1:
                    printf("Quetsion %d:\n",i+1);
                    printf("\nWho is the Father of C language?");
                    printf("\n\n a)Dr.P.Prawin\tb)Charles babbage\n");
                    printf("\n\n c)Adolph \td)Dennis Ritchie\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);
                    if(option[i]=='s')
                        goto submit;
                    clrscr();
                    break;
                case 2:
                    printf("Quetsion %d:\n",i+1);
                    printf("\nWhat does BMW stands for?");
                    printf("\n\n a)Brenlie Mechanical Works\tb) Bravarian  Mechanical Works\n");
                    printf("\n\n c) Bravarian Motor Works\td) Brenlie Motor Works\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);
                    if(option[i]=='s')
                        goto submit;
                    clrscr();
                    break;
                case 3:
                    printf("Quetsion %d:\n",i+1);
                    printf("\nWhat is the smallest country in the world?");
                    printf("\n\n a)Georgia\tb) Singapore\n");
                    printf("\n\n c)Sanfrancisco\td) Vatican City\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);
                    if(option[i]=='s')
                        goto submit;
                    clrscr();
                    break;
                case 4:
                    printf("Quetsion %d:\n",i+1);
                    printf("\nThe speed of the computer mouse is measured in?");
                    printf("\n\n a)Mickeys\tb)pixels\n");
                    printf("\n\n c)Meter per sec\td) cursor per sec\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);
                    if(option[i]=='s')
                        goto submit;
                    clrscr();
                    break;
                case 5:
                    printf("Question %d:\n",i+1);
                    printf("\nThe fear of dogs is termed as?");
                    printf("\n\n a)Aquaphobia\tb)Acrophobia\n");
                    printf("\n\n c)Cynophobia\td)Hypermetrophobia\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);
                    if(option[i]=='s')
                        goto submit;
                    clrscr();
                    break;
                case 6:
                    printf("Quetsion %d:\n",i+1);
                    printf("\nWhat is the Indian cinema that won OSCAR awards?");
                    printf("\n\n a)Salaar\tb)RRR\n");
                    printf("\n\n c)Bahubali \td)KGF\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);
                    if(option[i]=='s')
                        goto submit;
                    clrscr();
                    break;
                case 7:
                    printf("Quetsion %d:\n",i+1);
                    printf("\nCapital of Russia?");
                    printf("\n\n a)Moscow\tb)Paris\n");
                    printf("\n\n c)Rome \td)Greece\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);
                    if(option[i]=='s')
                        goto submit;
                    clrscr();
                    break;
                case 8:
                    printf("Quetsion %d:\n",i+1);
                    printf("\nWhat planets literally rain DIAMONDS?");
                    printf("\n\n a)Venus and Mercury\tb)Earth\n");
                    printf("\n\n c)Saturn and Jupiter\td)Uranus and Neptune\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);
                    if(option[i]=='s')
                        goto submit;
                    clrscr();
                    break;
                case 9:
                    printf("Quetsion %d:\n",i+1);
                    printf("\nWhich country has fastest internet in the world?");
                    printf("\n\n a)India\tb) China\n");
                    printf("\n\n c)United States\td) South Korea\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);
                    if(option[i]=='s')
                        goto submit;
                    clrscr();
                    break;
                case 10:
                    printf("Quetsion %d:\n",i+1);
                    printf("\nWhich Indian city is also known as   The City of Prime Ministers?");
                    printf("\n\n a)Ahmedabad\tb)New Delhi\n");
                    printf("\n\n c)Patna\td) Allahabad\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);
                    if(option[i]=='s')
                        goto submit;
                    clrscr();
                    break;
                case 11:
                    printf("Quetsion %d:\n",i+1);
                    printf("\nWhich country has the highest Life Expectancy?");
                    printf("\n\n a)Austria\tb)Antarctica\n");
                    printf("\n\n c)Holland\td) Hong Kong\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);
                    if(option[i]=='s')
                        goto submit;
                    clrscr();
                    break;
                case 12:
                    printf("Quetsion %d:\n",i+1);
                    printf("\nWhich of the following hydrocarbon is termed as Fruit Ripening Gas?");
                    printf("\n\n a)Ethane\tb)Ethylene\n");
                    printf("\n\n c)Methane\td) Propane\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);
                    if(option[i]=='s')
                        goto submit;
                    clrscr();
                    break;
                case 13:
                    printf("Quetsion %d:\n",i+1);
                    printf("\nWho appoints the Chief Minister?");
                    printf("\n\n a)President\tb)Prime Minister\n");
                    printf("\n\n c)Governer\td) Chief Justice\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);
                    if(option[i]=='s')
                        goto submit;
                    clrscr();
                    break;
                case 14:
                    printf("Quetsion %d:\n",i+1);
                    printf("\nThe largest part of human brain is?");
                    printf("\n\n a)Cerebellum\tb) Midbrain\n");
                    printf("\n\n c)Medulla Oblongata\td) Cerebrum\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);
                    if(option[i]=='s')
                        goto submit;
                    clrscr();
                    break;
                case 15:
                    printf("Quetsion %d:\n",i+1);
                    printf("\nThe Gupta King who assumed the title of Vikramaditya was?");
                    printf("\n\n a)Skandagupta\tb) Kumaragupta\n");
                    printf("\n\n c)Chandragupta 2\td) Samudragupta\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);
                    if(option[i]=='s')
                        goto submit;
                    clrscr();
                    break;
                case 16:
                    printf("Quetsion %d:\n",i+1);
                    printf("\nWhich gas is used in the refrigerator?");
                    printf("\n\n a)Oxygen\tb) Freon\n");
                    printf("\n\n c)Carbon\td) Nitrogen\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);
                    if(option[i]=='s')
                        goto submit;
                    clrscr();
                    break;
                case 17:
                    printf("\nQuetsion %d:\n",i+1);
                    printf("\nWhich is called the METAL OF THE FUTURE?");
                    printf("\n\n a)Titanium\tb) Lead\n");
                    printf("\n\n c)Platinum\td) Mercury\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);
                    if(option[i]=='s')
                        goto submit;
                    clrscr();
                    break;
                case 18:
                    printf("Quetsion %d:\n",i+1);
                    printf("\nWho opened the first school for girls in India?");
                    printf("\n\n a)Sarojini Naidu\tb) Indira Gandhi\n");
                    printf("\n\n c)Lakshmi Sahgal\td) Savitribai Phule\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);
                    if(option[i]=='s')
                        goto submit;
                    clrscr();
                    break;
                case 19:
                    printf("Quetsion %d:\n",i+1);
                    printf("\nWhich state in India is named as Land of Seven Languages?");
                    printf("\n\n a)Tamilnadu\tb) Kerala\n");
                    printf("\n\n c)Mumbai\td) Rajasthan\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);
                    if(option[i]=='s')
                        goto submit;
                    clrscr();
                    break;

                }
            }
submit:
            val=menu();
            if(val==1)
            {
            printf("\n\nChecking for evaluation.Loading...");
            printf("\nPlease Wait...");
            ts=eval(option);
                printf("\n\nThe TOTAL SCORE IS: %d",ts);
            printf("\n_____________________________________________\n");
            fprintf(ptr,"Total:%d",ts);
            review(ts);
            }
            else
                goto exit;
            printf("\nDo you want to Reattempt:");
            dr();
            scanf("%s",&ch);
            clrscr();
            j=comp(ch);
            if(j==0)
            {
                main();
            }
        }
    }
key:
    {
        printf("\nDo you want to check the key:");
        dr();
        scanf("%s",&ch);
        clrscr();
        j=comp(ch);
        if(j==0)
            key();
    }
exit:
    printf("\nThank you !");
}
void dm()
{
    printf("____________________Quiz_____________________");
    printf("\n\n Topic:General Knowledge");
    printf("\n\n Questions:20");
    printf("\n\n Negative marks:1 mark");
    printf("\n Unattempted:0 marks");
    printf("\n Correct:4 marks");
    printf("\n\n Are u Excited ?");
}
void di()
{
    printf("\nPlease go through the below instructions");
    printf("\n Do Enter\n  'S' for submission");
    printf("\n  'U' for unattempted");
    printf("\n There are Four options namely a,b,c,d");

}
void dr()
{
    printf("\n\n If yes Enter 'Yes'\n otherwise Enter 'No'");
    printf("\n\n Enter your choice:");
}
int comp(char opt[3])
{
    int r;
    char Yes[]="yes";
    r=strcasecmp(opt,Yes);
    return r;
}
int menu()
{
    int c;//choice
    printf("Please go through the choice:");
    printf("\n1.View Result");
    printf("\n2.Exit");
    printf("\nEnter the choice :");
    scanf("%d",&c);
    return c;
}
int eval(char o[20])
{
    int i,ts=0,r,cq=0,wq=0,uq=0;
    char key[]= {'b','d','c','d','a','c','b','a','c','d','d','d','b','c','d','c','b','a','d','b'};
    for(i=0; i<20; i++)
    {
        if(o[i]=='U'||o[i]=='n'||o[i]=='s'||o[i]=='\0')
        {
            if(o[i]=='U')
            uq+=1;
        ts+=0;
        }
        else if(o[i]==key[i])
        {
            cq+=1;
            ts+=4;
        }
        else
        {
         wq+=1;
         ts-=1;
        }
    }
    printf("\n_____________________________________________\n");
    printf("\n\nTOTAL QUESTIONS:20");
    printf("\nCorrect QUESTIONS:%d",cq);
    printf("\nWrong QUESTIONS:%d",wq);
    printf("\nUnattempted QUESTIONS:%d",uq);
    printf("\nAppeared QUESTIONS:%d",(cq+wq+uq));
    printf("\nUnappeared QUESTIONS:%d",20-(cq+wq+uq));
    printf("\n_____________________________________________\n");
    r=ts;
    return r;
}
void review(int total)
{
printf("\n\nREVIEW:\n");
if(total>=60)
printf("\nOUTSTANDING PERFORMER.Keep it up");
else if (total>=45)
printf("\nExcellent.Keep going");
else if (total>=30)
printf("\nGOOD.Need to be improved");
else if(total>=15)
printf("\nPOOR.Work hard");
else if(total>=5)
printf("\nCHADUVUKONDI FIRSTUUU.Mana parents Clg ki endhuku pampisthunnaru..");
else// Neeku isthamaindhi pettuko review 
printf("\nSTOP STUDYING.IT IS BETTER TO WORK AS LABOUR IN A FACTORY");
printf("\n_____________________________________________\n");
}
void key()
{
    int i;
    char key[]= {'b','d','c','d','a','c','b','a','c','d','d','d','b','c','d','c','b','a','d','b'};
    printf("\nThe Key is:\n");
    for(i=0; i<20; i++)
    {
        if(i<=8)
            printf(" %d.%c\n",i+1,key[i]);
        else
            printf("%d.%c\n",i+1,key[i]);
    }
}
