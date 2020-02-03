#include "Service.hpp"
#include "../view/View.hpp"


using namespace services;
using namespace view;
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
    int b = listeCompte.size();
    for(int i=0; i < b; i++) {
        cout << listeCompte[i]->getId() << endl;
        cout << listeCompte[i]->getNumero() << endl;
        cout << listeCompte[i]->getType() << endl;
        cout << listeCompte[i]->getSolde() << endl;
        cout << "\n\n";
        // cout << "squall";
    }
    cin.clear();
    cin.ignore();
    cin.get();
    
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

    

    
    showCompte(listeCompte);
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

    return t;
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



