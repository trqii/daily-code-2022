#define _CRT_SECURE_NO_WARNINGS 1

/*
** 1.模拟实现memcpy
*/

/*******************************************************

#include <stdio.h>
#include <assert.h>

void* my_memcpy(void* dest, const void* src, size_t count)
{
	assert(dest && src);
	void* ret = dest;

	while (count--)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return ret;
}

int main()
{
	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int arr2[5] = { 0 };

	my_memcpy(arr2, arr1 + 2, sizeof(int) * 5);

	int i = 0;
	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr2[i]);
	}
	return 0;
}

*******************************************************/

/*
** 2.模拟实现memmove
*/

#include <stdio.h>
#include <assert.h>

void* my_memmove(void* dest, const void* src, size_t count)
{
	assert(dest && src);
	void* ret = dest;

	if (dest < src)
	{
		// 从前向后拷贝
		while (count--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		// 从后向前拷贝
		while (count--)
		{
			*((char*)dest + count) = *((char*)src + count);
		}
	}
	return ret;
}

int main()
{
	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	my_memmove(arr1 + 5, arr1 + 2, sizeof(int) * 5);

	int i = 0;
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr1[i]);
	}

	return 0;
}