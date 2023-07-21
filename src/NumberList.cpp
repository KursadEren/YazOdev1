#include "NumberList.hpp"


NumberList::NumberList() {
    this->List = "";

}

NumberList::~NumberList() {

}

NumberList* NumberList::StringAdd(string str){

    this->List = str;
}

