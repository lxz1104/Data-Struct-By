//
// Created by longx on 2019/2/2.
//

#include "SeqString.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//初始化堆串
void InitString_HeapString(HString * str)
{
    str->length = 0;
    str->ch = NULL;
}

//为堆串赋值
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
        printf("分配内存失败！\n");
        exit(OVERFLOW);
    }
    for (int i = 0; i < len; ++i) {
        str->ch[i] = chars[i];
    }
    str->ch[len] = '\0';
    str->length = len;
    return SUCCESS;
}

//打印堆串
void PrintHeapString(HString * str)
{
    if(IsEmpty_HeapString(str))
    {
        printf("堆字符为空！\n");
        str->length = 0;
        return;
    }
    for (int i = 0; i < str->length; ++i) {
        printf("%c",str->ch[i]);
    }
}

//销毁堆串
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

//堆串复制
Status StrCopy_HeapString(HString * destStr,HString * srcStr)
{
    //判断目标字符串是否为空
    if(!IsEmpty_HeapString(destStr))
    {
        DelHeapString(destStr);
    } else
    {
        InitString_HeapString(destStr);
    }
    if(IsEmpty_HeapString(srcStr))
    {
        printf("要复制的字符串内容为空，复制失败！\n");
        return ERROR;
    }
    destStr->ch = (char *)malloc(sizeof(char) * srcStr->length);
    if(!destStr->ch)
    {
        printf("分配内存失败！\n");
        exit(OVERFLOW);
    }
    strcpy(destStr->ch,srcStr->ch);
    destStr->length = srcStr->length;
    return SUCCESS;
}

//判断堆串是否为空
Status IsEmpty_HeapString(HString * str)
{
    if(str->length == 0 || !str->ch)
    {
        str->length = 0;
        return TRUE;
    }
    return FLASE;
}

//堆串大小比较
Status StrCompare_HeapString(HString * str1,HString * str2)
{
    //先比较长度
    if(str1->length > str2->length)
    {
        return GT;
    } else if(str1->length < str2->length)
    {
        return LT;
    }
    //比较第一个不同的字符
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

//连接堆串
Status StrConcat_HeapString(HString * destStr,HString * srcStr)
{
    if(IsEmpty_HeapString(srcStr))
    {
        printf("要连接的字符串内容为空，连接失败！\n");
        return ERROR;
    }
    if(destStr->ch)
    {
        b
        destStr->ch = (char *)realloc(destStr->ch, sizeof(char) * (destStr->length + srcStr->length));
        if(!destStr->ch)
        {
            printf("分配内存失败！\n");
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

//截取字符串
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
        printf("分配内存失败！\n");
        exit(OVERFLOW);
    }
    for (int i = 0; i < len; ++i) {
        destStr->ch[i] = srcStr->ch[pos - 1 + i];
    }
    destStr->length = len;
    return SUCCESS;
}

//查找子串
int FindSubstr_HeapString(HString * parent,HString * child,int pos)
{
    /**
     * 不停从父串中截取与子串相同的字符串与子串进行比较
     */
    if(pos < 1)
    {
        printf("pos取值非法！\n");
        return -1;
    }
    //记录起始位置
    int i = pos;
    HString * subStr = (HString *)malloc(sizeof(HString));
    if(!subStr)
    {
        printf("内存分配失败！\n");
        exit(OVERFLOW);
    }
    InitString_HeapString(subStr);
    while (i + child->length - 1 <= parent->length)
    {
        //截取子串
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

//删除任意位置字符
Status StrDelete_HeapString(HString * str,int pos,int len)
{
    if(pos < 1 || pos + len -1 > str->length || len < 1)
    {
        printf("pos值非法!\n");
        return ERROR;
    }
    if(IsEmpty_HeapString(str))
    {
        printf("字符串为空，删除失败！\n");
        return ERROR;
    }
    //执行删除操作
    for (int i = pos - 1; i + len < str->length; ++i) {
        str->ch[i] = str->ch[i + len];
    }
    str->length -= len;
    str->ch[str->length] = '\0';
    //缩小分配的内存空间
    str->ch = (char *)realloc(str->ch,sizeof(char) * str->length);
    if(!str->ch)
    {
        printf("内存分配失败!\n");
        exit(OVERFLOW);
    }
    return SUCCESS;
}

//在制定位置插入字符串
Status StrInsert_HeapString(HString * str,int pos,HString * insert)
{
    if(pos < 1 || pos > str->length + 1)
    {
        printf("pos值非法!\n");
        return ERROR;
    }
    if(IsEmpty_HeapString(str))
    {
        printf("字符串为空，插入失败！\n");
        return ERROR;
    }
    str->ch = (char *)realloc(str->ch,sizeof(char) * (str->length + insert->length));
    //为插入内容空出位置
    for (int i = str->length - 1; i >= pos - 1; --i) {
        str->ch[i + insert->length] = str->ch[i];
    }
    //插入每个字符
    for (int i = 0; i < insert->length; ++i) {
        str->ch[pos - 1 + i]  = insert->ch[i];
    }
    str->length += insert->length;
    str->ch[str->length] = '\0';
    return SUCCESS;
}

//字符串替换
Status StrReplace_HeapString(HString * str,HString * olderStr,HString * newStr)
{
    if(IsEmpty_HeapString(str) || IsEmpty_HeapString(olderStr) || IsEmpty_HeapString(newStr))
    {
        return ERROR;
    }
    //从第一个位置查找oldeStr的位置
    int  pos = FindSubstr_HeapString(str,olderStr,1);
    //判断是否存在指定的子串
    while (pos != -1)
    {
        StrDelete_HeapString(str,pos,olderStr->length);
        StrInsert_HeapString(str,pos,newStr);
        pos += newStr->length;
        pos = FindSubstr_HeapString(str,olderStr,pos);
    }
    return SUCCESS;
}