//
// Created by longx on 2019/2/15.
//

#include "LinkedStack.h"

#include <stdio.h>
#include <stdlib.h>

#define MoveToNext(node) node = node->next


void InitLinkedStack(LinkedStack * LStack)
{
    LStack->length = 0;
    LStack->top = NULL;
}

int Push(LinkedStack * LStack,TreeNode * node)
{
    StackNode * tempNode = (StackNode *)malloc(sizeof(StackNode));
    if(!tempNode){
        return 0;
    }
    tempNode->data = node;
    tempNode->next = LStack->top;
    LStack->top = tempNode;
    LStack->length++;
    return 1;
}

int Pop(LinkedStack * LStack,TreeNode ** node)
{
    StackNode * tempNode = NULL;
    if(LStack->top == NULL || LStack->length == 0)
    {
        LStack->length = 0;
        return 0;
    }
    //返回栈中的数据域
    *node = LStack->top->data;
    tempNode = LStack->top;
    MoveToNext(LStack->top);
    free(tempNode);
    tempNode = NULL;
    LStack->length--;
    return 1;
}

int IsLinkedStackEmpty(LinkedStack * LStack)
{
    if(LStack->top == NULL || LStack->length == 0)
    {
        return 1;
    }
    return 0;
}

void ClearLinkedStack(LinkedStack * LStack)
{
    StackNode * tempNode;
    while (LStack->top)
    {
        tempNode = LStack->top;
        //栈顶指向下一个元素
        MoveToNext(LStack->top);
        free(tempNode);
        LStack->length--;
    }
}
void DestoryLinkedStack(LinkedStack * LStack)
{
    //1.清空栈
    ClearLinkedStack(LStack);
    InitLinkedStack(LStack);
}
