//
// Created by longx on 2019/1/25.
//

#include "Stack.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void InitSeqStack(SeqStack * seqStack)
{
    //Õ»¶¥ÖÃ¿Õ
    seqStack->top = EMPTY_STACK;
    //³¤¶ÈÖÃÁã
    seqStack->length = 0;
    //Êý¾ÝÔªËØÖÃÁã
    memset(seqStack->element, 0 , sizeof(seqStack->element[0]) * MAX_SIZE);
}

int PushSeqStack(SeqStack * seqStack,ElementType element)
{
    if(seqStack->top == MAX_SIZE - 1)
    {
        printf("Õ»ÒÑÂú£¬Ñ¹Õ»Ê§°Ü£¡\n");
        return PUSH_FAILURE;

    }
    seqStack->top++;
    //½«ÐÂ²åÈëµÄÔªËØ¸³Öµ¸øÕ»¶¥
    seqStack->element[seqStack->top] = element;
    seqStack->length++;
    return PUSH_SUCCESS;
}

ElementType PopSeqStack(SeqStack * seqStack)
{
    ElementType element = {0,NULL};
    if(seqStack->top == EMPTY_STACK)
    {
        printf("¿ÕÕ»£¬³öÕ»Ê§°Ü£¡\n");
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
    //Êý¾ÝÔªËØÖÃÁã
    memset(seqStack->element, 0 , sizeof(seqStack->element[0]) * MAX_SIZE);
}

void PrintSeqStack(SeqStack * seqStack)
{
    if(seqStack->top == EMPTY_STACK)
    {
        printf("¿ÕÕ»£¬´òÓ¡Ê§°Ü£¡\n");
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
        printf("¿ÕÕ»£¬»ñÈ¡Ê§°Ü£¡\n");
        return element;
    }
    return seqStack->element[seqStack->top];
}

int GetSeqStackLength(SeqStack * seqStack)
{
    return seqStack->length;
}