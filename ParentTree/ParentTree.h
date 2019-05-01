//
// Created by longx on 2019/3/4.
//

#ifndef PARENTTREE_PARENTTREE_H
#define PARENTTREE_PARENTTREE_H

/**
 * 数的双亲表示法
 * 此方式与二叉树的最大不同是其结点组成为：数据域 + 双亲（根结点）位置/下标
 */

#define MAX_TREE_SIZE 1024

/** 数据域结构 */
typedef struct {
    int id;
    char * name;
}ElementType;

/** 双亲结点 */
typedef struct pNode{
    ElementType data;   //数据域
    int parent;         //双亲下标/位置
}PNode;

/** 双亲表示法的树的结构 */
typedef struct {
    PNode node[MAX_TREE_SIZE];    //数的结点数组
    int root;                     //根结点位置
    int length;                   //当前结点数
}PTree;

/**
 * 初始化空树
 * @param tree 要操作的树的指针
 */
void InitPTree(PTree * tree);

/**
 * 构造树
 * @param tree 要操作的树的指针(需在传参前使用InitPTree()初始化)
 */
void CreateTree(PTree * tree);

/**
 * 为树结点赋值
 * @param node 要进行赋值的结点指针
 * @param parent 要进行赋值的结点的父结点(根结点)的位置（下标）
 * @param data 要进行赋值的数据
 */
void AssignPTree(PNode * node,int parent,ElementType data);

/**
 * 判断数是否为空
 * @param tree 要操作的树的指针(需在传参前使用InitPTree()初始化)
 * @return 为空，返回1；不为空，返回0
 */
int IsEmpty(PTree * tree);

/**
 * 打印树的所有结点
 * @param tree 要操作的树的指针(需在传参前使用InitPTree()初始化)
 */
void PrintPTree(PTree * tree);

/**
 * 销毁树
 * @param tree 要操作的树的指针
 */
void DestroyPTree(PTree * tree);
#endif //PARENTTREE_PARENTTREE_H
