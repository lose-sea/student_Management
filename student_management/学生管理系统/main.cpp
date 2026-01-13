#define _CRT_SECURE_NO_WARNINGS 
#include"student.h" 
int main() {
	// printf("当前已在第一页\n");
    // Sleep(2000);
    // // 先回到行首，再清除整行
    // printf("\033[1A\r\033[K");
	// int i = 0;  
	// scanf("%d", &i); 

	// for (int i = 0; i < 10; ++i) {
	// 	printf("i: %d\n", i);
	// } 
	// struct student stu; 
	// displayAllStudent(&stu); 

	//int i = 0; 
	//printf("%d", ++i); 

	//printf("hello"); 
	//printf("\b"); 
	//int i = 0; 
	//scanf("%d", &i); 

	/*char grade[300]; 
	
	printf("      级\b\b\b\b\b\b\b\b\b\b\b\b\b\b"); 
	fgets(grade, 300, stdin);*/

	// 输入年级
	printf("请输入年级: (例如：25)\n");
	char grade[300];
	printf("       级\b\b\b\b\b\b\b\b\b\b");
	fgets(grade, 300, stdin);
	removeNewline(grade);
	strcat(grade, "级");
	printf("%s\n", grade);

	// 输入班级
	printf("请输入班级: (例如:计科2501\n");
	char class1[300];
	printf("         班\b\b\b\b\b\b\b\b\b\b\b\b");
	fgets(class1, 300, stdin);
	removeNewline(class1);
	strcat(class1, "班");
	printf("%s\n", class1); 

	return 0; 
}  