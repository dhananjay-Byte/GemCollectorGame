#include "raylib.h"
#include "raymath.h"
#include "baseChar.h"
#include "mainCharacter.h"

class slime : public baseCharacter{
    public:
        slime(float intialX, float intialY);
        void tick();
        void setCharacter(mainCharacter *obj){charObj = obj;}
    protected:
        Texture2D slimeTexture;
        Rectangle rec{};
        Rectangle rec2{};
        Vector2 slimePos{};
        mainCharacter *charObj;
        bool backward = false;
        float intialPos{};
        float incremnet = 500;
        float alive = true;
        float damagerperHit{5.0f};
};