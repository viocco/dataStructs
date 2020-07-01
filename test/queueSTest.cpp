//
// Created by Vittorio Iocco on 6/28/20.
//

#include <iostream>
#include "../include/queueS.h"
#include "gtest/gtest.h"

TEST(queueSTest, initQueue){
    queueS<int> *q1 = new queueS<int>(1);
    ASSERT_FALSE(q1->isFull());
    ASSERT_TRUE(q1->isEmpty());
}

TEST(queueSTest, queueEnqueue){
    queueS<int> *q1 = new queueS<int>(100);
    q1->enqueue(5);
    ASSERT_FALSE(q1->isEmpty());
    ASSERT_FALSE(q1->isFull());
}


TEST (queueSTest, queueDequeue){
    queueS<int> *q1 = new queueS<int>(100);
    q1->enqueue(5);
    ASSERT_EQ(q1->dequeue(),5);
}

TEST (queueSTest, queueFull){
    queueS<int> *q1 = new queueS<int>(5);
    for(int i = 0; i < 4;i++){
        q1->enqueue(5);
        ASSERT_FALSE(q1->isFull());
    }
    q1->enqueue(5);
    ASSERT_TRUE(q1->isFull());
}

TEST (queueSTest, involved1){
    queueS<int> *q1 = new queueS<int>(10);
    for (int i = 0; i < 10; i++){
        q1->enqueue(i);
    }
    for (int i = 0; i < 10 ;i++){
        ASSERT_EQ(q1->dequeue(),i);
    }
}

TEST (queueSTest, involved3){
    //test a different type for T in stack<T>
    queueS<std::vector<int>> *q1 = new queueS<std::vector<int>>(10);
    for (int i = 0; i < 10; i++){
        std::vector<int> element (100,i);
        q1->enqueue(element);
    }

    for (int i = 0; i < 5; i++){
        ASSERT_EQ(q1->dequeue(),std::vector<int>(100,i));
    }
}

TEST (queueSTest, wrapAround){
    queueS<int> *q1 = new queueS<int>(10);
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

}

TEST (queueSTest, equalQueues){
    //first queue
    queueS<int> *q1 = new queueS<int>(10);
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
    queueS<int> *q2 = new queueS<int>(10);
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
}

TEST (queueSTest, equalQueues2){
    //first queue
    queueS<int> *q1 = new queueS<int>(10);
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
    queueS<int> *q2 = new queueS<int>(10);
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
}

TEST (queueSTest, unequalQueues){
    //first queue
    queueS<int> *q1 = new queueS<int>(10);
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
    queueS<int> *q2 = new queueS<int>(10);
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
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}
