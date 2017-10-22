#include <stdio.h>
#include "sort.h"
#include "print.h"

/*直接插入排序
 */
int insert_sort_fun(int a[], int len)
{
	printf("start %s\n", __FUNCTION__);
	for (int i = 1; i < len; i ++)	
	{
		/*如果当前排序点小于前一点，则将前一点向后移，
		 *再继续与更前一点比较，同样，若小于更前一点，更前一点向移，
		 *直到当前排序点不小于前某点为止,
		 *将排序点插入前某点之后
		 */
		if (a[i] < a[i - 1])
		{
			int j = i - 1;
			int tmp = a[i];
			a[i] = a[i - 1];

			for (; tmp < a[j] && j >= 0; j --)
			{
				a[j + 1] = a[j];
			}

			a[j + 1] = tmp;
		}

		//printf("%03d:  ", i);
		//print(a, len);
	}

	printf("end sort\n");
	return 0;
}

/***********************************************************************/


/*希尔排序
 */
int shell_insert_sort(int a[], int len, int dk)
{
	for (int i = dk; i < len; i ++)	
	{
		if (a[i] < a[i - dk])
		{
			int j = i - dk;
			int tmp = a[i];
			a[i] = a[i - dk];

			while (j >= 0 && tmp < a[j])
			{
				a[j + dk] = a[j];
				j -= dk;
			}

			a[j + dk] = tmp;
		}

		//printf("%03d:  ", i);
		//print(a, len);
	}

	return 0;
}

/*选择一个增量序列t1，t2，…，tk，其中ti>tj，tk=1
 * 按增量序列个数k，对序列进行k 趟排序
 * 每次排序，所有距离为增量数值的记录放在同一个组中。先在各组内进行直接插入排序
 * 直到增量为1,所有序列在一个分组，直接进行插入排序为止
 */
int shell_sort_fun(int a[], int len)
{
	printf("start %s\n", __FUNCTION__);
	int b[] = {5,3,1};

	for (int i = 0; i < (sizeof(b)/sizeof(int)); i ++)
	{
		shell_insert_sort(a, len, b[i]);
	}

	printf("end sort\n");
	return 0;
}


/******************************************************************************/

/*简单选择排序
 * 选出最小的与第一个位置的作交换
 * 余下的数中，选出第二小的与第二个位置的作交换
 * 一直到最终
 */

int get_min(int a[], int i, int len)
{
	int flag = i;
	for (int j = i + 1; j < len; j ++)
	{
		if (a[j] < a[flag]) 
		{
			flag = j;
		}
	}

	return flag;
}

int select_sort_fun(int a[], int len)
{
	printf("start %s\n", __FUNCTION__);

	int flag = 0;
	for (int i = 0; i < len ; i ++)
	{
		flag = get_min(a, i, len);

		if (flag != i)
		{
			int tmp = a[i];
			a[i] = a[flag];
			a[flag] = tmp;
		}
		//printf("%03d:  ", i);
		//print(a, len);
	}

	printf("end sort\n");
	return 0;
}

/******************************************************************************/

/*二元选择法
 * 在二元排序的基础上，一次判断最大值与最小值，分别交换头尾数
 */

int get_min_max(int a[], int i, int len, int *min, int *max)
{
	*min = i;
	*max = i;
	for (int j = i + 1; j < len - i; j ++)
	{
		if (a[j] < a[*min]) 
		{
			*min = j;
			continue;
		}

		if (a[j] > a[*max]) 
		{
			*max = j;
		}
	}

	return 0;
}

int select_twoele_sort_fun(int a[], int len)
{
	printf("start %s\n", __FUNCTION__);

	int min_flag = 0;
	int max_flag = 0;
	for (int i = 0; i < len / 2 ; i ++)
	{
		get_min_max(a, i, len, &min_flag, &max_flag);

		int tmp = a[i];
		a[i] = a[min_flag];
		a[min_flag] = tmp;

		if (max_flag == i)
		{
			max_flag = min_flag;
		}

		tmp = a[len - i - 1];
		a[len - i - 1] = a[max_flag];
		a[max_flag] = tmp;
		//printf("%03d:  ", i);
		//print(a, len);
	}

	printf("end sort\n");
	return 0;
}

