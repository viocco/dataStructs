//
// Created by Vittorio Iocco on 6/25/20.
//
#ifndef DATASTRUCTS_QUEUES_H
#define DATASTRUCTS_QUEUES_H
#include "stack.h"

template<class T>
class queueS{
public:
    explicit queueS(int size){
        s0 = new stack<T>(size);
        s1 = new stack<T>(size);
        sArr = new stack<T>*[2];
        sArr[0] = s0;
        sArr[1] = s1;
        which_stack = 0;
    }

    ~queueS(){
        delete[] sArr;
    }

    T dequeue(){
        if(isEmpty())
            throw "Dequeueing off empty queue: Underflow";
        else{
            //offload into temp stack
            while (!(sArr[which_stack]->isEmpty())){
                sArr[!which_stack]->push(sArr[which_stack]->pop());
            }
            which_stack = !which_stack;
            auto temp =  sArr[which_stack]->pop();

            //put back into original stack
            while (!(sArr[which_stack]->isEmpty())){
                sArr[!which_stack]->push(sArr[which_stack]->pop());
            }
            which_stack = !which_stack;
            return temp;
        }
    }

    void enqueue(const T& obj){
        if(isFull())
            throw "enqueueing onto full queue: Overflow!";
        else{
            sArr[which_stack]->push(obj);
        }
    }

    int isEmpty(){
        return sArr[which_stack]->isEmpty();
    }

    int isFull(){
        return sArr[which_stack]->isFull();
    }

    bool operator ==(queueS<T> &rhs){
        if (this->which_stack != rhs.which_stack || !(*(this->s0) == *(rhs.s0)) || !(*(this->s1) == *(rhs.s1)))
            return false;
        else
            return true;
    }


private:
    int which_stack;
    stack<T> **sArr;
    stack<T> *s0;
    stack<T> *s1;
};


#endif
