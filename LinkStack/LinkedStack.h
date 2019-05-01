//
// Created by longx on 2019/1/25.
//

#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

/**
 * 链栈（链栈是一个以top为头结点、从栈顶向栈底的单链表。）
 * - 链栈的结构与链表相似
 * - 插入与删除等操作都在链表头部
 */

//压栈成功
#define PUSH_SUCCESS 1
//压栈失败
#define PUSH_FAILURE 0
//出栈成功
#define POP_SUCCESS 1
#define POP_FAILURE 0

/** 数据元素结构 */
typedef struct {
    int id;
    char *name;
}ElementType;

/** 链栈结点结构 */
typedef struct linkedStackNode{
    //结点中保存的数据元素
    ElementType data;
    struct linkedStackNode * next;
}LinkedStackNode;

/** 链栈结构 */
typedef struct linkedStack{
    LinkedStackNode * top;
    int length;
}LinkedStack;

/**
 * 初始化链栈
 * @param linkedStack 要操作的链栈
 */
void InitLinkedStack(LinkedStack ** linkedStack);

/**
 * 压栈
 * @param linkedStack 要操作的链栈
 * @param element 要压入栈中的元素
 * @return 压栈成功，返回PUSH_SUCCESS，压栈失败，返回PUSH_FAILURE.
 */
int PushLinkedStack(LinkedStack * linkedStack,ElementType element);

/**
 * 出栈
 * @param linkedStack 要操作的链栈
 * @param element 接收出栈的元素
 * @return 出栈成功，返回POP_SUCCESS，出栈失败，返回POP_FAILURE.
 */
int PopLinkedStack(LinkedStack * linkedStack,ElementType * element);

/**
 * 清空栈
 * @param linkedStack 要操作的链栈
 */
void ClearLinkedStack(LinkedStack * linkedStack);

/**
 * 销毁栈
 * @param linkedStack 要操作的链栈
 */
void DestoryLinkedStack(LinkedStack ** linkedStack);

/**
 * 打印栈中的元素
 * @param linkedStack 要操作的链栈
 */
void PrintLinkedStack(LinkedStack * linkedStack);
#endif //LINKEDSTACK_H
