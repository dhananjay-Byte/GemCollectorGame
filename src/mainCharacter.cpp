 #include "mainCharacter.h"
 #include "baseChar.h"
 #include "raymath.h"

    mainCharacter :: mainCharacter(int maxWFrame){
        samuraiIdle = LoadTexture("../resources/Samurai_Commander/Idle.png");
        samuraiRun = LoadTexture("../resources/Samurai_Commander/Run.png");
        samuraiAttack = LoadTexture("../resources/Samurai_Commander/Attack_2.png");

        texture = samuraiIdle;
        maxWidhtFrame = maxWFrame;
        widht =  static_cast<float>(texture.width) /maxWFrame;
        height = static_cast<float>(texture.height);
        texturePos = {GetScreenWidth() / 2.0f - scaleFactor * (0.5f * static_cast<float>(texture.width) /maxWFrame),
                          GetScreenHeight() / 2.0f - scaleFactor * (0.5f * static_cast<float>(texture.height))};
        
    }
    
    // functions contining every variable which get updated on every frame.
    void mainCharacter::tickFunction(float deltatime)
    { 
        
        if (IsKeyDown(KEY_A))
            velVector.x -= 1.0;
        if (IsKeyDown(KEY_D))
            velVector.x += 1.0;
        if (IsKeyDown(KEY_W))
            velVector.y -= 1.0;
        if (IsKeyDown(KEY_S))
            velVector.y += 1.0;
            
        if(Vector2Length(velVector)!=0.0){
            texture = samuraiRun;
            maxFrame = 8;
            
        }else if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
            texture = samuraiAttack;
            maxFrame = 5;
        }else{
             texture = samuraiIdle;
            maxFrame = 5;
        }
        baseCharacter::tickFunction(deltatime);
    }

    void mainCharacter::takeDamage(float damage){
        totalHealth -= damage;

        if(totalHealth <= 0.0f){
            setAlive(false);
        }
    }