//
// Created by Vittorio Iocco on 6/25/20.
//

#ifndef DATASTRUCTS_STACK_H
#define DATASTRUCTS_STACK_H

template<class T>
class stack{
public:

    stack(){
        arr = new T[100000];
        top = 0;
        s = 100000;
    }

    explicit stack(int size){
        arr = new T[size];
        top = 0;
        s = size;
    }

    ~stack(){
        delete[] arr;
    }
    T pop(){
        if(isEmpty())
            throw "popping off empty stack: Underflow!";
        else{
            top = top - 1;
            T temp = arr[top];
            return temp;
        }
    }

    void push(T obj){
        if(isFull())
            throw "Pushing onto full stack: Overflow!";
        else{
            arr[top] = obj;
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
            T left = this->arr[i];
            T right = rhs.arr[i];
            if (this->arr[i] != rhs.arr[i]){
                return false;
            }
        }
        return true;
    }

private:
    T *arr;
    int top{};
    int s{};
};

#endif
