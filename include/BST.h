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

        explicit Node(T key) {
            leftChild = nil;
            rightChild = nil;
            parent = nil;
            this->key = key;
        }

        Node() {
            leftChild = nil;
            rightChild = nil;
            parent = nil;
            color = black;
        }

        ~Node() {} //doesn't really do anything just habit

        Node *min(Node *root) {
            Node *curr = root;
            Node *pred = nil;
            while (curr->leftChild != nil) {
                pred = curr;
                curr = curr->leftChild;
            }
            return curr->key;
        }

        Node *max(Node *root) {
            Node *curr = root;
            Node *pred = nil;
            while (curr->rightChild != nil) {
                pred = curr;
                curr = curr->rightChild;
            }
            return curr->key;
        }

        Node *search_helper(T &data, Node *curr) {
            while (curr != nil) {
                if (curr->key == data)
                    return curr;
                else if (curr->key < data)
                    search_helper(data, curr->leftChild);
                else
                    search_helper(data, curr->rightChild);
            }
            return nil;
        }

        Node *successor(Node *curr) {
            if (curr == nil) {
                return nil;
            } else if (curr->rightChild != nil) {
                return min(curr->rightChild);
            } else {
                Node *p = curr->parent;
                while (p != nil && curr == p->rightChild) {
                    curr = p;
                    p = curr->parent;
                }
                return p;
            }
        }

        Node *predecessor(Node *curr) {
            if (curr == nil) {
                return nil;
            } else if (curr->leftChild != nil) {
                return max(curr->rightChild);
            } else {
                Node *p = curr->parent;
                while (p != nil && curr == p->leftChild) {
                    curr = p;
                    p = curr->parent;
                }
                return p;
            }
        }
    };

    void RBT-Insert-Fix(Node
    * prob){
        Node * y = nil;
        while (prob->parent->color == red) {
            if (prob->parent == prob->parent->parent->leftChild) {
                y = prob->parent->parent->rightChild;
                if (y->color == red) {
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
                if (y->color == red) {
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

    void RBT-Delete-Fix(Node * shifted) {
        Node * sib = nil;
        while (shifted != root && shifted->color == black){
            if (shifted == shifted->parent->leftChild){
                sib = shifted->parent->leftChild;
                if (sib->color == red){
                    sib->color = black;
                    shifted->parent->color = red;
                    leftRotate(shifted->parent);
                    sib = shifted->parent->rightChild;
                }
                if (sib->leftChild->color == black && sib->rightChild->color == black){
                    sib->color = red;
                    shifted = shifted->parent;
                } else {
                    if (sib->rightChild->color == black) {
                        sib->leftChild->color = black;
                        sib->color = red;
                        rightRotate(sib);
                        sib = shifted->parent->rightChild;
                    }
                    sib->color = shifted->parent->color;
                    shifted->parent->color = black;
                    sib->rightChild->color = black;
                    leftRotate(shifted->parent);
                    shifted = root;
                }
            } else {
                sib = shifted->parent->rightChild;
                if (sib->color == red){
                    sib->color = black;
                    shifted->parent->color = red;
                    rightRotate(shifted->parent);
                    sib = shifted->parent->leftChild;
                }
                if (sib->rightChild->color == black && sib->leftChild->color == black){
                    sib->color = red;
                    shifted = shifted->parent;
                } else {
                    if (sib->leftChild->color == black) {
                        sib->rightChild->color = black;
                        sib->color = red;
                        leftRotate(sib);
                        sib = shifted->parent->leftChild;
                    }
                    sib->color = shifted->parent->color;
                    shifted->parent->color = black;
                    sib->leftChild->color = black;
                    rightRotate(shifted->parent);
                    shifted = root;
                }
            }
        }
    }

    void leftRotate(Node * root) {
        if (root->rightChild == nil) {
            throw "leftRotate undefined for nil right child"
        }
        Node * rc = root->rightChild;
        //reset root == root parent link to be root rc === root parent link
        rc->parent = root->parent;
        if (root->parent != nil) {
            if (root == root->parent->rightChild)
                root->parent->rightChild = rc;
            else
                root->parent->leftChild = rc;
        } else {
            this->root = rc;
        }

        //replace root's right child
        root->rightChild = rc->leftChild;
        if (root->rightChild != nil)
            root->rightChild->parent = root;

        //reset who is child and who is parent in root == root rc relationship
        root->parent = rc;
        rc->leftChild = root;

    }

    void rightRotate(Node * root) {
        if (root->leftChild == nil) {
            throw "rightRotate undefined for nil left child"
        }

        Node * lc = root->leftChild;
        //reset root == root parent link to be root rc === root parent link
        rc->parent = root->parent;
        if (root->parent != nil) {
            if (root == root->parent->rightChild)
                root->parent->rightChild = lc;
            else
                root->parent->leftChild = lc;
        } else {
            this->root = lc;
        }

        //replace root's right child
        root->leftChild = lc->rightChild;
        if (root->rightChild != nil)
            root->rightChild->parent = root;

        //reset who is child and who is parent in root == root rc relationship
        root->parent = lc;
        lc->rightChild = root;
    }

    void transplant(Node * replacee, Node * replacer){
        if (replacee->parent == nil)
            root = replacer;
        else if (replacee == replacee->parent->leftChild)
            replacee->parent->leftChild = replacer;
        else
            replacee->parent->rightChild = replacer;
        replacer->parent = replacee->parent;
    }
}

public:

    BST() {
        nil = Node();
        root = nil;
        root->leftChild = nil;
        root->rightChild = nil;
    }

    bool search(T &data) {
        return search_helper(data, root) != nil;
    }

    T &min() {
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

    T &max() {
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

    T &successor(T &curr) {
        Node * curr_node = search_helper(curr, root);
        if (curr_node == nil) {
            throw "Cannot find input value in tree";
        }
        curr_node = successor(curr_node);
        if (curr_node == nill) {
            throw "successor DNE";
        }
        return *curr_node;
    }

    T successorCopy(T &curr) {
        Node * curr_node = search_helper(curr, root);
        if (curr_node == nill) {
            throw "Cannot find input value in tree";
        }
        curr_node = successor(curr_node);
        if (curr_node == nill) {
            throw "successor DNE";
        }
        return *curr_node;
    }

    T &predecessor(T &curr) {
        Node * curr_node = search_helper(curr, root);
        if (curr_node == nil) {
            throw "Cannot find input value in tree";
        }
        curr_node = predecessor(curr_node);
        if (curr_node == nil) {
            throw "predecessor DNE";
        }
        return *curr_node;
    }

    T predecessorCopy(T &curr) {
        Node * curr_node = search_helper(curr, root);
        if (curr_node == nil) {
            throw "Cannot find input value in tree";
        }
        curr_node = predecessor(curr_node);
        if (curr_node == nil) {
            throw "predecessor DNE";
        }
        return *curr_node;
    }

    void insert(T &data) {
        //insert node as red
        Node * p = nil;
        Node * curr = root;
        while (curr != nil) {
            if (curr->data > data) {
                p = curr;
                curr = curr->leftChild;
            } else if (curr->data < data) {
                p = curr;
                curr = curr->rightChild;
            } else {
                throw "no repeats allowed";
            }
        }
        Node * insert = Node(data);
        curr = insert;
        curr->parent = p;
        curr->leftChild = nill;
        curr->rightChild = nill;

        if (p == nil) {
            root = curr;
            curr->color = black;
            return;
        } else if (curr = p->leftChild) {
            p->leftChild = curr;
        } else {
            p->rightChild = curr;
        }

        curr->color = red;
        RBT - Insert - Fix(curr);

    }

    void remove(T &data) {
        Node * rmv = search_helper(data);
        Node * swappee = rmv;
        Node * swapper = nil;
        Color origSwappee = swappee->color;
        if (rmv == nil) {
            return;
        } else if (rmv->leftChild == nil) {
            swapper = rmv->rightChild;
            transplant(rmv,rmv->rightChild);
        } else if (rmv->rightChild == nil) {
            swapper = rmv->leftChild;
            transplant(rmv,rmv->leftChild);
        } else {
            //replace with in-order successor b/c both children exist
            swappee = min(rmv->rightChild);
            origSwappee = swappee->color;
            swapper = swappee->rightChild;
            if (swappee->parent == rmv){
                swapper->parent = swappee;
            } else {
                transplant(swappee, swappee->rightChild);
                swappee->rightChild = rmv->rightChild;
                swappee->rightChild->parent = swappee;
            }
            transplant(rmv,swappee);
            swappee->leftChild = rmv->leftChild;
            swappee->leftChild->parent = swappee;
            swappee->color = rmv->color;
        }

        if (origSwappee == black){
            RBT-Delete-Fix(swapper);
        }
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
                    // at this point we have the correct in order structure
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