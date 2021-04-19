/*
 *	Une armada se compose d'une collection de bateaux ( vector<CBateau> m_listeBateaux ).
 *	La méthode bool placerAleatoirement() place aléatoirement TOUS les bateaux de la flottille à des
 *	positions compatibles avec les dimensions de la grille. Pour le placement aléatoire d'un bateau sur
 *	la grille, voici la marche à suivre :
 *	    ● utiliser rand() pour tirer un entier aléatoire k compris entre 0 et borneSup (y compris) :
 *	        1. srand ( time(NULL) ) ; // initialisation du tirage aléatoire 1 seule fois
 *	        2. int k = rand() % (borneSup + 1) ; // utilisation de rand() et du modulo
 *	    ● placer le bateau de telle sorte qu'il ne touche pas un autre bateau de la grille qui se trouve
 *	        sur la même ligne (ils peuvent par contre se chevaucher si ils se situent sur des lignes
 *	        différentes),
 *	    ● si le nombre de bateaux est trop important et rend le placement impossible sur la grille
 *	        (définir un nombre de tentatives maximum avec une constante MAX_ESSAIS) alors abandonner le 
 *	        placement et renvoyer faux.
 *	
 *	La lecture de TOUTE l’armada à partir d’un fichier texte flotille.txt est réalisée par la
 *	méthode void getArmadaFromFile() qui lit les bateaux un par un et les ajoute dans la collection de
 *	bateaux m_listeBateaux. Le placement aléatoire des bateaux se fait séparément lors de la mise en 
 *	place du jeu (voir fichier main.cpp). Le fichier flotille.txt doit obligatoirement respecter la 
 *	structure suivante :
 *	    # ceci est une ligne de commentaire qui commence par « # »
 *	    # format de 1 ligne :
 *	    # nomDuBateau<ESPACE>nombreSurGrille<ESPACE>nombreCasesHorizontales
 *	    # exemples :
 *	    torpilleur 2 2
 *	    porte-avion 1 4
 */

#ifndef CARMADA_H
#define CARMADA_H

#include <stdio.h>
#include <ctype.h>
#include "BiblioStd.h"
#include "CBateau.h"

class CArmada {

	private:
        vector<CBateau> m_listeBateaux;                             // La collection de bateaux qui est VIDE au départ

	public:
        CArmada ();                                                 // Constructeur par défaut de CArmada : crée le vecteur (taille à 0)

        void ajouterBateau ( CBateau& unBat );                      // Ajoute un bateau dans la structure m_listeBateaux (à la suite avec la méthode 
                                                                    // push_back de la classe vector)

        CBateau* getBateau ( int i );                               // Accesseur : renvoie (par pointeur) le bateau qui se trouve à l'index i dans le 
                                                                    // tableau (0 <= i < taille)

        int getEffectifTotal();                                     // Renvoie le nombre total de bateaux de l'armada

        int getNbreTotCases();                                      // Accesseur : renvoie le nombre total de cases occupées par l'armada

        int getEffectif();                                          // Renvoie le nombre de bateaux qui ne sont pas encore coulés (flottille encore en vie
                                                                    // sur l'eau)

        void getArmadaFromFile();                                   // Lecture du fichier flotille.txt qui contient la liste complète de tous les bateaux

        bool placerAleatoirement();                                 // Placement aléatoire ET automatique horizontalement de TOUS les bateaux sur la grille.
                                                                    // Renvoie faux si le positionnement automatique a échoué.

};

#endif // CARMADA_H
