#include <stdio.h>
#include <stdlib.h>
#include "./header/protolib.h"

int main(void){
	int choice = 0;
    system("clear");
	do{
		menu();
		printf("Entrer votre choix : ");
		scanf("%d",&choice);
		switch (choice)
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
			printf("Fonction a implementer: Charger une partie\n");
			break;
		case 4:
			printf("Fonction a implementer: Lancer directement un niveau via son Mot de passe\n");
			break;
		case 5:
			printf("Fonction a implementer: Scores \n");
			break;
		default:
			break;
		}
	}while (choice);
	
	return 0;
}
