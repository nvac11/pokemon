#include "combat.h"
#include "PokemonTypes.h"
#include "pokemon.h"
#include "utils.h"
#include "bestiaire.h"
#include <cstring>
#include <strings.h>
#include <iostream>

int hash_f(const char *str)
{
  unsigned long hash = 5381;
  int c;

  while (c = *str++){
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
  }
  return hash % 26;
}

bool contains(CombatHash* hashtable, CombatEspece* c) {
  CombatEspece* element = get(hashtable, c->nature);
  return (element != nullptr);
}

const char* pokemonTypeToString(PokemonType t) {
  if (t == Normal) {
    return "Normal";
  } else if (t == Fighting) {
    return "Fighting";
  } else if (t == Flying) {
    return "Flying";
  } else if (t == Poison) {
    return "Poison";
  } else if (t == Ground) {
    return "Ground";
  } else if (t == Rock) {
    return "Rock";
  } else if (t == Bug) {
    return "Bug";
  } else if (t == Ghost) {
    return "Ghost";
  } else if (t == Steel) {
    return "Steel";
  } else if (t == Fire) {
    return "Fire";
  } else if (t == Grass) {
    return "Grass";
  } else if (t == Water) {
    return "Water";
  } else if (t == Electric) {
    return "Electric";
  } else if (t == Psychic) {
    return "Psychic";
  } else if (t == Ice) {
    return "Ice";
  } else if (t == Dragon) {
    return "Dragon";
  } else if (t == Dark) {
    return "Dark";
  } else {
    return "Fairy";
  }
}
CombatEspece * get(CombatHash* hashtable, const char * key){
  int index = hash_f(key);
  CombatEspece * actualesp = hashtable->content[index];
  while (actualesp != nullptr && strcmp(actualesp->nature, key) != 0){
    actualesp = actualesp->next;  
  }
  return actualesp;
}

void insert(CombatEspece *c, CombatHash *hashtable) {
   int index = hash_f(c->nature);
   CombatEspece * esp = hashtable->content[index];
   c->next = esp;
   hashtable->content[index] = c;
}


