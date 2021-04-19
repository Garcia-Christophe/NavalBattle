#include "CArmada.h"

void testConstructeurParDefaut();
void testAjouterBateau();
void testGetBateau();
void testGetEffectifTotal();
void testGetNbreTotCases();
void testGetEffectif();
void testGetArmadaFromFile();
void testPlacerAleatoirement();

/**
 * Le main permet d'appeler toutes les méthodes de tests de la classe CArmada.
 */
int main () {
    cout << "\n*** TestCArmada ***" << endl;

    testConstructeurParDefaut();
    testAjouterBateau();
    testGetBateau();
    testGetEffectifTotal();
    testGetNbreTotCases();
    testGetEffectif();
    testGetArmadaFromFile();
    testPlacerAleatoirement();

    cout << "\n*** fin de TestCArmada ***\n" << endl;

    return 0;
}

/**
 * Teste le constructeur par défaut.
 */
void testConstructeurParDefaut() {
    cout << "\n== testConstructeurParDefaut ==" << endl;

    CArmada armada;
    cout << "\nNombre de bateaux dans l'armada : " << armada.getEffectifTotal() << endl;
}

/**
 * Teste la méthode d'ajout d'un bateau dans l'armada.
 */
void testAjouterBateau() {
    cout << "\n== testAjouterBateau ==" << endl;

    CArmada armada;
    CBateau bateau1("croiseur", pair<int, int>(2, 2), 4);
    CBateau bateau2("torpilleur", pair<int, int>(1, 1), 1);
    CBateau bateau3;

    /* Cas NORMAL */

    armada.ajouterBateau(bateau1);
    cout << "\nAjout bateau 1." << endl; 

    armada.ajouterBateau(bateau2);
    cout << "Ajout bateau 2." << endl; 

    /* Cas LIMITE */

    // Ajout d'un bateau déjà ajouté
    cout << "\nCas limite :" << endl;
    armada.ajouterBateau(bateau1);
    cout << "Ajout bateau 1." << endl; 
    
    // Affichage de l'armada pour vérifier
    cout << "\nAffichage de l'armada pour vérifier :\n"<< endl; 
    for (int i = 0; i < armada.getEffectifTotal(); i++) {
        cout << "Bateau " << i << ":\n" << *armada.getBateau(i) << endl;
    }

    /* Cas ERREUR */

    cout << "\nCas erreur :" << endl;
    try {
        cout << "Ajout bateau 3." << endl;
        armada.ajouterBateau(bateau3);
    } catch (logic_error e) {
        cout << "♦ Erreur: " << e.what() << endl;
    }
}

/**
 * Teste l'accesseur à un bateau de l'armada à l'aide d'un index.
 */
void testGetBateau() {
    cout << "\n== testGetBateau ==" << endl;

    CArmada armada;
    CBateau bateau1("croiseur", pair<int, int>(2, 2), 4);
    CBateau bateau2("torpilleur", pair<int, int>(1, 1), 1);
    CBateau bateau3("porte-avion", pair<int, int>(5, 5), 5);
    armada.ajouterBateau(bateau1);
    armada.ajouterBateau(bateau2);
    armada.ajouterBateau(bateau3);

    /* Cas NORMAL */

    cout << "\nBateau i=0 :\n" << *armada.getBateau(0) << endl;
    cout << "Bateau i=1 :\n" << *armada.getBateau(1) << endl;
    cout << "Bateau i=2 :\n" << *armada.getBateau(2) << endl;

    /* Cas ERREUR */

    cout << "\nCas d'erreur :" << endl;
    try {
        // Index égal à la taille de l'armada
        cout << "Bateau i=3 :\n" << *armada.getBateau(3) << endl;
    } catch (range_error e) {
        cout << "♦ Erreur: " << e.what() << endl;
    }

    try {
        // Index négatif
        cout << "Bateau i=-1 :\n" << *armada.getBateau(-1) << endl;
    } catch (range_error e) {
        cout << "♦ Erreur: " << e.what() << endl;
    }
}

/**
 * Teste la récupération de l'effectif total de l'armada.
 */
void testGetEffectifTotal() {
    cout << "\n== testGetEffectifTotal ==" << endl;

    CArmada armada;
    CBateau bateau1("croiseur", pair<int, int>(2, 2), 4);
    CBateau bateau2("torpilleur", pair<int, int>(1, 1), 1);
    CBateau bateau3("porte-avion", pair<int, int>(5, 5), 5);

    /* Cas NORMAL */

    armada.ajouterBateau(bateau1);
    cout << "\nAjout bateau 1. Effectif total : " << armada.getEffectifTotal() << endl; 

    armada.ajouterBateau(bateau2);
    cout << "Ajout bateau 2. Effectif total : " << armada.getEffectifTotal() << endl; 

    armada.ajouterBateau(bateau3);
    cout << "Ajout bateau 3. Effectif total : " << armada.getEffectifTotal() << endl;

    /* Cas LIMITE */

    // Ajout d'un bateau déjà ajouté
    cout << "\nCas limite :" << endl;
    armada.ajouterBateau(bateau1);
    cout << "Ajout bateau 1. Effectif total : " << armada.getEffectifTotal() << endl;
}

/**
 * Teste le comptage de cases occupées par l'armada.
 */
