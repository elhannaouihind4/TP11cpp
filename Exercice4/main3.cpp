#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Classe abstraite NoeudFichier
class NoeudFichier {
public:
    virtual string nom() const = 0;

    virtual int taille() const = 0;

    virtual ~NoeudFichier() {}
};

// Classe Fichier
class Fichier : public NoeudFichier {
private:
    string nomFichier;
    int tailleFichier;

public:
    Fichier(string nom, int taille) {
        nomFichier = nom;
        tailleFichier = taille;
    }

    string nom() const override {
        return nomFichier;
    }

    int taille() const override {
        return tailleFichier;
    }
};

// Classe Dossier
class Dossier : public NoeudFichier {
private:
    string nomDossier;
    vector<NoeudFichier*> enfants;

public:
    Dossier(string nom) {
        nomDossier = nom;
    }

    // Ajouter un fichier ou un sous-dossier
    void ajouter(NoeudFichier* noeud) {
        enfants.push_back(noeud);
    }

    string nom() const override {
        return nomDossier;
    }

    // Calculer la taille totale du dossier
    int taille() const override {
        int total = 0;

        for (int i = 0; i < enfants.size(); i++) {
            total += enfants[i]->taille();
        }

        return total;
    }

    // Afficher le contenu du dossier
    void afficher() const {
        cout << "\nDossier : " << nomDossier << endl;

        for (int i = 0; i < enfants.size(); i++) {
            cout << enfants[i]->nom()
                 << " - Taille : "
                 << enfants[i]->taille() << " Ko"
                 << endl;
        }
    }

    // Libérer les enfants
    ~Dossier() {
        for (int i = 0; i < enfants.size(); i++) {
            delete enfants[i];
        }
    }
};

int main() {

    Dossier* principal = new Dossier("Documents");

    Fichier* f1 = new Fichier("Cours.pdf", 200);
    Fichier* f2 = new Fichier("Exercice.docx", 100);

    Dossier* images = new Dossier("Images");
    Dossier* projets = new Dossier("Projets");

    images->ajouter(new Fichier("photo.jpg", 500));
    images->ajouter(new Fichier("logo.png", 300));

    projets->ajouter(new Fichier("main.cpp", 50));
    projets->ajouter(new Fichier("code.cpp", 70));

    principal->ajouter(f1);
    principal->ajouter(f2);
    principal->ajouter(images);
    principal->ajouter(projets);

    cout << " SYSTEME DE FICHIERS " << endl;

    principal->afficher();

    images->afficher();

    projets->afficher();

    cout << "\nTaille totale de Documents : "
         << principal->taille() << " Ko" << endl;

    cout << "Taille totale de Images : "
         << images->taille() << " Ko" << endl;

    delete principal;

    return 0;
}



