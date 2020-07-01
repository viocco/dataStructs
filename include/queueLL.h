//
// Created by Vittorio Iocco on 6/26/20.
//
#ifndef DATASTRUCTS_QUEUELL_H
#define DATASTRUCTS_QUEUELL_H
#include "LinkedList.h"

template<class T>
class queueLL{
public:
    queueLL(){
        lst = new LinkedList<T>();
    }

    ~queueLL(){
        delete lst;
    }

    T dequeue(){
        if(isEmpty())
            throw "Dequeueing off empty queue: Underflow";
        else{
            return lst->linked_delete();
        }
    }

    void enqueue(const T& obj){
        if(isFull())
            throw "enqueueing onto full queue: Overflow!";
        else{
            lst->insertLast(obj);
        }
    }

    int isEmpty(){
        if (lst->size() == 0){
            return true;
        } else {
            return false;
        }
    }

    int isFull(){
        return 0;
    }

    bool operator ==(queueLL<T> &rhs){
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
