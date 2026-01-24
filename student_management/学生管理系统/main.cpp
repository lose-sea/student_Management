#define _CRT_SECURE_NO_WARNINGS 
#include"student.h"   

struct student stu;
int main() { 
    loadFromFile(&stu); 
	displayAllStudent(&stu); 
    FILE* pf = fopen("studentAccount.bin", "w"); 
    fclose(pf); 
    pf = NULL; 
    updateStudent(&stu); 
    saveToFile(&stu); 
    return 0; 
}   
