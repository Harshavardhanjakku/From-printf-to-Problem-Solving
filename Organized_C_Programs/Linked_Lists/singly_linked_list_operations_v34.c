#include <stdio.h>
#include <string.h>
//int readop();
main()
{
    int r,k=1,tot=0,c=0,ic=0,u=0;
    char ch[3],op,name[30],Yes[]="yes";
    printf("Enter the Name:");
    gets(name);
    printf("\t\tWELCOME %s to \n",name);
    printf("_______________________Quiz_________________________");
    printf("\nTopic:General Knowledge");
    printf("\n Questions:20");
    printf("\n Negative marks:1 mark");
    printf("\n Unattempted:0 marks");
    printf("\n Correct:4 marks");
    printf("\n\n Are u Excited");
    printf("\n Dou want to continue?");
    printf("\n If yes Enter Yes,otherwise Enter No");
    printf("\n\n Enter your choice:    ");
    gets(ch);
    r=strcasecmp(ch,Yes);
    if(r==0)
    {
        printf("\nPlease go through the instructions");
        printf("\t\t Test Instructuions\n ");
        printf("\n enter the text S for submission");
        printf("\n enter U-unattempted;S-submission");
        printf("\n There are Four options");
        printf("\n Do u want to Begin the test:\n");
        r=strcasecmp(ch,Yes);
        if(r==0)
        {
            printf("\n\n\nQuetsion %d:\n",k++);
            printf("\n1.Who is the Father of Computer?");
            printf("\n\n a)Dennis Ritchie\tb)Charles babbage\n");
            printf("\n\n c)Adolph \td)Van Son\n");
            printf("\n\nEnter the choice:");
            scanf("%c",&op);
            if(op=='b')
            {
                tot+=4;
                c+=1;
            }

            else if(op=='U')
                u+=1;
            else if(op!='b')
                ic+=1;
            else if(op=='S')
                  goto submit;
            else
                tot+=-1;
            printf("\n\n\nQuetsion %d:\n",k++);
            printf("\n2.Who is the Father of C language?");
            printf("\n\n a)Dr.P.Prawin\tb)Charles babbage\n");
            printf("\n\n c)Adolph \td)Dennis Ritchie\n");
            printf("\n\nEnter the choice:");
           scanf("%s",&op);
            if(op=='d')
            {
                tot+=4;
                c+=1;
            }

            else if(op=='U')
                u+=1;
            else if(op!='d')
                ic+=1;
            else if(op=='S')
                  goto submit;
            else
                tot+=-1;
            printf("\n\n\nQuetsion %d:\n",k++);
            printf("\n 3.What does BMW stands for?");
            printf("\n\n a)Brenlie Mechanical Works\tb) Bravarian  Mechanical Works\n");
            printf("\n\n c) Bravarian Motor Works\td) Brenlie Motor Works\n");
            printf("\n\nEnter the choice:");
            scanf("%s",&op);
            if(op=='c')
            {
                tot+=4;
                c+=1;
            }

            else if(op=='U')
                u+=1;
            else if(op!='c')
                ic+=1;
            else if(op=='S')
                  goto submit;
            else
                tot+=-1;
            printf("\n\n\nQuetsion %d:\n",k++);
            printf("\n4.What is the smallest country in the world?");
            printf("\n\n a)Georgia\tb) Singapore\n");
            printf("\n\n c)Sanfrancisco\td) Vatican City\n");
            printf("\n\nEnter the choice:");
            scanf("%s",&op);
            if(op=='d')
            {
                tot+=4;
                c+=1;
            }

            else if(op=='U')
                u+=1;
            else if(op!='d')
                ic+=1;
            else if(op=='S')
                  goto submit;
            else
                tot+=-1;
                  printf("\n\n\nQuetsion %d:\n",k++);
            printf("\n5.The speed of the computer mouse is measured in?");
            printf("\n\n a)Mickeys\tb)pixels\n");
            printf("\n\n c)Meter per sec\td) cursor per sec\n");
            printf("\n\nEnter the choice:");
            scanf("%s",&op);
            if(op=='a')
            {
                tot+=4;
                c+=1;
            }

            else if(op=='U')
                u+=1;
            else if(op!='a')
                ic+=1;
            else if(op=='S')
                  goto submit;
            else
                tot+=-1;
                  printf("\n\n\nQuestion %d:\n",k++); 
            printf("\n6.The fear of dogs is termed as?");
            printf("\n\n a)Aquaphobia\tb)Acrophobia\n");
            printf("\n\n c)Cynophobia\td)Hypermetrophobia\n");
            printf("\n\nEnter the choice:");
            scanf("%s",&op);
            if(op=='c')
            {
                tot+=4;
                c+=1;
            }

            else if(op=='U')
                u+=1;
            else if(op!='c')
                ic+=1;
            else if(op=='S')
                  goto submit;
            else
                tot+=-1;
             printf("\n\n\nQuetsion %d:\n",k++);
            printf("\n7.What is the Indian cinema that won OSCAR awards?");
            printf("\n\n a)Salaar\tb)RRR\n");
            printf("\n\n c)Bahubali \td)KGF\n");
            printf("\n\nEnter the choice:");
            scanf("%s",&op);
            if(op=='b')
            {
                tot+=4;
                c+=1;
            }

            else if(op=='U')
                u+=1;
            else if(op!='b')
                ic+=1;
            else if(op=='S')
                  goto submit;
            else
                tot+=-1;
            printf("\n\n\nQuetsion %d:\n",k++);
            printf("\n8.Capital of Russia?");
            printf("\n\n a)Moscow\tb)Paris\n");
            printf("\n\n c)Rome \td)Greece\n");
            printf("\n\nEnter the choice:");
           scanf("%s",&op);
            if(op=='a')
            {
                tot+=4;
                c+=1;
            }

            else if(op=='U')
                u+=1;
            else if(op!='a')
                ic+=1;
            else if(op=='S')
                  goto submit;
            else
                tot+=-1;
            printf("\n\n\nQuetsion %d:\n",k++);
            printf("\n 9.What planets literally rain DIAMONDS?");
            printf("\n\n a)Venus and Mercury\tb)Earth\n");
            printf("\n\n c)Saturn and Jupiter\td)Uranus and Neptune\n");
            printf("\n\nEnter the choice:");
            scanf("%s",&op);
            if(op=='c')
            {
                tot+=4;
                c+=1;
            }

            else if(op=='U')
                u+=1;
            else if(op!='c')
                ic+=1;
            else if(op=='S')
                  goto submit;
            else
                tot+=-1;
            printf("\n\n\nQuetsion %d:\n",k++);
            printf("\n 10.Which country has fastest internet in the world?");
            printf("\n\n a)India\tb) China\n");
            printf("\n\n c)United States\td) South Korea\n");
            printf("\n\nEnter the choice:");
            scanf("%s",&op);
            if(op=='d')
            {
                tot+=4;
                c+=1;
            }

            else if(op=='U')
                u+=1;
            else if(op!='d')
                ic+=1;
            else if(op=='S')
                  goto submit;
            else
                tot+=-1;
            printf("\n\n\nQuetsion %d:\n",k++);
            printf("\n 11.Which Indian city is also known as   The City of Prime Ministers?");
            printf("\n\n a)Ahmedabad\tb)New Delhi\n");
            printf("\n\n c)Patna\td) Allahabad\n");
            printf("\n\nEnter the choice:");
            scanf("%s",&op);
            if(op=='d')
            {
                tot+=4;
                c+=1;
            }

            else if(op=='U')
                u+=1;
            else if(op!='d')
                ic+=1;
            else if(op=='S')
                  goto submit;
            else
                tot+=-1;
            printf("\n\n\nQuetsion %d:\n",k++);
            printf("\n 12.Which country has the highest Life Expectancy?");
            printf("\n\n a)Austria\tb)Antarctica\n");
            printf("\n\n c)Holland\td) Hong Kong\n");
            printf("\n\nEnter the choice:");
            scanf("%s",&op);
            if(op=='d')
            {
                tot+=4;
                c+=1;
            }

            else if(op=='U')
                u+=1;
            else if(op!='d')
                ic+=1;
            else if(op=='S')
                  goto submit;
            else
                tot+=-1;
            printf("\n\n\nQuetsion %d:\n",k++);
            printf("\n 13.Which of the following hydrocarbon is termed as Fruit Ripening Gas?");
            printf("\n\n a)Ethane\tb)Ethylene\n");
            printf("\n\n c)Methane\td) Propane\n");
            printf("\n\nEnter the choice:");
            scanf("%s",&op);
            if(op=='b')
            {
                tot+=4;
                c+=1;
            }

            else if(op=='U')
                u+=1;
            else if(op!='b')
                ic+=1;
            else if(op=='S')
                  goto submit;
            else
                tot+=-1;
            printf("\n\n\nQuetsion %d:\n",k++);
            printf("\n 14.Who appoints the Chief Minister?");
            printf("\n\n a)President\tb)Prime Minister\n");
            printf("\n\n c)Governer\td) Chief Justice\n");
            printf("\n\nEnter the choice:");
            scanf("%s",&op);
            if(op=='c')
            {
                tot+=4;
                c+=1;
            }

            else if(op=='U')
                u+=1;
            else if(op!='c')
                ic+=1;
            else if(op=='S')
                  goto submit;
            else
                tot+=-1;
            printf("\n\n\nQuetsion %d:\n",k++);
            printf("\n 15.The largest part of human brain is?");
            printf("\n\n a)Cerebellum\tb) Midbrain\n");
            printf("\n\n c)Medulla Oblongata\td) Cerebrum\n");
            printf("\n\nEnter the choice:");
            scanf("%s",&op);
            if(op=='d')
            {
                tot+=4;
                c+=1;
            }

            else if(op=='U')
                u+=1;
            else if(op!='d')
                ic+=1;
            else if(op=='S')
                  goto submit;
            else
                tot+=-1;
            printf("\n\n\nQuetsion %d:\n",k++);
            printf("\n 16.The Gupta King who assumed the title of Vikramaditya was?");
            printf("\n\n a)Skandagupta\tb) Kumaragupta\n");
            printf("\n\n c)Chandragupta 2\td) Samudragupta\n");
            printf("\n\nEnter the choice:");
            scanf("%s",&op);
            if(op=='c')
            {
                tot+=4;
                c+=1;
            }

            else if(op=='U')
                u+=1;
            else if(op!='c')
                ic+=1;
            else if(op=='S')
                  goto submit;
            else
                tot+=-1;
            printf("\n\n\nQuetsion %d:\n",k++);
            printf("\n 17.Which gas is used in the refrigerator?");
            printf("\n\n a)Oxygen\tb) Freon\n");
            printf("\n\n c)Carbon\td) Nitrogen\n");
            printf("\n\nEnter the choice:");
            scanf("%s",&op);
            if(op=='b')
            {
                tot+=4;
                c+=1;
            }

            else if(op=='U')
                u+=1;
            else if(op!='b')
                ic+=1;
            else if(op=='S')
                  goto submit;
            else
                tot+=-1;
            printf("\n\n\nQuetsion %d:\n",k++);
            printf("\n 18.Which is called the METAL OF THE FUTURE?");
            printf("\n\n a)Titanium\tb) Lead\n");
            printf("\n\n c)Platinum\td) Mercury\n");
            printf("\n\nEnter the choice:");
            scanf("%s",&op);
            if(op=='a')
            {
                tot+=4;
                c+=1;
            }

            else if(op=='U')
                u+=1;
            else if(op!='a')
                ic+=1;
            else if(op=='S')
                  goto submit;
            else
                tot+=-1;
            printf("\n\n\nQuetsion %d:\n",k++);
            printf("\n 19.Who opened the first school for girls in India?");
            printf("\n\n a)Sarojini Naidu\tb) Indira Gandhi\n");
            printf("\n\n c)Lakshmi Sahgal\td) Savitribai Phule\n");
            printf("\n\nEnter the choice:");
            scanf("%s",&op);
            if(op=='d')
            {
                tot+=4;
                c+=1;
            }

            else if(op=='U')
                u+=1;
            else if(op!='d')
                ic+=1;
            else if(op=='S')
                  goto submit;
            else
                tot+=-1;
            printf("\n\n\nQuetsion %d:\n",k++);
            printf("\n 20.Which state in India is named as Land of Seven Languages?");
            printf("\n\n a)Tamilnadu\tb) Kerala\n");
            printf("\n\n c)Mumbai\td) Rajasthan\n");
            printf("\n\nEnter the choice:");
            scanf("%s",&op);
            if(op=='b')
            {
                tot+=4;
                c+=1;
            }

            else if(op=='U')
                u+=1;
            else if(op='b')
                ic+=1;
            else if(op=='S')
                  goto submit;
            else
                tot+=-1;
        }
       
        else
        {
            goto Exit;
            printf("Thankyou");

        }


    }
    submit:
    {
    printf("\n\t\tPROGRESS");
    printf("\nName:%s",name);
    printf("\nTotal:%d",tot);
    printf("\nCorrect:%d",c);
    printf("\nIncorrect:%d",ic);
    printf("\nUnattempted:%d",u);
    if(tot>=60)
    printf("\nEXCELLENT KEEP IT UP");
    
    else if(tot>=40)
    printf("\nNEED TO BE IMPROVED");
    else
    printf("\nBETTER LUCK NEXT TIME");
    }
    
    
    Exit:
        printf("\n\n\n*****************THANKYOU****************");
main();
}
/*int readop()
{
char h;
gets(h);
return h;
}*/