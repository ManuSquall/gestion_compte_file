#include "Service.hpp"
#include "../view/View.hpp"
#include "../squall/Squall.hpp"


using namespace services;
using namespace view;
using namespace squall;
using namespace std;

Service::Service() {

}

Service::~Service() {

}

Compte * Service::createCompte(){

    
    Compte * c;
    View * vue = new View();
    
    switch (vue->choixCompte()){
        case 1:
            c= new Ce();
            break;
        case 2:
            c= new Cc();
            break;
            
    }
    return c;
}

void Service::addCompte(vector<Compte*> &listeCompte,Compte * c){
    listeCompte.push_back(c);
}

void Service::showCompte(vector<Compte*> &listeCompte){
    View * vue = new View();
    Squall * utils = new Squall();
    int b = listeCompte.size();
    for(int i=0; i < b; i++) {
        cout << "Compte n " <<i <<endl;
        vue->showACompte(listeCompte[i]);
    }
    utils->pause();
    
}
Compte * Service::getCompteById(vector<Compte*> &listeCompte, int id){
    Compte * c;
    int b = listeCompte.size();
    for(int i=0; i < b; i++) {
        if(listeCompte[i]->getId()==id){
            c=listeCompte[i];
        }
    }
    return c;
}


Transaction * Service::createTrans(vector<Compte*> &listeCompte){

    
        Transaction * t = new Transaction();

        View * vue = new View();
        t->setType(vue->getTypeTransac());

        

        
        Service::showCompte(listeCompte);
        cout << endl;

        
        switch (t->getTypeInt())
        {
            case DEPOT:
                t->setCompte(getCompteById(listeCompte, vue->saisieInt("id du compte de DEPOT")));
                cout << endl ;
                t->setMnt(vue->saisieInt("montant de depot"));
                cout << endl ;
                break;
            case RETRAIT:
                t->setCompte(getCompteById(listeCompte, vue->saisieInt("id du compte de RETRAIT")));
                cout << endl ;
                t->setMnt(vue->saisieInt("montant de retrait"));
                cout << endl ;
                break;
            case VIREMENT:
                // not yet
                break;
            default:
                break;
        }
        //*/

        return t;
    }

void Service::showTransaction(vector<Transaction*> transactions){
    View * vue = new View();
    Squall * utils = new Squall();
    int b = transactions.size();
    for(int i=0; i < b; i++) {
        vue->showATransaction(transactions[i]);
    }
    utils->pause();
    
}

void Service::test(vector <Compte *> &listeCompte){
    Squall * utils = new Squall();
    cout << listeCompte.size();
    
    utils->pause();
}

void Service::makeTransac(vector<Transaction*> &transactions, Transaction * t){
    transactions.push_back(t);
}

vector<Transaction*> Service::getTransactionsOfCompte(vector<Transaction*> &transactions, int id){
    int b = transactions.size();
    vector <Transaction *> transaCompte;
    for(int i=0; i < b; i++) {
        if(transactions[i]->getCompte()->getId()==id){
            transaCompte.push_back(transactions[i]);
        }
    }

    return transaCompte;
}

void Service::listTransactionOfCompte(vector<Transaction*> &transactions, vector<Compte*> &listeCompte){
    Service::showCompte(listeCompte);
    cout << endl;
    View * vue = new View();

    showTransaction(getTransactionsOfCompte(transactions,vue->saisieInt("id du compte à afficher")));


}




