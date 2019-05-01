#include "DoublelyLinkList.h"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void TestDoublelyLinkList();

int main() {
    TestDoublelyLinkList();
    getchar();
    return 0;
}

void TestDoublelyLinkList()
{
    //��������
    ElementType dataArray[] = {
            {1,"��������"},{2,"���һ��"},
            {3,"�������"},{4,"�����ඥ"},
            {5,"������"},{6,"��Ϊ����"}
    };
    DoublelyLinkList *dlList = NULL;
    dlList = InitDoublelyLinkList(dlList);
    for (int i = 0; i < sizeof(dataArray) / sizeof(dataArray[0]); ++i) {
        InsertDoublelyLinkList(dlList,1,dataArray[i]);
    }
    PrintDoublelyLinkList(dlList);
    DeleteDoublelyLinkList(dlList,1);
    printf("-----ɾ����-----\n");
    PrintDoublelyLinkList(dlList);
    FreeDoublelyLinkList(dlList);
}