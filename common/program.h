#pragma once

#include <fstream>
#include <iostream>
#include <iterator>
#include <optional>
#include <sstream>
#include <string>
#include <vector>
#include "util.h"

using namespace std;

using position_t = unsigned int;
using counter_t = unsigned int;

class Program {

private:
    vector<int> _instructions;
    position_t _ip; // "instruction pointer";
    bool _reached_completion;

public:
    Program(const vector<int> instructions);
    Program(const string filename);
    void list_instructions();
    string str();
    optional<int> current();
    bool jump(int offset);
    bool next();
    bool execute();
    bool inc();
    int run(const unsigned int max_steps);
    int run(); // run silently and potentially in an endless loop

};
