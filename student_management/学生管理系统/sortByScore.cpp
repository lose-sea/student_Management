#define _CRT_SECURE_NO_WARNINGS 

#include"student.h" 

//根据成绩总分进行排序(降序) 
void sortByScore(struct student* stu) {
	if (stu->studentSize <= 1) {
		return; // 学生数量小于等于1，无需排序
	}
	// 使用冒泡排序对链表进行排序 
	for (int i = 0; i < stu->studentSize - 1; i++) {  
		struct ListNode* prev = stu->head;
		for (int j = 0; j < stu->studentSize - i - 1; j++) { 
			struct ListNode* curr = prev;
			struct ListNode* nextNode = curr->next;
			if (curr->totalscore < nextNode->totalscore) {  
				if (curr == stu->head && nextNode == stu->tail) {
					stu->head = nextNode; 
					stu->tail = curr;  
					curr->next = NULL;
					nextNode->prev = NULL;  
					curr->prev = nextNode; 
					nextNode->next = curr; 
				} else if (curr == stu->head) {
					stu->head = nextNode;  
					curr->next = nextNode->next; 
					nextNode->next->prev = curr;  
					nextNode->next = curr; 
					curr->prev = nextNode;  
					nextNode->prev = NULL;  
				} else if (nextNode == stu->tail) {
					stu->tail = curr;  
					curr->next = NULL; 
					curr->prev->next = nextNode; 
					nextNode->prev = curr->prev; 
					nextNode->next = curr; 
					curr->prev = nextNode; 
				} else {
					curr->next = nextNode->next;
					curr->prev->next = nextNode;
					curr->next->prev = curr;
					nextNode->prev = curr->prev;
					curr->prev = nextNode;
					nextNode->next = curr;
				}
			} 
			prev = prev->next;
		} 
	}
	printf("已根据成绩进行排序（降序）\n");
	system("pause");
}