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
    //²âÊÔÊı¾İ
    ElementType dataArray[] = {
            {1,"ÜäÜäæİÁ¢"},{2,"ãìå¬Ò»Æø"},
            {3,"õáõá¶ÀĞĞ"},{4,"õ®õ­¹à¶¥"},
            {5,"ÃàÃà¹Ïğ¬"},{6,"·îÎª¹çô«"}
    };
    DoublelyLinkList *dlList = NULL;
    dlList = InitDoublelyLinkList(dlList);
    for (int i = 0; i < sizeof(dataArray) / sizeof(dataArray[0]); ++i) {
        InsertDoublelyLinkList(dlList,1,dataArray[i]);
    }
    PrintDoublelyLinkList(dlList);
    DeleteDoublelyLinkList(dlList,1);
    printf("-----É¾³ıºó-----\n");
    PrintDoublelyLinkList(dlList);
    FreeDoublelyLinkList(dlList);
}