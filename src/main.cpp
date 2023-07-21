#include "Reading.hpp"
#include "NumberList.hpp"

int main() {
    // "Veri.txt" dosyasının adını burada gösterildiği gibi değiştirin
    Reading read("Veri.txt");

    // Dosya içeriğini okuma işlemini gerçekleştirin
    NumberList** Number = read.readline();

   

}
