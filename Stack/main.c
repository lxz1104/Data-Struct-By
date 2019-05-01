#include "Stack.h"

#include <stdio.h>

void TestSeqStack();

int main() {
    TestSeqStack();
    return 0;
}

void TestSeqStack()
{
    //测试数据
    ElementType dataArray[] = {
            {1,"茕茕孑立"},{2,"沆瀣一气"},
            {3,"踽踽独行"},{4,"醍醐灌顶"},
            {5,"绵绵瓜瓞"},{6,"奉为圭臬"}
    };
    ElementType element = {0,NULL};
    SeqStack stack;

    InitSeqStack(&stack);
    //入栈
    for (int i = 0; i < sizeof(dataArray) / sizeof(dataArray[0]); ++i) {
        PushSeqStack(&stack,dataArray[i]);
    }
    printf("当前栈的长度为:%d\n",GetSeqStackLength(&stack));
    PrintSeqStack(&stack);
    //出栈
    element = PopSeqStack(&stack);
    printf("-----出栈后-----\n");
    printf("当前栈的长度为:%d\n",GetSeqStackLength(&stack));
    PrintSeqStack(&stack);
    printf("出栈元素:{%d,%s}\n",element.id,element.name);
    //清空栈
    ClearSeqStack(&stack);
    printf("-----清空栈后-----\n");
    printf("当前栈的长度为:%d\n",GetSeqStackLength(&stack));
    PrintSeqStack(&stack);
}