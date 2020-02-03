#pragma once

#include "../date/Date.hpp"
#include "../../squall/Squall.hpp"
#include "../compte/Compte.hpp"



using namespace std;
using namespace model;
using namespace squall;


namespace model {

    typedef enum
    {
        DEPOT = 1, RETRAIT, VIREMENT
    }TYPET;

class Transaction {

    public:
        Transaction();
        ~Transaction();

        void setType(int  type);
        
        int getTypeInt();
        
        string getTypeString();
        
        void setMnt(int mnt);
        
        int getMnt();
        
        void setId(int id);
        
        int getId();

        void setCompte(Compte * c);

        Compte * getCompte();

        void setDate(Date * date);

        Date * getDate();

    private:
        int id, mnt, type;
        Date * date;
        static unsigned int cpt;
        Compte * compte;
    };
};