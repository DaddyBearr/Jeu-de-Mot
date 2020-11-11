#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void jeudemot()   /* Procedure qui fait l'affichage du Menu Principale */
{
    printf("MENU PRINCIPALE JEU DE MOT\n ");    /* Affiche le nom du menuc*/
    printf("\n C : Conjugaison\n ");       /* Affichage des différents menus */
    printf("M : Mirroir\n ");
    printf("P : Palindrome\n ");
    printf("O : Occurence\n ");
    printf("Q : Quitter le Menu\n");
    printf("\nChoissisez le menu de votre choix : ");    /* Demande à l'utilisateur le menu de son choix */
}

void conjugaisonv2()
{
    char*indiceterminaison;
    char*pronom[18]={"\nPresent:\nje", "tu", "il", "nous", "vous", "ils", "Imparfait:\nje", "tu", "il", "nous", "vous", "ils", "Futur:\nje", "tu", "il", "nous", "vous", "ils"};
    char*terminaison1ergroupe[18]={"e", "es", "e", "ons", "ez", "ent\n",  "ais", "ais", "ait", "ions", "iez", "aient\n",  "erai", "eras", "era", "erons", "erez", "eront\n"};
    char*terminaison2ergroupe[18]={"is", "is", "it", "issons", "issez", "issent", "issais", "issais", "issait", "issions", "issiez", "issaient", "irai", "iras", "ira", "irons", "irez", "iront"};
    char*terminaison3ergroupe[18]={"erai", "eras", "era", "erons", "erez", "eront"};

    char verbe[15],rep;
    char groupe[2];
    int i=0, longueur;
    printf("\nVous avez choisi le menu conjugaison\n");
    while(rep != 'N',rep !='n')
    {
        printf("Veuillez choisir un verbe : ");
        scanf("%s",&verbe);
        longueur=strlen(verbe);
        groupe=substr(verbe,0,-2);
        if((verbe[longueur-2])=='e' || (verbe[longueur-1])=='r')
        {
            do
            {
                indiceterminaison=verbe+strlen(verbe)-2;   /* Donne l'indice du verbe sans le suffixe 'er' */
            }
            while(strcmp(indiceterminaison,"er"));
            for(i=0; i<18; i++)
            {
                strcpy(indiceterminaison, terminaison1ergroupe[i]);
                printf("%s %s\n",pronom[i],verbe);
            }
            printf("\nVoulez-vous recommencer (O/N): ");
            scanf(" %c", &rep);
            printf("\n");
            return 0;
        }
        if((verbe[longueur-2])=='i' || (verbe[longueur-1])=='r')
        {
            do
            {
                indiceterminaison=verbe+strlen(verbe)-2;   /* Donne l'indice du verbe sans le suffixe 'er' */
            }
            while(strcmp(indiceterminaison,"ir"));
            for(i=0; i<18; i++)
            {
                strcpy(indiceterminaison, terminaison2ergroupe[i]);
                printf("%s %s\n",pronom[i],verbe);
            }
            printf("\nVoulez-vous recommencer (O/N): ");
            scanf(" %c", &rep);
            printf("\n");
            return 0;
        }
        if((verbe[longueur-2])=='r' || (verbe[longueur-1])=='e')
        {
            do
            {
                indiceterminaison=verbe+strlen(verbe)-2;   /* Donne l'indice du verbe sans le suffixe 'er' */
            }
            while(strcmp(indiceterminaison,"re"));
            for(i=0; i<18; i++)
            {
                strcpy(indiceterminaison, terminaison3ergroupe[i]);
                printf("%s %s\n",pronom[i],verbe);
            }
            printf("\nVoulez-vous recommencer (O/N): ");
            scanf(" %c", &rep);
            printf("\n");
            return 0;
        }
    }
}
void conjugaison()       /* Procedure pour le menu Conjugaison*/
{
    /* Initialisation des pronoms personnels pour les 3 temps */
    char * pronom[18]= {"\nPresent:\nje", "tu", "il", "nous", "vous", "ils", "Imparfait:\nje", "tu", "il", "nous", "vous", "ils", "Futur:\nje", "tu", "il", "nous", "vous", "ils"};
    /* Initialisation des terminaison des 3 temps */
    char * terminaisonverbe[18]= {"e", "es", "e", "ons", "ez", "ent\n",  "ais", "ais", "ait", "ions", "iez", "aient\n",  "erai", "eras", "era", "erons", "erez", "eront\n"};
    char * indiceterminaison;   /* Initialisation de la chaîne de caractère indiceterminaison */
    char verbe[15],rep;   /* Initialisation taille de la chaîne de caractère pour le verbe et le caractère pour repeter le programme */
    int i=0,longueur;     /* Initialisation i et longueur pour le verbe */
    printf("\nVous avez choisi le menu conjugaison\n");
    while(rep != 'N',rep !='n')     /* Boucle tant que pour repeter le programme */
    {
        printf("Veuillez choisir un verbe du premier groupe :");   /* Demande de saisie du verbe à l'utilisateur */
        scanf("%s",&verbe);
        longueur= strlen(verbe);    /* La fonction strlen permet de calculer la longueur d'une chaîne de caractère donc calcul la longueur du verbe */
        if((verbe[longueur-2])!='e' || (verbe[longueur-1])!='r')    /* Boucle 'pour' pour vérifier si le verbe fait parti du premier groupe */
            printf("Ce n'est pas un verbe du premier groupe!\n\n");   /* Affiche un message d'erreur si le verbe n'est pas du premier groupe */
        else
        {
            do
            {
                indiceterminaison=verbe+strlen(verbe)-2;   /* Donne l'indice du verbe sans le suffixe 'er' */
            }
            while(strcmp(indiceterminaison,"er"));  /* La fonction strcmp permet de comparer deux chaîne de caractère pour verifier que le verbe finise par 'er' */
            for(i=0; i<18; i++)
            {
                strcpy(indiceterminaison, terminaisonverbe[i]);
                printf("%s %s\n",pronom[i],verbe);
            }
            printf("\nVoulez-vous recommencer (O/N): "); /* Demande à l'utilisateur si il veut recommencer ou quitter le programme */
            scanf(" %c", &rep);
            printf("\n");
        }
    }
    return 0;   /* Retourne au menu principal */
}

