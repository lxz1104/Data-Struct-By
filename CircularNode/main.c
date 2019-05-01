#include "CircularLinkedList.h"

#include <stdio.h>

void TestCircularLinkList();
int main() {
    TestCircularLinkList();
    return 0;
}

void TestCircularLinkList()
{
    //��������
    ElemType dataArray[] = {
            {1,"��������"},{2,"���һ��"},
            {3,"�������"},{4,"�����ඥ"},
            {5,"������"},{6,"��Ϊ����"}
    };
    //����ѭ������
    CirularLinkList *clList;
    clList = InitCirularLinkList(clList);
    InsertCirularLinkList(clList,1,dataArray[0]);
    InsertCirularLinkList(clList,2,dataArray[1]);
    InsertCirularLinkList(clList,2,dataArray[2]);
    PrintCirularLinkList(clList);
    printf("-----����������-----\n");
    PrintCirularLinkListByNode(clList,FindCirularLinkListNode(clList,dataArray[1]));
    printf("-----ɾ����-----\n");
    DeleteCirularLinkListNode(clList,1);
    PrintCirularLinkList(clList);
}