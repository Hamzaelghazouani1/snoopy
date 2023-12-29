#ifndef TYPE_H
#define TYPE_H

#define ROW 10
#define COL 20 
#define PATH "../dao/db.txt"

/**
 * @brief position d'un objet (x,y)
 * 
 */
typedef struct {
    int x;
    int y;
}Position;

/**
 * @brief objet du jeu (Snoopy, Ball, Blocks, Birds)
 * 
 */
typedef struct {
    char* ship;
    Position Position;
}Object;

/**
 * @brief joueur du jeu (Snoopy) 
 * 
 */
typedef struct {
    
}Player;

/**
 * @brief Snoopy du jeu (joueur)
 * 
 */
typedef struct {
    Object Object;
}Snoopy;

/**
 * @brief Blocks du jeu (obstacles)
 * 
 */
typedef struct {
    Object** Array;
    int nbrBlock;
}Blocks;

/**
 * @brief Ball du jeu (projectile)
 * 
 */
typedef struct {
    Object Object;
    int direction;
}Ball;

/**
 * @brief Birds du jeu (ennemies)
 * 
 */
typedef struct {
    Object Bird_1;
    Object Bird_2;
    Object Bird_3;
    Object Bird_4;
}Birds;

/**
 * @brief Parametres du jeu (level, time, life, birds)
 * 
 */
typedef struct {
    int level;
    int time;
    int life;
    int birds;
}Param;

/**
 * @brief Le jeu contient tous les objets du jeu (Snoopy, Ball, Blocks, Birds)
 * 
 */
typedef struct {
    Snoopy* Snoopy;
    Ball* Ball;
    Blocks* Blocks;
    Birds* Birds;
}Game;

/**
 * @brief Grid du jeu (tableau de char) qui contient tous les objets du jeu (Snoopy, Ball, Blocks, Birds), les parametres du jeu (level, time, life, birds)
 * 
 */
typedef struct {
    char** Array;
    int row;
    int col;
    Param Param;
    Game* Game;
}Grid;

#endif