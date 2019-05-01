//
// Created by longx on 2019/3/4.
//

#include "ParentTree.h"

#include <stdio.h>
#include <stdlib.h>

//��ʼ���ṹ
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

//������
void DestroyPTree(PTree * tree)
{
    if(tree)
    {
        free(tree);
        tree = NULL;
    }
}

//������
void CreateTree(PTree * tree)
{
    printf("�����������:");
    if(scanf("%d",&(tree->length)) == 0)
    {
        printf("������������!\n");
        tree->length = 0;
        //return;
    }
    fflush(stdin);
    if(tree->length <= 0 || tree->length > MAX_TREE_SIZE)
    {
        printf("�������Χ����!\n");
        fflush(stdin);
        tree->length = 0;
        return;
    }

    printf("----�������ֵ��˫�׵����----\n");

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
        printf("�������%d������ֵ: ",i + 1);
        scanf("%s",element->name);
        fflush(stdin);
        tree->node[i].data = *element;
        printf("�������%d������˫��λ��: ",i + 1);
        scanf("%d",&parentPos);
        fflush(stdin);
        //Ϊ��㸳ֵ
        AssignPTree(&(tree->node[i]),parentPos,*element);

    }
    //�����˫��λ����Ϊ-1
    tree->node[tree->root].parent = -1;
    printf("�����ɹ�!���ĳ���Ϊ:%d\n",tree->length);

}

//Ϊ���ڵ㸳ֵ
void AssignPTree(PNode * node,int parent,ElementType data)
{
    node->data = data;
    node->parent = parent;
}

//��ӡ�������н��
void PrintPTree(PTree * tree)
{
    if(IsEmpty(tree))
    {
        printf("�����Ϊ�գ���ӡʧ�ܣ�\n");
        return;
    }
    printf("�������Ϊ:%d\n",tree->length);

    for (int i = 0; i < tree->length; ++i) {
        printf("{���˫�׵��±� = %d, ���������: [%d,%s]}\n",
                tree->node[i].parent,tree->node[i].data.id,tree->node[i].data.name);
    }
}

//�ж����Ƿ�Ϊ��
int IsEmpty(PTree * tree)
{
    return (tree->root == -1 || tree->length == 0) ? tree->length = 0, 1 : 0;
}