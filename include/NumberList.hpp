#ifndef NUMBERLIST_HPP
#define NUMBERLIST_HPP
#include <iostream>
#include <string>
using namespace std;
class NumberList {
private:
  string List;
     struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
       };
       Node* onesHead; // Birler basamağı için aşağı yönlü bağlı listenin başı
       Node* tensHead; // Onlar basamağı için yukarı yönlü bağlı listenin başı

    

public:
    NumberList();
    ~NumberList();
    NumberList* StringAdd(string str);
   
    
   
};

#endif // NUMBERLIST_HPP
