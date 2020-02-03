#ifndef SQUALL_H
#define SQUALL_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <sstream>

namespace squall{



// // Get current date/time, format is YYYY-MM-DD.HH:mm:ss
// const std::string currentDateTime() {
//     time_t     now = time(0);
//     struct tm  tstruct;
//     char       buf[80];
//     tstruct = *localtime(&now);
//     // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
//     // for more information about date/time format
//     strftime(buf, sizeof(buf), "%X", &tstruct);
    
//     // replace_func(buf);
//     return buf;
// }

// int main() {
//     // std::string str ="squall";
//     std::string str =currentDateTime();
//     std::cout << str;
//     str.erase(std::remove(str.begin(), str.end(), ':'), str.end());
//     // std::cout << "currentDateTime()=" << currentDateTime() << std::endl;
//     // currentDateTime();
//     getchar();  // wait for keyboard input
//     std::cout << str;
//     getchar();  // wait for keyboard input
// }

std::string getTime(){
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%X", &tstruct);

    std::string str =buf;
    str.erase(std::remove(str.begin(), str.end(), ':'), str.end());
    
    return str;
}

std::string getDateInStr(){
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d-%m-%Y", &tstruct);

    std::string str =buf;
    str.erase(std::remove(str.begin(), str.end(), ':'), str.end());
    
    return str;
}

std::vector<std::string> explode(std::string const & s, char delim)
{
    std::vector<std::string> result;
    std::istringstream iss(s);

    for (std::string token; std::getline(iss, token, delim); )
    {
        result.push_back(std::move(token));
    }

    return result;
}

};

#endif  