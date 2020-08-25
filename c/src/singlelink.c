#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node* create(struct node*);
struct node* display(struct node*);
struct node* insert_begin(struct node*);
struct node* insert_after(struct node*);
struct node* delete_beg(struct node*);
struct node* insert_before(struct node*);
struct node *start=NULL;
int main()
{
	int option;
	do
	{
		printf("\n########    MENU    ##########\n");
		printf("1.Create\n");
		printf("2.Insert beginning\n");
		printf("3.Insert before a node\n");
		printf("4.Insert after a node\n");
		printf("5.Display\n");
		printf("7.Delete Beginning node\n");
		printf("6.Exit\n");
		printf("Enter the option\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1: start=create(start);
					break;
			case 2: start=insert_begin(start);
					break;
			case 3:start=insert_before(start);
					break;
			case 4:start=insert_after(start);
					break;
			case 5:start=display(start);
					break;
			case 7:start=delete_beg(start);
					break;
		}	
	}while(option!=6);
}
struct node* delete_beg(struct node* start)
{
	struct node *ptr;
	ptr=start;
	if(start==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
	printf("%d is deleted",start->data);
	start=start->next;
	ptr->next=NULL;
	free(ptr);
	}
	return start;
}
struct node* create(struct node *start)
{
	int num;
	struct node *ptr,*new_node;
	printf("\nenter the data and 0 to stop");
	scanf("%d",&num);
	while(num!=0)
	{
		new_node=((struct node*)malloc(sizeof(struct node)));
		new_node->data=num;
		if(start==NULL)
		{
			new_node->next=NULL;
			start=new_node;
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=new_node;
			new_node->next=NULL;
		}
	printf("\nenter the data and 0 to stop\n");
	scanf("%d",&num);
		}
	return start;
}
struct node* display(struct node *start)
{
	struct node *ptr;
ptr=start;
if(start==NULL)
	{
		printf("list is empty\n");
	}
while(ptr!=NULL)
{
	printf("%d\t",ptr->data);
	ptr=ptr->next;
}
return start;
}	
		

struct node* insert_begin(struct node *start)
{
	int num;
	struct node *new_node;
printf("\nenter the data to insert at the before");
scanf("%d",&num);
new_node=((struct node*)malloc(sizeof(struct node)));
new_node->data=num;
new_node->next=start;
start=new_node;
return start;
}
struct node* insert_before(struct node *start)
{
	int numm,num;
	struct node *ptr,*new_node,*temp;
	printf("\nenter the node data before which data need to insert");
scanf("%d",&numm);
printf("\nenter the node data");
scanf("%d",&num);
new_node=((struct node*)malloc(sizeof(struct node)));
new_node->data=num;
ptr=start;
while(ptr->data!=numm)
{	temp=ptr;
	ptr=ptr->next;
}
temp->next=new_node;
new_node->next=ptr;	
return start;
}
struct node* insert_after(struct node *start)
{
	int numm,num;
	struct node *ptr,*new_node;
	printf("\nenter the node data after which data need to insert");
scanf("%d",&numm);
printf("\nenter the node data");
scanf("%d",&num);
new_node=((struct node*)malloc(sizeof(struct node)));
new_node->data=num;
ptr=start;
while(ptr->data!=numm)
{
	ptr=ptr->next;
}
new_node->next=ptr->next;
ptr->next=new_node;
return start;
}
