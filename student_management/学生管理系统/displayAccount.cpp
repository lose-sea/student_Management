#define _CRT_SECURE_NO_WARNINGS 


#include"student.h" 

// 查看账号 
void displayAccount() {
	system("cls"); 
	printf("查看账号\n"); 
	printf("学生账号列表:\n"); 
	struct ListNode* curr_student = stu->head; 
	while (curr_student != NULL) {
		printf("账号: %s 密码: %s\n", curr_student->account, curr_student->password);  
		curr_student = curr_student->next; 
	} 
	printf("\n\n"); 
	printf("教师账号列表: \n"); 
	struct teacher* curr_teacher = teach; 
	while (curr_teacher != NULL) {
		printf("账号: %s 密码: %s\n", curr_student->account, curr_student->password); 
		curr_teacher = curr_teacher->next; 
	} 
	printf("\n\n"); 
	printf("管理员账号列表:\n"); 
	struct manager* curr_manager = manage; 
	while (curr_manager != NULL) {
		printf("账号: %s 密码: %s\n", curr_student->account, curr_student->password); 
		curr_manager = curr_manager->next; 
	} 
	system("pause"); 
}