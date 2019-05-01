//
// Created by longx on 2019/3/19.
//

#ifndef LINEARLIST_SEQLIST_H
#define LINEARLIST_SEQLIST_H

#include "LinearList.h"

#include <cassert>

template <class T>
class SeqList:public LinearList<T>{
public:
    SeqList(int mSize):maxLength(mSize)
    {
        this->n = 0;
        this->elements = new T[maxLength];
        assert(this->elements != nullptr);
       // n = 0;
    }
    ~SeqList(){ delete[] this->elements; this->elements = nullptr; }

    bool IsEmpty() const;
    int Length() const;
    bool Find(int i,T & x) const;
    bool Insert(int i,T x);
    int Search(T x) const;
    bool Delete(int i);
    bool Update(int i,T x);
    void Output(std::ostream & out) const;
private:
    int maxLength;
    T * elements;
    //int n;
};

template <class T>
bool SeqList<T>::IsEmpty() const{
    return this->n == 0;
}

template <class T>
int SeqList<T>::Length() const{
    return this->n;
}

template <class T>
bool SeqList<T>::Find(int i,T & x) const{
    if(i < 0 || i > this->n - 1)
    {
        std::cout << "Out of Bounds" << std::endl;
        return false;
    }
    x = this->elements[i];
    return true;

}

template <class T>
bool SeqList<T>::Insert(int i,T x){
    if(i < -1 || i > this->n - 1){
        std::cout << "Out of bounds" << std::endl;
        return false;
    }
    if(this->n == this->maxLength){
        std::cout << "OverFlow" << std::endl;
        return false;
    }
    for (int j = this->n - 1; j > i; --j) {
        this->elements[j + 1] = this->elements[j];
    }
    elements[i + 1] = x;
    this->n++;
    return true;
}

template <class T>
int SeqList<T>::Search(T x) const{
    for(int j = 0; j < this->n;++j){
        if(this->elements[j] == x)
        {
            return j;
        }
    }
    return -1;
}

template <class T>
bool SeqList<T>::Delete(int i){
    if(!this->n){
        std::cout << "UnderFlow" << std::endl;
        return false;
    }
    if(i < 0 || i > this->n -1){
        std::cout << "Out of bounds" << std::endl;
        return false;
    }
    for (int j = i + 1; j < this->n; ++j) {
        this->elements[j - 1] = this->elements[j];
    }
    this->n--;
    return true;
}

template <class T>
bool SeqList<T>::Update(int i,T x){
    if(i < 0 || i > this->n -1){
        std::cout << "Out of bounds" << std::endl;
        return false;
    }
    this->elements[i] = x;
    return true;
}

template <class T>
void SeqList<T>::Output(std::ostream & out) const{
    for (int i = 0; i < this->n; ++i) {
        out << "data: " << this->elements[i] << "   ";
        out << "address: " << &this->elements[i] << "   " << std::endl;
    }
    out << std::endl;
}

#endif //LINEARLIST_SEQLIST_H
