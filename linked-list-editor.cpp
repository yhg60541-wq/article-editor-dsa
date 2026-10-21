#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <iostream>
#include <windows.h>
#define MAX 80
#define MAX_INPUT 80
// 定义链表结点结构，用于存储一行文本
typedef struct Node {
    //char *data;
	char *line; 			// 指向存储行内容的字符串
	char data[81];	
	int row;		
    struct Node *next; 		// 指向下一个结点的指针
} Node;

// 定义链表结构
typedef struct LinkedList {
    Node *head; 			// 链表头指针
    Node *tail; 			// 链表尾指针
    size_t size; 			// 链表中元素的数量，用于统计字符总数
} LinkedList;

// 初始化链表
void initList(LinkedList *list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

// 向链表尾部添加一行
void appendLine(LinkedList *list, char *line,int row) {
    Node *newNode =(Node*) malloc(sizeof(Node));
    newNode->line = strdup(line);
    newNode->row =row; 
    newNode->next = NULL;
    
    if (list->tail) { 				// 如果有尾部结点
        list->tail->next = newNode; // 将新结点添加到尾部
    } 
	else { 							// 如果链表为空
        list->head = newNode; 		// 新结点成为头结点
    }
    list->tail = newNode; 			// 更新尾部结点
    list->size += strlen(line);
}

// 1.1从文件读取文章到链表中
void readFileToLinkedList(LinkedList *list) {
    char filename[100];
    printf("请输入你想打开的文件名：\n");
    scanf("%s",filename);			//读取文件名，最多99个字符 
	FILE *file = fopen(filename, "r");
    if (!file) {
        printf("无法打开文件: %s\n", filename);
        return;
    }
    
    
    //1.2控制每行的字符个数 
   char line[81];					 	// 每行最多80个字符
	int row=1;					
    while (fgets(line, 81, file)) { 	// 读取文件
        // 去除行尾的换行符
        if (strchr(line, '\n')) {
            *strchr(line, '\n') = '\0';
        }
        appendLine(list, line,row);
        row++;
    }
    fclose(file);
}


void printLinkedList(LinkedList *list) {
    for (Node *node = list->head; node != NULL; node = node->next) {
        printf("%s\n", node->line);
    }
}

// 1.3统计英文字母数和空格数
void countLettersAndSpaces(LinkedList *list) {
    size_t letters = 0, spaces = 0;		//

    for (Node *node = list->head; node != NULL; node = node->next) {
        for (size_t i = 0; i < strlen(node->line); i++) {
            if (isalpha(node->line[i])) {
                letters++;
            } else if (isspace(node->line[i])) {
                spaces++;
            }
        }
    }
    printf(" \n目前的字母个数为: %zu\n 目前的空格个数为: %zu\n 总个数为: %zu\n", letters, spaces, letters+spaces);
    printf("————————————————————\n");
}

// 1.4删除链表中的指定行
void deleteLine(LinkedList *list, size_t index) {
    Node *prev = NULL;
    Node *current = list->head;
    size_t i = 0;
    while (current != NULL && i < index) {
        prev = current;
        current = current->next;
        i++;
    }
    if (current != NULL) {
        if (prev) {
            prev->next = current->next;
        } else {
            list->head = current->next;
        }
        if (list->tail == current) {
            list->tail = prev;
        }
        free(current->line);
        free(current);
        list->size -= strlen(current->line);
    }
}

// 1.4插入新行
void insertLine(LinkedList *list, char *line, size_t index) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->line = strdup(line);
    newNode->next = NULL;

    Node *prev = NULL;
    Node *current = list->head;
    size_t i = 0;
    while (current != NULL && i < index) {
        prev = current;
        current = current->next;
        i++;
    }
    if (prev) {
        prev->next = newNode;
        newNode->next = current;
    } 
	else {
        list->head = newNode;			//设置新的头结点 
        newNode->next = current;		//指向结点 插入 
    }
    if (list->tail == current) {
        list->tail = newNode;
    }
    list->size += strlen(line);			//更新链表大小 
}

