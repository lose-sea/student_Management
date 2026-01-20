#define _CRT_SECURE_NO_WARNINGS 


#include"student.h" 

// 显示学生成绩列表
void displayStudentList(struct student* stu) {
    if (stu == NULL) {
        printf("暂无学生信息\n");
        system("pause");
        return;
    }
    int total_page = (stu->studentSize + 19) / 20;
    int currpage = 1;
    int i = 1;		// 当前学生序号
    struct ListNode* curr = stu->head;
    while (1) {
        printf("序号		高数		近代史		英语		总分\n");
        for (int j = 1; j < 20 && i <= stu->studentSize; j++) {
            printf("%d		%-4.2lf		%-6.2lf		%-4.2lf		%-4.2lf\n", i, curr->Math, curr->History, curr->English, curr->totalscore);
        }
        // 显示导航
        printf("\n\n第 %d 页 / 共 %d 页\n\n", currpage, total_page);
        printf("返回首页(F)    最后一页(L)    上一页(P)    下一页(N)    \n退出(R)\n");
        char selection = '\0';
        while (1) {
            selection = _getch();
            if (selection == 'F' || selection == 'f') {
                if (currpage == 1) {              // 每页显示20个同学信息
                    printf("当前已在第一页\n");
                } else {
                    curr = stu->head;
                    i = 1;
                    currpage = 1;
                    printf("正在跳转...");
                    Sleep(600);
                    break;
                }
            } else if (selection == 'L' || selection == 'l') {
                if (currpage == total_page) {
                    printf("当前已在最后一页\n");
                } else { 
                    int skipNodes = stu->studentSize % 20; 
                    curr = stu->tail; 
                    for (int j = 0; j < skipNodes - 1 && curr != NULL; j++) {
                        curr = curr->prev; 
                    }
                    currpage = total_page;
                    printf("正在跳转...");
                    Sleep(600);
                    break;
                }
            } else if (selection == 'P' || selection == 'p') {
                if (currpage == 1) {
                    printf("当前已在第一页\n");
                } else {
                    // 计算要跳过的节点数
                    int skipNodes = (currpage - 2) * 20;
                    curr = stu->head;
                    for (int j = 0; j < skipNodes && curr != NULL; j++) {
                        curr = curr->next;
                    }
                    i = skipNodes + 1;
                    currpage--;
                    printf("正在跳转...");
                    Sleep(600);
                    break;
                }
            } else if (selection == 'N' || selection == 'n') {
                if (currpage == total_page) {
                    printf("当前已在最后一页\n");
                } else {
                    currpage++;
                    printf("正在跳转...");
                    Sleep(600);
                    break;
                }
            } else if (selection == 'R' || selection == 'r') {
                system("pause");
                return;
            } else {
                printf("输入无效, 请重新输入\n");
            }
            Sleep(600);
            printf("\033[1A");    // 光标上移一行  
            printf("\033[2K");    // 清除整行  
            printf("\r");         // 回到行首  
        }
    }
}