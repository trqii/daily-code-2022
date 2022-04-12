#define _CRT_SECURE_NO_WARNINGS 1

/*
	1. C语言以二进制方式打开一个文件的方法是？( C )

	A.FILE *f = fwrite( "test.bin", "b" );
	B.FILE *f = fopenb( "test.bin", "w" );
	C.FILE *f = fopen( "test.bin", "wb" );
	D.FILE *f = fwriteb( "test.bin" );
*/

/*
	由于是要打开文件，AD直接排除，且没有B选项中的这个函数
	所以直接选C
*/

/*
	2. 关于fopen函数说法不正确的是：（ C ）

	A.fopen打开文件的方式是"r"，如果文件不存在，则打开文件失败
	B.fopen打开文件的方式是"w"，如果文件不存在，则创建该文件，打开成功
	C.fopen函数的返回值无需判断
	D.fopen打开的文件需要fclose来关闭
*/

/*
	C. fopen 函数的返回值用于检测文件是否打开成功
	所以在使用 fopen 函数时一定要对其返回值进行判断
	看看是否打开成功
*/

/*
	3. 下列关于文件名及路径的说法中错误的是：（ B ）

	A.文件名中有一些禁止使用的字符
	B.文件名中一定包含后缀名
	C.文件的后缀名决定了一个文件的默认打开方式
	D.文件路径指的是从盘符到该文件所经历的路径中各符号名的集合
*/

/*
	B.文件名中可以不包含后缀名
	A.文件名中不能包含字符 ：\ / : * ? " < > |
*/

/*
	4. C语言中关于文件读写函数说法不正确的是：（ B ）

	A.fgetc是适用于所有输入流字符输入函数
	B.getchar也是适用于所有流的字符输入函数
	C.fputs是适用于所有输出流的文本行输出函数
	D.fread是适用于文件输入流的二进制输入函数
*/

/*
	B.getchar 只针对标准输入流 stdin，即使对 stdin 重定向，getchar 针对的也只是 stdin
	AC.fgetc, fputs 是针对所有流的
*/

/*
	5. 下面程序的功能是什么?  ( B )

int main()
{
	long num=0;
	FILE *fp = NULL;
	if((fp=fopen("fname.dat","r"))==NULL)
	{
		printf("Can’t open the file! ");
		exit(0):
	}
	while(fgetc(fp) != EOF)
	{
		num++；
	}
	printf("num=%d\n",num);
	fclose(fp);
	return 0;
}

	A.拷贝文件
	B.统计文件的字符数
	C.统计文件的单词数
	D.统计文件的行数
*/

/*
	B.程序以只读的方式打开了一个文件，程序中使用了fgetc，且没有与 '\n' 相关的统计
*/

/*
	6. 下面说法不正确的是：（ D ）

	A.scanf和printf是针对标准输入、输出流的格式化输入、输出语句
	B.fscanf和fprintf是针对所有输入、输出流的格式化输入、输出语句
	C.sscanf是从字符串中读取格式化的数据
	D.sprintf是把格式化的数据写到输出流中
*/

/*
	D.sprintf是把格式化的数据写到字符串中，与输出流无关
*/

/*
	7. 通讯录3
	在之前的通讯录上增加两个函数，实现数据可以保存到文件，也可以从文件中加载数据。
	a. 添加一个函数，在退出通讯录的时候把信息到保存到文件中
	b. 添加一个函数，在通讯录打开的时候，可以把文件中的信息加载到通讯录中
*/

#include "contact.h"


// 打印菜单
void menu()
{
	printf("*****************************\n");
	printf("***** 1.add    2.del    *****\n");
	printf("***** 3.search 4.modify *****\n");
	printf("***** 5.print  6.remove *****\n");
	printf("***** 7.sort   0.exit   *****\n");
	printf("*****************************\n");
}


void test()
{
	int input = 0;
	// 创建通讯录
	contact con;
	// 初始化通讯录
	InitContact(&con);
	do
	{
		menu(); // 打印菜单
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con); // 增
			break;
		case DEL:
			DelContact(&con); // 删	
			break;
		case SEARCH:
			SearchContact(&con); // 查
			break;
		case MODIFY:
			ModifyContact(&con); // 改
			break;
		case PRINT:
			PrintContact(&con); // 显示
			break;
		case REMOVE:
			RemoveContact(&con); // 清除
			break;
		case SORT:
			SortContact(&con); // 排序
			break;
		case EXIT:
			SaveContact(&con); // 保存
			DestroyContact(&con); // 销毁
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}


	} while (input);
}


int main()
{
	test();
	return 0;
}