#define _CRT_SECURE_NO_WARNINGS 


#include"student.h" 

// //将学生信息保存到文件(二进制) 
// void saveToFile() { 
// 	if (stu == NULL) {
// 		printf("当前暂无学生信息\n"); 
// 		system("pause"); 
// 		return; 
// 	}  
// 	if (stu->studentSize == 0) {
// 		printf("当前暂无学生信息\n"); 
// 		system("pause"); 
// 		return; 
// 	}
// 	FILE* pf = fopen("student.bin", "wb"); 
// 	if (pf == NULL) {
// 		printf("文件打开失败\n"); 
// 		system("pause"); 
// 		return; 
// 	} 
// 	// 文件打开成功  
// 	// 先将学生人数写入文件开头
// 	int writeCount = fwrite(&stu->studentSize, sizeof(int), 1, pf);  
// 	if (writeCount != 1) {
// 		printf("保存失败"); 
// 	} 
// 	// // 遍历链表写入每个节点数据 
// 	ListNode* curr = stu->head;
// 	while (curr != NULL) {
// 		// 只保存数据部分，不保存 next 和 prev 指针
// 		fwrite(curr->id, sizeof(char), 300, pf);
// 		fwrite(curr->name, sizeof(char), 300, pf);
// 		fwrite(curr->sex, sizeof(char), 20, pf);
// 		fwrite(&curr->age, sizeof(int), 1, pf);
// 		fwrite(curr->telephone, sizeof(char), 100, pf);
// 		fwrite(curr->major, sizeof(char), 300, pf);
// 		fwrite(&curr->Math, sizeof(double), 1, pf);
// 		fwrite(&curr->History, sizeof(double), 1, pf);
// 		fwrite(&curr->English, sizeof(double), 1, pf);
// 		fwrite(&curr->totalscore, sizeof(double), 1, pf);
// 		fwrite(curr->grade, sizeof(char), 300, pf);
// 		fwrite(curr->class1, sizeof(char), 300, pf);
// 		curr = curr->next;
// 	}  

// 	fclose(pf);  
// 	pf = NULL;
// 	printf("保存成功\n"); 
// 	system("pause"); 
// }


//将学生信息保存到文件(二进制) 
void saveToFile() { 
	if (stu == NULL) {
		printf("当前暂无学生信息\n"); 
		system("pause"); 
		return; 
	}  
	if (stu->studentSize == 0) {
		printf("当前暂无学生信息\n"); 
		system("pause"); 
		return; 
	}
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
		printf("保存失败"); 
	} 
	// // 遍历链表写入每个节点数据 
	ListNode* curr = stu->head;
	while (curr != NULL) {
		// 只保存数据部分，不保存 next 和 prev 指针
		fwrite(curr->id, sizeof(char), 300, pf);
		fwrite(curr->name, sizeof(char), 300, pf);
		fwrite(curr->sex, sizeof(char), 20, pf);
		fwrite(&curr->age, sizeof(int), 1, pf);
		fwrite(curr->telephone, sizeof(char), 100, pf);
		fwrite(curr->major, sizeof(char), 300, pf);
		fwrite(&curr->Math, sizeof(double), 1, pf);
		fwrite(&curr->History, sizeof(double), 1, pf);
		fwrite(&curr->English, sizeof(double), 1, pf);
		fwrite(&curr->totalscore, sizeof(double), 1, pf);
		fwrite(curr->grade, sizeof(char), 300, pf);
		fwrite(curr->class1, sizeof(char), 300, pf);
		curr = curr->next;
	}  

	fclose(pf);  
	pf = fopen("teacher.bin", "wb"); 
	if (pf == NULL) {
		printf("文件打开失败\n"); 
		system("pause"); 
		return; 
	}  
	while (teach != NULL) {
		fwrite(teach->account, sizeof(char), 300, pf); 
		fwrite(teach->password, sizeof(char), 300, pf); 
		teach = teach->next;
	}  

	pf = fopen("administrator.bin", "wb"); 
	if (pf == NULL) {
		printf("文件打开失败\n"); 
		system("pause"); 
		return; 
	}  
	while (manage != NULL) {
		fwrite(manage->account, sizeof(char), 300, pf); 
		fwrite(manage->password, sizeof(char), 300, pf); 
		manage = manage->next;
	}  

	fclose(pf);  
	pf = NULL; 
	printf("保存成功\n"); 
	system("pause"); 
}
























////将学生信息保存到文件(二进制) 
//void saveToFile() {
//	if (stu == NULL) {
//		printf("当前暂无学生信息\n");
//		system("pause");
//		return;
//	}
//	if (stu->studentSize == 0) {
//		printf("当前暂无学生信息\n");
//		system("pause");
//		return;
//	}
//	FILE* pf = fopen("studentInformation.bin", "wb");
//	if (pf == NULL) {
//		printf("文件打开失败\n");
//		system("pause");
//		return;
//	}
//	// 文件打开成功  
//	// 先将学生人数写入文件开头
//	int writeCount = fwrite(&stu->studentSize, sizeof(int), 1, pf);
//	if (writeCount != 1) {
//		printf("保存失败");
//	}
//	// // 遍历链表写入每个节点数据 
//	ListNode* curr = stu->head;
//	//while (curr != NULL) {
//	//	// 只保存数据部分，不保存 next 和 prev 指针
//	//	fwrite(curr->id, sizeof(char), 300, pf);
//	//	fwrite(curr->name, sizeof(char), 300, pf);
//	//	fwrite(curr->sex, sizeof(char), 20, pf);
//	//	fwrite(&curr->age, sizeof(int), 1, pf);
//	//	fwrite(curr->telephone, sizeof(char), 100, pf);
//	//	fwrite(curr->major, sizeof(char), 300, pf);
//	//	fwrite(&curr->Math, sizeof(double), 1, pf);
//	//	fwrite(&curr->History, sizeof(double), 1, pf);
//	//	fwrite(&curr->English, sizeof(double), 1, pf);
//	//	fwrite(&curr->totalscore, sizeof(double), 1, pf);
//	//	fwrite(curr->grade, sizeof(char), 300, pf);
//	//	fwrite(curr->class1, sizeof(char), 300, pf);
//	//	curr = curr->next;
//	//} 
//
//	fwrite(curr, sizeof(struct ListNode), 1, pf); 
//
//	fclose(pf);
//	pf = NULL;
//	printf("加载成功\n");
//	system("pause");
//}