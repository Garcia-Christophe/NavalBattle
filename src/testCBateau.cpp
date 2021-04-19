#include "CBateau.h"

void testConstructeurParDefaut();
void testConstructeur();
void testCopyConstructeur();
void testOperatorEgal();
void testGetDegats();
void testGetNom();
void testGetTaille();
void testAccesseursPosition();
void testEstCoule();
void testTirAdverse();
void testOperatorAff();

/**
 * Le main permet d'appeler toutes les méthodes de tests de la classe CBateau.
 */
int main () {
    cout << "\n*** TestCBateau ***" << endl;

    testConstructeurParDefaut();
    testConstructeur();
    testCopyConstructeur();
    testOperatorEgal();
    testGetDegats();
    testGetNom();
    testGetTaille();
    testAccesseursPosition();
    testEstCoule();
    testTirAdverse();
	testOperatorAff();

    cout << "*** fin de TestCBateau ***\n" << endl;

    return 0;
}

/**
 * Teste le constructeur par défaut.
 */
void testConstructeurParDefaut() {
    cout << "\n== testConstructeurParDefaut ==" << endl;
    cout << "Le constructeur par défaut doit initialiser le nom à \"neant\", la taille et les positions à 0 :" << endl;

    CBateau bateau1;
    cout << "Nom : " << bateau1.getNom() << endl;
    cout << "Taille : " << bateau1.getTaille() << endl;
    cout << "Point d'encrage : i=" << bateau1.getPosition().first << ", j=" << bateau1.getPosition().second << endl;
}

/**
 * Teste le constructeur avec paramètres.
 */
void testConstructeur() {
    cout << "\n== testConstructeur ==" << endl;

    /* Cas NORMAL */

    cout << "\nbateau1:" << endl;
    pair<int,int> p1;
    p1.first = 1;
    p1.second = 4;
    CBateau bateau1("porte-avion", p1, 5);
    cout << "Nom : " << bateau1.getNom() << endl;
    cout << "Taille : " << bateau1.getTaille() << endl;
    cout << "Point d'encrage : i=" << bateau1.getPosition().first << ", j=" << bateau1.getPosition().second << endl;

    /* Cas ERREUR */

    cout << "\nCas d'erreur :" << endl;
    try {
        // La taille est égale à 0
        cout << "\nbateau2:" << endl;
        pair<int,int> p2;
        p2.first = 0;
        p2.second = 0;
        CBateau bateau2("porte-avion", p2, 0);
        cout << "Nom : " << bateau2.getNom() << endl;
        cout << "Taille : " << bateau2.getTaille() << endl;
        cout << "Point d'encrage : i=" << bateau2.getPosition().first << ", j=" << bateau2.getPosition().second << endl;
    } catch (range_error e) {
        cout << "♦ Erreur: " << e.what() << endl;
    }

    try {
        // La taille est trop grande
        cout << "\nbateau3:" << endl;
        pair<int,int> p3;
        p3.first = 0;
        p3.second = 7;
        CBateau bateau3("", p3, 4);
        cout << "Nom : " << bateau3.getNom() << endl;
        cout << "Taille : " << bateau3.getTaille() << endl;
        cout << "Point d'encrage : i=" << bateau3.getPosition().first << ", j=" << bateau3.getPosition().second << endl;
    } catch (range_error e) {
        cout << "♦ Erreur: " << e.what() << endl;
    }

    try {
        // Le nom est vide ("")
        cout << "\nbateau4:" << endl;
        pair<int,int> p4;
        p4.first = 0;
        p4.second = 0;
        CBateau bateau4("", p4, 1);
        cout << "Nom : " << bateau4.getNom() << endl;
        cout << "Taille : " << bateau4.getTaille() << endl;
        cout << "Point d'encrage : i=" << bateau4.getPosition().first << ", j=" << bateau4.getPosition().second << endl;
    } catch (logic_error e) {
        cout << "♦ Erreur: " << e.what() << endl;
    }

    try {
        // Le nom est un nom inconnu (porte-avion ne prend pas de "s")
        cout << "\nbateau5:" << endl;
        pair<int,int> p5;
        p5.first = 0;
        p5.second = 0;
        CBateau bateau5("porte-avions", p5, 5);
        cout << "Nom : " << bateau5.getNom() << endl;
        cout << "Taille : " << bateau5.getTaille() << endl;
        cout << "Point d'encrage : i=" << bateau5.getPosition().first << ", j=" << bateau5.getPosition().second << endl;
    } catch (logic_error e) {
        cout << "♦ Erreur: " << e.what() << endl;
    }

    try {
        // Le nom est connu, la taille entre 1 et 5 mais ne correspond pas au bon nom
        cout << "\nbateau6:" << endl;
        pair<int,int> p6;
        p6.first = 0;
        p6.second = 0;
        CBateau bateau6("porte-avion", p6, 1);
        cout << "Nom : " << bateau6.getNom() << endl;
        cout << "Taille : " << bateau6.getTaille() << endl;
        cout << "Point d'encrage : i=" << bateau6.getPosition().first << ", j=" << bateau6.getPosition().second << endl;
    } catch (logic_error e) {
        cout << "♦ Erreur: " << e.what() << endl;
    }

    try {
        // La taille est négative (-1)
        cout << "\nbateau7:" << endl;
        pair<int,int> p7;
        p7.first = 0;
        p7.second = 0;
        CBateau bateau7("porte-avion", p7, -1);
        cout << "Nom : " << bateau7.getNom() << endl;
        cout << "Taille : " << bateau7.getTaille() << endl;
        cout << "Point d'encrage : i=" << bateau7.getPosition().first << ", j=" << bateau7.getPosition().second << endl;
    } catch (range_error e) {
        cout << "♦ Erreur: " << e.what() << endl;
    }
}

