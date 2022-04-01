#define _CRT_SECURE_NO_WARNINGS 1

/*
** 1. 模拟实现strlen
*/

/*************************************************************

#include <stdio.h>
#include <assert.h>

// 1.计数器方式
size_t my_strlen1(const char* str)
{
	assert(str); // 断言保证传入指针的有效性
	size_t count = 0; // 计数器
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

// 2.递归方式（不创建临时变量）
size_t my_strlen2(const char* str)
{
	assert(str); 
	if (*str != '\0')
	{
		return 1 + my_strlen2(str + 1);
	}
	else
	{
		return 0;
	}
}

// 3.指针-指针方式
size_t my_strlen3(const char* str)
{
	assert(str);
	const char* end = str;
	while (*end != '\0')
	{
		end++;
	}
	return end - str; // 两指针之间的差值，即为元素个数
}

int main()
{
	char arr[] = "test strlen";

	printf("%u\n", my_strlen1(arr));
	printf("%u\n", my_strlen2(arr));
	printf("%u\n", my_strlen3(arr));

	return 0;
}

*************************************************************/

/*
** 2. 模拟实现strcpy
*/

/*************************************************************

#include <stdio.h>
#include <assert.h>

char* my_strcpy(char* dest, const char* src)
{
	assert(dest && src);
	char* ret = dest;
	while (*dest++ = *src++) // 拷贝
	{
		;
	}
	return ret;
}

int main()
{
	char arr1[50] = { 0 };
	char arr2[] = "test strcpy";

	my_strcpy(arr1, arr2);

	printf("%s\n", arr1);

	return 0;
}

*************************************************************/

/*
** 3. 模拟实现strcmp
*/

/*************************************************************

#include <stdio.h>
#include <assert.h>

int my_strcmp(const char* s1, const char* s2)
{
	assert(s1 && s2);
	while (*s1 == *s2)
	{
		if (*s1 == '\0') // 两字符串相等
		{
			return 0;
		}
		s1++;
		s2++;
	}
	return *s1 - *s2; // 两字符串不相等，返回差值
}

int main()
{
	printf("%d\n", my_strcmp("abc", "abc"));
	printf("%d\n", my_strcmp("abd", "abc"));
	printf("%d\n", my_strcmp("abc", "abd"));

	return 0;
}

*************************************************************/

/*
** 4. 模拟实现strcat
*/

/*************************************************************

#include <stdio.h>
#include <assert.h>

char* my_strcat(char* dest, const char* src)
{
	assert(dest && src);
	char* ret = dest;
	while (*dest != '\0') // 找 dest 中 '\0'的位置
	{
		dest++;
	}
	while (*dest++ = *src++) // 拷贝（同strcpy）
	{
		;
	}
	return ret;
}

int main()
{
	char arr1[50] = "test";
	char arr2[] = " strcat";

	my_strcat(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}

*************************************************************/

/*
** 5. 模拟实现strcat
*/

#include <stdio.h>
#include <assert.h>

char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	const char* s1 = str1;
	const char* s2 = str2;
	const char* cur = str1;
	while (*cur)
	{ 
		s1 = cur;  // 从当前位置，开始向后匹配
		s2 = str2; // 匹配失败，回到开头重新开始
		while (*s1 && *s2 && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0') // 找到了
		{
			return (char*)cur;
		}
		cur++; // 从下一个位置开始
	}
	return NULL; // 找不到
}
int main()
{
	char arr1[] = "abdabfabc";
	char arr2[] = "abc";

	printf("%s\n", my_strstr(arr1, arr2));

	return 0;
}