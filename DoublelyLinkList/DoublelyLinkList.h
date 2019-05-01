//
// Created by longx on 2019/1/25.
//

#ifndef DOUBLELYLINKLIST_DOUBLELYLINKLIST_H
#define DOUBLELYLINKLIST_DOUBLELYLINKLIST_H

/** 数据域定义 */
typedef struct {
    int id;
    char *data;
}ElementType;

/** 双向链表的结点，包含一个数据域，两个指针域 */
typedef struct doublelyLinkNode{
    ElementType data;
    //指向前缀结点
    struct doublelyLinkNode * prev;
    //指向后继结点
    struct doublelyLinkNode * next;
}DoublelyLinkNode;

/** 双向链表（头结点） */
typedef struct doublelyLinkList{
    //结点数量
    int length;
    //指向下一节点
    DoublelyLinkNode * next;
}DoublelyLinkList;

/**
 * 初始化双向链表
 * @param dlList 要操作的双链表
 * @return 初始化成功，返回头结点指针；初始化失败，返回NULL
 */
DoublelyLinkList * InitDoublelyLinkList(DoublelyLinkList * dlList);

/**
 * 释放双链表
 * @param dlList 要操作的双链表
 */
void FreeDoublelyLinkList(DoublelyLinkList * dlList);

/**
 * 置空双链表
 * @param dlList 要操作的双链表
 */
void EmptyeDoublelyLinkList(DoublelyLinkList * dlList);

/**
 * 向双向链表中的指定位置插入元素
 * @param dlList 要操作的双链表
 * @param pos 插入的位置
 * @param element 插入的元素
 * @return 插入成功，返回插入位置的结点指针；插入失败，返回NULL。
 */
DoublelyLinkNode * InsertDoublelyLinkList(DoublelyLinkList * dlList,int pos,ElementType element);

/**
 * 删除指定位置的元素
 * @param dlList 要操作的双链表
 * @param pos 要删除元素的位置
 * @return 删除成功，返回删除的元素，删除失败，返回空元素({0,NULL})。
 */
ElementType DeleteDoublelyLinkList(DoublelyLinkList * dlList,int pos);

/**
 * 打印双向链表的所有元素
 * @param dlList 要操作的双链表
 */
void PrintDoublelyLinkList(DoublelyLinkList * dlList);
#endif //DOUBLELYLINKLIST_DOUBLELYLINKLIST_H
