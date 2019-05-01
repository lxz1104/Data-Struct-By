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

    //������ֵ
    strAssign_L(&l1,"l1: world\n");
    strAssign_L(&l2,"l2: hello world!\n");
    printf("------��������ֵ��------\n");
    printString_L(l1);
    printString_L(l2);

    //��������
    strCopy_L(&l3,&l2);
    printf("------l2���Ƹ�l3��------\n");
    printString_L(l3);
    printString_L(l2);

    //������С�Ƚ�
    printf("------������С�Ƚ�------\n");
    printf("l1��l2�ȽϵĽ��Ϊ:%d\n",strCompare_L(l1,l2));
    printf("l3��l2�ȽϵĽ��Ϊ:%d\n",strCompare_L(l3,l2));

    //�������ȼ���
    printf("------�����ַ�������ȡ------\n");
    printf("l2���ַ�����Ϊ:%d\n",strLength_L(l2));

    //�������
    clearString_L(&l3);
    printf("------�������l3��------\n");
    printString_L(l3);

    //������������
    strConcat_L(&l3,l1,l2);
    printf("------����l1��l2��------\n");
    printString_L(l3);

    //��ȡ����
    subString_L(&l3,l2,5,5);
    printf("------��l2�н�ȡ�ַ�------\n");
    printString_L(l3);

    //�������Ӵ�ƥ��
    strAssign_L(&l3,"world");
    printf("\n------��l2�в���l3��һ�γ��ֵ�λ��------\n");
    printf("l1��l2�е�һ�γ��ֵ�λ��Ϊ:%d\n",index_L(l2,l3,1));

    //�������滻
    LString l4;
    initString_L(&l4);
    strAssign_L(&l4,"o");
    strAssign_L(&l3,"wor");
    strReplace_L(&l1,l3,l4);
    printf("------��l1�е�'wor'�滻Ϊ'o'------\n");
    printString_L(l1);

    //�����Ĳ���
    strAssign_L(&l3,"How ");
    strInsert_L(&l1,5,l3);
    printf("------��l1�в���'How'------\n");
    printString_L(l1);

    //������ɾ��
    strDelete_L(&l1,9,3);
    printf("------ɾ��l1�е�'old'------\n");
    printString_L(l1);

    //��������
    destoryString(&l1);
    destoryString(&l2);
    destoryString(&l3);
    destoryString(&l4);
}