//
// Created by longx on 2019/2/15.
//

#ifndef LINKEDBINTREE_LINKEDBINTREE_H
#define LINKEDBINTREE_LINKEDBINTREE_H

/** 前序遍历
 * 1.若二叉树为空，则空操作
 * 2.不为空
 *  - 访问根结点
 *  - 前序遍历左子树
 *  - 前序遍历右子树
 * 特点:
 * 第一位一定是根结点。
 * 根 -> 左 -> 右
 */

/** 中序遍历
 * 1.若二叉树为空，则空操作
 * 2.不为空
 *  - 中序遍历左子树
 *  - 访问根结点
 *  - 中序遍历左子树
 * 特点：
 *  根结点必在中间
 * 左 -> 根 -> 右
 */

/** 后序遍历
 * 1.若二叉树为空，则为空操作
 * 2.不为空
 * - 后序遍历左子树
 * - 后序遍历右子树
 * - 访问根结点
 * 特点：
 *  最后一位一定是根结点
 *  左 -> 右 -> 根
 */

//字符最大长度
#define MAXSIZE 1024

/** 结点元素结构 */
typedef struct {
    int id;
    char name[MAXSIZE];
}ElementType;

typedef struct treeNode{
    //数据域
    ElementType data;
    //左子树（左孩子）
    struct treeNode * left;
    //右子树（右孩子）
    struct treeNode * right;
}TreeNode;

/** 二叉链表 */
typedef struct {
    //二叉链根节点
    TreeNode * root;
    //结点总数
    int nodeCount;
    //二叉链表的深度
    int depth;
    //直径:从叶结点到叶结点的最长路径
    int diameter;

}BinTree;

/**
 * 初始化空二叉树
 * @param tree 要操作的二叉树
 */
void InitBinTree(BinTree * tree);

/**
 * 构造二叉树:需要事先在外部为结点分配内存
 * @param root 根节点
 * @return 创建失败，返回0；创建成功，返回1
 */
int CreateBinTree(TreeNode * root);

/**
 * 数组构造二叉树:需要事先在外部为结点分配内存
 * @param root 根节点
 * @return 创建失败，返回0；创建成功，返回1
 */
int TestCreateBinTree(TreeNode * root,char ** nodeArray);

/**
 * 前序遍历（先序遍历，前序周游，先根遍历）
 * @param node 访问的节点
 */
void PreOrderTraverse(TreeNode * node);

/**
 * 中序遍历（中序周游，中根遍历）
 * @param node 访问的节点
 */
void MiddleOrderTraverse(TreeNode * node);

/**
 * 非递归方式中序遍历(使用链栈)
 * @param node 访问的节点
 */
void MiddleOrderTraverse_Re(TreeNode * node);

/**
 *后序遍历
 * @param node 访问的根结点
 */
void PostOrderTraverse(TreeNode * node);

/**
 * 层序遍历(队列)
 * @param node 访问的根结点
 */
void ZOrderTraverse(TreeNode * node);

#endif //LINKEDBINTREE_LINKEDBINTREE_H
