#define _CRT_SECURE_NO_WARNINGS 
#include"student.h"  

// 从文件中读取数据(二进制) 
void readFromFile(struct student* stu) {
	FILE* pf = fopen("student.bin", "rb");  
	if (pf == NULL) {
		printf("文件打开失败\n"); 
		system("pause"); 
		return; 
	} 
	// 文件打开成功 
	// 重建双向链表
	struct student* student = (struct student*)malloc(sizeof(struct student)); 
	if (student == NULL) {
		printf("读取失败\n"); 
		system("pause");  
		return; 
	} 

}