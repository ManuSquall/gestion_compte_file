#include "Compte.hpp"
#include "../../view/View.hpp"

using namespace model;
using namespace view;
unsigned int Compte::cpt =0;

Compte::Compte() {
    View * vue = new View();
    Compte::cpt++;
    this->id = Compte::cpt;
    genererNumero();
    solde=vue->saisieInt("solde");
}

Compte::~Compte() {

}

void Compte::setSolde(int solde) {
        this->solde = solde;
    }
    
void Compte::setNumero(string numero) {
    this->numero = numero;
}

void Compte::setId(int id) {
    this->id = id;
}

int Compte::getSolde() {
    return solde;
}

string Compte::getNumero() {
    return numero;
}

int Compte::getId() {
    return id;
}

void Compte::setType(int type) {
    this->type = type;
}

int Compte::getType() {
    return type;
}

void Compte::genererNumero(){
    Squall * utils = new Squall();
    numero += "C_";
    numero += utils->getTime();
    numero += "_";
    numero += Compte::cpt;
}

void Compte::saisie(){

}