//
// Created by longx on 2019/1/24.
//

#include "StaticLinkList.h"

#include <stdio.h>
#include <stdlib.h>

void InitStaticLinkList(StaticLinkList slList)
{
    for(int i = 0;i < MAX_SIZE_SSL;++i)
    {
        slList[i].next = i + 1;
        slList[i].data.data = NULL;
        slList[i].data.id = 0;
    }
    //将最后一个结点置空
    slList[MAX_SIZE_SSL - 1].next = 0;
    //将备用的链表的尾结点置空
    slList[MAX_SIZE_SSL - 2].next = 0;
}

int InsertStaticLinkList(StaticLinkList slList,int pos,ElementType element)
{
    //判断位置是否合法
    if(pos < 1 || pos > GetStaticLinkListLength(slList) + 1)
    {
        printf("位置不合法，插入失败！\n");
        return INSERT_ERROR;
    }
    //拿到第一个元素的下标
    int cursor = MAX_SIZE_SSL - 1;
    //判断cursor的范围是否合法
    //分配内存
    int newIndex = mallocSSL(slList);
    if(newIndex != MALLOCSSL_ERROR)
    {
        slList[newIndex].data = element;
        //找到newIndex的前缀结点
        for (int i = 1; i <= pos - 1; ++i) {
            cursor = slList[cursor].next;
        }
        slList[newIndex].next = slList[cursor].next;
        slList[cursor].next = newIndex;
        return INSERT_SUCCESS;
    }
    return INSERT_ERROR;
}

int GetStaticLinkListLength(StaticLinkList slList)
{
    int count = 0;
    int cursor = slList[MAX_SIZE_SSL - 1].next;
    while (cursor)
    {
        //游标后移
        cursor = slList[cursor].next;
        count++;
    }
    return count;
}

int mallocSSL(StaticLinkList slList)
{
    //拿到第一个空闲结点的下标（备用链表）
    int cursor = slList[0].next;
    if(cursor)
    {
        slList[0].next = slList[cursor].next;

    }
    return cursor;
}

int DeleteStaticLinkList(StaticLinkList slList,int pos)
{
    //判断位置是否合法
    if(pos < 1 || pos > GetStaticLinkListLength(slList) + 1)
    {
        printf("位置不合法，删除失败！\n");
        return DELETE_ERROR;
    }
    int cursor = MAX_SIZE_SSL - 1;
    //获取删除位置的前缀结点
    for (int i = 1; i < pos - 1; ++i) {
        cursor = slList[cursor].next;
    }
    int delIndex = slList[cursor].next;
    slList[cursor].next = slList[delIndex].next;
    slList[delIndex].data.data = NULL;
    slList[delIndex].data.id = 0;
    //释放空间
    freeSSL(slList,delIndex);
    return DELETE_SUCCESS;
}

void freeSSL(StaticLinkList slList,int index)
{
    //将下标为index的空闲结点回收到备用链表
    slList[index].next = slList[0].next;
    //0号元素的next结点指向备用结点的第一个结点，表示index结点空闲
    slList[0].next = index;
}

void  PrintStaticLinkList(StaticLinkList slList)
{
    printf("数组下标     数据域                  next(游标)\n");
    for (int i = 0; i < MAX_SIZE_SSL; ++i) {
        printf("[%d]       {id = %d,data = %s}   [%d]\n",i,slList[i].data.id,slList[i].data.data,slList[i].next);
    }
}

void PrintStaticLinkListByInsert(StaticLinkList slList)
{
    printf("数组下标     数据域                  next(游标)\n");
    int cursor = slList[MAX_SIZE_SSL - 1].next;
    while (cursor)
    {
        printf("[%d]       {id = %d,data = %s}   [%d]\n",cursor,slList[cursor].data.id,slList[cursor].data.data,slList[cursor].next);
        //游标后移
        cursor = slList[cursor].next;
    }
}