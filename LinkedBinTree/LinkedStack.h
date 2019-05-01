//
// Created by longx on 2019/2/15.
//

#ifndef LINKEDBINTREE_LINKEDSTACK_H
#define LINKEDBINTREE_LINKEDSTACK_H

#include "LinkedBinTree.h"

/** 栈结点 */
typedef struct stackNode{
    //数据域
    TreeNode * data;
    //指针域
    struct stackNode * next;
}StackNode;

typedef struct {
    //栈顶指针
    StackNode * top;
    //栈长度
    int length;
}LinkedStack;

/**
 * 初始化链栈
 * @param LStack 要操作的链栈
 */
void InitLinkedStack(LinkedStack * LStack);

/**
 * 入栈
 * @param LStack 要操作的链栈
 * @param node 要入栈的元素
 * @return 成功，返回1；失败，返回0
 */
int Push(LinkedStack * LStack,TreeNode * node);

/**
 * 出栈
 * @param LStack 要操作的链栈
 * @param node 接收出栈元素
 * @return 成功，返回1；失败，返回0
 */
int Pop(LinkedStack * LStack,TreeNode ** node);

/**
 * 判断栈是否为空
 * @param LStack 要操作的链栈
 * @return 为空，返回1；不为空，返回0
 */
int IsLinkedStackEmpty(LinkedStack * LStack);

/**
 * 清空栈
 * @param linkedStack 要操作的链栈
 */
void ClearLinkedStack(LinkedStack * LStack);
/**
 * 销毁栈
 * @param linkedStack 要操作的链栈
 */
void DestoryLinkedStack(LinkedStack * LStack);
#endif //LINKEDBINTREE_LINKEDSTACK_H
