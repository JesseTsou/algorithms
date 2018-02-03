#include <stdio.h>
#include <string.h>

int handle(char *szbuf)
{
	int isstart = 0;
	int isspace = 0;
	char sznewbuf[128] = {0};
	char *szpos = szbuf;
	char *sznewpos = sznewbuf;

	printf("buf:%s!!!\n", szbuf);

	for (;*szpos != '\0'; szpos ++)
	{
		if (!isstart)
		{
			if (*szpos != ' ')
			{
				isstart = 1;
				*sznewpos = *szpos;
				sznewpos ++;
			}
		}
		else if (*szpos == ' ' && !isspace)
		{
			isspace = 1;
			*sznewpos = *szpos;
			sznewpos ++;
		}
		else if (*szpos != ' ')
		{
			isspace = 0;
			*sznewpos = *szpos;
			sznewpos ++;
		}
	}

	sznewbuf[strlen(sznewbuf) - 1] = '\0';
	printf("new buf:%s!!!\n", sznewbuf);

	return 0;
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("input error\n");
		return -1;
	}

	handle(argv[1]);
	return 0;
}
