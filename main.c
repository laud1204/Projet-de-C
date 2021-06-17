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
*  Nom du fichier : main.c                                                    *
*                                                                             *
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "fonctions.h"

//Fonction principale : main
void main() {
    char message[1000];
    printf("Veuillez saisir votre message s'il vous plait \n(taille max de 1000 caracteres / accents et caracteres speciaux non acceptes) : \n"); // Demande � l'utilisateur son message
    fgets(message, 1000, stdin);
    // Tant que le message saisi contient des caract�res inappropri�s, redemande la saisie du message
    while (!verificationAlphanumMessage(message)) {
        printf("Le message est incorrect, entrez votre message : \n");
        fgets(message, 1000, stdin);
        verificationAlphanumMessage(message);
    }
    printf("\n"); // Saut de ligne

    // Demande � l'utilisateur ce qu'il souhaite faire : chiffrer ou d�chiffrer son message
    int choix = 0;
    printf("Que souhaitez-vous faire ? \n");
    printf("\n1 - Je souhaite chiffrer mon message \n");
    printf("2 - Je souhaite dechiffrer mon message \n");
    // Tant que le choix n'est pas 1 ou 2, redemande � l'utilisateur de saisir son choix
    while(choix < 1 || choix > 2) {
        printf("\nVeuillez saisir votre choix (merci de choisir le cas 1 ou le cas 2) : \n");
        scanf("%d", &choix);

    }

    // Demande � l'utilisateur de choisir sa cl� de chiffrement/d�chiffrement
    int cle = 0;
    // Tant que la cl� n'est pas comprise entre 1 et 25, redemande � l'utilisateur de saisir une cl� valide
    while(cle < 1 || cle > 25) {
        printf("\nVeuillez saisir votre cle de chiffrement/dechiffrement (merci de choisir une valeur comprise entre 1 et 25) : \n");
        scanf("%d", &cle);
    }

    // Si le choix est 1 alors on chiffrera le message donn� avec la cl� donn�e
    // Si le choix est 2 alors on d�chiffrera le message donn� avec la cl� donn�e
    if (choix == 1) {
        chiffrementMessage(message, cle);
        printf("\nLe message chiffre est : %s \n", message);
        sauvegarderDansUnFichier(message);
        printf("\nVotre message chiffre est sauvegarde dans un fichier ! ");
        printf("\n"); // Saut de ligne
    }else{
        if (choix == 2){
            dechiffrementMessage(message, cle);
            printf("\nLe message dechiffre est : %s \n", message);
            sauvegarderDansUnFichier(message);
            printf("\nVotre message dechiffre est sauvegarde dans un fichier ! \n");
            printf("\n");// Saut de ligne
        }
    }
}


