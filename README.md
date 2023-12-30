## Bienvenue dans Snoopy, un jeu de console 2D développé en langage C

Snoopy est un jeu inspiré du célèbre chien Snoopy.
L'objectif est de récupérer quatre oiseaux situés aux quatre coins du niveau dans un temps imparti tout en évitant les obstacles et les pièges. 
Le jeu propose une série de niveaux de difficulté croissante avec de nouveaux éléments de jeu à chaque étape.

### Fonctionnalités
* Déplacement de Snoopy dans quatre directions.
* Gestion de la balle rebondissante et d'autres obstacles.
* Différents types de blocs avec des comportements variés.
* Ennemis tels que des balles rebondissantes et un Snoopy malveillant.
* Fonctionnalités spéciales comme la pause, la sauvegarde et le chargement de parties.
  
---

1. Clonez le référentiel sur votre machine locale:
```bash
git clone https://github.com/Hamzaelghazouani1/snoopy.git
```
2. Compilez le code source:
```bash
gcc *.c */*.c -o snoopy
```

3. Lancez le jeu.
```bash
./snoopy
```

---

### Structure du Projet
* src/ : Contient tous les fichiers source du jeu.
* dao/ : Gestion de la sauvegarde et du chargement.
* headers/ : Fichiers d'en-tête contenant les structures et les prototypes.

### Contrôles du Jeu
* Utilisez les touches directionnelles pour déplacer Snoopy.
* Appuyez sur la touche 'P' pour mettre en pause le jeu.
* Pour sauvegarder, appuyez sur la touche 'S', puis entrez le nom du fichier.
* Appuyez sur 'Q' pour quitter le jeu.

![Screenshot 2023-12-31 000830](https://github.com/Hamzaelghazouani1/snoopy/assets/91982044/6eed1ab2-eeab-41c1-b17c-1623efa3bff7)
![Screenshot 2023-12-31 002036](https://github.com/Hamzaelghazouani1/snoopy/assets/91982044/35046e36-37d6-4a14-9ccf-e2803532ffce)

