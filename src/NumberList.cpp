#include "NumberList.hpp"


NumberList::NumberList(int value) {
   
    this->LineCount = value;
    Lines = new NumberList*[value]; // 'Lines' dizisini 'value' kadar elemanla oluşturun
    for (int i = 0; i < value; i++) {
        Lines[i] = nullptr; // Her elemanı başlangıçta nullptr yapın
    }
    onesHead = nullptr; 
    tensHead = nullptr; 
}




NumberList::~NumberList() {
    // Implement destructor logic if needed.
}

void NumberList::StringAdd(string str) {
     
     
    int number = stoi(str);
    int oneDigit = number / 10; 
    int twoDigit = number % 10;
    AddUpList(oneDigit);
    AddDownList(twoDigit);
     
    
}

void NumberList::AddUpList(int value){
    AddUpNode(value, onesHead);
}

void NumberList::AddUpNode(int value, Node* &head) {
    Node* new_node = new Node(value);
    if (head == nullptr) {
        head = new_node;
    } else {
        Node* current = head;
        while (current->Up != nullptr) {
            current = current->Up;
        }
        current->Up = new_node;
    }
}
void NumberList::AddDownList(int value){
    AddDownNode(value, tensHead);
}

void NumberList::AddDownNode(int value, Node* &head) {
    Node* new_node = new Node(value);
    if (head == nullptr) {
        head = new_node;
    } else {
        Node* current = head;
        while (current->Down != nullptr) {
            current = current->Down;
        }
        current->Down = new_node;
    }
}
void NumberList::AddUpListPrint(){
    int count = this->LineCount;
    for(int i = 0 ; i<count ; i++)
    {
        Node*Current = Lines[i]->onesHead;
        while(Current)
        {
            cout << Current->data << " -> "<<endl;
            Current = Current->Up;
            cout << "None" << std::endl;
        }
    }
    
}
void NumberList::AddDownListPrint(){

}
