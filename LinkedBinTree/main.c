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

    printf("�������ṹ:\n");
    printf("         A         \n");
    printf("      /     \\          \n");
    printf("     B       C        \n");
    printf("   /   \\   /   \\       \n");
    printf("  D     E F     G     \n");

    //printf("����������: ");
    tree.root = (TreeNode *)malloc(sizeof(TreeNode));
    //CreateBinTree(tree.root);
    TestCreateBinTree(tree.root,nodeArray);

    //ǰ�����
    printf("ǰ��������:\n");
    PreOrderTraverse(tree.root);
    //�������
    printf("\n����������:\n");
    MiddleOrderTraverse(tree.root);

    //�ǵݹ��������
    printf("\n�ǵݹ��������:\n");
    MiddleOrderTraverse_Re(tree.root);

    //�������
    printf("\n�������:\n");
    PostOrderTraverse(tree.root);

    //�������
    printf("\n�������:\n");
    ZOrderTraverse(tree.root);

    free(tree.root);
    tree.root = NULL;

}