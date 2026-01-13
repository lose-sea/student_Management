#define _CRT_SECURE_NO_WARNINGS 

#include"student.h" 

// 更新学生信息
void updateStudent(struct student* stu) {
    system("cls");
    printf("请输入你要更新的学生姓名: ");
    char name[300];
    fgets(name, 300, stdin);
    removeNewline(name);
    struct ListNode* curr = stu->head;
    while (curr != NULL) { 
        if (strcmp(name, curr->name) == 0) {
            break; 
        }
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("不存在学生 %s 的信息\n", name);
        system("pause");
        return;
    } else { 
        while (1) {
            printf("学号: %s\n", curr->id);
            printf("姓名: %s\n", curr->name);
            printf("性别: %s\n", curr->sex);
            printf("年龄: %d\n", curr->age);
            printf("电话: %s\n", curr->telephone);
            printf("专业: %s\n", curr->major);
            printf("高数成绩: %.2lf\n", curr->Math);
            printf("近代史成绩: %.2lf\n", curr->History);
            printf("英语成绩: %.2lf\n", curr->English);
            printf("成绩: %.2f\n", curr->totalscore);
            printf("年级: %s\n", curr->grade);
            printf("班级: %s\n\n", curr->class1);

            printf("请选择你要修改的信息: \n");
            printf("1. 学号\n");
            printf("2. 姓名\n");
            printf("3. 性别\n");
            printf("4. 年龄\n");
            printf("5. 联系方式: \n");
            printf("6. 专业\n"); 
			printf("7. 高数成绩\n");
			printf("8. 近代史成绩\n");
            printf("9. 英语成绩\n");
            printf("10. 总成绩\n");
            printf("11. 年级: \n");
            printf("12. 班级: \n");
            printf("0. 取消修改\n");
            int i = 0; 
            while (1) {
                int judgeInput = scanf("%d", &i); 
                clearInputBuffer(); 
                if (judgeInput != 1 || i < 0 || i > 12) {
                    printf("输入无效,请重新输入: "); 
                    Sleep(2000);
                    printf("\033[1A");    // 光标上移一行  
                    printf("\033[2K");    // 清除整行  
                    printf("\r");         // 回到行首  
                } else {
                    break;
                }
            }
            switch (i) {
            case 0: {
                printf("取消修改,返回主界面\n");
                system("pause");
                system("cls");
                return;
            }
            case 1: {
                printf("你要修改的是学号: \n");
                printf("请输入新的学号: ");
                char id[300];
                while (1) {
                    fgets(id, 300, stdin);
                    removeNewline(id);
                    if (findByid(stu, id) == -1 || strcmp(curr->id, id) == 0) {
                        break;
                    } else {
                        printf("已存在该学号, 请重新输入: ");
                        Sleep(2000);
                        printf("\033[1A");    // 光标上移一行  
                        printf("\033[2K");    // 清除整行  
                        printf("\r");         // 回到行首  
                    }
                }

                strcpy(curr->id, id);
                printf("修改成功, 已将学号修改为%s", id);
                system("pause");
                break;
            }
            case 2: {
                printf("你要修改的是姓名: \n");
                printf("请输入新的姓名: ");
                char name[300];
                fgets(name, 300, stdin);
                removeNewline(name);
                strcpy(curr->name, name);
                printf("已将姓名修改为 %s \n", name);
                system("pause");
                break;
            }
            case 3: {
                printf("你要修改的是性别: \n");
                printf("M: 男\t F: 女\n");
                printf("请选择新的性别 : ");
                char sex;
                while (1) {
                    sex = _getch(); 

                    if (sex == 'M' || sex == 'm') {
                        strcpy(curr->sex, "男");
                        break;
                    } else if (sex == 'F' || sex == 'f') {
                        strcpy(curr->sex, "女");
                        break;
                    } else {
                        printf("选择错误, 请重新选择\n"); 
                        Sleep(2000);
                        printf("\033[1A");    // 光标上移一行  
                        printf("\033[2K");    // 清除整行  
                        printf("\r");         // 回到行首  
                    }
                }
                printf("修改成功\n");
                system("pause");
                break;
            }
            case 4: {
                printf("你要修改的是年龄: \n");
                printf("请输入新的年龄: ");
                int age;
                while (1) {
                    int judgeAge = scanf("%d", &age);
                    clearInputBuffer();
                    if (judgeAge != 1 || age < 0) {
                        printf("输入错误,请重新输入\n"); 
                        Sleep(2000);
                        printf("\033[1A");    // 光标上移一行  
                        printf("\033[2K");    // 清除整行  
                        printf("\r");         // 回到行首  
                    } else {
                        curr->age = age;
                        break;
                    }
                }
                printf("已将年龄修改为 %d \n", age);
                system("pause");
                break;
            }
            case 5: {
                printf("你要修改的是联系方式: \n");
                printf("请输入新的联系方式: ");
                char telephone[100];
                fgets(telephone, 100, stdin);
                removeNewline(telephone);
                strcpy(stu[index].telephone, telephone);
                printf("已将联系方式修改为 %s \n", telephone);
                system("pause");
                break;
            }
            case 6: {
                printf("你要修改的是专业: \n");
                printf("请输入新的专业: ");
                char major[300];
                fgets(major, 300, stdin);
                removeNewline(major);
                strcpy(stu[index].major, major);
                printf("已将专业修改为 %s \n", major);
                system("pause");
                break;
            }
            case 7: {
                printf("你要修改的是成绩: \n");
                printf("请输入新的成绩: ");
                double score;
                while (1) {
                    int judgescore = scanf("%lf", &score);
                    clearInputBuffer();
                    if (judgescore != 1 || score < 0 || score > 100) {
                        printf("输入错误,请重新输入\n"); 
                        Sleep(2000);
                        printf("\033[1A");    // 光标上移一行  
                        printf("\033[2K");    // 清除整行  
                        printf("\r");         // 回到行首  
                    } else {
                        stu[index].score = score;
                        break;
                    }
                }
                printf("已将成绩修改为 %.2lf \n", score);
                system("pause");
                break;
            }
            case 8: {
                printf("你要修改的是年级: \n");
                printf("请输入新的年级: ");
                char grade[300];
                fgets(grade, 300, stdin);
                removeNewline(grade);
                strcat(grade, "级");
                strcpy(stu[index].grade, grade);
                printf("已将年级修改为 %s \n", stu[index].grade);
                system("pause");
                break;
            }
            case 9: {
                printf("你要修改的是班级: \n");
                printf("请输入新的班级: ");
                char class1[300];
                fgets(class1, 300, stdin);
                removeNewline(class1);
                strcat(class1, "班");
                strcpy(stu[index].class1, class1);
                printf("已将班级修改为 %s \n", stu[index].class1);
                system("pause");
                break;
            }
            }
            printf("当前学生信息: \n");
            printf("学号: %s\n", stu[index].id);
            printf("姓名: %s\n", stu[index].name);
            printf("性别: %s\n", stu[index].sex);
            printf("年龄: %d\n", stu[index].age);
            printf("联系方式: %s\n", stu[index].telephone);
            printf("专业: %s\n", stu[index].major);
            printf("成绩: %.2lf\n", stu[index].score);
            printf("年级: %s\n", stu[index].grade);
            printf("班级: %s\n", stu[index].class1);
            printf("是否选择继续修改\n");
            printf("****** 继续修改 Y  退出 N");
            char chose;
            while (1) {
                int judgeChose = scanf("%c", &chose);
                clearInputBuffer();
                if (judgeChose != 1) {
                    printf("输入无效,请重新输入\n"); 
                    Sleep(2000);
                    printf("\033[1A");    // 光标上移一行  
                    printf("\033[2K");    // 清除整行  
                    printf("\r");         // 回到行首  
                } else if (chose == 'N' || chose == 'n') {
                    printf("退出\n");
                    system("pause");
                    system("cls");
                    return;
                } else if (chose == 'Y' || chose == 'y') {
                    system("cls");
                    break;
                } else {
                    printf("输入无效,请重新输入\n"); 
                    Sleep(2000);
                    printf("\033[1A");    // 光标上移一行  
                    printf("\033[2K");    // 清除整行  
                    printf("\r");         // 回到行首  
                }
            }
        }
    }
}