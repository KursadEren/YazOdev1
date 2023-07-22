#include "Reading.hpp"
#include "NumberList.hpp"

int main() {
    // "Veri.txt" dosyasının adını burada gösterildiği gibi değiştirin
    Reading* read = new Reading("Veri.txt");
     cout << "Hey";
    NumberList* Number = new NumberList(read->linecount());
     cout << "Hey1";
    read->readline();
     cout << "Hey2";
   
    Number = read->GetNumberlist();

}
