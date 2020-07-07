//
// Created by Vittorio Iocco on 6/25/20.
//

#ifndef DATASTRUCTS_STACK_H
#define DATASTRUCTS_STACK_H

#include "ArrayList.h"

template<class T>
class stack{
public:
    stack(){
        arr = new ArrayList<T>();
        top = 0;
        s = arr->get_capacity();
    }

    explicit stack(int cap){
        arr = new ArrayList<T>(cap);
        top = 0;
        s = cap;
    }

    ~stack(){
        delete arr;
    }
    T pop(){
        if(isEmpty())
            throw "popping off empty stack: Underflow!";
        else{
            top = top - 1;
            T temp = (*arr)[top];
            return temp;
        }
    }

    void push(const T& obj){
        if(isFull())
            throw "Pushing onto full stack: Overflow!";
        else{
            (*arr)[top] = obj;
            top = top + 1;
        }
    }

    int isEmpty(){
        if(top == 0)
            return 1;
        else
            return 0;
    }

    int isFull(){
        if(top == s)
            return 1;
        else
            return 0;
    }

    bool operator == (stack<T> &rhs){
        if (this->s !=  rhs.s)
            return false;
        if (this->top != rhs.top){
            return false;
        }
        for (int i = 0; i < top; i++){
            T left = (*this->arr)[i];
            T right = (*rhs.arr)[i];
            if (!((*this->arr)[i] == (*rhs.arr)[i])){
                return false;
            }
        }
        return true;
    }

private:
    ArrayList<T> *arr;
    int top{};
    int s{};
};

#endif
