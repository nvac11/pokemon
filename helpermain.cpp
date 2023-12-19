#include "bestiaire.h"
#include "historique.h"
#include "pokedex.h"
#include "pokemon.h"
#include "ressources.h"
#include "utils.h"
#include <cstring>
#include <iostream>

using namespace std;

void printMenu() {
  cout << endl << endl;
  ;
  cout << " 1 - Index des Pokemons" << endl;
  cout << " 2 - Mon Pokedex" << endl;
  cout << " 3 - Attraper un Pokemon" << endl;
  cout << " 4 - Power-up et évolution" << endl;
  cout << " 5 - Combat" << endl;
  cout << " 6 - Journal des évolutions" << endl;
  cout << " 7 - Quitter" << endl;
}

void powerupAndEvolution(Pokedex *pokedex, EspecePokemon bestiaire[150],
                         Ressources &ressources, Historique *historique) {
  int newchoice = 0;
  int idPokemon = -1;
  do {
    cout << "Choisir l'identifiant du pokemon à faire évoluer ou progresser."
         << endl;
    cin >> idPokemon;
  } while (idPokemon < 0);

  // récupérons le pointeur vers le pokemon que l'on souhaite modifier.
  Pokemon *p = &(pokedex->mesPokemons[idPokemon]);

  cout << "Choisir l'action à réaliser : " << endl;
  cout << " 1 - Powerup" << endl;
  cout << " 2 - Evolution" << endl;
  cout << " 3 - Retour au menu principal" << endl;

  do {
    cin >> newchoice;
    if (newchoice != 1 && newchoice != 2 && newchoice != 3) {
      cout << "mauvais choix, saisir 1, 2 ou 3";
    }
  } while (newchoice != 1 && newchoice != 2 && newchoice != 3);

  if (newchoice == 1) {
    if (ressources.candies >= 10 && ressources.stardust >= 500) {
      ressources.candies = ressources.candies - 10;
      ressources.stardust = ressources.stardust - 500;
      powerup(p);
    } else {
      cout << "Power-up impossible : 10 bonbons et 500 poussières sont "
              "nécessaires. Peut être devriez-vous attraper plus de pokemons !";
    }
  } else if (newchoice == 2) {

    // retrouver l'espece de pokemon du pokemon p. Il est pertinent de penser à
    // externaliser cette recherche dans une fonction "rechercheEspece" avec le
    // bestiaire et le pokemon à chercher dans le fichier bestiaire par exemple.
    int i = 0;
    while (i < 150 && strcmp(p->nom, bestiaire[i].nom) != 0) {
      i++;
    }

    // identifier le nom de l'espece vers laquelle le pokemon evolue
    const char *nextEvolution = bestiaire[i].evolvesTo;

    // connaitre le nombre de bonbons nécessaires pour cette évolution
    int nbBonbonsNecessaires = bestiaire[i].nbBonbonsPourEvoluer;

    if (nextEvolution == nullptr) {
      cout << "Evolution impossible: le pokemon est déjà dans sa dernière "
              "évolution !";
    } else {
      if (ressources.candies < nbBonbonsNecessaires) {
        cout << "Evolution impossible : " << nbBonbonsNecessaires
             << " bonbons sont nécessaires. Peut être devriez-vous attraper "
                "plus de pokemons !";
      } else {
        ressources.candies = ressources.candies - nbBonbonsNecessaires;
        evolve(p, nextEvolution, historique);
      }
    }
  }
}
