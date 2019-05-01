//
// Created by longx on 2019/1/24.
//

#ifndef SEQUENCELIST_SEQUENCELIST_H
#define SEQUENCELIST_SEQUENCELIST_H

//定义数据元素最多个数
#define MAX_SIZE 1024

//定义数据元素
typedef struct {
    int id;
    char *data;
}ElementType;

//定义顺序表结构
typedef struct {
    //顺序表中的数据元素集合
    ElementType datas[MAX_SIZE];
    //当前顺序表中的元素个数
    int length;
}SeqList;

/**
 * 初始化链表
 * @param seqList 要初始化的顺序表
 * @param elementType 初始化时要添加的元素内容数组
 * @param length 初始化时添加的元素个数
 */
void InitList(SeqList *seqList,ElementType *element, int length);

/**
 * 向顺序表中的index下标处插入某个元素
 * @param seqList 执行插入操作的顺序表
 * @param index 要插入的位置的下标
 * @param element 要插入的元素
 */
void InsertElement(SeqList *seqList,int index,ElementType element);

/**
 * 删除顺序表中指定下标的元素
 * @param seqList 要操作的顺序表
 * @param index 要删除元素的下标
 * @return 返回删除的元素，如果删除失败，返回NULL
 */
ElementType * DeleteElement(SeqList *seqList,int index);

/**
 * 查找指定下标的元素
 * @param seqList 要操作的顺序表
 * @param index 要返回元素的下标
 * @return 返回指定下标的元素，如果查找失败，返回NULL
 */
ElementType * FindElement(SeqList *seqList,int index);

/**
 * 查找指定元素的下标
 * @param seqList 要操作的顺序表
 * @param element 要查找的元素
 * @return 返回指定元素的下标，若查找失败，返回-1
 */
int FindIndex(SeqList *seqList, const ElementType * element);

/**
 * 为顺序表排序
 * @param seqList 要操作的顺序表
 */
void SortList(SeqList *seqList);

/**
 * 打印顺序表中的所有元素
 * @param seqList 要打印的顺序表
 */
void PrintList(SeqList *seqList);
#endif //SEQUENCELIST_SEQUENCELIST_H
