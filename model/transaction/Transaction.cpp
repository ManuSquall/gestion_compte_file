#include "Transaction.hpp"
#include <vector>


using namespace model;

unsigned int Transaction::cpt =0;

Transaction::Transaction() {
    Squall * utils = new Squall();

    Date * d = new Date();

    Transaction::cpt++;
    id=Transaction::cpt;

    // get the current date
    vector <string> s = utils->explode(utils->getDateInStr(), '-');
//  #####################################
    // cout << s[0] <<endl;
    // cout << s[1] <<endl;
    // cout << s[2] <<endl;
    
    
    // cout << s[0] <<endl;
    string z = s[0].c_str();
    string y = s[1].c_str();
    string w = s[2].c_str();
    // date->setJour(atoi((z.c_str())));

    // int b = stoi(z);
    // int e = stoi(y);
    // int d = stoi(w);
    // cout << b;



   

    d->setJour(atoi(s[0].c_str()));
    d->setMois(atoi(s[1].c_str()));
    d->setAnne(atoi(s[2].c_str()));

    // cout << d->getJour() << endl;
    // cout << d->getMois() << endl;
    // cout << d->getAnne() << endl;
    // date->setJour(b);
    // date->setMois(e);
    // date->setAnne(d);
    date=d;


    

}

Transaction::~Transaction() {

}

void Transaction::setType(int  type) {
    this-> type =  type;
}

int Transaction::getTypeInt() {
    return  type;
}

string Transaction::getTypeString() {
    string chaine;
    switch(type){
        case 1:
            chaine = "DEPOT";
            break;
        case 2:
            chaine = "RETRAIT";
            break;
        case 3:
            chaine = "VIREMENT";
            break;
        default:
            break;
    }
    return chaine;
}

void Transaction::setMnt(int mnt) {
    this->mnt = mnt;
}

int Transaction::getMnt() {
    return mnt;
}

void Transaction::setId(int id) {
    this->id = id;
}

int Transaction::getId() {
    return id;
}

void Transaction::setCompte(Compte * c) {
    this->compte = c;
}

Compte * Transaction::getCompte() {
    return compte;
}

void Transaction::setDate(Date * date) {
    this->date = date;
}

Date * Transaction::getDate() {
    return date;
}