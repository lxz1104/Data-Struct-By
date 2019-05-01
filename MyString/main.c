#include "SeqString.h"

#include <stdio.h>

void TestHString();

int main() {
    TestHString();
    return 0;
}

void TestHString()
{
    HString str;
    HString str2;

    StrAssign_HeapString(&str2,"This is for str2!");

    printf("------初始化堆串------\n");
    StrAssign_HeapString(&str,"hello world!");
    printf("str的值为:");
    PrintHeapString(&str);
    printf("\n");
    printf("str2的值为:");
    PrintHeapString(&str2);
    printf("\n");

    printf("\n------连接堆串------\n");
    printf("连接后的str的值为:");
    StrConcat_HeapString(&str,&str2);
    PrintHeapString(&str);
    printf("\n");

    printf("\n------堆串比较------\n");
    if(StrCompare_HeapString(&str,&str2) == GT)
    {
        printf("str > str2\n");
    }

    printf("\n------堆串复制------\n");
    StrCopy_HeapString(&str,&str2);
    printf("将str2复制给str后，str的值为:");
    PrintHeapString(&str);
    printf("\n");

    printf("\n------堆串截取------\n");
    HString str3;
    SubString_HeapString(&str3,&str,6,2);
    printf("截取后的堆串为:");
    PrintHeapString(&str3);
    printf("\n");
    DelHeapString(&str3);

    printf("\n------查找子串------\n");
    HString parent,child;
    StrAssign_HeapString(&parent,"123 321 654 789");
    StrAssign_HeapString(&child,"321");
    printf("父串为:");
    PrintHeapString(&parent);
    printf("\t子串为:");
    PrintHeapString(&child);
    printf("\n子串在父串中第一次出现的位置为:%d\n",FindSubstr_HeapString(&parent,&child,1)) ;
    DelHeapString(&parent);
    DelHeapString(&child);


    printf("\n------删除堆串中指定内容------\n");
    printf("str删除前:");
    PrintHeapString(&str);
    StrDelete_HeapString(&str,6,2);
    printf("\nstr删除指定内容后:");
    PrintHeapString(&str);

    printf("\n\n------在堆串中添加指定内容------\n");
    HString newStr;
    StrAssign_HeapString(&newStr,"is");
    printf("str添加前:");
    PrintHeapString(&str);
    StrInsert_HeapString(&str,6,&newStr);
    printf("\nstr添加指定内容后:");
    PrintHeapString(&str);
    DelHeapString(&newStr);

    printf("\n\n------替换堆串中指定内容------\n");
    HString oldStr;
    StrAssign_HeapString(&oldStr,"str2");
    StrAssign_HeapString(&newStr,"me");
    printf("str替换前:");
    PrintHeapString(&str);
    StrReplace_HeapString(&str,&oldStr,&newStr);
    printf("\nstr替换指定内容后:");
    PrintHeapString(&str);

    DelHeapString(&str2);
    DelHeapString(&str);
}