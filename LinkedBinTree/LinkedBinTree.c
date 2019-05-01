//
// Created by longx on 2019/2/15.
//

#include "LinkedStack.h"
#include "LinkedQueue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/** 结点id */
static int id = 0;
/** 访问nodeArray数组用的下标 */
static int nodeIndex = 0;

//层序遍历
void ZOrderTraverse(TreeNode * node)
{
    LinkedQueue queue;
    InitLinkedQueue(&queue);
    //根结点入队
    EnterQueue(&queue,node);
    while (!IsLinkedQueueEmpty(&queue))
    {
        node = DeQueue(&queue);
        printf("{%d, %s}-",node->data.id,node->data.name);
        if(node->left != NULL)
        {
            EnterQueue(&queue,node->left);
        }
        if(node->right != NULL)
        {
            EnterQueue(&queue,node->right);
        }
    }
    DestroyQueue(&queue);
}

//后序遍历
void PostOrderTraverse(TreeNode * node)
{
    if(node)
    {
        //遍历左子树
        PostOrderTraverse(node->left);
        //遍历右子树
        PostOrderTraverse(node->right);
        //访问根结点
        printf("{%d, %s}-",node->data.id,node->data.name);
    }
}

//非递归中序遍历
void MiddleOrderTraverse_Re(TreeNode * node)
{
    /**
     * 思路：
     * 1.根据中序遍历的顺序，对任意结点来说，优先访问左孩子，而左孩子又可以看做一个根结点
     * 2.继续访问左孩子结点为空的结点，按照相同规则访问右孩子
     */

    LinkedStack linkedStack;
    InitLinkedStack(&linkedStack);
    TreeNode * root = node;
    //currNode用来保存每个出栈的结点指针
    TreeNode * currNode = (TreeNode *)malloc(sizeof(TreeNode));
    //用来确保释放掉currNode分配的内存。
    TreeNode * tempNode = currNode;

    while (root || !IsLinkedStackEmpty(&linkedStack))
    {
        if(root)
        {
            Push(&linkedStack,root);
            root = root->left;
        } else{
            Pop(&linkedStack,&currNode);
            printf("{%d, %s}-",currNode->data.id,currNode->data.name);
            root = currNode->right;
        }
    }

    free(tempNode);
    tempNode = NULL;
    DestoryLinkedStack(&linkedStack);
}

//中序遍历
void MiddleOrderTraverse(TreeNode * node)
{
    if(node){
        //遍历左子树
        MiddleOrderTraverse(node->left);
        //访问根结点
        printf("{%d, %s}-",node->data.id,node->data.name);
        //遍历右子树
        MiddleOrderTraverse(node->right);
    }
}

//前序遍历
void PreOrderTraverse(TreeNode * node)
{
    //先访问根结点，然后遍历左子树，最后遍历右子树
    if(node)
    {
        //访问根结点
        printf("{%d, %s}-",node->data.id,node->data.name);
        //遍历左子树
        PreOrderTraverse(node->left);
        //遍历右子树
        PreOrderTraverse(node->right);
    }
}

int TestCreateBinTree(TreeNode * root,char ** nodeArray) {
    if (!root) {
        return 0;
    }
    //用户输入的结点名
    char inputName[MAXSIZE] = {'\0'};

    strcpy(inputName, nodeArray[nodeIndex++]);

    //用户输入回车表示结束当前子树创建
    if (strcmp(inputName, "#") == 0) {
        return 0;
    }

    //创建当前结点
    root->data.id = ++id;
    strcpy(root->data.name, inputName);

    //为左右结点分配内存
    root->left = (TreeNode *) malloc(sizeof(TreeNode));
    root->right = (TreeNode *) malloc(sizeof(TreeNode));
    if (!root->left || !root->right) {
        printf("内存分配失败!\n");
        exit(EXIT_FAILURE);
    }

    //分别递归创建左子树和右子树
    if (TestCreateBinTree(root->left,nodeArray) == 0) {
        free(root->left);
        root->left = NULL;
    }
    if (TestCreateBinTree(root->right,nodeArray) == 0){
        free(root->right);
        root->right = NULL;
    }
    return 1;
}

//初始化空二叉树
void InitBinTree(BinTree * tree)
{
    tree->root = NULL;
    tree->depth = 0;
    tree->diameter = 0;
    tree->nodeCount = 0;
}

//构造二叉树
int CreateBinTree(TreeNode * root)
{
    if(!root){
        return 0;
    }
    //用户输入的结点名
    char inputName[MAXSIZE] = {'\0'};
    gets(inputName);
    fflush(stdin);
    //用户输入回车表示结束当前子树创建
    if(strcmp(inputName,"\0") == 0){
        return 0;
    }

    //创建当前结点
    root->data.id = ++id;
    strcpy(root->data.name,inputName);

    //为左右结点分配内存
    root->left = (TreeNode *)malloc(sizeof(TreeNode));
    root->right = (TreeNode *)malloc(sizeof(TreeNode));
    if(!root->left || !root->right)
    {
        printf("内存分配失败!\n");
        exit(EXIT_FAILURE);
    }

    //分别递归创建左子树和右子树
    printf("左结点:");
    if(CreateBinTree(root->left) == 0)
    {
        free(root->left);
        root->left = NULL;
    }
    printf("右结点:");
    if(CreateBinTree(root->right) == 0)
    {
        free(root->right);
        root->right = NULL;
    }
    return 1;
}