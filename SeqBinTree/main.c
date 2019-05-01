#include "SeqTree.h"
#include <stdio.h>

void TestSeqTree();

int main() {
    TestSeqTree();
    return 0;
}

void TestSeqTree()
{
    SeqTree tree;
    InitSeqTree(tree);
    CreateSeqTree(tree,0);
    PrintSeqTree(tree);
    printf("树的结点总数为：%d\n",GetSeqTreeLength(tree));
    printf("树的深度为:%d\n",GetSeqTreeDepth(tree));
    getchar();
    fflush(stdin);
}