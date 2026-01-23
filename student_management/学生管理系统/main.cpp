#define _CRT_SECURE_NO_WARNINGS 
#include"student.h"   

struct student stu;
int main() { 
    
    
    loadFromFile(&stu);   
    //displayStudentList(&stu); 
    displayAllStudent(&stu);  
    addStudent(&stu);
    saveToFile(&stu);
    return 0; 
}   
