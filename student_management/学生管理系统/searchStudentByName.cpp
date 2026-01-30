#define _CRT_SECURE_NO_WARNINGS 


#include"student.h" 
// 通过姓名查找学生
void searchStudentByName(struct student* stu) { 
	system("cls");
	if (stu->head == NULL) {
		printf("当前暂无学生信息\n"); 
		system("pause"); 
		return; 
	}   
	printf("请输入你要查找的学生姓名: ");  
	char name[300]; 
	fgets(name, 300, stdin); 
	removeNewline(name); 
	struct ListNode* curr = stu->head; 
	while (curr != NULL) {
		if (strcmp(name, curr->name) == 0) {
			printf("学号: %s\n", curr->id);
			printf("姓名: %s\n", curr->name);
			printf("性别: %s\n", curr->sex);
			printf("年龄: %d\n", curr->age);
			printf("电话: %s\n", curr->telephone);
			printf("专业: %s\n", curr->major);
			printf("语文成绩: %.2lf\n", curr->Math); 
			printf("数学成绩: %.2lf\n", curr->History);
			printf("英语成绩: %.2lf\n", curr->English);
			printf("成绩: %.2f\n", curr->totalscore);
			printf("年级: %s\n", curr->grade);
			printf("班级: %s\n\n", curr->class1);
			system("pause");
			return;
		}
		curr = curr->next;
	}
	printf("未找到该学生信息\n");
	system("pause");
}
