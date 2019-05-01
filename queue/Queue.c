//
// Created by longx on 2019/2/2.
//

#include "Queue.h"

#include <stdlib.h>
#include <stdio.h>

//初始化循环队列
void InitSeqQueue(SeqQueue * queue)
{
    if(queue == NULL)
    {
        queue = (SeqQueue *)malloc(sizeof(SeqQueue));
        if(queue == NULL)
        {
            printf("内存分配失败！\n");
            return;
        }
    }
    queue->data->name = NULL;
    queue->data->id = 0;
    queue->length = 0;
    queue->front = 0;
    queue->rear = 0;
}

//队列是否为空
Bool IsEmpty(SeqQueue * queue)
{
    return queue->front == queue->rear ? True : False;
}

//队列是否已满
Bool IsFull(SeqQueue * queue)
{
    return (queue->rear + 1) % MAX_SIZE == queue->front ? True : False;
}

//入队
Bool OfferSeqQueue(SeqQueue * queue,ElementType element)
{
    if(IsFull(queue))
    {
        printf("队列已满，入队失败！\n");
        return False;
    }
    queue->data[queue->rear] = element;
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->length++;
    return True;
}

//出队
Bool PollSeqQueue(SeqQueue *  queue,ElementType * element)
{
    if(IsEmpty(queue))
    {
        printf("队列为空，出队失败！\n");
        return False;
    }
    //取出对头元素
    *element = queue->data[queue->front];
    queue->data[queue->front].id = 0;
    queue->data[queue->front].name = NULL;
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->length--;
    return True;
}

//答应队列中的元素
void PrintSeqQueue(SeqQueue * queue)
{
    if(IsEmpty(queue))
    {
        printf("队列为空，打印失败!\n");
        return;
    }
    for (int i = queue->front; i < queue->rear; ++i) {
        printf("<%d>:[%s]\n",queue->data[i].id,queue->data[i].name);
    }
}

//删除循环队列
void DelSeqQueue(SeqQueue * queue)
{
    if(queue == NULL)
    {
        return;
    }
    if(IsEmpty(queue))
    {
        free(queue);
        queue = NULL;
        return;
    }
    for (int i = queue->front; i < queue->rear; ++i) {
        queue->data[i].id = 0;
        queue->data[i].name = NULL;
    }
    queue->length = 0;
    free(queue);
    queue = NULL;
}