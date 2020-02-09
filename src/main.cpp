#include <iostream>

#include "../service/Service.hpp"
#include "../view/View.hpp"
#include "../fao/Fao.hpp"


using namespace services;
using namespace view;
using namespace fao;

int main() {

    Fao * fao = new Fao();
    
    ///*
    vector <Compte *> listecompte;
    vector <Transaction *> transactions;
    Service * fonc = new Service();
    View * vue = new View();
    listecompte = fao->loadComptes();
    transactions = fao->loadTransactions();
    mprinci:;
    switch (vue->menuPrincipal())
    {
    case 1:
        system("clear");
        fonc->addCompte(listecompte,fonc->createCompte());
        fao->majAllComptes(listecompte);
        goto mprinci;
        break;
    case 2:
        system("clear");
        // cout << "squall";
        // cin.clear();
        // cin.ignore();
        // cin.get();
        // fonc->showCompte(listecompte);

        // fonc->test(listecompte);
        // fonc->createTrans(listecompte);

        if(listecompte.size()!=0){
            fonc->makeTransac(transactions, fonc->createTrans(listecompte));
            fao->majAllTransactions(transactions);
            fao->majAllComptes(listecompte);
        }else{
            cout << "veuillez créer des comptes svp" << endl;
        }
        
        goto mprinci;
        break;
    case 3:
        system("clear");

        if(listecompte.size()!=0){
           fonc->listTransactionOfCompte(transactions, listecompte);
        }else{
            cout << "veuillez créer des comptes svp" << endl;
        }
        
        goto mprinci;
        break;
    default:
        break;
    }

    //*/
    
    //  creer un compte
    // view pour les menus

    // Cc * a = new Cc();
    // Ce * b = new Ce();

    // a->test();
    // cout << endl << endl;
    // b->test();
    // cout << "squall";

}