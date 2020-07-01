//
// Created by Vittorio Iocco on 6/26/20.
//

#ifndef DATASTRUCTS_LINKEDLIST1P_H
#define DATASTRUCTS_LINKEDLIST1P_H

template<class T>
class LinkedList1P{
public:
    LinkedList1P(){
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    ~LinkedList1P(){
        Node* next = nullptr;
        Node* prev = nullptr;
        while(head != nullptr){
            next = head->next(prev);
            prev = head; //location of current is location of next nodes

            Node *temp = next;
            delete head;
            head = temp;
        }
    };

    void insert(const T& obj){
        Node* new_head = new Node(obj);
        if (length == 0){
            head = new_head;
            tail = new_head;
        } else {
            head->resetCurrNP(new_head,head->np); //update head->np with new previous, head->np = next
            //here because prev = nullptr
            new_head->resetCurrNP((nullptr),head); //n->prev = nullptr, n->next = head
            head = new_head; //set head pointer to new node
        }
        length = length + 1;
    };

    T linked_delete(){
        if (length == 0){
            throw "deleting from empty list";
        }
        Node* old_head = head;
        //head = head->next;
        head = head->np; //head->np = next b/c prev = nullptr
        //head->prev = nullptr;
        if (head != nullptr)
            head->resetCurrNP((nullptr),head->next(old_head)); // previous^next = np.
        // head->np is next, before_head_addr // = np. So next ^ np = p. Since prev // = nullptr now, this is what we want
        length = length - 1;
        return old_head->obj;
    }

    void insertLast(T obj){
        Node *n = new Node(obj);
        if (length == 0){
            head = n;
            tail = n;
        } else {
            Node *oldTail = tail;
            tail->resetCurrNP(tail->np,n); //tail->np = tail->prev
            tail = n;
            n->resetCurrNP(oldTail,(nullptr)); //beforeTailAddr is prev and next = null
        }
        length = length + 1;
    }

    T deleteLast(){
        if (length == 0){
            throw "deleting node from empty list";
        }
        Node *old_tail = tail;
        tail = tail->np; //tail->np = tail->prev
        if (tail != nullptr){
            tail->resetCurrNP(tail->prev(old_tail),(nullptr)); //tail->np = tail->next, old_tail = tail->next
        }
        length = length - 1;
        return old_tail->obj;
    }

    void insertAfter(int index, T obj){
        Node *nd = new Node(obj);
        Node *curr = head;
        Node* next = nullptr;
        Node* prev = nullptr;
        while(index != 0){
            if (curr == nullptr || curr == tail){
                throw "index too large";
            } else {
                next = curr->next(prev);
                prev = curr; //location of current is location of next nodes
                curr = next;
            }
            index--;
        }

        if (curr == head){
            insert(obj);
        } else if (curr == tail) {
            insertLast(obj);
        } else {
            //push one node forward so prev (from above), not curr (from above) is the node we want to insert // after
            next = curr->next(prev);
            prev = curr;
            curr = next;

            prev->resetCurrNP(prev->next(curr),nd); // curr = prev->next. nd is new next.
            curr->resetCurrNP(curr->next(prev),nd);// prev = curr->np
            nd->resetCurrNP(prev,curr);
        }

        length = length + 1;
    }

    int size(){
        return length;
    }

    bool operator ==(LinkedList1P<T> &rhs){
        if (this->size() != rhs.size()){
            return false;
        }
        Node* nextlhs = nullptr;
        Node* prevlhs = nullptr;
        Node* nextrhs = nullptr;
        Node* prevrhs = nullptr;
        Node* lhsCurr = this->head;
        Node* rhsCurr = rhs.head;
        while(lhsCurr != nullptr && rhsCurr != nullptr){
            if (!(*rhsCurr == *lhsCurr)){
                return false;
            }
            nextlhs = lhsCurr->next(prevlhs);
            prevlhs = lhsCurr; //location of current is location of next nodes
            lhsCurr = nextlhs;
            nextrhs = rhsCurr->next(prevrhs);
            prevrhs = rhsCurr; //location of current is location of next nodes
            rhsCurr = nextrhs;
        }

        return true;
    }


private:
    struct Node {
    public:
        Node(T obj){
            this->obj = obj;
            np = nullptr;
        }

        bool operator == (Node& rhs){
            if (this->obj == rhs.obj){
                return true;
            } else {
                return false;
            }
        }

        Node* next(const Node* const prev) {
            // xor out the previous pointer to get the next pointer
            return reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(this->np) ^ reinterpret_cast<uintptr_t>(prev));
        }

        Node* prev(const Node* const next) {
            // xor out the next pointer to get the previous pointer
            return reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(this->np) ^ reinterpret_cast<uintptr_t>(next));
        }

        void resetCurrNP(const Node* const prev, const Node* const next) {
            // xor out the next pointer to get the previous pointer
            this->np = reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(prev) ^ reinterpret_cast<uintptr_t>(next));
        }


    public:
        T obj;
        Node *np;
    };
    Node* head;
    Node* tail;
    int length;
};


#endif
