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
    //测试数据
    ElementType dataArray[] = {
            {1,"茕茕孑立"},{2,"沆瀣一气"},
            {3,"踽踽独行"},{4,"醍醐灌顶"},
            {5,"绵绵瓜瓞"},{6,"奉为圭臬"}
    };
    SeqQueue seq;
    ElementType * delElement = (ElementType *)malloc(sizeof(ElementType));
    InitSeqQueue(&seq);
    for (int i = 0; i < sizeof(dataArray) / sizeof(dataArray[0]); ++i) {
        OfferSeqQueue(&seq,dataArray[i]);
    }
    PrintSeqQueue(&seq);
    printf("------出队后------\n");
    PollSeqQueue(&seq,delElement);
    PrintSeqQueue(&seq);
    DelSeqQueue(&seq);
}

