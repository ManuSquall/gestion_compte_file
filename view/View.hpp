#pragma once
#include <iostream>
#include "../model/transaction/Transaction.hpp"

using namespace std;
using namespace model;

namespace view {
    class View {

    public:
        View();
        ~View();

        int choixCompte();
        int saisieInt(std::string lib);
        int saisieJour();
        int saisieMois();
        int menuPrincipal();
        int getTypeTransac();

        void listTransactions(vector <Transaction *> transaCompte);
        
    };
};