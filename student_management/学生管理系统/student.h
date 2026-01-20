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

// 清空链表
void clearList(struct student* stu); 
  
 
 
// 显示菜单 
void displayMenu();

// 显示班级学生具体信息 
void  displayAllStudent(struct student* stu); 

// 添加学生信息 (头插)
void addStudent(struct student* stu); 

// 根据姓名查找学生信息
void searchStudentByName(struct student* stu, char* name); 

// 显示学生成绩列表
void displayStudentList(struct student* stu); 

// 更新学生信息
void updateStudent(struct student* stu);  

// 插入学生信息
void insertStudent(struct student* stu);  

// 删除尾部学生记录
void deleteTailStudent(struct student* stu); 

// 根据成绩总分排序(降序)
void sortByScore(struct student* stu);

// 删除学生信息
void deleteStudent(struct student* stu); 

//将学生信息保存到文件(二进制) 
void saveToFile(struct student* stu); 

// 从文件中读取学生信息
void loadFromFile(struct student* stu);