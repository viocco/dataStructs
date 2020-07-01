//
// Created by Vittorio Iocco on 6/25/20.
//

#ifndef DATASTRUCTS_LINKEDLIST_H
#define DATASTRUCTS_LINKEDLIST_H

template<class T>
class LinkedList{
public:
   LinkedList(){
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    ~LinkedList(){
        while(head != nullptr){
            Node *temp = head->next;
            delete head;
            head = temp;
        }
    };

    void insert(T obj){
        Node* n = new Node(obj);
        if (length != 0){
            head->prev = n;
            head->prev->next = head;
            head->prev->prev = nullptr;
            head = n;
        } else {
            head = n;
            tail = n;
        }
        length = length + 1;
    };

    T linked_delete(){
        if (length == 0){
            throw "deleting from empty list";
        }
        Node * temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        length = length - 1;
        return temp->obj;
    }

    void insertLast(T obj){
        Node *n = new Node(obj);
        if (length != 0){
            n->prev = tail;
            n->next = nullptr;
            tail = n;
            tail->prev->next = tail;
        } else {
            head = n;
            tail = n;
        }
        length = length + 1;
    }

    T deleteLast(){
        if (length == 0){
            throw "deleting node from empty list";
        }
        Node * temp = tail;
        tail = tail->prev;
        if (tail != nullptr){
            tail->next = nullptr;
        }
        length = length - 1;
        return temp->obj;
    }

    void insertAfter(int index, T obj){
        Node *nd = new Node(obj);
        Node *curr = head;
        while(index > 0){
            if (curr == nullptr || curr == tail){
                throw "index too large";
            } else {
                curr = curr->next;
            }
            index--;
        }
        if (curr == head){
            insert(obj);
        } else if (curr == tail) {
            insertLast(obj);
        } else {
            curr->next->prev = nd;
            nd->next = curr->next;
            nd->prev = curr;
            curr->next = nd;
        }

        length = length + 1;
    }

    int size(){
        return length;
    }

    bool operator ==(LinkedList<T> &rhs){
        if (this->size() != rhs.size()){
            return false;
        }
        Node* lhsCurr = this->head;
        Node* rhsCurr = rhs.head;
        while(lhsCurr != nullptr && rhsCurr != nullptr){
            if (lhsCurr->obj != rhsCurr->obj){
                return false;
            }
            lhsCurr = lhsCurr->next;
            rhsCurr = rhsCurr->next;
        }

        return true;
    }

private:
    struct Node {
    public:
        explicit Node(T obj){
            this->obj = obj;
            prev = nullptr;
            next = nullptr;
        }

        bool operator == (Node& rhs){
            if (this->obj == rhs->obj){
                return true;
            } else {
                return false;
            }
        }

    public:
        T obj;
        Node *prev;
        Node *next;
    };
    Node* head;
    Node* tail;
    int length;
};

#endif
