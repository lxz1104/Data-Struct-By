//
// Created by longx on 2019/2/2.
//

#ifndef MYSTRING_SEQSTRING_H
#define MYSTRING_SEQSTRING_H

/**
 * 串的顺序结构
 */

#include "StatusLib.h"


/** 串的堆式顺序存储结构 */
typedef struct {
    //如果是非空串，那么就按照指定长度分配内存。
    char * ch;
    //串的当前长度
    int length;
}HString;

/**
 * 初始化堆串
 * @param str 要操作的堆串
 */
void InitString_HeapString(HString * str);

/**
 * 为字符串赋值
 * @param Str 要操作的堆串
 * @param chars 要赋值给字符串的内容
 * @return 返回对应状态码
 */
Status StrAssign_HeapString(HString * str,char * chars);

/**
 * 打印堆串
 * @param str 要操作的堆串
 */
void PrintHeapString(HString * str);

/**
 * 销毁堆串(清空堆串)
 * @param str 要操作的堆串
 */
void DelHeapString(HString * str);

/**
 * 赋值堆串
 * @param destStr 要复制到的目标堆串
 * @param srcStr 要复制的堆串
 * @return 返回状态码
 */
Status StrCopy_HeapString(HString * destStr,HString * srcStr);

/**
 * 判断字符串是否为空
 * @param str 要操作的堆串
 * @return 为空，返回TRUE；不为空，返回FLASE
 */
Status IsEmpty_HeapString(HString * str);

/**
 * 判断两个堆串的大小关系
 * @param str1 要比较的堆串1
 * @param str2 要比较的堆串2
 * @return str1 > str2,返回GT；str1 < str2,返回LT；str1 = str2，返回EQ
 */
Status StrCompare_HeapString(HString * str1,HString * str2);

/**
 * 连接堆串
 * @param destStr 要连接到的目标堆串
 * @param srcStr 要连接的堆串
 * @return 返回状态码
 */
Status StrConcat_HeapString(HString * destStr,HString * srcStr);

/**
 * 截取指定长度的堆串
 * @param destStr 截取的结果
 * @param str 要截取的目标字符串
 * @param pos 截取的起始位置（从1开始）
 * @param len 截取的长度(len ∈ [1,len - pos + 1])
 * @return 返回状态码
 */
Status SubString_HeapString(HString * destStr,HString * srcStr,int pos,int len);

/**
 * 查找子串在父串中第一次出现的位置(匹配子串)
 * @param parent 父串
 * @param child 子串
 * @param pos 开始查找的位置
 * @return 若查找到返回，第一次出现的位置；未查找到，返回-1
 */
int FindSubstr_HeapString(HString * parent,HString * child,int pos);

/**
 * 删除堆串中任意位置、任意长度的内容
 * @param str 要操作的堆串
 * @param pos 删除操作的起始位置（从1开始）
 * @param len 删除的长度
 * @return 返回状态码
 */
Status StrDelete_HeapString(HString * str,int pos,int len);

/**
 * 向指定位置插入串
 * @param str 插入到的目标串
 * @param pos 插入的位置
 * @param insert 插入的串
 * @return 返回状态码
 */
Status StrInsert_HeapString(HString * str,int pos,HString * insert);

/**
 * 堆串的替换
 * @param str 要操作的堆串
 * @param olderStr 待替换的字符串
 * @param newStr 用来替换的新字符串
 * @return 返回状态码
 */
Status StrReplace_HeapString(HString * str,HString * olderStr,HString * newStr);

#endif //MYSTRING_SEQSTRING_H
