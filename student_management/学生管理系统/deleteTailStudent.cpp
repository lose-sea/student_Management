#define _CRT_SECURE_NO_WARNINGS 

#include"student.h"
// 删除尾部学生记录
void deleteTailStudent(struct student* stu) {
	if (stu->studentSize == 0) {
		printf("没有学生记录可删除。\n");
		return;
	}
	struct ListNode* curr = stu->head;
	// 遍历到链表的最后一个节点
	while (curr->next != NULL) {
		curr = curr->next;
	} 
	struct ListNode* prev = curr->prev;
	// 如果只有一个节点
	if (prev == NULL) {
		stu->head = NULL;
	} else {
		prev->next = NULL;
	} 
	stu->tail = prev; 
	free(curr);
	stu->studentSize--;
	printf("已删除尾部学生记录\n"); 
	system("pause"); 
}