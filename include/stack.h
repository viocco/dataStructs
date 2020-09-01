//
// Created by Vittorio Iocco on 6/25/20.
//
//:::::::::::::::::::::::: ArrayList Implimentation ::::::::::::::::::::::
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

//:::::::::::::::::::::::: LinkedList Implimentation ::::::::::::::::::::::
//#include "LinkedList.h"
//
//template<class T>
//class stack{
//public:
//
//    stack(){
//        lst = new LinkedList<T>();
//    }
//
//    ~stack(){
//        delete lst;
//    }
//
//    T pop(){
//        if(isEmpty())
//            throw "popping off empty stack: Underflow!";
//        else{
//            return lst->deleteLast();
//        }
//    }
//
//    void push(const T& obj){
//        if(isFull())
//            throw "Pushing onto full stack: Overflow!";
//        else{
//            lst->insertLast(obj);
//        }
//    }
//
//    int isEmpty(){
//        return !lst->size();
//    }
//
//    int isFull(){
//        return 0;
//    }
//
//    bool operator ==(stack<T> &rhs){
//        if (*this->lst == *rhs.lst){
//            return true;
//        } else {
//            return false;
//        }
//    }
//
//private:
//    LinkedList<T> *lst;
//};


//:::::::::::::::::::::::: Queue Implimentation ::::::::::::::::::::::
//#include "queue.h"
//
//template<class T>
//class stack{
//public:
//    explicit stack(int size){
//        q0 = new queue<T>(size);
//        q1 = new queue<T>(size);
//        qArr = new queue<T>*[2];
//        qArr[0] = q0;
//        qArr[1] = q1;
//        which_q = 0;
//    }
//
//    T pop(){
//        if(isEmpty())
//            throw "Popping off empty stack: Underflow";
//        else{
//            while (qArr[which_q]->get_size() > 1){
//                qArr[!which_q]->enqueue(qArr[which_q]->dequeue());
//            }
//            auto temp = qArr[which_q]->dequeue();
//            which_q = !which_q;
//            return temp;
//        }
//    }
//
//    void push(const T& obj){
//        if(isFull())
//            throw "enqueueing onto full queue: Overflow!";
//        else{
//            qArr[which_q]->enqueue(obj);
//        }
//    }
//
//    int isEmpty(){
//        return qArr[which_q]->isEmpty();
//    }
//
//    int isFull(){
//        return qArr[which_q]->isFull();
//    }
//
//    bool operator ==(stack<T> &rhs){
//        if (this->which_q != rhs.which_q || !(*(this->q0) == *(rhs.q0)) || !(*(this->q1) == *(rhs.q1)))
//            return false;
//        else
//            return true;
//    }
//
//private:
//    int which_q;
//    queue<T> **qArr;
//    queue<T> *q0;
//    queue<T> *q1;
//};