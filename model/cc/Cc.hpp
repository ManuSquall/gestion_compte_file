#pragma once
#include <iostream>
#include "../compte/Compte.hpp"

using namespace std;

namespace model {
    class Cc : public Compte {

    public:
        Cc();
        ~Cc();

        void setInteret(int interet);
        
        int getInteret();

        // void test();


    private:
        int interet;

    
    
    };
};