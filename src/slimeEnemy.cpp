#include "slimeEnemy.h"
#include <iostream>

using namespace std;
slime::slime(float intialX, float intialY){
    slimeTexture = LoadTexture("../resources/slime-Sheet.png");
    texture = slimeTexture;
    wordlPos = {intialX,intialY};
    intialPos = wordlPos.x;
    widht = static_cast<float>(slimeTexture.width) / 8;
    height = static_cast<float>(slimeTexture.height);
    maxWidhtFrame = 8;
}

void slime::tick(){

    worldLastPos = wordlPos;
    slimePos = Vector2Subtract(wordlPos,charObj->getWorldPos());
    texturePos = slimePos;

    if(wordlPos.x < (intialPos+incremnet) && !backward){
        wordlPos.x += 2.0f;
    }else if(wordlPos.x==(intialPos+incremnet)){
        backward = true;
    }

    if(backward && intialPos!=wordlPos.x){
        warriorDirection = 1.0f;
        wordlPos.x -= 2.0f;
    }else{
        warriorDirection = -1.0f;
        backward = false;
    }

    if(alive){
        animation(8);
        drawCharacter(warriorDirection,8);
    }
    
    padding = 20;
      if(CheckCollisionRecs(charObj->getColRec(),getColRec())){
                noMotion();
                charObj->takeDamage(damagerperHit*GetFrameTime());
        }
}