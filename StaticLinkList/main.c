#include "StaticLinkList.h"

#include <stdio.h>

void TestStaticLinkList();
int main() {
    TestStaticLinkList();
    return 0;
}

void TestStaticLinkList()
{
    //��������
    ElementType dataArray[] = {
            {1,"��������"},{2,"���һ��"},
            {3,"�������"},{4,"�����ඥ"},
            {5,"������"},{6,"��Ϊ����"}
    };
    StaticLinkList slList;
    InitStaticLinkList(slList);
    InsertStaticLinkList(slList,1,dataArray[0]);
    InsertStaticLinkList(slList,1,dataArray[1]);
    InsertStaticLinkList(slList,1,dataArray[2]);


    PrintStaticLinkList(slList);
    printf("-----��������-----\n");
    PrintStaticLinkListByInsert(slList);
    printf("-----ɾ����-----\n");
    DeleteStaticLinkList(slList,1);
    PrintStaticLinkList(slList);

}