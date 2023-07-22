#include "NumberList.hpp"

NumberList::NumberList(int value) {
    this->List = "";
    this->LineCount = value;
    this->Lines = NULL;
    onesHead = NULL;
    tensHead = NULL;
}



NumberList::~NumberList() {
    // Implement destructor logic if needed.
}

void NumberList::StringAdd(string str) {
     
     
    int number = stoi(str);
    int oneDigit = number / 10; 
    int twoDigit = number % 10;
    AddUpList  (oneDigit);
    AddDownList(twoDigit);
     
    
}

void NumberList::AddUpList(int value){
   
    Node* new_node = new Node(value);
     
    if (onesHead == NULL) {
            
            onesHead = new_node;
            
        } else {
            
            Node* current = onesHead;
            while (current->Up != NULL) {
                current = current->Up;
            }
            current->Up = new_node;
        }
  
}
void NumberList::AddDownList(int value){

         Node* new_node = new Node(value);
    if (tensHead == nullptr) {
            tensHead = new_node;
        } else {
            Node* current = tensHead;
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