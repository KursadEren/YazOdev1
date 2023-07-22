#include "Reading.hpp"
#include "NumberList.hpp"

Reading :: Reading(string filename) {
     int count = linecount();
     this->filename = filename;
     this->LineCount = count;
    // Bellekte dizi oluşturun
    this->line = new NumberList*[count];
    for (int i = 0; i < count; i++) {
        this->line[i] = new NumberList(count);
    }
}

void Reading :: readline() {
    string token;
    int i = 0;
   
    ifstream file(this->filename);
    string str;
    int index = 0;
    cout << endl;
    cout<< "Merhaba"<<endl;
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

