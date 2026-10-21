#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 240
#define NOT_FOUND -1

//定义结构体
struct line {
	char text[MAX];      //该行的内容
	int num;                 //用来记录行号
	struct line* prior;      //用来指向前一行
	struct line* next;       //用来指向下一行
};
struct line* start;          //指向线性表的第一行
struct line* last;           //指向线性表的最后一行

int menu1() {
	printf(" _____________________________ \n");
	printf("|___________开始菜单__________|\n");
	printf("|          1.键盘输入         |\n");
	printf("|          2.打开文件         |\n");
	printf("|          3.退出程序         |\n");
	printf("|_____________________________|\n");
	printf("请按数字选择：\n");
	return 0;
}


//  输出链表的内容
void PrintWord() {
	struct line* p = start;
	while (p != last) {
		printf("\n第%d行|%s", p->num, p->text);
		p = p->next;
	}
	printf("\n第%d行|%s", last->num, last->text);
	printf("\n共%d行\n", last->num);
}

//把文本文件的内容读到线性表中 d:\1.txt
void file_load() {
	struct line* info, * temp;  // 行指针，info指向当前行，temp指向info的前驱行
	char ch;
	temp = NULL;
	int linenum, i;  // 行计数器，行字符数组下标
	FILE* fp;  // 文件指针
	char name[100];
	printf("请输入要打开文件名字（例如d:\\1.txt）:\n");
	scanf("%s", name);

	while ((fp = fopen(name, "r")) == NULL) {
		printf("\n打开文件失败，请重新输入要打开的文件名：");
		scanf("%s", name);
	}

	start = (struct line*)malloc(sizeof(struct line));  // 生成一行的结点空间
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
		info->text[i] = '\0';  // 添加字符串结束符
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

	last = info->prior;
	printf("\n文件读入完毕\n");
	fclose(fp);
}


