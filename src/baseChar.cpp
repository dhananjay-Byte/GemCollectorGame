 #include "baseChar.h"
 #include "raymath.h"

    baseCharacter::baseCharacter(){

    }
    Rectangle baseCharacter::getColRec(){
        return Rectangle{texturePos.x+padding,texturePos.y+padding,widht-2*padding,height-2*padding};
    }
    // function to draw the character.
    void baseCharacter::drawCharacter(float warriorDirect, int maxWFrame)
    {
        Rectangle src = {frame * static_cast<float>(texture.width) / maxWidhtFrame, 0.0f, warriorDirect * static_cast<float>(texture.width) / maxWidhtFrame, static_cast<float>(texture.height)};
        Rectangle des = {texturePos.x,
                         texturePos.y,
                         scaleFactor * static_cast<float>(texture.width) / maxWFrame,
                         scaleFactor * static_cast<float>(texture.height)};
        DrawTexturePro(texture, src, des, Vector2{}, 0.0f, WHITE);
    }

    // function to animate the sprite sheets.
    void baseCharacter::animation(int maxF)
    {
        currentTime += GetFrameTime();
        if (currentTime >= frameDelay)
        {
            currentTime = 0.0f;
            frame++;
            if (frame > maxF - 1)
                frame = 0;
        }
    }

    void baseCharacter::tickFunction(float deltatime){

        worldLastPos = wordlPos;
        maxWidhtFrame = maxFrame;

        if (Vector2Length(velVector) != 0.0)
        {
            wordlPos = Vector2Add(wordlPos,
                                  Vector2Scale(Vector2Normalize(velVector), speed));

            velVector.x < 0 ? warriorDirection = -1.0f : warriorDirection = 1.0f;
        }

        animation(maxFrame);
        drawCharacter(warriorDirection, maxWidhtFrame);
        velVector = {};
        
    }

    void baseCharacter::undoMap(){
        wordlPos = worldLastPos;
    }

     void baseCharacter::noMotion(){
        wordlPos.x = worldLastPos.x;
    }