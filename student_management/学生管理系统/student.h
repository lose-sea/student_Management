#define _CRT_SECURE_NO_WARNINGS 
#include"common.h"





// 去除fgets输入的字符串末尾的换行符
void removeNewline(char* str);

// 清除输入缓冲区
void clearInputBuffer();

// 检查输入是否合法
bool isValid(int judge); 

// 检查输入的字符串是否由纯数字组成
bool isDigit(char* str);

// 根据学号检查学生是否已经存在
int findByid(char* id);

//// 根据姓名判断学生是否存在
//int findStudentByname(char* name);

//// 根据成绩进行排序的比较函数  
//int cmp(const void* e1, const void* e2); 
  
 
 
// 显示菜单 
void displayMenu();

// 显示学生列表
void displayAllStudent(struct student* stu);

//// 添加学生
//void addStudent();
//
//// 根据姓名查找学生信息
//void searchStudentByname();
//
//// 更新学生信息
//void updateStudent();
//
//// 根据成绩排序
//void sortByScore();
//
//// 删除学生信息
//void deleteStudent();
//
//// 将学生信息保存到文件
//void saveToFile();
//
//// 从文件中读取学生信息
//void loadFromFile();