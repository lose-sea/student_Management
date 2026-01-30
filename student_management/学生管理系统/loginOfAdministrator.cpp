#define _CRT_SECURE_NO_WARNINGS 


#include"student.h" 

// 管理员端登录
void loginOfAdministrator() {
	char account[300];
	char password[300];
	struct manager* curr = NULL;
	bool mark = true;
	while (mark) { 
		system("cls"); 
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
		char mark = '\0';
		while (1) {
			displayMenuOfTeacher();
			printf("请选择你要执行的操作: \n");
			mark = _getch();
			if ((mark >= '0' && mark <= '9') || mark >= 'A' && mark <= 'E') {
				printf("输入无效, 请重新输入\n");
			}
		}
		switch (mark) {
			case '1': {
				
				break;
			}
			case '2': {
				createAccount(); 
				break;
			}
			case '3': {
				
				break;
			}
			case '4': {
				retrievePassword(); 
				break;
			}
			case '5': {
				
				break;
			}
			case '6': {
				displayAllStudent(stu); 
				break;
			}
			case '7': {
				addStudent(stu); 
				break;
			}
			case '8': {
				searchStudentByName(stu); 
				break;
			}
			case '9': {
				insertStudent(stu);  
				break; 
			} 
			case 'A': {
				updateStudent(stu); 
				break; 
			} 
			case 'B': {
				deleteStudent(stu);  
				break; 
			} 
			case 'C': {
				saveToFile(); 
				break; 
			} 
			case 'D': {
				loadFromFile(); 
				printf("加载成功\n"); 
				system("pause"); 
				break; 
			} 
			/*case 'E': {
				goto login; 
			}
			case '0': {
				return 0;
			}*/
		}
	}
}