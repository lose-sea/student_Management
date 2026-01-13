#define _CRT_SECURE_NO_WARNINGS 
#include"common.h"

// 
// 辅助函数
// 去除fgets输入的字符串末尾的换行符
void removeNewline(char* str);

// 清除输入缓冲区
void clearInputBuffer();

// 检查输入是否合法
bool isValid(int judge); 

// 检查输入的字符串是否由纯数字组成
bool isDigit(char* str);

// 根据学号查找学生
int findByid(struct student* stu, char* id); 

// 通过姓名查找学生
int findByName(struct student* stu, char* name); 
  
 
 
// 显示菜单 
void displayMenu();

// 显示班级学生具体信息
void displayAllStudent(struct student* stu);

// 添加学生
void addStudent(); 

// 根据姓名查找学生信息
void searchStudentByName(struct student* stu, char* name);

// 更新学生信息
void updateStudent(struct student* stu); 


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