/**
 * Teste le copy-constructeur.
 */
void testCopyConstructeur() {
    cout << "\n== testCopyConstructeur ==" << endl;

    /* Cas NORMAL */

    // Copie d'un bateau créé par le consructeur sans paramètre.
    CBateau bateau1;
    cout << "\nBateau 1 :\n" << bateau1 << endl;
    CBateau bateau11(bateau1);
    cout << "Bateau 11 :\n" << bateau11 << endl;

    // Copie d'un bateau créé par le consructeur avec paramètres.
    pair<int,int> p;
    p.first = 1;
    p.second = 1;
    CBateau bateau2("croiseur", p, 4);
    cout << "Bateau 2 :\n" << bateau2 << endl;
    CBateau bateau22(bateau2);
    cout << "Bateau 22 :\n" << bateau22 << endl;

    /* Cas LIMITE */

    // On change les valeurs du bateau 22
    cout << "Cas limite:" << endl;
    bateau22.setPosition(0, 0);
    cout << "\nBateau 2 :\n" << bateau2 << endl;
    cout << "Bateau 22 :\n" << bateau22 << endl;
}

/**
 * Teste la redéfinition de l'opérateur =.
 */
void testOperatorEgal() {
    cout << "\n== testOperatorEgal ==" << endl;

    // Copie d'un bateau créé par le consructeur sans paramètre.
    CBateau bateau1;
    cout << "\nBateau 1 :\n" << bateau1 << endl;
    CBateau bateau11 = bateau1;
    cout << "Bateau 11 :\n" << bateau11 << endl;

    // Copie d'un bateau créé par le consructeur avec paramètres.
    pair<int,int> p;
    p.first = 1;
    p.second = 1;
    CBateau bateau2("croiseur", p, 4);
    cout << "Bateau 2 :\n" << bateau2 << endl;
    CBateau bateau22 = bateau2;
    cout << "Bateau 22 :\n" << bateau22 << endl;

    /* Cas LIMITE */

    // On change les valeurs du bateau 22
    cout << "Cas limite:" << endl;
    bateau22.setPosition(0, 0);
    cout << "\nBateau 2 :\n" << bateau2 << endl;
    cout << "Bateau 22 :\n" << bateau22 << endl;
}

/**
 * Teste l'accesseur au tableau de degats du bateau.
 */
