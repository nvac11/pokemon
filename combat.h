#pragma once
#include "PokemonTypes.h"
#include "pokedex.h"
#include <cstring>
using namespace std;

typedef struct CombatEspece {
  const char *nature;
  const char *strongAgainst[5];
  const char *weakAgainst[5];
  CombatEspece *next;
} CombatEspece;

typedef struct CombatHash {
  int size;
  CombatEspece *content[26];
} CombatHash;

int hash_f(const char *str);

const char *pokemonTypeToString(PokemonType t);

CombatEspece *get(CombatHash *hashtable, const char *key);
bool contains(CombatHash *hashtable, CombatEspece *c);
void insert(CombatEspece *c, CombatHash *hashtable);
void combat(int id1, int id2, Pokedex * pokedex, EspecePokemon bestiaire[150]);
