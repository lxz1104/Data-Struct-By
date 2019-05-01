//
// Created by longx on 2019/3/19.
//

#ifndef LINEARLIST_LINKEDLIST_H
#define LINEARLIST_LINKEDLIST_H

#include "LinearList.h"
#include "Node.h"

#define MoveToNext(node) node = node->link

template <class T>
class SingleList:public LinearList<T>
{
public:
    SingleList();
    ~SingleList();
    bool IsEmpty() const;
    int Length() const;
    bool Find(int i,T & x) const;
    bool Insert(int i,T x);
    int Search(T x) const;
    bool Delete(int i);
    bool Update(int i,T x);
    void Output(std::ostream & out) const;
    void Clear();

private:
    Node<T> * first;
};

template <class T>
SingleList<T>::SingleList()
{
    this->n = 0;
    this->first = nullptr;
}

template <class T>
SingleList<T>::~SingleList()
{
    Node<T> * p;
    while (this->first)
    {
        p = this->first->link;
        delete this->first;
        this->first = p;
    }
}

template <class T>
bool SingleList<T>::IsEmpty() const
{
    return this->n == 0;
}

template <class T>
int SingleList<T>::Length() const
{
    return this->n;
}

template <class T>
bool SingleList<T>::Find(int i,T & x) const
{
    if(i < 0 || i > this->n -1){
        std::cout << "Out of bounds" << std::endl;
        return false;
    }
    Node<T> * p = this->first;
    for (int j = 0; j < i; ++j) {
        MoveToNext(p);
    }
    x = p->element;
    return true;
}

template <class T>
bool SingleList<T>::Insert(int i,T x)
{
    if(i < -1 || i > this->n -1){
        std::cout << "Out of bounds" << std::endl;
        return false;
    }
    auto * q = new Node<T>;
    q->element = x;
    Node<T> * p = this->first;
    for (int j = 0; j < i; ++j) {
        MoveToNext(p);
    }
    if(i > -1)
    {
        q->link = p->link;
        p->link = q;
    } else{
        q->link = this->first;
        this->first = q;
    }
    this->n++;
    return true;
}

template <class T>
int SingleList<T>::Search(T x) const
{
    Node<T> * p = this->first;
    int j = 0;
    for (j = 0; p && p->element != x; ++j) {
        MoveToNext(p);
    }
    if(p)
    {
        return j;
    }
    return -1;
}

template <class T>
bool SingleList<T>::Delete(int i)
{
    if(!this->n){
        std::cout << "UnderFlow" << std::endl;
        return false;
    }
    if(i < 0 || i > this->n -1){
        std::cout << "Out of bounds" << std::endl;
        return false;
    }
    Node<T> * p = this->first,*q = this->first;
    for (int j = 0; j < i - 1; ++j) {
        MoveToNext(q);
    }
    if(i == 0){
        MoveToNext(this->first);
    } else
    {
        p = q->link;
        q->link = p->link;
    }
    delete p;
    this->n--;
    return true;
}

template <class T>
bool SingleList<T>::Update(int i,T x){
    if(i < 0 || i > this->n -1){
        std::cout << "Out of bounds" << std::endl;
        return false;
    }
    Node<T> * p = this->first;
    for (int j = 0; j < i; ++j) {
        MoveToNext(p);
    }
    p->element = x;
    return true;
}

template <class T>
void SingleList<T>::Output(std::ostream & out) const
{
    Node<T> * p = this->first;
    while (p)
    {
        out << "element: " << p->element << "   ";
        out << "link: " << p->link << "   ";
        out << "address: " << &p->element;
        out << std::endl;
        MoveToNext(p);
    }
    out << std::endl;
}

template <class T>
void SingleList<T>::Clear()
{

}

#endif //LINEARLIST_LINKEDLIST_H
