#pragma once
#include <vector>

#include "../model/compte/Compte.hpp"
#include "../model/cc/Cc.hpp"
#include "../model/ce/Ce.hpp"
#include "../model/transaction/Transaction.hpp"

using namespace model;

namespace services {
    class Service {

        public:
            Service();
            ~Service();
            

            Compte * createCompte();
            void addCompte(vector<Compte*> &listeCompte, Compte * c);
            void showCompte(vector<Compte*> &listeCompte);
            Compte * getCompteById(vector<Compte*> &listeCompte, int id);

            Transaction * createTrans(vector<Compte*> &listeCompte);
            void makeTransac(vector<Transaction*> &transactions, Transaction * t);

            vector<Transaction*> getTransactionsOfCompte(vector<Transaction*> &transactions, int id);
    };
};