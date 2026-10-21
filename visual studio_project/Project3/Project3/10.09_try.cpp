#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 80
#define MAX_FILE_SIZE 1024*1024

typedef struct FileData {
    char* data;
    size_t length;
} FileData;

void initFileData(FileData* fd) {
    //fd->data = malloc(MAX_FILE_SIZE);
    fd->length = 0;
}

void freeFileData(FileData* fd) {
    free(fd->data);
    fd->data = NULL;
}

void readFile(FileData* fd, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    while (fgets(fd->data + fd->length, MAX_FILE_SIZE - fd->length, file)) {
        fd->length += strlen(fd->data + fd->length);
    }

    fd->data[fd->length] = '\0';
    fclose(file);
}

void displayFile(FileData* fd) {
    puts(fd->data);
}

void addText(FileData* fd) {
    char line[MAX_LINE_LEN];
    printf("Add Text: ");
    fgets(line, MAX_LINE_LEN, stdin);
    size_t len = strlen(line) - 1; // remove newline character
    if (fd->length + len <= MAX_FILE_SIZE) {
        strcat(fd->data, line);
        fd->length += len;
    }
}

void deleteText(FileData* fd, const char* delStr) {
    int foundPos = -1;
    for (int pos = 0; pos <= fd->length - strlen(delStr); pos++) {
        if (strncmp(fd->data + pos, delStr, strlen(delStr)) == 0) {
            foundPos = pos;
            break;
        }
    }
    if (foundPos > -1) {
        memmove(fd->data + foundPos, fd->data + foundPos + strlen(delStr), strlen(fd->data + foundPos + strlen(delStr)) + 1);
        fd->length -= strlen(delStr);
    }
    else {
        printf("Deletion failed: String not found in file.\n");
    }
}

void replaceText(FileData* fd, const char* search, const char* replace) {
    size_t search_len = strlen(search);
    size_t replace_len = strlen(replace);
    size_t total_len = fd->length;

    int found_pos = 0;
    while ((found_pos = strstr(fd->data, search) - fd->data) + search_len <= total_len && found_pos > -1) {
        memmove(&fd->data[found_pos + replace_len], &fd->data[found_pos + search_len], total_len - (found_pos + search_len));
        strcpy(&fd->data[found_pos], replace);
        total_len += replace_len - search_len;
    }
    fd->data[total_len] = '\0';
    fd->length = total_len;
}

void insertTable(FileData* fd, size_t row_count, size_t col_count) {
    static bool initialized = false;
    if (!initialized) {
        printf("Adding table...");
        // Inserting header
        snprintf(fd->data + fd->length, MAX_FILE_SIZE - fd->length,
            "+----+");
        for (size_t i = 0; i < col_count; i++) {
            strcat(fd->data, "-----+");
        }
        strcat(fd->data, "\n");

        // Adding rows and columns
        for (size_t r = 0; r < row_count; r++) {
            strcat(fd->data, "|     ");
            for (size_t c = 0; c < col_count; c++) {
                strcat(fd->data, "     |");
            }
            strcat(fd->data, "\n");
            strcat(fd->data, "+----+");
            for (size_t i = 0; i < col_count; i++) {
                strcat(fd->data, "-----+");
            }
            strcat(fd->data, "\n");
        }

        fd->length = strlen(fd->data);
        initialized = true;
    }
}

void countChar(FileData* fd, char target) {
    int cnt = 0;
    for (size_t i = 0; i < fd->length; i++)
        if (fd->data[i] == target)
            cnt++;
    printf("%c appears %d times.\n", target, cnt);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* filename = argv[1];
    FileData fileData;
    initFileData(&fileData);

    readFile(&fileData, filename);
    displayFile(&fileData);

    char action;
    do {
        printf("Command(a: Add, d: Delete, r: Replace, t: Table, s: Save, q: Quit): ");
        scanf(" %c", &action);
        switch (action) {
        case 'a':
            addText(&fileData);
            break;
        case 'd': {
            char delStr[128];
            printf("Delete what? : ");
            scanf("%s", delStr);
            deleteText(&fileData, delStr);
            break;
        }
        case 'r': {
            char search[128], replacement[128];
            printf("Search for: ");
            scanf("%s", search);
            printf("Replace with: ");
            scanf("%s", replacement);
            replaceText(&fileData, search, replacement);
            break;
        }
        case 't': {
            unsigned short rows, cols;
            printf("Rows: ");
            scanf("%hu", &rows);
            printf("Columns: ");
            scanf("%hu", &cols);
            insertTable(&fileData, rows, cols);
            break;
        }
        case 's': {
            FILE* output = fopen(filename, "w");
            fwrite(fileData.data, sizeof(char), fileData.length, output);
            fclose(output);
            break;
        }
        }
        if (action != 'q') {
            displayFile(&fileData);
            printf("\n");
        }
    } while (action != 'q');
    freeFileData(&fileData);
    return 0;
}