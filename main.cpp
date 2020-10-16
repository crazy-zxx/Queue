#include <stdio.h>
#include <stdlib.h>
#include "commonDefine.h"

/*--------------------------------- 顺序队列的数组实现 ---------------------------------*/
//简易实现
void function() {
    //顺序队列定义及初始化
    QElemType queue[MAXQSIZE];
    int front = 0;
    int rear = 0;

    //判空
    if (front == rear) {       //空

    }

    QElemType e = 10;
    //入队
    queue[rear++] = e;

    //出队
    e = queue[front++];

    //取队头
    e = queue[front];
}
/*-------------------------------------------------------------------------------------*/

/*--------------------------------- 循环（顺序）队列的实现 ---------------------------------*/
/*-------------- 队列的初始化 ----------------*/
Status InitQueue(SqQueue &Q) {
    Q.base = (QElemType *) malloc(sizeof(QElemType) * MAXQSIZE);
    if (!Q.base){
        exit(OVERFLOW);
    }
    Q.front = Q.rear = 0;

    return OK;
}

/*-------------- 入队 ----------------*/
Status EnQueue(SqQueue &Q,QElemType e){
    if ((Q.rear+1)%MAXQSIZE==Q.front){
        return ERROR;
    }
    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%MAXQSIZE;

    return OK;
}

/*-------------- 出队 ----------------*/
Status DeQueue(SqQueue &Q,QElemType &e){
    if (Q.front==Q.rear){
        return ERROR;
    }
    e=Q.base[Q.front];
    Q.front=(Q.front+1)%MAXQSIZE;

    return OK;
}

/*-------------- 获取队头 ----------------*/
Status GetHead(SqQueue &Q,QElemType &e){
    if (Q.front==Q.rear){
        return ERROR;
    }
    e=Q.base[Q.front];

    return OK;
}

/*-------------- 队空判断 ----------------*/
Status QueueEmpty(SqQueue Q){
    if (Q.front==Q.rear){
        return TRUE;
    } else{
        return FALSE;
    }
}

/*-------------- 队列长度 ----------------*/
int QueueLength(SqQueue Q){
    return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}

/*-------------- 清空队列 ----------------*/
Status CleanQueue(SqQueue &Q){
    Q.front=Q.rear=0;

    return OK;
}

/*-------------- 销毁队列 ----------------*/
Status DestroyQueue(SqQueue &Q){
    free(Q.base);
    Q.base=NULL;
    Q.front=Q.rear=0;

    return OK;
}

/*-------------- 打印队列 ----------------*/
void printQueue(SqQueue Q){
    if (Q.front==Q.rear){
        printf("空队列\n");
        return;
    }
    while (Q.front!=Q.rear){
        printf("%d ",Q.base[Q.front]);
        Q.front=(Q.front+1)%MAXQSIZE;
    }
    printf("\n");
}
/*-------------------------------------------------------------------------------------*/

/*-------------------------------------- 链队列的实现 -----------------------------------*/
//链队列，front始终指向链表头结点，rear指向队尾。入队尾插，出队删除首元素.
/*-------------- 队列的初始化 ----------------*/
Status InitQueue(LinkQueue &Q) {
    Q.front=Q.rear = (Queue) malloc(sizeof(QNode));     //头结点
    if (!Q.front){
        exit(OVERFLOW);
    }
    Q.front->next=NULL;

    return OK;
}
/*-------------- 入队 ----------------*/
Status EnQueue(LinkQueue &Q,QElemType e){

    Queue t=(Queue)malloc(sizeof(QNode));
    if (!t){
        exit(OVERFLOW);
    }
    t->data=e;
    t->next=NULL;
    Q.rear->next=t;
    Q.rear=t;

    return OK;
}

/*-------------- 出队 ----------------*/
Status DeQueue(LinkQueue &Q,QElemType &e){
    if (Q.front==Q.rear){   //队空判断
        return ERROR;
    }
    Queue t=Q.front->next;
    e=t->data;
    Q.front->next=t->next;
    if (Q.rear==t){         //如果删除的是队尾节点，则队列空，需要将队尾指针和对头指针指向一起（即头结点）
        Q.rear=Q.front;
    }
    free(t);

    return OK;
}

/*-------------- 获取队头 ----------------*/
Status GetHead(LinkQueue &Q,QElemType &e){
    if (Q.front==Q.rear){   //队空判断
        return ERROR;
    }
    e=Q.front->next->data;

    return OK;
}

/*-------------- 队空判断 ----------------*/
Status QueueEmpty(LinkQueue Q){
    if (Q.front==Q.rear){
        return TRUE;
    } else{
        return FALSE;
    }
}

/*-------------- 队列长度 ----------------*/
int QueueLength(LinkQueue Q){
    if (Q.front==Q.rear){
        return 0;
    }
    int count=0;
    Queue t=Q.front->next;
    while (t){
        count++;
        t=t->next;
    }
    return count;
}

/*-------------- 销毁队列 ----------------*/
Status DestroyQueue(LinkQueue &Q){
    while (Q.front){
        Q.rear=Q.front->next;
        free(Q.front);
        Q.front=Q.rear;
    }

    return OK;
}

/*-------------- 打印队列 ----------------*/
void printQueue(LinkQueue Q){
    if (Q.front==Q.rear){
        printf("空队列\n");
        return;
    }
    Queue t=Q.front->next;
    while (t){
        printf("%d ",t->data);
        t=t->next;
    }
    printf("\n");
}
/*-------------------------------------------------------------------------------------*/

int main() {

//    SqQueue Q1;
//    InitQueue(Q1);
//    printQueue(Q1);
//    EnQueue(Q1,10);
//    QElemType e=100;
//    EnQueue(Q1,e);
//    printQueue(Q1);
//    DeQueue(Q1,e);
//    printQueue(Q1);
//    printf("empty:%d\n",QueueEmpty(Q1));
//    printf("length:%d\n",QueueLength(Q1));
//    CleanQueue(Q1);
//    printf("empty:%d\n",QueueEmpty(Q1));
//    printf("length:%d\n",QueueLength(Q1));
//    DestroyQueue(Q1);

    LinkQueue Q1;
    InitQueue(Q1);
    printQueue(Q1);
    EnQueue(Q1,10);
    QElemType e=100;
    EnQueue(Q1,e);
    printQueue(Q1);
    DeQueue(Q1,e);
    printQueue(Q1);
    printf("empty:%d\n",QueueEmpty(Q1));
    printf("length:%d\n",QueueLength(Q1));

    DestroyQueue(Q1);
    printf("empty:%d\n",QueueEmpty(Q1));
    printf("length:%d\n",QueueLength(Q1));

    return 0;
}
