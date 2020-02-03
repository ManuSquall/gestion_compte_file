#pragma once

namespace model {
    class Date {

    public:
        Date();
        ~Date();
        void setAnne(int  an);
        
        int getAnne();
        
        void setMois(int mois);
        
        int getMois();
        
        void setJour(int jour);
        
        int getJour();

        void saisie();
        void affiche();

    private:
        int jour, mois, anne;

        
        
    };
};