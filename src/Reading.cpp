#include "Reading.hpp"
#include "NumberList.hpp"

Reading :: Reading(string filename) {
     
     this->filename = filename;
     this->LineCount = linecount();
    
    this->line = new NumberList*[linecount()];
    for (int i = 0; i < linecount(); i++) {
        cout << i <<endl;
        this->line[i] = new NumberList(linecount());
       
    }
   
}

void Reading :: readline() {
    string token;
    int i = 0;
   
    ifstream file(this->filename);
    string str;
   
   cout << linecount();
    while (getline(file, token)) {
        istringstream ss(token);
        while (getline(ss, str, ' ')) {
           
             
        this->line[i]->StringAdd(str);
         
         
        }
        i++;
    }
    
    file.close();
    
    // Eğer NumberList döndürmek istiyorsanız uygun bir dönüş değeri verin.
}

int Reading :: linecount() {
    int counter = 0;
    ifstream file(this->filename);
    string unused;
    while (getline(file, unused))
        ++counter;

    file.close();
    return counter;
}

NumberList* Reading::GetNumberlist() {
    NumberList* list = new NumberList(this->LineCount); // NumberList nesnesi oluşturuyoruz

    // NumberList nesnesinin Lines üye değişkenine oluşturulan işaretçi dizisini atıyoruz
    list->Lines = line;

    return list; // NumberList nesnesini döndür
}



Reading :: ~Reading() {
    int count = linecount();
    for (int i = 0; i < count; i++) {
        delete this->line[i];
    }
    delete[] this->line; // Bellek sızıntısını önlemek için line dizisini serbest bırakın
}

