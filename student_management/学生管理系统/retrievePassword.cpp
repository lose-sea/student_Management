#define _CRT_SECURE_NO_WARNINGS 


#include"student.h" 

// 找回密码 
void retrievePassword() {
	printf("========= 找回密码 =========\n");
	printf("请输入你的账号类型\n");
	printf("1.学生		2.教师		3.管理员\n");
	char selection = '\0';
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
	switch (selection) {
		case '1': {
			char account[300];
			printf("请输入账号(账号至少为8为数字或英文字母): \n");
			while (1) {
				clearInputBuffer();
				fgets(account, 300, stdin);
				removeNewline(account); 
				if (findStudentByAccount(stu, account) == NULL) {
					printf("该账号不存在\n");
					printf("是否重新输入(是(Y) / 否(N)) : ");
					char judgement = '\0';
					while (1) {
						judgement = _getch();
						if (judgement == 'Y' || judgement == 'y') {
							break;
						} else if (judgement == 'N' || judgement == 'n') {
							printf("退出\n");
							system("pause");
							return;
						} else {
							printf("选择无效, 请重新选择: \n");
						}
					}
				}
				break;
			}  
			struct ListNode* curr = findStudentByAccount(stu, account);
			printf("请输入学号验证: \n"); 
			char id[300];
			while (1) {
				clearInputBuffer();
				fgets(id, 300, stdin);
				removeNewline(id);
				if (strcmp(id, curr->id) != 0) {
					printf("验证失败\n");
					printf("是否重新输入(是(Y) / 否(N)) : ");
					char judgement = '\0';
					while (1) {
						judgement = _getch();
						if (judgement == 'Y' || judgement == 'y') {
							break;
						} else if (judgement == 'N' || judgement == 'n') {
							printf("退出\n");  
							system("pause");  
							return;    
						} else {  
							printf("选择无效, 请重新选择: \n");  
						}
					}
				} else {
					printf("验证成功\n"); 
					Sleep(800);
					printf("\033[1A");    // 光标上移一行  
					printf("\033[2K");    // 清除整行  
				}
			}   
			system("cls"); 
			char password[300] = {0};
			while (1) {  
				system("cls"); 
				printf("请输入新的密码(密码至少为8为数字或英文字母): \n");
				clearInputBuffer();
				int i = 0;
				char ch;
				while ((ch = _getch()) != '\n') {  
					password[i++] = ch;  
					printf("*");  
				}  
				password[i] = '\0';
				if (strlen(password) < 8 || !isAlphanumeric(password)) {
					printf("密码至少为8位数字或英文字母\n");
					Sleep(800);
					continue; 
				} else {
					char temp[300] = {0};
					i = 0;
					printf("请再次输入新密码确认: \n");
					while ((ch = _getch()) != '\n') {
						temp[i++] = ch;
						printf("*");
					}
					temp[i] = '\0'; 
					if (strcmp(temp, password) != 0) {
						printf("两次输入不一样, 请重新输入\n"); 
						continue; 
					} else {
						strcpy(curr->password, password);  
						break; 
					}
				} 
			} 
		}  
		case '2': {
			char account[300];
			printf("请输入账号(账号至少为8为数字或英文字母): \n");
			while (1) {
				clearInputBuffer();
				fgets(account, 300, stdin);
				removeNewline(account); 
				if (findTeacherByAccount(teach, account) == NULL) {
					printf("该账号不存在\n");
					printf("是否重新输入(是(Y) / 否(N)) : ");
					char judgement = '\0';
					while (1) {
						judgement = _getch();
						if (judgement == 'Y' || judgement == 'y') {
							break;
						} else if (judgement == 'N' || judgement == 'n') {
							printf("退出\n");
							system("pause");
							return;
						} else {
							printf("选择无效, 请重新选择: \n");
						}
					}
				}
				break;
			}  
			struct teacher* curr = findTeacherByAccount(teach, account);
			system("cls");
			char password[300] = {0};
			while (1) {
				system("cls");
				printf("请输入新的密码(密码至少为8为数字或英文字母): \n");
				clearInputBuffer();
				int i = 0;
				char ch;
				while ((ch = _getch()) != '\n') {
					password[i++] = ch;
					printf("*");
				}
				password[i] = '\0';
				if (strlen(password) < 8 || !isAlphanumeric(password)) {
					printf("密码至少为8位数字或英文字母\n");
					Sleep(800);
					continue;
				} else {
					char temp[300] = {0};
					i = 0;
					printf("请再次输入新密码确认: \n");
					while ((ch = _getch()) != '\n') {
						temp[i++] = ch;
						printf("*");
					}
					temp[i] = '\0';
					if (strcmp(temp, password) != 0) {
						printf("两次输入不一样, 请重新输入\n");
						continue;
					} else {
						strcpy(curr->password, password);
						break;
					}
				}
			}
		} 
		case '3': {
			char account[300];
			printf("请输入账号(账号至少为8为数字或英文字母): \n");
			while (1) {
				clearInputBuffer();
				fgets(account, 300, stdin);
				removeNewline(account);
				if (findAdministratorByAccount(manage, account) == NULL) {
					printf("该账号不存在\n");
					printf("是否重新输入(是(Y) / 否(N)) : ");
					char judgement = '\0';
					while (1) {
						judgement = _getch();
						if (judgement == 'Y' || judgement == 'y') {
							break;
						} else if (judgement == 'N' || judgement == 'n') {
							printf("退出\n");
							system("pause");
							return;
						} else {
							printf("选择无效, 请重新选择: \n");
						}
					}
				}
				break;
			}
			struct manager* curr = findAdministratorByAccount(manage, account);
			system("cls");
			char password[300] = {0};
			while (1) {
				system("cls");
				printf("请输入新的密码(密码至少为8为数字或英文字母): \n");
				clearInputBuffer();
				int i = 0;
				char ch;
				while ((ch = _getch()) != '\n') {
					password[i++] = ch;
					printf("*");
				}
				password[i] = '\0';
				if (strlen(password) < 8 || !isAlphanumeric(password)) {
					printf("密码至少为8位数字或英文字母\n");
					Sleep(800);
					continue;
				} else {
					char temp[300] = {0};
					i = 0;
					printf("请再次输入新密码确认: \n");
					while ((ch = _getch()) != '\n') {
						temp[i++] = ch;
						printf("*");
					}
					temp[i] = '\0';
					if (strcmp(temp, password) != 0) {
						printf("两次输入不一样, 请重新输入\n");
						continue;
					} else {
						strcpy(curr->password, password);
						break;
					}
				}
			}
		}
	}
}