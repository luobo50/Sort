
#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include<iostream>
#include<stdlib.h>
using std::cout;
using std::endl;
using std::cin;
/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int *a, int n)
{
	int i, j;
	int temp;
	for (i = 1;i < n;i++)
	{
		for (j = 0;j < i;j++)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}

}
/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a, int begin, int mid, int end, int *temp)
{
	//汪汪汪
}
/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int *a, int begin, int end, int *temp)
{
	if (end - begin > 1)
	{
		int m = (begin + (end - begin) / 2);
		int p = begin, q = m, i = begin;
		MergeSort(a, begin, m, temp);
		MergeSort(a, m, end, temp);
		while (p < m || q < end)
		{
			if (q >= end || (p < m && a[p] <= a[q]))
				temp[i++] = a[p++];
			else
				temp[i++] = a[q++];
		}
		for (i = begin; i < end; i++)
			a[i] = temp[i];
	}
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int* a, int begin, int end)
{
	int i = begin;
	int j = end;
	int t;
	int temp = a[begin];
	if (begin > end)
		return;
	while (i != j)
	{
		while (i < j && a[j] >= temp)
		{
			j--;
		}
		while (i < j && a[i] <= temp)
		{
			i++;
		}
		if (i < j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	a[begin] = a[i];
	a[i] = temp;
	QuickSort_Recursion(a, begin, i - 1);
	QuickSort_Recursion(a, i + 1, end);
}



/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int* a, int size) 
{
	//喵喵喵？
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int* a, int begin, int end) 
{
	int pivot = a[begin];
	while (begin < end)
	{
		while (begin < end && a[--end] >= pivot)
			a[begin] = a[end];
		while (begin < end && a[begin++] <= pivot)
			a[end] = a[begin];
	}
	a[begin] = pivot;
	return begin;
}


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int *a, int size, int max)
{
	int *b = new int[max+1];
	int *c = new int[size];
	memset(b, 0, (max+1) * sizeof(int));
	memset(c, 0, size * sizeof(int));
	for (int i = 0;i < size;i++)
	{
		b[a[i]]++;
	}
	for (int i = 1;i < max + 1;i++)
	{
		b[i] = b[i] + b[i - 1];
	}
	for (int i = 0;i < size;i++)
	{
		b[a[i]]--;
		c[b[a[i]]] = a[i];
	}
	for (int i = 0;i < size;i++)
	{
		cout << c[i] << endl;
	}
	delete[]b;
	delete[]c;
}


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
int Getmaxwidth(int* a, int size)//求最大位数
{
	int max = a[0];
	int count = 0;
	for (int i = 1; i < size; i++)
	{
		if (max < a[i])
		{
			max = a[i];
		}
	}
	while (max > 0)
	{
		max /= 10;
		count++;
	}
	return count;
}
void RadixCountSort(int* a, int size)
{
	int width = Getmaxwidth(a, size);
	int count[10];
	int tmp[10];
	int i, j, k;
	int radix = 1;
	for (i = 1; i <= width; i++)
	{
		for (j = 0; j < 10; j++)
			count[j] = 0;
		for (j = 0; j < size; j++)
		{
			k = (a[j] / radix) % 10;
			count[k]++;
		}
		for (j = 1; j < 10; j++)
			count[j] = count[j - 1] + count[j];
		for (j = size - 1; j >= 0; j--)
		{
			k = (a[j] / radix) % 10;
			tmp[count[k] - 1] = a[j];
			count[k]--;
		}
		for (j = 0; j < size; j++)
			a[j] = tmp[j];
		radix *= 10;
	}
}

/**  //第一道应用题
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int* a, int size)
{
	int target = 1;
	int next_less_pos = 0;
	int next_bigger_pos = size - 1;
	int next_scan_pos = 0;
	int t = 0;
	while (next_scan_pos <= next_bigger_pos)
	{
		if (a[next_scan_pos] < target)
		{
			    t = a[next_scan_pos];
				a[next_scan_pos] = a[next_less_pos];
				a[next_less_pos] = t;
				next_scan_pos++;
				next_less_pos++;
		}
		else if (a[next_scan_pos] > target)
		{
			t = a[next_scan_pos];
			a[next_scan_pos] = a[next_bigger_pos];
			a[next_bigger_pos] = t;
			next_bigger_pos--;
		}
		else
		{
			next_scan_pos++;
		}
	}
}


/**  //第二道应用题
 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
 */
int Quickselect(int* a, int k, int size)
{
	int begin = 0, end = size;
	int target = 0;
	while (begin < end)
	{
		int pos = Partition(a, begin, end);
		if (pos == k - 1)
		{
			target = a[pos];
			break;
		}
		else if (pos > k - 1)
		{
			end = pos;
		}
		else
		{
			begin = pos + 1;
		}
	}
	return target;
}

#endif // QUEUE_H_INCLUDED