void testGetDegats() {
    cout << "\n== testGetDegats ==" << endl;
    cout << "(0 = false, 1 = true)" << endl;

    /* Cas NORMAL */

    cout << "\nAucun tir effectué :" << endl;
    pair<int,int> p;
    p.first = 1;
    p.second = 4;
    CBateau bateau("sous-marin", p, 2);
    cout << "Degat i=0 :" << bateau.getDegats(0) << endl;
    cout << "Degat i=1 :" << bateau.getDegats(1) << endl;

    // Tir adverse 1 : réussi
    cout << "\nTir adverse 1 : réussi (1,5) :" << endl;
    pair<int,int> tir;
    tir.first = 1;
    tir.second = 5;
    bateau.tirAdverse(tir);
    cout << "Degat i=0 :" << bateau.getDegats(0) << endl;
    cout << "Degat i=1 :" << bateau.getDegats(1) << endl;

    // Tir adverse 2 : raté
    cout << "\nTir adverse 2 : raté (1,3) :" << endl;
    pair<int,int> tir2;
    tir2.first = 1;
    tir2.second = 3;
    bateau.tirAdverse(tir2);
    cout << "Degat i=0 :" << bateau.getDegats(0) << endl;
    cout << "Degat i=1 :" << bateau.getDegats(1) << endl;

    // Tir adverse 3 : réussi
    cout << "\nTir adverse 3 : réussi (1,4) :" << endl;
    pair<int,int> tir3;
    tir3.first = 1;
    tir3.second = 4;
    bateau.tirAdverse(tir3);
    cout << "Degat i=0 :" << bateau.getDegats(0) << endl;
    cout << "Degat i=1 :" << bateau.getDegats(1) << endl;

    /* Cas ERREUR */

    cout << "\nCas d'erreur :" << endl;
    try {
        // Index égal à la taille du bateau
        cout << "Degat i=2 :\n" << bateau.getDegats(2) << endl;
    } catch (out_of_range e) {
        cout << "♦ Erreur: " << e.what() << endl;
    }

    try {
        // Index négatif
        cout << "Degat i=-1 :\n" << bateau.getDegats(-1) << endl;
    } catch (out_of_range e) {
        cout << "♦ Erreur: " << e.what() << endl;
    }

    try {
        // Bateau "neant"
        CBateau bateau2;
        cout << "(Bateau \"neant\") Degat i=0 :\n" << bateau2.getDegats(0) << endl;
    } catch (logic_error e) {
        cout << "♦ Erreur: " << e.what() << endl;
    }
}

/**
 * Teste l'accesseur au nom du bateau.
 */
void testGetNom() {
    cout << "\n== testGetNom ==" << endl;

    // Constructeur sans paramètres
    CBateau bateau1;
    cout << "\nBateau 1 > Nom : " << bateau1.getNom() << endl;

    // Constructeur avec paramètres
    pair<int,int> p;
    p.first = 1;
    p.second = 4;
    CBateau bateau2("torpilleur", p, 1);
    cout << "Bateau 2 > Nom : " << bateau2.getNom() << endl;
}

/**
 * Teste l'accesseur à la taille du bateau.
 */
void testGetTaille() {
    cout << "\n== testGetTaille ==" << endl;

    // Constructeur sans paramètres
    CBateau bateau1;
    cout << "\nBateau 1 > Taille : " << bateau1.getTaille() << endl;

    // Constructeur avec paramètres
    pair<int,int> p;
    p.first = 1;
    p.second = 4;
    CBateau bateau2("contre-torpilleur", p, 3);
    cout << "Bateau 2 > Taille : " << bateau2.getTaille() << endl;
}

/**
 * Teste les accesseurs à la position d'encrage du bateau.
 */
void testAccesseursPosition() {
    cout << "\n== testAccesseursPosition ==" << endl;

    /* Cas NORMAL */

    // Constructeur sans paramètres
    CBateau bateau1;
    cout << "\nBateau 1 > Point d'encrage : i=" << bateau1.getPosition().first << ", j=" << bateau1.getPosition().second << endl;

    // Modification de la position
    bateau1.setPosition(1, 1);
    cout << "Bateau 1 > Point d'encrage modifié (1,1) : i=" << bateau1.getPosition().first << ", j=" << bateau1.getPosition().second << endl;

    // Constructeur avec paramètres
    pair<int,int> p;
    p.first = 1;
    p.second = 4;
    CBateau bateau2("croiseur", p, 4);
    cout << "Bateau 2 > Point d'encrage : i=" << bateau2.getPosition().first << ", j=" << bateau2.getPosition().second << endl;

    // Modification de la position
    bateau2.setPosition(5, 5);
    cout << "Bateau 2 > Point d'encrage modifié (5,5) : i=" << bateau1.getPosition().first << ", j=" << bateau1.getPosition().second << endl;


    /* Cas ERREUR */

    cout << "\nCas d'erreur :" << endl;
    try {
        // i < 0
        bateau2.setPosition(-1, 8);
    } catch (out_of_range e) {
        cout << "♦ Erreur: " << e.what() << endl;
    }

    try {
        // i > TAILLE_GRILLE - 2
        bateau2.setPosition(10, 8);
    } catch (out_of_range e) {
        cout << "♦ Erreur: " << e.what() << endl;
    }

    try {
        // j < 0
        bateau2.setPosition(8, -1);
    } catch (out_of_range e) {
        cout << "♦ Erreur: " << e.what() << endl;
    }

    try {
        // j > TAILLE_GRILLE - 2
        bateau2.setPosition(8, 10);
    } catch (out_of_range e) {
        cout << "♦ Erreur: " << e.what() << endl;
    }

    try {
        // Les positions sont bonnes mais le bateau dépasse maintenant de la grille
        bateau2.setPosition(8, 7);
    } catch (out_of_range e) {
        cout << "♦ Erreur: " << e.what() << endl;
    }
}

