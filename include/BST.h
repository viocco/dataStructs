//
// Created by Vittorio Iocco on 7/7/20.
//

#ifndef DATASTRUCTS_BST_H
#define DATASTRUCTS_BST_H

#include <iostream>

template <class T>
class BST {
private:
    Node *root;
    Node *nil;

    enum Color {
        red,
        black
    };

    class Node {
        Node *leftChild;
        Node *rightChild;
        Node *parent
        Color color;
        T key;

        explicit Node(T key){
            leftChild = nil;
            rightChild = nil;
            parent = nil;
            this->key = key;
        }

        Node(){
            leftChild = nil;
            rightChild = nil;
            parent = nil;
            color = black;
        }

        ~Node(){} //doesn't really do anything just habit

        Node* min(Node * root){
            Node * curr = root;
            Node * pred = nil;
            while (curr->leftChild != nil) {
                pred = curr;
                curr = curr->leftChild;
            }
            return curr->key;
        }

        Node* max(Node * root){
            Node * curr = root;
            Node * pred = nil;
            while (curr->rightChild != nil) {
                pred = curr;
                curr = curr->rightChild;
            }
            return curr->key;
        }

        Node* search_helper(T& data, Node* curr){
            while (curr != nil){
                if (curr->key == data)
                    return curr;
                else if (curr->key < data)
                    search_helper(data,curr->leftChild);
                else
                    search_helper(data,curr->rightChild);
            }
            return nil;
        }

        Node* successor(Node* curr){
            if (curr == nil){
                return nil;
            } else if (curr->rightChild != nil) {
                return min(curr->rightChild);
            } else {
                Node * p = curr->parent;
                while(p != nil && curr == p->rightChild){
                    curr = p;
                    p = curr->parent;
                }
                return p;
            }
        }

        Node* predecessor(Node* curr){
            if (curr == nil){
                return nil;
            } else if (curr->leftChild != nil) {
                return max(curr->rightChild);
            } else {
                Node * p = curr->parent;
                while(p != nil && curr == p->leftChild){
                    curr = p;
                    p = curr->parent;
                }
                return p;
            }
        }
    };

    void RBT-Insert-Fix(Node * prob){
        Node *y = nil;
        while (prob->parent->color == red){
            if (prob->parent == prob->parent->parent->leftChild){
                y = prob->parent->parent->rightChild;
                if (y->color == red){
                    prob->parent->color = black;
                    y->color = black;
                    prob->parent->parent->color = red;
                    prob = prob->parent->parent;
                } else {
                    if (prob == prob->parent->rightChild) {
                        prob = prob->parent;
                        leftRotate(prob);
                    }
                    prob->parent->color = black;
                    prob->parent->parent->color = red;
                    rightRotate(prob->parent->parent);
                }
            } else {
                y = prob->parent->parent->leftChild;
                if (y->color == red){
                    prob->parent->color = black;
                    y->color = black;
                    prob->parent->parent->color = red;
                    prob = prob->parent->parent;
                } else {
                    if (prob == prob->parent->leftChild) {
                        prob = prob->parent;
                        rightRotate(prob);
                    }
                    prob->parent->color = black;
                    prob->parent->parent->color = red;
                    leftRotate(prob->parent->parent);
                }
            }
        }

        root->color = black;
    }

    void RBT-Delete-Fix(){
        // -- TODO
    }

public:

    BST(){
        nil = Node();
        root = nil;
        root->leftChild = nil;
        root->rightChild = nil;
    }

    bool search(T& data){
        return search_helper(data,root) != nil;
    }

    T& min(){
        Node * curr = root;
        if (root != nil) {
            while (curr->leftChild != nil) {
                curr = curr->left;
            }
            return curr->key;
        } else {
            throw "minimum of empty tree is not well-defined";
        }

    }

    T& max(){
        Node * curr = root;
        if (root != nil) {
            while (curr->rightChild != nil) {
                curr = curr->rightChild;
            }
            return curr->key;
        } else {
            throw "maximum of empty tree is not well-defined";
        }
    }

    T& successor(T& curr){
        Node * curr_node = search_helper(curr,root);
        if (curr_node == nil){
            throw "Cannot find input value in tree";
        }
        curr_node = successor(curr_node);
        if (curr_node == nill){
            throw "successor DNE";
        }
        return *curr_node;
    }

