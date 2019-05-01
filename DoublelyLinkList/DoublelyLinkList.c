//
// Created by longx on 2019/1/25.
//

#include "DoublelyLinkList.h"

#include <stdlib.h>
#include <stdio.h>

//���ƽ��
#define MoveToNext(node) node = node->next

DoublelyLinkList * InitDoublelyLinkList(DoublelyLinkList * dlList)
{
    dlList = (DoublelyLinkList *)malloc(sizeof(DoublelyLinkList));
    if(!dlList)
    {
        printf("�����ڴ�ʧ��!!!\n");
        return NULL;
    }
    dlList->next = NULL;
    dlList->length = 0;
    return dlList;
}

void FreeDoublelyLinkList(DoublelyLinkList * dlList)
{
    if(dlList)
    {
        EmptyeDoublelyLinkList(dlList);
        free(dlList);
        dlList = NULL;
    }
}

void EmptyeDoublelyLinkList(DoublelyLinkList * dlList)
{
    DoublelyLinkNode * node = dlList->next;
    DoublelyLinkNode * temp = NULL;
    if(!node || dlList->length == 0)
    {
        printf("������Ϊ�գ��ÿ�ʧ�ܣ�\n");
        dlList->length = 0;
        return;
    }
    for(int i = 0; node && i < dlList->length; ++i)
    {
        temp = node;
        MoveToNext(node);
        free(temp);
    }
    dlList->next = NULL;
    dlList->length = 0;
}

DoublelyLinkNode * InsertDoublelyLinkList(DoublelyLinkList * dlList,int pos,ElementType element) {
    /**
     * ����ʱ�����������
     * 1.������ǵ�һ��Ԫ�أ�pos = 1
     * node->prev = NULL
     * node->next = dlList->next;
     * dlList->next = node;
     * node->next->prev = node;
     * 2.�����λ�ò��ǵ�һ��Ԫ�أ�pos �� (1,length + 1]
     * node->prev = preNode;
     * if(preNode->next != NULL) { preNode->next->prev = node; }
     * node->next = preNode->next;
     * preNode->next = node;
     */

    if(pos < 1 || pos > dlList->length + 1)
    {
        printf("λ�÷Ƿ������ʧ�ܣ�pos �� (1,%d]\n",dlList->length + 1);
        return NULL;
    }

    //�����սڵ�
    DoublelyLinkNode *node = (DoublelyLinkNode *) malloc(sizeof(DoublelyLinkNode));
    if(!node)
    {
        printf("�����ڴ�ʧ��!!!\n");
        return NULL;
    }
    node->next = NULL;
    node->prev = NULL;
    node->data = element;

    //�ڵ�һ��λ�ò�����
    if(1 == pos)
    {
        if(dlList->length == 0)
        {
            dlList->next = node;
            dlList->length++;
            return node;
        }
        node->next = dlList->next;
        dlList->next = node;
        node->next->prev = node;
        dlList->length++;
        return node;
    } else if(pos > 1)
    {
        //����Ĳ��ǵ�һ��Ԫ��
        //����λ�õ�ǰ׺���
        DoublelyLinkNode *preNode = dlList->next;
        for (int i = 1; preNode && i < pos - 1; ++i) {
            MoveToNext(preNode);
        }
        if(preNode)
        {
            node->prev = preNode;
            //���ǰ׺���ǿգ�Ϊ�ձ�ʾû�к�̽�㣩
            if(preNode->next)
            {
                //������λ�ô���ǰ׺���ָ���½��
                preNode->next->prev = node;
            }
            node->next = preNode->next;
            preNode->next = node;
            dlList->length++;
            return preNode->next;
        }
    }
    free(node);
    node = NULL;
    return NULL;
}

ElementType DeleteDoublelyLinkList(DoublelyLinkList * dlList,int pos)
{
    ElementType element = {0,NULL};
    if(!dlList->next || dlList->length == 0)
    {
        printf("����Ϊ�գ�ɾ��ʧ�ܣ�\n");
        dlList->length = 0;
        return element;
    }
    if(pos < 1 || pos > dlList->length)
    {
        printf("λ�÷Ƿ���ɾ��ʧ�ܣ�pos �� (1,%d]\n",dlList->length);
        return element;
    }
    if(1 == pos)
    {
        DoublelyLinkNode * node = dlList->next;
        if(node)
        {
            element = node->data;
            dlList->next = node->next;
            //����еڶ����
            if(node->next)
            {
                node->next->prev = NULL;
            }
            free(node);
            dlList->length--;
        }
    } else if(pos > 1)
    {
        DoublelyLinkNode * node = dlList->next;
        for (int i = 1; node && i < pos; ++i) {
            MoveToNext(node);
        }
        if(node)
        {
            element = node->data;
            if(node->next)
            {
                node->next->prev = node->prev;
            }
            node->prev->next = node->next;
            free(node);
            dlList->length--;
        }
    }
    return element;
}

void PrintDoublelyLinkList(DoublelyLinkList * dlList)
{
    DoublelyLinkNode * node = dlList->next;
    if(!node || dlList->length == 0)
    {
        printf("����Ϊ�գ���ӡʧ�ܣ�\n");
        dlList->length = 0;
        return;
    }
    for (int i = 0; i < dlList->length; ++i) {
        printf("<%d>:[%s]\n",node->data.id,node->data.data);
        MoveToNext(node);
    }
}