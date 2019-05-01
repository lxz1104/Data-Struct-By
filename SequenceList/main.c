#include "SequenceList.h"

#include <stdio.h>

void TestSequenceList();

int main(void) { 
    TestSequenceList();
    return 0;
}

void TestSequenceList()
{
    //��������
    ElementType dataArray[] = {
            {1,"��������"},{2,"���һ��"},
            {3,"�������"},{4,"�����ඥ"},
            {5,"������"},{6,"��Ϊ����"}
    };
    ElementType dataArray2[] = {
            {3,"�������"},{1,"��������"},
            {2,"���һ��"},{4,"�����ඥ"},
            {6,"��Ϊ����"},{5,"������"}
    };

    ElementType data = {6,"��Ϊ����"};
    //����˳���
    SeqList seqList;
    //��ʼ��˳���
    InitList(&seqList,dataArray, sizeof(dataArray) / sizeof(dataArray[0]));
    PrintList(&seqList);
    DeleteElement(&seqList,0);
    printf("----------------\n");
    PrintList(&seqList);
    printf("{6,\"��Ϊ����\"}���±�Ϊ:%d\n",FindIndex(&seqList,&data));

    //��ʼ��˳���
    InitList(&seqList,dataArray2, sizeof(dataArray2) / sizeof(dataArray2[0]));
    PrintList(&seqList);
    SortList(&seqList);
    printf("----------------\n");
    PrintList(&seqList);

}