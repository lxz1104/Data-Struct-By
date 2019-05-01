#include "LinkedBinTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void TestBinTree();

int main() {
    TestBinTree();
    return 0;
}

void TestBinTree()
{
    BinTree tree;
    InitBinTree(&tree);
    char * nodeArray[] = {"A","B","D","#","#","E","#","#","C","F","#","#","G","#","#"};

    printf("二叉树结构:\n");
    printf("         A         \n");
    printf("      /     \\          \n");
    printf("     B       C        \n");
    printf("   /   \\   /   \\       \n");
    printf("  D     E F     G     \n");

    //printf("请输入根结点: ");
    tree.root = (TreeNode *)malloc(sizeof(TreeNode));
    //CreateBinTree(tree.root);
    TestCreateBinTree(tree.root,nodeArray);

    //前序遍历
    printf("前序遍历结果:\n");
    PreOrderTraverse(tree.root);
    //中序遍历
    printf("\n中序遍历结果:\n");
    MiddleOrderTraverse(tree.root);

    //非递归中序遍历
    printf("\n非递归中序遍历:\n");
    MiddleOrderTraverse_Re(tree.root);

    //后序遍历
    printf("\n后序遍历:\n");
    PostOrderTraverse(tree.root);

    //层序遍历
    printf("\n层序遍历:\n");
    ZOrderTraverse(tree.root);

    free(tree.root);
    tree.root = NULL;

}