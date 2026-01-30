#define _CRT_SECURE_NO_WARNINGS 


#include"student.h" 



// 学生端登录
void loginOfStudent() {
	char account[300];
	char password[300];
	struct ListNode* curr = NULL;
	while (1) { 
		system("cls"); 
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
	char mark = '\0'; 	
	while (1) { 
		displayMenuOfStudent();
		printf("请选择你要执行的操作: \n");
		mark = _getch(); 
		if (mark < '0' || mark > '5') {
			printf("输入无效, 请重新输入\n"); 
		}
	}
	switch (mark) {
		case '1': {
			printf("=========== 显示学生信息 ===========\n");
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
			break; 
		} 
		case '2': { 
			printf("=========== 查看个人成绩 ===========\n");
			printf("高数成绩: %.2lf\n", curr->Math);
			printf("近代史成绩: %.2lf\n", curr->History);
			printf("英语成绩: %.2lf\n", curr->English); 
			break; 
		} 
		case '3': {
			printf("=========== 查看本班成绩 ===========\n"); 
			displayStudentScoreList(stu);  
			break; 
		} 
		case '4': {
			scoreAnalysis(stu);  
			break; 
		} 
		/*case '5': {
			goto login; 
		} 
		case '0': {
			return 0; 
		}*/
	}
}