#define _CRT_SECURE_NO_WARNINGS 
#include"student.h"
int main() {  
	struct student stu;   
	stu.head = NULL;  
	stu.tail = NULL;
	stu.studentSize = 0; 
	loadFromFile(&stu);  
	struct ListNode* curr = stu.head;  
	/*while (curr->next != NULL) {
		curr = curr->next;
	} 
	free(curr); 
	stu.studentSize--;*/

	displayAllStudent(&stu); 
	addStudent(&stu);  
	//deleteStudent(&stu); 
	saveToFile(&stu);
	return 0;
}