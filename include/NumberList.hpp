#ifndef NUMBERLIST_HPP
#define NUMBERLIST_HPP

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class NumberList {
  private:
    string List;
    int LineCount;
    struct Node {
        int data;
        Node* Up;
        Node* Down;
        Node(int val) : data(val), Up(NULL),Down(NULL) {}
    };

    Node* onesHead; // Birler basamağı için aşağı yönlü bağlı listenin başı
    Node* tensHead; // Onlar basamağı için yukarı yönlü bağlı listenin başı
    NumberList** Lines;
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
