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
       
    teach = (struct teacher*)malloc(sizeof(struct teacher)); 
    manage = (struct manager*)malloc(sizeof(struct manager)); 

    loadFromFile(); 
	displayAllStudent(stu); 
    FILE* pf = fopen("studentAccount.bin", "w"); 
    fclose(pf); 
    pf = NULL; 
    updateStudent(stu); 
    saveToFile(); 
    return 0; 
}   
