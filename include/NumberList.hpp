#ifndef NUMBERLIST_HPP
#define NUMBERLIST_HPP

#include <iostream>
#include <string>
#include <sstream>
#include "Node.hpp"
using namespace std;

class NumberList {
  private:
    int UpListCount;
    int DownListCount;
    int LineCount;
    
    Node* onesHead; // Birler basamağı için aşağı yönlü bağlı listenin başı
    Node* tensHead; // Onlar basamağı için yukarı yönlü bağlı listenin başı

    //...

    void AddUpNode(int value, Node* head);
    void AddDownNode(int value, Node* head);
    NumberList** Lines;
    
    void DestroyUpNodes(Node* head);
    void DestroyDownNodes(Node* head);

    friend class Reading;
public:
  
    NumberList(int value);
    ~NumberList();
    void StringAdd(string str);
    void AddUpList  (int value);
    void AddDownList(int value);
    void AddUpListPrint();
    void AddDownListPrint();
    void CalculateUpListAverage  ();
    void CalculateDownListAverage();
    void PrintUpDownCount();
    int FindMaxUpNodeCount();
    int FindMaxDownNodeCount();
    int FindUpNodeData(int value,Node *head);
    int FindDownNodeData(int value,Node *head);
    void SwipNode(int value,int value2);
    string GetUpNodeData(Node* head);
    string GetDownNodeData(Node* head);
   
};

#endif // NUMBERLIST_HPP
