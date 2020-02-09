#pragma once
#include <iostream>
#include <fstream>
#include "../model/compte/Compte.hpp"
#include "../model/transaction/Transaction.hpp"
#include "../squall/Squall.hpp"

using namespace std;
using namespace model;
using namespace squall;


namespace fao{
    class Fao {

    public:
        Fao();
        ~Fao();

            vector<Compte*> loadComptes(); //done
            vector<Transaction*> loadTransactions(); // done

            int majAllComptes(vector<Compte*> listeCompte); //done
            int majAllTransactions(vector<Transaction*> transactions); //done

            
            void saveAllCompte(vector<Compte*> listeCompte);
            void saveAllTransaction(vector<Transaction*> transactions);

            

            int saveTest(int a);
            int loadTest();
        

    private:
        string cfile;
        string tfile;
    };

};