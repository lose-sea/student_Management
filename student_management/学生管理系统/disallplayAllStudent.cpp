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
    int totalpage = (stu->studentSize + 9) / 10;        // 总页数
    int currpage = 1;               // 当前页码 
    int i = 1;  
    struct ListNode* curr = stu->head;
    while (1) {  
        system("cls"); 
        
        printf("当前班级有 %d 名学生\n", stu->studentSize);  
        
        for (int j = 0; j < 10 && i <= stu->studentSize && curr != NULL; j++) {
            printf("序号:%d  ", i);
            printf("姓名:%s  学号:%s  性别: %s \n", curr->name, curr->id, curr->sex);
            printf("\n"); 
            i++; 
            curr = curr->next; 
        }
        // 显示导航
        printf("第 %d 页 / 共 %d 页\n", currpage, totalpage); 
        printf("返回首页(F)    最后一页(L)    上一页(P)    下一页(N)    \n退出(R)\n"); 
        char selection = '\0';  
        while (1) { 
            selection = _getch(); 
            if (selection == 'F' || selection == 'f') {
                if (currpage == 1) {              // 每页显示10个同学信息
                    printf("当前已在第一页\n"); 
                } else {
                    curr = stu->head; 
                    i = 1;   
                    currpage = 1; 
                    printf("正在跳转..."); 
                    Sleep(1500); 
                    break; 
                }
            } else if (selection == 'L' || selection == 'l') {
                if (currpage == totalpage) {
                    printf("当前已在最后一页\n"); 
                } else { 
                    curr = stu->head; 
                    // 计算要跳过的节点数
                    int skipNodes = (totalpage - 1) * 10; 
                    for (int j = 0; j < skipNodes; j++) {
                        curr = curr->next; 
                    } 
                    i = skipNodes + 1; 
                    currpage = totalpage; 
                    printf("正在跳转..."); 
                    Sleep(1500); 
                    break; 
                }
            } else if (selection == 'P' || selection == 'p') {
                if (currpage == 1) {
                    printf("当前已在第一页\n"); 

                } else { 
                    // 计算要跳过的节点数
                    int skipNodes = (currpage - 2) * 10; 
                    curr = stu->head; 
                    for (int j = 0; j < skipNodes && curr != NULL; j++) {
                        curr = curr->next; 
                    } 
                    i = skipNodes + 1; 
                    currpage--; 
                    break; 
                }
            } else if (selection == 'N' || selection == 'n') {
                if (currpage == totalpage) {
                    printf("当前已在最后一页\n"); 
                    Sleep(2000); 
                } else { 
                    currpage++; 
                    break; 
                }
            } else if (selection == 'R' || selection == 'r') {
                system("pause"); 
                return; 
            } else {
                printf("输入无效, 请重新输入\n"); 
            }
            Sleep(2000);
            printf("\033[1A");    // 光标上移一行
            printf("\033[2K");    // 清除整行
            printf("\r");         // 回到行首 
        }
    }
}