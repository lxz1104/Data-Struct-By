//
// Created by longx on 2019/2/11.
//

#ifndef LINKEDSTRING_LINKEDSTRING_H
#define LINKEDSTRING_LINKEDSTRING_H

#include "StatusLib.h"

/** 块大小的定义*/
#define BLOCK_SIZE 80 //块的长度决定了存储密度(串值所占的存储位/实际分配的存储位)，BLOCK_SIZE越大，存储密度越大

/** 定义块的结构 */
typedef struct block{
    //块的数据
    char ch[BLOCK_SIZE];
    //指向下一个块
    struct block * next;
}Blocks;

/** 串的链式储存结构 */
typedef struct {
    //串的头指针
    Blocks *head;
    //串的尾指针
    Blocks *tail;
    //串当前的长度
    unsigned int length;
}LString;

/**
 * 初始化链串
 * @param LinkedStr 要操作的链串
 */
void initString_L(LString * LinkedStr);

/**
 * 给链串添加内容
 * @param LinkedStr 要操作的链串
 * @param chs 要添加的内容
 * @return 添加成功，返回SUCCESS，添加失败，返回ERROR
 */
Status strAssign_L(LString * LinkedStr,char *chs);

/**
 * 复制链串
 * @param LinkedStr 要操作的链串
 * @param s 复制的目标链串
 * @return 复制成功，返回SUCCESS，复制失败，返回ERROR
 */
Status strCopy_L(LString * LinkedStr,LString * s);

/**
 * 判断链串是否为空
 * @param LinkedStr 要操作的链串
 * @return 为空，返回TRUE;不为空，返回FLASE
 */
Status IsEmpty_L(LString LinkedStr);

/**
 * 比较两个链串的大小
 * @param LinkedStr1 要比较的链串
 * @param LinkedStr2 要比较的链串
 * @return LinkedStr1 == LinkedStr2,返回0；LinkedStr1 > LinkedStr2,返回正数；LinkedStr1 < LinkedStr2返回负数
 */
Status strCompare_L(LString LinkedStr1,LString LinkedStr2);

/**
 * 计算链串长度
 * @param LinkedStr 要操作的链串
 * @return 链串LinkedStr长度
 */
unsigned int strLength_L(LString LinkedStr);

/**
 * 清空链串
 * @param LinkedStr 要操作的链串
 */
void clearString_L(LString * LinkedStr);

/**
 * 连接两个链串
 * @param NewStr 连接后的链串
 * @param s1 前一个链串
 * @param s2 后一个链串
 */
void strConcat_L(LString * NewStr,LString s1,LString s2);

/**
 * 截取链串
 * @param sub 截取的结果
 * @param LinkedStr 要截取的链串
 * @param pos 截取的起始位置（最小为1）
 * @param length 截取的长度（最小为1）
 * @return 状态码
 */
Status subString_L(LString * sub,LString LinkedStr,unsigned int pos,unsigned int length);

/**
 * 链串的子串匹配
 * @param parent 父串
 * @param child 子串
 * @param pos 匹配的起始位置
 * @return 匹配成功，返回子串第一个字符第一次出现的位置；匹配失败，
 */
unsigned int index_L(LString parent,LString child,unsigned int pos);

/**
 * 链串的替换
 * @param LinkedStr 要操作的链串
 * @param s1 父串中要被替换的部分
 * @param s2 用来替换的链串
 * @return 状态码
 */
Status strReplace_L(LString * LinkedStr,LString s1,LString s2);

/**
 * 在指定位置插入字符
 * @param LinkedStr 要操作的链串
 * @param pos 要插入的位置（最小为1）
 * @param L 要插入的链串
 * @return 状态码
 */
Status strInsert_L(LString * LinkedStr, unsigned int pos,LString L);

/**
 * 删除链串中指定位置指定长度的内容
 * @param LinkedStr 要操作的链串
 * @param pos 要删除的起始位置（最小为1）
 * @param length 要删除的长度
 * @return 状态码
 */
Status strDelete_L(LString * LinkedStr, unsigned int pos, unsigned int length);

/**
 * 销毁链串
 * @param LinkedStr 要销毁的链串
 */
void destoryString(LString * LinkedStr);

/**
 * 打印链串的内容
 * @param LinkedStr 要操作的链串
 */
void printString_L(LString LinkedStr);
#endif //LINKEDSTRING_LINKEDSTRING_H
