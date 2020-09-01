//
// Created by Vittorio Iocco on 6/25/20.
//

//:::::::::::::::::::: ArrayList Implimentation :::::::::::::::::::::
#include "ArrayList.h"
template<class T>
class queue{
public:

    queue(){
        arr = new ArrayList<T>();
        head = 0;
        tail = 0;
        capacity = arr->get_capacity();
        size = 0;
    }

    explicit queue(int capacity){
        arr = new ArrayList<T>(capacity);
        head = 0;
        tail = 0;
        size = 0;
        this->capacity = capacity;
    }

    ~queue(){
        delete arr;
    }

    T dequeue(){
        if(isEmpty())
            throw "Dequeueing off empty queue: Underflow";
        else{
            T temp = (*arr)[head];
            if (head == capacity - 1)
                head = 0;
            else
                head = head + 1;
            size--;
            return temp;
        }
    }

    void enqueue(const T& obj){
        if(isFull())
            throw "enqueueing onto full queue: Overflow!";
        else{
            (*arr)[tail] = obj;
            if (tail == capacity-1){
                tail = 0;
            } else {
                tail = tail + 1;
            }
            size++;
        }
    }

    int isEmpty(){
        if(size == 0)
            return 1;
        else
            return 0;
    }

    int isFull(){
        if(size == capacity)
            return 1;
        else
            return 0;
    }

    int get_size(){
        return size;
    }

    bool operator == (queue<T> &rhs){
        if (this->head !=  rhs.head)
            return false;
        if (this->tail != rhs.tail){
            return false;
        }
        if (this->capacity != rhs.capacity){
            return false;
        }
        if (this->size != rhs.size){
            return false;
        }
        for (int i = head; i < tail; i++){
            T left = (*this->arr)[i];
            T right = (*rhs.arr)[i];
            if ((*this->arr)[i] != (*rhs.arr)[i]){
                return false;
            }
        }
        return true;
    }

private:
    ArrayList<T> *arr;
    int head{};
    int tail{};
    int size{};
    int capacity{};
};


//:::::::::::::::::::: Linked List Implimentation :::::::::::::::::::::
//#include "LinkedList.h"
//
//template<class T>
//class queue{
//public:
//    queue(){
//        lst = new LinkedList<T>();
//    }
//
//    ~queue(){
//        delete lst;
//    }
//
//    T dequeue(){
//        if(isEmpty())
//            throw "Dequeueing off empty queue: Underflow";
//        else{
//            return lst->linked_delete();
//        }
//    }
//
//    void enqueue(const T& obj){
//        if(isFull())
//            throw "enqueueing onto full queue: Overflow!";
//        else{
//            lst->insertLast(obj);
//        }
//    }
//
//    int isEmpty(){
//        if (lst->size() == 0){
//            return true;
//        } else {
//            return false;
//        }
//    }
//
//    int isFull(){
//        return 0;
//    }
//
//    bool operator ==(queue<T> &rhs){
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

//:::::::::::::::::::: Stack Implimentation :::::::::::::::::::::
//#include "stack.h"
//
//template<class T>
//class queue{
//public:
//    explicit queue(int size){
//        s0 = new stack<T>(size);
//        s1 = new stack<T>(size);
//        sArr = new stack<T>*[2];
//        sArr[0] = s0;
//        sArr[1] = s1;
//        which_stack = 0;
//    }
//
//    ~queue(){
//        delete[] sArr;
//    }
//
//    T dequeue(){
//        if(isEmpty())
//            throw "Dequeueing off empty queue: Underflow";
//        else{
//            //offload into temp stack
//            while (!(sArr[which_stack]->isEmpty())){
//                sArr[!which_stack]->push(sArr[which_stack]->pop());
//            }
//            which_stack = !which_stack;
//            auto temp =  sArr[which_stack]->pop();
//
//            //put back into original stack
//            while (!(sArr[which_stack]->isEmpty())){
//                sArr[!which_stack]->push(sArr[which_stack]->pop());
//            }
//            which_stack = !which_stack;
//            return temp;
//        }
//    }
//
//    void enqueue(const T& obj){
//        if(isFull())
//            throw "enqueueing onto full queue: Overflow!";
//        else{
//            sArr[which_stack]->push(obj);
//        }
//    }
//
//    int isEmpty(){
//        return sArr[which_stack]->isEmpty();
//    }
//
//    int isFull(){
//        return sArr[which_stack]->isFull();
//    }
//
//    bool operator ==(queue<T> &rhs){
//        if (this->which_stack != rhs.which_stack || !(*(this->s0) == *(rhs.s0)) || !(*(this->s1) == *(rhs.s1)))
//            return false;
//        else
//            return true;
//    }
//
//
//private:
//    int which_stack;
//    stack<T> **sArr;
//    stack<T> *s0;
//    stack<T> *s1;
//};

