//
// Created by longx on 2019/3/22.
//

#ifndef YSUMAP_GRAPH_H
#define YSUMAP_GRAPH_H

#include <string>
#include <vector>
#include <array>

/** 定义最大顶点数 */
const int MAX_VERTEX = 100;

/**
 * 无向图抽象类型（虚基类）
 */


class AdjListGraph;    //无向图类


/**
 * 边/弧的结点类
 */
class Node{
private:
    int adjVex;                     //该边指向这条边邻接点的下标
    unsigned int weight;            //权重
    Node * nextEdge;                //指向下一条边结点的指针
    Node * nextArc;                 //指向下一个弧结点的指针
public:
    //默认构造
    Node():
        adjVex(0),weight(0),nextEdge(nullptr),nextArc(nullptr) {}
    //带参构造
    Node(int _adjVex,unsigned int _weight,Node * _nextEdge,Node * _nextArc):
        adjVex(_adjVex),weight(_weight),nextEdge(_nextEdge),nextArc(_nextArc) {}
    friend class AdjListGraph;
    friend class VexNode;
};

/**
 * 顶点结点类
 */
class VexNode{
private:
    std::string vex;             //顶点值
    Node * firstEdge;            //指向第一条边的指针
    Node * firstArc;             //指向第一条弧的指针
public:
    VexNode():
        firstArc(nullptr),firstEdge(nullptr) {}
    VexNode(std::string & _vex, Node * _firstEdge,Node * _firstArc):
            vex(_vex),firstArc(_firstEdge),firstEdge(_firstArc) {}
    friend class AdjListGraph;
};

/**
 * 无向图类
 */
class AdjListGraph{
public:
    //删除无用自生成函数
    AdjListGraph operator=(AdjListGraph &) = delete;
    AdjListGraph(const AdjListGraph &) = delete;
    //构造函数
    AdjListGraph();
    //析构函数
    ~AdjListGraph();

private:
    /**
     * 返回某个顶点在顶点数组中的下标
     * @param vex 要定位的顶点
     * @return 存在，返回下标（从0开始）；不存在，返回-1
     */
    int LocateVex_AdjList(std::string & vex);
private:
    std::array<VexNode,MAX_VERTEX>  vexes;       //邻接表数组
    int vexCount;                    //顶点数量
    int edgeCount;                   //图的边数
    int arcCount;                    //图的弧数
};



#endif //YSUMAP_GRAPH_H
