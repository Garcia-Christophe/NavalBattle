#include "CArmada.h"

/**
 * Constructeur de CArmada par défaut. Il crée le vecteur de CBateau avec une taille égale à 0.
 */
CArmada::CArmada() {

    vector<CBateau> m_listeBateaux(0);
}

/**
 * Ajoute un bateau dans l'armada.
 *
 * @param unBat le bateau à ajouter
 */
void CArmada::ajouterBateau(CBateau& unBat) {

    if (unBat.getTaille() <= 0) {
        logic_error e ("Pour être ajouté dans l'armada, le bateau doit avoir une taille strictement positive.");
        throw e;
    }

    m_listeBateaux.push_back(unBat);
}

/**
 * Retourne le bateau à l'index i du vecteur.
 * 
 * @param i l'index du bateau demandé
 *
 * @pre Si l'indice ne rentre pas dans le vecteur (0 <= i < taille)
 *
 * @return le bateau à l'index i
 */
CBateau* CArmada::getBateau(int i) {

    // Pré-condition
    if (i < 0 || i >= getEffectifTotal()) {
        range_error e ("Il n'existe pas de bateau dans l'armada à cet indice.");
        throw e;
    }

    return &m_listeBateaux.at(i);
}

/**
 * Rtourne le nombre de bateaux de l'armada.
 *
 * @return l'effectif total de l'armada
 */
int CArmada::getEffectifTotal() {

    return m_listeBateaux.size();
}

/**
 * Retourne le nombre de cases occupées par l'armada.
 * 
 * @return la somme des tailles des bateaux de l'armada
 */
int CArmada::getNbreTotCases() {

    int nbTotal = 0;

    // Additionne le nombre de cases occupées par chacun des bateaux de l'armada
    for (CBateau bateau : m_listeBateaux) 
        nbTotal += bateau.getTaille();

    return nbTotal;
}

/**
 * Retourne le nombre de bateaux qui ne sont pas encore coulés (flottille encore en vie sur l'eau).
 * 
 * @return le nombre de bateaux qui ne sont pas encore coulés
 */
int CArmada::getEffectif() {

    int effectif = 0;

    // Compte le nombre de bateaux non-coulés
    for (CBateau bateau : m_listeBateaux)
        if (!bateau.estCoule())
            effectif++;

    return effectif;
}

/**
 * Lis le fichier flotille.txt et remplit l'armada des bateaux présents dans ce fichier.
 * 
 * @pre Si le fichier existe
 */
void CArmada::getArmadaFromFile() {

    ifstream fichier("../ws/flotille.txt");
    
    // Pré-condition
    if (!fichier) {
        logic_error e ("Le fichier \"flotille.txt\" n'a pas été trouvé.");
        throw e;
    }

    string ligne;
        
    // Tant qu'on n'est pas à la fin, on lit la ligne
    while (getline(fichier, ligne)) {
        string segment;
        vector<string> seglist;
        stringstream ss(ligne);
        
        // Divise la ligne grâce aux espaces
        while(getline(ss, segment, ' ')) {
            seglist.push_back(segment);
        }

        // Les valeurs de la ligne
        string nom;
        int nbBateaux;
        int taille;

        // Si la ligne comporte bien 3 champs
        if (seglist.size() == 3) {
            nom = seglist.at(0);

            // Si le nom du bateau est connu
            if (nom == "porte-avion" || nom == "croiseur" || nom == "contre-torpilleur" || nom == "sous-marin" || nom == "torpilleur") {
                bool secondChampOk = true;
                try {
                    nbBateaux = stoi(seglist.at(1));

                    for (unsigned int i = 0; i < seglist.at(1).length(); i++)
                        if (!isdigit(seglist.at(1)[i]))
                            if (nbBateaux >= 0)
                                secondChampOk = false;
                } catch (exception &err) {
                    secondChampOk = false;
                }

                // Si le 2d champ est un entier positif
                if (secondChampOk) {
                    bool troisiemeChampOk = false;
                    try {
                        taille = stoi(seglist.at(2));

                        for (unsigned int i = 0; i < seglist.at(2).length(); i++) {
                            if (isdigit(seglist.at(2)[i])) {
                                if (taille > 0 && taille <= 5) {
                                    troisiemeChampOk = true;
                                }
                            }
                        }
                    } catch (exception &err) {
                        troisiemeChampOk = false;
                    }

                    // Si le 3e champ est un entier entre 1 et 5
                    if (troisiemeChampOk) {

                        // Si la taille du bateau correspond avec ce dernier
                        if ((nom == "porte-avion" && taille == 5) || (nom == "croiseur" && taille == 4) || (nom == "contre-torpilleur" && taille == 3) || (nom == "sous-marin" && taille == 2) || (nom == "torpilleur" && taille == 1)) {
                            
                            // Crée nbBateaux CBateau et les ajoute dans m_listeBateaux
                            for (int i = 0; i < nbBateaux; i++) {

                                // Try/catch pour éviter le plantage du jeu lors d'une exception
                                // Si jamais une exception survient, on peut l'ignorer en ne n'ajoutant pas le bateau
                                try {
                                    pair<int,int> p;
                                    p.first = 0;
                                    p.second = 0;
                                    CBateau bateau(nom, p, taille);
                                    ajouterBateau(bateau);
                                } catch (exception &err) {
                                }
                            }
                        } else {
                            cout << "La taille du bateau n'est pas bonne." << endl; 
                        }
                    } else { 
                        cout << "Le 3e champ doit être un nombre entre 1 et 5 (taille du bateau)." << endl; 
                    }
                } else {
                    cout << "Le 2d champ doit être un entier positif (nombre de \"" << nom << "\")." << endl; 
                }
            } else {
                cout << "Le 1er champ n'est pas un nom de bateau connu." << endl; 
            }
        } else {
            cout << "La ligne ne comporte pas exactement 3 champs." << endl; 
        }
    }
}

