//
// Created by Vittorio Iocco on 6/28/20.
//
//
// Created by Vittorio Iocco on 6/28/20.
//

#include "gtest/gtest.h"
#include "../include/stackLL.h"

TEST(stackLLTest, initStack){
    stackLL<int> *s1 = new stackLL<int>();
    ASSERT_FALSE(s1->isFull());
    ASSERT_TRUE(s1->isEmpty());
}

TEST(stackLLTest, stackPush){
    stackLL<int> *s1 = new stackLL<int>();
    s1->push(5);
    ASSERT_FALSE(s1->isEmpty());
    ASSERT_FALSE(s1->isFull());
}

TEST(stackLLTest, stackPop){
    stackLL<int> *s1 = new stackLL<int>();
    s1->push(5);
    ASSERT_EQ(s1->pop(),5);
}

TEST(stackLLTest, involved1){
    stackLL<int> *s1 = new stackLL<int>();
    for (int i = 0; i < 10; i++){
        s1->push(i);
    }

    stackLL<int> *s2 = new stackLL<int>();
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

TEST(stackLLTest, involved2){
    //test a different type for T in stack<T>
    stackLL<std::vector<int>> *s1 = new stackLL<std::vector<int>>();
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
