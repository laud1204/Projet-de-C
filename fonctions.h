/******************************************************************************
*  ASR => M2101                                                               *
*******************************************************************************
*                                                                             *
*  N° de Sujet : 3                                                            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé : Chiffrement de messages                                         *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-prénom1 : DELMAS Lauretta    Groupe B1                                 *
*                                                                             *
*  Nom-prénom2 : DIEYE Awa          Groupe B1                                 *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier : fonctions.h                                               *
*                                                                             *
******************************************************************************/

#include <stdio.h>

// Signatures des fonctions créées
bool verificationAlphanumMessage(char message[]);
void chiffrementMessage(char message[], int cle);
void dechiffrementMessage(char messagecode[], int cle);
void sauvegarderDansUnFichier(char message[]);
