#include "Stack.h"

#include <stdio.h>

void TestSeqStack();

int main() {
    TestSeqStack();
    return 0;
}

void TestSeqStack()
{
    //��������
    ElementType dataArray[] = {
            {1,"��������"},{2,"���һ��"},
            {3,"�������"},{4,"�����ඥ"},
            {5,"������"},{6,"��Ϊ����"}
    };
    ElementType element = {0,NULL};
    SeqStack stack;

    InitSeqStack(&stack);
    //��ջ
    for (int i = 0; i < sizeof(dataArray) / sizeof(dataArray[0]); ++i) {
        PushSeqStack(&stack,dataArray[i]);
    }
    printf("��ǰջ�ĳ���Ϊ:%d\n",GetSeqStackLength(&stack));
    PrintSeqStack(&stack);
    //��ջ
    element = PopSeqStack(&stack);
    printf("-----��ջ��-----\n");
    printf("��ǰջ�ĳ���Ϊ:%d\n",GetSeqStackLength(&stack));
    PrintSeqStack(&stack);
    printf("��ջԪ��:{%d,%s}\n",element.id,element.name);
    //���ջ
    ClearSeqStack(&stack);
    printf("-----���ջ��-----\n");
    printf("��ǰջ�ĳ���Ϊ:%d\n",GetSeqStackLength(&stack));
    PrintSeqStack(&stack);
}