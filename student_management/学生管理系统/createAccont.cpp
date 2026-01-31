#define _CRT_SECURE_NO_WARNINGS 


#include"student.h" 

// 注册账号
void createAccount() { 
    system("cls"); 
	printf("========= 注册账号 =========\n"); 
	printf("请输入你要注册的账号类型\n"); 
	printf("1.学生		2.教师		3.管理员\n"); 
    printf("0.返回上一层\n");  
	char selection; 
	while (1) {
		selection = _getch();  
		if (selection == '1') { 
            system("cls");
			printf("学生端\n"); 
			break; 
		} else if (selection == '2') { 
            system("cls");
			printf("教师端\n"); 
			break;     
		} else if (selection == '3') { 
            system("cls");
			printf("管理员端\n"); 
			break; 
        } else if (selection == '0') {
            return; 
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
            while (1) {  
                printf("请输入学号: \n");
                fgets(id, 300, stdin);
                removeNewline(id);
                if (!isDigit(id)) {    
                    printf("学号应为纯数字, 请重新输入\n");
                    Sleep(800);
                    system("cls"); 
                    continue;
                } else if (strlen(id) == 0) {
                    printf("学号不能为空, 请重新输入\n");
                    Sleep(800);
                    system("cls");
                    continue;
                }
                if (findByid(stu, id) == NULL) {
                    printf("该学生不存在\n");
                    printf("是否重新输入(是(Y) 否(N)): \n");
                    char selection = 0;
                    while (1) {  
                        selection = _getch();
                        if (selection == 'Y' || selection == 'y') { 
                            system("cls");
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
                }  else {
                    break; 
                }
            }
            struct ListNode* curr = findByid(stu, id);
            printf("请输入账号(账号至少为6位数字或英文字母): \n");
            char account[300];
            while (1) { 
                fgets(account, 300, stdin);
                removeNewline(account);
                if (strlen(account) < 6 || !isAlphanumeric(account)) {
                    printf("账号至少为6位数字或英文字母\n");
                    Sleep(800);
                    printf("\033[1A");    // 光标上移一行    
                    printf("\033[2K");    // 清除整行      
                    printf("\033[1A");    // 光标上移一行    
                    printf("\033[2K");    // 清除整行     
                    printf("\r");  
                } else if (findStudentByAccount(stu, account) != NULL) {  
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
            printf("请输入密码(密码至少为6为数字或英文字母): \n");
            char password[300] = {0};
            while (1) { 
                int i = 0;  
                char ch; 
                while ((ch = _getch()) != '\r')  // 检测回车按键 '\r'
                {
                    if (ch == '\b' && i > 0) { // 处理退格键
                        i--;
                        printf("\b \b");  // 退格并清空显示
                    } else if (ch != '\b') {
                        password[i++] = ch;
                        printf("*");
                    }
                }
                password[i] = '\0';
                if (strlen(password) < 6 || !isAlphanumeric(password)) {    
                    printf("\n密码至少为6位数字或英文字母\n");   
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
            saveToFile();  
            break; 
        }    
        case '2': { 
            printf("请输入账号(账号至少为6为数字或英文字母): \n"); 
            struct teacher* node = (struct teacher*)malloc(sizeof(struct teacher)); 
            char account[300];
            while (1) { 
                fgets(account, 300, stdin);
                removeNewline(account); 
                if (strlen(account) < 6 || !isAlphanumeric(account)) {
                    printf("账号至少为6位数字或英文字母\n");
                    Sleep(800);
                    printf("\033[1A");    // 光标上移一行    
                    printf("\033[2K");    // 清除整行      
                    printf("\033[1A");    // 光标上移一行    
                    printf("\033[2K");    // 清除整行     
                    printf("\r");
                } else if (findTeacherByAccount(teach, account) != NULL) {
                    printf("已存在该账号\n");
                    Sleep(800);
                    printf("\033[1A");    // 光标上移一行  
                    printf("\033[2K");    // 清除整行   
                    printf("\033[1A");    // 光标上移一行  
                    printf("\033[2K");    // 清除整行   
                    printf("\r"); 
                    printf("是否重新输入： 是(Y) 否(N)\n");
                    char selection = 0;
                    while (1) {  
                        selection = _getch();
                        if (selection == 'Y' || selection == 'y') {
                            break;
                        } else if (selection == 'N' || selection == 'n') {
                            printf("返回上一层\n");
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
                } else {
                    break; 
                }
            }
            printf("请输入密码(密码至少为6位数字或英文字母): \n");
            char password[300] = {0};
            while (1) { 
                int i = 0;  
                char ch; 
                while ((ch = _getch()) != '\r')  // 检测回车按键 '\r'
                {
                    if (ch == '\b' && i > 0) {
                        i--;
                        printf("\b \b");  // 退格并清空显示
                    } else if (ch != '\b') {
                        password[i++] = ch;
                        printf("*");
                    }
                }
                password[i] = '\0';
                if (strlen(password) < 6 || !isAlphanumeric(password)) {
                    printf("\n密码至少为6位数字或英文字母\n");
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
            node->next = teach;  
            teach = node;   
            saveToFile(); 
            break; 
        } 
        case '3': {
            printf("请输入账号(账号至少为6位数字或英文字母): \n");
            struct manager* node = (struct manager*)malloc(sizeof(struct manager));
            char account[300];
            while (1) { 
                fgets(account, 300, stdin);
                removeNewline(account);
                if (strlen(account) < 6 || !isAlphanumeric(account)) {
                    printf("账号至少为6位数字或英文字母\n");
                    Sleep(800);
                    printf("\033[1A");    // 光标上移一行    
                    printf("\033[2K");    // 清除整行      
                    printf("\033[1A");    // 光标上移一行    
                    printf("\033[2K");    // 清除整行     
                    printf("\r");
                } else if (findAdministratorByAccount(manage, account) != NULL) {
                    printf("已存在该账号\n");
                    Sleep(800);
                    printf("\033[1A");    // 光标上移一行  
                    printf("\033[2K");    // 清除整行   
                    printf("\033[1A");    // 光标上移一行  
                    printf("\033[2K");    // 清除整行   
                    printf("\r");
                    printf("是否重新输入： 是(Y) 否(N)\n");
                    char selection = 0;
                    while (1) { 
                        selection = _getch();
                        if (selection == 'Y' || selection == 'y') {
                            break;
                        } else if (selection == 'N' || selection == 'n') {
                            printf("返回上一层\n");
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
                } else {
                    break;
                }
            } 
            printf("请输入密码(密码至少为6位数字或英文字母): \n");
            char password[300] = {0};
            while (1) { 
                int i = 0;  
                char ch; 
                while ((ch = _getch()) != '\r')  // 检测回车按键 '\r'
                {
                    if (ch == '\b' && i > 0) {
                        i--;
                        printf("\b \b");  // 退格并清空显示
                    } else if (ch != '\b') {
                        password[i++] = ch;
                        printf("*");
                    }
                }
                password[i] = '\0';
                if (strlen(password) < 6 || !isAlphanumeric(password)) {
                    printf("\n密码至少为6位数字或英文字母\n");
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
            node->next = manage; 
            manage = node;   
            saveToFile();  
            break; 
        }
    }  
}  