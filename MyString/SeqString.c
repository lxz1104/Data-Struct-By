//
// Created by longx on 2019/2/2.
//

#include "SeqString.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��ʼ���Ѵ�
void InitString_HeapString(HString * str)
{
    str->length = 0;
    str->ch = NULL;
}

//Ϊ�Ѵ���ֵ
Status StrAssign_HeapString(HString * str,char * chars)
{
    int len  = strlen(chars);
    if(!len)
    {
        return ERROR;
    }
    if(!IsEmpty_HeapString(str))
    {
        DelHeapString(str);
    } else
    {
        InitString_HeapString(str);
    }
    str->ch = (char *)malloc(sizeof(char) * len);
    if(!str->ch)
    {
        printf("�����ڴ�ʧ�ܣ�\n");
        exit(OVERFLOW);
    }
    for (int i = 0; i < len; ++i) {
        str->ch[i] = chars[i];
    }
    str->ch[len] = '\0';
    str->length = len;
    return SUCCESS;
}

//��ӡ�Ѵ�
void PrintHeapString(HString * str)
{
    if(IsEmpty_HeapString(str))
    {
        printf("���ַ�Ϊ�գ�\n");
        str->length = 0;
        return;
    }
    for (int i = 0; i < str->length; ++i) {
        printf("%c",str->ch[i]);
    }
}

//���ٶѴ�
void DelHeapString(HString * str)
{
    if(!str->ch)
    {
        return;
    }
    free(str->ch);
    str->ch = NULL;
    str->length = 0;
}

//�Ѵ�����
Status StrCopy_HeapString(HString * destStr,HString * srcStr)
{
    //�ж�Ŀ���ַ����Ƿ�Ϊ��
    if(!IsEmpty_HeapString(destStr))
    {
        DelHeapString(destStr);
    } else
    {
        InitString_HeapString(destStr);
    }
    if(IsEmpty_HeapString(srcStr))
    {
        printf("Ҫ���Ƶ��ַ�������Ϊ�գ�����ʧ�ܣ�\n");
        return ERROR;
    }
    destStr->ch = (char *)malloc(sizeof(char) * srcStr->length);
    if(!destStr->ch)
    {
        printf("�����ڴ�ʧ�ܣ�\n");
        exit(OVERFLOW);
    }
    strcpy(destStr->ch,srcStr->ch);
    destStr->length = srcStr->length;
    return SUCCESS;
}

//�ж϶Ѵ��Ƿ�Ϊ��
Status IsEmpty_HeapString(HString * str)
{
    if(str->length == 0 || !str->ch)
    {
        str->length = 0;
        return TRUE;
    }
    return FLASE;
}

//�Ѵ���С�Ƚ�
Status StrCompare_HeapString(HString * str1,HString * str2)
{
    //�ȱȽϳ���
    if(str1->length > str2->length)
    {
        return GT;
    } else if(str1->length < str2->length)
    {
        return LT;
    }
    //�Ƚϵ�һ����ͬ���ַ�
    for (int i = 0; i < str1->length; ++i) {
        if(str1->ch[i] > str2->ch[i])
        {
            return GT;
        } else if(str1->ch[i] < str2->ch[i])
        {
            return LT;
        }
    }
    return EQ;
}

//���ӶѴ�
Status StrConcat_HeapString(HString * destStr,HString * srcStr)
{
    if(IsEmpty_HeapString(srcStr))
    {
        printf("Ҫ���ӵ��ַ�������Ϊ�գ�����ʧ�ܣ�\n");
        return ERROR;
    }
    if(destStr->ch)
    {
        b
        destStr->ch = (char *)realloc(destStr->ch, sizeof(char) * (destStr->length + srcStr->length));
        if(!destStr->ch)
        {
            printf("�����ڴ�ʧ�ܣ�\n");
            exit(OVERFLOW);
        }
        for (int i = srcStr->length; i >= 0; --i) {
            destStr->ch[destStr->length + i] = srcStr->ch[i];
        }
        destStr->length += srcStr->length;
        destStr->ch[destStr->length] = '\0';
        return SUCCESS;
    }
    StrCopy_HeapString(destStr,srcStr);
    return SUCCESS;
}

