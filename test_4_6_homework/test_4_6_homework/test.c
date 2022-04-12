#define _CRT_SECURE_NO_WARNINGS 1

/*
	1. C�����Զ����Ʒ�ʽ��һ���ļ��ķ����ǣ�( C )

	A.FILE *f = fwrite( "test.bin", "b" );
	B.FILE *f = fopenb( "test.bin", "w" );
	C.FILE *f = fopen( "test.bin", "wb" );
	D.FILE *f = fwriteb( "test.bin" );
*/

/*
	������Ҫ���ļ���ADֱ���ų�����û��Bѡ���е��������
	����ֱ��ѡC
*/

/*
	2. ����fopen����˵������ȷ���ǣ��� C ��

	A.fopen���ļ��ķ�ʽ��"r"������ļ������ڣ�����ļ�ʧ��
	B.fopen���ļ��ķ�ʽ��"w"������ļ������ڣ��򴴽����ļ����򿪳ɹ�
	C.fopen�����ķ���ֵ�����ж�
	D.fopen�򿪵��ļ���Ҫfclose���ر�
*/

/*
	C. fopen �����ķ���ֵ���ڼ���ļ��Ƿ�򿪳ɹ�
	������ʹ�� fopen ����ʱһ��Ҫ���䷵��ֵ�����ж�
	�����Ƿ�򿪳ɹ�
*/

/*
	3. ���й����ļ�����·����˵���д�����ǣ��� B ��

	A.�ļ�������һЩ��ֹʹ�õ��ַ�
	B.�ļ�����һ��������׺��
	C.�ļ��ĺ�׺��������һ���ļ���Ĭ�ϴ򿪷�ʽ
	D.�ļ�·��ָ���Ǵ��̷������ļ���������·���и��������ļ���
*/

/*
	B.�ļ����п��Բ�������׺��
	A.�ļ����в��ܰ����ַ� ��\ / : * ? " < > |
*/

/*
	4. C�����й����ļ���д����˵������ȷ���ǣ��� B ��

	A.fgetc�������������������ַ����뺯��
	B.getcharҲ�����������������ַ����뺯��
	C.fputs��������������������ı����������
	D.fread���������ļ��������Ķ��������뺯��
*/

/*
	B.getchar ֻ��Ա�׼������ stdin����ʹ�� stdin �ض���getchar ��Ե�Ҳֻ�� stdin
	AC.fgetc, fputs �������������
*/

/*
	5. �������Ĺ�����ʲô?  ( B )

int main()
{
	long num=0;
	FILE *fp = NULL;
	if((fp=fopen("fname.dat","r"))==NULL)
	{
		printf("Can��t open the file! ");
		exit(0):
	}
	while(fgetc(fp) != EOF)
	{
		num++��
	}
	printf("num=%d\n",num);
	fclose(fp);
	return 0;
}

	A.�����ļ�
	B.ͳ���ļ����ַ���
	C.ͳ���ļ��ĵ�����
	D.ͳ���ļ�������
*/

/*
	B.������ֻ���ķ�ʽ����һ���ļ���������ʹ����fgetc����û���� '\n' ��ص�ͳ��
*/

/*
	6. ����˵������ȷ���ǣ��� D ��

	A.scanf��printf����Ա�׼���롢������ĸ�ʽ�����롢������
	B.fscanf��fprintf������������롢������ĸ�ʽ�����롢������
	C.sscanf�Ǵ��ַ����ж�ȡ��ʽ��������
	D.sprintf�ǰѸ�ʽ��������д���������
*/

/*
	D.sprintf�ǰѸ�ʽ��������д���ַ����У���������޹�
*/

/*
	7. ͨѶ¼3
	��֮ǰ��ͨѶ¼����������������ʵ�����ݿ��Ա��浽�ļ���Ҳ���Դ��ļ��м������ݡ�
	a. ���һ�����������˳�ͨѶ¼��ʱ�����Ϣ�����浽�ļ���
	b. ���һ����������ͨѶ¼�򿪵�ʱ�򣬿��԰��ļ��е���Ϣ���ص�ͨѶ¼��
*/

#include "contact.h"


// ��ӡ�˵�
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
	// ����ͨѶ¼
	contact con;
	// ��ʼ��ͨѶ¼
	InitContact(&con);
	do
	{
		menu(); // ��ӡ�˵�
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con); // ��
			break;
		case DEL:
			DelContact(&con); // ɾ	
			break;
		case SEARCH:
			SearchContact(&con); // ��
			break;
		case MODIFY:
			ModifyContact(&con); // ��
			break;
		case PRINT:
			PrintContact(&con); // ��ʾ
			break;
		case REMOVE:
			RemoveContact(&con); // ���
			break;
		case SORT:
			SortContact(&con); // ����
			break;
		case EXIT:
			SaveContact(&con); // ����
			DestroyContact(&con); // ����
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}


	} while (input);
}


int main()
{
	test();
	return 0;
}