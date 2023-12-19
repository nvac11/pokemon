#pragma once

typedef enum {
  Normal,
  Fighting,
  Flying,
  Poison,
  Ground,
  Rock,
  Bug,
  Ghost,
  Steel,
  Fire,
  Grass,
  Water,
  Electric,
  Psychic,
  Ice,
  Dragon,
  Dark,
  Fairy
} PokemonType;

typedef struct EspecePokemon {
  const char *nom;
  PokemonType type;
  int nbBonbonsPourEvoluer;
  const char *evolvesTo;
  bool estEvolue;
} EspecePokemon;
