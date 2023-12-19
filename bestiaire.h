#pragma once

#include "PokemonTypes.h"
#include "pokemon.h"

void initBestiaire(EspecePokemon bestiaire[]);
void afficheBestiaire(EspecePokemon bestiaire[]);
void afficheBestiaireTrie(EspecePokemon bestiaire[]);
EspecePokemon lookupEspecePokemon(EspecePokemon bestiaire[], const char *nom);
