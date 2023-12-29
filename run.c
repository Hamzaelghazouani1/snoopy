#include "./header/protolib.h"

/**
 * @brief Menu principal du jeu
 * 
 * @return int 
 */
int run(void){
	int choice = 0;
    system("clear");
	do{
		menu();
		printf("Entrer votre choix : ");
		scanf("%d",&choice);
		switch ((int)choice)
		{
		case 1:
			displayGameRules();
		    getchar();
		    system("clear");
			break;
		case 2:
			startNewGame();
			break;
		case 3:
			resumeGame();
			getchar();
		    system("clear");
			break;
		case 4:
			printf("Fonction a implementer: Lancer directement un niveau via son Mot de passe\n");
		    getchar();
		    system("clear");
			break;
		case 5:
			printf("Fonction a implementer: Scores \n");
		    getchar();
		    system("clear");
			break;
		default:
			break;
		}
	}while ((int)choice);
	system("clear");
	return 0;
}