void mirroir()   /* Procedure pour le menu Mirroir */
{
    char mot[15],rep;     /* Déclaration chaîne de caractere pour le mot et le caractere pour repeter le programme */
    int ind = 0, longueur;  /* Décclaration indice du tableau et la longueur du mot */
    printf("\nLe programme mirroir ecrit le mot choisi a l envers\n");
    while (rep != 'N',rep !='n')       /* Boucle tant que pour repeter le programme */
    {
        printf("Veuillez saisir un mot:");   /* Demande de saisie de la chaîne de caractere à l'utilisateur */
        scanf("%s", mot);
        printf("\nLe mot inverse donne :");
        longueur = strlen(mot); /* La fonction strlen permet de calculer la longueur du mot */
        for(ind = (longueur - 1); ind >= 0; ind--)   /* Boucle 'pour' qui permet de changer l'indice du tableau pour renverser la chaîne */
        {
            printf(" %c",mot[ind]);   /* Affiche la chaîne de caractere à l'envers */
        }
        printf("\n\nVoulez-vous recommencer (O/N): ");  /* Demande à l'utilisateur si il veut recommencer ou quitter le programme */
        scanf(" %c", &rep);
        printf("\n");
    }
    return 0;  /* Retourne au menu principal */
}

void palindrome() /* Procedure pour le menu Palindrome */
{
    char mot[15],mot2[15],rep;  /* Déclaration chaîne de caractere pour le mot et le caractere pour repeter le programme */
    int ind = 0, longueur,comp,cpt=0;  /* Décclaration indice du tableau et la longueur du mot */
    printf("\nLe programme palindrome \n");
    while (rep != 'N',rep !='n')       /* Boucle tant que pour repeter le programme */
    {
        printf("Veuillez saisir un mot:");   /* Demande de saisie de la chaîne de caractere à l'utilisateur */
        scanf("%s",&mot);
        strcpy(mot2,mot);
        printf("\nLe mot inverse donne :");
        longueur = strlen(mot); /* La fonction strlen permet de calculer la longueur du mot */
        for(ind = (longueur - 1); ind >= 0; ind--)   /* Boucle 'pour' qui permet de changer l'indice du tableau pour renverser la chaîne */
        {
            printf(" %c",mot[ind]);   /* Affiche la chaîne de caractere à l'envers */
        }
        for(ind=0;ind<longueur;ind++)
        {
            comp=strcmp(mot2,mot);
            if(comp!=0)
                break;
            else
                cpt++;
        }
        if(cpt==longueur)
            printf(" \nCe mot est un palindrome\n");
        else
        {
            printf(" \nCe mot n'est pas un palindrome\n");
        }
        printf("\n\nVoulez-vous recommencer (O/N): ");  /* Demande à l'utilisateur si il veut recommencer ou quitter le programme */
        scanf(" %c", &rep);
        printf("\n");
    }
    return 0;  /* Retourne au menu principal */
}