/**
 * Teste si le bateau est coulé.
 */
void testEstCoule() {
    cout << "\n== testEstCoule ==" << endl;
    cout << "(0 = false, 1 = true)" << endl;

    /* Cas NORMAL */

    // Création du bateau
    pair<int,int> p;
    p.first = 1;
    p.second = 1;
    CBateau bateau("sous-marin", p, 2);
    cout << "\nBateau :\n" << bateau << endl;
    cout << "Coulé : " << bateau.estCoule() << endl;

    // Tir adverse 1 : réussi
    cout << "Tir adverse (1,2) : ";
    pair<int,int> tir;
    tir.first = 1;
    tir.second = 2;
    bateau.tirAdverse(tir);
    cout << "Coulé : " << bateau.estCoule() << endl;

    // Tir adverse 2 : raté
    cout << "Tir adverse (1,3) : ";
    pair<int,int> tir2;
    tir2.first = 1;
    tir2.second = 3;
    bateau.tirAdverse(tir2);
    cout << "Coulé : " << bateau.estCoule() << endl;

    // Tir adverse 3 : réussi
    cout << "Tir adverse (1,1) : ";
    pair<int,int> tir3;
    tir3.first = 1;
    tir3.second = 1;
    bateau.tirAdverse(tir3);
    cout << "Coulé : " << bateau.estCoule() << endl;
}

/**
 * Teste si le tir adverse est une réussite ou non.
 */
void testTirAdverse() {
    cout << "\n== testTirAdverse ==" << endl;
    cout << "(0 = false, 1 = true)" << endl;

    /* Cas NORMAL */

    // Création du bateau
    pair<int,int> p;
    p.first = 1;
    p.second = 1;
    CBateau bateau("sous-marin", p, 2);
    cout << "\nBateau :\n" << bateau << endl;

    // Tir adverse 1 : réussi
    cout << "Tir adverse (1,2) : ";
    pair<int,int> tir;
    tir.first = 1;
    tir.second = 2;
    cout << bateau.tirAdverse(tir) << endl;

    // Tir adverse 2 : raté
    cout << "Tir adverse (1,3) : ";
    pair<int,int> tir2;
    tir2.first = 1;
    tir2.second = 3;
    cout << bateau.tirAdverse(tir2) << endl;

    // Tir adverse 3 : réussi
    cout << "Tir adverse (1,1) : ";
    pair<int,int> tir3;
    tir3.first = 1;
    tir3.second = 1;
    cout << bateau.tirAdverse(tir3) << endl;

    /* Cas LIMITE */

    // On tire sur une partie déjà touchée d'un bateau non coulé
    cout << "\nCas limite :" << endl;
    cout << "Tir adverse (1,2) : ";
    pair<int,int> tir4;
    tir4.first = 1;
    tir4.second = 2;
    cout << bateau.tirAdverse(tir4) << endl;
}

/**
 * Teste la méthode d'affichage du bateau avec les 2 constructeurs possibles.
 */
void testOperatorAff() {
    cout << "\n== testOperatorAff ==" << endl;

    // Bateau sans paramètres
    cout << "\nBateau1:" << endl;
    CBateau bateau1;
    cout << bateau1 << endl;

    // Bateau avec paramètres
    cout << "Bateau2:" << endl;
    pair<int,int> p;
    p.first = 1;
    p.second = 4;
    CBateau bateau2("croiseur", p, 4);
    cout << bateau2 << endl;

    // Tir adverse sur le bateau2 (réussi)
    cout << "Bateau2 (après tir en 1,6):" << endl;
    pair<int,int> tir;
    tir.first = 1;
    tir.second = 6;
    bateau2.tirAdverse(tir);
    cout << bateau2 << endl;
}
