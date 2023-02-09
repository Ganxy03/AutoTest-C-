#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

//AutoTest版本2.0			//开源不易
FILE* fp;					//转载标注下原作者Ganxy 这是对我最大的支持
int pan[20]={0};			//博客blog.ganxy03.cn
int randnum;				//Github:https://github.com/Ganxy03
int count=0;

void Tm();					//开源不易
void Intro();				//转载标注下原作者Ganxy 这是对我最大的支持
void Menu();				//博客blog.ganxy03.cn
void Radm();				//Github:https://github.com/Ganxy03
void NoRepet();
int Exit();
void ChooseBank();
void Choese();				//开源不易
struct ques {				//转载标注下原作者Ganxy 这是对我最大的支持
	char question[300];		//博客blog.ganxy03.cn
	char select[5][200];	//Github:https://github.com/Ganxy03
	char temp[2];
	char answer;
}a[30];						//开源不易
void Tm()					//转载标注下原作者Ganxy 这是对我最大的支持
{							//博客blog.ganxy03.cn
	time_t timep;			//Github:https://github.com/Ganxy03
	time(&timep);
	struct tm* p = gmtime(&timep);
	printf("当前时间（北京时间）：%d/%d/%d", (1900 + p->tm_year), (1 + p->tm_mon), p->tm_mday);
	printf(" %d:%d:%d\n", (8 + p->tm_hour), p->tm_min, p->tm_sec);	
}
void Intro()
{
	printf("Title:AutoTEST(2.0测试版)\n");
	printf("Author:Ganxy(ID：如果梦醒一分钟)\n");
	printf("Date:2023/2/6\n");
	printf("Intro:默认包含省一模拟题库里的选择题，通过修改题库地址可作其他用途,\n博客地址http://blog.ganxy03.cn/?p=123\n源码关注https://github.com/Ganxy03\n如果觉得好用请给我的博客点赞或者给我Github Star吧\n>>免费使用 无偿分享<<\n待优化:\n1.菜单选择字母死循环\n2.程序结束提示被吞（有两处 每套题库30题刷完提示、欢迎下次使用提示）\n3.界面菜单提示不清晰\n4.题库第一题得先回车\n");
	printf("\n");			//开源不易
	printf("\n");			//转载标注下原作者Ganxy 这是对我最大的支持
	printf("\n");			//博客blog.ganxy03.cn
	printf("\n");			//Github:https://github.com/Ganxy03
}
void Menu()
{
	printf("**** 菜单 ****\n");
	printf("*** 1.开始 ***\n");
	printf("*** 0.退出 ***\n");
	printf("**************\n");
	printf("\n");
}
void Menu2()
{
	printf("**** 选择题库 ****\n");
	printf("**** 1.第一套 ****\n");
	printf("**** 2.第二套 ****\n");
	printf("**** 3.第三套 ****\n");
	printf("**** 4.第四套 ****\n");
	printf("**** 5.第五套 ****\n");
	printf("**** 6.第六套 ****\n");
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
	fp = fopen("2021下半年选择模拟题库/第一套.txt", "r");
	if (fp == NULL)
	{
		printf("文件打开失败！请检查题库位置\n");
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
		printf(">>这是第一套选择(支持识别小写)\n");
		printf("%s",a[count+1].question);
		for(int j=1;j<=4;j++)
		{
			printf("%s",a[count+1].select[j]);
		}
		printf("选择：>>");
		scanf("%c",&an);
		if(an>='a'&&an<='d')
		{
			an-=32;
			if(an==a[count+1].answer)
			{
				printf("Binggo！答对了 (任意键加回车退出 / 直接回车继续下一题)\n");
			}
			else
			{
				printf("回答错误！\n");
				printf("正确答案是：%c(任意键加回车退出 / 直接回车继续下一题)\n",a[count+1].answer);
			}
		}
		else if(an>='A'&&an<='D')
		{
			if(an==a[count+1].answer)
			{
			printf("Binggo！答对了 (任意键加回车退出 / 直接回车继续下一题)\n");
			}
			else
			{
				printf("回答错误！\n");
				printf("正确答案是：%c(任意键加回车退出 / 直接回车继续下一题)\n",a[count+1].answer);
			}
		}
		else
		{
			printf("请输入正确的选项(任意键加回车退出 / 直接回车继续下一题)\n");			//这句话被清屏了
			char flag1;
			char temp1;
			scanf("%c",&temp1);
			flag1=getchar();
			if(flag1!='\n')
			{
			printf("恭喜你已经刷了%d题 \n",count);
			printf("欢迎下次使用\n");
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
			printf("恭喜你已经刷了%d题 \n",count);
			printf("欢迎下次使用\n");
			exit(1);
		}
		if(count==30)
		{
			printf("恭喜你已经刷了%d题，第一套已经刷完啦\n",count);
			printf("欢迎下次使用\n");
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
	fp = fopen("2021下半年选择模拟题库/第二套.txt", "r");
	if (fp == NULL)
	{
		printf("文件打开失败！请检查题库位置\n");
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
		printf(">>这是第二套选择(支持识别小写)\n");
		printf("%s",a[count+1].question);
		for(int j=1;j<=4;j++)
		{
			printf("%s",a[count+1].select[j]);
		}
		printf("选择：>>");
		scanf("%c",&an);
		if(an>='a'&&an<='d')
		{
			an-=32;
			if(an==a[count+1].answer)
			{
				printf("Binggo！答对了 (任意键加回车退出 / 直接回车继续下一题)\n");
			}
			else
			{
				printf("回答错误！\n");
				printf("正确答案是：%c(任意键加回车退出 / 直接回车继续下一题)\n",a[count+1].answer);
			}
		}
		else if(an>='A'&&an<='D')
		{
			if(an==a[count+1].answer)
			{
			printf("Binggo！答对了 (任意键加回车退出 / 直接回车继续下一题)\n");
			}
			else
			{
				printf("回答错误！\n");
				printf("正确答案是：%c(任意键加回车退出 / 直接回车继续下一题)\n",a[count+1].answer);
			}
		}
		else
		{
			printf("请输入正确的选项(任意键加回车退出 / 直接回车继续下一题)\n");			//这句话被清屏了
			char flag1;
			char temp1;
			scanf("%c",&temp1);
			flag1=getchar();
			if(flag1!='\n')
			{
			printf("恭喜你已经刷了%d题 \n",count);
			printf("欢迎下次使用\n");
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
			printf("恭喜你已经刷了%d题 \n",count);
			printf("欢迎下次使用\n");
			exit(1);
		}
		if(count==30)
		{
			printf("恭喜你已经刷了%d题，第一套已经刷完啦\n",count);
			printf("欢迎下次使用\n");
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
	fp = fopen("2021下半年选择模拟题库/第三套.txt", "r");
	if (fp == NULL)
	{
		printf("文件打开失败！请检查题库位置\n");
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
		printf(">>这是第三套选择(支持识别小写)\n");
		printf("%s",a[count+1].question);
		for(int j=1;j<=4;j++)
		{
			printf("%s",a[count+1].select[j]);
		}
		printf("选择：>>");
		scanf("%c",&an);
		if(an>='a'&&an<='d')
		{
			an-=32;
			if(an==a[count+1].answer)
			{
				printf("Binggo！答对了 (任意键加回车退出 / 直接回车继续下一题)\n");
			}
			else
			{
				printf("回答错误！\n");
				printf("正确答案是：%c(任意键加回车退出 / 直接回车继续下一题)\n",a[count+1].answer);
			}
		}
		else if(an>='A'&&an<='D')
		{
			if(an==a[count+1].answer)
			{
			printf("Binggo！答对了 (任意键加回车退出 / 直接回车继续下一题)\n");
			}
			else
			{
				printf("回答错误！\n");
				printf("正确答案是：%c(任意键加回车退出 / 直接回车继续下一题)\n",a[count+1].answer);
			}
		}
		else
		{
			printf("请输入正确的选项(任意键加回车退出 / 直接回车继续下一题)\n");			//这句话被清屏了
			char flag1;
			char temp1;
			scanf("%c",&temp1);
			flag1=getchar();
			if(flag1!='\n')
			{
			printf("恭喜你已经刷了%d题 \n",count);
			printf("欢迎下次使用\n");
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
			printf("恭喜你已经刷了%d题 \n",count);
			printf("欢迎下次使用\n");
			exit(1);
		}
		if(count==30)
		{
			printf("恭喜你已经刷了%d题，第一套已经刷完啦\n",count);
			printf("欢迎下次使用\n");
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
	fp = fopen("2021下半年选择模拟题库/第四套.txt", "r");
	if (fp == NULL)
	{
		printf("文件打开失败！请检查题库位置\n");
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
		printf(">>这是第四套选择(支持识别小写)\n");
		printf("%s",a[count+1].question);
		for(int j=1;j<=4;j++)
		{
			printf("%s",a[count+1].select[j]);
		}
		printf("选择：>>");
		scanf("%c",&an);
		if(an>='a'&&an<='d')
		{
			an-=32;
			if(an==a[count+1].answer)
			{
				printf("Binggo！答对了 (任意键加回车退出 / 直接回车继续下一题)\n");
			}
			else
			{
				printf("回答错误！\n");
				printf("正确答案是：%c(任意键加回车退出 / 直接回车继续下一题)\n",a[count+1].answer);
			}
		}
		else if(an>='A'&&an<='D')
		{
			if(an==a[count+1].answer)
			{
			printf("Binggo！答对了 (任意键加回车退出 / 直接回车继续下一题)\n");
			}
			else
			{
				printf("回答错误！\n");
				printf("正确答案是：%c(任意键加回车退出 / 直接回车继续下一题)\n",a[count+1].answer);
			}
		}
		else
		{
			printf("请输入正确的选项(任意键加回车退出 / 直接回车继续下一题)\n");			//这句话被清屏了
			char flag1;
			char temp1;
			scanf("%c",&temp1);
			flag1=getchar();
			if(flag1!='\n')
			{
			printf("恭喜你已经刷了%d题 \n",count);
			printf("欢迎下次使用\n");
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
			printf("恭喜你已经刷了%d题 \n",count);
			printf("欢迎下次使用\n");
			exit(1);
		}
		if(count==30)
		{
			printf("恭喜你已经刷了%d题，第一套已经刷完啦\n",count);
			printf("欢迎下次使用\n");
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
	fp = fopen("2021下半年选择模拟题库/第五套.txt", "r");
	if (fp == NULL)
	{
		printf("文件打开失败！请检查题库位置\n");
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
		printf(">>这是第五套选择(支持识别小写)\n");
		printf("%s",a[count+1].question);
		for(int j=1;j<=4;j++)
		{
			printf("%s",a[count+1].select[j]);
		}
		printf("选择：>>");
		scanf("%c",&an);
		if(an>='a'&&an<='d')
		{
			an-=32;
			if(an==a[count+1].answer)
			{
				printf("Binggo！答对了 (任意键加回车退出 / 直接回车继续下一题)\n");
			}
			else
			{
				printf("回答错误！\n");
				printf("正确答案是：%c(任意键加回车退出 / 直接回车继续下一题)\n",a[count+1].answer);
			}
		}
		else if(an>='A'&&an<='D')
		{
			if(an==a[count+1].answer)
			{
			printf("Binggo！答对了 (任意键加回车退出 / 直接回车继续下一题)\n");
			}
			else
			{
				printf("回答错误！\n");
				printf("正确答案是：%c(任意键加回车退出 / 直接回车继续下一题)\n",a[count+1].answer);
			}
		}
		else
		{
			printf("请输入正确的选项(任意键加回车退出 / 直接回车继续下一题)\n");			//这句话被清屏了
			char flag1;
			char temp1;
			scanf("%c",&temp1);
			flag1=getchar();
			if(flag1!='\n')
			{
			printf("恭喜你已经刷了%d题 \n",count);
			printf("欢迎下次使用\n");
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
			printf("恭喜你已经刷了%d题 \n",count);
			printf("欢迎下次使用\n");
			exit(1);
		}
		if(count==30)
		{
			printf("恭喜你已经刷了%d题，第一套已经刷完啦\n",count);
			printf("欢迎下次使用\n");
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
	fp = fopen("2021下半年选择模拟题库/第六套.txt", "r");
	if (fp == NULL)
	{
		printf("文件打开失败！请检查题库位置\n");
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
		printf(">>这是第六套选择(支持识别小写)\n");
		printf("%s",a[count+1].question);
		for(int j=1;j<=4;j++)
		{
			printf("%s",a[count+1].select[j]);
		}
		printf("选择：>>");
		scanf("%c",&an);
		if(an>='a'&&an<='d')
		{
			an-=32;
			if(an==a[count+1].answer)
			{
				printf("Binggo！答对了 (任意键加回车退出 / 直接回车继续下一题)\n");
			}
			else
			{
				printf("回答错误！\n");
				printf("正确答案是：%c(任意键加回车退出 / 直接回车继续下一题)\n",a[count+1].answer);
			}
		}
		else if(an>='A'&&an<='D')
		{
			if(an==a[count+1].answer)
			{
			printf("Binggo！答对了 (任意键加回车退出 / 直接回车继续下一题)\n");
			}
			else
			{
				printf("回答错误！\n");
				printf("正确答案是：%c(任意键加回车退出 / 直接回车继续下一题)\n",a[count+1].answer);
			}
		}
		else
		{
			printf("请输入正确的选项(任意键加回车退出 / 直接回车继续下一题)\n");			//这句话被清屏了
			char flag1;
			char temp1;
			scanf("%c",&temp1);
			flag1=getchar();
			if(flag1!='\n')
			{
			printf("恭喜你已经刷了%d题 \n",count);
			printf("欢迎下次使用\n");
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
			printf("恭喜你已经刷了%d题 \n",count);
			printf("欢迎下次使用\n");
			exit(1);
		}
		if(count==30)
		{
			printf("恭喜你已经刷了%d题，第一套已经刷完啦\n",count);
			printf("欢迎下次使用\n");
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
	printf("欢迎下次使用！\n再见！\n");
	exit(0);
}
void ChooseBank()
{
	system("cls");
	Intro();
	Tm();
	Menu2();
	int input;
	printf("输入数字选择你的选项>>");
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
				printf("输入错误！请按提示输入数字\n");
				Choese();
		}
	}while(input);
	system("pause");	
}
void Choese()
{
	int input;
	printf("输入数字选择你的选项>>");
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
				printf("输入错误！请按提示输入数字\n");
				
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
