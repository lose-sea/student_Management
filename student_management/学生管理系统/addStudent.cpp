#include"student.h" 

// 添加学生信息 (头插)
void addStudent(struct student* stu) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));  
    if (stu->head == NULL) {        // 将新的节点插入到正确位置
        stu->head = node; 
    } else { 
        node->next = stu->head->next; 
        node->prev = stu->head; 
        stu->head->next = node; 
    } 
    // 为新的节点输入信息 
    // 输入学号
    char id[30]; 
    printf("请输入学号: \n"); 
    fgets(id, 300, stdin);  
    removeNewline(id); 
    if (findByid(id) != -1) {
        printf("已经存在该学号的学生\n"); 
        system("pause"); 
        return; 
    } else {
        strcpy(node->id, id);
    }

    // 输入姓名
    char name[300]; 
    printf("请输入姓名: \n"); 
    fgets(name, 300, stdin); 
    removeNewline(name); 
    strcpy(node->name, name); 

    // 选择性别
    char sex = 0; 
    printf("请选择性别: \n"); 
    printf("M: 男\t F: 女\n");  
    while (1) {
        scanf("%c", &sex); 

        clearInputBuffer(); 

        if (sex == 'M' || sex == 'm') {
            strcpy(node->sex, "男");  
            break; 
        } else if (sex == 'F' || sex == 'f') {
            strcpy(node->sex, "女"); 
            break; 
        } else {
            printf("选择错误, 请重新选择\n"); 
        }
    }  

    // 输入年龄
    int age; 
    printf("请输入年龄: \n");  
    while (1) { 
        int judgeAge = scanf("%d", &age);  
        clearInputBuffer();  
        if (judgeAge != 1 || age < 0 || age > 150) { 
            printf("输入无效,请重新输入\n");  
        } else { 
            node->age = age;  
            break;  
        } 
    }  

    // 输入联系方式
    printf("请输入联系方式: \n"); 
    char telephone[100]; 
    fgets(telephone, 100, stdin); 
    removeNewline(telephone); 
    strcpy(node->telephone, telephone); 
}