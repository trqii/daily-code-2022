#define _CRT_SECURE_NO_WARNINGS 1

/*
** BC98-序列中删除指定数字
** https://www.nowcoder.com/practice/7bbcdd2177a445a9b66da79512b32dd7?tpId=107&&tqId=33379&rp=1&ru=/ta/beginner-programmers&qru=/ta/beginner-programmers/question-ranking
*/

/*************************************

#include <stdio.h>

int main()
{
	int arr[50] = { 0 };
	int n, i, del;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &del);

	int j = 0;
	for (i = 0; i < n; i++)
	{
		if (arr[i] != del)
			arr[j++] = arr[i];
	}

	for (i = 0; i < j; i++)
		printf("%d ", arr[i]);

	return 0;
}

*************************************/

/*
** BC68-X形图案
** https://www.nowcoder.com/practice/83d6afe3018e44539c51265165806ee4?tpId=107&&tqId=33349&rp=1&ru=/ta/beginner-programmers&qru=/ta/beginner-programmers/question-ranking
*/

#include <stdio.h>

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j || i + j == n - 1)
					printf("*");
				else
					printf(" ");
			}
			printf("\n");
		}
	}

	return 0;
}