void testGetNbreTotCases() {
    cout << "\n== testGetNbreTotCases ==" << endl;

    CArmada armada;
    CBateau bateau1("croiseur", pair<int, int>(2, 2), 4);
    CBateau bateau2("torpilleur", pair<int, int>(1, 1), 1);
    CBateau bateau3("porte-avion", pair<int, int>(5, 5), 5);

    cout << "\nBateau 1:\n" << bateau1 << endl;
    cout << "Bateau 2:\n" << bateau2 << endl;
    cout << "Bateau 3:\n" << bateau3 << endl;

    /* Cas NORMAL */

    armada.ajouterBateau(bateau1);
    cout << "\nAjout bateau 1. Nb cases occupées par l'armada : " << armada.getNbreTotCases() << endl; 

    armada.ajouterBateau(bateau2);
    cout << "Ajout bateau 2. Nb cases occupées par l'armada : " << armada.getNbreTotCases() << endl;

    armada.ajouterBateau(bateau3);
    cout << "Ajout bateau 3. Nb cases occupées par l'armada : " << armada.getNbreTotCases() << endl;
}

/**
 * Teste la récupération de l'effectif des bateaux encore sur l'eau.
 */
void testGetEffectif() {
    cout << "\n== testGetEffectif ==" << endl;

    CArmada armada;
    CBateau bateau1("croiseur", pair<int, int>(2, 2), 4);
    CBateau bateau2("torpilleur", pair<int, int>(1, 1), 1);

    /* Cas NORMAL */

    armada.ajouterBateau(bateau1);
    cout << "\nAjout bateau 1. Effectif : " << armada.getEffectif() << endl; 

    armada.ajouterBateau(bateau2);
    cout << "Ajout bateau 2. Effectif : " << armada.getEffectif() << endl;
}

/**
 * Teste le remplissage de l'armada à partir d'un fichier.
 */
void testGetArmadaFromFile() {
    cout << "\n== testGetArmadaFromFile ==" << endl;

    CArmada armada;
    try {
        cout << "\nErreurs maitrisées lors des tentatives de lecture de lignes non conformes :\n" << endl;
        armada.getArmadaFromFile();
    } catch (logic_error e) {
        cout << "♦ Erreur: " << e.what() << endl;
    }

    cout << "\nVoici le contenu du fichier flotille.txt :\n" << endl;
    cout << "porte-avion 2 5" << endl;
    cout << "sous-marin 3 2" << endl;
    cout << "erreurs:" << endl;
    cout << "" << endl;
    cout << "neant 5 0" << endl;
    cout << "voilier 4 1" << endl;
    cout << "torpilleur 1 5" << endl;
    cout << "torpilleur 1 1 1" << endl;
    cout << "torpilleur un 1" << endl;
    cout << "torpilleur 1 un" << endl;
    cout << "torpilleur 1  1" << endl;

    cout << "\nVoici le contenu de l'armada après l'appel à la méthode getArmadaFromFile() :\n" << endl;
    for (int i = 0; i < armada.getEffectifTotal(); i++) {
        cout << "Bateau " << i << ":\n" << *armada.getBateau(i) << endl;
    }

    cout << "\nEffectif total de l'armada : " << armada.getEffectifTotal() << endl;
}

/**
 * Teste le placement aléatoire et automatique des bateaux de l'armada sur la grille.
 */
void testPlacerAleatoirement() {
    cout << "\n== testPlacerAleatoirement ==" << endl;
    cout << "(0 = false, 1 = true)" << endl;

    CArmada armada;
    CBateau bateau1("croiseur", pair<int, int>(0, 0), 4);
    CBateau bateau2("torpilleur", pair<int, int>(0, 0), 1);
    CBateau bateau3("porte-avion", pair<int, int>(0, 0), 5);
    armada.ajouterBateau(bateau1);
    armada.ajouterBateau(bateau2);
    armada.ajouterBateau(bateau3);

    /* Cas NORMAL */

    cout << "\nVoici l'armada avant le placement aléatoire :\n" << endl;
    for (int i = 0; i < armada.getEffectifTotal(); i++) {
        cout << "Bateau " << i << ":\n" << *armada.getBateau(i) << endl;
    }

    // Placement aléatoire 1
    cout << "Placement aléatoire 1 réussi ? " << armada.placerAleatoirement() << endl;

    cout << "Voici l'armada après un premier placement aléatoire :\n" << endl;
    for (int i = 0; i < armada.getEffectifTotal(); i++) {
        cout << "Bateau " << i << ":\n" << *armada.getBateau(i) << endl;
    }

    // Placement aléatoire 2
    cout << "Placement aléatoire 2 réussi ? " << armada.placerAleatoirement() << endl;

    cout << "Voici l'armada après un second placement aléatoire :\n" << endl;
    for (int i = 0; i < armada.getEffectifTotal(); i++) {
        cout << "Bateau " << i << ":\n" << *armada.getBateau(i) << endl;
    }

    /* Cas LIMITE */

    // L'armada est remplie de telle sorte qu'elle ne puisse pas placer correctement les bateaux
    cout << "Cas limite :" << endl;
    CArmada armada2;
    for (int i = 0; i < 50; i++)
        armada2.ajouterBateau(bateau1);
    cout << "Effectif total de l'armada 2 : " << armada2.getEffectifTotal() << endl;

    // Placement aléatoire 3
    cout << "Placement aléatoire de armada2 réussi ? " << armada2.placerAleatoirement() << endl;
}