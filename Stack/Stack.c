//
// Created by longx on 2019/1/25.
//

#include "Stack.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void InitSeqStack(SeqStack * seqStack)
{
    //ջ���ÿ�
    seqStack->top = EMPTY_STACK;
    //��������
    seqStack->length = 0;
    //����Ԫ������
    memset(seqStack->element, 0 , sizeof(seqStack->element[0]) * MAX_SIZE);
}

int PushSeqStack(SeqStack * seqStack,ElementType element)
{
    if(seqStack->top == MAX_SIZE - 1)
    {
        printf("ջ������ѹջʧ�ܣ�\n");
        return PUSH_FAILURE;

    }
    seqStack->top++;
    //���²����Ԫ�ظ�ֵ��ջ��
    seqStack->element[seqStack->top] = element;
    seqStack->length++;
    return PUSH_SUCCESS;
}

ElementType PopSeqStack(SeqStack * seqStack)
{
    ElementType element = {0,NULL};
    if(seqStack->top == EMPTY_STACK)
    {
        printf("��ջ����ջʧ�ܣ�\n");
        return element;
    }
    element = seqStack->element[seqStack->top];
    seqStack->element[seqStack->top].name = NULL;
    seqStack->element[seqStack->top].id = 0;
    seqStack->top--;
    seqStack->length--;
    return element;
}

void ClearSeqStack(SeqStack * seqStack)
{
    seqStack->top = EMPTY_STACK;
    seqStack->length = 0;
    //����Ԫ������
    memset(seqStack->element, 0 , sizeof(seqStack->element[0]) * MAX_SIZE);
}

void PrintSeqStack(SeqStack * seqStack)
{
    if(seqStack->top == EMPTY_STACK)
    {
        printf("��ջ����ӡʧ�ܣ�\n");
        return;
    }
    for(int i = seqStack->top;i >= 0;--i)
    {
        printf("<%d>:[%s]\n",seqStack->element[i].id,seqStack->element[i].name);
    }
}

ElementType GetSeqStackTop(SeqStack * seqStack)
{
    ElementType element = {0,NULL};
    if(seqStack->top == EMPTY_STACK)
    {
        printf("��ջ����ȡʧ�ܣ�\n");
        return element;
    }
    return seqStack->element[seqStack->top];
}

int GetSeqStackLength(SeqStack * seqStack)
{
    return seqStack->length;
}