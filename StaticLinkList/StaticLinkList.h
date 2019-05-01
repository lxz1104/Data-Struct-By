//
// Created by longx on 2019/1/24.
//

/**
 * 静态链表（游标表示法）
 * 特点:
 * 1.数组的第一元素的next游标用来存放第一个空闲结点的下标（备用链表的下标）
 * 2.数组的最后一个元素next用来保存最新插入一个的元素
 * 基本操作:
 * 1.初始化:每个元素的next都指向下一个元素
 * 2.插入数据:
 *  （1）.分配内存（malloc）：①.获得第一个空节点下标，②.赋值，③.将第一个元素(下标为0)的next指向第一个空节点的next.
 *  （2）.将最后一个结点(MAX_SIZE_SSL - 1)的next指向新插入元素的下标
 * 优点：
 * 可以不使用指针实现链表操作。
 */

#ifndef STATICLINKLIST_STATICLINKLIST_H
#define STATICLINKLIST_STATICLINKLIST_H

//静态链表长度
#define MAX_SIZE_SSL 5
//插入成功
#define INSERT_SUCCESS 1
//插入错误
#define INSERT_ERROR 0
//分配失败
#define MALLOCSSL_ERROR 0
//删除成功
#define DELETE_SUCCESS 1
//删除失败
#define DELETE_ERROR 0

/** 数据元素 */
typedef struct {
    int id;
    char *data;
}ElementType;

/** 定义静态链表*/
typedef struct {
    ElementType data;
    int next;
}StaticLinkList[MAX_SIZE_SSL];

/**
 * 初始化静态链表
 * @param slList 要初始化的静态链表
 */
void InitStaticLinkList(StaticLinkList slList);

/**
 * 向指定位置插入元素
 * @param slList 要操作的静态链表
 * @param pos 插入的位置
 * @param element 插入的元素
 * @return 插入成功，返回INSERT_SUCCESS；插入失败，返回INSERT_ERROR。
 */
int InsertStaticLinkList(StaticLinkList slList,int pos,ElementType element);

/**
 * 获取静态链表的长度
 * @param slList 要操作的静态链表
 * @return 返回静态链表的长度
 */
int GetStaticLinkListLength(StaticLinkList slList);

/**
 * 为静态链表分配一个空间的内存
 * @param slList 要操作的静态链表
 * @return 分配成功，返回空闲结点；分配失败，返回MALLOCSSL_ERROR。
 */
int mallocSSL(StaticLinkList slList);

/**
 * 删除链表中指定元素
 * @param slList 要操作的静态链表
 * @param pos 删除元素的位置
 * @return 删除成功，返回DELETE_SUCCESS；插入失败，返回DELETE_ERROR。
 */
int DeleteStaticLinkList(StaticLinkList slList,int pos);

/**
 * 回收原始数组中指定下标的空间
 * @param slList 要操作的静态链表
 * @param index 要回收元素的下标
 */
void freeSSL(StaticLinkList slList,int index);

/**
 * 打印静态链表的所有元素
 * @param slList 要操作的静态链表
 */
void  PrintStaticLinkList(StaticLinkList slList);

/**
 * 按插入顺序打印数据
 * @param slList 要操作的静态链表
 */
void PrintStaticLinkListByInsert(StaticLinkList slList);
#endif //STATICLINKLIST_STATICLINKLIST_H
