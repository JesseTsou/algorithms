#include <stdio.h>

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

