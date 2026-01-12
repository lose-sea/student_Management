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
    printf("当前班内有 %d 名学生\n", stu->studentSize);
    int i = 0;
    struct ListNode* curr = stu->head;
    while (curr != NULL) {
        printf("序号:%d  ", i++);
        printf("姓名:%s  学号:%s  性别: %s \n", curr->name, curr->id, curr->sex);
        printf("\n");
        i++; 
        curr = curr->next;   
        if (curr != NULL) {
            if (i == 10) {      // 每页显示10位学生信息
                printf("下一页( N )\n"); 
                printf("退出 ( R )"); 
                char selection = '\0'; 
                selection = getch(); 
                if (selection == 'N' || selection == 'n') {
                    curr = curr->next; 
                } else if (selection == 'R' || selection == 'r') {
                    system("pause"); 
                }
                
            }
        }
    }
    printf("下一页: 'N'");
    char turn_page;
    while (1) {
        turn_page = _getch(); 
        clearInputBuffer();
        printf("\b");
        if (turn_page == 'N' || turn_page == 'n') {
            break;
        }
        else {
            scanf("输入无效, 请重新输入!");
            continue;
        }
    }

}