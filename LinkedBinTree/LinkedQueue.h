//
// Created by longx on 2019/2/27.
//

#ifndef LINKEDBINTREE_LINKEDQUEUE_H
#define LINKEDBINTREE_LINKEDQUEUE_H

/**
 * 链式队列实现
 */

#include "LinkedBinTree.h"

/** 链队结点 */
typedef struct queueNode{
    TreeNode * data;    //数据域
    struct queueNode * next;    //指针域
}QueueNode;

/** 链队列结构 */
typedef struct {
    QueueNode * qFront; //队列头指针
    QueueNode * qRear;  //队列尾指针
}LinkedQueue;

/**
 * 初始化队列
 * @param linkedQueue 要操作的队列
 */
void InitLinkedQueue(LinkedQueue * linkedQueue);

/**
 * 入队
 * @param linkedQueue 要操作的队列
 * @param data 要入队的元素
 */
void EnterQueue(LinkedQueue * linkedQueue,TreeNode * data);

/**
 * 出队
 * @param linkedQueue 要操作的队列
 * @return 出队的元素
 */
TreeNode * DeQueue(LinkedQueue * linkedQueue);

/**
 * 判断队列是否为空
 * @param linkedQueue 要操作的队列
 * @return 为空，返回1；不为空，返回0
 */
int IsLinkedQueueEmpty(LinkedQueue * linkedQueue);

/**
 * 销毁队列
 * @param linkedQueue 要操作的队列
 */
void DestroyQueue(LinkedQueue * linkedQueue);
#endif //LINKEDBINTREE_LINKEDQUEUE_H
