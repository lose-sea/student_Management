#define _CRT_SECURE_NO_WARNINGS 
#include"student.h" 

void insertStudent(struct student* stu) {
    system("cls");
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (node == NULL) {
        printf("内存分配失败\n");
        Sleep(2000);
        return;
    } 
    node->next = NULL; 
    node->prev = NULL; 
    
    // 为新的节点输入信息  
    // 输入学号 
    printf("请输入要插入的学生信息: \n");
    char id[300];
    while (1) {
        printf("请输入学号: \n");
        fgets(id, 300, stdin);
        removeNewline(id);
        if (!isDigit(id)) {
            printf("学号应为纯数字, 请重新输入\n");
            Sleep(800);  
            system("cls");
            continue; 
        } else if (strlen(id) == 0) {
            printf("学号不能为空, 请重新输入\n");
            Sleep(800);
            system("cls");
            continue;
        }
        if (findByid(stu, id) != NULL) {
            printf("已经存在该学号的学生\n");
            system("cls"); 
            printf("是否重新输入： 是(Y) 否(N)\n");
            char selection = 0;
            while (1) {
                selection = _getch();
                if (selection == 'Y' || selection == 'y') {
                    break;
                } else if (selection == 'N' || selection == 'n') { 
                    free(node);  
                    node = NULL; 
                    printf("退出\n");  
                    system("pause");
                    return;
                } else {
                    printf("选择错误, 请重新选择\n");
                    Sleep(800);
                    system("cls");
                    continue;
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
    while (1) {
        fgets(name, 300, stdin);
        removeNewline(name);
        if (strlen(name) == 0) {
            printf("姓名不能为空, 请重新输入\n");
            Sleep(800);
            printf("\033[1A");    // 光标上移一行  
            printf("\033[2K");    // 清除整行   
            printf("\r"); 
            continue;
        }
        strcpy(node->name, name);
        break;
    }
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
    while (1) {
        fgets(telephone, 300, stdin);
        removeNewline(telephone);
        if (strlen(telephone) == 0) {
            printf("联系方式不能为空, 请重新输入\n");
            Sleep(800);
            printf("\033[1A");    // 光标上移一行  
            printf("\033[2K");    // 清除整行   
            printf("\r"); 
            continue;
        } else if (!isDigit(telephone)) {
            printf("联系方式应为纯数字, 请重新输入\n");
            Sleep(800);
            printf("\033[1A");    // 光标上移一行  
            printf("\033[2K");    // 清除整行  
            continue;
        } else {
            strcpy(node->telephone, telephone);
            break;
        }
    }

    // 输入专业
    printf("请输入专业: \n");
    char major[300];
    fgets(major, 300, stdin);
    removeNewline(major);
    strcpy(node->major, major);

    // 输入高数成绩 
    printf("请输入高数成绩: \n");
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


    // 显示当前学生列表
    struct ListNode* curr = stu->head;
    for (int i = 1; i <= stu->studentSize && curr != NULL; i++) {
        printf("序号:%d  ", i);
        printf("姓名:%s  学号:%s  性别: %s \n", curr->name, curr->id, curr->sex);
        curr = curr->next;
    }
    printf("请输入要插入的位置(1 到 %d): \n", stu->studentSize + 1); 
    int position;
    while (1) { 
        int judgePosition = scanf("%d", &position);
        clearInputBuffer();
        if (judgePosition != 1 || position < 1 || position > stu->studentSize + 1) {
            printf("输入无效, 请重新输入\n");
            Sleep(600);
            printf("\033[1A");    // 光标上移一行  
            printf("\033[2K");    // 清除整行  
        }
        else {
            // 插入节点
            if (position == 1) {   // 插入到头部
                node->next = stu->head;
                if (stu->head != NULL) {
                    stu->head->prev = node;
                } else {
                    stu->tail = node;  
                }
                stu->head = node;
            }
            else if (position == stu->studentSize + 1) { // 插入到尾部
                node->next = NULL;
                node->prev = stu->tail;
                if (stu->tail != NULL) {
                    stu->tail->next = node;
                } else {
                    stu->head = node;  
                }
                stu->tail = node;
            }
            else {  // 插入到中间
                struct ListNode* prevNode = stu->head; 
                for (int i = 1; i < position - 1; i++) {
                    prevNode = prevNode->next;
                }
                node->next = prevNode->next;
                node->prev = prevNode;
                prevNode->next->prev = node;
                prevNode->next = node;
            }
            
            // 更新学生数量
            stu->studentSize++;
            break;
        }
    }


    system("cls");
    printf("学生信息插入成功!\n"); 

    system("pause");
}