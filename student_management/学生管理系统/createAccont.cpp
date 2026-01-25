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
    switch (selection) { 
        case '1': {
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
                    printf("\033[1A");    // 光标上移一行  
                    printf("\033[2K");    // 清除整行   
                    printf("\r");
                    continue;
                } else if (strlen(id) == 0) {
                    printf("学号不能为空, 请重新输入\n");
                    Sleep(800);
                    printf("\033[1A");    // 光标上移一行  
                    printf("\033[2K");    // 清除整行   
                    printf("\033[1A");    // 光标上移一行  
                    printf("\033[2K");    // 清除整行   
                    printf("\r");
                    continue;
                }
                if (findByid(&stu, id) == NULL) {
                    printf("该学生不存在\n");
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
                            printf("\033[1A");    // 光标上移一行  
                            printf("\033[2K");    // 清除整行   
                            printf("\r");
                        }
                    }
                }
            }
            struct ListNode* curr = findByid(&stu, id);
            printf("请输入账号(账号至少为8为数字或英文字母): \n");
            char account[300];
            while (1) {
                fgets(account, 300, stdin);
                removeNewline(account);
                if (strlen(account) < 8 || !isAlphanumeric(account)) {
                    printf("账号至少为8位数字或英文字母\n");
                    Sleep(800);
                    printf("\033[1A");    // 光标上移一行    
                    printf("\033[2K");    // 清除整行      
                    printf("\033[1A");    // 光标上移一行    
                    printf("\033[2K");    // 清除整行     
                    printf("\r");  
                } else if (findStudentByAccount(&stu, account) != NULL) {  
                    printf("已存在该账号\n");  
                    Sleep(800);  
                    printf("\033[1A");    // 光标上移一行  
                    printf("\033[2K");    // 清除整行   
                    printf("\033[1A");    // 光标上移一行  
                    printf("\033[2K");    // 清除整行   
                    printf("\r");
                } else {
                    break;
                }
            }
            char password[300];
            while (1) {
                fgets(password, 300, stdin);    
                removeNewline(password);   
                if (strlen(password) < 8 || !isAlphanumeric(password)) {    
                    printf("密码至少为8位数字或英文字母\n");   
                    Sleep(800);  
                    printf("\033[1A");    // 光标上移一行  
                    printf("\033[2K");    // 清除整行   
                    printf("\033[1A");    // 光标上移一行    
                    printf("\033[2K");    // 清除整行   
                    printf("\r"); 
                } else {  
                    break;  
                }  
            }  
            strcpy(curr->account, account);  
            strcpy(curr->password, password);   
            saveToFile(&stu); 
        }    
        case '2': { 
            printf("请输入账号(账号至少为8为数字或英文字母): \n"); 
            struct teacher* node = (struct teacher*)malloc(sizeof(struct teacher)); 
            char account[300];
            while (1) {
                fgets(account, 300, stdin);
                removeNewline(account); 
                if (strlen(account) < 8 || !isAlphanumeric(account)) {
                    printf("账号至少为8位数字或英文字母\n");
                    Sleep(800);
                    printf("\033[1A");    // 光标上移一行    
                    printf("\033[2K");    // 清除整行      
                    printf("\033[1A");    // 光标上移一行    
                    printf("\033[2K");    // 清除整行     
                    printf("\r");
                } else if (findStudentByAccount(&stu, account) != NULL) {
                    printf("已存在该账号\n");
                    Sleep(800);
                    printf("\033[1A");    // 光标上移一行  
                    printf("\033[2K");    // 清除整行   
                    printf("\033[1A");    // 光标上移一行  
                    printf("\033[2K");    // 清除整行   
                    printf("\r");
                } else {
                    break;
                }
            }
            char password[300];
            while (1) {
                fgets(password, 300, stdin);
                removeNewline(password);
                if (strlen(password) < 8 || !isAlphanumeric(password)) {
                    printf("密码至少为8位数字或英文字母\n");
                    Sleep(800);
                    printf("\033[1A");    // 光标上移一行  
                    printf("\033[2K");    // 清除整行   
                    printf("\033[1A");    // 光标上移一行    
                    printf("\033[2K");    // 清除整行   
                    printf("\r");
                } else {
                    break;
                }
            }
            strcpy(node->account, account);
            strcpy(node->password, password);
            saveToFile(&stu);
        }
    }  
}  