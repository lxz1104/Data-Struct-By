#include "ParentTree.h"
#include <stdio.h>

void TestPTree();

int main() {
    TestPTree();
    return 0;
}

void TestPTree()
{
    PTree pTree;
    InitPTree(&pTree);
    CreateTree(&pTree);
    PrintPTree(&pTree);
    DestroyPTree(&pTree);
    getchar();
}