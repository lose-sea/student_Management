#define _CRT_SECURE_NO_WARNINGS 
#include"student.h"


// 去除fgets输入的字符串末尾的换行符
void removeNewline(char* str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}


// 清除输入缓冲区
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {

    }
}

// // 检查输入是否合法
bool isValid(int judge) {
    return judge == 1;
}

// 检查输入的字符串是否由纯数字组成
bool isDigit(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}
