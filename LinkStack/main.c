#include "LinkedStack.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <psapi.h>

//��ʾ�ڴ���Ϣ
void showMemoryInfo(void);

//���Ժ���
void TestLinkedStack();
void TestLinkedStack2();

int main() {
    TestLinkedStack();
    TestLinkedStack2();
    return 0;
}

void TestLinkedStack()
{
    //��������
    ElementType dataArray[] = {
            {1,"��������"},{2,"���һ��"},
            {3,"�������"},{4,"�����ඥ"},
            {5,"������"},{6,"��Ϊ����"}
    };
    ElementType * popNode = (ElementType *)malloc(sizeof(ElementType));
    LinkedStack * stack;

    //��ʼ��ջ
    InitLinkedStack(&stack);
    //����һ�ֽ�������ǲ���malloc�������Ƶ�ʵ����ʽ��
    // InitLinkedStack()����LinkedStack*���ͣ�LinkedStack * stack = InitLinkedStack();

    //��ջ
    for (int i = 0; i < sizeof(dataArray) / sizeof(dataArray[0]); ++i) {
        PushLinkedStack(stack,dataArray[i]);
    }
    printf("-----��ջ��-----\n");
    PrintLinkedStack(stack);

    //��ջ
    PopLinkedStack(stack,popNode);
    printf("-----��ջ��-----\n");
    PrintLinkedStack(stack);
    printf("��ջԪ��Ϊ: {%d,%s}\n",popNode->id,popNode->name);

    //���ջ
    ClearLinkedStack(stack);
    printf("-----���ջ��-----\n");
    PrintLinkedStack(stack);

    //����ջ
    DestoryLinkedStack(&stack);
    free(popNode);
    popNode = NULL;
}

void TestLinkedStack2()
{
    printf("\n#########�ڴ����#########\n\n");

    //��������
    ElementType dataArray = {1,"��������"};
    //��ʾ�ڴ���Ϣ
    printf("-----��ջǰ-----\n");
    showMemoryInfo();
    ElementType * popNode = (ElementType *)malloc(sizeof(ElementType));
    LinkedStack * stack = NULL;

    //��ʼ��ջ
    InitLinkedStack(&stack);

    //��ջ
    for (int i = 0; i < 100000; ++i) {
        PushLinkedStack(stack,dataArray);
    }
    printf("-----��ջ��-----\n");
    //��ʾ�ڴ���Ϣ
    showMemoryInfo();

    //��ջ
    PopLinkedStack(stack,popNode);
    printf("-----��ջ��-----\n");
    //��ʾ�ڴ���Ϣ
    showMemoryInfo();

    //���ջ
    ClearLinkedStack(stack);
    printf("-----���ջ��-----\n");
    //��ʾ�ڴ���Ϣ
    showMemoryInfo();

    //��ջ
    for (int i = 0; i < 100000; ++i) {
        PushLinkedStack(stack,dataArray);
    }
    printf("-----��ջ��-----\n");
    //��ʾ�ڴ���Ϣ
    showMemoryInfo();

    //����ջ
    DestoryLinkedStack(&stack);
    free(popNode);
    popNode = NULL;
    //��ʾ�ڴ���Ϣ
    printf("-----����ջ��-----\n");
    showMemoryInfo();
}

void showMemoryInfo(void)
{
    HANDLE handle = GetCurrentProcess();
    PROCESS_MEMORY_COUNTERS pmc;
    GetProcessMemoryInfo(handle,&pmc,sizeof(pmc));
    printf("�ڴ�ʹ��:[%ldK/%ldK] �����ڴ�ʹ��:[%ldK/%ldK]\n",pmc.WorkingSetSize/1000,pmc.PeakWorkingSetSize/1000,pmc.PagefileUsage/1000,pmc.PeakPagefileUsage/1000);
}