// 2.查找字符在链表中的所有出现位置和次数
void findCharOccurrences(LinkedList *list, char target) {
    int total_count = 0;				//初始化 
    printf("字符 '%c' 出现的位置是:\n", target);

    for (Node *node = list->head; node != NULL; node = node->next) {
        const char *line = node->line;		//目标字符 
        for (int col = 0; line[col] != '\0'; col++) {		//遍历字符串的每个字符 
            if (line[col] == target) {
                printf("第 %d 行, 第 %d 列\n", node->row, col+1);
                total_count++;
            }
        }
    }
    
    printf("字符 '%c' 出现的次数为: %d\n", target, total_count);
}
//3.删除子串，后面字符前移 
void deleteSubstringInList(LinkedList *list, const char *subStr) {
    for (Node *node = list->head; node != NULL; node = node->next) {	//遍历 
        size_t subLen = strlen(subStr);			//计算长度
        size_t totalLen = strlen(node->line) + 1;		 
        char *buffer =(char*) malloc(totalLen * sizeof(char));
        if (!buffer) {
            printf("内存分配失败。\n");
            return;
        }
        
        char *dest = buffer;	//初始化目标指针 
        char *src = node->line;	//初始化源指针 
        
        while (*src) {		// 遍历指针，直到空字符 
            if (strncmp(src, subStr, subLen) == 0) {            
                src += subLen;
            } else {		// 没有匹配，复制当前字符
                
                *dest++ = *src++;
            }
        }
        // 复制剩余的部分
        strcpy(dest, src);
        // 更新原字符串
        free(node->line);
        node->line = strdup(buffer);
        free(buffer);
        
        list->size -= subLen * list->size / strlen(node->line);// 更新链表
    }
}

//4.保存修改后的文件到指定位置
void save(LinkedList *list) {
    system("cls");
    char name[100];
    
    // 获取文件名
    printf("\n请输入保存地址(例如: d:\\2.txt):");
    scanf("%s", name);
    
    // 保证文件可以打开
    FILE* fp = NULL;
    while ((fp = fopen(name, "w")) == NULL) {
        printf("文件无法打开，请重新输入文件名：");
        scanf("%s", name);
    }
    
    // 遍历链表并将内容写入文件
    for (Node *info = list->head; info; info = info->next) {
        fputs(info->line, fp);
        fputc('\n', fp);	//换行符 
    }
    
    fclose(fp);
    
    printf("\n文件保存成功\n");
}

//5.创建新的文档，可进行编辑 
void editDocument(LinkedList *list) {
    system("cls");
    printf("正在创建新的空白文档...\n\n");
    
    // 确保链表为空
    initList(list);
    
    char line[MAX_INPUT + 1];
    
    printf("请输入文档内容，输入'.'后回车结束输入。\n");
    printf("注意：编辑完成后，您将被提示保存文档到指定位置。\n\n");
    
    // 读取用户输入，直到用户输入'.'结束
    while (1) {
        fgets(line, MAX_INPUT + 1, stdin);
        if (line[0] == '.') break;
        if (strchr(line, '\n')) {
            *strchr(line, '\n') = '\0';
        }
        appendLine(list, strdup(line), list->size + 1);
    }
    
    printf("文档创建完成，已添加 %zu 行。\n", list->size);
}
 
//6.字符串替换
 void replaceStringInList(LinkedList *list, const char *oldStr, const char *newStr) {
    for (Node *node = list->head; node != NULL; node = node->next) {
        // 创建一个新的缓存字符串，用于存储替换后的行
        size_t oldLen = strlen(oldStr), newLen = strlen(newStr);
        size_t totalLen = strlen(node->line) + 1;
        char *buffer = (char*)malloc(totalLen * sizeof(char));
        if (!buffer) {
            printf("内存分配失败。\n");
            return;
        }
        
        char *dest = buffer;
        char *src = node->line;
        
        while (*src) {
            if (strncmp(src, oldStr, oldLen) == 0) {
                // 发现匹配，复制新字符串
                dest += sprintf(dest, "%s", newStr);
                src += oldLen;
            } else {
                // 没有匹配，复制当前字符
                *dest++ = *src++;
            }
        }
        // 复制剩余的部分
        strcpy(dest, src);
        // 更新原字符串
        free(node->line);
        node->line = strdup(buffer);
        free(buffer);
        // 更新链表的size属性
        list->size -= oldLen * list->size / strlen(node->line);
        list->size += newLen * list->size / strlen(node->line);
    }
}