//��ȡ�ַ���
Status SubString_HeapString(HString * destStr,HString * srcStr,int pos,int len)
{
    InitString_HeapString(destStr);
    if(pos < 1 || pos > srcStr->length || len < 1 || pos + len - 1 > srcStr->length)
    {

        return ERROR;
    }
    destStr->ch = (char *)malloc(sizeof(char) * len);
    if(!destStr->ch)
    {
        printf("�����ڴ�ʧ�ܣ�\n");
        exit(OVERFLOW);
    }
    for (int i = 0; i < len; ++i) {
        destStr->ch[i] = srcStr->ch[pos - 1 + i];
    }
    destStr->length = len;
    return SUCCESS;
}

//�����Ӵ�
int FindSubstr_HeapString(HString * parent,HString * child,int pos)
{
    /**
     * ��ͣ�Ӹ����н�ȡ���Ӵ���ͬ���ַ������Ӵ����бȽ�
     */
    if(pos < 1)
    {
        printf("posȡֵ�Ƿ���\n");
        return -1;
    }
    //��¼��ʼλ��
    int i = pos;
    HString * subStr = (HString *)malloc(sizeof(HString));
    if(!subStr)
    {
        printf("�ڴ����ʧ�ܣ�\n");
        exit(OVERFLOW);
    }
    InitString_HeapString(subStr);
    while (i + child->length - 1 <= parent->length)
    {
        //��ȡ�Ӵ�
        SubString_HeapString(subStr,parent,i,child->length);
        if(StrCompare_HeapString(subStr,child) != EQ)
        {
            i++;
        } else
        {
            return i;
        }
    }
    free(subStr);
    return -1;
}

//ɾ������λ���ַ�
Status StrDelete_HeapString(HString * str,int pos,int len)
{
    if(pos < 1 || pos + len -1 > str->length || len < 1)
    {
        printf("posֵ�Ƿ�!\n");
        return ERROR;
    }
    if(IsEmpty_HeapString(str))
    {
        printf("�ַ���Ϊ�գ�ɾ��ʧ�ܣ�\n");
        return ERROR;
    }
    //ִ��ɾ������
    for (int i = pos - 1; i + len < str->length; ++i) {
        str->ch[i] = str->ch[i + len];
    }
    str->length -= len;
    str->ch[str->length] = '\0';
    //��С������ڴ�ռ�
    str->ch = (char *)realloc(str->ch,sizeof(char) * str->length);
    if(!str->ch)
    {
        printf("�ڴ����ʧ��!\n");
        exit(OVERFLOW);
    }
    return SUCCESS;
}

//���ƶ�λ�ò����ַ���
Status StrInsert_HeapString(HString * str,int pos,HString * insert)
{
    if(pos < 1 || pos > str->length + 1)
    {
        printf("posֵ�Ƿ�!\n");
        return ERROR;
    }
    if(IsEmpty_HeapString(str))
    {
        printf("�ַ���Ϊ�գ�����ʧ�ܣ�\n");
        return ERROR;
    }
    str->ch = (char *)realloc(str->ch,sizeof(char) * (str->length + insert->length));
    //Ϊ�������ݿճ�λ��
    for (int i = str->length - 1; i >= pos - 1; --i) {
        str->ch[i + insert->length] = str->ch[i];
    }
    //����ÿ���ַ�
    for (int i = 0; i < insert->length; ++i) {
        str->ch[pos - 1 + i]  = insert->ch[i];
    }
    str->length += insert->length;
    str->ch[str->length] = '\0';
    return SUCCESS;
}

//�ַ����滻
Status StrReplace_HeapString(HString * str,HString * olderStr,HString * newStr)
{
    if(IsEmpty_HeapString(str) || IsEmpty_HeapString(olderStr) || IsEmpty_HeapString(newStr))
    {
        return ERROR;
    }
    //�ӵ�һ��λ�ò���oldeStr��λ��
    int  pos = FindSubstr_HeapString(str,olderStr,1);
    //�ж��Ƿ����ָ�����Ӵ�
    while (pos != -1)
    {
        StrDelete_HeapString(str,pos,olderStr->length);
        StrInsert_HeapString(str,pos,newStr);
        pos += newStr->length;
        pos = FindSubstr_HeapString(str,olderStr,pos);
    }
    return SUCCESS;
}