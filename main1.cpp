#include <iostream>
using namespace std;

// Classe abstraite
class Paiement {
public:
    virtual void effectuerPaiement(double montant) = 0;

    virtual ~Paiement() {}
};

// Classe PaiementCarte
class PaiementCarte : public Paiement {
public:
    void effectuerPaiement(double montant) override {
        cout << "Paiement de " << montant
             << " DH par carte bancaire." << endl;
    }
};

// Classe PaiementEspece
class PaiementEspece : public Paiement {
public:
    void effectuerPaiement(double montant) override {
        cout << "Paiement de " << montant
             << " DH en especes." << endl;
    }
};


int main() {


    Paiement* paiements[4];


    paiements[0] = new PaiementCarte();
    paiements[1] = new PaiementEspece();
    paiements[2] = new PaiementCarte();
    paiements[3] = new PaiementEspece();

    double montants[4] = {600, 400, 100, 340};

    cout << " SIMULATION DES PAIEMENTS " << endl;


    for (int i = 0; i < 4; i++) {
        paiements[i]->effectuerPaiement(montants[i]);
    }


    for (int i = 0; i < 4; i++) {
        delete paiements[i];
    }

    return 0;
}



