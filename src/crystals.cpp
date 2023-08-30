#include "crystals.h"
#include "raymath.h"
#include <iostream>

using namespace std;
gems::gems(mainCharacter *charO,onre *enemyO){
    charObj = charO;
    enemyObj = enemyO;
    randomVal = GetRandomValue(800,1000);
    wordlPos = {randomVal,randomVal};
    texture = gem;
}

void gems::tickFunction(float deltatime){

    if(totalGems!=5){
        
        if(CheckCollisionRecs(getColRec(),charObj->getColRec())){
            wordlPos = enemyObj->getIdlePos();
            totalGems++;
        }
            texturePos = Vector2Subtract(wordlPos,charObj->getWorldPos());
            DrawTextureEx(texture,texturePos,0.0,1.5,WHITE);
    }else{
        enemyObj->gemCollected(totalGems);
    }
     
}