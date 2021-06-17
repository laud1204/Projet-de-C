Projet de C / M2101 / S2 / 2020-2021
Groupe B1 - DELMAS Lauretta & DIEYE Awa


DESCRIPTION DE L'ALGORITHME DE CESAR : 
" Le code César est un chiffrement basé sur un décalage 
de l'alphabet (déplacement des lettres plus loin dans 
l'alphabet), il s'agit d'une substitution monoalphabétique, 
c'est-à-dire qu'une même lettre n'est remplacée que 
par une seule autre (toujours identique pour un même message)."


SOURCES : 
- http://exo7.emath.fr/cours/ch_crypto.pdf 
- https://www.dcode.fr/chiffre-cesar#:~:text=Le%20code%20C%C3%A9sar%20est%20un,identique%20pour%20un%20m%C3%AAme%20message).


PETITES PRECISIONS :
- Nous avons décidé de traiter uniquement des messages contenant des lettres minuscules ou majuscules
et d'exclure les caractères numériques "0123456789".
- Nous avons également exclu les caractères spéciaux et les lettres accentuées.
- Nous avons fait le choix de faire un affichage console du résultat et de stocker également 
le résultat dans un fichier texte "result.txt" qui se retrouve dans le dossier du projet après éxécution. 
- Notre programme comprend les espaces dans le message donné.
- Nous avons pensé à faire des boucles while pour les cas de saisie incorrects.
- Nous avons limité la taille du message à 1000 caractères pour ne pas avoir une durée d'exécution trop longue.


LES FONCTIONS DEVELOPPEES (contenues dans le fichier "fonctions.c") :
// Fonction "verificationAlphanumMessage"
// Permet de détecter des caractères inappropriés
// Paramètres : un tableau de char qui constitue le message
// Return : un booléen
bool verificationAlphanumMessage (char message[]){
    bool correct = true;
    char charactereSpeciaux[40]= {'>','<','#','(','{','[',']','}',')','/','*','-','+','.',
                                 '@','|','&','~','"','_','`','^','?',';',',',':','!','%',
                                 '$','§','µ','£','¤','*','€','=','°','²','\'','\\'};
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
// Permet de chiffrer un message donné avec la méthode de César
// Paramètres : un tableau de char qui constitue le message, un entier qui constitue la clé de chiffrement
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
// Permet de dechiffrer un message donné avec la méthode de César
// Paramètres : un tableau de char qui constitue le message, un entier qui constitue la clé de chiffrement
void dechiffrementMessage(char messagecode[], int cle){
  int i = 0;
  // Tant qu'on ne rencontre pas le caractère de fin on continue de parcourir le tableau de caractères
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
// Permet de stocker le message chiffré/déchiffré dans un fichier
// Paramètres : un tableau de char qui constitue le message
void sauvegarderDansUnFichier(char message[]){
    FILE* fichier = NULL;
    // Le fichier produit s'appelle "result.txt"
    fichier = fopen("result.txt", "w"); // On y ajoute le droit d'écriture
    fprintf(fichier, "%s", message);
    fclose(fichier);
}
