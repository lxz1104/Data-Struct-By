#include "StatusLib.h"
#include "LinkedString.h"

#include <stdio.h>

void TestLinkedString();

int main() {
    TestLinkedString();
    PressEnter();
    return 0;
}

void TestLinkedString()
{
    LString l1,l2,l3;
    initString_L(&l1);
    initString_L(&l2);
    initString_L(&l3);

    //链串赋值
    strAssign_L(&l1,"l1: world\n");
    strAssign_L(&l2,"l2: hello world!\n");
    printf("------给链串赋值后------\n");
    printString_L(l1);
    printString_L(l2);

    //链串复制
    strCopy_L(&l3,&l2);
    printf("------l2复制给l3后------\n");
    printString_L(l3);
    printString_L(l2);

    //链串大小比较
    printf("------链串大小比较------\n");
    printf("l1和l2比较的结果为:%d\n",strCompare_L(l1,l2));
    printf("l3和l2比较的结果为:%d\n",strCompare_L(l3,l2));

    //链串长度计算
    printf("------链串字符个数获取------\n");
    printf("l2的字符个数为:%d\n",strLength_L(l2));

    //清空链串
    clearString_L(&l3);
    printf("------清空链串l3后------\n");
    printString_L(l3);

    //连接两个链串
    strConcat_L(&l3,l1,l2);
    printf("------连接l1和l2后------\n");
    printString_L(l3);

    //截取链串
    subString_L(&l3,l2,5,5);
    printf("------在l2中截取字符------\n");
    printString_L(l3);

    //链串的子串匹配
    strAssign_L(&l3,"world");
    printf("\n------在l2中查找l3第一次出现的位置------\n");
    printf("l1在l2中第一次出现的位置为:%d\n",index_L(l2,l3,1));

    //链串的替换
    LString l4;
    initString_L(&l4);
    strAssign_L(&l4,"o");
    strAssign_L(&l3,"wor");
    strReplace_L(&l1,l3,l4);
    printf("------将l1中的'wor'替换为'o'------\n");
    printString_L(l1);

    //链串的插入
    strAssign_L(&l3,"How ");
    strInsert_L(&l1,5,l3);
    printf("------在l1中插入'How'------\n");
    printString_L(l1);

    //链串的删除
    strDelete_L(&l1,9,3);
    printf("------删除l1中的'old'------\n");
    printString_L(l1);

    //销毁链串
    destoryString(&l1);
    destoryString(&l2);
    destoryString(&l3);
    destoryString(&l4);
}