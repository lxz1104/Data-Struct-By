//
// Created by longx on 2019/2/2.
//

#include "Queue.h"

#include <stdlib.h>
#include <stdio.h>

//��ʼ��ѭ������
void InitSeqQueue(SeqQueue * queue)
{
    if(queue == NULL)
    {
        queue = (SeqQueue *)malloc(sizeof(SeqQueue));
        if(queue == NULL)
        {
            printf("�ڴ����ʧ�ܣ�\n");
            return;
        }
    }
    queue->data->name = NULL;
    queue->data->id = 0;
    queue->length = 0;
    queue->front = 0;
    queue->rear = 0;
}

//�����Ƿ�Ϊ��
Bool IsEmpty(SeqQueue * queue)
{
    return queue->front == queue->rear ? True : False;
}

//�����Ƿ�����
Bool IsFull(SeqQueue * queue)
{
    return (queue->rear + 1) % MAX_SIZE == queue->front ? True : False;
}

//���
Bool OfferSeqQueue(SeqQueue * queue,ElementType element)
{
    if(IsFull(queue))
    {
        printf("�������������ʧ�ܣ�\n");
        return False;
    }
    queue->data[queue->rear] = element;
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->length++;
    return True;
}

//����
Bool PollSeqQueue(SeqQueue *  queue,ElementType * element)
{
    if(IsEmpty(queue))
    {
        printf("����Ϊ�գ�����ʧ�ܣ�\n");
        return False;
    }
    //ȡ����ͷԪ��
    *element = queue->data[queue->front];
    queue->data[queue->front].id = 0;
    queue->data[queue->front].name = NULL;
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->length--;
    return True;
}

//��Ӧ�����е�Ԫ��
void PrintSeqQueue(SeqQueue * queue)
{
    if(IsEmpty(queue))
    {
        printf("����Ϊ�գ���ӡʧ��!\n");
        return;
    }
    for (int i = queue->front; i < queue->rear; ++i) {
        printf("<%d>:[%s]\n",queue->data[i].id,queue->data[i].name);
    }
}

//ɾ��ѭ������
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