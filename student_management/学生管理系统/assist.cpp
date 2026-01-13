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

// 根据学号查找学生
int findByid(struct student* stu, char* id) {
    if (stu->studentSize == 0) {
        return -1; 
    } 
    struct ListNode* curr = stu->head;  
    for (int i = 0; i < stu->studentSize; i++) {
        if (strcmp(id, curr->id) == 0) {
            return i; 
        }
    }
    return -1; 
} 

// 通过姓名查找学生
int findByName(struct student* stu, char* name) {
    if (stu->studentSize == 0) {
        return -1; 
    } 
    struct ListNode* curr = stu->head;  
    for (int i = 0; i < stu->studentSize; i++) {
        if (strcmp(name, curr->name) == 0) {
            return i; 
        }
    }
	return -1;
}