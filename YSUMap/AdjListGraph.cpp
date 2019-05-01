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

//���캯��
AdjListGraph::AdjListGraph(){

    printf("����������ͼ�Ķ�������");
    cin >> this->vexCount;
    printf("������ߵ�������");
    cin >>  this->edgeCount;
    printf("�������붥�����Ϣ\n");
    for (int i = 0; i < this->vexCount; ++i) {
        printf("����%d��",i + 1);
        cin >> this->vexes[i].vex;
        //��ʼ���ڽӱ������ÿ�
        this->vexes[i].firstEdge = nullptr;
        this->vexes[i].firstArc = nullptr;
    }

    printf("�����붥����ڽӵ���Ϣ�������ڽӱ�\n");
    string vex1,vex2;
    for (int i = 0; i < this->edgeCount; ++i) {
        //��¼�����Ȩֵ
        unsigned int value = 0;
        printf("���㣺");
        cin >> vex1;
        printf("�ڽӵ㣺");
        cin >> vex2;
        printf("Ȩֵ��");
        cin >> value;

        //������������ڶ��������е�����
        int x = LocateVex_AdjList(vex1);
        int y = LocateVex_AdjList(vex2);
        if(x == -1 || y == -1){
            return;
        }

        //�����½��
        Node * edgeNode = new Node(x,value,this->vexes[y].firstEdge, nullptr);
        assert(edgeNode != nullptr);
//        edgeNode->adjVex = x;
//        edgeNode->nextEdge = this->vexes[y].firstEdge;
//        edgeNode->weight = 0;
        this->vexes[y].firstEdge = edgeNode;

        //�Գ���
        edgeNode = new Node(y,value,this->vexes[x].firstEdge, nullptr);
//        edgeNode->adjVex = y;
//        edgeNode->nextEdge = this->vexes[x].firstEdge;
//        edgeNode->weight = 0;
        this->vexes[x].firstEdge = edgeNode;

    }
}

//��������
AdjListGraph::~AdjListGraph(){
    printf("\n�ڽӱ�\n");
    for (int i = 0; i < this->vexCount; ++i) {
        VexNode vNode = this->vexes[i];
        cout << "����: " << vNode.vex;
        Node *eNode = vNode.firstEdge;
        while (eNode) {
            printf(" -> %s", this->vexes[eNode->adjVex].vex);
            eNode = eNode->nextEdge;
        }
        cout << endl;
    }

    cout << "��������~" << endl;
}

//����ĳ�������ڶ��������е��±�
int AdjListGraph::LocateVex_AdjList(std::string & vex){
    //�������������
    for (auto it = this->vexes.begin(); it != this->vexes.end() ; ++it) {
        if(it->vex == vex){

            return int(it - this->vexes.begin());
        }
    }
    return -1;
}