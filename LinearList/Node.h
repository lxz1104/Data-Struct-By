//
// Created by longx on 2019/3/19.
//

#ifndef LINEARLIST_NODE_H
#define LINEARLIST_NODE_H

template <class T> class SingleList;
template <class T>
class Node{
private:
    T element;
    Node<T> * link;
    friend class SingleList<T>;
};

#endif //LINEARLIST_NODE_H
