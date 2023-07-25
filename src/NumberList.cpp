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
    // 'onesHead' ve 'tensHead' düğümlerini silmek için yardımcı işlevi çağırın
    DestroyNodes(onesHead);
    DestroyNodes(tensHead);

    // Bellekte dinamik olarak oluşturulan 'Lines' dizisini temizleyin
    for (int i = 0; i < LineCount; i++) {
        delete Lines[i];
    }
    delete[] Lines;
}

void NumberList::StringAdd(string str) {
     
     
    int number = stoi(str);
    int oneDigit = number / 10; 
    int twoDigit = number % 10;
     cout << "Hey0"<<endl;
    AddUpList(oneDigit);
    cout << "Hey1"<<endl;
    AddDownList(twoDigit);
      cout << "Hey2"<<endl;
    
}

void NumberList::AddUpList(int value){
    AddUpNode(value, onesHead);
}

void NumberList::AddDownList(int value){
    AddDownNode(value, tensHead);
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
void NumberList::DestroyNodes(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->Up; // Aşağı yönlü bağlı liste için 'Up' kullanıyoruz
        delete temp;
    }
}



void NumberList::AddUpNode(int value, Node* &head) {
    Node* new_node = new Node(value);
    cout<< onesHead ;
    if (onesHead == nullptr) {
        
        onesHead = new_node;
         
    } else {
        cout << "hey"<<endl; 
        Node* current = onesHead;
        while (current->Up != nullptr) {
            current = current->Up;
        }
       
        current->Up = new_node;
    }
    
}

void NumberList::AddDownNode(int value, Node* &head) {
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

