#define _CRT_SECURE_NO_WARNINGS 

#include"student.h" 

// 显示班级学生具体信息 
void  displayAllStudent(struct student* stu) {
    system("cls");
    if (stu->studentSize == 0) {
        printf("暂无学生信息\n");
        system("pause");
        return;
    }
    int directorypage = (stu->studentSize + 9) / 10;        // 目录页数  
	int totalpage = directorypage + stu->studentSize;       // 总页数（目录页数 + 学生信息页数）
    int currpage = 1;               // 当前页码 
    int i = 1;                  // 当前显示的学生序号
    struct ListNode* curr = stu->head;

    while (1) {
        system("cls");
        printf("当前班级有 %d 名学生\n", stu->studentSize); 
        if (currpage <= directorypage) { 
            printf("=========== 显示学生目录 ===========\n\n\n"); 
            for (int j = 0; j < 10 && i <= stu->studentSize && curr != NULL; j++) {
                printf("序号:%d  ", i);
                printf("姓名:%s  学号:%s  性别: %s \n\n", curr->name, curr->id, curr->sex); 
				curr = curr->next;  
                i++; 
            }
		} else if (currpage > directorypage) {
            printf("=========== 显示学生信息 ===========\n");
            printf("序号:%d  \n", i);
            printf("学号: %s\n", curr->id);
            printf("姓名: %s\n", curr->name);
            printf("性别: %s\n", curr->sex);
            printf("年龄: %d\n", curr->age);
            printf("电话: %s\n", curr->telephone);
            printf("专业: %s\n", curr->major);
            printf("高数成绩: %.2lf\n", curr->Math);
            printf("近代史成绩: %.2lf\n", curr->History);
            printf("英语成绩: %.2lf\n", curr->English);
            printf("成绩: %.2f\n", curr->totalscore);
            printf("年级: %s\n", curr->grade);
            printf("班级: %s\n\n", curr->class1);
        }
        // 显示导航
        printf("\n\n第 %d 页 / 共 %d 页\n\n", currpage, totalpage);
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
                    Sleep(600);
                    break;
                }
            } else if (selection == 'L' || selection == 'l') {
                if (currpage == totalpage) {
                    printf("当前已在最后一页\n");
                } else {
                    curr = stu->head;
                    for (int j = 0; j  < stu->studentSize - 1; j++) {
                        curr = curr->next;
					}
                    i = stu->studentSize;
                    currpage = totalpage;
                    printf("正在跳转...");
                    Sleep(600);
                    break;
                }
            }
            else if (selection == 'P' || selection == 'p') {
                if (currpage == 1) {
                    printf("当前已在第一页\n"); 
                } else if (currpage == directorypage + 1) {
                    curr = stu->head; 
                    curr = stu->head;
					int skipNodes = (currpage - 2) * 10; 
                    currpage--;
                    for (int j = 0; j < skipNodes && curr != NULL; j++) {
                        curr = curr->next;
                    }
                    i = skipNodes + 1;
                    printf("正在跳转...");
                    Sleep(600);
                    break; 
                } else if (currpage <= directorypage){
                    // 计算要跳过的节点数
                    int skipNodes = (currpage - 2) * 10;
                    curr = stu->head;
                    for (int j = 0; j < skipNodes && curr != NULL; j++) {
                        curr = curr->next;
                    }
                    i = skipNodes + 1;
                    currpage--; 
                    printf("正在跳转...");
                    Sleep(600);
                    break;
                } else { 
					if (curr->prev != NULL) {
                        curr = curr->prev;
                    }
                    i--; 
		            
                    currpage--;                     
                    printf("正在跳转...");
                    Sleep(600);
					break;
                }
            } else if (selection == 'N' || selection == 'n') {
                if (currpage == totalpage) {
                    printf("当前已在最后一页\n");
                } else if (currpage == directorypage) {
                    curr = stu->head; 
                    i = 1; 
                    currpage++; 
                    printf("正在跳转...");
                    Sleep(600); 
                    break; 
                } else if (currpage > directorypage) {
                    if (curr != NULL) {
                        curr = curr->next;
					} 
                    i++;
                    currpage++;
                    printf("正在跳转...");
                    Sleep(600);
                    break;
                }  else {
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
