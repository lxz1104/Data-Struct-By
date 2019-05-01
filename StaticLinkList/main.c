#include "StaticLinkList.h"

#include <stdio.h>

void TestStaticLinkList();
int main() {
    TestStaticLinkList();
    return 0;
}

void TestStaticLinkList()
{
    //²âÊÔÊı¾İ
    ElementType dataArray[] = {
            {1,"ÜäÜäæİÁ¢"},{2,"ãìå¬Ò»Æø"},
            {3,"õáõá¶ÀĞĞ"},{4,"õ®õ­¹à¶¥"},
            {5,"ÃàÃà¹Ïğ¬"},{6,"·îÎª¹çô«"}
    };
    StaticLinkList slList;
    InitStaticLinkList(slList);
    InsertStaticLinkList(slList,1,dataArray[0]);
    InsertStaticLinkList(slList,1,dataArray[1]);
    InsertStaticLinkList(slList,1,dataArray[2]);


    PrintStaticLinkList(slList);
    printf("-----ÒÑÓÃÁ´±í-----\n");
    PrintStaticLinkListByInsert(slList);
    printf("-----É¾³ıºó-----\n");
    DeleteStaticLinkList(slList,1);
    PrintStaticLinkList(slList);

}