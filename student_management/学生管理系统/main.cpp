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
	/*int mark = 1; 
	while (mark) { 
		displayInitialInterfal();
		char selection = '\0';
		while (1) {
			selection = _getch();
			if (selection == '1' || selection == '2' || selection == '3' || selection == '0') {
				break;
			} else {
				printf("选择无效，请重新输入:\n");
			}
		}
		if (selection == '1') {
			system("cls");
			displayMenuOfLogin(); 
			mark = 0; 
		} else if (selection == '2') {
			system("cls");
			createAccount(); 
			break; 
		} else if (selection == '3') {
			system("cls");
			retrievePassword(); 
			break; 
		} else if (selection == '0') {
			printf("感谢使用学生管理系统，程序即将退出...\n");
			system("pause"); 
			return 0;
		} else {
			printf("选择无效，请重新输入:\n");
		}
	}*/
	
	createAccount(); 

	//displayAllStudent(stu);       
 //   addStudent(stu);    
 //   saveToFile(); 
    return 0; 
}   
