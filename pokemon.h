#pragma once

#include "PokemonTypes.h"
#include "historique.h"

typedef struct Pokemon {

  const char *nom;
  int xp;
  int evolution;
  int pv;
  int cp;

} Pokemon;

void evolve(Pokemon *p, const char *nextEvolution, Historique *historique);
void powerup(Pokemon *p);
void display(const Pokemon p, EspecePokemon bestiaire[150],
             const char *typesLabel[18]);
