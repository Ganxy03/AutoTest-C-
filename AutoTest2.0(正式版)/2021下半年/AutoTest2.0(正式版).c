#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

//AutoTest�汾2.0			//��Դ����
FILE* fp;					//ת�ر�ע��ԭ����Ganxy ���Ƕ�������֧��
int pan[20]={0};			//����blog.ganxy03.cn
int randnum;				//Github:https://github.com/Ganxy03
int count=0;

void Tm();					//��Դ����
void Intro();				//ת�ر�ע��ԭ����Ganxy ���Ƕ�������֧��
void Menu();				//����blog.ganxy03.cn
void Radm();				//Github:https://github.com/Ganxy03
void NoRepet();
int Exit();
void ChooseBank();
void Choese();				//��Դ����
struct ques {				//ת�ر�ע��ԭ����Ganxy ���Ƕ�������֧��
	char question[300];		//����blog.ganxy03.cn
	char select[5][200];	//Github:https://github.com/Ganxy03
	char temp[2];
	char answer;
}a[30];						//��Դ����
void Tm()					//ת�ر�ע��ԭ����Ganxy ���Ƕ�������֧��
{							//����blog.ganxy03.cn
	time_t timep;			//Github:https://github.com/Ganxy03
	time(&timep);
	struct tm* p = gmtime(&timep);
	printf("��ǰʱ�䣨����ʱ�䣩��%d/%d/%d", (1900 + p->tm_year), (1 + p->tm_mon), p->tm_mday);
	printf(" %d:%d:%d\n", (8 + p->tm_hour), p->tm_min, p->tm_sec);	
}
void Intro()
{
	printf("Title:AutoTEST(2.0���԰�)\n");
	printf("Author:Ganxy(ID���������һ����)\n");
	printf("Date:2023/2/6\n");
	printf("Intro:Ĭ�ϰ���ʡһģ��������ѡ���⣬ͨ���޸�����ַ����������;,\n���͵�ַhttp://blog.ganxy03.cn/?p=123\nԴ���עhttps://github.com/Ganxy03\n������ú�������ҵĲ��͵��޻��߸���Github Star��\n>>���ʹ�� �޳�����<<\n���Ż�:\n1.�˵�ѡ����ĸ��ѭ��\n2.���������ʾ���̣������� ÿ�����30��ˢ����ʾ����ӭ�´�ʹ����ʾ��\n3.����˵���ʾ������\n4.����һ����Ȼس�\n");
	printf("\n");			//��Դ����
	printf("\n");			//ת�ر�ע��ԭ����Ganxy ���Ƕ�������֧��
	printf("\n");			//����blog.ganxy03.cn
	printf("\n");			//Github:https://github.com/Ganxy03
}
void Menu()
{
	printf("**** �˵� ****\n");
	printf("*** 1.��ʼ ***\n");
	printf("*** 0.�˳� ***\n");
	printf("**************\n");
	printf("\n");
}
void Menu2()
{
	printf("**** ѡ����� ****\n");
	printf("**** 1.��һ�� ****\n");
	printf("**** 2.�ڶ��� ****\n");
	printf("**** 3.������ ****\n");
	printf("**** 4.������ ****\n");
	printf("**** 5.������ ****\n");
	printf("**** 6.������ ****\n");
	printf("******************\n");
	printf("\n");	
}
int SetQus1()
{
	system("cls");
	Intro();
	printf("\n");
	Tm();
	FILE* fp = NULL;
	fp = fopen("2021�°���ѡ��ģ�����/��һ��.txt", "r");
	if (fp == NULL)
	{
		printf("�ļ���ʧ�ܣ��������λ��\n");
	}
	for(int i=1;i<=30;i++)
	{
		fgets(a[i].question, 300, fp);
		for(int j=1;j<=4;j++)
		{
			fgets(a[i].select[j], 200, fp);
		}
		fgets(a[i].temp, 5, fp);
		a[i].answer=*a[i].temp;
	}
	int count=0;
	while(count>=0)
	{
Start:
		system("cls");
		Intro();
		printf("\n");
		Tm();
		char an;
		printf(">>���ǵ�һ��ѡ��(֧��ʶ��Сд)\n");
		printf("%s",a[count+1].question);
		for(int j=1;j<=4;j++)
		{
			printf("%s",a[count+1].select[j]);
		}
		printf("ѡ��>>");
		scanf("%c",&an);
		if(an>='a'&&an<='d')
		{
			an-=32;
			if(an==a[count+1].answer)
			{
				printf("Binggo������� (������ӻس��˳� / ֱ�ӻس�������һ��)\n");
			}
			else
			{
				printf("�ش����\n");
				printf("��ȷ���ǣ�%c(������ӻس��˳� / ֱ�ӻس�������һ��)\n",a[count+1].answer);
			}
		}
		else if(an>='A'&&an<='D')
		{
			if(an==a[count+1].answer)
			{
			printf("Binggo������� (������ӻس��˳� / ֱ�ӻس�������һ��)\n");
			}
			else
			{
				printf("�ش����\n");
				printf("��ȷ���ǣ�%c(������ӻس��˳� / ֱ�ӻس�������һ��)\n",a[count+1].answer);
			}
		}
		else
		{
			printf("��������ȷ��ѡ��(������ӻس��˳� / ֱ�ӻس�������һ��)\n");			//��仰��������
			char flag1;
			char temp1;
			scanf("%c",&temp1);
			flag1=getchar();
			if(flag1!='\n')
			{
			printf("��ϲ���Ѿ�ˢ��%d�� \n",count);
			printf("��ӭ�´�ʹ��\n");
			exit(1);
			}
			goto Start;
		}
		count++;
		char flag2;
		char temp;
		scanf("%c", &temp);
		flag2=getchar();
		if(flag2!='\n')
		{
			printf("��ϲ���Ѿ�ˢ��%d�� \n",count);
			printf("��ӭ�´�ʹ��\n");
			exit(1);
		}
		if(count==30)
		{
			printf("��ϲ���Ѿ�ˢ��%d�⣬��һ���Ѿ�ˢ����\n",count);
			printf("��ӭ�´�ʹ��\n");
			exit(1);
		}
	}
	return 1;
}
int SetQus2()
{
	system("cls");
	Intro();
	printf("\n");
	Tm();
	FILE* fp = NULL;
	fp = fopen("2021�°���ѡ��ģ�����/�ڶ���.txt", "r");
	if (fp == NULL)
	{
		printf("�ļ���ʧ�ܣ��������λ��\n");
	}
	for(int i=1;i<=30;i++)
	{
		fgets(a[i].question, 300, fp);
		for(int j=1;j<=4;j++)
		{
			fgets(a[i].select[j], 200, fp);
		}
		fgets(a[i].temp, 5, fp);
		a[i].answer=*a[i].temp;
	}
	int count=0;
	while(count>=0)
	{
Start:
		system("cls");
		Intro();
		printf("\n");
		Tm();
		char an;
		printf(">>���ǵڶ���ѡ��(֧��ʶ��Сд)\n");
		printf("%s",a[count+1].question);
		for(int j=1;j<=4;j++)
		{
			printf("%s",a[count+1].select[j]);
		}
		printf("ѡ��>>");
		scanf("%c",&an);
		if(an>='a'&&an<='d')
		{
			an-=32;
			if(an==a[count+1].answer)
			{
				printf("Binggo������� (������ӻس��˳� / ֱ�ӻس�������һ��)\n");
			}
			else
			{
				printf("�ش����\n");
				printf("��ȷ���ǣ�%c(������ӻس��˳� / ֱ�ӻس�������һ��)\n",a[count+1].answer);
			}
		}
		else if(an>='A'&&an<='D')
		{
			if(an==a[count+1].answer)
			{
			printf("Binggo������� (������ӻس��˳� / ֱ�ӻس�������һ��)\n");
			}
			else
			{
				printf("�ش����\n");
				printf("��ȷ���ǣ�%c(������ӻس��˳� / ֱ�ӻس�������һ��)\n",a[count+1].answer);
			}
		}
		else
		{
			printf("��������ȷ��ѡ��(������ӻس��˳� / ֱ�ӻس�������һ��)\n");			//��仰��������
			char flag1;
			char temp1;
			scanf("%c",&temp1);
			flag1=getchar();
			if(flag1!='\n')
			{
			printf("��ϲ���Ѿ�ˢ��%d�� \n",count);
			printf("��ӭ�´�ʹ��\n");
			exit(1);
			}
			goto Start;
		}
		count++;
		char flag2;
		char temp;
		scanf("%c", &temp);
		flag2=getchar();
		if(flag2!='\n')
		{
			printf("��ϲ���Ѿ�ˢ��%d�� \n",count);
			printf("��ӭ�´�ʹ��\n");
			exit(1);
		}
		if(count==30)
		{
			printf("��ϲ���Ѿ�ˢ��%d�⣬��һ���Ѿ�ˢ����\n",count);
			printf("��ӭ�´�ʹ��\n");
			exit(1);
		}
	}
	return 1;
}
int SetQus3()
{
	system("cls");
	Intro();
	printf("\n");
	Tm();
	FILE* fp = NULL;
	fp = fopen("2021�°���ѡ��ģ�����/������.txt", "r");
	if (fp == NULL)
	{
		printf("�ļ���ʧ�ܣ��������λ��\n");
	}
	for(int i=1;i<=30;i++)
	{
		fgets(a[i].question, 300, fp);
		for(int j=1;j<=4;j++)
		{
			fgets(a[i].select[j], 200, fp);
		}
		fgets(a[i].temp, 5, fp);
		a[i].answer=*a[i].temp;
	}
	int count=0;
	while(count>=0)
	{
Start:
		system("cls");
		Intro();
		printf("\n");
		Tm();
		char an;
		printf(">>���ǵ�����ѡ��(֧��ʶ��Сд)\n");
		printf("%s",a[count+1].question);
		for(int j=1;j<=4;j++)
		{
			printf("%s",a[count+1].select[j]);
		}
		printf("ѡ��>>");
		scanf("%c",&an);
		if(an>='a'&&an<='d')
		{
			an-=32;
			if(an==a[count+1].answer)
			{
				printf("Binggo������� (������ӻس��˳� / ֱ�ӻس�������һ��)\n");
			}
			else
			{
				printf("�ش����\n");
				printf("��ȷ���ǣ�%c(������ӻس��˳� / ֱ�ӻس�������һ��)\n",a[count+1].answer);
			}
		}
		else if(an>='A'&&an<='D')
		{
			if(an==a[count+1].answer)
			{
			printf("Binggo������� (������ӻس��˳� / ֱ�ӻس�������һ��)\n");
			}
			else
			{
				printf("�ش����\n");
				printf("��ȷ���ǣ�%c(������ӻس��˳� / ֱ�ӻس�������һ��)\n",a[count+1].answer);
			}
		}
		else
		{
			printf("��������ȷ��ѡ��(������ӻس��˳� / ֱ�ӻس�������һ��)\n");			//��仰��������
			char flag1;
			char temp1;
			scanf("%c",&temp1);
			flag1=getchar();
			if(flag1!='\n')
			{
			printf("��ϲ���Ѿ�ˢ��%d�� \n",count);
			printf("��ӭ�´�ʹ��\n");
			exit(1);
			}
			goto Start;
		}
		count++;
		char flag2;
		char temp;
		scanf("%c", &temp);
		flag2=getchar();
		if(flag2!='\n')
		{
			printf("��ϲ���Ѿ�ˢ��%d�� \n",count);
			printf("��ӭ�´�ʹ��\n");
			exit(1);
		}
		if(count==30)
		{
			printf("��ϲ���Ѿ�ˢ��%d�⣬��һ���Ѿ�ˢ����\n",count);
			printf("��ӭ�´�ʹ��\n");
			exit(1);
		}
	}
	return 1;
}
int SetQus4()
{
	system("cls");
	Intro();
	printf("\n");
	Tm();
	FILE* fp = NULL;
	fp = fopen("2021�°���ѡ��ģ�����/������.txt", "r");
	if (fp == NULL)
	{
		printf("�ļ���ʧ�ܣ��������λ��\n");
	}
	for(int i=1;i<=30;i++)
	{
		fgets(a[i].question, 300, fp);
		for(int j=1;j<=4;j++)
		{
			fgets(a[i].select[j], 200, fp);
		}
		fgets(a[i].temp, 5, fp);
		a[i].answer=*a[i].temp;
	}
	int count=0;
	while(count>=0)
	{
Start:
		system("cls");
		Intro();
		printf("\n");
		Tm();
		char an;
		printf(">>���ǵ�����ѡ��(֧��ʶ��Сд)\n");
		printf("%s",a[count+1].question);
		for(int j=1;j<=4;j++)
		{
			printf("%s",a[count+1].select[j]);
		}
		printf("ѡ��>>");
		scanf("%c",&an);
		if(an>='a'&&an<='d')
		{
			an-=32;
			if(an==a[count+1].answer)
			{
				printf("Binggo������� (������ӻس��˳� / ֱ�ӻس�������һ��)\n");
			}
			else
			{
				printf("�ش����\n");
				printf("��ȷ���ǣ�%c(������ӻس��˳� / ֱ�ӻس�������һ��)\n",a[count+1].answer);
			}
		}
		else if(an>='A'&&an<='D')
		{
			if(an==a[count+1].answer)
			{
			printf("Binggo������� (������ӻس��˳� / ֱ�ӻس�������һ��)\n");
			}
			else
			{
				printf("�ش����\n");
				printf("��ȷ���ǣ�%c(������ӻس��˳� / ֱ�ӻس�������һ��)\n",a[count+1].answer);
			}
		}
		else
		{
			printf("��������ȷ��ѡ��(������ӻس��˳� / ֱ�ӻس�������һ��)\n");			//��仰��������
			char flag1;
			char temp1;
			scanf("%c",&temp1);
			flag1=getchar();
			if(flag1!='\n')
			{
			printf("��ϲ���Ѿ�ˢ��%d�� \n",count);
			printf("��ӭ�´�ʹ��\n");
			exit(1);
			}
			goto Start;
		}
		count++;
		char flag2;
		char temp;
		scanf("%c", &temp);
		flag2=getchar();
		if(flag2!='\n')
		{
			printf("��ϲ���Ѿ�ˢ��%d�� \n",count);
			printf("��ӭ�´�ʹ��\n");
			exit(1);
		}
		if(count==30)
		{
			printf("��ϲ���Ѿ�ˢ��%d�⣬��һ���Ѿ�ˢ����\n",count);
			printf("��ӭ�´�ʹ��\n");
			exit(1);
		}
	}
	return 1;
}
int SetQus5()
{
	system("cls");
	Intro();
	printf("\n");
	Tm();
	FILE* fp = NULL;
	fp = fopen("2021�°���ѡ��ģ�����/������.txt", "r");
	if (fp == NULL)
	{
		printf("�ļ���ʧ�ܣ��������λ��\n");
	}
	for(int i=1;i<=30;i++)
	{
		fgets(a[i].question, 300, fp);
		for(int j=1;j<=4;j++)
		{
			fgets(a[i].select[j], 200, fp);
		}
		fgets(a[i].temp, 5, fp);
		a[i].answer=*a[i].temp;
	}
	int count=0;
	while(count>=0)
	{
Start:
		system("cls");
		Intro();
		printf("\n");
		Tm();
		char an;
		printf(">>���ǵ�����ѡ��(֧��ʶ��Сд)\n");
		printf("%s",a[count+1].question);
		for(int j=1;j<=4;j++)
		{
			printf("%s",a[count+1].select[j]);
		}
		printf("ѡ��>>");
		scanf("%c",&an);
		if(an>='a'&&an<='d')
		{
			an-=32;
			if(an==a[count+1].answer)
			{
				printf("Binggo������� (������ӻس��˳� / ֱ�ӻس�������һ��)\n");
			}
			else
			{
				printf("�ش����\n");
				printf("��ȷ���ǣ�%c(������ӻس��˳� / ֱ�ӻس�������һ��)\n",a[count+1].answer);
			}
		}
		else if(an>='A'&&an<='D')
		{
			if(an==a[count+1].answer)
			{
			printf("Binggo������� (������ӻس��˳� / ֱ�ӻس�������һ��)\n");
			}
			else
			{
				printf("�ش����\n");
				printf("��ȷ���ǣ�%c(������ӻس��˳� / ֱ�ӻس�������һ��)\n",a[count+1].answer);
			}
		}
		else
		{
			printf("��������ȷ��ѡ��(������ӻس��˳� / ֱ�ӻس�������һ��)\n");			//��仰��������
			char flag1;
			char temp1;
			scanf("%c",&temp1);
			flag1=getchar();
			if(flag1!='\n')
			{
			printf("��ϲ���Ѿ�ˢ��%d�� \n",count);
			printf("��ӭ�´�ʹ��\n");
			exit(1);
			}
			goto Start;
		}
		count++;
		char flag2;
		char temp;
		scanf("%c", &temp);
		flag2=getchar();
		if(flag2!='\n')
		{
			printf("��ϲ���Ѿ�ˢ��%d�� \n",count);
			printf("��ӭ�´�ʹ��\n");
			exit(1);
		}
		if(count==30)
		{
			printf("��ϲ���Ѿ�ˢ��%d�⣬��һ���Ѿ�ˢ����\n",count);
			printf("��ӭ�´�ʹ��\n");
			exit(1);
		}
	}
	return 1;
}
int SetQus6()
{
	system("cls");
	Intro();
	printf("\n");
	Tm();
	FILE* fp = NULL;
	fp = fopen("2021�°���ѡ��ģ�����/������.txt", "r");
	if (fp == NULL)
	{
		printf("�ļ���ʧ�ܣ��������λ��\n");
	}
	for(int i=1;i<=30;i++)
	{
		fgets(a[i].question, 300, fp);
		for(int j=1;j<=4;j++)
		{
			fgets(a[i].select[j], 200, fp);
		}
		fgets(a[i].temp, 5, fp);
		a[i].answer=*a[i].temp;
	}
	int count=0;
	while(count>=0)
	{
Start:
		system("cls");
		Intro();
		printf("\n");
		Tm();
		char an;
		printf(">>���ǵ�����ѡ��(֧��ʶ��Сд)\n");
		printf("%s",a[count+1].question);
		for(int j=1;j<=4;j++)
		{
			printf("%s",a[count+1].select[j]);
		}
		printf("ѡ��>>");
		scanf("%c",&an);
		if(an>='a'&&an<='d')
		{
			an-=32;
			if(an==a[count+1].answer)
			{
				printf("Binggo������� (������ӻس��˳� / ֱ�ӻس�������һ��)\n");
			}
			else
			{
				printf("�ش����\n");
				printf("��ȷ���ǣ�%c(������ӻس��˳� / ֱ�ӻس�������һ��)\n",a[count+1].answer);
			}
		}
		else if(an>='A'&&an<='D')
		{
			if(an==a[count+1].answer)
			{
			printf("Binggo������� (������ӻس��˳� / ֱ�ӻس�������һ��)\n");
			}
			else
			{
				printf("�ش����\n");
				printf("��ȷ���ǣ�%c(������ӻس��˳� / ֱ�ӻس�������һ��)\n",a[count+1].answer);
			}
		}
		else
		{
			printf("��������ȷ��ѡ��(������ӻس��˳� / ֱ�ӻس�������һ��)\n");			//��仰��������
			char flag1;
			char temp1;
			scanf("%c",&temp1);
			flag1=getchar();
			if(flag1!='\n')
			{
			printf("��ϲ���Ѿ�ˢ��%d�� \n",count);
			printf("��ӭ�´�ʹ��\n");
			exit(1);
			}
			goto Start;
		}
		count++;
		char flag2;
		char temp;
		scanf("%c", &temp);
		flag2=getchar();
		if(flag2!='\n')
		{
			printf("��ϲ���Ѿ�ˢ��%d�� \n",count);
			printf("��ӭ�´�ʹ��\n");
			exit(1);
		}
		if(count==30)
		{
			printf("��ϲ���Ѿ�ˢ��%d�⣬��һ���Ѿ�ˢ����\n",count);
			printf("��ӭ�´�ʹ��\n");
			exit(1);
		}
	}
	return 1;
}
void Over()
{
	system("cls");
	Intro();
	printf("\n");
	Tm();
	printf("��ӭ�´�ʹ�ã�\n�ټ���\n");
	exit(0);
}
void ChooseBank()
{
	system("cls");
	Intro();
	Tm();
	Menu2();
	int input;
	printf("��������ѡ�����ѡ��>>");
	scanf("%d",&input);
	do
	{
		switch(input)
		{
			case 1:
				SetQus1();
				system("pause");
				break;
			case 2:
				SetQus2();
				system("pause");
				break;
			case 3:
				SetQus3();
				system("pause");
				break;
			case 4:
				SetQus4();
				system("pause");
				break;
			case 5:
				SetQus5();
				system("pause");
				break;
			case 6:
				SetQus6();
				system("pause");
				break;
			default:
				system("cls");
				Intro();
				Tm();
				Menu();
				printf("��������밴��ʾ��������\n");
				Choese();
		}
	}while(input);
	system("pause");	
}
void Choese()
{
	int input;
	printf("��������ѡ�����ѡ��>>");
	scanf("%d",&input);
	do
	{
		switch(input)
		{
			case 1:
				ChooseBank();
				system("pause");
				break;
			case 0:
				Over();
				break;
			default:
				system("cls");
				Intro();
				Tm();
				Menu();
				printf("��������밴��ʾ��������\n");
				
				Choese();
		}
	}while(input);
	system("pause");
}
int main()
{
	Intro();
	Menu();	
	Choese();
}
