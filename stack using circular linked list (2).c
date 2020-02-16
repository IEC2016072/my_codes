//stack as circular linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node* next;
};

struct node* push(struct node* start,int x,int size,int *c)
{
	struct node* p;
	p=start;
	struct node* tmp;
	tmp=(struct node*)malloc(sizeof(struct node));
	if(*c==size)
	{
		printf("Overfow\n");
		return start;
	}
	if(p==NULL)
	{
		*c=*c+1;
		tmp->data=x;
		start=tmp;
		tmp->next=tmp;
		return start;
	}
	else
	{
		*c=*c+1;
		tmp->data=x;
		while(p->next!=start)
		p=p->next;
		p->next=tmp;
		tmp->next=start;
		return start;
	}
}

struct node* pop(struct node* start,int *c)
{
	int a;
	struct node *p,*q;
	p=start;
	q=start;
	if(p==NULL)
	{
		printf("Underflow\n");
		return start;
	}
	else
	{
		while(p->next!=start)
		{
			p=p->next;
			if(p->next!=start)
			q=q->next;
		}
		if(p!=q)
		{
			*c=*c-1;
			a=p->data;
			printf("Popped element is=%d\n",a);
			q->next=start;	
			return start;
		}
		else if(p==q)
		{
			*c=*c-1;
			a=p->data;
			printf("Popped element is=%d\n",a);
			start=NULL;
			return start;
		}
	}
}	
	
void display(struct node* start)
{
	struct node* p;
	p=start;
	while(p->next!=start)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("%d\n",p->data);
}
	
int main()
{
	int size,choice,x;
	int c=0;
	struct node* start;
	start=NULL;
	scanf("%d",&size);
	printf("1.push\n2.pop\n3.Display\n4.exit\n");
	while(1)
	{
		printf("Enter the choice=");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the element to push=");
				scanf("%d",&x);
				start=push(start,x,size,&c);
				break;
			case 2:
				start=pop(start,&c);				
				break;
			case 3:
				display(start);
				break;
			case 4:
				exit(1);
		}
	}
}
			
