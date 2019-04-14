#include"Sort.h"
#include<stdio.h>
int main()
{
	int n;
	printf("先输入n，之后输入n个数\n");
	scanf("%d", &n);
	int count=0;
	int a[10000] = { 0 };
	int T[10000] = { 0 };
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		count++;
	}
	QuickSort_Recursion(a, 0, count);

	for (int j = 0; j < count; j++)
	{
		printf("%d", a[j]);
	}

}