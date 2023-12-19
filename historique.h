#pragma once

typedef struct Evolution {
  const char *from;
  const char *to;
  Evolution *nextEvolution;
} Evolution;

typedef struct {
  int nombre;
  Evolution *debut;
} Historique;

void insererTete(Historique *historique, const char *from, const char *to);
void afficherHistorique(Historique *historique);
