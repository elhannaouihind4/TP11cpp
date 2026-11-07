#include <iostream>
#include <vector>
using namespace std;

// Classe abstraite Animal
class Animal {
public:

    // Méthode virtuelle pure
    virtual void crier() const = 0;

    // Méthode non abstraite
    void info() const {
        cout << "Je suis un animal." << endl;
    }

    virtual ~Animal() {}
};

// Classe Chien
class Chien : public Animal {
public:
    void crier() const override {
        cout << "Wouf !" << endl;
    }
};

// Classe Chat
class Chat : public Animal {
public:
    void crier() const override {
        cout << "Miaou !" << endl;
    }
};

// Classe Vache
class Vache : public Animal {
public:
    void crier() const override {
        cout << "Meuh !" << endl;
    }
};

int main() {

    vector<Animal*> animaux;

    animaux.push_back(new Chien());
    animaux.push_back(new Chat());
    animaux.push_back(new Vache());

    cout << " GESTION DES ANIMAUX " << endl;

    for (int i = 0; i < animaux.size(); i++) {

        animaux[i]->info();

        animaux[i]->crier();

        cout << "\n" << endl;
    }

    for (int i = 0; i < animaux.size(); i++) {
        delete animaux[i];
    }

    return 0;
}



