#include "enemy.h"
#include "raymath.h"
#include <iostream>

using namespace std;
onre::onre(int maxWFrame){

    speed = 3.0f;

    enemyRun = LoadTexture("../resources/Onre/Run.png");
    enemyIdle = LoadTexture("../resources/Onre/Idle.png");
    texture = enemyIdle;

    maxFrame = maxWFrame;
    widht = texture.width/ maxWFrame;
    height = texture.height;

    float randomVal = GetRandomValue(300,1000);
    wordlPos = {randomVal,randomVal};
}

void onre::tickFunction(float deltatime){
    
    texturePos = Vector2Subtract(wordlPos,target->getWorldPos());
    padding = 40;

    distanceFrom_char = Vector2Distance(target->getCharacterPos(),getCharacterPos());

    if(distanceFrom_char <= 250 && !CheckCollisionRecs(target->getColRec(),getColRec()) ){
        texture = enemyRun;
        maxFrame = 7;
        velVector = Vector2Subtract(target->getCharacterPos(),texturePos);
    }else{
        idlePos = wordlPos;
        texture = enemyIdle;
        maxFrame = 6;
    }

    if(CheckCollisionRecs(target->getColRec(),getColRec())){
      texture = onreAttack;
      maxFrame = 4;
      target->takeDamage(damageperHit*deltatime);
    }
    if(CheckCollisionRecs(target->getColRec(),getColRec()) && (totalgems==5) && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
        setAlive(false);
    }
    baseCharacter::tickFunction(deltatime);
}