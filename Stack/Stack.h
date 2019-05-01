//
// Created by longx on 2019/1/25.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

/**
 * 栈(Stack)是仅限定在表尾插入和删除操作的线性表（LIFO结构）。
 * - 允许插入和删除的一段称为栈顶(top),另一端称为栈底(bottom)。
 * - 不含任何元素的栈称为空栈
 * 特点:
 * - 先进后出
 * - 后出先进
 * 常见操作:
 * - 栈的插入操作，称为进栈(压栈、入栈、push)。
 * - 栈的删除操作。称为出栈(弹栈、pop)。
 */

 /**
  * 利用数组实现顺序栈
  */


 //栈的最大长度
#define MAX_SIZE 10
//空栈
#define EMPTY_STACK -1
//压栈成功
#define PUSH_SUCCESS 1
//压栈失败
#define PUSH_FAILURE 0



/** 定义数据元素结构 */
typedef struct {
    int id;
    char *name;
}ElementType;

/** 定义顺序栈结构 */
typedef struct seqStack{
    //数据域
    ElementType element[MAX_SIZE];
    //栈顶（数组的下标）
    int top;
    //当前栈的元素个数
    int length;
}SeqStack;

/**
 * 初始化栈
 * @param seqStack 要操作的栈
 */
void InitSeqStack(SeqStack * seqStack);

/**
 * 向栈中压入元素
 * @param seqStack 要操作的栈
 * @param element 要压人栈中的数据元素
 * @return 压栈成功，返回PUSH_SUCCESS；压栈失败，返回PUSH_FAILURE。
 */
int PushSeqStack(SeqStack * seqStack,ElementType element);

/**
 * 出栈
 * @param seqStack 要操作的栈
 * @return 出栈成功，返回出栈的元素；出栈失败，返回空元素({0,NULL})
 */
ElementType PopSeqStack(SeqStack * seqStack);

/**
 * 清空栈
 * @param seqStack 要操作的栈
 */
void ClearSeqStack(SeqStack * seqStack);

/**
 * 打印栈的所有元素
 * @param seqStack 要操作的栈
 */
void PrintSeqStack(SeqStack * seqStack);

/**
 * 获取栈顶元素
 * @param seqStack 要操作的栈
 * @return 出栈成功，返回出栈的元素；出栈失败，返回空元素({0,NULL})
 */
ElementType GetSeqStackTop(SeqStack * seqStack);

/**
 * 获取栈的元素个数
 * @param seqStack 要操作的栈
 * @return 栈的元素个数
 */
int GetSeqStackLength(SeqStack * seqStack);
#endif //STACK_STACK_H
