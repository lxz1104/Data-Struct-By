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
        printf("超出了数组的最大容量[%d]，初始化失败！\n",MAX_SIZE);
        return;
    }
    seqList->length = 0;
    for (int i = 0; i < length; ++i) {
        //每次循环都在下标为i的位置插入一个元素
        InsertElement(seqList,i,element[i]);
    }
    
}

void InsertElement(SeqList *seqList,int index,ElementType element)
{
    //1、验证插入后元素空间是否超过MAX_SIZE
    //2、index的值是否合法，index∈[0,MAX_SIZE - 1]
    //3、插入的index应该在length内
    //4、从第length-1下标开始，前面的一个元素赋值给后面一个元素

    if(seqList->length + 1 > MAX_SIZE) {
        printf("数组已满，插入失败！\n");
        return;
    }
    if(index < 0 || index > MAX_SIZE - 1) {
        printf("index下标不合法,插入失败！合法范围:[0,%d]\n", MAX_SIZE - 1);
        return;
    }
    if(index > seqList->length) {
        printf("插入的下标超过当前数组的长度，插入失败！length = %d\n", seqList->length);
        return;
    }
    //开始插入元素
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
        printf("index下标不合法,插入失败！合法范围:[0,%d]\n", MAX_SIZE - 1);
        return NULL;
    }
    //1、找到要删除的元素
    //2、从指定位置删除，后面一个元素赋值给前面一个元素
    //3、顺序表总长度-1
    ElementType * delElement = (ElementType*)malloc(sizeof(ElementType));
    *delElement = *FindElement(seqList,index);
    for (int i = index; i < seqList->length; ++i) {
        seqList->datas[i] = seqList->datas[i + 1];
    }
    seqList->length--;
    return delElement; //使用完后需要进行free
}

ElementType * FindElement(SeqList *seqList,int index)
{
    if(index < 0 || index > MAX_SIZE - 1)
    {
        printf("index下标不合法,插入失败！合法范围:[0,%d]\n", MAX_SIZE - 1);
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