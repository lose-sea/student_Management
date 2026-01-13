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
    int currpage = 1;               // 当前页码 
    printf("当前班级有 %d 名学生\n", stu->studentSize); // 显示所有学生目录 
    int i = 0;  
    struct ListNode* curr = stu->head;
    while (curr != NULL) { 
        for (int j = 0; j < 10 && i < stu->studentSize; j++) {
            printf("序号:%d  ", ++i);
            printf("姓名:%s  学号:%s  性别: %s \n", curr->name, curr->id, curr->sex);
            printf("\n"); 
            curr = curr->next;   
        }
        // 显示导航
        printf("返回首页(F) \t 最后一页(L) \t 上一页(P) \t 下一页(N)"); 
    }
}