    T successorCopy(T& curr){
        Node * curr_node = search_helper(curr,root);
        if (curr_node == nill){
            throw "Cannot find input value in tree";
        }
        curr_node = successor(curr_node);
        if (curr_node == nill){
            throw "successor DNE";
        }
        return *curr_node;
    }

    T& predecessor(T& curr){
        Node * curr_node = search_helper(curr,root);
        if (curr_node == nil){
            throw "Cannot find input value in tree";
        }
        curr_node = predecessor(curr_node);
        if (curr_node == nil){
            throw "predecessor DNE";
        }
        return *curr_node;
    }

    T predecessorCopy(T& curr){
        Node * curr_node = search_helper(curr,root);
        if (curr_node == nil){
            throw "Cannot find input value in tree";
        }
        curr_node = predecessor(curr_node);
        if (curr_node == nil){
            throw "predecessor DNE";
        }
        return *curr_node;
    }

    void insert(T& data){
        //insert node as red
        Node *p = nil;
        Node *curr = root;
        while (curr != nil){
            if (curr->data > data){
                p = curr;
                curr = curr->leftChild;
            } else if (curr->data < data){
                p = curr;
                curr = curr->rightChild;
            }
        }
        Node * insert = Node(data);
        curr = insert;
        curr->parent = p;
        curr->leftChild = nill;
        curr->rightChild = nill;

        if (p == nil){
            root = curr;
            curr->color = black;
            return;
        } else if (curr = p->leftChild){
            p->leftChild = curr;
        } else {
            p->rightChild = curr;
        }

        curr->color = red;
        RBT-Insert-Fix(curr);

    }

    void remove(T& data){
        // -- TODO
    }

    void inOrder(){
        //Morris Inorder Traversal
        Node * curr = root;
        Node * pred = nil;
        while (curr != nil){
            if (curr->leftChild == nil){
                std::cout << " " << curr->data;
                curr = curr->rc;
            } else {
                pred = pred->leftChild;
                while (pred->rightChild != nil && pred->rightChild != curr){
                    pred = pred->rightChild;
                }
                if (pred->rightChild == nil){
                    pred->rightChild = curr;
                    curr = curr->leftChild;
                } else {
                    std::cout << " " << curr->data;
                    curr = curr->rightChild;
                    pred->rightChild = nil;
                }
            }
        }
    }

    void preOrder(){
        //Morris Preorder Traversal
        Node * curr = root;
        Node * pred = nil;
        while (curr != nil){
            if (curr->leftChild == nil){
                std::cout << " " << curr->data;
                curr = curr->rc;
            } else {
                pred = pred->leftChild;
                while (pred->rightChild != nil && pred->rightChild != curr){
                    pred = pred->rightChild;
                }
                if (pred->rightChild == nil){
                    std::cout << " " << curr->data;
                    pred->rightChild = curr;
                    curr = curr->leftChild;
                } else {
                    curr = curr->rightChild;
                    pred->rightChild = nil;
                }
            }
        }
    }

    void postOrder(){
        //Morris Inorder Traversal
        Node * curr = root;
        Node * pred = nil;
        Node * first = nil;
        Node * middle = nil;
        Node * last = nil;
        Node * dummy;
        dummy->leftChild = root;
        curr = dummy; // we must never print dummy!
        while (curr != nil){
            if (curr->leftChild == nil){
                curr = curr->rc;
            } else {
                pred = pred->leftChild;
                while (pred->rightChild != nil && pred->rightChild != curr){
                    pred = pred->rightChild;
                }
                if (pred->rightChild == nil){
                    pred->rightChild = curr;
                    curr = curr->leftChild;
                } else {
                    // at this point we have the correct in order strucutre
                    // but we want to print in reverse order so reverse rc chain
                    // note we don't print curr here because we will print it
                    // in a future iteration where lc = the current curr (which // is after we print current curr's rc). We don't print dummy // this way.
                    //reverse rightChild pointers
                    first = curr;
                    middle = curr->left;
                    while(middle != curr){
                        last = middle->right;
                        middle->right = first;
                        first = middle;
                        middle = last;
                    }

                    // visit the nodes from pred to p
                    // again reverse
                    first = curr;
                    middle = curr;
                    while(middle != curr){
                        std::cout<<" "<<middle->data;
                        last = middle->right;
                        middle->right = first;
                        first = middle;
                        middle = last;
                    }
                    pred->right = NULL;
                    curr = curr-> right;
                }
            }
        }
    };
#endif