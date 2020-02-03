#include "Cc.hpp"
#include "../compte/Compte.hpp"
#include "../../view/View.hpp"

using namespace model;
using namespace view;


Cc::Cc() {
    setType(2);
    View * vue = new View();
    setInteret(vue->saisieInt("interet"));

}

Cc::~Cc() {

}

void Cc::setInteret(int interet) {
    this->interet = interet;
}

int Cc::getInteret() {
    return interet;
}


// void Cc::test() {
//     cout << "hello from CC";
// }