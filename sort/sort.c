#include <stdio.h>
#include "sort.h"

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

			for (; tmp < a[j]; j --)
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

