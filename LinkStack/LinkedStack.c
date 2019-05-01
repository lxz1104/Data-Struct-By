//
// Created by longx on 2019/1/25.
//

#include "LinkedStack.h"

#include <stdio.h>
#include <stdlib.h>

//后移结点
#define MoveToNext(node) node = node->next

void InitLinkedStack(LinkedStack ** linkedStack)
{
    //这里存在一点小问题，无法判断*linkedStack是否在函数外已指向在heap中分配的内存，可能引起内存泄漏
    *linkedStack = (LinkedStack *)malloc(sizeof(LinkedStack));
    (*linkedStack)->length = 0;
    (*linkedStack)->top = NULL;

}

int PushLinkedStack(LinkedStack * linkedStack,ElementType element)
{
    //创建新结点
    LinkedStackNode * newNode = (LinkedStackNode *)malloc(sizeof(LinkedStackNode));
    if(!newNode)
    {
        printf("内存分配失败！\n");
        return PUSH_FAILURE;
    }
    newNode->data = element;
    //新结点指向当前的栈顶
    newNode->next = linkedStack->top;
    linkedStack->top = newNode;
    linkedStack->length++;
    return PUSH_SUCCESS;
}

int PopLinkedStack(LinkedStack * linkedStack,ElementType * element)
{
    if(linkedStack->top == NULL || linkedStack->length == 0)
    {
        printf("空栈，出栈失败！\n");
        linkedStack->length = 0;
        return POP_FAILURE;
    }
    //返回栈顶元素
    *element = linkedStack->top->data;
    //记录出栈操作前的栈顶指针
    LinkedStackNode * tempNode = linkedStack->top;
    //栈顶指针下移一位
    MoveToNext(linkedStack->top);
    //释放原栈点
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
        //栈顶指向下一个元素
        MoveToNext(linkedStack->top);
        free(tempNode);
        linkedStack->length--;
    }
}

void DestoryLinkedStack(LinkedStack ** linkedStack)
{
    //1.清空栈
    ClearLinkedStack(*linkedStack);
    //2.销毁栈
    free(*linkedStack);
    *linkedStack = NULL;
}

void PrintLinkedStack(LinkedStack * linkedStack)
{
    if(linkedStack->top == NULL || linkedStack->length == 0)
    {
        printf("空栈，打印失败！\n");
        linkedStack->length = 0;
        return;
    }
    LinkedStackNode * node = linkedStack->top;
    for (int i = 0; node && i < linkedStack->length; ++i) {
        printf("<%d>:[%s]\n",node->data.id,node->data.name);
        MoveToNext(node);
    }
}