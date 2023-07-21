#include "Reading.hpp"
#include "NumberList.hpp"

Reading :: Reading(string filename) {
    this->filename = filename;

    int count = linecount();

    // Bellekte dizi oluşturun
    this->line = new NumberList*[count];
    for (int i = 0; i < count; i++) {
        this->line[i] = new NumberList();
    }
}


NumberList** Reading :: readline() {
    string token;
    int i = 0;
    ifstream file(this->filename);
    string str;
    int index = 0;
    while (getline(file, token)) {
        istringstream ss(token);

        this->line[i]->StringAdd(token);
        i++;
    }
    file.close();
    return line; // Eğer NumberList döndürmek istiyorsanız uygun bir dönüş değeri verin.
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

Reading :: ~Reading() {
    int count = linecount();
    for (int i = 0; i < count; i++) {
        delete this->line[i];
    }
    delete[] this->line; // Bellek sızıntısını önlemek için line dizisini serbest bırakın
}

void NumberList::PrintList() {
    cout << "List: " << List << endl;
}