#define _CRT_SECURE_NO_WARNINGS 


#include"student.h"

// 成绩分析
void scoreAnalysis(struct student* stu) {
	if (stu == NULL) {
		printf("暂无学生信息\n");
		system("pause");
		return;
	}
	if (stu->studentSize == 0) {
		printf("暂无学生信息\n");
		system("pause");
		return;
	}
	double totalMath = 0.0;
	double totalHistory = 0.0;
	double totalEnglish = 0.0;
	struct ListNode* curr = stu->head;
	while (curr != NULL) {
		totalMath += curr->Math;
		totalHistory += curr->History;
		totalEnglish += curr->English;
		curr = curr->next;
	}
	double avgMath = totalMath / stu->studentSize;
	double avgHistory = totalHistory / stu->studentSize;
	double avgEnglish = totalEnglish / stu->studentSize;
	printf("成绩分析结果:\n");
	printf("高数平均分: %.2lf\n", avgMath);
	printf("近代史平均分: %.2lf\n", avgHistory);
	printf("英语平均分: %.2lf\n", avgEnglish);
	system("pause");
}