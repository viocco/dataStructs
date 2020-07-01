//
// Created by Vittorio Iocco on 6/26/20.
//
#ifndef DATASTRUCTS_STACKLL_H
#define DATASTRUCTS_STACKLL_H

#include "LinkedList.h"

template<class T>
class stackLL{
public:

    stackLL(){
        lst = new LinkedList<T>();
    }

    ~stackLL(){
        delete lst;
    }

    T pop(){
        if(isEmpty())
            throw "popping off empty stack: Underflow!";
        else{
            return lst->deleteLast();
        }
    }

    void push(const T& obj){
        if(isFull())
            throw "Pushing onto full stack: Overflow!";
        else{
            lst->insertLast(obj);
        }
    }

    int isEmpty(){
        return !lst->size();
    }

    int isFull(){
        return 0;
    }

    bool operator ==(stackLL<T> &rhs){
        if (*this->lst == *rhs.lst){
            return true;
        } else {
            return false;
        }
    }

private:
    LinkedList<T> *lst;
};


#endif
