#define _CRT_SECURE_NO_WARNINGS 


#include"student.h" 

//将学生信息保存到文件(二进制) 
void loadToFile(struct student* stu) {
	FILE* pf = fopen("student.bin", "wb"); 
	if (pf == NULL) {
		printf("文件打开失败\n"); 
		system("pause"); 
		return; 
	} 
	// 文件打开成功  

	// 先将学生人数写入文件开头
	int writeCount = fwrite(&stu->studentSize, sizeof(int), 1, pf);
	if (writeCount != 1) { 
		printf("人数保存失败\n"); 
		fclose(pf);
		system("pause");
		return;
	}
	struct ListNode* curr = stu->head; 
	// 遍历链表写入每个节点数据
	while (curr != NULL) {
		int countNode = fwrite(curr, sizeof(ListNode), 1, pf);  
		if (countNode != 1) {
			printf("保存失败\n"); 
			system("pause"); 
			return; 
		} 
		curr = curr->next; 
	}  
	printf("已将数据保存到文件\n"); 
	system("pause"); 
	fclose(pf);  
	pf = NULL; 
}