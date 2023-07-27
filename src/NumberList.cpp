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
         DestroyUpNodes  (this->Lines[i]->onesHead);
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
      cout << "Birinci geçiş "<< endl;
    AddUpNode(value, this->onesHead);
     cout << "ikinci geçiş "<< endl;
    this->UpListCount++;
}

void NumberList::AddDownList(int value){
    AddDownNode(value, this->tensHead);
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
    onesHead = nullptr;
}
void NumberList::DestroyDownNodes(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->Down; 
        cout << temp<<endl;
        delete temp;
    }
    tensHead = nullptr;
}



void NumberList::AddUpNode(int value, Node* head) {
    Node* new_node = new Node(value);
    
    
 
    if (onesHead == nullptr) {
        
        onesHead = new_node;
         cout << "Hey";
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
        Node* current = head;
        while (current->Down != NULL) {
            
            current = current->Down;
        }
        current->Down = new_node;
        
    }
   
}

void NumberList::CalculateUpListAverage() {
    double totalSum = 0;
    double LineSum = 0;
    int digits =0;
    int nodeCount = 0;
    int UpNodeMax = FindMaxUpNodeCount();

    for (int a = 0; a < UpNodeMax; a++) {
        LineSum = 0;
        nodeCount = 0;

        for (int i = 0; i < LineCount; i++) {
            
                digits = FindUpNodeData(a, this->Lines[i]->onesHead);
               
                if(digits != -1)
                {
                     LineSum += digits;
                     nodeCount++;
                }
               
                
            
        }
                 cout << "Digits " << digits   << " " << a  <<  " Line " << LineSum  <<endl;
                 cout << "-----------------------------------------"<< endl;
        totalSum += (LineSum / nodeCount);
    }

    cout << totalSum << "Total sum" << endl;
}


void NumberList::CalculateDownListAverage() {
    double totalSum = 0;
    double LineSum = 0;
    int digits =0;
    int nodeCount = 0;
    int UpNodeMax = FindMaxDownNodeCount();

    for (int a = 0; a < UpNodeMax; a++) {
        LineSum = 0;
        nodeCount = 0;

        for (int i = 0; i < LineCount; i++) {
            
                digits = FindDownNodeData(a, this->Lines[i]->tensHead);
               
                if(digits != -1)
                {
                     LineSum += digits;
                     nodeCount++;
                }
               
                
            
        }
                 cout << "Digits " << digits   << " " << a  <<  " Line " << LineSum  <<endl;
                 cout << "-----------------------------------------"<< endl;
        totalSum += (LineSum / nodeCount);
    }

    cout << totalSum << "Total sum" << endl;
}
void NumberList::PrintUpDownCount() {
    int maxDownListCount = 0;
    int maxUpListCount = 0;
    int maxDownListIndex = -1;
    int maxUpListIndex = -1;

    for (int i = 0; i < this->LineCount; i++) {
        cout << "Line " << i << " DownListCount: " << this->Lines[i]->DownListCount << endl;
        cout << "Line " << i << " UpListCount: " << this->Lines[i]->UpListCount << endl;

    }
    int i = FindMaxDownNodeCount();
    int a =FindMaxUpNodeCount();
    cout << i << endl;
    cout << a<< endl;
   
}
int NumberList::FindMaxDownNodeCount() {
    int maxDownListCount = 0;
    int maxDownListIndex = -1;

    for (int i = 0; i < this->LineCount; i++) {
        if (this->Lines[i]->DownListCount > maxDownListCount) {
            maxDownListCount = this->Lines[i]->DownListCount;
            maxDownListIndex = i;
        }
    }

    return maxDownListCount;
}

int NumberList::FindMaxUpNodeCount() {
    int maxUpListCount = 0;
    int maxUpListIndex = -1;

    for (int i = 0; i < this->LineCount; i++) {
        if (this->Lines[i]->UpListCount > maxUpListCount) {
            maxUpListCount = this->Lines[i]->UpListCount;
            maxUpListIndex = i;
        }
    }

    return maxUpListCount;
}


int NumberList::FindUpNodeData(int value,Node *head)  
{   
    Node* current = head;
    if(value==0)
    {
          return current->data;
    }
    for(int i = 0; i<value ;i++)
    {
        
        current=current->Up;
        
    }
         if(current == nullptr)
         {
            return -1;
         }else{
           return current->data;
         }
        
}
int  NumberList::FindDownNodeData(int value,Node *head)
{
        Node* current = head;
    if(value==0)
    {
          return current->data;
    }
    for(int i = 0; i<value ;i++)
    {
        
        current=current->Down;
        
    }
         if(current == nullptr)
         {
            return -1;
         }else{
           return current->data;
         }
}

void NumberList::SwipNode(int One, int Two) {
    string Upstr = GetUpNodeData(Lines[One]->onesHead);
    string Downstr = GetDownNodeData(Lines[Two]->tensHead);
    
    // Mevcut düğümleri sil
    DestroyUpNodes(this->Lines[One]->onesHead);
    DestroyDownNodes(this->Lines[Two]->tensHead);
     Lines[One]->onesHead = nullptr;
     Lines[Two]->tensHead = nullptr;
       Lines[One]->UpListCount = 0;
       Lines[Two]->DownListCount = 0;
    // Upstr dizesini parse ederek düğümleri tekrar oluştur
    istringstream ss(Downstr);
    string value_str;
    while (ss >> value_str) {
        int value = stoi(value_str);
        Lines[One]->AddUpList(value);
    }

    // Downstr dizesini parse ederek düğümleri tekrar oluştur
    istringstream aa(Upstr);
    while (aa >> value_str) {
        int value = stoi(value_str);
        Lines[Two]->AddDownList(value);
    }
}




string NumberList::GetUpNodeData(Node* head) {
    Node* current = head;
    string dataString;

    while (current != nullptr) {
        dataString += to_string(current->data) + " ";
        current = current->Up;
    }

    
    return dataString;
}

string NumberList::GetDownNodeData(Node* head) {
    Node* current = head;
    string dataString;

    while (current != nullptr) {
        dataString += to_string(current->data) + " ";
        current = current->Down;
    }

    
    return dataString;
}