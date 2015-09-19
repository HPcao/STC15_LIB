/*
 * Copyright (c) 2015
 * All rights reserved.
 *
 * �ļ����ƣ� tools.c
 * �ļ���ʶ�� �����ù���ƻ���
 * ժ    Ҫ�� С���߼���
 *
 * ��ǰ�汾�� 1.1
 * ������int2string_lcd����
 * �� �ߣ� ��˧
 * ������ڣ� 2015��8��4��
 *
 * ��ʷ�汾�� 1.0
 * �� �ߣ� ��˧
 * ������ڣ� 2015��8��3��
 */

#include <stdio.h>
#include <string.h>

/*
 * �������ܣ�int����ת��Ϊ�ַ���
 * ���������x: Ҫת����int
 * ���������strDest��Ŀ���ַ������ַ��
 * ����ֵ  ��Ŀ���ַ������ַstrDest
 */
char *int2string(char *strDest, int x)
{
	//assert(strDest != NULL);
	int  tmp = x;
	char   i = 0;
	char len = 1;
	char string[10];
	char flag = 0;		//������־

	if(x >= 0)
	{
		flag = 1;
	}
	else
	{
		flag = 0;
		x = -x;
	}

	while (tmp /= 10)
	{
		len++;
	}

	if (flag)
	{
		for (i=0; i < len; i++)
		{
			string[len-i-1] = x%10 + '0';
			x /= 10;
		}
		string[len] = '\0';
	}
	else
	{
		string[0] = '-';
		for (i=0; i < len; i++)
		{
			string[len-i] = x%10 + '0';
			x /= 10;
		}
		string[len+1] = '\0';
	}//end of if

	return strcpy(strDest, string);
}

/*
 * �������ܣ�int����ת��Ϊ�ַ���(��lcd��ʾ֮�� ������)
 * ���������x: Ҫת����int��m��lcd�ַ���ʾλ��
 * ���������strDest��Ŀ���ַ������ַ��
 * ����ֵ  ��Ŀ���ַ������ַstrDest
 */
char *int2string_lcd(char *strDest, int x, char m)
{
	//assert(strDest != NULL);
	int  tmp = x;
	char   i = 0;
	char len = 1;
	char string[10];
	char flag = 0;		//������־

	if(x >= 0)
	{
		flag = 1;
	}
	else
	{
		flag = 0;
		x = -x;
	}

	while (tmp /= 10)
	{
		len++;
	}

	if (flag)
	{
		for (i=0; i < len; i++)
		{
			string[m-i-1] = x%10 + '0';
			x /= 10;
		}

		for (i=0; i < m-len; i++)
		{
			string[i] = ' ';
		}
		string[m] = '\0';
	}
	else
	{
		for (i=0; i < m-len-1; i++)
		{
			string[i] = ' ';
		}

		string[i] = '-';

		for (i=0; i < len; i++)
		{
			string[m-i-1] = x%10 + '0';
			x /= 10;
		}

		string[m] = '\0';
	}//end of if

	return strcpy(strDest, string);
}



