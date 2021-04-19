#include "CGui.h"

void testConstructeurs();
void testSetterArmadaCoups();
void testPositionnerBateaux();
void testChoisirAttaque();
void testAfficheGagne();
void testAffichePerdu();
void testOperateurAff();

/**
 * Le main permet d'appeler toutes les méthodes de tests de la classe CGui.
 */
int main () {
    cout << "\n*** TestCGui ***" << endl;

    testConstructeurs();
    testSetterArmadaCoups();
    testPositionnerBateaux();
    testChoisirAttaque();
    testAfficheGagne();
    testAffichePerdu();
    testOperateurAff();

    cout << "\n*** fin de TestCGui ***\n" << endl;

    return 0;
}

/**
 * Teste le constructeur les constructeurs.
 */
void testConstructeurs() {
    cout << "\n== testConstructeurs ==\n" << endl;

    /* Cas NORMAL */

    try {
        CGui gui;
        cout << "CGui gui : ok" << endl;
    } catch (logic_error e) {
        cout << "CGui gui :\n" << "♦ Erreur: " << e.what() << endl;
    }

    try {
        // Avec des pointeurs != NULL
        CArmada* pArmada = new CArmada();
        CCoups* pCoups = new CCoups();

        CGui gui(pArmada, pCoups);
        cout << "CGui gui(pArmada, pCoups) : ok" << endl;
    } catch (logic_error e) {
        cout << "CGui gui(pArmada, pCoups) :\n" << "♦ Erreur: " << e.what() << endl;
    }

    /* Cas ERREUR */

    cout << "\nCas d'erreur :" << endl;
    try {
        // Pointeur sur l'armada == NULL
        CCoups* pCoups = new CCoups();

        CGui gui(NULL, pCoups);
        cout << "CGui gui(NULL, pCoups) : ok" << endl;
    } catch (logic_error e) {
        cout << "CGui gui(NULL, pCoups) :\n" << "♦ Erreur: " << e.what() << endl;
    }

    try {
        // Pointeur sur l'unique structure d'enregistrement des tirs == NULL
        CArmada* pArmada = new CArmada();

        CGui gui(pArmada, NULL);
        cout << "\nCGui gui(pArmada, NULL) : ok" << endl;
    } catch (logic_error e) {
        cout << "\nCGui gui(pArmada, NULL) :\n" << "♦ Erreur: " << e.what() << endl;
    }
}

/**
 * Teste le setter des pointeurs (celui sur l'armada et celui sur la structure d'enregistrement des tirs).
 */
void testSetterArmadaCoups() {
    cout << "\n== testSetterArmadaCoups ==\n" << endl;

    /* Cas NORMAL */

    try {
        // Avec des pointeurs != NULL
        CArmada* pArmada = new CArmada();
        CCoups* pCoups = new CCoups();

        CGui gui;
        gui.setArmadaCoups(pArmada, pCoups);
        cout << "CGui gui, setArmadaCoups(pArmada, pCoups) : ok" << endl;
    } catch (logic_error e) {
        cout << "CGui gui, setArmadaCoups(pArmada, pCoups) :\n" << "♦ Erreur: " << e.what() << endl;
    }

    /* Cas ERREUR */

    cout << "\nCas d'erreur :" << endl;
    try {
        // Pointeur sur l'armada == NULL
        CCoups* pCoups = new CCoups();

        CGui gui;
        gui.setArmadaCoups(NULL, pCoups);
        cout << "CGui gui, setArmadaCoups(NULL, pCoups) : ok" << endl;
    } catch (logic_error e) {
        cout << "CGui gui, setArmadaCoups(NULL, pCoups) :\n" << "♦ Erreur: " << e.what() << endl;
    }

    try {
        // Pointeur sur l'unique structure d'enregistrement des tirs == NULL
        CArmada* pArmada = new CArmada();

        CGui gui;
        gui.setArmadaCoups(pArmada, NULL);
        cout << "\nCGui gui, setArmadaCoups(pArmada, NULL) : ok" << endl;
    } catch (logic_error e) {
        cout << "\nCGui gui, setArmadaCoups(pArmada, NULL) :\n" << "♦ Erreur: " << e.what() << endl;
    }
}

/**
 * Teste le positionnement des bateaux.
 */
