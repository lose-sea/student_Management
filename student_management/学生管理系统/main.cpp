
#include"student.h" 
int main() { 
    struct student stu; 
    stu.head = NULL; 
    stu.tail = NULL; 
    stu.studentSize = 0; 
    
    loadFromFile(&stu);   
    //displayStudentList(&stu);
    
    displayAllStudent(&stu);  
    addStudent(&stu);
    saveToFile(&stu);
    return 0; 
}