#define _CRT_SECURE_NO_WARNINGS 


#include"student.h" 

// 注册账号
void createAccount() {
	printf("===== 注册账号 =====\n"); 
	printf("请输入你要注册的账号类型\n"); 
	printf("1.学生		2.教师		3.管理员"); 
	char selection; 
	while (1) {
		selection = _getch(); 
		if (selection == '1') {
			printf("学生端\n"); 
			break; 
		} else if (selection == '2') {
			printf("教师端\n"); 
			break; 
		} else if (selection == '3') {
			printf("管理员端\n"); 
			break; 
		} else {
			printf("输入错误, 请重新输入\n"); 
			Sleep(800);
			printf("\033[1A");    // 光标上移一行  
			printf("\033[2K");    // 清除整行  
		}
	} 

	// 学生端
	if (selection == '1') {
		FILE* pf = fopen("studentAccount.bin", "r");  
		if (pf == NULL) {
			printf("文件打开失败\n");  
			return; 
		} 

        char id[300]; 
        printf("请输入学号: \n");
        while (1) {
            fgets(id, 300, stdin);
            removeNewline(id);
            if (!isDigit(id)) {
                printf("学号应为纯数字, 请重新输入\n");
                Sleep(800);
                printf("\033[1A");    // 光标上移一行  
                printf("\033[2K");    // 清除整行  
                continue;
            } else if (strlen(id) == 0) {
                printf("学号不能为空, 请重新输入\n");
                Sleep(800);
                printf("\033[1A");    // 光标上移一行  
                printf("\033[2K");    // 清除整行  
                continue;
            }
            if (findByid(&stu, id) != -1) {
                printf("已经存在该学号的学生\n");
                printf("是否重新输入： 是(Y) 否(N)\n");
                char selection = 0;
                while (1) {
                    selection = _getch();
                    if (selection == 'Y' || selection == 'y') {
                        break;
                    } else if (selection == 'N' || selection == 'n') {
                        printf("退出\n");
                        system("pause");
                        return;
                    } else {
                        printf("选择错误, 请重新选择\n");
                        Sleep(800);
                        system("cls");
                        continue;
                    }
                }
            } else {
                // 学号验证通过，跳出循环
                break;
            }
        }
	}
}