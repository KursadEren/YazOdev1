#include "Reading.hpp"
#include "NumberList.hpp"

int main() {
    // "Veri.txt" dosyasının adını burada gösterildiği gibi değiştirin
    Reading* read = new Reading("Veri.txt");
   
    NumberList* Number = new NumberList(read->linecount());
    read->readline();
    Number = read->GetNumberlist();
    Number->PrintUpDownCount();
    Number->CalculateUpListAverage();
    Number->CalculateDownListAverage();
    int number= 0;
    int number2 = 0;
    cout << "Bir sayı girin: ";
    cin >> number;
     cout << "Bir sayı girin: ";
    cin >> number2;
    Number->SwipNode(number,number2);
     }
