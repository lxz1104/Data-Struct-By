//
// Created by longx on 2019/2/2.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

/**
 * 队列（Queue）是只允许在一端进行插入操作，而在另一端进行删除操作的顺序表
 * - 队列是一种先进先出的线性表
 * - 允许插入的一段称为队尾，允许删除的一端称为队头
 * 特点:
 * - 先进先出
 * - 后进后出
 * 注意:队列是操作受限的线性表
 *
 * 循环链表处理队空、队满的两种方法:
 * 1.少用一个空间元素，即队列空间大小为MAX_SIZE时，有MAX_SIZE-1个元素就认为是满队
 * 2.单独设置一个标识位以便区别队列是否为满状态或空状态
 *
 * 判断方法；
 * - 队列为空:rear == front == 0
 * - 队列已满:(rear + 1) % MAX_SIZE == front
 */

/**
 * 下面使用游标实现循环队列
 */

//队列最大长度
#define MAX_SIZE 256

typedef enum {
    False,True
}Bool;

/** 数据元素结构体 */
typedef struct {
    int id;
    char * name;
}ElementType;
/** 循环队列 */
typedef struct seqQueue{
    ElementType data[MAX_SIZE];
    //头指针
    int front;
    //尾指针
    int rear;
    //当前队列长度
    unsigned int length;
}SeqQueue;

/**
 * 初始化循环队列
 * @param queue 要操作的循环队列
 */
void InitSeqQueue(SeqQueue * queue);

/**
 * 判断队列是否为空
 * @param queue 要操作的循环队列
 * @return 队列为空，返回True；队列已满，返回False
 */
Bool IsEmpty(SeqQueue * queue);

/**
 * 判断队列是否已满
 * @param queue 要操作的循环队列
 * @return 队列为空，返回False；队列已满，返回True
 */
Bool IsFull(SeqQueue * queue);

/**
 * 入队
 * @param queue 要操作的循环队列
 * @param element 入队的元素
 * @return 入队成功，返回True；入队失败，返回False
 */
Bool OfferSeqQueue(SeqQueue * queue,ElementType element);

/**
 * 出队
 * @param queue 要操作的循环队列
 * @param element 要出队的元素指针
 * @return 出队成功，返回True；出队失败，返回False
 */
Bool PollSeqQueue(SeqQueue *  queue,ElementType * element);

/**
 * 打印队列中的元素
 * @param queue 要操作的循环队列
 */
void PrintSeqQueue(SeqQueue * queue);

/**
 * 删除队列
 * @param queue 要操作的循环队列
 */
void DelSeqQueue(SeqQueue * queue);
#endif //QUEUE_QUEUE_H
