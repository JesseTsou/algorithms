#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "generate.h"
#include "sort.h"
#include "print.h"


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
		insert_sort_fun(nums, sizeof(nums)/sizeof(int));
		print(nums, sizeof(nums)/sizeof(int));
	}
	else
	{
		int size = atoi(argv[1]);
		int nums[size];
		generate_nums(nums, size);

		print(nums, size);
		//insert_sort_fun(nums, size);
		shell_sort_fun(nums, size);
		t2 = time(&time2);
		printf("time2:%d\n", t2);

		print(nums, size);
	}

	printf("time:%d\n", t2 - t1);
	
	return 0;
}
