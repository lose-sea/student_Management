#define _CRT_SECURE_NO_WARNINGS 


#include"student.h" 


// 删除账号 
void deleteAccount() {  
	start: 
	char selection = '\0'; 
	while (1) { 
		system("cls");
		printf("删除账号\n");
		printf("请选择你要删除的账号类型\n");
		printf("1.学生		2.教师		3.管理员	0.返回上一层\n");
		selection = _getch(); 
		if (selection != '1' && selection != '2' && selection != '3' && selection != '0') {
			printf("选择无效,请重新选择: \n"); 
		}   
		break; 
	}
	switch (selection) { 
		case'0': {
			return; 
		}
		case '1': {    
			struct ListNode* curr = stu->head; 
			char account[300]; 
			printf("请输入你要删除的学生账号: \n");
			fgets(account, 300, stdin);
			removeNewline(account);  
			curr = findStudentByAccount(stu, account); 
			if (curr == NULL) {
				printf("暂无该账号信息\n");  
				Sleep(600);  
				goto start; 
			} else if (curr == stu->head) {
				struct ListNode* next = curr->next;
				stu->head = next;
				next->prev = NULL;
				free(curr);
			} else if (curr == stu->tail) {
				struct ListNode* prev = curr->prev;
				prev->next = NULL;
				stu->tail = prev;
				free(curr);
			} else {
				struct ListNode* next = curr->next;
				struct ListNode* prev = curr->prev;
				prev->next = next;
				next->prev = prev;
				free(curr);
			}
		} 
		case '2': {
			struct teacher* curr = teach; 
			char account[300]; 
			printf("请输入你要删除的教师账号: \n"); 
			fgets(account, 300, stdin); 
			removeNewline(account);  
			curr = findTeacherByAccount(teach, account); 
			if (curr == NULL) {
				printf("暂无该账号信息\n");
				Sleep(600);
				goto start;
			} 
			struct teacher* dummy = (struct teacher*)malloc(sizeof(struct teacher)); 
			dummy->next = teach; 
			struct teacher* prev = dummy; 
			while (prev->next != curr) {
				prev = prev->next; 
			}
			prev->next = curr->next; 
			free(curr); 
		} 
		case '3': {
			struct manager* curr = manage;
			char account[300];
			printf("请输入你要删除的管理员账号: \n");
			fgets(account, 300, stdin);
			removeNewline(account);
			curr = findAdministratorByAccount(manage, account);
			if (curr == NULL) {
				printf("暂无该账号信息\n");
				Sleep(600);
				goto start;
			}
			struct manager* dummy = (struct manager*)malloc(sizeof(struct manager));
			dummy->next = manage;
			struct manager* prev = dummy;
			while (prev->next != curr) {
				prev = prev->next;
			}
			prev->next = curr->next;
			free(curr);
		}
	} 
	printf("删除成功\n");  
	system("pause"); 
}