//
// Created by longx on 2019/1/24.
//

#ifndef CIRCULARNODE_CIRCULARNODE_H
#define CIRCULARNODE_CIRCULARNODE_H

/**
 * 循环链表
 * 特点：
 * 1.带有头结点的循环链表，尾节点的指针域同样指向第一个结点，而不是头结点。
 * head->node1->node2->...->nodeN->node1
 * 优点:
 * 能够通过任意结点往后遍历整个链表结构。
 */

/** 定义数据域 */
typedef struct {
    int id;
    char *str;
}ElemType;

/** 定义循环链表的结点 */
typedef struct cirularNode{
    //数据域
    ElemType data;
    //指向下一个结点的指针域
    struct cirularNode *next;
}CirularNode,*pCirularNode;

/** 循环链表的结构 */
typedef struct cirularLinkList{
    //指向第一个结点的指针，头指针
    CirularNode *next;
    //链表长度
    int length;
}CirularLinkList;

/**
 * 初始化循环链表(创建循环链表)
 * @param clList 要操作的链表
 * @return 初始化成功，返回头结点；初始化失败，返回NULL。
 */
CirularLinkList * InitCirularLinkList(CirularLinkList * clList);

/**
 * 在循环链表的指定位置插入元素
 * @param clList 要操作的循环链表
 * @param pos 要插入的位置
 * @param element 要插入的数据
 * @return 插入成功，返回插入位置结点；插入失败，返回NULL。
 */
pCirularNode InsertCirularLinkList(CirularLinkList * clList,int pos,ElemType element);


/**
 * 根据元素内容返回对应的结点指针
 * @param clList 要操作的循环链表
 * @param element 要查找的元素
 * @return 查找成功，返回对应的结点指针；查找失败，返回NULL。
 */
pCirularNode FindCirularLinkListNode(CirularLinkList *clList,ElemType element);

/**
 * 根据位置删除链表的对应结点
 * @param clList 要操作的循环链表
 * @param pos 要删除结点的位置
 * @return 删除成功，返回删除的元素。
 */
ElemType DeleteCirularLinkListNode(CirularLinkList *clList,int pos);

/**
 * 打印循环链表的所有结点
 * @param clList 要打印的循环链表
 */
void PrintCirularLinkList(CirularLinkList * clList);

/**
 * 根据某个节点遍历整个链表
 * @param clList 要操作的循环链表
 * @param node 遍历的起始结点
 */
void PrintCirularLinkListByNode(CirularLinkList * clList,CirularNode * node);
#endif //CIRCULARNODE_CIRCULARNODE_H
