#include "Fao.hpp"

using namespace fao;
// using namespace std;

Fao::Fao() {

    cfile="fichiers/fichier_comptes.txt";
    tfile="fichiers/fichier_transactions.txt";

}

Fao::~Fao() {

}

int Fao::majAllComptes(vector<Compte*> listeCompte){
    ofstream fecriture(cfile.c_str());
    Compte * c;
    if(fecriture)
    {
            int b = listeCompte.size();
            for(int i=0; i < b; i++) {
                c= listeCompte[i];
                fecriture << c->getId() <<"_" << c->getNumero() <<"_" << c->getSolde() <<"_" << c->getType() << endl;

            }
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir en lecture le fichier des comptes" << endl;
        return 0;
    }
    
    return 1;
}

int Fao::majAllTransactions(vector<Transaction*> transactions){
    ofstream fecriture(tfile.c_str());
    Transaction * t = new Transaction();
    if(fecriture)
    {
            int b = transactions.size();
            for(int i=0; i < b; i++) {
                t = transactions[i];
                fecriture << t->getId() <<"_" << t->getTypeInt() <<"_" << t->getMnt() <<"_" << t->getDate()->getJour() <<"/" << t->getDate()->getMois() << "/" << t->getDate()->getAnne() << endl;

            }
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir en lecture le fichier des transactions" << endl;
        return 0;
    }
    
    return 1;
}

vector<Compte*> Fao::loadComptes(){
    ifstream flecture(cfile.c_str());
    Compte * a;
    vector<Compte*> b;
    if(flecture)
    {
        
         string ligne; //Une variable pour stocker les lignes lues

         while(getline(flecture, ligne)){
            Squall * utils = new Squall();
            vector<string> data = utils->explode(ligne, '_');
                // attribution des propriétés
                a->setId( utils->convertStringToInt(data[0]));
                a->setNumero(data[1]);
                a->setSolde(utils->convertStringToInt(data[2]));
                a->setType(utils->convertStringToInt(data[3]));
                b.push_back(a);
            }
    }
    else
    {
        Squall * utils = new Squall();
        cout << "ERREUR: Impossible d'ouvrir en lecture le fichier des comptes" << endl;
        cout << "Un nouveau fichier sera créé" << endl;
        ofstream fecriture(cfile.c_str());
        utils->pause();
    }
    return b;
}

vector<Transaction*> Fao::loadTransactions(){
    ifstream flecture(tfile.c_str());
    Transaction * a;
    vector<Transaction*> b;
    if(flecture)
    {
        
         string ligne; //Une variable pour stocker les lignes lues

         while(getline(flecture, ligne)){
            Squall * utils = new Squall();
            vector<string> data = utils->explode(ligne, '_');
                // attribution des propriétés
                a->setId( utils->convertStringToInt(data[0]));
                a->setType(utils->convertStringToInt(data[1]));
                a->setMnt(utils->convertStringToInt(data[3]));
                
                Date * d = new Date();
                vector<string> date = utils->explode(data[4], '/');
                d->setJour(utils->convertStringToInt(date[0]));
                d->setMois(utils->convertStringToInt(date[1]));
                d->setAnne(utils->convertStringToInt(date[2]));
                a->setDate(d);
                b.push_back(a);
        }
    }
    else
    {
        Squall * utils = new Squall();
        cout << "ERREUR: Impossible d'ouvrir en lecture le fichier des transactions" << endl;
        cout << "Un nouveau fichier sera créé" << endl;
        ofstream fecriture(tfile.c_str());
        utils->pause();
    }
    return b;
}





























// ###############################################################

int Fao::saveTest(int a){
    ofstream fecriture(cfile.c_str(), ios::app);
    if(fecriture)
    {
             fecriture << a << endl;

    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir en lecture le fichier des id." << endl;
    }
    cout << "squall";

    return 0;
}

int Fao::loadTest(){
    ifstream flecture(cfile.c_str());
    int a;
    if(flecture)
    {
        
         string ligne; //Une variable pour stocker les lignes lues

         while(getline(flecture, ligne)){
            Squall * utils = new Squall();
            vector<string> data = utils->explode(ligne, '_');
            int b = data.size();
            for(int i=0; i < b; i++) {
                a = utils->convertStringToInt(data[i]);
                cout << a;
                utils->pause();
            }

            cout << endl;
        }
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir en lecture le fichier des comptes" << endl;
    }
    return a;
}