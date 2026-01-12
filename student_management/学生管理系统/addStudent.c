#include"student.h" 

// 添加学生信息 (头插)
void addStudent(struct student* stu) {
    struct ListNode* node = (struct student*)malloc(sizeof(struct student));  
    if (stu->head == NULL) {        // 将新的节点插入到正确位置
        stu->head = node; 
    } else { 
        node->next = stu->head->next; 
        node->prev = stu->head; 
        stu->head->next = node; 
    } 
    // 为新的节点输入信息 
    // 
}