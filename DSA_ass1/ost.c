#include<stdio.h>
#include<stdlib.h>
typedef long long int lint;
typedef struct node
{
	lint  info;
	struct node *next;
} node;
node *head, *temp, *np, *tail;

void  push(lint  n)
{
	np = (node*)malloc(sizeof(node));
	

	if (head == NULL)
	{
		head = np;
		tail =np;
		head -> info = n;
	}
	else
	{
		//if (head ->info != n)
		np->next = head;
		head = np;
		head -> info =n;
	}
}

lint pop()
{
	lint n = head -> info;
	head = head -> next;
	
//	printf("popping %lld\n", n );
	return n;
}

void traverse()
{
	temp = head;
	if (temp == NULL)
		return;
	while(temp!=NULL)
	{
		printf("%lld    ", temp -> info );
		temp = temp -> next;
	}
		printf("\n");
}

lint a[1000001]={0};
lint less(lint a, lint b)
{
	if (a>b)
		return b;
	else
		return a;
}
int main()
{
	

	lint n;
	lint ans=0,n1,n2;
	scanf("%lld",&n);

	for(int i=0;i<n;i++)
	{
		scanf("%lld",a+i); 	//input arr
	}

	push(0);

	for(lint i=1;i<n;i++)
	{
//		printf("$%lld %lld\n", i, a[tail->info]);

		if(a[i] <= a[head->info] )
			push(i);

		else if (a[i] >= a[tail->info])
		{
//			printf("      %lld\n",a[tail->info]*(i-tail->info) );
			ans += a[tail->info]*(i-tail->info);
			head=NULL;
			push(i);
		}

		else
		{
//			traverse();
			n1 = pop();
			while (a[i]>a[head->info])
			{
				
				pop();
//				traverse();
				//head = head->next;
			}
			//ans+= a[n1]*(i - head -> info);
			push(i);
//			printf("hi\n");

		}


	}
//	printf("tra");
//	traverse();
//	printf("ans %lld \n",ans );

	temp = head;

	if (head != NULL)
	{
		if (head -> next ==NULL);

		while(head->next!=NULL)
		{
			n1= pop();
			//head = head->next;
		//	printf("bitch u thot\n");
			ans += a[n1]*(n1 - head -> info);
		//	printf("%lld      %lld\n", a[n1]*(n1- head->info), ans);
			//temp =temp->next;
		}
	}
	printf("%lld\n",ans );


	//traverse();

	
}