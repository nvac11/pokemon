
#include "historique.h"
#include <iostream>

using namespace std;

void insererTete(Historique *historique, const char *from, const char *to) {

  Evolution *e = new Evolution;
  e->from = from;
  e->to = to;
  e->nextEvolution = nullptr;

  if (historique->debut == nullptr) {

    historique->nombre = 1;
    historique->debut = e;
  } else {
    e->nextEvolution = historique->debut;
    historique->debut = e;
    historique->nombre = historique->nombre + 1;
  }
}

void afficherHistorique(Historique *historique) {
  if (historique->debut == nullptr) {
    cout << "Vous n'avez encore réalisé aucune évolution !" << endl;
  } else {
    cout << "Voici la liste des évolutions réalisées par ordre "
            "ante-chronologique :"
         << endl;
    Evolution *current = historique->debut;
    while (current != nullptr) {
      cout << current->from << " est devenu un " << current->to << endl;
      current = current->nextEvolution;
    }
  }
}
