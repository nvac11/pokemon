#pragma once

#include "pokemon.h"
#include "ressources.h"

typedef struct {
  Pokemon *mesPokemons;
  int capacity;
  int nbPokemons;

} Pokedex;

Pokedex *initPokedex(const int size);

void insertPokemon(Pokedex **moPokedex, Pokemon p);

void displayPokedex(Pokedex *pokedex, EspecePokemon bestiaire[150],
                    const char *typesLabel[18], const Ressources ressources);

Pokemon *genererPokemon(EspecePokemon bestiaire[150],
                        const char *typesLabel[18]);
