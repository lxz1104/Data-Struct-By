//
// Created by longx on 2019/1/25.
//

#include "LinkedStack.h"

#include <stdio.h>
#include <stdlib.h>

//���ƽ��
#define MoveToNext(node) node = node->next

void InitLinkedStack(LinkedStack ** linkedStack)
{
    //�������һ��С���⣬�޷��ж�*linkedStack�Ƿ��ں�������ָ����heap�з�����ڴ棬���������ڴ�й©
    *linkedStack = (LinkedStack *)malloc(sizeof(LinkedStack));
    (*linkedStack)->length = 0;
    (*linkedStack)->top = NULL;

}

int PushLinkedStack(LinkedStack * linkedStack,ElementType element)
{
    //�����½��
    LinkedStackNode * newNode = (LinkedStackNode *)malloc(sizeof(LinkedStackNode));
    if(!newNode)
    {
        printf("�ڴ����ʧ�ܣ�\n");
        return PUSH_FAILURE;
    }
    newNode->data = element;
    //�½��ָ��ǰ��ջ��
    newNode->next = linkedStack->top;
    linkedStack->top = newNode;
    linkedStack->length++;
    return PUSH_SUCCESS;
}

int PopLinkedStack(LinkedStack * linkedStack,ElementType * element)
{
    if(linkedStack->top == NULL || linkedStack->length == 0)
    {
        printf("��ջ����ջʧ�ܣ�\n");
        linkedStack->length = 0;
        return POP_FAILURE;
    }
    //����ջ��Ԫ��
    *element = linkedStack->top->data;
    //��¼��ջ����ǰ��ջ��ָ��
    LinkedStackNode * tempNode = linkedStack->top;
    //ջ��ָ������һλ
    MoveToNext(linkedStack->top);
    //�ͷ�ԭջ��
    free(tempNode);
    tempNode = NULL;
    linkedStack->length--;
    return POP_SUCCESS;
}

void ClearLinkedStack(LinkedStack * linkedStack)
{
    LinkedStackNode * tempNode = NULL;
    while (linkedStack->top)
    {
        tempNode = linkedStack->top;
        //ջ��ָ����һ��Ԫ��
        MoveToNext(linkedStack->top);
        free(tempNode);
        linkedStack->length--;
    }
}

void DestoryLinkedStack(LinkedStack ** linkedStack)
{
    //1.���ջ
    ClearLinkedStack(*linkedStack);
    //2.����ջ
    free(*linkedStack);
    *linkedStack = NULL;
}

void PrintLinkedStack(LinkedStack * linkedStack)
{
    if(linkedStack->top == NULL || linkedStack->length == 0)
    {
        printf("��ջ����ӡʧ�ܣ�\n");
        linkedStack->length = 0;
        return;
    }
    LinkedStackNode * node = linkedStack->top;
    for (int i = 0; node && i < linkedStack->length; ++i) {
        printf("<%d>:[%s]\n",node->data.id,node->data.name);
        MoveToNext(node);
    }
}