//7.插入自定义表格
void createAndInsertTable(LinkedList *list, size_t index) {
    int rows, cols;
    printf("请输入表格的行数和列数（例如：3 5）:");
    scanf("%d %d", &rows, &cols);

   // 定义表格的首尾边框
char topBottomBorder[cols * 3 + 1];
topBottomBorder[0] = '+';
for (int i = 1; i < cols * 3; i += 3) {
    topBottomBorder[i] = '-';
    topBottomBorder[i + 1] = '-';
    topBottomBorder[i + 2] = '+';
}
topBottomBorder[cols * 3] = '\0';

// 定义中间边框
char midBorder[cols * 3 + 1];
midBorder[0] = '|';
for (int i = 1; i < cols * 3; i += 3) {
    midBorder[i] = ' ';
    midBorder[i + 1] = ' ';
    midBorder[i + 2] = '|';
}
midBorder[cols * 3] = '\0';

// 收集行内容
char **rowContents = (char **)malloc(rows * sizeof(char *));
for (int i = 0; i < rows; i++) {
    rowContents[i] = (char *)malloc(cols * 3 + 1);
    printf("请输入第%d行的内容（最多%d个字符）:", i + 1, cols);
    scanf(" %[^\n]", rowContents[i]);
    for (int j = strlen(rowContents[i]); j < cols * 3; j += 3) {
        rowContents[i][j] = ' ';
    }
    rowContents[i][cols * 3] = '\0';
}

// 创建完整表格
char table[rows * (cols * 3 + 3) + 1];
int pos = 0;

table[pos++] = '\n';
for (int i = 0; i <= rows; i++) {
    strcpy(table + pos, topBottomBorder);
    pos += strlen(topBottomBorder);
    if (i < rows) {
        strcpy(table + pos, "\n");
        pos += 1;
        strcpy(table + pos, midBorder);
        pos += strlen(midBorder);
        strcpy(table + pos, " ");
        pos += 1;
        strcpy(table + pos, rowContents[i]);
        pos += strlen(rowContents[i]);
        strcpy(table + pos, " ");
        pos += 1;
        strcpy(table + pos, midBorder);
        pos += strlen(midBorder);
        strcpy(table + pos, "\n");
        pos += 1;
    }
}

// 清理临时数据
for (int i = 0; i < rows; i++) {
    free(rowContents[i]);
}
free(rowContents);
printf("表格内容：\n%s\n",table);
// 插入表格到链表中
insertLine(list, table, index);
//printLinkedlist(&list);
}
 
//8.改变字体颜色
 void setConsoleColor(short color) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandle, color);
}

//复制功能
 void copyListToFile(LinkedList *list, const char *targetFilename) {
    FILE *targetFile = fopen(targetFilename, "w");
    if (!targetFile) {
        printf("无法创建或打开目标文件: %s\n", targetFilename);
        return;
    }

    for (Node *node = list->head; node != NULL; node = node->next) {
        fprintf(targetFile, "%s\n", node->line);
    }

    fclose(targetFile);
}

