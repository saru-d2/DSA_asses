#include<stdio.h>

int main()
{
	char a[1000000];
	scanf("%[^\n]%*c",a);
	printf("%s",a);
}