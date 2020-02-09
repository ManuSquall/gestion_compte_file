#pragma once

#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

namespace squall{

class Squall {

public:
    Squall();
    ~Squall();

    string getTime();
    string getDateInStr();
    vector<string> explode(string const & s, char delim);
    void pause();
};

};