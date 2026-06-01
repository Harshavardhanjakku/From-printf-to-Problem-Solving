#include <stdio.h>
#include <string.h>
struct cab {
    int id;
    char driver_name[50];
    char cab_model[20];
    char cab_number[10];
    int available_seats;
    float per_km_rate;
    char driver_contact[15];
    char cab_status[10];
};
void main()
{
struct cab cabs[5];
int i,ch,d;
    printf("\n************  CAB BOOKING SYSTEM  *********");
    printf("\n\nHello Welcome to Caberz\n\n");
    printf("\nSelect the ride u want:");
    printf("\n1.Bike\n2.Car\n3.Family Car");
    printf("\nEnter your choice:");
    scanf("%d",&ch);
    printf("\n\nChoose ur range");
    if(ch==1)
    printf("\n200-500>bike");
    else if(ch==2)
    printf("\n700-1000>car");
    else if(ch==3)
    printf("\n1500-1900>Family car");
    printf("\nEnter the distance u want to travel:");
    scanf("%d",&d);
    if(ch==1)
    printf("\nChoose Your location");
    else if(ch==2)
    {
    printf("\nChoose ur Car");
    printf("\n1.Swift\n2.Dezire\n3.I10\n4.I20\n5.Indica");
    }
    else if(ch==3)
    {
    printf("\nChoose ur Family Car");
    printf("\n1.Ertiga\n2.Innova\n3.Innova Crysta\n4.Safari\n5.Harrier");
    }
    
}
/*void initialize_cabs() 
{
    for(int i=0; i<5; i++) 
    {
        cabs[i].id = i+1;
        cabs[i].available_seats = 4;
        cabs[i].per_km_rate = 10.0;
        strcpy(cabs[i].cab_status, "Available");
    }
    strcpy(cabs[0].driver_name, "John");
    strcpy(cabs[0].cab_model, "Sedan");
    strcpy(cabs[0].cab_number, "KA04MG1234");
    strcpy(cabs[0].driver_contact, "9876543210");

    strcpy(cabs[1].driver_name, "Peter");
    strcpy(cabs[1].cab_model, "Hatchback");
    strcpy(cabs[1].cab_number, "KA04AB4567");
    strcpy(cabs[1].driver_contact, "9876543211");

    strcpy(cabs[2].driver_name, "Dave");
    strcpy(cabs[2].cab_model, "SUV");
    strcpy(cabs[2].cab_number, "KA04AC6789");
    strcpy(cabs[2].driver_contact, "9876543212");

    strcpy(cabs[3].driver_name, "Mike");
    strcpy(cabs[3].cab_model, "Sedan");
    strcpy(cabs[3].cab_number, "KA04BC2345");
    strcpy(cabs[3].driver_contact, "9876543213");

    strcpy(cabs[4].driver_name, "Rajesh");
    strcpy(cabs[4].cab_model, "SUV");
    strcpy(cabs[4].cab_number, "KA04DF6789");
    strcpy(cabs[4].driver_contact, "9876543214");
}

void print_cabs() {
    printf("\n\nAvailable cabs:\n");
    printf("--------------------------------------------------------\n");
    printf("| ID | DRIVER NAME | CAB MODEL | CAB NUMBER | SEATS | PER KM RATE | DRIVER CONTACT | STATUS |\n");
    printf("--------------------------------------------------------\n");
    for(int i=0; i<5; i++) {
        if(strcmp(cabs[i].cab_status, "Available") == 0) {
            printf("| %d  | %-11s | %-9s | %-10s | %-5d | %-11.2f | %-14s | %-6s |\n",
                    cabs[i].id, cabs[i].driver_name, cabs[i].cab_model, cabs[i].cab_number,
                    cabs[i].available_seats, cabs[i].per_km_rate, cabs[i].driver_contact, cabs[i].cab_status);
        }
    };
    printf("--------------------------------------------------------\n");
}

void book_cab(int id) {
    if(cabs[id-1].available_seats == 0) {
        printf("Sorry! No seats available in this cab.\n");
    } else {
        printf("Enter source and destination:\n");
        char source[20];
        }*/