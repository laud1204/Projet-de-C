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
*  Nom du fichier : makefile                                                  *
*                                                                             *
******************************************************************************/
all: main

main: main.c
	gcc main.c -o main

clean:
	rm -f main
