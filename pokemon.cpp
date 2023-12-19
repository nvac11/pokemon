#include "pokemon.h"
#include "bestiaire.h"
#include <iostream>
using namespace std;

void evolve(Pokemon *p, const char *nextEvolution, Historique *historique) {

  const char *oldName = p->nom;
  p->nom = nextEvolution;
  p->evolution = p->evolution + 1;
  insererTete(historique, oldName, nextEvolution);
  cout << endl
       << "Félicitations, votre " << oldName << " est devenu un "
       << nextEvolution << " ! " << endl
       << endl;
}

void powerup(Pokemon *p) {
  p->cp = (int)p->cp * 1.25;
  cout << "Félicitations, votre " << p->nom
       << " a progressé et gagné 25% de ses points de combats, une véritable "
          "armoire à glace ! ";
}

void display(const Pokemon p, EspecePokemon bestiaire[150],
             const char *typesLabel[18]) {
  EspecePokemon esp = lookupEspecePokemon(bestiaire, p.nom);
  cout << p.nom << "  | " << typesLabel[esp.type] << " | "
       << "  (Evolution : " << p.evolution << ")" << endl;
  cout << "PV : " << p.pv << "   |   XP : " << p.xp << "   |   CP " << p.cp
       << endl;
}
