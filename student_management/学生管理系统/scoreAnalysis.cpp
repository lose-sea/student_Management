#define _CRT_SECURE_NO_WARNINGS 


#include"student.h" 
// 成绩分析
void scoreAnalysis(struct student* stu) {
	if (stu->head == NULL) {
		printf("当前无学生信息，无法进行成绩分析！\n"); 
		system("pause"); 
		return; 
	} 
	double Math_sum = 0.0;  
	double History_sum = 0.0;  
	double English_sum = 0.0;
	struct ListNode* curr = stu->head; 
	while (curr) {
		Math_sum += curr->Math; 
		History_sum += curr->History;  
		English_sum += curr->English;
		curr = curr->next; 
	} 
	double Math_avarage = Math_sum / stu->studentSize; 
	double History_avarage = History_sum / stu->studentSize;  
	double English_avarage = English_sum / stu->studentSize;
	printf("高数平均分: %.2lf\n", Math_avarage); 
	printf("近代史平均分: %.2lf\n", History_avarage);  
	printf("英语平均分: %.2lf\n", English_avarage);  

}