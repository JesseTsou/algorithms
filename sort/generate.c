#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int generate_nums(int *a, int size)
{
	if (a)
	{
		srand((unsigned)time(NULL));
		for (int i = 0; i < size; i ++)
		{
			a[i] = rand() % size;
		}
	}
	
	return 0;
}
