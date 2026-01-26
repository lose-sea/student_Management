#define _CRT_SECURE_NO_WARNINGS 
#include"student.h"   

struct student* stu = NULL; 
struct teacher* teach = NULL;  
struct manager* manage = NULL; 
int main() {   

    stu = (struct student*)malloc(sizeof(struct student));
    stu->head = NULL;
    stu->tail = NULL;
    stu->studentSize = 0;
       
    teach = NULL;  // 链表头指针初始化为 NULL
    manage = NULL;  // 链表头指针初始化为 NULL 

    loadFromFile(); 
	displayAllStudent(stu);     
    FILE* pf = fopen("studentAccount.bin", "w"); 
    fclose(pf); 
    pf = NULL;  
    addStudent(stu);    
    saveToFile(); 
    return 0; 
}   
