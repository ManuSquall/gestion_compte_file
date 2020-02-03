#pragma once
#include <iostream>
#include "../../squall/Squall.hpp"


using namespace std;
using namespace squall;


namespace model {

    typedef enum
    {
        EPARGNE = 1, CHEQUE
    }TYPEC;

    class Compte {

    public:
        

        Compte();
        ~Compte();

        void setSolde(int solde);
        void setNumero(string numero);
        void setId(int id);
        void setType(int type);
    
        int getSolde();
        string getNumero();
        int getId();
        int getType();

        void genererNumero();
        void saisie();

    private:
        int id;
        string numero;
        int solde;
        int type;

        static unsigned int cpt;

    
    
        
        
    };
};