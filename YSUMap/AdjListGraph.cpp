//
// Created by longx on 2019/3/23.
//

#include "Graph.h"


#include <iostream>
#include <fstream>
#include <map>
#include <queue>
#include <cassert>
#include <cstdio>

using std::string;
using std::cout;
using std::endl;
using std::cin;

//构造函数
AdjListGraph::AdjListGraph(){

    printf("请输入无向图的顶点数：");
    cin >> this->vexCount;
    printf("请输入边的数量：");
    cin >>  this->edgeCount;
    printf("依次输入顶点的信息\n");
    for (int i = 0; i < this->vexCount; ++i) {
        printf("顶点%d：",i + 1);
        cin >> this->vexes[i].vex;
        //初始化邻接表，将边置空
        this->vexes[i].firstEdge = nullptr;
        this->vexes[i].firstArc = nullptr;
    }

    printf("请输入顶点和邻接点信息，构建邻接表\n");
    string vex1,vex2;
    for (int i = 0; i < this->edgeCount; ++i) {
        //记录输入的权值
        unsigned int value = 0;
        printf("顶点：");
        cin >> vex1;
        printf("邻接点：");
        cin >> vex2;
        printf("权值：");
        cin >> value;

        //获得两个顶点在顶点数组中的坐标
        int x = LocateVex_AdjList(vex1);
        int y = LocateVex_AdjList(vex2);
        if(x == -1 || y == -1){
            return;
        }

        //构造新结点
        Node * edgeNode = new Node(x,value,this->vexes[y].firstEdge, nullptr);
        assert(edgeNode != nullptr);
//        edgeNode->adjVex = x;
//        edgeNode->nextEdge = this->vexes[y].firstEdge;
//        edgeNode->weight = 0;
        this->vexes[y].firstEdge = edgeNode;

        //对称性
        edgeNode = new Node(y,value,this->vexes[x].firstEdge, nullptr);
//        edgeNode->adjVex = y;
//        edgeNode->nextEdge = this->vexes[x].firstEdge;
//        edgeNode->weight = 0;
        this->vexes[x].firstEdge = edgeNode;

    }
}

//析构函数
AdjListGraph::~AdjListGraph(){
    printf("\n邻接表：\n");
    for (int i = 0; i < this->vexCount; ++i) {
        VexNode vNode = this->vexes[i];
        cout << "顶点: " << vNode.vex;
        Node *eNode = vNode.firstEdge;
        while (eNode) {
            printf(" -> %s", this->vexes[eNode->adjVex].vex);
            eNode = eNode->nextEdge;
        }
        cout << endl;
    }

    cout << "析构调用~" << endl;
}

//返回某个顶点在顶点数组中的下标
int AdjListGraph::LocateVex_AdjList(std::string & vex){
    //正向迭代器遍历
    for (auto it = this->vexes.begin(); it != this->vexes.end() ; ++it) {
        if(it->vex == vex){

            return int(it - this->vexes.begin());
        }
    }
    return -1;
}