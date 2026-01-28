#define _CRT_SECURE_NO_WARNINGS 
#include"common.h"


// 辅助函数
// 
// 去除fgets输入的字符串末尾的换行符
void removeNewline(char* str);

// 清除输入缓冲区
void clearInputBuffer();

// 检查输入的字符串是否由纯数字组成
bool isDigit(char* str); 

// 判断输入的字符串是否有数字或英文字符组成
bool isAlphanumeric(char* str); 

// 根据学号查找学生
struct ListNode* findByid(struct student* stu, char* id); 

// 通过姓名查找学生
int findByName(struct student* stu, char* name);   

// 清空链表
void clearList(struct student* stu);  

// 根据账号查找学生
struct ListNode* findStudentByAccount(struct student* stu, char* account);  

//根据账号查找教师
struct teacher* findTeacherByAccount(struct teacher* teacher, char* account); 

// 根据账号查找管理员
struct manager* findAdministratorByAccount(struct manager* administrator, char* account); 
  
 
// 显示初始界面
void displayInitialInterfal(); 

// 显示登录菜单
void displayMenuOfLogin();  

// 登录
void login(); 

// 注册账号
void createAccount(); 

// 显示菜单(管理员端)
void displayMenuOfAdministrator();  

// 显示菜单(教师端) 
void displayMenuOfTeacther(); 

// 显示菜单(学生端) 
void displayOfStudent();  

// 找回密码 
void retrievePassword(); 

// 显示班级学生具体信息 
void  displayAllStudent(struct student* stu); 

// 添加学生信息 (头插)
void addStudent(struct student* stu); 

// 根据姓名查找学生信息
void searchStudentByName(struct student* stu, char* name); 

// 显示学生成绩列表
void displayStudenScoretList(struct student* stu);

// 更新学生信息
void updateStudent(struct student* stu);  

// 插入学生信息
void insertStudent(struct student* stu);  

// 删除尾部学生记录
void deleteTailStudent(struct student* stu);  

// 根据高数成绩排序(降序)
void sortByMathScore(struct student* stu); 

// 根据近代史成绩排序(降序) 
void sortByHistoryScore(struct student* stu);  

// 根据英语成绩排序(降序) 
void sortByEnglishScore(struct student* stu);

// 根据成绩总分排序(降序)
void sortByTotalScore(struct student* stu); 

// 删除学生信息
void deleteStudent(struct student* stu);  

// 成绩分析
void scoreAnalysis(struct student* stu); 

//将学生信息保存到文件(二进制) 
void saveToFile(); 

// 从文件中读取学生信息
void loadFromFile();