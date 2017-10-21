#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "generate.h"

int print(int *a, int len)
{
	if (len <= 1000)
	{
		printf("    ");
		for (int i = 0; i < len; i ++)
		{
			printf("%d ", *(a + i));
		}
		printf("\n");
	}

	return 0;
}

int sort_fun(int a[], int len)
{
	printf("\nstart sort\n");
	for (int i = 1; i < len; i ++)	
	{
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

	printf("\nend sort\n");
	return 0;
}

int main(int argc, char **argv)
{
	time_t time1;
	time_t time2;
	int t1,t2;

	t1 = time(&time1);
	printf("time1:%d\n", t1);
	if (argc == 1)
	{
		int nums[] = {100,55,34,12,76,11,13,1,11,6,7,4,7,14};

		print(nums, sizeof(nums)/sizeof(int));
		sort_fun(nums, sizeof(nums)/sizeof(int));
		print(nums, sizeof(nums)/sizeof(int));
	}
	else
	{
		int size = atoi(argv[1]);
		int nums[size];
		generate_nums(nums, size);

		print(nums, size);
		sort_fun(nums, size);
		t2 = time(&time2);
		printf("time2:%d\n", t2);

		print(nums, size);
	}

	printf("time:%d\n", t2 - t1);
	
	return 0;
}
