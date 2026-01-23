#define _CRT_SECURE_NO_WARNINGS 
#include"student.h"  

// 从文件中读取数据(二进制) 
void loadFromFile(struct student* stu) {  
	if (stu == NULL) {
		printf("当前暂无学生信息\n"); 
		system("pause"); 
		return; 
	}
	FILE* pf = fopen("student.bin", "rb");  
	if (pf == NULL) {
		printf("文件打开失败\n"); 
		system("pause"); 
		return; 
	} 
	// 文件打开成功 
	// 读取学生数量
	int count = 0; 
	if (fread(&count, sizeof(int), 1, pf) != 1) {
		printf("读取失败\n"); 
		fclose(pf); 
		pf = NULL; 
		return; 
	} else { 
		printf("共 %d 名学生\n", count);   
	}
	
	// 清空现有数据
	ListNode* curr = stu->head; 
	while (curr != NULL) {
		ListNode* temp = curr; 
		curr = curr->next; 
		free(temp); 
	} 
	stu->head = NULL;  
	stu->tail = NULL;
	stu->studentSize = count;  
	// 重建双向链表  
	for (int i = 1; i <= count; i++) {
		ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
		if (newNode == NULL) {
			printf("内存分配失败\n"); 
			break; 
		}    

		// 尾插   
		newNode->next = NULL;
		newNode->prev = stu->tail;
		if (stu->head == NULL) {
			stu->head = newNode; 
			stu->tail = newNode; 
		} else {
			stu->tail->next = newNode;
			stu->tail = newNode;
		}
		
		// 读取数据  
		fread(newNode->id, sizeof(char), 300, pf);
		fread(newNode->name, sizeof(char), 300, pf);
		fread(newNode->sex, sizeof(char), 20, pf);
		fread(&newNode->age, sizeof(int), 1, pf);
		fread(newNode->telephone, sizeof(char), 100, pf);
		fread(newNode->major, sizeof(char), 300, pf);
		fread(&newNode->Math, sizeof(double), 1, pf);
		fread(&newNode->History, sizeof(double), 1, pf);
		fread(&newNode->English, sizeof(double), 1, pf);
		fread(&newNode->totalscore, sizeof(double), 1, pf);
		fread(newNode->grade, sizeof(char), 300, pf);
		fread(newNode->class1, sizeof(char), 300, pf);

		// 显示进度
		printf("正在读取第 %d/%d 个学生: %s\n", i, stu->studentSize, newNode->name);
		Sleep(2);  
		// 上移一行
		printf("\033[1A");
		// 清除当前行
		printf("\033[2K"); 
		printf("\r"); 
	} 
	fclose(pf); 
	printf("成功加载 %d 名学生信息\n", stu->studentSize);  
	system("pause"); 
}
