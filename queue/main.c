#include "Queue.h"

#include <stdio.h>
#include <stdlib.h>

void TestSeqQueue();

int main(void) {
    TestSeqQueue();
    return 0;
}

void TestSeqQueue()
{
    //��������
    ElementType dataArray[] = {
            {1,"��������"},{2,"���һ��"},
            {3,"�������"},{4,"�����ඥ"},
            {5,"������"},{6,"��Ϊ����"}
    };
    SeqQueue seq;
    ElementType * delElement = (ElementType *)malloc(sizeof(ElementType));
    InitSeqQueue(&seq);
    for (int i = 0; i < sizeof(dataArray) / sizeof(dataArray[0]); ++i) {
        OfferSeqQueue(&seq,dataArray[i]);
    }
    PrintSeqQueue(&seq);
    printf("------���Ӻ�------\n");
    PollSeqQueue(&seq,delElement);
    PrintSeqQueue(&seq);
    DelSeqQueue(&seq);
}

