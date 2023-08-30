#include "raylib.h"

#ifndef BASE_CHAR_H
#define BASE_CHAR_H
class baseCharacter{
    public:

        baseCharacter();

        Vector2 getWorldPos(){ return wordlPos;}

        Vector2 getLastPos(){return worldLastPos;}

        Vector2 getCharacterPos(){return texturePos;}
        // function to draw the character.
        void drawCharacter(float warriorDirect,int maxWidhtFrame);

        // function to animate the sprite sheets.
        void animation(int maxFrame);

        virtual void tickFunction(float deltatime);

        void undoMap();

        Rectangle getColRec();

        void noMotion();

        void setAlive(bool isalive){ alive = isalive;}
        bool getAlive(){return alive;}

    protected:
        Texture2D texture = {};
        Texture2D idle{}; 
        Texture2D Run{};
        Texture2D onreAttack = LoadTexture("../resources/Onre/Attack_3.png");

        Vector2 texturePos{};
        Rectangle rec;

        // animating variables
        float currentTime = 0.0f;
        float frameDelay = (1.0f / 10.0f);
        int frame = 0;

        Vector2 wordlPos{0.0f,0.0f};
        Vector2 worldLastPos{};
        Vector2 velVector{};

        float warriorDirection = 1.0f;

        float scaleFactor = 1.5f;
        float speed = 4.0f;
        float padding{};
        
        int framesize{};
        int maxFrame{};

        int maxWidhtFrame{};

        float widht{};
        float height{};
    private:
        bool alive{true};
};

#endif