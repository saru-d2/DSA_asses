#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>


typedef struct node
{
	double info;
	struct node *next;
} node;
node *head, *temp, *np;

void push(double n)
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

double  pop()
{
	double n = head -> info;
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
	//	printf("%d    ", temp -> info );
		temp = temp -> next;
	}
}

int main()
{
	int o;
	scanf("%d",&o);
	getchar();
	while(o--)
	{
		double n1,n2;
		char a[10000];
		
		scanf("%[^\n]%*c",a);
		//printf("hi\n");
		double num;
		int i=0;
		while(a[i]!='\0')
		{
			//printf("%d\n",i);
			traverse();
			if (isdigit(a[i]))
			{
				num = (int)a[i]-48;
				i++;
				while (isdigit(a[i]))
				{
					//printf("nooooo");
					num*=10.0;
					num+=(double)a[i]-48;
					i++;
				}
				//printf("num\n");
				push(num);
			}

			if(a[i]=='+')
			{
				n1=pop();
				n2=pop();
				push((double)(n1+n2));
			}
			if(a[i]=='-')
			{
				n1=pop();
				n2=pop();
				push((double)(n2-n1));
			}
			if(a[i]=='*')
			{
				n1=pop();
				n2=pop();
				push((double)(n1*n2));
			}
			if(a[i]=='/')
			{
				n1=pop();
				n2=pop();
			//	printf("%f %f %f \n",n2, n1, (double)n2/n1 );
				push((double)(n2/n1));
			}
			i++;

		//printf("hi\n");		
		}

		printf("%f\n", head -> info );
		head = NULL;
	}
}
			
