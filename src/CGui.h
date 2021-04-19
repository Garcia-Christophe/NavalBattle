/*
 *	Chaque joueur a besoin de visualiser sa propre grille (ses propres bateaux et les ploufs
 *  adverses) mais également la grille de l'adversaire pour connaître l'emplacement des tirs victorieux
 *  et des ploufs du joueur. Dès lors, DEUX grilles doivent être affichées : elles sont mémorisées par
 *  les attributs m_grilleJou et m_grilleAdv de la classe CGui.
 *  
 *  La classe CGui hérite de la classe abstraite CBaseJeu dans laquelle est déclarée, parmi
 *  d'autres méthodes abstraites, la méthode abstraite virtual void remplirDeuxGrilles ( ostream& os )
 *  = 0 qui doit se charger de l'affichage des 2 grilles. TOUTES les méthodes abstraites (virtual...=0)
 *  de CBaseJeu doivent être redéfinies dans CGui.
 *
 *  Afin de pouvoir afficher dans les grilles, les bateaux du joueur, de même que les tirs de
 *  l'adversaire et les tirs du joueur sur la grille adverse, la classe CGui possède 2 attributs
 *  supplémentaires : l'un de type pointeur sur l'armada du joueur (m_pArmada) et l'autre de type
 *  pointeur sur la structure de mémorisation des tirs (m_pCoups).
 *
 *  Un exemple de grille du joueur est donné en annexe2. Par pure convention pour l’affichage,
 *  définir une constante TAILLE_GRILLE = nbre de lignes + 1 (ou nbre de colonnes + 1 car la grille
 *  est carrée) pour tenir compte de l’affichage supplémentaire des légendes 0...(nbre colonnes – 1) et
 *  0...(nbre lignes – 1).
 */

#ifndef CGUI_H
#define CGUI_H

#include "BiblioStd.h"
#include "CBaseJeu.h"
#include "CArmada.h"
#include "CCoups.h"

class CGui : public CBaseJeu {

	private:
        char m_grilleJou[TAILLE_GRILLE-1][TAILLE_GRILLE-1];         		// Grille du joueur

        char m_grilleAdv[TAILLE_GRILLE-1][TAILLE_GRILLE-1];         		// Grille de l'adversaire

        CArmada* m_pArmada;                                         		// Pointeur sur l'unique armada du joueur

        CCoups* m_pCoups;                                           		// Pointeur sur l'unique structure d'enregistrement des tirs

	public:
        CGui ();						    								// Constructeur par défaut de CGui : m_pArmada et m_pCoups à NULL

        CGui ( CArmada* pArmada, CCoups* pCoups );                  		// Constructeur qui reçoit un pointeur sur l'armada et un pointeur sur la 
                                                                    		// structure d'enregistrement des tirs

        virtual ~CGui ();		                                            // Destructeur : destruction des zones pointées par m_pArmada et m_pCoups

        void setArmadaCoups ( CArmada* pArmada, CCoups* pCoups );   		// Modificateur : mise à jour des attributs

        friend ostream& operator<< ( ostream& os, CGui& theG );     		// Surcharge de l'opérateur << pour l'affichage des grilles. Cette fonction
                                                                    		// fait un simple appel à remplirDeuxGrilles(...) de l'objet theG

		bool positionnerBateaux () override;								// Méthode appelée au début du jeu pour positionner tous les bateaux sur la
																			// grille en exécutant placerAleatoirement de CArmada. Renvoie faux si le
																			// positionnement a échoué

		pair<int,int> choisirAttaque () override;							// Saisie de la coordonnée (ligne, colonne) de l'attaque (vérification
																			// obligatoire bon/mauvais après saisie de la coordonnée par l'utilisateur)

		void afficheGagne () override;										// Affiche la partie est gagnée à l'écran

		void affichePerdu () override;										// Affiche la partie est perdue à l'écran

	private:
		void remplirDeuxGrilles ( ostream& os ) override;					// Voir explication (1) ci-dessous

		void afficherLaGrille ( ostream& os, string jouOuAdv ) override;	// Affichage d'une grille (joueur ou adversaire) à l'écran, c'est-à-dire
																			// affichage du contenu de m_grilleJou ou m_grilleAdv + les légendes
																			// (0...TAILLE_GRILLE-2).

/*
 * (1) la méthode void remplirDeuxGrilles ( ostream& os ) doit :
 * 
 * ● remplir la grille du joueur m_grilleJou :
 * 		– en mettant 'B' dans les cases occupées par les cases des bateaux (du joueur) non touchées
 * 		– en mettant 'X' dans les cases occupées par les cases des bateaux (du joueur) touchées
 *		– en mettant 'O' dans les cases ou les tirs adverses ont échoués (ploufs)
 * Pour cela, se baser d'une part sur l'armada du joueur pour les bateaux (un bateau connait
 * l'emplacement des tirs adverses) et, d'autre part, sur la structure m_pCoups du joueur pour
 * les ploufs de l'adversaire (clé de recherche ploufAdverse).
 * Afficher cette grille en appelant afficherLaGrille ( os, "joueur" ).
 *
 * ● remplir la grille de l'adversaire m_grilleAdv :
 *		– en mettant 'X' dans les cases où les tirs du joueur sont victorieux
 *		– en mettant 'O' dans les cases où les tirs du joueur ont échoués (ploufs)
 * Pour cela, consulter la structure m_pCoups du joueur pour rechercher la position de ses tirs
 * à l'aide des clés de recherche touche et dansLEau.
 * Afficher cette grille en appelant afficherLaGrille ( os, "adversaire" ).
 */
};

#endif // CGUI_H
