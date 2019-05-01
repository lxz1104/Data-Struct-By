//
// Created by longx on 2019/3/4.
//

#include "ParentTree.h"

#include <stdio.h>
#include <stdlib.h>

//初始化结构
void InitPTree(PTree * tree)
{
    if(!tree)
    {
        printf("Init failed!\n");
        return;
    }
    tree->root = -1;
    tree->length = 0;
}

//销毁树
void DestroyPTree(PTree * tree)
{
    if(tree)
    {
        free(tree);
        tree = NULL;
    }
}

//构造树
void CreateTree(PTree * tree)
{
    printf("请输入结点个数:");
    if(scanf("%d",&(tree->length)) == 0)
    {
        printf("请输入正整数!\n");
        tree->length = 0;
        //return;
    }
    fflush(stdin);
    if(tree->length <= 0 || tree->length > MAX_TREE_SIZE)
    {
        printf("结点树范围出错!\n");
        fflush(stdin);
        tree->length = 0;
        return;
    }

    printf("----输入结点的值和双亲的序号----\n");

    tree->root = 0;
    int parentPos = 0;

    for (int i = tree->root; i < tree->length; ++i) {

        ElementType * element = (ElementType *)malloc(sizeof(ElementType));
        if(!element)
        {
            printf("malloc failed!\n");
            exit(-1);
        }
        element->id = i + 1;
        printf("请输入第%d个结点的值: ",i + 1);
        scanf("%s",element->name);
        fflush(stdin);
        tree->node[i].data = *element;
        printf("请输入第%d个结点的双亲位置: ",i + 1);
        scanf("%d",&parentPos);
        fflush(stdin);
        //为结点赋值
        AssignPTree(&(tree->node[i]),parentPos,*element);

    }
    //根结点双亲位置设为-1
    tree->node[tree->root].parent = -1;
    printf("创建成功!数的长度为:%d\n",tree->length);

}

//为树节点赋值
void AssignPTree(PNode * node,int parent,ElementType data)
{
    node->data = data;
    node->parent = parent;
}

//打印树的所有结点
void PrintPTree(PTree * tree)
{
    if(IsEmpty(tree))
    {
        printf("树结点为空，打印失败！\n");
        return;
    }
    printf("结点总数为:%d\n",tree->length);

    for (int i = 0; i < tree->length; ++i) {
        printf("{结点双亲的下标 = %d, 结点数据域: [%d,%s]}\n",
                tree->node[i].parent,tree->node[i].data.id,tree->node[i].data.name);
    }
}

//判断数是否为空
int IsEmpty(PTree * tree)
{
    return (tree->root == -1 || tree->length == 0) ? tree->length = 0, 1 : 0;
}