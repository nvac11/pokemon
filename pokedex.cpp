
#include "pokedex.h"
#include "utils.h"
#include <cstring>
#include <iostream>

using namespace std;

Pokedex *initPokedex(const int size) {

  Pokedex *pokedex = new Pokedex;

  pokedex->capacity = size;
  pokedex->nbPokemons = 0;

  pokedex->mesPokemons = new Pokemon[size];

  return pokedex;
}

void insertPokemon(Pokedex **monPokedex, Pokemon p) {

  Pokedex *pokedex = *monPokedex;

  if (pokedex->capacity == pokedex->nbPokemons) {

    Pokedex *newpokedex = initPokedex((int)(pokedex->capacity * 1.5));
    for (int i = 0; i < pokedex->nbPokemons; i++) {
      newpokedex->mesPokemons[i] = pokedex->mesPokemons[i];
    }
    newpokedex->nbPokemons = pokedex->nbPokemons;

    *monPokedex = newpokedex;
    pokedex = newpokedex;
  }

  if (pokedex->nbPokemons == 0) {
    pokedex->mesPokemons[0] = p;
  } else {
    int i = 0;
    while (i < pokedex->nbPokemons &&
           strcmp(pokedex->mesPokemons[i].nom, p.nom) < 0) {
      i++;
    }

    if (i == pokedex->nbPokemons) {
      pokedex->mesPokemons[i] = p;
    } else {
      for (int k = pokedex->nbPokemons - 1; k >= i; k--) {
        pokedex->mesPokemons[k + 1] = pokedex->mesPokemons[k];
      }
      pokedex->mesPokemons[i] = p;
    }
  }

  pokedex->nbPokemons = pokedex->nbPokemons + 1;
}

void displayPokedex(Pokedex *pokedex, EspecePokemon bestiaire[150],
                    const char *typesLabel[18], const Ressources ressources) {
  cout << "Mes ressources : "
       << "\t " << ressources.candies << " bonbons \t" << ressources.stardust
       << " poussières" << endl
       << endl;
  cout << endl
       << "Contenu du pokedex (Actuellement " << pokedex->nbPokemons
       << " pokemons capturés)" << endl;
  for (int i = 0; i < pokedex->nbPokemons; i++) {
    cout << i << " : ";
    display(pokedex->mesPokemons[i], bestiaire, typesLabel);
  }
}

Pokemon *genererPokemon(EspecePokemon bestiaire[150],
                        const char *typesLabel[18]) {
  Pokemon *p = new Pokemon;

  EspecePokemon e = bestiaire[random_at_most(149)];
  while (e.estEvolue != 0) {
    e = bestiaire[random_at_most(149)];
  }
  p->nom = e.nom;
  p->xp = 0;
  p->cp = 200 + (int)random_at_most(800); // un nombre de cp entre 200 et 1000
  p->pv = 30 + (int)random_at_most(470);  // un nombre de PV dans 30 et 500
  return p;
}