void testPositionnerBateaux() {
    cout << "\n== testPositionnerBateaux ==" << endl;
    cout << "(0 = false, 1 = true)\n" << endl;

    CGui gui;
    CArmada armada;
    CBateau bateau1("croiseur", pair<int, int>(0, 0), 4);
    CBateau bateau2("torpilleur", pair<int, int>(0, 0), 1);
    CBateau bateau3("porte-avion", pair<int, int>(0, 0), 5);
    armada.ajouterBateau(bateau1);
    armada.ajouterBateau(bateau2);
    armada.ajouterBateau(bateau3);
    CArmada* pArmada = &armada;
    CCoups* pCoups = new CCoups();
    gui.setArmadaCoups(pArmada, pCoups);

    /* Cas NORMAL */

    cout << "Voici l'armada avant le positionnement des bateaux :\n" << endl;
    for (int i = 0; i < armada.getEffectifTotal(); i++) {
        cout << "Bateau " << i << ":\n" << *armada.getBateau(i) << endl;
    }

    // Positionnement des bateaux 1
    cout << "Positionnement des bateaux 1 réussi ? " << gui.positionnerBateaux() << endl;

    cout << "Voici l'armada après un premier positionnement des bateaux :\n" << endl;
    for (int i = 0; i < armada.getEffectifTotal(); i++) {
        cout << "Bateau " << i << ":\n" << *armada.getBateau(i) << endl;
    }

    // Positionnement des bateaux 2
    cout << "Positionnement des bateaux 2 réussi ? " << gui.positionnerBateaux() << endl;

    cout << "Voici l'armada après un second positionnement des bateaux :\n" << endl;
    for (int i = 0; i < armada.getEffectifTotal(); i++) {
        cout << "Bateau " << i << ":\n" << *armada.getBateau(i) << endl;
    }

    /* Cas LIMITE */

    // L'armada est remplie de telle sorte qu'elle ne puisse pas placer correctement les bateaux
    cout << "Cas limite :" << endl;
    CArmada armada2;
    for (int i = 0; i < 50; i++)
        armada2.ajouterBateau(bateau1);
    pArmada = &armada2;
    gui.setArmadaCoups(pArmada, pCoups);
    cout << "Effectif total de l'armada : " << armada2.getEffectifTotal() << endl;

    // Positionnement des bateaux 3
    cout << "Positionnement des bateaux 3 réussi ? " << gui.positionnerBateaux() << endl;
}

/**
 * Teste la saisie des coordonnées du prochain tir du joueur.
 */
void testChoisirAttaque() {
    cout << "\n== testChoisirAttaque ==\n" << endl;

    cout << "La méthode va être lancée, les tests peuvent être les suivants :" << endl;
    cout << "- erreur : rentrer une lettre" << endl;
    cout << "- erreur : rentrer un nombre négatif" << endl;
    cout << "- erreur : rentrer un chiffre supérieur à (TAILLE_GRILLE - 2)" << endl;
    cout << "- erreur : rentrer un espace" << endl;
    cout << "- erreur : rentrer rien (retour chariot)" << endl;
    cout << "- erreur : rentrer 2 chiffres séparés d'un espace" << endl;
    cout << "- limites: rentrer 0 puis 9 (00 et 00009 fonctionnent)\n" << endl;

    CGui gui;
    pair<int, int> p = gui.choisirAttaque();

    cout << "\nAffichage des coordonnées : (" << p.first << "," << p.second << ")" << endl;
}

/**
 * Teste l'affichage du message lorsque le joueur a gagné.
 */
void testAfficheGagne() {
    cout << "\n== testAfficheGagne ==\n" << endl;

    CGui gui;
    gui.afficheGagne();
}

/**
 * Teste l'affichage du message lorsque le joueur a perdu.
 */
void testAffichePerdu() {
    cout << "\n== testAffichePerdu ==\n" << endl;

    CGui gui;
    gui.affichePerdu();
}

/**
 * Teste la méthode d'affichage des grilles avec les 2 constructeurs possibles.
 */
void testOperateurAff() {
    cout << "\n== testOperateurAff ==\n" << endl;

    // Armada vide
    cout << "-> Armada vide :" << endl;
    CArmada* pArmada = new CArmada();
    CCoups* pCoups = new CCoups();

    CGui gui(pArmada, pCoups);
    cout << gui << endl;

    // Armada non vide + quelques tirs
    cout << "-> Armada non vide + quelques tirs :" << endl;
    CArmada armada;
    CBateau bateau1("croiseur", pair<int, int>(3, 3), 4);
    CBateau bateau2("torpilleur", pair<int, int>(6, 5), 1);
    CBateau bateau3("porte-avion", pair<int, int>(5, 5), 5);
    bateau1.tirAdverse(pair<int, int>(3, 4));
    armada.ajouterBateau(bateau1);
    armada.ajouterBateau(bateau2);
    armada.ajouterBateau(bateau3);

    // Ajout de quelques faux tirs dans l'unique structure d'enregistrement des tirs
    CCoups coups;

    // Tirs : sur la grille adverses
    coups.ajouterTirMap("touche", *(new pair<int, int>(2, 2)));
    coups.ajouterTirMap("touche", *(new pair<int, int>(7, 4)));
    coups.ajouterTirMap("touche", *(new pair<int, int>(8, 8)));
    coups.ajouterTirMap("dansLEau", *(new pair<int, int>(1, 5)));
    coups.ajouterTirMap("dansLEau", *(new pair<int, int>(4, 7)));
    coups.ajouterTirMap("dansLEau", *(new pair<int, int>(9, 3)));
    coups.ajouterTirMap("dansLEau", *(new pair<int, int>(5, 6)));

    // Tirs : sur la grille du joueur
    coups.ajouterTirMap("ploufAdverse", *(new pair<int, int>(5, 1)));
    coups.ajouterTirMap("ploufAdverse", *(new pair<int, int>(4, 7)));
    coups.ajouterTirMap("ploufAdverse", *(new pair<int, int>(1, 5)));
    coups.ajouterTirMap("ploufAdverse", *(new pair<int, int>(8, 6)));

    CArmada* pArmada2 = &armada;
    CCoups* pCoups2 = &coups;

    CGui gui2(pArmada2, pCoups2);
    cout << gui2 << endl;
}
