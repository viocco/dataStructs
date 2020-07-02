//
// Created by Vittorio Iocco on 6/28/20.
//


#include <iostream>
#include "gtest/gtest.h"
#include "../include/queueLL.h"

TEST(queueLLTest, initQueue){
    queueLL<int> *q1 = new queueLL<int>();
    ASSERT_FALSE(q1->isFull());
    ASSERT_TRUE(q1->isEmpty());
    delete q1;
}

TEST(queueLLTest, queueEnqueue){
    queueLL<int> *q1 = new queueLL<int>();
    q1->enqueue(5);
    ASSERT_FALSE(q1->isEmpty());
    ASSERT_FALSE(q1->isFull());
    delete q1;
}


TEST (queueLLTest, queueDequeue){
    queueLL<int> *q1 = new queueLL<int>();
    q1->enqueue(5);
    ASSERT_EQ(q1->dequeue(),5);
    delete q1;
}

TEST (queueLLTest, queueFull){
    queueLL<int> *q1 = new queueLL<int>();
    for(int i = 0; i < 4;i++){
        q1->enqueue(5);
        ASSERT_FALSE(q1->isFull());
    }
    q1->enqueue(5);
    delete q1;
}

TEST (queueLLTest, involved1){
    queueLL<int> *q1 = new queueLL<int>();
    for (int i = 0; i < 10; i++){
        q1->enqueue(i);
    }
    for (int i = 0; i < 10 ;i++){
        ASSERT_EQ(q1->dequeue(),i);
    }
    delete q1;
}

TEST (queueLLTest, involved3){
    //test a different type for T in stack<T>
    queueLL<std::vector<int>> *q1 = new queueLL<std::vector<int>>();
    for (int i = 0; i < 10; i++){
        std::vector<int> element (100,i);
        q1->enqueue(element);
    }

    for (int i = 0; i < 5; i++){
        ASSERT_EQ(q1->dequeue(),std::vector<int>(100,i));
    }
    delete q1;
}

TEST (queueLLTest, wrapAround){
    queueLL<int> *q1 = new queueLL<int>();
    for (int i = 0; i < 10; i++){
        q1->enqueue(i);
    }
    for (int i = 0; i < 9 ;i++){
        ASSERT_EQ(q1->dequeue(),i);
    }

    for (int i = 20; i < 25; i++){
        q1->enqueue(i);
        ASSERT_FALSE(q1->isFull());
    }
    ASSERT_EQ(q1->dequeue(),9);

    for (int i = 20; i < 25; i++){
        ASSERT_EQ(q1->dequeue(),i);
    }
    ASSERT_TRUE(q1->isEmpty());
    delete q1;
}

TEST (queueLLTest, equalQueues){
    //first queue
    queueLL<int> *q1 = new queueLL<int>();
    for (int i = 0; i < 10; i++){
        q1->enqueue(i);
    }
    for (int i = 0; i < 9 ;i++){
        ASSERT_EQ(q1->dequeue(),i);
    }

    for (int i = 20; i < 25; i++){
        q1->enqueue(i);
        ASSERT_FALSE(q1->isFull());
    }
    ASSERT_EQ(q1->dequeue(),9);

    for (int i = 20; i < 25; i++){
        ASSERT_EQ(q1->dequeue(),i);
    }
    ASSERT_TRUE(q1->isEmpty());

    //second queue
    queueLL<int> *q2 = new queueLL<int>();
    for (int i = 0; i < 10; i++){
        q2->enqueue(i);
    }
    for (int i = 0; i < 9 ;i++){
        ASSERT_EQ(q2->dequeue(),i);
    }

    for (int i = 20; i < 25; i++){
        q2->enqueue(i);
        ASSERT_FALSE(q2->isFull());
    }
    ASSERT_EQ(q2->dequeue(),9);

    for (int i = 20; i < 25; i++){
        ASSERT_EQ(q2->dequeue(),i);
    }
    ASSERT_TRUE(q2->isEmpty());
    ASSERT_TRUE(*q1 == *q2);
    delete q1;
    delete q2;
}

TEST (queueLLTest, equalQueues2){
    //first queue
    queueLL<int> *q1 = new queueLL<int>();
    for (int i = 0; i < 10; i++){
        q1->enqueue(i);
    }
    for (int i = 0; i < 9 ;i++){
        ASSERT_EQ(q1->dequeue(),i);
    }

    for (int i = 20; i < 25; i++){
        q1->enqueue(i);
        ASSERT_FALSE(q1->isFull());
    }
    ASSERT_EQ(q1->dequeue(),9);

    //second queue
    queueLL<int> *q2 = new queueLL<int>();
    for (int i = 0; i < 10; i++){
        q2->enqueue(i);
    }
    for (int i = 0; i < 9 ;i++){
        ASSERT_EQ(q2->dequeue(),i);
    }

    for (int i = 20; i < 25; i++){
        q2->enqueue(i);
        ASSERT_FALSE(q2->isFull());
    }
    ASSERT_EQ(q2->dequeue(),9);
    ASSERT_FALSE(q1->isFull());
    ASSERT_FALSE(q1->isEmpty());
    ASSERT_TRUE(*q1 == *q2);
    delete q1;
    delete q2;
}

TEST (queueLLTest, unequalQueues){
    //first queue
    queueLL<int> *q1 = new queueLL<int>();
    for (int i = 0; i < 10; i++){
        q1->enqueue(i);
    }
    for (int i = 0; i < 9 ;i++){
        ASSERT_EQ(q1->dequeue(),i);
    }

    for (int i = 20; i < 25; i++){
        q1->enqueue(i);
        ASSERT_FALSE(q1->isFull());
    }
    ASSERT_EQ(q1->dequeue(),9);

    //second queue
    queueLL<int> *q2 = new queueLL<int>();
    for (int i = 0; i < 10; i++){
        q2->enqueue(i);
    }
    for (int i = 0; i < 9 ;i++){
        ASSERT_EQ(q2->dequeue(),i);
    }

    for (int i = 20; i < 25; i++){
        q2->enqueue(i);
        ASSERT_FALSE(q2->isFull());
    }
    ASSERT_FALSE(q1->isFull());
    ASSERT_FALSE(q1->isEmpty());
    ASSERT_FALSE(*q1 == *q2);
    delete q1;
    delete q2;
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}
