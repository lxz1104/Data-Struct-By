//
// Created by longx on 2019/3/19.
//

#ifndef LINEARLIST_LINEARLIST_H
#define LINEARLIST_LINEARLIST_H

#include <iostream>

template<class T>
class LinearList{
public:
//    LinearList(int num):n(num){}
    virtual bool IsEmpty() const = 0;
    virtual int Length() const = 0;
    virtual bool Find(int i,T & x) const = 0;
    virtual bool Insert(int i,T x) = 0;
    virtual int Search(T x) const = 0;
    virtual bool Delete(int i) = 0;
    virtual bool Update(int i,T x) = 0;
    virtual void Output(std::ostream & out) const = 0;
    virtual ~LinearList() = default;

protected:
    int n;
};

#endif //LINEARLIST_LINEARLIST_H
