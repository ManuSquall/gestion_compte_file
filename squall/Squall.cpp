#include "Squall.hpp"

using namespace squall;
using namespace std;


Squall::Squall() {

}

Squall::~Squall() {

}

string Squall::getTime(){
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%X", &tstruct);

    std::string str =buf;
    str.erase(std::remove(str.begin(), str.end(), ':'), str.end());
    
    return str;
}

string Squall::getDateInStr(){
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d-%m-%Y", &tstruct);

    std::string str =buf;
    str.erase(std::remove(str.begin(), str.end(), ':'), str.end());
    
    return str;
}

vector<std::string> Squall::explode(std::string const & s, char delim)
{
    std::vector<std::string> result;
    std::istringstream iss(s);

    for (std::string token; std::getline(iss, token, delim); )
    {
        result.push_back(std::move(token));
    }

    return result;
}

void Squall::pause(){
    cout << "Appuyer sur \"entrée\" pour continuer" <<endl;
    cin.clear();
    cin.ignore();
    cin.get();
}

