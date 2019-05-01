//
// Created by longx on 2019/2/15.
//

#include "SeqTree.h"

#include <stdio.h>
#include <math.h>

/** 初始化空二叉树 */
void InitSeqTree(SeqTree tree)
{
    for (int i = 0; i <= MAX_SIZE; ++i) {
        tree[i] = '\0';
    }
}

//创建完全二叉树
void CreateSeqTree(SeqTree tree, int i)
{
    char ch;
    if(i == 0)
    {
        printf("根节点:");
    }
    scanf("%c",&ch);
    fflush(stdin);

    //若输入^号表示结束当前结点的输入
    if(ch == '^')
    {
        tree[i] = '\0';
        return;
    }

    tree[i] = ch;
    //结点输入完毕后，让用户输入左孩子和右孩子
    printf("左孩子结点:");
    //递归调用
    CreateSeqTree(tree,2 * i + 1);

    printf("右孩子结点");
    CreateSeqTree(tree,2 * (i + 1));
}

//打印二叉树
void PrintSeqTree(SeqTree tree)
{
    int count = 0;
    int node_count = GetSeqTreeLength(tree);
    for (int i = 0; i < MAX_SIZE; ++i) {
        if(tree[i] != '\0')
        {
            printf("%c  ",tree[i]);
            count++;
            if(count == node_count)
            {
                break;
            }
        }
    }
    printf("\n");
}

//获取根节点元素
char GetSeqTreeRoot(SeqTree tree)
{
    if(GetSeqTreeLength(tree) == 0)
    {
        return '\0';
    }
    return tree[0];
}

//获取树的结点总数
int GetSeqTreeLength(SeqTree tree)
{
    int len = 0;
    for (int i = 0; i < MAX_SIZE; ++i) {
        if(tree[i] == '\0')
        {
            continue;
        }
        ++len;
    }
    return len;
}

//获取树的深度
int GetSeqTreeDepth(SeqTree tree)
{
    //深度为k的二叉树最多有2^k-1个结点
    int depth = 0;  //深度
    int len = GetSeqTreeLength(tree);

    while ((int)pow(2,depth) - 1 < len){
        ++depth;
    }
    return depth;
}