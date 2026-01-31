#define _CRT_SECURE_NO_WARNINGS 
#include"student.h"   

struct student* stu = NULL;   
struct teacher* teach = NULL;    
struct manager* manage = NULL;   
int main() {
	stu = (struct student*)malloc(sizeof(struct student));
	stu->head = NULL;
	stu->tail = NULL;
	stu->studentSize = 0;

	teach = NULL;  // 链表头指针初始化为 NULL  
	manage = NULL;  // 链表头指针初始化为 NULL   

	loadFromFile();




	int judgement = 1;
	while (judgement) {
		displayInitialInterfal();
	start:
		system("cls");
		displayOfOperation();

		char selection = '\0';
		while (1) {
			selection = _getch();
			if (selection == '1' || selection == '2' || selection == '3' || selection == '0') {
				break;
			} else {
				printf("\n选择无效，请重新输入:\n");
				Sleep(600);
				printf("\033[1A");    // 光标上移一行  
				printf("\033[2K");    // 清除整行   
				printf("\r");
			}
		}
		if (selection == '1') {
			system("cls");
			judgement = 0;
			break;
		} else if (selection == '2') {
			system("cls");
			createAccount();
		} else if (selection == '3') {
			system("cls");
			retrievePassword();
		} else if (selection == '0') {
			printf("\n感谢使用学生管理系统，程序即将退出...\n");
			system("pause");
			return 0;
		} else {
			printf("\n选择无效，请重新输入:\n");
			Sleep(600);
			system("cls");
		}
	}
	judgement = 1;

	// 登录 
login:
	displayMenuOfLogin();
	char selection = '\0';
	while (1) {
		selection = _getch();
		if (selection == '1' || selection == '2' || selection == '3') {
			break;
		} else if (selection == '0') {
			goto start;
		} else {
			printf("\n选择无效，请重新输入:\n");
		}
	}

	// 学生端
	if (selection == '1') {
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
				printf("\n账号至少为6位数字或英文字母\n");
				Sleep(800);
				system("cls");
				continue;
			}
			printf("\n请输入密码: ");
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
				printf("\n账号或密码输入错误, 请重新输入\n");
				Sleep(800);
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
				printf("\n输入无效, 请重新输入\n");
			}
			system("cls");
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
					system("pause");
					break;
				}
				case '2': {
					printf("=========== 查看个人成绩 ===========\n");
					printf("高数成绩: %.2lf\n", curr->Math);
					printf("近代史成绩: %.2lf\n", curr->History);
					printf("英语成绩: %.2lf\n", curr->English);
					system("pause");
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
				case '5': {
					goto login;
				}
				case '0': {
					return 0;
				}
			}
		}
	} else if (selection == '2') {
		// 教师端 
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
				printf("\n账号至少为6位数字或英文字母\n");
				Sleep(800);
				system("cls");
				continue;
			}
			printf("\n请输入密码: ");
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
				printf("\n账号或密码输入错误, 请重新输入\n");
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

			system("cls");
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
				case '9': {
					scoreAnalysis(stu);
					break;
				}
				case 'A':
				case 'a': {
					goto login;
				}
				case '0': {
					return 0;
				}
				default: {
					printf("\n输入无效, 请重新输入\n");
					Sleep(600);
					continue;
				}
			}
		}
	} else if (selection == '3') {
		// 管理员端
		char account[300];
		char password[300];
		struct manager* curr = NULL;
		while (1) {
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
				printf("\n账号或密码输入错误, 请重新输入\n");
				Sleep(800);
				system("cls");
				continue;
			} else {
				printf("\n登录成功");
				break;
			}
		}
		char mark = '\0';
		while (1) {
			displayMenuOfAdministrator();
			printf("请选择你要执行的操作: \n");
			mark = _getch();

			system("cls");
			switch (mark) {
				case '1': {
					createAccount();
					break;
				}
				case '2': {
					displayAccount();
					break;
				}
				case '3': {
					retrievePassword();
					break;
				}
				case '4': {
					deleteAccount();
					break;
				}
				case '5': {
					displayAllStudent(stu);
					break;
				}
				case '6': {
					addStudent(stu);
					break;
				}
				case '7': {
					searchStudentByName(stu);
					break;
				}
				case '8': {
					insertStudent(stu);
					break;
				}
				case '9': {
					updateStudent(stu);
					break;
				}
				case 'A':
				case 'a': {
					deleteStudent(stu);
					break;
				}
				case 'B':
				case 'b': {
					saveToFile();
					break;
				}
				case 'C':
				case 'c': {
					loadFromFile();
					printf("加载成功\n");
					system("pause");
					break;
				}
				case 'D':
				case 'd': {
					goto login;
				}
				case '0': {
					return 0;
				}
				default: {
					printf("\n输入无效, 请重新输入\n");
					Sleep(600);
					continue;
				}
			}
		}
	} 

	//struct ListNode* curr = stu->head;
	//curr = curr->next;
	//curr = curr->next;
	//while (curr != NULL) {
	//	curr->account[0] = '\0';
	//	curr->password[0] = '\0'; 
	//	curr = curr->next; 
	//}


	saveToFile();
	return 0;
	
}
