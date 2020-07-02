//
// Created by Vittorio Iocco on 6/30/20.
//

#include <cmath>
#include <ctime>
#include "gtest/gtest.h"
#include "../include/ArrayList.h"

TEST(ArrayListTest, initArrayList){
    ArrayList<int> a;
    ASSERT_EQ(a.get_size(), 0);
    ASSERT_EQ(a.get_capacity(), 1);
}

TEST(ArrayListTest, insertElementNoGrow){
    ArrayList<int> a;
    a.push_back(4);
    ASSERT_EQ(a.get_size(),1);
    ASSERT_EQ(a.get_capacity(),1);
}

TEST(ArrayListTest, insertElementGrow1){
    ArrayList<int> a;
    a.push_back(4);
    a.push_back(3);
    ASSERT_EQ(a.get_size(),2);
    ASSERT_EQ(a.get_capacity(),2);
}

TEST(ArrayListTest, insertElementGrow2){
    ArrayList<int> a;
    a.push_back(4);
    a.push_back(3);
    ASSERT_EQ(a.get_size(),2);
    ASSERT_EQ(a.get_capacity(),2);
    a.push_back(2);
    ASSERT_EQ(a.get_size(),3);
    ASSERT_EQ(a.get_capacity(),4);
    a.push_back(1);
    ASSERT_EQ(a.get_size(),4);
    ASSERT_EQ(a.get_capacity(),4);
    a.push_back(0);
    ASSERT_EQ(a.get_size(),5);
    ASSERT_EQ(a.get_capacity(),8);
}

TEST(ArrayListTest, insertLoopAndLinearTime){
    ArrayList<int> a;
    //struct tm * ti;
    double old_elapsed_secs = INFINITY; //first iteration must be less than infinity runtime (but we don't know what it will be)
    a.push_back(-1); // the indexing starting at zero throws off loop below, so just push one element and start at index 1
    for (int j = 0; j < 30; j++){
        clock_t begin = clock();
        for (int i = pow(2,j); i < pow(2,j+1); i++){
            ASSERT_EQ(a.get_size(),i);
            a.push_back(i);
            ASSERT_EQ(a.get_capacity(),pow(2,j+1));
        }
        clock_t end = clock();
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        if (double(old_elapsed_secs*2.5) < elapsed_secs){
            throw "NON_LINEAR_TIME";
        }
        old_elapsed_secs = elapsed_secs;
        std::cerr << "\nIteration: " + std::to_string(j) + " Time elapsed =" + std::to_string(elapsed_secs) + "[s]";
    }
}

TEST(ArrayListTest, insertAndTestLocation){
    ArrayList<int> a;
    //struct tm * ti;
    int size = 1000000;
    for (int i = 0; i < size; i++){
        a.push_back(i);
    }

    for (int i = 0; i < size; i++){
        ASSERT_EQ(a[i],i);
    }

    for (int i = size - 2; i >= 0; i--){
        ASSERT_EQ(a.pop_back(),i);
    }
}

TEST (ArrayListTest, complexDataType){
    //test a different type for T in stack<T>
    ArrayList<std::vector<int>> *q1 = new ArrayList<std::vector<int>>();
    int size = 20;
    for (int i = 0; i < size; i++){
        std::vector<int> element (100,i);
        q1->push_back(element);
    }

    for (int i = size - 2; i >= 0; i--){
        ASSERT_EQ(q1->pop_back(),std::vector<int>(100,i));
    }
}




int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}