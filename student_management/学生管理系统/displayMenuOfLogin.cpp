#define _CRT_SECURE_NO_WARNINGS 
#include"student.h"
 

// 显示初始界面
void displayInitialInterfal() {
	system("cls");
	printf("=======================================\n");
	printf("=========== 学生管理系统 ==============\n"); 
	printf("=======================================\n");
	printf("\n\n");
	printf("          欢迎使用学生管理系统         \n");
	printf("\n\n");
	printf("=======================================\n");
	printf("=======================================\n"); 
	printf("请选择要执行的操作:\n");  
	printf("1. 登录账号\n");
	printf("2. 注册账号\n");
	printf("3. 找回密码\n");
	printf("0. 退出系统\n");
	char selection = '\0'; 
	while (1) {
		selection = _getch();
		if (selection == '1') {
			system("cls");
			displayMenuOfLogin();
		} else if (selection == '2') {
			system("cls");
			createAccount();
		} else if (selection == '3') {
			system("cls");
			printf("找回密码功能正在开发中，敬请期待！\n");
			Sleep(2000);
			displayInitialInterfal();
		} else if (selection == '0') {
			printf("感谢使用学生管理系统，程序即将退出...\n");
			system("pause");
			return;
		} else {
			printf("选择无效，请重新输入:\n");
		}
	}
}


// 显示操作界面 
void displayOperationInterfal() {
	printf("=======================================\n"); 
	printf("1. 登录账号\n"); 
	printf("2. 注册账号\n");  
	printf("3. 找回密码\n"); 
	printf("0. 退出系统\n");
}


// 显示登录菜单
void displayMenuOfLogin() {
	system("cls");
	printf("=========== 学生管理系统 ==============\n"); 
	printf("========== 请选择登录身份:=============\n");
	printf("********** 1. 管理员登录 **************\n"); 
	printf("********** 2. 教师登录 ****************\n");
	printf("********** 3. 学生登录 ****************\n");
	printf("********** 0. 返回上一级 **************\n");
	printf("=======================================\n");
}    





