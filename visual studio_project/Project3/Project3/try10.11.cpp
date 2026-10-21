#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define MAX 80

// 定义链表结点结构，用于存储一行文本
typedef struct Node {
    char* line; 			// 指向存储行内容的字符串
    char data[81];
    int row;
    struct Node* next; 		// 指向下一个结点的指针
} Node;

// 定义链表结构
typedef struct LinkedList {
    Node* head; 			// 链表头指针
    Node* tail; 			// 链表尾指针
    size_t size; 			// 链表中元素的数量，用于统计字符总数
} LinkedList;

// 初始化链表
void initList(LinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

// 向链表尾部添加一行
void appendLine(LinkedList* list, char* line, int row) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->line = strdup(line);
    newNode->row = row;
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
void readFileToLinkedList(LinkedList* list) {
    char filename[100];
    printf("请输入你想打开的文件名：\n");
    scanf("%99[^\n]", filename);			//读取文件名，最多99个字符 
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("无法打开文件: %s\n", filename);
        return;
    }


    //1.2控制每行的字符个数 
    char line[81];					 	// 每行最多80个字符
    int row = 1;
    while (fgets(line, 81, file)) { 	// 读取文件
        // 去除行尾的换行符
        if (strchr(line, '\n')) {
            *strchr(line, '\n') = '\0';
        }
        appendLine(list, line, row);
        row++;
    }
    fclose(file);
}

// 打印链表中的所有行
void printLinkedList(LinkedList* list) {
    for (Node* node = list->head; node != NULL; node = node->next) {
        printf("%s\n", node->line);
    }
}

// 1.3统计英文字母数和空格数
void countLettersAndSpaces(LinkedList* list) {
    size_t letters = 0, spaces = 0;

    for (Node* node = list->head; node != NULL; node = node->next) {
        for (size_t i = 0; i < strlen(node->line); i++) {
            if (isalpha(node->line[i])) {
                letters++;
            }
            else if (isspace(node->line[i])) {
                spaces++;
            }
        }
    }
    printf(" \n目前的字母个数为: %zu\n 目前的空格个数为: %zu\n 总个数为: %zu\n", letters, spaces, list->size);
    printf("————————————————————\n");
}

// 1.4删除链表中的指定行
void deleteLine(LinkedList* list, size_t index) {
    Node* prev = NULL;
    Node* current = list->head;
    size_t i = 0;
    while (current != NULL && i < index) {
        prev = current;
        current = current->next;
        i++;
    }
    if (current != NULL) {
        if (prev) {
            prev->next = current->next;
        }
        else {
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
void insertLine(LinkedList* list, char* line, size_t index) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->line = strdup(line);
    newNode->next = NULL;

    Node* prev = NULL;
    Node* current = list->head;
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
        list->head = newNode;
        newNode->next = current;
    }
    if (list->tail == current) {
        list->tail = newNode;
    }
    list->size += strlen(line);
}

// 2.查找字符在链表中的所有出现位置和次数
void findCharOccurrences(LinkedList* list, char target) {
    int total_count = 0;
    printf("字符 '%c' 出现的位置是:\n", target);

    for (Node* node = list->head; node != NULL; node = node->next) {
        const char* line = node->line;
        for (int col = 0; line[col] != '\0'; col++) {
            if (line[col] == target) {
                printf("第 %d 行, 第 %d 列\n", node->row, col + 1);
                total_count++;
            }
        }
    }

    printf("字符 '%c' 出现的次数为: %d\n", target, total_count);
}
//3.删除子串，后面字符前移 
void removeSubstringFromLines(LinkedList* list, char* substring) {
    size_t substringLen = strlen(substring);

    for (Node* node = list->head; node != NULL; node = node->next) {
        char* currentLine = node->line;

        // 查找子串位置
        char* foundPos = strstr(currentLine, substring);

        while (foundPos != NULL) {
            // 计算偏移量
            size_t offset = foundPos - currentLine;

            // 跳过子串
            memmove(foundPos, foundPos + substringLen, strlen(foundPos + substringLen) + 1);

            // 重新计算当前行长度
            list->size -= substringLen;
            list->size += strlen(currentLine) - strlen(node->line);

            // 继续查找下一处子串
            foundPos = strstr(currentLine + offset, substring);
        }
    }
}
//4.保存修改后的文件到指定位置


// 主函数
int main() {
    char substringToSearchFor[100];
    LinkedList list;
    initList(&list);

    readFileToLinkedList(&list);	//调用函数，输入要打开的文件名 
    printf("该文件的内容为:\n");
    printf("\n");
    printLinkedList(&list);
    printf("\n");
    //countLettersAndSpaces(&list);

    while (1) {
        printf("选择你想实现的功能:\n ");
        printf("\n1.插入一行\n");
        printf("2.删除一行\n");
        printf("3.统计英文字母数和空格数\n");
        printf("4.查找字符\n");
        printf("5.删除子串\n");
        printf("6.保存文件到指定位置\n");
        printf("7.新建空白文件\n");
        printf("8.replace,替换字符串\n");
        printf("9.插入自定义表格\n");
        printf("10.退出\n");
        int choice;
        printf("\n你的选择是：");
        scanf(" %d", &choice);

        if (choice == 10) {
            break;
        }
        else if (choice == 1) {
            size_t index;
            char line[81];
            printf("\n请输入你想插入的位置（第几行后）: \n");
            scanf("%zu", &index);
            printf("请输入你想插入的内容: \n");
            scanf(" %[^\n]", line);
            insertLine(&list, line, index);
        }

        else if (choice == 2) {
            size_t index;
            printf("请输入你想删除的位置（第几行后）: \n");
            scanf("%zu", &index);
            deleteLine(&list, index);
        }

        else if (choice == 3) {
            printf("\n");
            countLettersAndSpaces(&list);
        }

        else if (choice == 4) {
            char targetChar;
            printf("请输入要查找的字符：");
            scanf(" %c", &targetChar);
            findCharOccurrences(&list, targetChar);
        }

        else if (choice == 5) {
            char substringToSearchFor[100];
            printf("请输入你想删除的子串：\n");
            if (fgets(substringToSearchFor, 100, stdin)) {
                // 移除末尾的换行符
                substringToSearchFor[strcspn(substringToSearchFor, "\n")] = 0;

                removeSubstringFromLines(&list, substringToSearchFor); // 删除子串

                // 打印处理后的链表，以便查看删除效果
                printLinkedList(&list);
            }
        }

        else {
            printf("操作失败，请重试。\n");
        }
        printf("目前的文件内容为：\n");
        printLinkedList(&list);
        printf("————————————————————\n");
        //countLettersAndSpaces(&list);
    }

    return 0;
}