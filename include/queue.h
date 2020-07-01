//
// Created by Vittorio Iocco on 6/25/20.
//

#ifndef DATASTRUCTS_QUEUE_H
#define DATASTRUCTS_QUEUE_H

template<class T>
class queue{
public:

    queue(){
        arr = new T[100000];
        head = 0;
        tail = 0;
        capacity = 100000;
        size = 0;
    }

    explicit queue(int capacity){
        arr = new T[capacity];
        head = 0;
        tail = 0;
        size = 0;
        this->capacity = capacity;
    }

    ~queue(){
        delete[] arr;
    }

    T dequeue(){
        if(isEmpty())
            throw "Dequeueing off empty queue: Underflow";
        else{
            T temp = arr[head];
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
            arr[tail] = obj;
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
    int head{};
    int tail{};
    int size{};
    int capacity{};
};


#endif
