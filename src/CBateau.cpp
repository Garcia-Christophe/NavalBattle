#include "CBateau.h"

/**
 * Constructeur de CBateau par défaut. Il initialise le nom du bateau à "néant", sa taille et ses 
 * positions à 0, et son tableau de dégâts à NULL.
 */
CBateau::CBateau() {

    m_nom = "neant";
    m_taille = 0;
    m_position.first = 0;
    m_position.second = 0;
    m_pDegats = NULL;
}

/**
 * Constructeur de CBateau avec paramètres. Ces paramètres perttent d'initialiser le bateau en lui donnant
 * son nom, sa taille et ses positions. Son tableau de dégâts est rempli de valeurs booléennes "false".
 * 
 * @param n le nom du bateau
 * @param p les positions du bateau
 * @param t la taille du bateau
 *
 * @pre Si la taille passée en paramètre est positive, si le nom (non null) correspond à un nom connu et si
 * la taille correspond au nom du bateau
 */
CBateau::CBateau(string n, pair<int,int> p, int t) {

    // Pré-condition
    if (t <= 0) {
        range_error e ("Taille incorrecte pour un bateau.");
        throw e;
    } else if (p.second + t - 1 > TAILLE_GRILLE - 2) {
        range_error e ("La taille du bateau est trop grande.");
        throw e;
    } else if (n != "porte-avion" && n != "croiseur" && n != "contre-torpilleur" && n != "sous-marin" && n != "torpilleur") {
        logic_error e ("Le bateau doit avoir un nom connu (porte-avion, croiseur, contre-torpilleur, sous-marin, torpilleur).");
        throw e;
    } else if ((n == "porte-avion" && t != 5) || (n == "croiseur" && t != 4) || (n == "contre-torpilleur" && t != 3) || (n == "sous-marin" && t != 2) || (n == "torpilleur" && t != 1)) {
        logic_error e ("La taille du bateau doit correspondre au nom (porte-avion : 5, croiseur : 4, contre-torpilleur : 3, sous-marin : 2, torpilleur : 1).");
        throw e;
    }

    m_nom = n;
    m_taille = t;
    m_pDegats = new bool[m_taille];
    setPosition(p.first, p.second);
    for (int i = 0; i < m_taille; i++) {
        m_pDegats[i] = false;
    }
}

/**
 * Le copy-constructeur copie profondément le bateau passé en paramètre.
 *
 * @param theB le bateau à copier
 */
CBateau::CBateau(const CBateau& theB) {
    
    m_nom = theB.m_nom;
    m_taille = theB.m_taille;
    m_pDegats = new bool[m_taille];
    setPosition(theB.m_position.first, theB.m_position.second);
    for (int i = 0; i < theB.m_taille; i++) {
        m_pDegats[i] = theB.m_pDegats[i];
    }
}

/**
 * Redéfinit l'opérateur =.
 * 
 * @param theB le bateau qui récupère les valeurs de ce bateau
 *
 * @return la bateau avec les nouvelles données
 */
CBateau CBateau::operator= (CBateau& theB) {

    theB.m_nom = m_nom;
    theB.m_taille = m_taille;
    theB.m_pDegats = m_pDegats;
    theB.setPosition(m_position.first, m_position.second);

    return theB;
}

/**
 * Retourne l'état de la partie du bateau correspondant à l'index passé en paramètre. "true" signifie que
 * partie a été touchée par l'ennemi, "false" signifie qu'elle est toujours intacte.
 * 
 * @param i la position d'une partie du bateau
 *
 * @pre Si le paramètre est positif et inférieur à la taille du bateau
 *
 * @return vrai si la partie du bateau est coulée, faux sinon
 */
bool CBateau::getDegats(int i) {
    
    // Pré-condition
    if (i < 0 || i >= m_taille) {
        out_of_range e ("L'index doit être positif et inférieur à la taille du bateau.");
        throw e;
    }

    bool degats = false;

    // Si le bateau n'est pas le neant
    if (m_taille > 0) {
        degats = m_pDegats[i];
    }

    return degats;
}

/**
 * Retourne le nom du bateau.
 *
 * @return le nom du bateau
 */
string CBateau::getNom() {

    return m_nom;
}

/**
 * Retourne la taille du bateau.
 *
 * @return la taille du bateau
 */
int CBateau::getTaille() {

    return m_taille;
}

/**
 * Retourne les positions du bateau.
 *
 * @return les positions du bateau
 */
pair<int,int> CBateau::getPosition() {

    return m_position;
}

/**
 * Définit les positions du bateau.
 *
 * @param i la ligne du point d'encrage du bateau
 * @param j la colonne du point d'encrage du bateau
 *
 * @pre Si les paramètres rentrent bien dans la grille et que la taille ne fait pas dépasser
 * le nouveau point d'encrage
 */
void CBateau::setPosition(int i, int j) {

    // Pré-condition
    if (i < 0 || i > TAILLE_GRILLE - 2 || j < 0 || j > TAILLE_GRILLE - 2) {
        out_of_range e ("Le bateau dépasse la grille.");
        throw e;
    } else if (j + m_taille - 1 > TAILLE_GRILLE - 2) {
        out_of_range e ("Le nouveau point d'encrage fait dépasser le bateau de la grille.");
        throw e;
    }

    m_position.first = i;
    m_position.second = j;
}

/**
 * Retourne l'état du bateau. "true" signifie que toutes les parties du bateau ont été touchées par
 * l'ennemi, "false" signifie qu'une partie est toujours intacte.
 *
 * @return vrai si le bateau est coulé, faux sinon
 */
bool CBateau::estCoule() {

    bool estCoule = true;
    int i = 0;

    // Le bateau est coulé si toutes ses cases ont été touchées
    while (estCoule && i < m_taille) {
        if (!m_pDegats[i]) {
            estCoule = false;
        }
        
        i++;
    }

    return estCoule;
}

/**
 * Retourne l'état du tir adverse. "true" signifie que l'ennemi vient de toucher une partie du bateau
 * qui était encore restée intacte, "false" signifie que le tir a manqué le bateau.
 * 
 * @param p la position du tir adverse
 *
 * @return vrai si le tir adverse touche le bateau, faux sinon
 */
bool CBateau::tirAdverse(pair<int,int> p) {

    bool tirReussi = false;

    // Si le tir touche une case du bateau
    if (p.first == m_position.first && p.second >= m_position.second && p.second < m_position.second + m_taille) {

        // Si la case n'a pas déjà été touchée
        if (!m_pDegats[p.second - m_position.second]) {
            tirReussi = true;
            m_pDegats[p.second - m_position.second] = true;
        }
    }

    return tirReussi;
}

/**
 * Affiche à l'écran les caractéristiques du bateau.
 * 
 * @param os la sortie de l'affichage
 * @param theB le bateau à afficher
 *
 * @return l'affichage des caractéristiques du bateau
 */
ostream& operator<< (ostream& os, CBateau& theB) {

    os << "Nom : " << theB.m_nom << endl;
    os << "Taille : " << theB.m_taille << endl;

    if (theB.m_taille > 0) {
        os << "Positions : " << endl;
        
        for (int i = 0; i < theB.m_taille; i++) {
            string touchePasTouche;
            if (theB.m_pDegats[i]) {
                touchePasTouche = " : touche";
            } else {
                touchePasTouche = " : pas touche";
            }

            os << "- " << theB.m_position.first << "," << (theB.m_position.second + i) << touchePasTouche << endl;
        }
    }

	return os;
}

/**
 * Desctructeur de CBateau.
 */
CBateau::~CBateau() {

    delete[] m_pDegats;
}

