#include "SequenceList.h"

#include <stdio.h>

void TestSequenceList();

int main(void) { 
    TestSequenceList();
    return 0;
}

void TestSequenceList()
{
    //测试数据
    ElementType dataArray[] = {
            {1,"茕茕孑立"},{2,"沆瀣一气"},
            {3,"踽踽独行"},{4,"醍醐灌顶"},
            {5,"绵绵瓜瓞"},{6,"奉为圭臬"}
    };
    ElementType dataArray2[] = {
            {3,"踽踽独行"},{1,"茕茕孑立"},
            {2,"沆瀣一气"},{4,"醍醐灌顶"},
            {6,"奉为圭臬"},{5,"绵绵瓜瓞"}
    };

    ElementType data = {6,"奉为圭臬"};
    //定义顺序表
    SeqList seqList;
    //初始化顺序表
    InitList(&seqList,dataArray, sizeof(dataArray) / sizeof(dataArray[0]));
    PrintList(&seqList);
    DeleteElement(&seqList,0);
    printf("----------------\n");
    PrintList(&seqList);
    printf("{6,\"奉为圭臬\"}的下标为:%d\n",FindIndex(&seqList,&data));

    //初始化顺序表
    InitList(&seqList,dataArray2, sizeof(dataArray2) / sizeof(dataArray2[0]));
    PrintList(&seqList);
    SortList(&seqList);
    printf("----------------\n");
    PrintList(&seqList);

}