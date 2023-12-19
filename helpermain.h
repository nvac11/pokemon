#pragma once

#include "historique.h"
#include "pokedex.h"
#include "pokemon.h"
#include "ressources.h"
void printMenu();

void powerupAndEvolution(Pokedex *p, EspecePokemon bestiaire[150],
                         Ressources &ressources, Historique *historique);
