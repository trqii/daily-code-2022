#define _CRT_SECURE_NO_WARNINGS 1

/*
** BC70 - 空心三角形图案
** https://www.nowcoder.com/practice/2ccc5fca423e47f0b622fe6f151cfab4?tpId=107&&tqId=33351&rp=1&ru=/ta/beginner-programmers&qru=/ta/beginner-programmers/question-ranking
*/

/****************************************************

#include <stdio.h>

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (j == 1 || i == n || i == j)
					printf("* ");
				else
					printf("  ");
			}
			printf("\n");
		}
	}
	return 0;
}

****************************************************/


/*
** BC100-有序序列合并
** https://www.nowcoder.com/practice/a9e943b0dab142759807d0cfb6863897?tpId=107&&tqId=33381&rp=1&ru=/ta/beginner-programmers&qru=/ta/beginner-programmers/question-ranking
*/

#include <stdio.h>

int main()
{
	int arr1[1001] = { 0 };
	int arr2[1001] = { 0 };
	int res[2002] = { 0 };
	int n, m, i;

	// 输入
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%d", &arr1[i]);
	for (i = 0; i < m; i++)
		scanf("%d", &arr2[i]);

	int j = 0;
	int k = 0;
	i = 0;	
	
	// 处理
	while (j < n && k < m)
	{
		if (arr1[j] > arr2[k])
			res[i++] = arr2[k++];
		else
			res[i++] = arr1[j++];
	}
	// 第一个数组剩余
	while (j < n)			
		res[i++] = arr1[j++];			
	
	// 第二个数组剩余
	while (k < m)			
		res[i++] = arr2[k++];			
	
	for (i = 0; i < n + m; i++)
		printf("%d ", res[i]);

	return 0;
}