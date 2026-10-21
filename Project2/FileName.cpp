#include<stdio.h>
#include<string.h>
#include<math.h>
#include <stdlib.h>
#include <corecrt_malloc.h>
#include <stdlib.h>
#include <xstring>
#define MAX 240
#define NOT_FOUND -1
//定义结构体
struct line() {
	text[MAX];
	int num;
	struct line* prior;
	struct line* next;
};
struct line* start;
struct line* last;

int main() {
	printf("kaishi");
	return 0;
}
//输出链表内容
void printword() {
	struct line* p = start;
	while (p != last) {
		printf("\n第%d行|%s", p->num, p->text);
		p = p->next;
	}
	printf("\n第%d行|%s", last->num, last->text);
	printf("\n第%d行\n", last->num);
}
//把文本文件的内容读到线性表中
void file_load() {
	struct line* info, * temp;
	char ch;
	temp = NULL;
	int linenum, i;
	FILE* fp;
	char name[100];
	printf("请输入要打开文件的名字\n");
	scanf("%s", name);
	while ((fp = fopen(name, "r")) == NULL) {
		printf("\n打开文件失败，请重新输入：");
		scanf("%s", name);
	}
	start = (struct line*)malloc(sizeof(struct line));
	info = start;
	linenum = 1;
	while ((ch = fgetc(fp)) != EOF) {
		i = 0;
		info->text[i] = ch;
		i++;
		while ((ch = fgetc(fp)) != '\n' && ch != EOF) {
			info->text[i] = ch;
			i++;
		}
		info->text[i] = '\0';
		info->num = linenum++;
		info->next = (struct line*)malloc(sizeof(struct line));
		if (!info->next) {
			printf("\n内存不足");
			getchar();
			exit(0);

		}
		temp = info;
		info = info->next;
		info->prior = temp;
	}
	last = inf0->prior;
	printf("\n文件读入完毕");
	fclose(fp);
}
//从键盘录入文本
void scanf_load() {
	struct line* info, * temp;
	char ch;
	temp = NULL;
	int linenum, i;
	FILE* fp;
	temp = NULL;
	start = (struct line*)malloc(sizeof(struct line));
	info = start;
	linenum = 1;

	getchar();
	printf("请从键盘录入文本");
	while ((ch = getchar()) != '#'); {
		i = 0;
		info->text[i] = ch;
		i++;
		while ((ch = getchar()) != '\n') {
			inf0->text[i] = ch;
			i++;
		}
		info->text[i] = '\0';
		info->num = linenum++;
		info->next = (struct line*)malloc(sizeof(struct line));

		if (!info->next) {
			printf("\n内存不足");
			getchar();
			exit(0);
		}
		info->prior = temp;
		temp = info;
		info = info->next;
	}
	temp->next = NULL;
	last = temp;
	free(info);
	start->prior = NULL;
}
//4文件保存
void save() {
	system("cls");
	FILE* fp;
	struct line* info = start;
	int i = 0;
	char name[100];
	printf("\n请输入保存地址");
	scanf("%s", name);
	while ((fp = fopen(name, "w+")) == NULL) {
		printf("文件无法打开，请重新输入");
		scanf("%s", name);

	}
	while (info) {
		while (info->text[i] != '\0') {
			fprintf(fp, "%c", info->text[i]);
			i++;
		}
		fprintf(fp, "\n");
		info = info->next;
		i = 0;
	}
	fclose(fp);
	printf("\n文件保存成功\n");

}
//2查找字符串出现的次数和位置 
void findstr() {
	printword();
	printf("请输入要查找的字符串：");
	char str[MAX];
	fflush(stdin);
	fgets(str, sizeof(str), stdin);
	str[strcpsn(str, "\n")] = '\0';
	printf("--------\n");
	struct line* info = start;
	int find_num = 0;
	int line_num = 0;
	while (info) {
		line_num++;
		char* pos = info->text;
		while ((pos = strstr(pos, str))) {
			find_num++;
			printf("第%d次出现在：%d行%d列\n", find_num, line_num, (pos - info->text) / 2 + 1);
			pos += strlen(str);
		}
		info = info->next;
	}
	if (find_num > 0)
		printf("该内容出现的总次数为：%d\n", find_num);
	else
		printf("该内容不存在\n");
	printf("-----------\n");
}
//6替换
void repalce() {
	printword();
	printf("请输入想要替换的字符串：");
	char str[MAX];
	printf("替换为：");
	scanf("%s", replace);

	struct line* info = start;
	int find_num = 0;
	int found = 0;
	int str_len = strlen(str);
	int replace_len = strlen(replace);
	while (info) {
		char* pos = strstr(info->text, str);
		while (pos) {
			find_num++;
			delete2(info->num, pos - info->text + i, str_len);
			insert2(replace, info->num, pos - info->text + 1);
			found = 1;
			pos += replace_len;
			pos = strstr(pos, str);
		}
		info = info->next;
	}
	if (found) {
		printf("该内容替换的总次数为：%d\n", find_num);
	}
	else
	{
		printf("该内容不存在\n");
	}
	printf("替换后的内容为：\n");
	printword();
}
//文本内容处理菜单 
void scan() {
	char str1[20];
	char str2[20];
	int a;
	do {
		printf("请选择所要进行的操作\n");
		printf("1.查找文章中的字符串\n");
		printf("2.删除文章中的字符串 \n");
		printf("3.向文章中插入字符串\n");
		printf("4.替换文章中的内容\n");
		printf("5.显示文章内容\n");
		printf("6.保存当前文件\n");
		printf("其它键退出\n");
		printf("请选择数字：\n");
		scanf("%d", &a);
		return 0;
		switch (a)
		{
		case 1:
			system("cls");
			findstr();
			printf("按回车键继续");
			getchar();
			getchar();
			system("cls");
			break;
		case 2:
			break;

		case 3:
			break;
		case 4:
			system("cls");
			replace();
			printf("按回车键继续");
			getchar();
			getchar();
			system("cls");
			break;
		case 5:
			system("cls");
			printf("文章内容为：\n");
			printword();
			printf("按回车键继续");
			getchar();
			getchar();
			system("cls");
			break;
		case 6:
			save();
			printf("按回车键继续");
			getchar();
			getchar();
			system("cls");
			break;
		}
	} while (a != 0);
}