void occurence()
{
    int i, longueur, occurrence = 0;  /* Déclaration i, longueur du mot et l'occurence */
    char carac,rep,mot[15];    /* Déclaration du caractère recherche de la lettre, le caractère pour repeter le programme et la chaîne de caractère pour le mot */
    printf("\nVous avez choisi l occurrence d un mot\n");
    while(rep != 'N',rep !='n')       /* Boucle tant que pour repeter le programme */
    {
        printf("Veuillez saisir un mot:");   /* Demande de saisie du mot par l'utilisateur */
        scanf("%s", mot);
        longueur = strlen(mot);   /* La fonction strlen permet de calculer la longueur d'une chaîne de caractère donc calcul la longueur du mot */
        printf("\nVeuillez saisir le caractere recherche : ");    /* Demande de saisie du caractère rechercher par l'utilisateur */
        scanf(" %c", &carac);
        for(i = 0; i < longueur; i++)   /* Boucle 'pour' qui permet de faire la recherche du caractère saisie */
        {
            if(carac == mot[i])   /* Condition qui vérifie si le caractère choisi ce trouve dans le mot et compte le nombre de fois qu'il revient */
                occurrence++;
        }
        printf("Le mot que vous avez saisi possede %d fois la lettre  '%c'.\n\n", occurrence, carac);
        printf("\nVoulez-vous recommencer (O/N): ");    /* Demande à l'utilisateur si il veut recommencer ou quitter le programme */
        scanf(" %c", &rep);
        printf("\n");
    }
    return 0;         /* Retourne au menu principal */
}


int main()
{
    char signe;           /* Déclaration du signe qui permet de choisir le menu */
    jeudemot();
    scanf(" %c",& signe);
    while(signe != 'Q', signe != 'q')    /* Boucle tant que qui permet de rentrer dans le menu ou le quitter */
    {
        switch(signe)      /* Boucle selon qui permet de choisir un menu */
        {
            case 'C':
                do
                {
                    conjugaisonv2();    /* Ouvre la procedure conjugaison */
                }
                while(signe=='O',signe=='o');
            break;
            case 'c':
                do
                {
                    conjugaisonv2();    /* Ouvre la procedure conjugaison */
                }
                while(signe=='O',signe=='o');
            break;
            case 'M':
                do
                {
                    mirroir();     /* Ouvre la procedure mirroir */
                }
                while(signe=='O',signe=='o');
            break;
            case 'm':
                do
                {
                    mirroir();     /* Ouvre la procedure mirroir */
                }
                while(signe=='O',signe=='o');
            break;
            case 'P':
                do
                {
                    palindrome();      /* Ouvre la procedure palindrome */
                }
                while(signe=='O',signe=='o');
            break;
            case 'p':
                do
                {
                    palindrome();      /* Ouvre la procedure palindrome */
                }
                while(signe=='O',signe=='o');
            break;
            case 'O':
                do
                {
                    occurence();      /* Ouvre la procedure occurence */
                }
                while(signe=='O',signe=='o');
            break;
            case 'o':
                do
                {
                    occurence();      /* Ouvre la procedure occurence */
                }
                while(signe=='O',signe=='o');
            break;
            default:
                printf("\nErreur de saisie\n\n");    /* Message erreur de saisie si le caractère n'est attribuer */
            break;
        }
    jeudemot();
    scanf(" %c",& signe);
    }
    return 0;   /* */
}
