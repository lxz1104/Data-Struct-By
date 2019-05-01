//
// Created by longx on 2019/1/24.
//

#include "SequenceList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void InitList(SeqList *seqList,ElementType *element, int length)
{
    if(length > MAX_SIZE)
    {
        printf("������������������[%d]����ʼ��ʧ�ܣ�\n",MAX_SIZE);
        return;
    }
    seqList->length = 0;
    for (int i = 0; i < length; ++i) {
        //ÿ��ѭ�������±�Ϊi��λ�ò���һ��Ԫ��
        InsertElement(seqList,i,element[i]);
    }
    
}

void InsertElement(SeqList *seqList,int index,ElementType element)
{
    //1����֤�����Ԫ�ؿռ��Ƿ񳬹�MAX_SIZE
    //2��index��ֵ�Ƿ�Ϸ���index��[0,MAX_SIZE - 1]
    //3�������indexӦ����length��
    //4���ӵ�length-1�±꿪ʼ��ǰ���һ��Ԫ�ظ�ֵ������һ��Ԫ��

    if(seqList->length + 1 > MAX_SIZE) {
        printf("��������������ʧ�ܣ�\n");
        return;
    }
    if(index < 0 || index > MAX_SIZE - 1) {
        printf("index�±겻�Ϸ�,����ʧ�ܣ��Ϸ���Χ:[0,%d]\n", MAX_SIZE - 1);
        return;
    }
    if(index > seqList->length) {
        printf("������±곬����ǰ����ĳ��ȣ�����ʧ�ܣ�length = %d\n", seqList->length);
        return;
    }
    //��ʼ����Ԫ��
    for (int i = seqList->length -1; i >= index; --i) {
        seqList->datas[i + 1] = seqList->datas[i];
    }
    seqList->datas[index] = element;
    seqList->length++;
}

ElementType * DeleteElement(SeqList *seqList,int index)
{
    if(index < 0 || index > MAX_SIZE - 1)
    {
        printf("index�±겻�Ϸ�,����ʧ�ܣ��Ϸ���Χ:[0,%d]\n", MAX_SIZE - 1);
        return NULL;
    }
    //1���ҵ�Ҫɾ����Ԫ��
    //2����ָ��λ��ɾ��������һ��Ԫ�ظ�ֵ��ǰ��һ��Ԫ��
    //3��˳����ܳ���-1
    ElementType * delElement = (ElementType*)malloc(sizeof(ElementType));
    *delElement = *FindElement(seqList,index);
    for (int i = index; i < seqList->length; ++i) {
        seqList->datas[i] = seqList->datas[i + 1];
    }
    seqList->length--;
    return delElement; //ʹ�������Ҫ����free
}

ElementType * FindElement(SeqList *seqList,int index)
{
    if(index < 0 || index > MAX_SIZE - 1)
    {
        printf("index�±겻�Ϸ�,����ʧ�ܣ��Ϸ���Χ:[0,%d]\n", MAX_SIZE - 1);
        return NULL;
    }
    ElementType * element;
    element = &seqList->datas[index];
    return element;
}

int FindIndex(SeqList *seqList, const ElementType * element)
{
    for (int i = 0; i < seqList->length; ++i) {
        if(element->id == seqList->datas[i].id && !strcmp(element->data,seqList->datas[i].data))
        {
            return i;
        }
    }
    return -1;
}

void SortList(SeqList *seqList)
{
    for(int i  = 0;i < seqList->length;++i)
    {
        for(int j = i + 1;j < seqList->length;++j)
        {
            if(seqList->datas[i].id > seqList->datas[j].id)
            {
                ElementType temp;
                temp = seqList->datas[j];
                seqList->datas[j] = seqList->datas[i];
                seqList->datas[i] = temp;
            }
        }
    }
}

void PrintList(SeqList *seqList)
{
    for (int i = 0; i < seqList->length; ++i) {
        printf("<%d>:[%s]\n",seqList->datas[i].id,seqList->datas[i].data);
    }
}