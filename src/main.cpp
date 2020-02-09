#include <iostream>

#include "../service/Service.hpp"
#include "../view/View.hpp"


using namespace services;
using namespace view;

int main() {
    vector <Compte *> listecompte;
    vector <Transaction *> transactions;
    Service * fonc = new Service();
    View * vue = new View();

    mprinci:;
    switch (vue->menuPrincipal())
    {
    case 1:
        fonc->addCompte(listecompte,fonc->createCompte());
        goto mprinci;
        break;
    case 2:
        // cout << "squall";
        // cin.clear();
        // cin.ignore();
        // cin.get();
        // fonc->showCompte(listecompte);

        // fonc->test();
        // fonc->createTrans(listecompte);
        fonc->makeTransac(transactions, fonc->createTrans(listecompte));
        goto mprinci;
        break;
    case 3:
        // fonc->showCompte(listecompte);
        fonc->listTransactionOfCompte(transactions, listecompte);
        goto mprinci;
        break;
    default:
        break;
    }
    
    //  creer un compte
    // view pour les menus

    // Cc * a = new Cc();
    // Ce * b = new Ce();

    // a->test();
    // cout << endl << endl;
    // b->test();
    // cout << "squall";

}