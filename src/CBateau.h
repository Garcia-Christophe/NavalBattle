/*
 *	Un bateau est caractérisé par le nombre de cases (m_taille) qu'il occupe sur la grille, par un
 *	nom (porte-avion, croiseur, ...) et par le point de départ de sa position HORIZONTALE sur la
 *	grille (appelé point d'ancrage du bateau sur la grille) : pair<int,int> m_position, (0, 0)
 *	correspondant à la case en haut à gauche sur la grille. 
 *	Il mémorise également dans un tableau de booléens les dégâts occasionnés sur le bateau (une case
 *	est à faux si elle n'est pas touchée par un tir adverse).
 */

#ifndef CBATEAU_H
#define CBATEAU_H

#include "BiblioStd.h"

class CBateau {

	private:
		int m_taille;												// nombre de cases occupées (horizontalement) sur la grille
		
		string m_nom; 												// nom du bateau
		
		pair<int,int> m_position;									// coord. (int ligneHoriz, int colonneVert) du point d'ancrage
																	// m_position.first = le numéro de la ligne horizontale
																	// m_position.second = le numéro de la colonne verticale

		bool* m_pDegats;											// tableau des dégâts de taille m_taille (case à faux si pas de dégât)

	public:
		CBateau ();													// Constructeur par défaut : "neant", (0,0), 0, NULL
        
		CBateau ( string n, pair<int,int> p, int t );				// Constructeur, le bateau n'a encore aucune case touchée (m_pDegats à faux partout)

		CBateau( const CBateau& theB );								// Copy-constructeur, copie profondément le bateau passé en paramètre

		CBateau operator= ( CBateau& theB );						// Surcharge de l'opérateur = pour créer un nouveau bateau en copiant un existant

		bool getDegats ( int i ); 									// Renvoie vrai si la case numéro i du bateau est touchée ( 0 <= i < m_taille )
        
		string getNom();											// Accesseur : nom du bateau
       
		int getTaille();											// Accesseur : taille du bateau
        
		pair<int,int> getPosition();								// Accesseur : ancrage du bateau sur la grille

		void setPosition ( int i, int j );							// Modifie la position du bateau sur la grille en  ième ligne, jème colonne (nouveau point d'ancrage)

		bool estCoule();											// Renvoie vrai si le bateau est coulé

		bool tirAdverse ( pair<int,int> p );						// Tir adverse : renvoie vrai si la coordonnée passée en paramètre est un tir victorieux (une case du 
																	// bateau est touchée). Si le tir est victorieux il doit être marqué dans le tableau m_pDegats.
																	// ATTENTION si une case est déjà touchée il ne faut PAS renvoyer vrai (donc renvoyer faux) sinon un tir
																	// victorieux est comptabilisé en trop

		friend ostream& operator<< ( ostream& os, CBateau& theB );	// Surcharge de l'opérateur << pour afficher à l'écran les caractéristiques du bateau

		~CBateau();													// Destructeur pour libérer la place mémoire

};

#endif // CBATEAU_H
