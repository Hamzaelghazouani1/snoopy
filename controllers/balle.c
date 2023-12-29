#include "../header/protolib.h"

/**
 * @brief Creation des balles
 * 
 * @return Ball* 
 */
Ball * createBall(void){
    Ball * ball = (Ball*)malloc(sizeof(Ball));
    ball->Object.Position.x = 14;
    ball->Object.Position.y = 76;
    ball->direction = 0;
    return ball;
}

/**
 * @brief Deplacement du ball
 * 
 * @param ball 
 */
void moveBall(Ball * ball){
    gotoligcol(ball->Object.Position.x,ball->Object.Position.y);
    printf("%c",0xAB);
    if(ball->direction && ball->Object.Position.y<80){
        gotoligcol(ball->Object.Position.x,ball->Object.Position.y);
        printf(" ");
        ball->Object.Position.x+=2;
        ball->Object.Position.y+=4;
        gotoligcol(ball->Object.Position.x,ball->Object.Position.y);
        printf("%c",0xAB);
    }else if(!ball->direction && (ball->Object.Position.x > 2)){
        gotoligcol(ball->Object.Position.x,ball->Object.Position.y);
        printf(" ");            
        ball->Object.Position.x-=2;
        ball->Object.Position.y-=4;
        gotoligcol(ball->Object.Position.x,ball->Object.Position.y);
        printf("%c",0xAB);
    }else ball->direction = !ball->direction;
}

/**
 * @brief Distruction des balles
 * 
 * @param Ball*
 */
void distroyBall(Ball * ball){
    free(ball);
}
