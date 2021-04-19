/*
 *	Cette classe m�morise tous les tirs � la fois du joueur et de l'adversaire :
 *      	- tout ce que le joueur a mis dans l'eau dans la grille adverse (les tirs rat�s du joueur : "dansLEau")
 *       	- tout ce que le joueur a touch� comme bateaux adverses (les tirs victorieux du joueur : "touche")
 *       	- tout ce que l'adversaire a mis dans l'eau dans la grille du joueur (les tirs rat�s de l'adversaire : "ploufAdverse")
 *
 *	On se rappelle que les tirs victorieux de l'adversaire sont stock�s dans le tableau m_degats de chaque bateau du joueur.
 */

#ifndef CCOUPS_H
#define CCOUPS_H

#include "BiblioStd.h"

class CCoups {

	private:
	
		/* La structure de donn�es est de type map (�quivalent � HashTable en Java).
		 * Notre "map" (m_donnees), est un tableau o� chaque case du tableau est accessible par une cl� de type string.
		 * Par convention, on dispose de 3 cl�s : "dansLEau", "touche" et "ploufAdverse".
		 * UNE case du tableau contient une collection (vector) de coordonn�es de type pair(horiz, vert).
		 * Ces coordonn�es repr�sentent les tirs.
		 * Pour r�cup�rer les collections de tirs, il suffit d'utiliser la cl� :
		 *	m_donnees["dansLEau"] : renvoie la collection (vector) des tirs (coord.) que le joueur a mis dans l'eau dans la grille adverse
		 *	m_donnees["touche"] : renvoie la collection (vector) des tirs (coord.) victorieux du joueur dans la grille adverse
		 * 	m_donnees["ploufAdverse"] : renvoie la collection (vector) des tirs (coord.) que l'adversaire a mis dans l'eau dans la grille du joueur
		 * Note importante : pour conna�tre les d�g�ts sur les bateaux du joueur, consulter le tableau m_degats de chaque
		 * bateau du joueur.
		 */
		map < string, vector < pair < int,int> > > m_donnees;

	public:
		CCoups();													// construction par d�faut : des collections vides
        
		int getCoupsBut();											// renvoie le nombre de tirs victorieux du joueur (tirs "touche")
        
		bool tirDansMap ( const string& s, pair<int,int>& p );		// renvoie un bool�en � vrai si le tir pass� en param�tre et associ� � une cl� est dans la structure m_donnees
        
		void ajouterTirMap ( const string& s, pair<int,int>& p );	// ajoute un nouveau tir "p" dans la collection associ�e � la cl� "s" pass�e en param�tre
       
		int getTaille ( const string& s );							// renvoie la taille de la collection (vector) associ�e � la cl� "s"
        
		pair<int,int> getPair ( const string& s, int index );		// renvoie le tir stock� � l'indice "index" dans la collection associ�e � la cl� "s"

};

#endif // CCOUPS_H
