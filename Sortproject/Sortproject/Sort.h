
#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include<iostream>
#include<stdlib.h>
using std::cout;
using std::endl;
using std::cin;
/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ��������
 *  @param       : ����ָ�� a, ���鳤�� n
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
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int *a, int begin, int mid, int end, int *temp)
{
	//������
}
/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
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
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
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
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
void QuickSort(int* a, int size) 
{
	//��������
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
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
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
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
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
int Getmaxwidth(int* a, int size)//�����λ��
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

/**  //��һ��Ӧ����
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
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


/**  //�ڶ���Ӧ����
 *  @name        : ����
 *  @description : ��һ�������������ҵ���K��/С����
 *  @param       : ����ָ��a�����鳤��size
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
