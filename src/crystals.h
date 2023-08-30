#include "raylib.h"
#include "baseChar.h"
#include "mainCharacter.h"
#include "enemy.h"

class gems : public baseCharacter{
    public:
    gems(mainCharacter *charO,onre *enemyO);

    virtual void tickFunction(float deltatime)override;

    int getgems(){return totalGems;}

    protected:
    mainCharacter *charObj;
    onre *enemyObj;
    Texture2D gem = LoadTexture("../resources/redCrystal.png");
    int totalGems{};
    float randomVal{};
    bool collectgem = false;

    float frameDely = 12;
    float framTime{};
};