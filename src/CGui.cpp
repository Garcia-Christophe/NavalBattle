#include "CGui.h"

/**
 * Constructeur de CGui par défaut. Il met les pointeurs à NULL.
 */
CGui::CGui() {

    m_pArmada = NULL;
    m_pCoups = NULL;
}

/**
 * Constructeur avec paramètres. Il reçoit un pointeur sur l'armada et un pointeur sur la structure d'enregistrement des tirs.
 * 
 * @param pArmada le pointeur sur l'armada
 * @param pCoups le pointeur sur la structure d'enregistrement des tirs
 */
CGui::CGui(CArmada* pArmada, CCoups* pCoups) {

    setArmadaCoups(pArmada, pCoups);
}

/**
 * Modificateur des pointeurs. Il metà jour le pointeur sur l'armada et le pointeur sur la structure d'enregistrement des tirs.
 * 
 * @param pArmada le pointeur sur l'armada
 * @param pCoups le pointeur sur la structure d'enregistrement des tirs
 *
 * @pre Si les pointeurs ne sont pas NULL
 */
void CGui::setArmadaCoups(CArmada* pArmada, CCoups* pCoups) {

    // pré-condition
    if (pArmada == NULL) {
        logic_error e ("Le pointeur \"pArmada\" ne doit pas être NULL.");
        throw e;
    } else if (pCoups == NULL) {
        logic_error e ("Le pointeur \"pCoups\" ne doit pas être NULL.");
        throw e;
    }

    m_pArmada = pArmada;
    m_pCoups = pCoups;
}

/**
 * Méthode appelée au début du jeu pour positionner tous les bateaux sur la grille en exécutant
 * placerAleatoirement de CArmada.
 * 
 * @return vrai si la placement aléatoire et automatique des bateaux de l'armada est un succès, faux sinon
 */
bool CGui::positionnerBateaux() {

    return m_pArmada->placerAleatoirement();
}

/*
 * Saisie de la coordonnée (ligne, colonne) de l'attaque.
 */
pair<int,int> CGui::choisirAttaque() {

    pair<int,int> p;
    bool validCoord = false;
    int line;
    int column;
    string str;

    cout << "A votre tour d'attaquer Capitaine ! Veuillez saisir les coordonnées du tir." << endl;

    // On vérifie que la coordonnée verticale est bonne (ligne)
    while (!validCoord) {
        cout << "Entrez la ligne (0-" << TAILLE_GRILLE - 2 << ") : ";
        getline(cin, str);

        try {
            bool allDigits = true;
            for (unsigned int i = 0; i < str.length(); i++)
                if (!isdigit(str[i]))
                    allDigits = false;

            if (allDigits) {
                line = stoi(str);

                if (line >= 0 && line <= (TAILLE_GRILLE - 2)) {
                    validCoord = true;
                }
            }
        } catch (exception &err) {
            validCoord = false;
        }
    }

    validCoord = false;

    // On vérifie que la coordonnée horizontale est bonne (colonne)
    while (!validCoord) {
        cout << "Entrez la colonne (0-" << TAILLE_GRILLE - 2 << ") : ";
        getline(cin, str);

        try {
            bool allDigits = true;
            for (unsigned int i = 0; i < str.length(); i++)
                if (!isdigit(str[i]))
                    allDigits = false;

            if (allDigits) {
                column = stoi(str);

                if (column >= 0 && column <= (TAILLE_GRILLE - 2)) {
                    validCoord = true;
                }
            }
        } catch (exception &err) {
            validCoord = false;
        }
    }

    p.first = line;
    p.second = column;

    return p;
}

/**
 * Affiche les félicitations du joueur lorsqu'il gagne la partie.
 */
void CGui::afficheGagne() {

    cout << "|-------------------------------------|" << endl;
    cout << "|           FÉLICITATIONS !           |" << endl;
    cout << "|      Vous avez gagné la partie.     |" << endl;
    cout << "|                                     |" << endl;
    cout << "|  Vous feriez un excellent amiral !  |" << endl;
    cout << "|-------------------------------------|" << endl;
}

/**
 * Affiche les condoléances du joueur lorsqu'il perd la partie.
 */
void CGui::affichePerdu() {

    cout << "|-------------------------------------|" << endl;
    cout << "|              DOMMAGE...             |" << endl;
    cout << "|      Vous avez perdu la partie.     |" << endl;
    cout << "|                                     |" << endl;
    cout << "|   L'important est de participer !   |" << endl;
    cout << "|-------------------------------------|" << endl;
}

/**
 * Remplit la grille du joueur m_grilleJou et la grille de l'adversaire m_grilleAdv.
 * Puis affiche chacune des grilles à l'aide de la méthode afficherLaGrille().
 *
 * @param os la sortie de l'affichage
 */
