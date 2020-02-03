#pragma once
#include <iostream>
#include "../compte/Compte.hpp"
#include "../date/Date.hpp"

using namespace std;

namespace model {
    class Ce : public Compte {

    public:
        Ce();
        ~Ce();

        void setDate(Date * date);
        Date * getDate();
        
        void setTaux(int taux);
        int getTaux();

        // void test();

    private:
        int taux;
        Date * date;

    
    };
};