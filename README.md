# NavalBattle

				BATAILLE NAVALE (c++)
				Garcia Christophe B2
________________________________________________________________________________________

Le jeu est fonctionnel, et le TP de NavalBattle a pu être entièrement terminé et documenté.
Voici son avancement :

• Tous les tests sont fonctionnels tant qu'une condition est respectée : il faut que la constante 
TAILLE_GRILLE soit égale à 11, car pour l'exhaustivité des tests, il y a des cas normaux, des cas limites et 
des cas d'erreur. Si la constante TAILLE_GRILLE change, il peut y avoir des erreurs non capturées dans les
cas normaux, ou des erreurs qui ne correspondent plus au bon try/catch des cas d'erreur.

• Voici les cas d'utilisation prévus lors de la partie :

	- Entrée des coordonnées du tir : (lettres, espace, retour chariot, un nombre négatif, un
nombre > TAILLE_GRILLE - 2, 2 chiffres séparés d'un espace).

	- Tir au même endroit : si jamais l'utilisateur souhaite tiré au même endroit, que ce soit dans
l'eau ou sur un bateau déjà touché/coulé, le jeu ne comptera pas ce tir comme victorieux.

	- TAILLE_GRILLE changeable : si cette constante change, le jeu s'adapte et fonctionnera tout
aussi bien (affichage des grilles, prise des coordonnées du tir, ajout des bateaux dans l'armada, placement
aléatoire et automatique de ces bateaux).

	- Bateaux : pour une plus grande réalité/immersion, les bateaux possibles sont les suivants :
		* porte-avion (taille = 5)
		* croiseur (taille = 4)
		* contre-torpilleur (taille = 3)
		* sous-marin (taille = 2)
		* torpilleur (taille = 1)
		* neant (taille = 0), ce bateau n'est pas accepté dans une armada.

	- flotille.txt : qu'importe ce qui est écrit, la ligne doit correspondre exactement à 
NOM_DU_BATEAU_CONNU nbBateaux tailleBateau.

• Makefile : 

	- Compilation des classes :
		* make compileCBateau 
		* make compileCArmada 
		* make compileCCoups
		* make compileCGui
		* make compileCSocket
		* make compileCClientSocket
		* make compileCServerSocket
		* make compileCJoueur
		* make compileCJoueurCli
		* make compileCJoueurServ

	- Compilation des tests :
		* make compileTestCBateau
		* make compileCArmada
		* make compileTestCGui

	- Compilation et exécution des tests :
		* make testCBateau
		* make testCArmada
		* make testCGui

	- Compilation finale :
		* make lanceurFinal

	- Compilation et exécution de tous les tests :
		* make tests

	- Lancer le jeu :
		* make startGame
