//
// Created by longx on 2019/2/27.
//

#include "LinkedQueue.h"

#include <stdlib.h>

/**
 * 初始化队列
 */
void InitLinkedQueue(LinkedQueue * linkedQueue)
{
    linkedQueue->qFront = (QueueNode *)malloc(sizeof(QueueNode));
    linkedQueue->qFront->next = NULL;
    linkedQueue->qRear  = linkedQueue->qFront;
}

/**
 * 入队
 */
void EnterQueue(LinkedQueue * linkedQueue,TreeNode * data)
{
    QueueNode * node = (QueueNode *)malloc(sizeof(QueueNode));
    node->data = data;
    node->next = NULL;
    linkedQueue->qRear->next = node;
    linkedQueue->qRear = node;
}

/**
 * 出队
 */
TreeNode * DeQueue(LinkedQueue * linkedQueue)
{
    TreeNode * data = NULL; //返回出队元素
    if(linkedQueue->qFront == linkedQueue->qRear){
        return data;
    }
    QueueNode * node = linkedQueue->qFront->next;
    data = node->data;
    linkedQueue->qFront->next = node->next;
    if(linkedQueue->qRear == node)
    {
        linkedQueue->qRear = linkedQueue->qFront;
    }
    free(node);
    node = NULL;
    return data;
}

/**
 * 判断队列是否为空
 */
int IsLinkedQueueEmpty(LinkedQueue * linkedQueue)
{
    return linkedQueue->qFront == linkedQueue->qRear ? 1 : 0;
}

/**
 * 销毁队列
 */
void DestroyQueue(LinkedQueue * linkedQueue)
{
    while (DeQueue(linkedQueue));
    if(linkedQueue->qFront != NULL)
    {
        free(linkedQueue->qFront);
        linkedQueue->qFront = NULL;
        linkedQueue->qRear = NULL;
    }
}