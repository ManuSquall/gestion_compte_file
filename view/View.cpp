#include "View.hpp"

using namespace view;

View::View() {

}

View::~View() {

}

int View::choixCompte(){
    int chint;
    do
    {
        cout << "Quel type de compte souhaitez vous creer?" << endl;
        cout << "\t1 - Epargne \n \t2- Cheque" << endl;
        cin >> chint;
    } while(chint !=1 && chint !=2);
    
    return chint;
}

int View::saisieInt(string lib){
    int chint;
    do
    {
        cout << "Veuillez saisir la valeur pour "<<lib << endl;
        cin >> chint;
    } while(chint < 0);
    
    return chint;
}

int View::saisieJour(){
    int chint;
    do
    {
        cout << "Veuillez saisir le jour" << endl;
        cin >> chint;
    } while(chint < 0 || chint > 31);
    
    return chint;
}

int View::saisieMois(){
    int chint;
    do
    {
        cout << "Veuillez saisir le mois "<< endl;
        cin >> chint;
    } while(chint < 0 || chint >12);
    
    return chint;
}

int View::menuPrincipal(){
    int chint;
    do
    {
        system("clear");
        cout << "\t\t\t\t\t MENU" << endl;
        cout << "\n\t\t\t\t\t 1-            CREER COMPTE" << endl;
        cout << "\n\t\t\t\t\t 2-            FAIRE UNE TRANSACTION" << endl;
        cout << "\n\t\t\t\t\t 3-            LISTER COMPTE" << endl;
        cout << "\n\t\t\t\t\t 4-            QUITTER" << endl;
        cout << "\n\n" << endl;
        cin >> chint;
    } while(chint <0 || chint>4);
    
    return chint;
}

int View::getTypeTransac(){
    int chint;
    do
    {
        cout << "Quelle type de transaction voulez vous effectuez? " << endl;
        cout << "\t 1 - DEPOT | 2 - RETRAIT | 3 - VIREMENT\n" << endl;
        cin >> chint;
    } while(chint <0 || chint>3);
    
    return chint;
}

void listTransactions(vector <Transaction *> transaCompte){
    int b = transaCompte.size();
    for(int i=0; i < b; i++) {
        cout << "Transaction n "<< i << endl;
        transaCompte[i]->getDate()->affiche();
        cout << endl;
        cout << "id : "<< transaCompte[i]->getId() << endl;
        cout << "Montant : "<< transaCompte[i]->getId() << endl;
        cout << "Type : "<< transaCompte[i]->getTypeString() << endl;
        cout << "\n\n";
        // cout << "squall";
    }
    cin.clear();
    cin.ignore();
    cin.get();
}
