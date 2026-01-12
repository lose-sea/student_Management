#define _CRT_SECURE_NO_WARNINGS 
#include"student.h"
// 显示所有学生信息
void displayAllStudent(struct student* stu) {
    system("cls");
    if (stu->studentSize == 0) {
        printf("暂无学生信息\n");
        system("pause");
        return;
    }
    int totalpage = (stu->studentSize - 1) / 10;        // 总页数
    int currpage = 0;               // 当前页码 
    printf("当前班内有 %d 名学生\n", stu->studentSize); // 显示所有学生目录 
    int i = 0;  
    struct ListNode* curr = stu->head;
    while (curr != NULL) {
        printf("序号:%d  ", ++i);
        printf("姓名:%s  学号:%s  性别: %s \n", curr->name, curr->id, curr->sex);
        printf("\n"); 
        curr = curr->next;   
        if (i == 10 && i != stu->studentSize) {      // 每页显示10位学生信息     
            printf("下一页( N )\n"); 
            printf("退出 ( R )\n"); 
            char selection = '\0'; 
            while (1) { 
                selection = _getch(); 
                if (selection == 'N' || selection == 'n') { 
                    curr = curr->next;  
                    system("cls"); 
                } else if (selection == 'R' || selection == 'r') {
                    system("pause"); 
                    return; 
                } else {
                    printf("输入错误, 请重新输入\n"); 
                }
            }
        } else if (i == 10 && stu->studentSize == 10) {
             system("pause"); 
        } else if (i == stu->studentSize && i > 10) {
            printf("下一页( P )\n"); 
            printf("退出 ( R )\n"); 
            char selection = '\0'; 
            while (1) { 
                selection = _getch(); 
                if (selection == 'P' || selection == 'p') {
                    for (int j = 0; j < 10; j++) {
                        curr = curr->prev; 
                        --i;  
                    }  
                    system("cls"); 
                } else if (selection == 'R' || selection == 'r') {
                    system("pause"); 
                    return; 
                } else {
                    printf("输入错误, 请重新输入\n"); 
                }
            }
        } else if (i % 10 == 0) { 
            printf("上一页( P ) \t\t 下一页( N )\n"); 
            printf("退出 ( R )\n"); 
            char selection = '\0'; 
            while (1) { 
                selection = _getch(); 
                if (selection == 'N' || selection == 'n') {
                    curr = curr->next; 
                    system("cls"); 
                } else if (selection == 'P' || selection == 'p') {
                    for (int j = 0; j < 10; j++) {
                        curr = curr->prev; 
                        --i; 
                    } 
                    system("cls"); 
                } else if (selection == 'R' || selection == 'r') {
                    system("pause"); 
                    return; 
                } else {
                    printf("输入错误, 请重新输入\n"); 
                }
            }
        }
    }
}