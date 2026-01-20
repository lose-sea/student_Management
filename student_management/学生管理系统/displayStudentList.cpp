#define _CRT_SECURE_NO_WARNINGS 


#include"student.h" 

// 显示学生成绩列表
void displayStudentList(struct student* stu) {
	if (stu == NULL) {
		printf("暂无学生信息\n"); 
		system("pause");  
		return; 
	}  
	struct ListNode* curr = stu->head;  
	printf("序号		高数		近代史		英语		总分\n"); 
	for (int i = 1; i <= stu->studentSize; i++) {
		printf("%-4d		%-4d		%-6d		%-4d		%-4d\n", curr->Math, curr->History, curr->English);  

	} 
}