#include "Ce.hpp"
#include "../../view/View.hpp"

using namespace model;
using namespace view;

Ce::Ce() {
    setType(1);
    View * vue = new View();
    setTaux(vue->saisieInt("taux"));
    Date * d = new Date();
    d->saisie();
    // d->affiche();
    

}

Ce::~Ce() {

}

void Ce::setDate(Date * date) {
    this->date = date;
}

Date * Ce::getDate() {
    return date;
}

void Ce::setTaux(int taux) {
    this->taux = taux;
}

int Ce::getTaux() {
    return taux;
}

// void Ce::test() {
//     cout << "hello from CE";
// }