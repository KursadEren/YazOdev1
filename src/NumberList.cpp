#include "NumberList.hpp"


NumberList::NumberList(int value) {
    this->DownListCount=0;
    this->UpListCount=0;
    this->LineCount = value;
    this->Lines = new NumberList*[value]; // 'Lines' dizisini 'value' kadar elemanla oluşturun
    for (int i = 0; i < value; i++) {
        Lines[i] = nullptr; // Her elemanı başlangıçta nullptr yapın
    }
    onesHead = nullptr;
    tensHead = nullptr;
}




NumberList::~NumberList() {
    // 'onesHead' ve 'tensHead' düğümlerini silmek için yardımcı işlevi çağırın
    for(int i = 0; i<this->LineCount; i++)
    {
         DestroyUpNodes(this->Lines[i]->onesHead);
         DestroyDownNodes(this->Lines[i]->tensHead);
    }
   

    // Bellekte dinamik olarak oluşturulan 'Lines' dizisini temizleyin
    
    delete[] Lines;
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
     
    this->UpListCount++;
}

void NumberList::AddDownList(int value){
    AddDownNode(value, tensHead);
    this->DownListCount++;
}



// ... (sınıf tanımlaması ve diğer fonksiyonlar) ...

void NumberList::AddUpListPrint() {
    int count = this->LineCount;
    for (int i = 0; i < count; i++) {
        Node* current = Lines[i]->onesHead;
        cout << "Line " << i << " (Up List): ";
        while (current) {
            cout << current->data << " -> ";
            current = current->Up;
        }
        cout << "None" << endl;
    }
}

void NumberList::AddDownListPrint() {
    int count = this->LineCount;
    for (int i = 0; i < count; i++) {
        Node* current = Lines[i]->tensHead;
        cout << "Line " << i << " (Down List): ";
        while (current) {
            cout << current->data << " -> ";
            current = current->Down;
        }
        cout << "None" << endl;
    }
}

// ... (diğer fonksiyonlar ve sınıf tanımlamasının kalan kısmı) ...


void NumberList::DestroyUpNodes(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->Up; // Aşağı yönlü bağlı liste için 'Up' kullanıyoruz
        delete temp;
    }
}
void NumberList::DestroyDownNodes(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->Down; 
        delete temp;
    }
}



void NumberList::AddUpNode(int value, Node* head) {
    Node* new_node = new Node(value);
    
    
 
    if (onesHead == nullptr) {
        
        onesHead = new_node;
         
    } else {
        Node* current = onesHead;
          
        while (current->Up != NULL) {
           
        current = current->Up;
        }
        
        current->Up = new_node;
        
       
    }
     
}


void NumberList::AddDownNode(int value, Node* head) {
    Node* new_node = new Node(value);
    
    
    if (tensHead == nullptr) {
        tensHead = new_node;
    } else {
        Node* current = tensHead;
        while (current->Down != NULL) {
            
            current = current->Down;
        }
        current->Down = new_node;
        
    }
   
}

double NumberList::CalculateUpListAverage(int value){
    
 
}
double NumberList::CalculateDownListAverage(int value){


}
void NumberList::PrintUpDownCount(){
    for(int i = 0 ; i<this->LineCount; i++)
    {
         cout<<i <<" "<< this->Lines[i]->DownListCount<< endl;
         cout<<i << " " << this->Lines[i]->UpListCount<<endl;
    }
   
}