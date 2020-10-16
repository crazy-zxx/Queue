//
// Created by xylx on 2020/10/14.
//

#ifndef SQLIST_COMMONDEFINE_H
#define SQLIST_COMMONDEFINE_H


/* ----------- 常用返回值预定义 --------------*/
typedef int Status;
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
/*-----------------------------------------*/

//元素类型
typedef int QElemType;

/* ----------- 顺序队列（循环队列）结构定义 ---------------*/
#define MAXQSIZE 100
typedef struct sqQNode{
    QElemType *base;
    int front;
    int rear;
}SqQueue;
/*-----------------------------------------*/


/* ----------- 链队列结构定义 ---------------*/
//链表节点
typedef struct qNode {
    QElemType data;
    struct qNode *next;
}QNode, *Queue;
//链队列（头尾指针）
typedef struct lQNode{
    Queue front;
    Queue rear;
}LinkQueue;
/*-----------------------------------------*/



#endif //SQLIST_COMMONDEFINE_H
