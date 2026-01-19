#pragma once
#include<stdio.h> 
#include<stdlib.h> 
#include<limits.h> 
#include<string.h> 
#include<stdbool.h> 
#include<windows.h> 
#include<ctype.h> 
#include<conio.h>
// #include<windows.h>


  

// 学生节点
typedef struct ListNode {
    char id[300];           // 学号
    char name[300];         // 姓名
    char sex[20];           // 性别
    int age;                // 年龄
    char telephone[100];    // 电话
    char major[300];        // 专业 
    double Math;         // 高数
	double History;          // 近代史
	double English;         // 英语
    double totalscore;           // 总成绩
    char grade[300];        // 年级
    char class1[300];       // 班级
    struct ListNode* next;  // 上一个节点
    struct ListNode* prev;  // 下一个节点 
}ListNode;


// 学生链表
typedef struct student {
    ListNode* head;     // 头节点 
	ListNode* tail;     // 尾节点
    int studentSize;    // 学生数量
}student;
