#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX_line 80
//定义结构体，储存每行数据 
typedef struct {
	char line[MAX_line + 1];					/*每行不超过80个字符*/
	int linelength;
}Line;
//从文件中读取文章 
int readfile(char* filename, Line* lines) {
	FILE* file = fopen("article.txt", "r");
	if (file == NULL) {							/*判断文件是否打开*/
		printf("can not open the file\n");
		return 0;
	}
	int ch;
	while ((ch = fgetc(file)) != EOF)
		putchar(ch);
	//char str[80];
	//while(fgets(str,80,file)){
	//	printf("%s",str);
	//}
	fclose(file);
	return 0;
}
//统计字母和空格
void countLetters_space(Line* lines, int count) {
	int letters = 0;
	int space = 0;
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < lines[i].linelength; j++) {
			if (isalpha(lines[i].line[j]))
				letters++;
			if (isspace(lines[i].line[j]))
				space++;
		}
	}
	printf("字母个数letters:%d\n,空格个数space：%d\n", letters, space);
}