// 主函数/
int main() {
	char substringToSearchFor[100];
    LinkedList list;
    initList(&list);	//初始化链表 
	
	int mainChoice;
		do{
			printf("选择你想实现的功能:\n ");
			printf("1.打开文件:\n ");
			printf("2.新建空白文件:\n ");
			printf("3.退出:\n ");
			printf("\n你的选择是：");
			scanf(" %d", &mainChoice);
			//getchar();//消费换行符
			switch(mainChoice){
			case 1:								//打开文件 
				readFileToLinkedList(&list);	//调用函数，输入要打开的文件名
				printf("该文件的内容为:\n");
				printLinkedList(&list);
				//getchar();
				//editChoice=1;
				printf("按任意键继续\n");
				getchar();						//等待用户输入	
				break;
			case 2:
				// 清空链表，用于创建空白文件
    		
    			editDocument(&list);
    			save(&list);
    			// 显示文档内容
    			printLinkedList(&list);
    			printf("————————————————————\n");
    			
				break;
			default:
				printf("无效输入，请重新选择！");
				break; 
		}
	} while(mainChoice<1||mainChoice>3);

   
	char str1[20];
	char str2[20];
	int choice;
	do{
		printf("选择你想实现的功能:\n ");
        printf("\n1.插入一行\n");
		printf("2.删除一行\n");
		printf("3.统计英文字母数和空格数\n");
		printf("4.查找字符\n");
		printf("5.删除子串\n");
		printf("6.保存文件到指定位置\n");
		printf("7.replace,替换字符串\n");
		printf("8.插入自定义表格\n"); 
		printf("9.改变字体颜色\n");
		printf("10.复制文本内容到另一个文件\n");
		printf("11.退出\n"); 
        
        printf("\n你的选择是：");
        scanf(" %d", &choice);
		switch(choice){
			
			case 1:		//插入一行 
				size_t index;
            	char line[81];
            	printf("\n请输入你想插入的位置（第几行后）: \n");
            	scanf("%zu", &index);
            	printf("请输入你想插入的内容: \n");
            	scanf(" %[^\n]", line);
            	insertLine(&list, line, index);
            	printf("目前的文件内容为：\n");
        		printLinkedList(&list);
        		printf("————————————————————\n");
            	printf("功能执行完成。\n");
				printf("按回车键继续。\n");
				fflush(stdin);
				getchar(); 
				break;
			
			case 2:		//删除整行 
            	printf("请输入你想删除的位置（第几行后）: \n");
            	scanf("%zu", &index);
            	deleteLine(&list, index);
            	printf("目前的文件内容为：\n");
        		printLinkedList(&list);
        		printf("————————————————————\n");
        		printf("功能执行完成。\n");
				printf("按回车键继续。\n");
				fflush(stdin);
				getchar();
				break;
			
			case 3:		//统计 
			 	printf("\n");
            	countLettersAndSpaces(&list);
            	printf("功能执行完成。\n");
				printf("按回车键继续。\n");
				fflush(stdin);
				getchar();
            	break;
            
			case 4:		//查找字符 
            	char targetChar;
				printf("请输入要查找的字符：");
				scanf(" %c",&targetChar);
				findCharOccurrences(&list, targetChar);
				printf("目前的文件内容为：\n");
        		printLinkedList(&list);
        		printf("————————————————————\n");
        		printf("功能执行完成。\n");
				printf("按回车键继续。\n");
				fflush(stdin);
				getchar();
				break;
		    
			case 5:		//删除字符串 
		    	char subStr[100];
    			printf("请输入你想删除的子串：");
    			scanf(" %[^\n]", subStr);
    			deleteSubstringInList(&list, subStr);
    			printf("删除后的文件内容为：\n");
    			printLinkedList(&list);
    			printf("————————————————————\n");
    			printf("功能执行完成。\n");
				printf("按回车键继续。\n");
				fflush(stdin);
				getchar();
    			break;
        	
			case 6:		//保存文件 
        		save(&list);
        		printf("目前的文件内容为：\n");
        		printLinkedList(&list);
        		printf("————————————————————\n");
        		printf("功能执行完成。\n");
				printf("按回车键继续。\n");
				fflush(stdin);
				getchar();
				break;
			
			case 7:		//替换 
				char oldStr[100], newStr[100];
    			printf("请输入你想替换的字符串：");
    			scanf(" %[^\n]", oldStr);
    			printf("请输入新的字符串：");
    			scanf(" %[^\n]", newStr);
    			replaceStringInList(&list, oldStr, newStr);
   			    printf("替换后的文件内容为：\n");
    			printLinkedList(&list);
    			printf("————————————————————\n");
    			printf("功能执行完成。\n");
				printf("按回车键继续。\n");
				fflush(stdin);
				getchar();
    			break;
			
			case 8:		//表格 
				size_t index2;
    			printf("请输入你想插入表格的位置（第几行后）:");
    			scanf("%zu", &index2);
    			createAndInsertTable(&list, index);
    			printf("目前的文件内容为：\n");
    			printLinkedList(&list);
    			printf("————————————————————\n");
    			printf("功能执行完成。\n");
				printf("按回车键继续。\n");
				fflush(stdin);
				getchar();
    			break;
			 
			case 9:		//颜色 
			 	int colorChoice;
                printf("请选择颜色：\n");
                printf("1 - 红色\n");
                printf("2 - 绿色\n");
                printf("3 - 蓝色\n");
                printf("4 - 黄色\n");
                printf("输入你的选择: ");
                scanf(" %d", &colorChoice);
                printf("你的文本如下：\n");
                switch (colorChoice) {
                    case 1:
                        setConsoleColor(FOREGROUND_RED);
                        printf("\n");
						printLinkedList(&list);
                        break;
                    case 2:
                        setConsoleColor(FOREGROUND_GREEN);
                        printLinkedList(&list);
                        printf("\n");
                        break;
                    case 3:
                        setConsoleColor(FOREGROUND_BLUE);
                        printLinkedList(&list);
                        printf("\n");
                        break;
                    case 4:
                        setConsoleColor(FOREGROUND_GREEN | FOREGROUND_RED);
                        printLinkedList(&list);
                        printf("\n");
                        break;
                    default:
                        printf("无效的颜色选择！\n");
                        break;
               		}
               	int resetChoice;
               	printf("\n"); 
        		printf("是否恢复默认颜色？(1 - 是，0 - 否): ");
        		scanf(" %d", &resetChoice);
        		if(resetChoice == 1) {
            		setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 恢复默认颜色
            		printf("文本颜色已恢复默认。\n");
        		} else {
           			printf("文本颜色保持当前设置。\n");
       				}
       			printf("功能执行完成。\n");
				printf("按回车键继续。\n");
				fflush(stdin);
				getchar();	
    			break;
    		
			case 10:	//复制 
				printf("请输入新文件的地址：");
                char targetFilename[100];
                scanf("%s", targetFilename);
                copyListToFile(&list, targetFilename);
                printf("文件已复制到 %s\n", targetFilename);
                printf("功能执行完成。\n");
				printf("按回车键继续。\n");
				fflush(stdin);
				getchar();	
    			break;
				
			case 11:
				break; 
			
			default:
				printf("无效输入，请重新选择！");
				break; 
			}
		}while(choice!=9);
	return 0;
}

