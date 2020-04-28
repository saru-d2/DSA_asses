#include<stdio.h>
#include<stdlib.h>
typedef long long int lint;
typedef struct node
{
	lint info;
	struct node *next;
} node;
node *head, *temp, *np;

void push(lint n)
{
	np = (node*)malloc(sizeof(node));
	if (head == NULL)
	{
		head = np;
		head -> info = n;
	}
	else
	{
		np->next = head;
		head = np;
		head -> info =n;
	}
}

lint  pop()
{
	lint n = head -> info;
	head = head -> next;
	return n;
}

void traverse()
{
	temp = head;
	if (temp == NULL)
		return;
	while(temp -> next != NULL)
	{
		printf("%lld    ", temp -> info );
		temp = temp -> next;
	}
}

int main()
{
	lint t,n, a[1000]={0},flag =1;;
	scanf("%lld",&t);
	while(t--)
	{
		head=NULL;
		for(int i=0;i<1000;i++)
			a[i]=0;
		//flag=1;
		scanf("%lld",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%lld",a+i);
		}

		int ctr=0;
		int j=0;

		while(ctr<n && j<=n)
		{
			
			//printf("   %d %d\n",ctr,j );
			if (a[j]==ctr+1)
				{ctr++;j++;}

			else if (head != NULL)
			{
				if (head -> info == ctr+1)
				{
					pop();
					ctr++;
				}

				else 
				{
					push(a[j]);
					j++;
				}
			}

			else
			{
				push(a[j]);
				j++;
			}
			

			//traverse();

		}


		if (head == NULL)
			printf("Yes\n");
		else
			printf("No\n");
	}
}