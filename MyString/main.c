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

    printf("------��ʼ���Ѵ�------\n");
    StrAssign_HeapString(&str,"hello world!");
    printf("str��ֵΪ:");
    PrintHeapString(&str);
    printf("\n");
    printf("str2��ֵΪ:");
    PrintHeapString(&str2);
    printf("\n");

    printf("\n------���ӶѴ�------\n");
    printf("���Ӻ��str��ֵΪ:");
    StrConcat_HeapString(&str,&str2);
    PrintHeapString(&str);
    printf("\n");

    printf("\n------�Ѵ��Ƚ�------\n");
    if(StrCompare_HeapString(&str,&str2) == GT)
    {
        printf("str > str2\n");
    }

    printf("\n------�Ѵ�����------\n");
    StrCopy_HeapString(&str,&str2);
    printf("��str2���Ƹ�str��str��ֵΪ:");
    PrintHeapString(&str);
    printf("\n");

    printf("\n------�Ѵ���ȡ------\n");
    HString str3;
    SubString_HeapString(&str3,&str,6,2);
    printf("��ȡ��ĶѴ�Ϊ:");
    PrintHeapString(&str3);
    printf("\n");
    DelHeapString(&str3);

    printf("\n------�����Ӵ�------\n");
    HString parent,child;
    StrAssign_HeapString(&parent,"123 321 654 789");
    StrAssign_HeapString(&child,"321");
    printf("����Ϊ:");
    PrintHeapString(&parent);
    printf("\t�Ӵ�Ϊ:");
    PrintHeapString(&child);
    printf("\n�Ӵ��ڸ����е�һ�γ��ֵ�λ��Ϊ:%d\n",FindSubstr_HeapString(&parent,&child,1)) ;
    DelHeapString(&parent);
    DelHeapString(&child);


    printf("\n------ɾ���Ѵ���ָ������------\n");
    printf("strɾ��ǰ:");
    PrintHeapString(&str);
    StrDelete_HeapString(&str,6,2);
    printf("\nstrɾ��ָ�����ݺ�:");
    PrintHeapString(&str);

    printf("\n\n------�ڶѴ������ָ������------\n");
    HString newStr;
    StrAssign_HeapString(&newStr,"is");
    printf("str���ǰ:");
    PrintHeapString(&str);
    StrInsert_HeapString(&str,6,&newStr);
    printf("\nstr���ָ�����ݺ�:");
    PrintHeapString(&str);
    DelHeapString(&newStr);

    printf("\n\n------�滻�Ѵ���ָ������------\n");
    HString oldStr;
    StrAssign_HeapString(&oldStr,"str2");
    StrAssign_HeapString(&newStr,"me");
    printf("str�滻ǰ:");
    PrintHeapString(&str);
    StrReplace_HeapString(&str,&oldStr,&newStr);
    printf("\nstr�滻ָ�����ݺ�:");
    PrintHeapString(&str);

    DelHeapString(&str2);
    DelHeapString(&str);
}