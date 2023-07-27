#include "Reading.hpp"
#include "NumberList.hpp"

int main() {
    // "Veri.txt" dosyasının adını burada gösterildiği gibi değiştirin
    Reading* read = new Reading("Veri.txt");
   
    NumberList* Number = new NumberList(read->linecount());
    read->readline();
    Number = read->GetNumberlist();
    Number->PrintUpDownCount();
   
     }
