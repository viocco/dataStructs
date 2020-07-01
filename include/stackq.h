//
// Created by Vittorio Iocco on 6/25/20.
//
#ifndef DATASTRUCTS_STACKQ_H
#define DATASTRUCTS_STACKQ_H
#include "queue.h"

template<class T>
class stackq{
public:
    explicit stackq(int size){
        q0 = new queue<T>(size);
        q1 = new queue<T>(size);
        qArr = new queue<T>*[2];
        qArr[0] = q0;
        qArr[1] = q1;
        which_q = 0;
    }

    T pop(){
        if(isEmpty())
            throw "Popping off empty stack: Underflow";
        else{
            while (qArr[which_q]->get_size() > 1){
                qArr[!which_q]->enqueue(qArr[which_q]->dequeue());
            }
            auto temp = qArr[which_q]->dequeue();
            which_q = !which_q;
            return temp;
        }
    }

    void push(const T& obj){
        if(isFull())
            throw "enqueueing onto full queue: Overflow!";
        else{
            qArr[which_q]->enqueue(obj);
        }
    }

    int isEmpty(){
        return qArr[which_q]->isEmpty();
    }

    int isFull(){
        return qArr[which_q]->isFull();
    }

    bool operator ==(stackq<T> &rhs){
        if (this->which_q != rhs.which_q || !(*(this->q0) == *(rhs.q0)) || !(*(this->q1) == *(rhs.q1)))
            return false;
        else
            return true;
    }

private:
    int which_q;
    queue<T> **qArr;
    queue<T> *q0;
    queue<T> *q1;
};

#endif
