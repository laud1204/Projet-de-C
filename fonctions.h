/******************************************************************************
*  ASR => M2101                                                               *
*******************************************************************************
*                                                                             *
*  N� de Sujet : 3                                                            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitul� : Chiffrement de messages                                         *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-pr�nom1 : DELMAS Lauretta    Groupe B1                                 *
*                                                                             *
*  Nom-pr�nom2 : DIEYE Awa          Groupe B1                                 *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier : fonctions.h                                               *
*                                                                             *
******************************************************************************/

#include <stdio.h>

// Signatures des fonctions cr��es
bool verificationAlphanumMessage(char message[]);
void chiffrementMessage(char message[], int cle);
void dechiffrementMessage(char messagecode[], int cle);
void sauvegarderDansUnFichier(char message[]);
