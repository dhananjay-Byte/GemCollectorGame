#include "raylib.h"
#include "baseChar.h"
#include "mainCharacter.h"
#ifndef ONRE_ENEMY
#define ONRE_ENEMY
class onre : public baseCharacter{
    public:
        onre(int maxWFrame);

        virtual void tickFunction(float deltatime)override;

        void setTarget(mainCharacter *character){ target = character;};

        Vector2 getIdlePos(){return idlePos;}

        int gemCollected(int gems){
            totalgems = gems;
            return totalgems;
        }
    protected:
   
        int maxWidhtF{};
        int maxHeightF{};
        mainCharacter *target;

        float distanceFrom_char{};
        Texture2D enemyRun{};
        Texture2D enemyIdle{};

        Vector2 idlePos{};

        float damageperHit{20.f};
        int totalgems{};
    private:
};

#endif