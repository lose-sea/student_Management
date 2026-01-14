#define _CRT_SECURE_NO_WARNINGS 


#include"student.h" 

void deleteSrudent(struct student* stu) {
	if (stu->studentSize == 0) {
		printf("当前暂无学生信息\n"); 
		system("pause"); 
		return; 
	} 
	printf("请输入你要删除的学生姓名: "); 
	char name[300];
	fgets(name, 300, stdin);
	removeNewline(name);
	struct ListNode* curr = stu->head;
	while (curr != NULL) { 
		if (strcmp(name, curr->name) == 0) {
			break; 
		}
		curr = curr->next;
	}
	if (curr == NULL) {
		printf("不存在学生 %s 的信息\n", name);
		system("pause");
		return;
	} else {
		// 找到学生信息，进行删除
		struct ListNode* prev = stu->head;
		while (prev->next != curr) {
			prev = prev->next;
		}
		prev->next = curr->next; 
		curr->next->prev = prev; 
		free(curr); 
		stu->studentSize--;		// 删除成功，学生数量减一
		printf("已成功删除学生 %s 的信息\n", name);
		system("pause");
		return;
	}
}