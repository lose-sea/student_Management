#include"student.h" 

// 添加学生信息 (尾插)
void addStudent(struct student* stu) { 
	system("cls");
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));  
    if (node == NULL) {
        printf("内存分配失败\n"); 
        Sleep(2000);
        return; 
    }
    if (stu->head == NULL) {        // 将新的节点插入到正确位置
        stu->head = node;  
		stu->tail = node;
        node->prev = NULL; 
        node->next = NULL; 
    } else { 
        node->next = NULL; 
        node->prev = stu->tail; 
        stu->tail = node; 
    } 
    // 为新的节点输入信息 
    // 输入学号
    char id[300];  
    while (1) {
        printf("请输入学号: \n"); 
        fgets(id, 300, stdin);
        removeNewline(id); 
        if (!isDigit(id)) {
            printf("学号应为纯数字, 请重新输入\n");
            Sleep(800);  
            printf("\033[1A");    // 光标上移一行  
            printf("\033[2K");    // 清除整行  
            continue; 
		}
        if (findByid(stu, id) != -1) {
            printf("已经存在该学号的学生\n");
            Sleep(2000);  
            printf("\033[1A");    // 光标上移一行  
            printf("\033[2K");    // 清除整行  
            system("pause");
            printf("是否重新输入： 是(Y) 否(N)\n");
            int selection = 0;
            while (1) {
                int judgeselection = scanf("%d", &selection);
                clearInputBuffer();
                if (judgeselection != 1 || selection != 'Y' || selection != 'y' || selection != 'N' || selection != 'n') {
                    printf("选择错误, 请重新选择\n");
                    Sleep(2000);
                    printf("\033[1A");    // 光标上移一行  
                    printf("\033[2K");    // 清除整行  
                } else if (selection == 'Y' || 'y') {
                    break;
                } else if (selection == 'N' || selection == 'n') {
                    printf("退出\n");
                    system("pause");
                    return;
                } 
            }
        } else {
            strcpy(node->id, id); 
            break; 
        }
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
        sex = _getch(); 
        if (sex == 'M' || sex == 'm') { 
            printf("男\n"); 
            strcpy(node->sex, "男");  
            break; 
        } else if (sex == 'F' || sex == 'f') { 
            printf("女\n"); 
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

    // 输入高数成绩 
    printf("请输入语文成绩: \n"); 
    double Math;
    while (1) {
        int judgeScore = scanf("%lf", &Math); 
        clearInputBuffer(); 
        if (judgeScore != 1 || Math < 0 || Math > 100) {
            printf("输入错误, 请重新输入: \n"); 
           
        } else {
            node->Math = Math;  
            break;  
        } 
    }  

    // 输入近代史成绩 
    printf("请输入近代史成绩: \n");
    double History;
    while (1) {
        int judgeScore = scanf("%lf", &History);
        clearInputBuffer();
        if (judgeScore != 1 || History < 0 || History > 100) {
            printf("输入错误, 请重新输入: \n"); 
           
        } else {
            node->History = History;
            break;
        }
    }

    // 输入英语成绩 
    printf("请输入英语成绩: \n");
    double English;
    while (1) {
        int judgeScore = scanf("%lf", &English);
        clearInputBuffer();
        if (judgeScore != 1 || English < 0 || English > 100) {
            printf("输入错误, 请重新输入: \n"); 
            
        } else {
            node->English = English;
            break;
        }
    } 

	// 计算总成绩
	node->totalscore = node->Math + node->History + node->English;

    // 输入年级
    printf("请输入年级: \n");  
    char grade[300];
    printf("       级\b\b\b\b\b\b\b\b\b\b");
    fgets(grade, 300, stdin);
    removeNewline(grade);   
    strcat(grade, "级"); 
    strcpy(node->grade, grade); 

    // 输入班级
    printf("请输入班级: \n"); 
    char class1[300];  
    printf("         班\b\b\b\b\b\b\b\b\b\b\b\b");
    fgets(class1, 300, stdin);
    removeNewline(class1); 
    strcat(class1, "班"); 
    strcpy(node->class1, class1);  


    system("cls"); 
	printf("学生信息添加成功!\n"); 

    // 添加之后人数加一
    stu->studentSize++; 
    system("pause"); 
}