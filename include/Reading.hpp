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
    int LineCount;
    public:
    Reading(string filename);
    int linecount();
    void readline();
    ~Reading();
    NumberList* GetNumberlist();
};

#endif