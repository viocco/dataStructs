//
// Created by Vittorio Iocco on 6/30/20.
//

#ifndef DATASTRUCTS_ARRAYLIST_H
#define DATASTRUCTS_ARRAYLIST_H

template <class T>
class ArrayList {
    public:
        ArrayList(){
            arr = new T[1];
            size = 0;
            capacity = 1;
        }

        explicit ArrayList(int cap){
            arr = new T[cap];
            size = 0;
            capacity = cap;
        }

        ~ArrayList(){
            delete [] arr;
        }

        T& operator[](int index){
            if (index > capacity - 1) {
                throw std::out_of_range("Index out of range of ArrayList");
            } else {
                return arr[index];
            }
        }

        T& pop_back(){
            if (size == 0) {
                throw std::underflow_error("Popping off of empty ArrayList");
            } else {
                T& temp = arr[size - 1]; //not sure if T& gets originsl
                size--;
                return arr[size - 1];
            }
        }

        void push_back(const T &obj){
            if (size == capacity) {
                T* new_arr = new T[capacity*2];
                for (int i = 0; i < capacity;i++){
                    new_arr[i] = arr[i];
                }
                delete [] arr;
                arr = new_arr;
                capacity = capacity * 2;
            }
            arr[size] = obj;
            size++;
        }

        int get_size(){
            return size;
        }

        int get_capacity(){
            return capacity;
        }

private:
        T* arr;
        int size;
        int capacity;
};


#endif
