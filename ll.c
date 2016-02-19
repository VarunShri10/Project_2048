#include<stdio.h>
void createnode(int value);
void display();
struct node
{
	int data;
	struct node *next;
}*start,*current;
void linkupdate(int no);
void linkupdate(int no)
{
	int length=0,temp,i;
	struct node *q;
	q=start;
	while(q!=NULL)
	{
		q=q->next;
		length++;
	}
	if(no>=1&&no<length)
	{
		q=start;
		temp=length-no;
		for(i=0;i<temp;i++)
		{
			q=q->next;	
		}
		q->data=(q->data)*2;
	}
}

void createnode(int value)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	if(start==NULL)
	{
		temp->data=value;
		temp->next=NULL;
		current=temp;
		start=temp;
	}
	else
	{
		temp->data=value;
		current->next=temp;
		temp->next=NULL;
		current=temp;
	}
}

void display()
{
	struct node *q;
	q=start;
	if(start==NULL)
	printf("Underflow");
	else
	while(q!=NULL)
	{
		printf("%d ",q->data);
		q=q->next;
	}
}
int main()
{
 int value,no;
	printf("Enter Values : ");
	scanf("%d",&value);
	while(value!=(-1))
	{
		createnode(value);
		scanf("%d",&value);
	}
	display();
	printf("Enter No of update : ");
	scanf("%d",&no);
	linkupdate(no);
	display();
	getch();
	return 0;
}
