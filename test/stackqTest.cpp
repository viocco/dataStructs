//
// Created by Vittorio Iocco on 6/28/20.
//
#include <iostream>
#include "../include/stackq.h"
#include "gtest/gtest.h"

TEST(stackqTest, initStack){
    stackq<int> *s1 = new stackq<int>(1);
    ASSERT_FALSE(s1->isFull());
    ASSERT_TRUE(s1->isEmpty());
}

TEST(stackqTest, stackqPush){
    stackq<int> *s1 = new stackq<int>(100);
    s1->push(5);
    ASSERT_FALSE(s1->isEmpty());
    ASSERT_FALSE(s1->isFull());
}


TEST (stackqTest, stackqPop){
    stackq<int> *s1 = new stackq<int>(100);
    s1->push(5);
    ASSERT_EQ(s1->pop(),5);
}

TEST (stackqTest, stackqFull){
    stackq<int> *s1 = new stackq<int>(5);
    for(int i = 0; i < 4;i++){
        s1->push(5);
        ASSERT_FALSE(s1->isFull());
    }
    s1->push(5);
    ASSERT_TRUE(s1->isFull());
}

TEST (stackqTest, pushAndPop){
    stackq<int> *s1 = new stackq<int>(5);
    for(int i = 0; i < 5;i++){
        s1->push(i);
    }
    for(int i = 4; i >= 0; i--){
        ASSERT_EQ(s1->pop(),i);
    }
}

TEST (stackqTest, involved1){
    stackq<int> *s1 = new stackq<int>(10);
    for (int i = 0; i < 10; i++){
        s1->push(i);
    }

    stackq<int> *s2 = new stackq<int>(10);
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

TEST (stackqTest, involved2){
    //test a different type for T in stack<T>
    stackq<std::vector<int>> *s1 = new stackq<std::vector<int>>(10);
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