CombatHash* initCombatHash()
{
	CombatHash* hashtable = new CombatHash;
	hashtable->size = 18;
	// Initialisation
	for (int k = 0; k < 26; k++)
	{
		hashtable->content[k] = nullptr; 
	}

	// Insertions successives
	int i = -1;
	CombatEspece* bug = new CombatEspece;
	bug->nature = "Bug";
	bug->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		bug->strongAgainst[i] = nullptr;
		bug->weakAgainst[i] = nullptr;
	}
	bug->strongAgainst[0] = "Dark";
	bug->strongAgainst[1] = "Grass";
	bug->strongAgainst[2] = "Psychic";
	bug->weakAgainst[0] = "Fire";
	bug->weakAgainst[1] = "Flying";
	bug->weakAgainst[2] = "Rock";
	insert(bug, hashtable);

	CombatEspece* dark = new CombatEspece;
	dark->nature = "Dark";
	dark->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		dark->strongAgainst[i] = nullptr;
		dark->weakAgainst[i] = nullptr;
	}
	dark->strongAgainst[0] = "Ghost";
	dark->strongAgainst[1] = "Psychic";
	dark->weakAgainst[0] = "Bug";
	dark->weakAgainst[1] = "Fairy";
	dark->weakAgainst[2] = "Fight";
	insert(dark, hashtable);

	CombatEspece* dragon = new CombatEspece;
	dragon->nature = "Dragon";
	dragon->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		dragon->strongAgainst[i] = nullptr;
		dragon->weakAgainst[i] = nullptr;
	}
	dragon->strongAgainst[0] = "Dragon";
	dragon->weakAgainst[0] = "Dragon";
	dragon->weakAgainst[1] = "Fairy";
	dragon->weakAgainst[2] = "Ice";
	insert(dragon, hashtable);

	CombatEspece* electric = new CombatEspece;
	electric->nature = "Electric";
	electric->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		electric->strongAgainst[i] = nullptr;
		electric->weakAgainst[i] = nullptr;
	}
	electric->strongAgainst[0] = "Flying";
	electric->strongAgainst[1] = "Water";
	electric->weakAgainst[0] = "Ground";
  
  CombatEspece* fairy = new CombatEspece;
  fairy->nature = "Fairy";
  fairy->next = nullptr; 
  fairy->strongAgainst[0] = "Dark";
  fairy->strongAgainst[1] = "Dragon";
  fairy->strongAgainst[2] = "Fight";
  fairy->weakAgainst[0] = "Poison";
  fairy->weakAgainst[1] = "Steel";
  insert(fairy, hashtable);

  CombatEspece *fighting = new CombatEspece;
  fighting->nature = "Fighting";
  fighting->next = nullptr;
  for (i = 0; i < 5; i++) {
    fighting->strongAgainst[i] = nullptr;
    fighting->weakAgainst[i] = nullptr;
  }
  fighting->strongAgainst[0] = "Dark";
  fighting->strongAgainst[1] = "Ice";
  fighting->strongAgainst[2] = "Normal";
  fighting->strongAgainst[3] = "Rock";
  fighting->strongAgainst[4] = "Steel";
  fighting->weakAgainst[0] = "Fairly";
  fighting->weakAgainst[1] = "Flying";
  fighting->weakAgainst[2] = "Psychic";
  insert(fighting, hashtable);

  CombatEspece *fire = new CombatEspece;
  fire->nature = "Fire";
  fire->next = nullptr;
  for (i = 0; i < 5; i++) {
    fire->strongAgainst[i] = nullptr;
    fire->weakAgainst[i] = nullptr;
  }
  fire->strongAgainst[0] = "Bug";
  fire->strongAgainst[1] = "Grass";
  fire->strongAgainst[2] = "Ice";
  fire->strongAgainst[3] = "Steel";
  fire->weakAgainst[0] = "Ground";
  fire->weakAgainst[1] = "Rock";
  fire->weakAgainst[2] = "Water";
  insert(fire, hashtable);

  CombatEspece *flying = new CombatEspece;
  flying->nature = "Flying";
  flying->next = nullptr;
  for (i = 0; i < 5; i++) {
    flying->strongAgainst[i] = nullptr;
    flying->weakAgainst[i] = nullptr;
  }
  flying->strongAgainst[0] = "Bug";
  flying->strongAgainst[1] = "Fight";
  flying->strongAgainst[2] = "Grass";
  flying->weakAgainst[0] = "Electric";
  flying->weakAgainst[1] = "Ice";
  flying->weakAgainst[2] = "Rock";
  insert(flying, hashtable);

  CombatEspece *ghost = new CombatEspece;
  ghost->nature = "Ghost";
  ghost->next = nullptr;
  for (i = 0; i < 5; i++) {
    ghost->strongAgainst[i] = nullptr;
    ghost->weakAgainst[i] = nullptr;
  }
  ghost->strongAgainst[0] = "Ghost";
  ghost->strongAgainst[1] = "Psychic";
  ghost->weakAgainst[0] = "Dark";
  ghost->weakAgainst[1] = "Ghost";
  insert(ghost, hashtable);

  CombatEspece *grass = new CombatEspece;
  grass->nature = "Grass";
  grass->next = nullptr;
  for (i = 0; i < 5; i++) {
    grass->strongAgainst[i] = nullptr;
    grass->weakAgainst[i] = nullptr;
  }
  grass->strongAgainst[0] = "Ground";
  grass->strongAgainst[1] = "Rock";
  grass->strongAgainst[2] = "Water";
  grass->weakAgainst[0] = "Bug";
  grass->weakAgainst[1] = "Fire";
  grass->weakAgainst[2] = "Flying";
  grass->weakAgainst[3] = "Ice";
  grass->weakAgainst[4] = "Poison";
  insert(grass, hashtable);

  CombatEspece *ground = new CombatEspece;
  ground->nature = "Ground";
  ground->next = nullptr;
  for (i = 0; i < 5; i++) {
    ground->strongAgainst[i] = nullptr;
    ground->weakAgainst[i] = nullptr;
  }
  ground->strongAgainst[0] = "Electric";
  ground->strongAgainst[1] = "Fire";
  ground->strongAgainst[2] = "Poison";
  ground->strongAgainst[3] = "Rock";
  ground->strongAgainst[4] = "Steel";
  ground->weakAgainst[0] = "Grass";
  ground->weakAgainst[1] = "Ice";
  ground->weakAgainst[2] = "Water";
  insert(ground, hashtable);

  CombatEspece *ice = new CombatEspece;
  ice->nature = "Ice";
  ice->next = nullptr;
  for (i = 0; i < 5; i++) {
    ice->strongAgainst[i] = nullptr;
    ice->weakAgainst[i] = nullptr;
  }
  ice->strongAgainst[0] = "Dragon";
  ice->strongAgainst[1] = "Flying";
  ice->strongAgainst[2] = "Grass";
  ice->strongAgainst[3] = "Ground";
  ice->weakAgainst[0] = "Fight";
  ice->weakAgainst[1] = "Fire";
  ice->weakAgainst[2] = "Rock";
  ice->weakAgainst[3] = "Steel";
  insert(ice, hashtable);

  CombatEspece *normal = new CombatEspece;
  normal->nature = "Normal";
  normal->next = nullptr;
  for (i = 0; i < 5; i++) {
    normal->strongAgainst[i] = nullptr;
    normal->weakAgainst[i] = nullptr;
  }
  normal->weakAgainst[0] = "Fight";
  insert(normal, hashtable); // correction ici.
	ice->strongAgainst[3] = "Ground";
	ice->weakAgainst[0] = "Fight";
	ice->weakAgainst[1] = "Fire";
	ice->weakAgainst[2] = "Rock";
	ice->weakAgainst[3] = "Steel";
	insert(ice, hashtable);

	normal->nature = "Normal";
	normal->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		normal->strongAgainst[i] = nullptr;
		normal->weakAgainst[i] = nullptr;
	}
	normal->weakAgainst[0] = "Fight";
	insert(normal, hashtable); // correction ici.

	CombatEspece* poison = new CombatEspece;
	poison->nature = "Poison";
	poison->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		poison->strongAgainst[i] = nullptr;
		poison->weakAgainst[i] = nullptr;
	}
	poison->strongAgainst[0] = "Fairy";
	poison->strongAgainst[1] = "Grass";
	poison->weakAgainst[0] = "Ground";
	poison->weakAgainst[1] = "Psychic";
	insert(poison, hashtable);

	CombatEspece* psychic = new CombatEspece;
	psychic->nature = "Psychic";
	psychic->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		psychic->strongAgainst[i] = nullptr;
		psychic->weakAgainst[i] = nullptr;
	}
	psychic->strongAgainst[0] = "Fight";
	psychic->strongAgainst[1] = "Poison";
	psychic->weakAgainst[0] = "Bug";
	psychic->weakAgainst[1] = "Dark";
	psychic->weakAgainst[2] = "Ghost";
	insert(psychic, hashtable);

	CombatEspece* rock = new CombatEspece;
	rock->nature = "Rock";
	rock->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		rock->strongAgainst[i] = nullptr;
		rock->weakAgainst[i] = nullptr;
	}
	rock->strongAgainst[0] = "Bug";
	rock->strongAgainst[1] = "Fire";
	rock->strongAgainst[2] = "Flying";
	rock->strongAgainst[3] = "Ice";
	rock->weakAgainst[0] = "Fight";
	rock->weakAgainst[1] = "Grass";
	rock->weakAgainst[2] = "Ground";
	rock->weakAgainst[3] = "Steel";
	rock->weakAgainst[4] = "Water";
	insert(rock, hashtable);

	CombatEspece* steel = new CombatEspece;
	steel->nature = "Steel";
	steel->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		steel->strongAgainst[i] = nullptr;
		steel->weakAgainst[i] = nullptr;
	}
	steel->strongAgainst[0] = "Fairy";
	steel->strongAgainst[1] = "Ice";
	steel->strongAgainst[2] = "Rock";
	steel->weakAgainst[0] = "Fight";
	steel->weakAgainst[1] = "Fire";
	steel->weakAgainst[2] = "Ground";
	insert(steel, hashtable);

	CombatEspece* water = new CombatEspece;
	water->nature = "Water";
	water->next = nullptr;
	for (i = 0; i < 5; i++)
	{
		water->strongAgainst[i] = nullptr;
		water->weakAgainst[i] = nullptr;
	}
	water->strongAgainst[0] = "Fire";
	water->strongAgainst[1] = "Ground";
	water->strongAgainst[2] = "Rock";
	water->weakAgainst[0] = "Electric";
	water->weakAgainst[1] = "Grass";
	insert(water, hashtable);

	return hashtable;
}

