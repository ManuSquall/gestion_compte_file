#include "Date.hpp"
#include "../../view/View.hpp"

using namespace view;
using namespace model;

Date::Date() {

}

Date::~Date() {

}

void Date::setAnne(int  an) {
    this-> anne =  an;
}

int Date::getAnne() {
    return  anne;
}

void Date::setMois(int mois) {
    this->mois = mois;
}

int Date::getMois() {
    return mois;
}

void Date::setJour(int jour) {
    this->jour = jour;
}

int Date::getJour() {
    return jour;
}

void Date::saisie(){
    View * vue = new View();
    // Date * d = new Date();
    // d->setJour(vue->saisieJour());
    // d->setMois(vue->saisieMois());
    // d->setAnne(vue->saisieInt("anne"));
    setJour(vue->saisieJour());
    setMois(vue->saisieMois());
    setAnne(vue->saisieInt("anne"));
    // this->jour=vue->saisieJour();
    // this->mois=vue->saisieMois();
    // this->anne=vue->saisieInt("anne");
}

void Date::affiche(){
    cout << getJour() << "-" << getMois() << "-" << getAnne();

}
