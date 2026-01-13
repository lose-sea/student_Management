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
    char id[300]; 
    printf("请输入学号: \n"); 
    fgets(id, 300, stdin);  
    removeNewline(id); 
    if (findByid(stu, id) != -1) {
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
    char telephone[300]; 
    fgets(telephone, 300, stdin); 
    removeNewline(telephone); 
    strcpy(node->telephone, telephone); 

    // 输入专业
    printf("请输入专业: \n");  
    char major[300]; 
    fgets(major, 300, stdin); 
    removeNewline(major);  
    strcpy(node->major, major); 

    // 输入成绩 
    printf("请输入成绩: \n"); 
    double score;
    while (1) {
        int judgeScore = scanf("%lf", &score); 
        clearInputBuffer(); 
        if (judgeScore != 1 || score < 0 || score > 100) {
            printf("输入错误, 请重新输入: "); 
        } else {
            node->score = score;  
            break;  
        } 
    }  

    // 输入年级
    printf("请输入年级: \n");  
    char grade[300];
    fgets(grade, 62, stdin);  
    removeNewline(grade);   
    strcat(grade, "级"); 
    strcpy(node->grade, grade); 

    // 输入班级
    printf("请输入班级: \n"); 
    char class1[300]; 
    fgets(class1, 60, stdin); 
    removeNewline(class1); 
    strcat(class1, "班"); 
    strcpy(node->class1, class1);  

    // 添加之后人数加一
    stu->studentSize++; 
    system("pause"); 
}