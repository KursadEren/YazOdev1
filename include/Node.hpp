#ifndef NODE_HPP
#define NODE_HPP

 class Node {
    public:
        int data;
        Node* Up;
        Node* Down;
        Node(int val,Node*Up=NULL,Node*Down=NULL ) {
            this->data = val;
            this->Up = Up;
            this->Down=Down;
        }
        Node() {
            this->data = 0;
            this->Up = NULL;
            this->Down=NULL;
        }
    };
#endif