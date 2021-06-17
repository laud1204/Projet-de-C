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
*  Nom du fichier : fonctions.c                                               *
*                                                                             *
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Fonction "verificationAlphanumMessage"
// Permet de d�tecter des caract�res inappropri�s
// Param�tres : un tableau de char qui constitue le message
// Return : un bool�en
bool verificationAlphanumMessage (char message[]){
    bool correct = true;
    char charactereSpeciaux[40]= {'>','<','#','(','{','[',']','}',')','/','*','-','+','.',
                                 '@','|','&','~','"','_','`','^','?',';',',',':','!','%',
                                 '$','�','�','�','�','*','�','=','�','�','\'','\\'};
    for(int i = 0; i < wcslen(message); i++){
        for(int j = 0; j < 40; j++){
            if(message[i] == charactereSpeciaux[j]){
                return correct = false;
            }
        }
    }
    return correct;
}

// Procedure "chiffrementMessage"
// Permet de chiffrer un message donn� avec la m�thode de C�sar
// Param�tres : un tableau de char qui constitue le message, un entier qui constitue la cl� de chiffrement
void chiffrementMessage(char message[], int cle) {
  int i = 0;
  while (message[i] != '\0') {
    // Cas des lettres majuscules
    if (message[i] >= 'A' && message[i]<= 'Z') {
        message[i] = 'A' + ((message[i] - 'A') + cle) % 26;
    } else {
        // Cas des lettres minuscules
        if (message[i] >= 'a' && message[i]<= 'z') {
            message[i] = 'a' + ((message[i] - 'a') + cle) % 26;
        }
    }
    i++;
  }
}

// Procedure "dechiffrementMessage"
// Permet de dechiffrer un message donn� avec la m�thode de C�sar
// Param�tres : un tableau de char qui constitue le message, un entier qui constitue la cl� de chiffrement
void dechiffrementMessage(char messagecode[], int cle){
  int i = 0;
  // Tant qu'on ne rencontre pas le caract�re de fin on continue de parcourir le tableau de caract�res
  while (messagecode[i] != '\0') {
    // Cas des lettres majuscules
    if (messagecode[i] >= 'A' && messagecode[i]<= 'Z') {
        messagecode[i] = 'A' + ((messagecode[i] - 'A') + 26 - cle) % 26;
    } else {
        // Cas des lettres minuscules
        if (messagecode[i] >= 'a' && messagecode[i]<= 'z') {
            messagecode[i] = 'a' + ((messagecode[i] - 'a') + 26 - cle) % 26;
        }
    }
    i++;
  }
}

// Procedure "sauvegarderDansUnFichier"
// Permet de stocker le message chiffr�/d�chiffr� dans un fichier
// Param�tres : un tableau de char qui constitue le message
void sauvegarderDansUnFichier(char message[]){
    FILE* fichier = NULL;
    // Le fichier produit s'appelle "result.txt"
    fichier = fopen("result.txt", "w"); // On y ajoute le droit d'�criture
    fprintf(fichier, "%s", message);
    fclose(fichier);
}
