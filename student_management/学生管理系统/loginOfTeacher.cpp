#define _CRT_SECURE_NO_WARNINGS 


#include"student.h" 



// 教师端登录
void loginOfTeacher() {
	char account[300];
	char password[300];
	struct teacher* curr = NULL;
	while (1) { 
		system("cls"); 
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
	char mark = '\0';
	while (1) {
		displayMenuOfTeacher();
		printf("请选择你要执行的操作: \n");
		mark = _getch();
		if (mark < '0' || mark > '9') {
			printf("输入无效, 请重新输入\n");
		}
	}
	switch (mark) {
		case '1': {
			displayAllStudent(stu); 
			break;
		}
		case '2': {
			addStudent(stu); 
			break;
		}
		case '3': {
			printf("查找学生信息\n"); 
			searchStudentByName(stu); 
			break;
		}
		case '4': { 
			insertStudent(stu); 
			break;
		}
		case '5': {
			updateStudent(stu); 
			break; 
		} 
		case '6': {
			deleteStudent(stu); 
			break; 
		} 
		case '7': {
			saveToFile();  
			break; 
		} 
		case '8': {
			displayStudentScoreList(stu); 
			break; 
		} 
		/*case '9': {
			goto login; 
		}
		case '0': {
			return 0;
		}*/
	}
}