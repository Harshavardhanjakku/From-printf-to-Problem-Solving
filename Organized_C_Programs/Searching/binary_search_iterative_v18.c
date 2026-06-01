#include<stdio.h>
#include<string.h>
#include<conio.h>
void dm();//display function
void di();//display instructions
void dr();//display read
void dn();
int comp(opt[3]);
int menu();
void key();
int main()
{
    int val,i,ts=0,j;//total score
    char name[30],ch[3],option[20];
    dn();
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
                    clrscr();
                    break;
                case 1:
                    printf("Quetsion %d:\n",i+1);
                    printf("\nWho is the Father of C language?");
                    printf("\n\n a)Dr.P.Prawin\tb)Charles babbage\n");
                    printf("\n\n c)Adolph \td)Dennis Ritchie\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);

                    clrscr();
                    break;
                case 2:
                    printf("Quetsion %d:\n",i+1);
                    printf("\nWhat does BMW stands for?");
                    printf("\n\n a)Brenlie Mechanical Works\tb) Bravarian  Mechanical Works\n");
                    printf("\n\n c) Bravarian Motor Works\td) Brenlie Motor Works\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);

                    clrscr();
                    break;
                case 3:
                    printf("Quetsion %d:\n",i+1);
                    printf("\nWhat is the smallest country in the world?");
                    printf("\n\n a)Georgia\tb) Singapore\n");
                    printf("\n\n c)Sanfrancisco\td) Vatican City\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);

                    clrscr();
                    break;
                case 4:
                    printf("Quetsion %d:\n",i+1);
                    printf("\nThe speed of the computer mouse is measured in?");
                    printf("\n\n a)Mickeys\tb)pixels\n");
                    printf("\n\n c)Meter per sec\td) cursor per sec\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);

                    clrscr();
                    break;
                case 5:
                    printf("Question %d:\n",i+1);
                    printf("\nThe fear of dogs is termed as?");
                    printf("\n\n a)Aquaphobia\tb)Acrophobia\n");
                    printf("\n\n c)Cynophobia\td)Hypermetrophobia\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);

                    clrscr();
                    break;
                case 6:
                    printf("Quetsion %d:\n",i+1);
                    printf("\nWhat is the Indian cinema that won OSCAR awards?");
                    printf("\n\n a)Salaar\tb)RRR\n");
                    printf("\n\n c)Bahubali \td)KGF\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);

                    clrscr();
                    break;
                case 7:
                    printf("Quetsion %d:\n",i+1);
                    printf("\nCapital of Russia?");
                    printf("\n\n a)Moscow\tb)Paris\n");
                    printf("\n\n c)Rome \td)Greece\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);

                    clrscr();
                    break;
                case 8:
                    printf("Quetsion %d:\n",i+1);
                    printf("\nWhat planets literally rain DIAMONDS?");
                    printf("\n\n a)Venus and Mercury\tb)Earth\n");
                    printf("\n\n c)Saturn and Jupiter\td)Uranus and Neptune\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);
                    clrscr();
                    break;
                case 9:
                    printf("Quetsion %d:\n",i+1);
                    printf("\nWhich country has fastest internet in the world?");
                    printf("\n\n a)India\tb) China\n");
                    printf("\n\n c)United States\td) South Korea\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);

                    clrscr();
                    break;
                case 10:
                    printf("Quetsion %d:\n",i+1);
                    printf("\nWhich Indian city is also known as   The City of Prime Ministers?");
                    printf("\n\n a)Ahmedabad\tb)New Delhi\n");
                    printf("\n\n c)Patna\td) Allahabad\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);

                    clrscr();
                    break;
                case 11:
                    printf("Quetsion %d:\n",i+1);
                    printf("\nWhich country has the highest Life Expectancy?");
                    printf("\n\n a)Austria\tb)Antarctica\n");
                    printf("\n\n c)Holland\td) Hong Kong\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);

                    clrscr();
                    break;
                case 12:
                    printf("Quetsion %d:\n",i+1);
                    printf("\nWhich of the following hydrocarbon is termed as Fruit Ripening Gas?");
                    printf("\n\n a)Ethane\tb)Ethylene\n");
                    printf("\n\n c)Methane\td) Propane\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);

                    clrscr();
                    break;
                case 13:
                    printf("Quetsion %d:\n",i+1);
                    printf("\nWho appoints the Chief Minister?");
                    printf("\n\n a)President\tb)Prime Minister\n");
                    printf("\n\n c)Governer\td) Chief Justice\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);

                    clrscr();
                    break;
                case 14:
                    printf("Quetsion %d:\n",i+1);
                    printf("\nThe largest part of human brain is?");
                    printf("\n\n a)Cerebellum\tb) Midbrain\n");
                    printf("\n\n c)Medulla Oblongata\td) Cerebrum\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);
                    clrscr();
                    break;
                case 15:
                    printf("Quetsion %d:\n",i+1);
                    printf("\nThe Gupta King who assumed the title of Vikramaditya was?");
                    printf("\n\n a)Skandagupta\tb) Kumaragupta\n");
                    printf("\n\n c)Chandragupta 2\td) Samudragupta\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);
                    clrscr();
                    break;
                case 16:
                    printf("Quetsion %d:\n",i+1);
                    printf("\nWhich gas is used in the refrigerator?");
                    printf("\n\n a)Oxygen\tb) Freon\n");
                    printf("\n\n c)Carbon\td) Nitrogen\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);
                    clrscr();
                    break;
                case 17:
                    printf("\nQuetsion %d:\n",i+1);
                    printf("\nWhich is called the METAL OF THE FUTURE?");
                    printf("\n\n a)Titanium\tb) Lead\n");
                    printf("\n\n c)Platinum\td) Mercury\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);
                    clrscr();
                    break;
                case 18:
                    printf("Quetsion %d:\n",i+1);
                    printf("\nWho opened the first school for girls in India?");
                    printf("\n\n a)Sarojini Naidu\tb) Indira Gandhi\n");
                    printf("\n\n c)Lakshmi Sahgal\td) Savitribai Phule\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);
                    clrscr();
                    break;
                case 19:
                    printf("Quetsion %d:\n",i+1);
                    printf("\nWhich state in India is named as Land of Seven Languages?");
                    printf("\n\n a)Tamilnadu\tb) Kerala\n");
                    printf("\n\n c)Mumbai\td) Rajasthan\n");
                    printf("\n\nEnter the choice:");
                    scanf("%s",&option[i]);
                    clrscr();
                    i=19;
                    break;
                case 20:
submit:
                    val=menu();
                    if(val==1)
                    {

                        printf("\nThe total score is %d",eval(option));
                    }
                    else
                        goto exit;
                }
            }
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
    printf("\nThank you");
}
void dn()
{
    char name[30];
    printf("Enter the Name:");
    gets(name);
    printf("\n    A Warm Welcome to u %s\n",name);
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
int comp(opt[3])
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
    int i,ts=0,r;
    char key[]= {'b','d','c','d','a','c','b','a','c','d','d','d','b','c','d','c','b','a','d','b'};

    for(i=0; i<20; i++)
    {
        if(o[i]=='U')
            ts+=0;
        else if(o[i]==key[i])
        {
            ts+=4;
        }
        else
            ts-=1;
    }
    r=ts;
    return r;
}
void key()
{
    int i,ts=0;
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