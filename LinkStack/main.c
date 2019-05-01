#include "LinkedStack.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <psapi.h>

//显示内存信息
void showMemoryInfo(void);

//测试函数
void TestLinkedStack();
void TestLinkedStack2();

int main() {
    TestLinkedStack();
    TestLinkedStack2();
    return 0;
}

void TestLinkedStack()
{
    //测试数据
    ElementType dataArray[] = {
            {1,"茕茕孑立"},{2,"沆瀣一气"},
            {3,"踽踽独行"},{4,"醍醐灌顶"},
            {5,"绵绵瓜瓞"},{6,"奉为圭臬"}
    };
    ElementType * popNode = (ElementType *)malloc(sizeof(ElementType));
    LinkedStack * stack;

    //初始化栈
    InitLinkedStack(&stack);
    //还有一种解决方法是采用malloc函数相似的实现形式：
    // InitLinkedStack()返回LinkedStack*类型，LinkedStack * stack = InitLinkedStack();

    //入栈
    for (int i = 0; i < sizeof(dataArray) / sizeof(dataArray[0]); ++i) {
        PushLinkedStack(stack,dataArray[i]);
    }
    printf("-----入栈后-----\n");
    PrintLinkedStack(stack);

    //出栈
    PopLinkedStack(stack,popNode);
    printf("-----出栈后-----\n");
    PrintLinkedStack(stack);
    printf("出栈元素为: {%d,%s}\n",popNode->id,popNode->name);

    //清空栈
    ClearLinkedStack(stack);
    printf("-----清空栈后-----\n");
    PrintLinkedStack(stack);

    //销毁栈
    DestoryLinkedStack(&stack);
    free(popNode);
    popNode = NULL;
}

void TestLinkedStack2()
{
    printf("\n#########内存测试#########\n\n");

    //测试数据
    ElementType dataArray = {1,"茕茕孑立"};
    //显示内存信息
    printf("-----入栈前-----\n");
    showMemoryInfo();
    ElementType * popNode = (ElementType *)malloc(sizeof(ElementType));
    LinkedStack * stack = NULL;

    //初始化栈
    InitLinkedStack(&stack);

    //入栈
    for (int i = 0; i < 100000; ++i) {
        PushLinkedStack(stack,dataArray);
    }
    printf("-----入栈后-----\n");
    //显示内存信息
    showMemoryInfo();

    //出栈
    PopLinkedStack(stack,popNode);
    printf("-----出栈后-----\n");
    //显示内存信息
    showMemoryInfo();

    //清空栈
    ClearLinkedStack(stack);
    printf("-----清空栈后-----\n");
    //显示内存信息
    showMemoryInfo();

    //入栈
    for (int i = 0; i < 100000; ++i) {
        PushLinkedStack(stack,dataArray);
    }
    printf("-----入栈后-----\n");
    //显示内存信息
    showMemoryInfo();

    //销毁栈
    DestoryLinkedStack(&stack);
    free(popNode);
    popNode = NULL;
    //显示内存信息
    printf("-----销毁栈后-----\n");
    showMemoryInfo();
}

void showMemoryInfo(void)
{
    HANDLE handle = GetCurrentProcess();
    PROCESS_MEMORY_COUNTERS pmc;
    GetProcessMemoryInfo(handle,&pmc,sizeof(pmc));
    printf("内存使用:[%ldK/%ldK] 虚拟内存使用:[%ldK/%ldK]\n",pmc.WorkingSetSize/1000,pmc.PeakWorkingSetSize/1000,pmc.PagefileUsage/1000,pmc.PeakPagefileUsage/1000);
}
