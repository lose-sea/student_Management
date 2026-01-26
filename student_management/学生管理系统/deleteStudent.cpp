#define _CRT_SECURE_NO_WARNINGS 


#include"student.h" 


// 删除学生
void deleteStudent(struct student* stu) {
	system("cls");
	if (stu->studentSize == 0) {
		printf("当前暂无学生信息\n");
		system("pause");
		return;
	}
	printf("请输入你要删除的学生姓名: \n");
	char name[300]; 
	 while (1) {
		fgets(name, 300, stdin);
		removeNewline(name); 
		if (strlen(name) == 0) {
			printf("姓名不能为空，请重新输入: \n");
			Sleep(800);
			printf("\033[1A");    // 光标上移一行  
			printf("\033[2K");    // 清除整行  
		} else {
			break;
		}
	} 
	printf("请输入你要删除的学生学号: \n");
	char id[300]; 
	 while (1) {
		fgets(id, 300, stdin);
		removeNewline(id); 
		if (strlen(id) == 0) {
			printf("学号不能为空，请重新输入: \n");
			Sleep(800);
			printf("\033[1A");    // 光标上移一行  
			printf("\033[2K");    // 清除整行  
		} else {
			break;
		}
	} 
	struct ListNode* curr = stu->head; 
	while (curr != NULL) { 
		if (strcmp(name, curr->name) == 0 && strcmp(id, curr->id) == 0) {
			break; 
		}  
		curr = curr->next;
	}  
	if (curr == NULL) {
		printf("不存在学生 %s (学号: %s) 的信息\n", name, id); 
		system("pause");
		return;
	} else {  
		printf("是否确认删除 %s (学号: %s)的信息? (是(Y)/否(N))", curr->name, curr->id);   
		char selection = '\0'; 
		while (1) {
			selection = _getch(); 
			if (selection == 'Y' || selection == 'y') {
				break;
			} else if (selection == 'N' || selection == 'n') {
				printf("已取消删除操作\n");
				system("pause");
				return;
			} else {
				printf("无效输入，请输入 Y 或 N\n"); 
				Sleep(800);
				printf("\033[1A");    // 光标上移一行  
				printf("\033[2K");    // 清除整行  
			}
		}
		struct ListNode* prev = curr->prev;  
		if (prev == NULL) {
			stu->head = curr->next;
			if (stu->head != NULL) {
				stu->head->prev = NULL;
			}
		} else {
			prev->next = curr->next; 
			if (curr->next != NULL) {
				curr->next->prev = prev; 
			} else {
				stu->tail = prev; 
			}
		}
		free(curr); 
		stu->studentSize--;		// 删除成功，学生数量减一
		printf("已成功删除学生 %s (学号: %s) 的信息\n", name, id); 
		system("pause");
		return;
	}
} 
