#define _CRT_SECURE_NO_WARNINGS 


#include"student.h" 

// 登录功能
void login() {
	system("cls");
	displayMenuOfLogin(); 
	char selection = '\0';
	while (1) {
		selection = _getch();
		if (selection == '1') { 
			system("cls"); 
			break;
		} else if (selection == '2') { 
			system("cls");
			break;
		} else if (selection == '3') { 
			system("cls");
			break;
		} else {
			printf("输入错误, 请重新输入\n");
			Sleep(800);
			printf("\033[1A");    // 光标上移一行  
			printf("\033[2K");    // 清除整行  
		}
	} 
	switch (selection) {
		case '1': {
			char account[300];   
			char password[300]; 
			struct ListNode* curr = NULL; 
			bool mark = true; 
			while (mark) {  
				printf("学生端\n");
				printf("请输入账号: ");
				fgets(account, 300, stdin);
				removeNewline(account); 
				curr = findStudentByAccount(stu, account); 
				if (strlen(account) < 6 || !isAlphanumeric(account)) {
					printf("账号至少为6位数字或英文字母\n"); 
					Sleep(800);
					system("cls");  
					continue; 
				}   
				printf("请输入密码: "); 
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
				if (curr == NULL || strcmp(curr->password, password) != 0) {
					printf("账号或密码输入错误, 请重新输入\n");  
					Sleep(800);
					system("cls"); 
					continue; 
				} else { 
					printf("登录成功"); 
					break; 
				}
			} 
			break; 
		}
		case '2': {
			char account[300];
			char password[300];
			struct teacher* curr = NULL;
			bool mark = true;
			while (mark) {
				printf("教师端\n");
				printf("请输入账号: ");
				fgets(account, 300, stdin);
				removeNewline(account);
				curr = findTeacherByAccount(teach, account);
				if (strlen(account) < 6 || !isAlphanumeric(account)) {
					printf("账号至少为6位数字或英文字母\n");
					Sleep(800);
					system("cls");
					continue;
				} 
				printf("请输入密码: "); 
				
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
				if (curr == NULL || strcmp(curr->password, password) != 0) {
					printf("账号或密码输入错误, 请重新输入\n");
					Sleep(800);
					system("cls");
					continue;
				} else {
					printf("登录成功");
					break;
				}
			}
			break;
		}
		case '3': {
			char account[300];
			char password[300];
			struct manager* curr = NULL;
			bool mark = true;
			while (mark) {
				printf("管理员端\n");
				printf("请输入账号: ");
				fgets(account, 300, stdin);
				removeNewline(account);
				curr = findAdministratorByAccount(manage, account);
				if (strlen(account) < 6 || !isAlphanumeric(account)) {
					printf("账号至少为6位数字或英文字母\n");
					Sleep(800);
					system("cls");
					continue;
				} 
				printf("请输入密码: "); 
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
				if (curr == NULL || strcmp(curr->password, password) != 0) {
					printf("账号或密码输入错误, 请重新输入\n");
					Sleep(800);
					system("cls");
					continue;
				} else {
					printf("登录成功");
					break;
				}
			}
			break;
		}
	}
}