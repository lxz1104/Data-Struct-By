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
    //�����һ������ÿ�
    slList[MAX_SIZE_SSL - 1].next = 0;
    //�����õ������β����ÿ�
    slList[MAX_SIZE_SSL - 2].next = 0;
}

int InsertStaticLinkList(StaticLinkList slList,int pos,ElementType element)
{
    //�ж�λ���Ƿ�Ϸ�
    if(pos < 1 || pos > GetStaticLinkListLength(slList) + 1)
    {
        printf("λ�ò��Ϸ�������ʧ�ܣ�\n");
        return INSERT_ERROR;
    }
    //�õ���һ��Ԫ�ص��±�
    int cursor = MAX_SIZE_SSL - 1;
    //�ж�cursor�ķ�Χ�Ƿ�Ϸ�
    //�����ڴ�
    int newIndex = mallocSSL(slList);
    if(newIndex != MALLOCSSL_ERROR)
    {
        slList[newIndex].data = element;
        //�ҵ�newIndex��ǰ׺���
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
        //�α����
        cursor = slList[cursor].next;
        count++;
    }
    return count;
}

int mallocSSL(StaticLinkList slList)
{
    //�õ���һ�����н����±꣨��������
    int cursor = slList[0].next;
    if(cursor)
    {
        slList[0].next = slList[cursor].next;

    }
    return cursor;
}

int DeleteStaticLinkList(StaticLinkList slList,int pos)
{
    //�ж�λ���Ƿ�Ϸ�
    if(pos < 1 || pos > GetStaticLinkListLength(slList) + 1)
    {
        printf("λ�ò��Ϸ���ɾ��ʧ�ܣ�\n");
        return DELETE_ERROR;
    }
    int cursor = MAX_SIZE_SSL - 1;
    //��ȡɾ��λ�õ�ǰ׺���
    for (int i = 1; i < pos - 1; ++i) {
        cursor = slList[cursor].next;
    }
    int delIndex = slList[cursor].next;
    slList[cursor].next = slList[delIndex].next;
    slList[delIndex].data.data = NULL;
    slList[delIndex].data.id = 0;
    //�ͷſռ�
    freeSSL(slList,delIndex);
    return DELETE_SUCCESS;
}

void freeSSL(StaticLinkList slList,int index)
{
    //���±�Ϊindex�Ŀ��н����յ���������
    slList[index].next = slList[0].next;
    //0��Ԫ�ص�next���ָ���ý��ĵ�һ����㣬��ʾindex������
    slList[0].next = index;
}

void  PrintStaticLinkList(StaticLinkList slList)
{
    printf("�����±�     ������                  next(�α�)\n");
    for (int i = 0; i < MAX_SIZE_SSL; ++i) {
        printf("[%d]       {id = %d,data = %s}   [%d]\n",i,slList[i].data.id,slList[i].data.data,slList[i].next);
    }
}

void PrintStaticLinkListByInsert(StaticLinkList slList)
{
    printf("�����±�     ������                  next(�α�)\n");
    int cursor = slList[MAX_SIZE_SSL - 1].next;
    while (cursor)
    {
        printf("[%d]       {id = %d,data = %s}   [%d]\n",cursor,slList[cursor].data.id,slList[cursor].data.data,slList[cursor].next);
        //�α����
        cursor = slList[cursor].next;
    }
}