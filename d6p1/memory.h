#pragma once

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// A memory bank
class Bank {

private:
    vector<int> _blocks;

public:
    Bank(vector<int> numbers);
    size_t length();
    string str();

};

class Memory {

private:
    vector<Bank> _banks;

public:
    Memory();
    Bank largest_bank();

};
