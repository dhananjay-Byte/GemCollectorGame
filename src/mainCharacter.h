#include "raylib.h"
#include "baseChar.h"

#ifndef CHARACTER_H
#define CHARACTER_H
class mainCharacter : public baseCharacter{

public:
    mainCharacter(int maxWFrame);
    // functions contining every variable which get updated on every frame.
    virtual void tickFunction(float deltatime)override;
    // Vector2 getCharacterPos(){return texturePos;}
    Rectangle getRec(){return rec;}

    float getHealth() const {return totalHealth;}
    
    void takeDamage(float damage);

protected:
   Texture2D samuraiRun{};
   Texture2D samuraiIdle{};
   Texture2D samuraiAttack{};
   float totalHealth = 100.0f;
private:

};

#endif