void CGui::remplirDeuxGrilles(ostream& os) {

    bool isB = false;
    bool isO = false;
    bool isX = false;

    // Remplit la grille du joueur (m_grilleJou)
    for (int i = 0; i < TAILLE_GRILLE - 1; i++) {
        for (int j = 0; j < TAILLE_GRILLE - 1; j++) {
            isO = false;

            for (int k = 0; k < m_pCoups->getTaille("ploufAdverse"); k++) {
                if (m_pCoups->getPair("ploufAdverse", k).first == i && m_pCoups->getPair("ploufAdverse", k).second == j) {
                    isO = true;
                }
            }

            // Si l'adversaire a tiré dans l'eau (O)
            if (isO) {
                m_grilleJou[i][j] = 'O';
            } else {
                isB = false;
                isX = false;

                for (int k = 0; k < m_pArmada->getEffectifTotal(); k++) {
                    for (int l = 0; l < m_pArmada->getBateau(k)->getTaille(); l++) {
                        if (m_pArmada->getBateau(k)->getPosition().first == i && (m_pArmada->getBateau(k)->getPosition().second + l) == j) {
                            if (m_pArmada->getBateau(k)->getDegats(l)) {
                                isX = true;
                            } else {
                                isB = true;
                            }
                        }
                    }
                }

                // Si un bateau de l'armada occupe la case (B)
                if (isB) {
                    m_grilleJou[i][j] = 'B';
                }

                // Si le bateau est touché sur cette position (X)
                else if (isX) {
                    m_grilleJou[i][j] = 'X';
                }

                // Si cette case n'est pas occupée par un bateau et n'a pas été la cible d'un tir adverse (-)
                else {
                    m_grilleJou[i][j] = '-';
                }
            }
        }
    }

    // Affiche la grille du joueur
    afficherLaGrille(os, "joueur");

    // Remplit la grille de l'adversaire (m_grilleAdv)
    for (int i = 0; i < TAILLE_GRILLE - 1; i++) {
        for (int j = 0; j < TAILLE_GRILLE - 1; j++) {
            isO = false;

            for (int k = 0; k < m_pCoups->getTaille("dansLEau"); k++) {
                if (m_pCoups->getPair("dansLEau", k).first == i && m_pCoups->getPair("dansLEau", k).second == j) {
                    isO = true;
                }
            }

            // Si le joueur a tiré dans l'eau (O)
            if (isO) {
                m_grilleAdv[i][j] = 'O';
            } else {
                isX = false;

                for (int k = 0; k < m_pCoups->getTaille("touche"); k++) {
                    if (m_pCoups->getPair("touche", k).first == i && m_pCoups->getPair("touche", k).second == j) {
                        isX = true;
                    }
                }

                // Si le joueur a tiré sur un bateau adverse (X)
                if (isX) {
                    m_grilleAdv[i][j] = 'X';
                }
                
                // Si cette case n'a pas été la cible d'un tir du joueur (-)
                else {
                    m_grilleAdv[i][j] = '-';
                }
            }
        }
    }

    // Affiche la grille de l'adversaire, du point de vue du joueur
    afficherLaGrille(os, "adversaire");
}

/**
 * Affiche la grille (du joueur ou de l'adversaire) à l'écran (contenu et légendes).
 *
 * @param os la sortie de l'affichage
 * @param jouOuAdv "joueur" si c'est le joueur, "adversaire" si c'est l'adversaire
 *
 * @pre Si le paramètre "jouOuAdv" correspond bien à "joueur" ou "adversaire"
 */
void CGui::afficherLaGrille(ostream& os, string jouOuAdv) {

    // pré-condition
    if (jouOuAdv != "joueur" && jouOuAdv != "adversaire") {
        logic_error e ("Pour afficher une grille, il faut préciser le nom : \"joueur\" ou \"adversaire\".");
        throw e;
    }

    // Regarde quelle grille doit être affichée : celle du joueur ou celle de l'adversaire
    if (jouOuAdv == "joueur") {

        // Description de la grille
        os << "\nVotre grille :\n" << endl;

        // Affichage de la première ligne (légende horizontale)
        os << " ";
        for (int i = 0; i < TAILLE_GRILLE - 1; i++) {
            os << "   " << i;
        }
        os << "\n" << endl;

        // Affichage du contenu et de la légende verticale
        for (int i = 0; i < TAILLE_GRILLE - 1; i++) {
            os << i;
            for (int j = 0; j < TAILLE_GRILLE - 1; j++) {
                os << "   " << m_grilleJou[i][j];
            }
            os << "\n" << endl;
        }

        // Légende
        os << "Légende :" << endl;
        os << "   • B : case occupée par un de vos bateaux" << endl;
        os << "   • O : tir manqué par l'adversaire" << endl;
        os << "   • X : votre bateau est touché ou coulé\n" << endl;
    } else {

        // Description de la grille
        os << "La grille adverse :\n" << endl;

        // Affichage de la première ligne (légende horizontale)
        os << " ";
        for (int i = 0; i < TAILLE_GRILLE - 1; i++) {
            os << "   " << i;
        }
        os << "\n" << endl;

        // Affichage du contenu et de la légende verticale
        for (int i = 0; i < TAILLE_GRILLE - 1; i++) {
            os << i;
            for (int j = 0; j < TAILLE_GRILLE - 1; j++) {
                os << "   " << m_grilleAdv[i][j];
            }
            os << "\n" << endl;
        }

        // Légende
        os << "Légende :" << endl;
        os << "   • O : vous n'avez pas touché de bateaux adverses" << endl;
        os << "   • X : vous avez touché un bateau adverse\n" << endl;
    }
}

/**
 * Surcharge de l'opérateur << pour l'affichage des grilles. Cette fonction fait un simple
 * appel à remplirDeuxGrilles(...) de l'objet theG.
 * 
 * @param os la sortie de l'affichage
 * @param theG l'objet CGui
 *
 * @return l'affichage des grilles
 */
ostream& operator<< (ostream& os, CGui& theG) {

    theG.remplirDeuxGrilles(os);

	return os;
}

/**
 * Desctructeur de CGui.
 */
CGui::~CGui() {

    m_pArmada = NULL; // pointe vers NULL
    delete m_pArmada; // mémoire libérée
    m_pCoups = NULL;
    delete m_pCoups;
}
