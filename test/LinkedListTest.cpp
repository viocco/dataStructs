//
// Created by Vittorio Iocco on 6/28/20.
//

#include "gtest/gtest.h"
#include "../include/LinkedList.h"

TEST(LinkedListTest, initList){
    LinkedList<int> *ll = new LinkedList<int>();
    ASSERT_TRUE(ll->size() == 0);
    delete ll;

}

TEST(LinkedListTest, insert){
    LinkedList<int> *ll = new LinkedList<int>();
    ll->insert(5);
    ASSERT_TRUE(ll->size() == 1);
    delete ll;
}

TEST(LinkedListTest, insertLast){
    LinkedList<int> *ll = new LinkedList<int>();
    ll->insertLast(5);
    ASSERT_TRUE(ll->size() == 1);
    ll->insertLast(4);
    ASSERT_TRUE(ll->size() == 2);
    delete ll;
}

TEST(LinkedListTest, linked_delete){
    LinkedList<int> *ll = new LinkedList<int>();
    ll->insert(5);
    ll->insert(6);
    ASSERT_EQ(ll->linked_delete(),6);
    delete ll;
}

TEST(LinkedListTest, deleteLast){
    LinkedList<int> *ll = new LinkedList<int>();
    ll->insert(5);
    ll->insert(6);
    ASSERT_EQ(ll->deleteLast(),5);
    delete ll;
}

TEST(LinkedListTest, deleteLast2){
    LinkedList<int> *ll = new LinkedList<int>();
    for (int i = 0; i < 1000; i++){
        ll->insert(i);
    }
    ASSERT_EQ(ll->deleteLast(),0);
    delete ll;
}

TEST(LinkedListTest, insertLast2){
    LinkedList<int> *ll = new LinkedList<int>();
    for (int i = 0; i < 1000; i++){
        ll->insertLast(i);
    }
    ASSERT_EQ(ll->deleteLast(),999);
    delete ll;
}

TEST(LinkedListTest, insertLastDelete){
    LinkedList<int> *ll = new LinkedList<int>();
    for (int i = 0; i < 1000; i++){
        ll->insertLast(i);
    }
    ASSERT_EQ(ll->linked_delete(),0);
    delete ll;
}

TEST(LinkedListTest, insertAfter){
    LinkedList<int> *ll = new LinkedList<int>();
    for (int i = 0; i < 1000; i++){
        ll->insertLast(i);
    }

    ll->insertAfter(10, -100);
    for (int i = 0; i < 11; i++){
        ASSERT_EQ(ll->linked_delete(),i);
    }
    ASSERT_EQ(ll->linked_delete(),-100);
    ASSERT_EQ(ll->linked_delete(),11);
    delete ll;
}

TEST(LinkedListTest, testEquals){
    LinkedList<int> *ll1 = new LinkedList<int>();
    for (int i = 0; i < 1000; i++){
        ll1->insertLast(i);
    }
    ASSERT_EQ(ll1->linked_delete(),0);

    LinkedList<int> *ll2 = new LinkedList<int>();
    for (int i = 0; i < 1000; i++){
        ll2->insertLast(i);
    }
    ASSERT_EQ(ll2->linked_delete(),0);
    ASSERT_TRUE(*ll1 == *ll2);
    delete ll1;
    delete ll2;
}

TEST(LinkedListTest, complexDataType){
    LinkedList<std::vector<int>> *ll1 = new LinkedList<std::vector<int>>();
    for (int i = 0; i < 50; i++){
        ASSERT_TRUE(ll1->size() == i);
        std::vector<int> element (100,i);
        ll1->insertLast(element);
    }

    for (int i = 0; i < 50; i++){
        ASSERT_TRUE(ll1->size() == 50-i);
        ASSERT_EQ(ll1->linked_delete(),std::vector<int> (100,i));
    }
    ASSERT_TRUE(ll1->size() == 0);
    delete ll1;
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}

