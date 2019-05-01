#include "CircularLinkedList.h"

#include <stdio.h>

void TestCircularLinkList();
int main() {
    TestCircularLinkList();
    return 0;
}

void TestCircularLinkList()
{
    //测试数据
    ElemType dataArray[] = {
            {1,"茕茕孑立"},{2,"沆瀣一气"},
            {3,"踽踽独行"},{4,"醍醐灌顶"},
            {5,"绵绵瓜瓞"},{6,"奉为圭臬"}
    };
    //定义循环链表
    CirularLinkList *clList;
    clList = InitCirularLinkList(clList);
    InsertCirularLinkList(clList,1,dataArray[0]);
    InsertCirularLinkList(clList,2,dataArray[1]);
    InsertCirularLinkList(clList,2,dataArray[2]);
    PrintCirularLinkList(clList);
    printf("-----遍历方法二-----\n");
    PrintCirularLinkListByNode(clList,FindCirularLinkListNode(clList,dataArray[1]));
    printf("-----删除后-----\n");
    DeleteCirularLinkListNode(clList,1);
    PrintCirularLinkList(clList);
}