//从键盘录入文本
void scanf_load() {
	struct line* info, * temp;                //行指针，info指向当前行，temp指向info的前驱行
	char ch;
	temp = NULL;
	int linenum, i;         //行计数器,行字符数组下标
	FILE* fp;                                 //文件指针
	temp = NULL;
	start = (struct line*)malloc(sizeof(struct line));    //生成一行的结点空间

	info = start;
	linenum = 1;

	// 清除之前输入的多余换行符
	getchar();

	printf("请从键盘录入文本(输入时回车换行，输入结束后在新的一行输入#结束录入)\n");

	while ((ch = getchar()) != '#') {
		i = 0;
		info->text[i] = ch;
		i++;

		while ((ch = getchar()) != '\n') {   //从文件中读到一行字符到线性表中
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

		info->prior = temp;
		temp = info;
		info = info->next;
	}

	temp->next = NULL;
	last = temp;
	free(info);
	start->prior = NULL;
}

//文件保存
void save() {
	system("cls");
	FILE* fp;
	struct line* info = start;
	int i = 0;
	char name[100];
	printf("\n请输入保存地址(例如: d:\\2.txt):");
	scanf("%s", name);
	while ((fp = fopen(name, "w+")) == NULL) {
		printf("文件无法打开，请重新输入文件名：");
		scanf("%s", name);
	}

	while (info) {
		while (info->text[i] != '\0') { // 修改为 '\0'，以便正确写入字符串
			fprintf(fp, "%c", info->text[i]);
			i++;
		}
		fprintf(fp, "\n"); // 写入换行符
		info = info->next;
		i = 0;
	}

	fclose(fp);
	printf("\n文件保存成功\n");
}

//查找字符串
void findstr() {
	PrintWord();
	printf("输入想要查找的字符串：");
	char str[MAX];
	fflush(stdin);  // 清除输入缓冲区中的换行符
	fgets(str, sizeof(str), stdin);
	str[strcspn(str, "\n")] = '\0';   // 移除换行符

	printf("________________________________\n");
	struct line* info = start;
	int find_num = 0;   //匹配到的次数
	int line_num = 0;
	while (info) { //查询每一行
		line_num++;
		char* pos = info->text;
		while ((pos = strstr(pos, str))) {   // 在当前行中查找字符串
			find_num++;
			printf("第%d次出现在：%d行%d列\n", find_num, line_num, (pos - info->text) / 2 + 1);
			pos += strlen(str);   // 更新指针，跳过已匹配的字符串长度
		}
		info = info->next;
	}
	if (find_num > 0)
		printf("该内容出现的总次数为%d\n", find_num);
	else
		printf("该内容不存在\n");
	printf("________________________________\n");
}

//删除一行
void delete1(int line_num) {
	struct line* info, * p;
	info = start;
	while ((info->num < line_num) && info)  //寻找要删除的行
		info = info->next;
	if (info == NULL)
		printf("该行不存在");
	else {
		p = info->next;     //指向要删除的行后面一行
		if (start == info) { //如果删除的是第一行
			start = info->next;
			if (start)  //如果删除后，不为空
				start->prior = NULL;
			else  //删除后为空
				last = NULL;
		}
		else {
			info->prior->next = info->next;  //指定行的上一行指向指定行的下一行
			if (info != last) //如果不是最后一行
				info->next->prior = info->prior;  //修改其下一行的指向头的指针
			else  //如果是最后一行，修改尾指针
				last = info->prior;
		}
		free(info);
		while (p) { //被删除行之后的行号减一
			p->num = p->num - 1;
			p = p->next;
		}

	}

}

//删除某行,某列定长的内容
void delete2(int line_num, int position, int lenth) {

	struct line* info = start;
	char rest_str[MAX];
	if (line_num == 1)
		info = start;
	else
		for (int i = 1; i < line_num; i++) //让info指向删除内容所在行
			info = info->next;
	if (info == NULL)
		printf("该行没有字符！n");
	else {
		if (strlen(info->text) <= (position + lenth))  //本行的字符长度<=待删除的列号+删除长度，直接在当前位置插入'\0'
			info->text[position] = '\0';
		else {
			int i;
			for (i = position - 1; info->text[i + lenth] != '\0'; i++)
				info->text[i] = info->text[i + lenth];
			info->text[i] = '\0';
		}
	}
}


// 插入一行文字
void insert1() {
	int linenum;
	printf("输入插入位置的行号：");
	scanf("%d", &linenum);
	struct line* info, * q, * p;
	p = start;
	q = NULL;

	while (p && p->num != linenum) {
		q = p;    //插入行前面一行
		p = p->next;    //插入行后面一行
	}

	if (p == NULL && (q->num + 1) != linenum) { //指定行不存在，不能插入
		printf("输入的行号不存在");
	}

	else { // 指定行存在，进行插入
		info = (struct line*)malloc(sizeof(struct line));
		printf("输入要插入的字符串:");
		scanf("%s", info->text);
		info->num = linenum;
		if (linenum == 1) {     //插入在第一行
			info->next = p;
			p->prior = info;
			info->prior = NULL;
			start = info;
		}

		else if (q->num != linenum) { //插入在最后一行
			q->next = info;
			info->next = p;
			info->prior = q;
		}

		else {   //插入在其他行
			q->next = info;
			info->next = p;
			p->prior = info;
			info->prior = q;
		}

		while (p) { //如果不是插入在最后一行，插入行后面的行号都加1
			p->num = p->num + 1;
			p = p->next;
		}
	}
}

//插入文字到文本
void insert2(char str[], int linenum, int position) {
	struct line* info;
	int len, i;
	int lenth;
	char rest_str[MAX], kongge[2] = { " " };
	info = start;

	while (info && info->num != linenum) { //查询要插入的行
		info = info->next;
	}
	if (info == NULL)
		printf("不存在该行！\n");
	else if (position < 0)
		printf("不存在该列！\n");

	else {  //如果行和列都存在，则进行插入
		lenth = strlen(info->text);
		if (lenth < position) { //插入列大于本行文件列数
			len = position - lenth - 1;
			for (i = 0; i < len; i++)
				strcat(info->text, kongge);   //将空余的部分插入空格符
			strcat(info->text, str);    //插入字符到列的未尾
		}
		else { //插入列在本行文字的中间
			strcpy(rest_str, &info->text[position - 1]);
			strcpy(&info->text[position - 1], str);
			strcat(info->text, rest_str);
		}
	}
}

//替换
void replace() {
	PrintWord();
	printf("输入想要替换的字符串：");
	char str[MAX];
	scanf("%s", str);
	char replace[MAX];
	printf("替换为：");
	scanf("%s", replace);

	struct line* info = start;
	int find_num = 0; // 匹配到的次数
	int found = 0; // 是否找到匹配字符串
	int str_len = strlen(str);
	int replace_len = strlen(replace);

	while (info) { // 查询每一行
		char* pos = strstr(info->text, str);

		while (pos) { // 在当前行内查找匹配字符串
			find_num++;
			delete2(info->num, pos - info->text + 1, str_len);
			insert2(replace, info->num, pos - info->text + 1);
			found = 1;

			// 更新指针位置
			pos += replace_len;
			pos = strstr(pos, str);
		}

		info = info->next;
	}

	if (found) { // 找到匹配字符串
		printf("该内容替换的总次数为%d\n", find_num);

	}
	else {
		printf("该内容不存在\n");
	}

	printf("经过替换后的内容为：\n");
	PrintWord();
}


//移动菜单
void menu_move() {

	int choice;
	printf("\n|________________移动操作________________|\n");
	printf("|             1.向下移动一行             |\n");
	printf("|             2.向上移动一行             |\n");
	printf("|             3.向右移动一列             |\n");
	printf("|             4.向左移动一列             |\n");
	printf("|             5.返回上级菜单             |\n");
	printf("|________________________________________|\n");
	printf("请按数字选择：\n");
	scanf("%d", &choice);
	int line_num, number;
	char str[2];
	switch (choice) {
	case 1:   // 向下移动一行

		printf("需移动的字符串所在行号：");
		scanf("%d", &line_num);
		struct line* info, * p;                   //新建一行空行
		info = (struct line*)malloc(sizeof(struct line));
		info->text[0] = ' ';
		info->text[1] = '\0';
		info->num = line_num;
		if (line_num == 1) {  //插入在首行
			info->next = start;
			start->prior = info;
			start = info;
			start->prior = NULL;
			p = start->next;
		}
		else { //插入在其他行
			p = start;
			while (p->num != line_num)
				p = p->next;                    //令p指向插入行
			info->next = p;
			info->prior = p->prior;
			p->prior->next = info;
			p->prior = info;
		}
		while (p) { //插入行后面的行号都加1
			p->num = p->num + 1;
			p = p->next;
		}
		break;
	case 2:   //向上移动一行
		printf("需移动的字符串所在行号：");
		scanf("%d", &line_num);
		delete1(line_num - 1);
		break;
	case 3:   //向右移动一列
		printf("需移动的字符串所在行号：");
		scanf("%d", &line_num);
		printf("需移动的字符串所在列号：");
		scanf("%d", &number);
		str[0] = ' ';
		str[1] = '\0';
		insert2(str, line_num, number);
		break;
	case 4:   //向左移动
		printf("需移动的字符串所在行号：");
		scanf("%d", &line_num);
		printf("需移动的字符串所在列号：");
		scanf("%d", &number);
		if (number <= 0)
			printf("该列不存在");
		else
			delete2(line_num, number - 2, 1);
		break;
	case 5:   //退出移动
		break;

	}

}

//文本内容处理菜单
void menu2() {
	char str1[20];
	char str2[20];
	int a;
	do {
		printf("\n_____________________________________________\n");
		printf("|              文章内容处理菜单              |\n");
		printf("|____________________________________________|\n");
		printf("|       1、查找文章中的字符或者字符串        |\n");
		printf("|       2、删除文章中的字符或者字符串        |\n");
		printf("|       3、向文章中插入字符或者字符串        |\n");
		printf("|       4、移动文章字符或字符串              |\n");
		printf("|       5、替换文章字符或字符串              |\n");
		printf("|       6、显示当前文章内容                  |\n");
		printf("|       7、保存当前文章内容                  |\n");
		printf("|       8、直接退出                          |\n");
		printf("|____________________________________________|\n");
		printf("请按数字选择：\n");
		scanf("%d", &a);
		switch (a) {
		case 1:
			system("cls");
			findstr();
			printf("按回车键继续·····");
			getchar();
			getchar();
			system("cls");
			break;
		case 2:
			system("cls");
			printf(" __________________________________ \n");
			printf("|_____________删除菜单_____________|\n");
			printf("|          1:删除一行文字          |\n");
			printf("|     2:删除某行某列定长的内容     |\n");
			printf("|__________________________________|\n");
			int delete_choice;
			scanf("%d", &delete_choice);
			getchar();
			if (delete_choice == 1) {
				int linenum;
				printf("当前文本为：\n");
				PrintWord();
				printf("请输入你删除行的行号：");
				scanf("%d", &linenum);
				getchar();
				delete1(linenum);
			}
			else if (delete_choice == 2) {
				int linenum, position, lenth; //行，列，删除长度
				printf("当前文本为：\n");
				PrintWord();
				printf("请输入要删除内容所在行，列，删除内容字节长度，中间用空格隔开\n");
				printf("注意：汉字占两个字节\n");
				scanf("%d %d %d", &linenum, &position, &lenth);
				position = (position * 2) - 1;
				getchar();
				delete2(linenum, position, lenth);
			}
			printf("删除后的文章为:\n");
			PrintWord();
			printf("按回车键继续·····");
			getchar();
			getchar();
			system("cls");
			break;
		case 3:
			system("cls");
			printf(" __________________________________ \n");
			printf("|_____________插入菜单_____________|\n");
			printf("|          1:插入一行文字          |\n");
			printf("|  2：插入文字到文本到一行的中间   |\n");
			printf("|__________________________________|\n");
			int insert_choice;
			scanf("%d", &insert_choice);
			if (insert_choice == 1) {
				printf("当前文本为：\n");
				PrintWord();
				insert1();
			}
			else {
				printf("当前文本为：\n");
				PrintWord();
				char str[MAX];
				int linenum;
				int position;
				printf("输入插入位置-行号：");
				scanf("%d", &linenum);
				printf("输入插入位置-列号：");
				scanf("%d", &position);
				position = (position * 2) - 1;
				printf("要插入的字符串：");
				scanf("%s", str);
				insert2(str, linenum, position);
			}

			printf("插入字符或字符串后文章为:\n");
			PrintWord();
			printf("按回车键继续·····");
			getchar();
			getchar();
			system("cls");
			break;
		case 4:
			system("cls");
			menu_move();
			printf("移动后文本内容为：\n");
			PrintWord();
			printf("按回车键继续·····");
			getchar();
			getchar();
			system("cls");
			break;
		case 5:
			system("cls");
			replace();
			printf("按回车键继续·····");
			getchar();
			getchar();
			system("cls");
			break;
		case 6:
			system("cls");
			printf("\n文章内容为：\n");
			PrintWord();
			printf("按回车键继续·····");
			getchar();
			getchar();
			system("cls");
			break;
		case 7:
			save();
			printf("按回车键继续·····");
			getchar();
			getchar();
			system("cls");
			break;
		case 8:
			exit(0);
			break;
		default:
			printf("请输入正确的功能序号\n");
			printf("按回车键继续·····");
			getchar();
			getchar();
			system("cls");
			break;
		}
	} while (a != 8);
}


int main() {
	int c1, c2;
	menu1();
	do {
		scanf("%d", &c1);
		switch (c1) {
		case 1:
			scanf_load();
			system("cls");
			break;
		case 2:
			file_load();
			PrintWord();
			printf("\n");
			printf("按回车键继续·····");
			getchar();
			getchar();
			system("cls");
			break;
		case 3:
			return 0;
			break;
		default:
			printf("请输入正确的功能序号\n");
			break;
		}
	} while (c1 < 1 || c1 > 3);
	menu2();
	return 0;
}