#ifndef NODE_HPP
#define NODE_HPP

 class Node {
    public:
        int data;
        Node* Up;
        Node* Down;
        Node(int val,Node*Up=nullptr,Node*Down=nullptr ) {
            this->data = val;
            this->Up = Up;
            this->Down=Down;
        }
        Node() {
            this->data = 0;
            this->Up = nullptr;
            this->Down=nullptr;
        }
    };
#endif