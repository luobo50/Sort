#include"Sort.h"
#include<iostream>
#include<cstdlib>
#include<time.h>
#define MAX 100000000
using std::cout;
using std::cin;
using std::endl;
int main()
{
	srand(int(time(0)));
	int a[10005] = { 0 };
	int aT[10005] = { 0 };
	int b[50005] = { 0 };
	int bT[50005] = { 0 };
	int c[200005] = { 0 };
	int cT[200005] = { 0 };
	for (int i = 0; i < 10000; i++)
	{
		a[i] = rand() %MAX;
	}
	clock_t start = clock();
	MergeSort(a, 0, 10000, aT);
	clock_t diff = clock() - start;
	printf("MergeSort(10000)=%dms\n", diff);

	clock_t start = clock();
	MergeSort(b, 0, 50000, bT);
	clock_t diff = clock() - start;
	printf("MergeSort(50000)=%dms\n", diff);

	clock_t start = clock();
	MergeSort(c, 0, 200000, cT);
	clock_t diff = clock() - start;
	printf("MergeSort(200000)=%dms\n", diff);

	//C6262,нр©щак








}