//
// Created by Vittorio Iocco on 6/28/20.
//

#include <iostream>
#include "../include/queue.h"
#include "gtest/gtest.h"
#include "../include/stack.h"

TEST(queueTest, initQueue){
    queue<int> *q1 = new queue<int>(1);
    ASSERT_FALSE(q1->isFull());
    ASSERT_TRUE(q1->isEmpty());
    delete q1;
}

TEST(queueTest, queueEnqueue){
    queue<int> *q1 = new queue<int>(100);
    q1->enqueue(5);
    ASSERT_FALSE(q1->isEmpty());
    ASSERT_FALSE(q1->isFull());
    delete q1;
}


TEST (queueTest, queueDequeue){
    queue<int> *q1 = new queue<int>(100);
    q1->enqueue(5);
    ASSERT_EQ(q1->dequeue(),5);
    delete q1;
}

TEST (queueTest, queueFull){
    queue<int> *q1 = new queue<int>(5);
    for(int i = 0; i < 4;i++){
        q1->enqueue(5);
        ASSERT_FALSE(q1->isFull());
    }
    q1->enqueue(5);
    ASSERT_TRUE(q1->isFull());
    delete q1;
}

TEST (queueTest, involved1){
    queue<int> *q1 = new queue<int>(10);
    for (int i = 0; i < 10; i++){
        q1->enqueue(i);
    }
    for (int i = 0; i < 10 ;i++){
        ASSERT_EQ(q1->dequeue(),i);
    }
    delete q1;
}

TEST (queueTest, involved3){
    //test a different type for T in stack<T>
    queue<std::vector<int>> *q1 = new queue<std::vector<int>>(10);
    for (int i = 0; i < 10; i++){
        std::vector<int> element (100,i);
        q1->enqueue(element);
    }

    for (int i = 0; i < 5; i++){
        ASSERT_EQ(q1->dequeue(),std::vector<int>(100,i));
    }
    delete q1;
}

TEST (queueTest, wrapAround){
    queue<int> *q1 = new queue<int>(10);
    for (int i = 0; i < 10; i++){
        q1->enqueue(i);
    }
    ASSERT_TRUE(q1->isFull());
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

TEST (queueTest, equalQueues){
    //first queue
    queue<int> *q1 = new queue<int>(10);
    for (int i = 0; i < 10; i++){
        q1->enqueue(i);
    }
    ASSERT_TRUE(q1->isFull());
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
    queue<int> *q2 = new queue<int>(10);
    for (int i = 0; i < 10; i++){
        q2->enqueue(i);
    }
    ASSERT_TRUE(q2->isFull());
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

TEST (queueTest, equalQueues2){
    //first queue
    queue<int> *q1 = new queue<int>(10);
    for (int i = 0; i < 10; i++){
        q1->enqueue(i);
    }
    ASSERT_TRUE(q1->isFull());
    for (int i = 0; i < 9 ;i++){
        ASSERT_EQ(q1->dequeue(),i);
    }

    for (int i = 20; i < 25; i++){
        q1->enqueue(i);
        ASSERT_FALSE(q1->isFull());
    }
    ASSERT_EQ(q1->dequeue(),9);

    //second queue
    queue<int> *q2 = new queue<int>(10);
    for (int i = 0; i < 10; i++){
        q2->enqueue(i);
    }
    ASSERT_TRUE(q2->isFull());
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

TEST (queueTest, unequalQueues){
    //first queue
    queue<int> *q1 = new queue<int>(10);
    for (int i = 0; i < 10; i++){
        q1->enqueue(i);
    }
    ASSERT_TRUE(q1->isFull());
    for (int i = 0; i < 9 ;i++){
        ASSERT_EQ(q1->dequeue(),i);
    }

    for (int i = 20; i < 25; i++){
        q1->enqueue(i);
        ASSERT_FALSE(q1->isFull());
    }
    ASSERT_EQ(q1->dequeue(),9);

    //second queue
    queue<int> *q2 = new queue<int>(10);
    for (int i = 0; i < 10; i++){
        q2->enqueue(i);
    }
    ASSERT_TRUE(q2->isFull());
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
