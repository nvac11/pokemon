
#include "bestiaire.h"
#include "combat.h"
#include "helpermain.h"
#include "historique.h"
#include "pokedex.h"
#include "pokemon.h"
#include "ressources.h"
#include "utils.h"
#include <iostream>

using namespace std;
int main(int argc, const char *argv[]) {

  Historique *historique = new Historique;

  EspecePokemon bestiaire[150];
  initBestiaire(bestiaire);

  Ressources ressources;
  ressources.stardust = 1000;
  ressources.candies = 100;

  Pokedex *pokedex = initPokedex(3);
  const char *typesLabel[18] = {
      "Normal",   "Fighting", "Flying", "Poison", "Ground", "Rock",
      "Bug",      "Ghost",    "Steel",  "Fire",   "Grass",  "Water",
      "Electric", "Psychic",  "Ice",    "Dragon", "Dark",   "Fairy"};
  /*
  Pokemon a;
  a.nom = "Seadra";
  a.xp = 1;
  a.cp = 4;
  a.evolution = 1;
  a.pv = 23;

  Pokemon b;
  b.nom = "Arbok";
  b.xp = 0;
  b.cp = 123;
  b.evolution = 2;
  b.pv = 134;

  Pokemon c;
  c.nom = "Zubat";
  c.xp = 40;
  c.cp = 300;
  c.evolution = 1;
  c.pv = 223;

  Pokemon d;
  d.nom = "Paras";
  d.xp = 0;
  d.cp = 23;
  d.evolution = 1;
  d.pv = 90;

  Pokemon e;
  e.nom = "Arkanine";
  e.xp = 0;
  e.cp = 23;
  e.evolution = 2;
  e.pv = 290;

  insertPokemon(&pokedex, a);
  cout << "******* Pokedex after inserting pokemon a *********" << endl;
  displayPokedex(pokedex, bestiaire, typesLabel, ressources);
  cout << "***************************************************" << endl << endl
  << endl;

  insertPokemon(&pokedex, b);
  cout << "******* Pokedex after inserting pokemon b *********" << endl;
  displayPokedex(pokedex, bestiaire, typesLabel, ressources);
  cout << "***************************************************" << endl << endl
  << endl;

  insertPokemon(&pokedex, c);
  cout << "******* Pokedex after inserting pokemon c *********" << endl;
  displayPokedex(pokedex, bestiaire, typesLabel, ressources);
  cout << "***************************************************" << endl << endl
  << endl;

  insertPokemon(&pokedex, d);
  cout << "******* Pokedex after inserting pokemon d *********" << endl;
  displayPokedex(pokedex, bestiaire, typesLabel, ressources);
  cout << "***************************************************" << endl << endl
  << endl;

  insertPokemon(&pokedex, e);
  cout << "******* Pokedex after inserting pokemon e *********" << endl;
  displayPokedex(pokedex, bestiaire, typesLabel, ressources);
  cout << "***************************************************" << endl << endl
  << endl;
  */
  int choice = 7;
  const char *exit_msg = "au revoir !";
  cout << "                                   .::.                            "
       << endl;
  cout << "                                 .;:**'                            "
       << endl;
  cout << "                                 `                                 "
       << endl;
  cout << "     .:XHHHHk.              db.   .;;.     dH  MX                  "
       << endl;
  cout << "   oMMMMMMMMMMM       ~MM  dMMP :MMMMMR   MMM  MR      ~MRMN       "
       << endl;
  cout << "   QMMMMMb  \"MMX       MMMMMMP !MX' :M~   MMM MMM  .oo. XMMM 'MMM  "
       << endl;
  cout << "     `MMMM.  )M> :X!Hk. MMMM   XMM.o\"  .  MMMMMMM X?XMMM MMM>!MMP  "
       << endl;
  cout << "      'MMMb.dM! XM M'?M MMMMMX.`MMMMMMMM~ MM MMM XM `\" MX MMXXMM   "
       << endl;
  cout << "       ~MMMMM~ XMM. .XM XM`\"MMMb.~*?**~ .MMX M t MMbooMM XMMMMMP   "
       << endl;
  cout << "        ?MMM>  YMMMMMM! MM   `?MMRb.    `\"\"\"   !L\"MMMMM XM IMMM "
          "   "
       << endl;
  cout << "         MMMX   \"MMMM\"  MM       ~%:           !Mh.\"\"\" dMI "
          "IMMP    "
       << endl;
  cout << "         'MMM.                                             IMX     "
       << endl;
  cout << "          ~M!M                                             IMP     "
       << endl
       << endl;
  cout << "                            - TSE EDITION -                        "
       << endl;

  printMenu();

  do {
    cin >> choice;
    switch (choice) {
    case 1: {
      int chx = 0;
      do {
        cout << " 1 - Tri naturel " << endl << " 2 - Tri par nom " << endl;
        cin >> chx;
      } while (chx != 1 && chx != 2);
      if (chx == 1) {
        afficheBestiaire(bestiaire);
      } else {
        afficheBestiaireTrie(bestiaire);
      }
      break;
    }
    case 2:
      displayPokedex(pokedex, bestiaire, typesLabel, ressources);
      break;
    case 3: {
      int catchchoice = 3;
      do {
        Pokemon *p = genererPokemon(bestiaire, typesLabel);
        cout << endl
             << "\tVous apercevez le pokemon sauvage suivant : " << endl
             << endl;
        display(*p, bestiaire, typesLabel);
        cout << endl << "\tQue souhaitez-vous faire ? " << endl;
        cout << "\t 1- Tenter de le capturer" << endl;

        cout << "\t 2- Laisser ce pokemon vivre sa vie en plein air.";
        cout << "Regardons s'il n'y en aurait pas d'autres aux alentours ..."
             << endl;
        cout << "\t 3- Ne plus attraper de pokemon." << endl;
        cin >> catchchoice;

        if (catchchoice == 1) {
          if ((int)(random_at_most(100)) >= 70) {
            cout << "\t Vous avez capturé ce pokemon, hell yeah !" << endl
                 << endl;
            insertPokemon(&pokedex, *p);

            // mise à jour des ressources
            ressources.stardust = ressources.stardust + 100;
            ressources.candies = ressources.candies + 3;
          } else {
            cout << "\t Le pokemon s'est échappé ! " << endl << endl;
          }

          catchchoice = 3;
          cout << "\tVoulez-vous continuer à attraper des pokemons ?" << endl;
          cout << "\t 1 - Oui" << endl;
          cout << "\t 2 - Non" << endl;
          cin >> catchchoice;
          if (catchchoice == 2) {
            catchchoice =
                3; // forcer le fait de sortir du menu après une capture
          }
        }
      } while (catchchoice != 3);
      break;
    }
    case 4:
      cout << "Voici le contenu de votre pokedex : " << endl << endl;
      displayPokedex(pokedex, bestiaire, typesLabel, ressources);
      powerupAndEvolution(pokedex, bestiaire, ressources, historique);
      break;
    case 5:
      displayPokedex(pokedex, bestiaire, typesLabel, ressources);
      cout << "entrer deux deux identifiants de pokemon dans le bestiaire"
           << endl;
      int id1;
      int id2;
      do {
        cin >> id1;
        cin >> id2;
      } while (id1 >= 150 && id1 < 0 && id2 >= 150 && id2 < 0);
      // combat(id1 , id2);
      break;
    case 6:
      afficherHistorique(historique);
      break;
    case 7:
      std::cout << exit_msg << endl;
      return 0;
    default:
      cout << "Veuillez saisir une entrée entre 1 et 6.";
      break;
    }
    printMenu();
  } while (choice != 7);

  std::cout << exit_msg << endl;
  return 0;
}
