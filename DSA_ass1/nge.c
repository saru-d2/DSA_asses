#include <stdio.h>
#include <stdlib.h>
typedef long long int lint;
typedef struct node
{
	lint info;
	struct node *next;
} node;
node *head, *temp, *np;

void push(lint n)
{
	np = (node *)malloc(sizeof(node));

	if (head == NULL)
	{
		head = np;
		head->info = n;
	}
	else
	{
		np->next = head;
		head = np;
		head->info = n;
	}
}

lint pop()
{
	lint n = head->info;
	head = head->next;
	return n;
}

void traverse()
{
	temp = head;
	if (temp == NULL)
		return;
	while (temp->next != NULL)
	{
		printf("%lld    ", temp->info);
		temp = temp->next;
	}
	printf("\n");
}
lint a[1000005];
int main()
{

	lint n;
	lint max = 0, tmp;
	scanf("%lld", &n);

	for (lint i = 0; i < n; i++)
	{
		scanf("%lld", a + i);
	}
	push(0);

	push(a[0]);
	for (lint i = 0; i < n; i++)
	{
		if (head->info > a[i] && a[i] != head->info)
			push(a[i]);
		else
		{

			temp = head;
			while (a[i] > head->info && head->info != 0)
			{
				pop();
				if (head->info * a[i] > max)
				{
					max = head->info * a[i];
				}
				if (head->info != a[i])
					temp = temp->next;
			}
			if (a[i] != head->info)
				push(a[i]);
		}
	}
	printf("%lld\n", max);
}