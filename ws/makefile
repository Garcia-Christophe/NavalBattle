# Makefile du projet "Bataille navale" A PLACER DANS /ws

# Chaque classe du projet doit être testée séparément.
# Il y aura donc un lanceur (main) par classe à tester.

# Ce makefile doit permettre de faire :
#	- la compilation du lanceur associé à chaque classe à tester
#	- la compilation du projet final (c-à-d main.cpp)

# Déclaration de quelques variables utiles au makefile
GPP = g++ -Wall
SRC = ../src
BIN = ../bin

# La cible "deleteAll" est exécutée en tapant la commande "make deleteAll"
deleteAll :
	@# Précéder chaque commande d'une TABULATION
	@echo suppression du contenu du répertoire ../bin
	rm -f $(BIN)/*.o $(BIN)/*.bin

# Test de la classe CBateau
# Compilation du lanceur testCBateau, pour cela (l'ordre de compilation est important en C++) :
#	- supprimer le contenu du répertoire "../bin" et
#	- d'abord compiler CBateau
#	- ensuite compiler testCBateau

# La cible "testCBateau" est exécutée en tapant la commande "make testCBateau"
testCBateau : deleteAll compileCBateau compileTestCBateau launchTestCBateau 

# La cible "compileCBateau" est exécutée en tapant la commande "make compileCBateau"
compileCBateau :
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation CBateau
	$(GPP) $(SRC)/CBateau.cpp -o $(BIN)/CBateau.o -c

# La cible "compileTestCBateau" est exécutée en tapant la commande "make compileTestCBateau"
compileTestCBateau :
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation testCBateau
	$(GPP) $(SRC)/testCBateau.cpp $(BIN)/CBateau.o -o $(BIN)/testCBateau.bin

# La cible "launchTestCBateau" est exécutée en tapant la commande make "launchTestCBateau"
launchTestCBateau :
	@# Précéder chaque commande d'une TABULATION
	@echo Lancement testCBateau
	$(BIN)/testCBateau.bin

# Test de la classe CArmada
# Compilation du lanceur testCArmada, pour cela (l'ordre de compilation est important en C++) :
#	- supprimer le contenu du répertoire "../bin" et
#	- d'abord compiler CArmada
#	- ensuite compiler testCArmada

# La cible "testCArmada" est exécutée en tapant la commande "make testCArmada"
testCArmada : deleteAll compileCBateau compileCArmada compileTestCArmada launchTestCArmada 

# La cible "compileCArmada" est exécutée en tapant la commande "make compileCArmada"
compileCArmada :
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation CArmada
	$(GPP) $(SRC)/CArmada.cpp -o $(BIN)/CArmada.o -c

# La cible "compileTestCArmada" est exécutée en tapant la commande "make compileTestCArmada"
compileTestCArmada :
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation testCArmada
	$(GPP) $(SRC)/testCArmada.cpp $(BIN)/CBateau.o $(BIN)/CArmada.o -o $(BIN)/testCArmada.bin

# La cible "launchTestCArmada" est exécutée en tapant la commande make "launchTestCArmada"
launchTestCArmada :
	@# Précéder chaque commande d'une TABULATION
	@echo Lancement testCArmada
	$(BIN)/testCArmada.bin

# Test de la classe CGui
# Compilation du lanceur testCGui, pour cela (l'ordre de compilation est important en C++) :
#	- supprimer le contenu du répertoire "../bin" et
#	- d'abord compiler CGui
#	- ensuite compiler testCGui

# La cible "testCGui" est exécutée en tapant la commande "make testCGui"
testCGui : deleteAll compileCBateau compileCArmada compileCCoups compileCGui compileTestCGui launchTestCGui 

# La cible "compileCCoups" est exécutée en tapant la commande "make compileCCoups"
compileCCoups :
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation CCoups
	$(GPP) $(SRC)/CCoups.cpp -o $(BIN)/CCoups.o -c

# La cible "compileCGui" est exécutée en tapant la commande "make compileCGui"
compileCGui :
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation CGui
	$(GPP) $(SRC)/CGui.cpp -o $(BIN)/CGui.o -c

# La cible "compileTestCGui" est exécutée en tapant la commande "make compileTestCGui"
compileTestCGui :
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation testCGui
	$(GPP) $(SRC)/testCGui.cpp $(BIN)/CCoups.o $(BIN)/CBateau.o $(BIN)/CArmada.o $(BIN)/CGui.o -o $(BIN)/testCGui.bin

# La cible "compileCSocket" est exécutée en tapant la commande "make compileCSocket"
compileCSocket :
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation CSocket
	$(GPP) $(SRC)/CSocket.cpp -o $(BIN)/CSocket.o -c

# La cible "compileCClientSocket" est exécutée en tapant la commande "make compileCClientSocket"
compileCClientSocket :
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation CClientSocket
	$(GPP) $(SRC)/CClientSocket.cpp -o $(BIN)/CClientSocket.o -c

# La cible "compileCServerSocket" est exécutée en tapant la commande "make compileCServerSocket"
compileCServerSocket :
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation CServerSocket
	$(GPP) $(SRC)/CServerSocket.cpp -o $(BIN)/CServerSocket.o -c

# La cible "compileCJoueur" est exécutée en tapant la commande "make compileCJoueur"
compileCJoueur :
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation CJoueur
	$(GPP) $(SRC)/CJoueur.cpp -o $(BIN)/CJoueur.o -c

# La cible "compileCJoueurCli" est exécutée en tapant la commande "make compileCJoueurCli"
compileCJoueurCli :
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation CJoueurCli
	$(GPP) $(SRC)/CJoueurCli.cpp -o $(BIN)/CJoueurCli.o -c

# La cible "compileCJoueurServ" est exécutée en tapant la commande "make compileCJoueurServ"
compileCJoueurServ :
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation CJoueurServ
	$(GPP) $(SRC)/CJoueurServ.cpp -o $(BIN)/CJoueurServ.o -c

# La cible "launchTestCGui" est exécutée en tapant la commande "make launchTestCGui"
launchTestCGui :
	@# Précéder chaque commande d'une TABULATION
	@echo Lancement testCGui
	$(BIN)/testCGui.bin

# ICI, la cible de compilation finale pour obtenir main.bin
# A executer A LA FIN du projet en s'assurant que toutes les classes du projet compilent et s'exécutent sans erreurs !
# La cible "lanceurFinal"
lanceurFinal : deleteAll compileCBateau compileCArmada compileCCoups compileCGui compileCSocket compileCClientSocket compileCServerSocket compileCJoueur compileCJoueurCli compileCJoueurServ
	@echo Compilation lanceurFinal
	$(GPP) $(SRC)/main.cpp $(BIN)/CBateau.o $(BIN)/CArmada.o $(BIN)/CCoups.o $(BIN)/CGui.o $(BIN)/CSocket.o $(BIN)/CClientSocket.o $(BIN)/CServerSocket.o $(BIN)/CJoueur.o $(BIN)/CJoueurCli.o $(BIN)/CJoueurServ.o -o $(BIN)/main.bin

# La cible "launchGame" est exécutée en tapant la commande "make launchGame"
launchGame :
	@# Précéder chaque commande d'une TABULATION
	@echo Lancement main
	$(BIN)/main.bin

# La cible "tests" est exécutée en tapant la commande "make tests"
tests : testCBateau testCArmada testCGui

# La cible "startGame" est exécutée en tapant la commande "make startGame"
startGame : lanceurFinal launchGame