/**
 * Place les bateaux de l'armada aléatoirement sur la grille, et si au bout de MAXESSAIS essais,
 * les bateaux n'ont pas réussi à être correctement placés, la méthode retourne faux.
 * 
 * @return vrai si le placement aléatoire des bateaux sur la grille est un succès, faux sinon
 */
bool CArmada::placerAleatoirement() {

    //srand(time(NULL));
    bool placementReussi = false;
    bool maxEssaisAtteint = false;
    int nbBateauxPlaces = 0;
    vector<pair<int,int>> casesOccupees(getNbreTotCases());
    
    bool bateauPlace;
    bool caseOccupee;
    int essais;
    int i;
    int j;

    // Tant que le nombre d'essais max n'a pas été atteint 1 fois et que tous les bateaux ne sont pas placés
    while (!maxEssaisAtteint && nbBateauxPlaces < (int) m_listeBateaux.size()) {
        essais = 0;
        bateauPlace = false;

        // Tant qu'on atteint pas MAXESSAIS tentatives de placement et que le bateau n'est toujours pas placé
        while (essais < MAXESSAIS && !bateauPlace) {
            bateauPlace = false;
            caseOccupee = false;

            // On prend une position au hasard dans la grille
            i = rand() % (TAILLE_GRILLE - 1);
            j = TAILLE_GRILLE;
            while ((j + m_listeBateaux.at(nbBateauxPlaces).getTaille() - 1) > (TAILLE_GRILLE - 2)) {
                j = rand() % (TAILLE_GRILLE - 1);
            }
            essais++;

            // Vérifie si le bateau peut être placé avec comme point d'ancrage la position prise au hasard
            for (pair<int,int> p : casesOccupees) {

                // Si le bateau se trouve sur la même ligne que la case occupée
                if (p.first == i) {

                    // Si la case juste à gauche est occupée
                    if (p.second == (j - 1))
                        caseOccupee = true;
                    
                    for (int j2 = 0; j2 < m_listeBateaux.at(nbBateauxPlaces).getTaille(); j2++) {

                        // Si une case du bateau est en fait déjà occupée
                        if ((j + j2) <= (TAILLE_GRILLE - 2) && p.second == (j + j2))
                            caseOccupee = true;
                    }

                    // Si la case juste à droite est occupée
                    if ((j + m_listeBateaux.at(nbBateauxPlaces).getTaille()) <= (TAILLE_GRILLE - 2) && p.second == (j + m_listeBateaux.at(nbBateauxPlaces).getTaille()))
                        caseOccupee = true;
                }
            }

            // Si la position prise au hasard n'est pas déjà occupée, on donne les positions au bateau
            // et on ajoute les positions occupées dans casesOccupees pour la suite
            if (!caseOccupee) {
                bateauPlace = true;

                // On donne les positions au bateau
                m_listeBateaux.at(nbBateauxPlaces).setPosition(i, j);

                // On ajoute toutes les positions du bateau dans casesOccupees pour la suite du placement aléatoire et automatique
                for (int y = 0; y < m_listeBateaux.at(nbBateauxPlaces).getTaille(); y++) {
                    pair<int,int> p;
                    p.first = i;
                    p.second = j + y;
                    casesOccupees.push_back(p);
                }

                nbBateauxPlaces++;
            }
        }

        // Si le max d'essais a été atteint
        if (essais >= MAXESSAIS)
            maxEssaisAtteint = true;
    }

    // Le placement est réussi si tous les bateaux ont été placés aléatoirement et automatiquement sans dépasser MAXESSAIS essais
    if (!maxEssaisAtteint)
        placementReussi = true;

    return placementReussi;
}