void combat(int id1, int id2, Pokedex * pokedex, EspecePokemon bestiaire[150]){
  CombatHash * hashtable = initCombatHash();
  int number = random_at_most(1);
  int first  = (1 - number) * id1 + number * id2;
  int second = (1 - number) * id2 + number * id1;
  int damage1 = 30;
  int damage2 = 30;

  Pokemon p1 = pokedex->mesPokemons[first];
  Pokemon p2 = pokedex->mesPokemons[second];
  PokemonType p1data = lookupEspecePokemon(bestiaire, p1.nom).type;
  PokemonType p2data = lookupEspecePokemon(bestiaire, p2.nom).type;
  //cout << pokemonTypeToString(p1data) << endl;
  
  CombatEspece * esp1 = get(hashtable, pokemonTypeToString(p1data));
  CombatEspece * esp2 = get(hashtable, pokemonTypeToString(p1data));
  //cout << esp1->strongAgainst[0] << endl;

  for (int i = 0; i < 5; i++) {
    if (esp1->strongAgainst[i] != nullptr && esp2->strongAgainst[i] != nullptr) 
    {
      if(strcmp(esp1->strongAgainst[i], esp2->nature) == 0){
        damage1 = 90; 
      } else if (strcmp(esp2->strongAgainst[i], esp1->nature) == 0){
        damage2 = 90;
      }
    }
  } 
  
  
   
  while (p1.pv > 0 || p2.pv > 0) {
    p2.pv -= damage1;
    p1.pv -= damage2;
  } 
  if (p2.pv <= 0){
    cout << "vainqueur est " << p1.nom << "!" << endl;
  } else {
    cout << "vainqueur est " << p2.nom << "!" << endl;
  }

}
