#ifndef NUMBERLIST_HPP
#define NUMBERLIST_HPP

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class NumberList {
  private:
    
    int LineCount;
    struct Node {
        int data;
        Node* Up;
        Node* Down;
        Node(int val) : data(val), Up(nullptr), Down(nullptr) {}
    };

   Node* onesHead; // Birler basamağı için aşağı yönlü bağlı listenin başı
    Node* tensHead; // Onlar basamağı için yukarı yönlü bağlı listenin başı

    //...

    void AddUpNode(int value, Node* &head);
    void AddDownNode(int value, Node* &head);
    NumberList** Lines;
    void DestroyNodes(Node* head);
    friend class Reading;
public:
  
    NumberList(int value);
    ~NumberList();
    void StringAdd(string str);
    void PrintList();
    void AddUpList  (int value);
    void AddDownList(int value);
    void AddUpListPrint();
    void AddDownListPrint();
};

#endif // NUMBERLIST_HPP
