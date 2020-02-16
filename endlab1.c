#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
};
struct node*insert(struct node*start,int x)
{
	struct node*p = start,*temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = NULL;
	if(start == NULL)
		start = temp;
	else
	{
		p = start;
		while(p->next != NULL)
			p = p->next;
		p->next = temp;
	}
	return(start);
}
void display(struct node*start)
{
	struct node*p = start;
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p = p->next;
	}
}
void printmax(struct node*start,struct node*p)
{
	if(p == NULL)
		return;
	struct node*q = p->next;
	int max;
	if(q!=NULL)
		max = q->data;
	while(q!=NULL)
	{
		if(q->data >= max)
			max = q->data;
		q = q->next;
	}
	q = p;
	while(q!=NULL&& q->next!=NULL)
	{
		if(q->next->data == max)
		{
			q->next = q->next->next;
			break;
		}
		q = q->next;
		if(q == NULL)
			break;
	}
	printf("\n");
	q = p->next;
	printmax(start,q);
	return;
}
int main()
{
	int n,i,x;
	struct node*start = NULL,*p;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		start = insert(start,x);
	}
	p = start;
	printmax(start,p);
	display(start);
	return(0);
}
