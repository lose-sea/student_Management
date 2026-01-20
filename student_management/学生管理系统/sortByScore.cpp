#define _CRT_SECURE_NO_WARNINGS 

#include"student.h" 

//根据成绩总分进行排序(降序) 
void sortByScore(struct student* stu) {
	if (stu->studentSize <= 1) {
		return; // 学生数量小于等于1，无需排序
	}
	// 使用冒泡排序对链表进行排序
	for (int i = 0; i < stu->studentSize - 1; i++) {
		struct ListNode* curr = stu->head;
		for (int j = 0; j < stu->studentSize - i - 1; j++) {
			if (curr->totalscore < curr->next->totalscore) {
				// 交换节点数据
				struct ListNode temp = *curr;
				*curr = *(curr->next);
				*(curr->next) = temp;
				// 修正指针关系
				struct ListNode* nextNode = curr->next;
				curr->next = nextNode->next;
				nextNode->next = curr;
				// 更新头指针和尾指针
				if (j == 0) {
					stu->head = nextNode;
				}
				if (j == stu->studentSize - i - 2) {
					stu->tail = curr;
				}
			} else {
				curr = curr->next;
			}
		}
	}
	printf("已根据成绩进行排序（降序）\n");
	system("pause");
}