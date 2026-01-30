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



	int mark = 1; 
	loadFromFile();
	while (mark) {
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
				printf("选择无效，请重新输入:\n");
				Sleep(600);
				printf("\033[1A");    // 光标上移一行  
				printf("\033[2K");    // 清除整行   
				printf("\r");
			}
		}
		if (selection == '1') {
			system("cls");
			mark = 0;
			break;
		} else if (selection == '2') {
			system("cls");
			createAccount();
		} else if (selection == '3') {
			system("cls");
			retrievePassword();
		} else if (selection == '0') {
			printf("感谢使用学生管理系统，程序即将退出...\n");
			system("pause");
			return 0;
		} else {
			printf("选择无效，请重新输入:\n");
			Sleep(600);
			system("cls");
		}
	}
	mark = 1;

	// 登录
	displayMenuOfLogin();
	char selection = '\0';
	while (1) {
		selection = _getch();
		if (selection == '1' || selection == '2' || selection == '3' || selection == '0') {
			break;
		} else {
			printf("选择无效，请重新输入:\n");
		}
	}
	if (selection == '0') {
		goto start;
	} 
	
	
	 
	saveToFile(); 
    return 0; 
}   
