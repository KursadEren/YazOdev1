#ifndef READING_HPP
#define READING_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "NumberList.hpp"
using namespace std;
class Reading {
    private:
    NumberList ** line;
    string filename;
    public:
    Reading(string filename);
    int linecount();
    NumberList** readline();
    ~Reading();

};

#endif