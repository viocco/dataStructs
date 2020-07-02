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
    delete s1;
}

TEST(stackTest, stackPush){
    stack<int> *s1 = new stack<int>(100);
    s1->push(5);
    ASSERT_FALSE(s1->isEmpty());
    ASSERT_FALSE(s1->isFull());
    delete s1;
}


TEST (stackTest, stackPop){
    stack<int> *s1 = new stack<int>(100);
    s1->push(5);
    ASSERT_EQ(s1->pop(),5);
    delete s1;
}

TEST (stackTest, stackFull){
    stack<int> *s1 = new stack<int>(5);
    for(int i = 0; i < 4;i++){
        s1->push(5);
        ASSERT_FALSE(s1->isFull());
    }
    s1->push(5);
    ASSERT_TRUE(s1->isFull());
    delete s1;
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
    delete s1;
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
    delete s1;
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}