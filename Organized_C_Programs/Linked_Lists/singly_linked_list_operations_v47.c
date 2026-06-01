#include<stdio.h>
#include <stdlib.h>
void create();
void traverse();
void insert_begin();
void insert_end();
void insert_specifiedposition();
struct Node{
	int info;
	struct Node *next;
};
struct Node *start=NULL;//creation of structure
void create(){
	struct Node *temp,*newnode;
	int i;
	temp=(struct Node*)malloc(sizeof(struct Node));
	int total,item;
	if(start==NULL){
		printf("\n Enter total no.of nodes.");
		scanf("%d",&total);
		if(total<=0){
			printf("\n enter the correct no.of nodes.");
		}
		else{
			printf("\n enter the values to insert:");
			scanf("%d",&item);
			temp->info=item;//assign item to info
			temp->next=temp;
			start=temp;
			for(i=2;i<=total;i++){
				newnode=(struct Node*)malloc(sizeof(struct Node));
				printf("\n enter the values to insert:");
			    scanf("%d",&item);
			    newnode->info=item;
			    newnode->next=start;
			    temp->next=newnode;
			    temp=newnode;
							}
			printf("\n List created successfully");
		}
	}
	else{
		printf("\n list already created.\n");
	}
}
void traverse(){
	struct Node *temp;
	if(start==NULL){
		printf("\n list is empty.");
	}
	else{
		temp=start;
	    do{
			printf("%d ",temp->info);
			temp=temp->next;
		}
			while(temp!=start);
	}
}
void insert_begin(){
	struct Node *newnode,*temp;
	int item;
	newnode=(struct Node*)malloc(sizeof(struct Node));
	if(newnode==NULL){
		printf("\n memory is not allocated.");
	}
	else{
		printf("\n Enter item:");
		scanf("%d",&item);
		newnode->info=item;
		newnode->next=newnode;
	}
	if(start==NULL){
	       start=newnode;
	}
	else{
		temp=start;
       while(temp->next!=start){
	           temp=temp->next;
			}
			temp->next=newnode;
			newnode->next=start;
			start=newnode;
}
}
void insert_end(){
	struct Node *newnode,*temp;
	int item;
	newnode=(struct Node*)malloc(sizeof(struct Node));
	if(newnode==NULL){
		printf("\n memory is not allocated.");
	}
	else{
		printf("\n Enter item:");
		scanf("%d",&item);
		newnode->info=item;
		newnode->next=newnode;
	}
	if(start==NULL){
	       start=newnode;
	}
	else{
		temp=start;
       while(temp->next!=start){
	           temp=temp->next;
			}
			temp->next=newnode;
			newnode->next=start;
}
}
void insert_specifiedposition(){
	struct Node *newnode,*temp,*ptr;
	int pos,item,count=1;
	newnode=(struct Node*)malloc(sizeof(struct Node));
    if(newnode==NULL){
		printf("\n memory is not allocated.");
	}
	else{
		printf("\n Enter position");
		scanf("%d",&pos);
		printf("\n Enter item:");
		scanf("%d",&item);
		newnode->info=item;
		newnode->next=temp;
	}
	if(pos==1){
		newnode->next=start;
		start=newnode;
	}
	else if(start==NULL){
		start=newnode;
	}
	else{
		temp=start;
		while(temp!=NULL &&count!=pos){
			count++;
			ptr=temp;
			temp=temp->next;
		}
		ptr->next=newnode;
		newnode->next=temp;
	}
	if(temp==NULL){
		printf("\n Invalid Position");
	}
}
void main(){
	while(1){
		int choice;
     	printf("\n 1.Create");
		printf("\n 2.Traverse");
		printf("\n 3.Insert At Begin");
		printf("\n 4.Insert At End");
		printf("\n 5.Insert At Position");
		printf("\n 6.Exit");
		printf("\nEnter your choice:");
	    scanf("%d",&choice);
	    switch(choice){
	    case 1:
	    	create();
	    	break;
	    case 2:
	    	traverse();
	    	break;
	    case 3:
	    	insert_begin();
	    	break;
	    case 4:
	    	insert_end();
	    	break;
	    case 5:
	    	insert_specifiedposition();
	    	break;
	    case 6:
	    	exit(0);
	    default:printf("\n invalid choice");
	}
	}
}
