//
// Created by longx on 2019/2/15.
//

#ifndef SEQBINTREE_SEQTREE_H
#define SEQBINTREE_SEQTREE_H

/**
 * 树的顺序储存结构：一般用于完全二叉树或满二叉树，这样可以避免内存浪费
 */

/** 一位数组能存放的最大结点数 */
#define MAX_SIZE 1024

/** 定义顺序数类型 */
typedef char SeqTree[MAX_SIZE + 1];

/**
 * 初始化空二叉树
 * @param tree 要操作的二叉树
 */
void InitSeqTree(SeqTree tree);

/**
 * 创建完全二叉树
 * @param tree 要操作的二叉树
 * @param i 数组中的下标
 */
void CreateSeqTree(SeqTree tree, int i);

/**
 * 打印二叉树
 * @param tree 要操作的二叉树
 */
void PrintSeqTree(SeqTree tree);

/**
 * 获取根节点元素
 * @param tree 要操作的二叉树
 * @return 根节点元素
 */
char GetSeqTreeRoot(SeqTree tree);

/**
 * 获取树的结点总数
 * @param tree 要操作的二叉树
 * @return 结点总数
 */
int GetSeqTreeLength(SeqTree tree);

/**
 * 获取树的深度
 * @param tree 要操作的二叉树
 * @return 二叉树的深度
 */
int GetSeqTreeDepth(SeqTree tree);
#endif //SEQBINTREE_SEQTREE_H
