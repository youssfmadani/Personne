#include <stdio.h>
#include <string.h>

struct Adresse {
    char rue[50];
    char ville[50];
    int codePostal;
};

struct Personne {
    char nom[50];
    int age;
    struct Adresse adresse;
};

int main() {
    struct Personne personnes[100]; 
    int nbPersonnes = 0;

    while (1) {
        printf("\n------------------Menu-------------------:\n");
        printf("1. Ajouter une personne\n");
        printf("2. Afficher toutes les personnes\n");
        printf("3. Modifier une personne\n");
        printf("4. Supprimer une personne\n");
        printf("5. Quitter\n");

        int choix;
        printf("#############   Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                if (nbPersonnes < 100) {
                    printf("Entrez les informations de la nouvelle personne:\n");
                    printf("Nom: ");
                    scanf("%s", personnes[nbPersonnes].nom);
                    printf("Age: ");
                    scanf("%d", &personnes[nbPersonnes].age);
                    printf("Rue: ");
                    scanf("%s", personnes[nbPersonnes].adresse.rue);
                    printf("Ville: ");
                    scanf("%s", personnes[nbPersonnes].adresse.ville);
                    printf("Code postal: ");
                    scanf("%d", &personnes[nbPersonnes].adresse.codePostal);
                    nbPersonnes++;
                } else {
                    printf("Tableau plein.\n");
                }
                break;
            case 2:
                if (nbPersonnes == 0) {
                    printf("Aucune personne enregistrée.\n");
                } else {
                    printf("Liste des personnes:\n");
                    for (int i = 0; i < nbPersonnes; i++) {
                        printf("Personne %d:\n", i+1);
                        printf("Nom: %s\n", personnes[i].nom);
                        printf("Age: %d ans\n", personnes[i].age);
                        printf("Adresse: %s, %s (%d)\n", personnes[i].adresse.rue, personnes[i].adresse.ville, personnes[i].adresse.codePostal);
                    }
                }
                break;
                case 3:
                if (nbPersonnes == 0) {
                    printf("Aucune personne enregistrée.\n");
                } else {
                    int indice;
                    printf("Entrez l'indice de la personne à modifier : ");
                    scanf("%d", &indice);
                    if (indice >= 0 && indice < nbPersonnes) {
                        printf("Nouvelles informations pour la personne %d :\n", indice+1);
                         if (indice >= 0 && indice < nbPersonnes) {
                        	 printf("Nom: ");
                             scanf("%s", personnes[indice].nom);
                             printf("Age: ");
                             scanf("%d", &personnes[indice].age);
                             printf("Rue: ");
                             scanf("%s", personnes[indice].adresse.rue);
                             printf("Ville: ");
                             scanf("%s", personnes[indice].adresse.ville);
                             printf("Code postal: ");
                             scanf("%d", &personnes[indice].adresse.codePostal);
                           
                        }
                       
                    } else {
                        printf("Indice invalide.\n");
                    }
                }
                break;
            case 4:
                if (nbPersonnes == 0) {
                    printf("Aucune personne à supprimer.\n");
                } else {
                    int indice;
                    printf("Entrez l'indice de la personne à supprimer : ");
                    scanf("%d", &indice);
                    if (indice >= 0 && indice < nbPersonnes) {
                        for (int i = indice; i < nbPersonnes - 1; i++) {
                            personnes[i] = personnes[i+1];
                        }
                        nbPersonnes--;
                        printf("Personne supprimée.\n");
                    } else {
                        printf("Indice invalide.\n");
                    }
                }
                break;
           
        
            case 5:
                printf("Au revoir!\n");
                return 0;
            default:
                printf("Choix invalide.\n");
        }
    }

    return 0;
}
