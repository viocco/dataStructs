//
// Created by Vittorio Iocco on 6/26/20.
//
#include <iostream>
#include "../include/stack.h"
#include "gtest/gtest.h"

TEST(stackTest, initStack){
    stack<int> *s1 = new stack<int>(1);
    ASSERT_FALSE(s1->isFull());
    ASSERT_TRUE(s1->isEmpty());
}

TEST(stackTest, stackPush){
    stack<int> *s1 = new stack<int>(100);
    s1->push(5);
    ASSERT_FALSE(s1->isEmpty());
    ASSERT_FALSE(s1->isFull());
}


TEST (stackTest, stackPop){
    stack<int> *s1 = new stack<int>(100);
    s1->push(5);
    ASSERT_EQ(s1->pop(),5);
}

TEST (stackTest, stackFull){
    stack<int> *s1 = new stack<int>(5);
    for(int i = 0; i < 4;i++){
        s1->push(5);
        ASSERT_FALSE(s1->isFull());
    }
    s1->push(5);
    ASSERT_TRUE(s1->isFull());
}

TEST (stackTest, involved1){
    stack<int> *s1 = new stack<int>(10);
    for (int i = 0; i < 10; i++){
        s1->push(i);
    }

    stack<int> *s2 = new stack<int>(10);
    for (int i = 0; i < 10; i++){
        s2->push(i);
    }

    ASSERT_TRUE(*s2 == *s1);

    for (int i = 9; i >= 0; i--){
        int first = s1->pop();
        int second = s2->pop();
        ASSERT_EQ(i,first);
        ASSERT_EQ(first,second);
    }
}

TEST (stackTest, involved2){
    //test a different type for T in stack<T>
    stack<std::vector<int>> *s1 = new stack<std::vector<int>>(10);
    for (int i = 0; i < 10; i++){
        std::vector<int> element (100,i);
        s1->push(element);
    }

    //test some popping and re-pushing different elements
    for (int i = 9; i >= 5; i--){
        ASSERT_EQ(s1->pop(),std::vector<int> (100,i));
    }
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}

// DEFAULT CONSTRUCTOR EXISTS, UNTIL YOU INCLUDE 1 non-default constructor.
// Many operators depend on default constructor, such as [].

/*
 * Differences between array and pointer:
 *  1.  T* arr = new T[n];
 *      T* actual_arr[n];
 *      sizeof(arr) = 8 (because its a pointer);
 *      sizeof(actual_arr) = n*sizeof(T);
 *
 *      REASON: arr and actual_arr both point to first element of arr, but under hood actual_arr has more going on
 *      IMPLICATION: sizeof(actual_arr)/sizeof(T) = n (size of array) only if declared as arr not pointer
 *      IMPLICATION: Dynamically allocated arrays must be done the first way because can't have non-integer at compile time
 *                   for array.
 * 2.  Second type has fixed address, can't assign actual_arr to a different address.
 *
 *
 */

//To consider making for each class: default constructor/(for arr), copy constructor (for =)
//Things to learn: 1) assignment vs copy constructor and when used
//double pointers and initializing (new type[][] vs new type*[])