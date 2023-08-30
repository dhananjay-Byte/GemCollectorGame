#include "raylib.h"
#include "raymath.h"
#include "mainCharacter.h"
#include "enemy.h"
#include "slimeEnemy.h"
#include "crystals.h"
#include <iostream>

using namespace std;

// Drivers code
int main()
{
    const int widht = 500;
    const int height = 500;

    bool startGame{false};
    bool showMenu{true};

    InitWindow(widht, height, "First RPG Game");
    Texture2D map = LoadTexture("../resources/caveMap.png");
    Vector2 mapPosition = {0, 0};

    mainCharacter character {5};
    onre enemy {6};
    enemy.setTarget(&character);

    gems gemObj{&character,&enemy};

    slime slimeObj[] = {slime(900,300),slime(800,800),slime(400,1400)};

    for(int i=0;i<3;i++){
        slimeObj[i].setCharacter(&character);
    }

    SetTargetFPS(60);


    while (!WindowShouldClose())
    {

        BeginDrawing();

        // game logic starts here.
        if(startGame){
                mapPosition = Vector2Scale(character.getWorldPos(),-1.0f);
                DrawTextureEx(map, mapPosition, 0.0, 2, WHITE);

                
                if(!character.getAlive()){
                float textMes = MeasureText("GAME OVER",40);
                DrawText("GAME OVER",widht/2 - textMes,height - textMes,80,RED);
                EndDrawing();

                continue;

            }else if(!enemy.getAlive()){
                float textMes = MeasureText("YOU WON!",40);
                DrawText("YOU WON!",widht/2-textMes,height-textMes,80,RED);
                EndDrawing();

                continue;

            }else{
                string samuraiHealth = "Health: ";
                string gemsCollection = "Total Gems: ";
                
                samuraiHealth.append(to_string(character.getHealth()),0,5);
                gemsCollection.append(to_string(gemObj.getgems()));
                DrawText(samuraiHealth.c_str(),0,20,30,YELLOW);

                float textwidth = MeasureText(gemsCollection.c_str(),30);
                DrawText(gemsCollection.c_str(),GetScreenWidth()-textwidth,20,30,GREEN);
            }

                character.tickFunction(GetFrameTime());
                enemy.tickFunction(GetFrameTime());
                gemObj.tickFunction(GetFrameTime());

            for(int i=0;i<3;i++){
                slimeObj[i].tick();
            }


                if(character.getWorldPos().x < 0 ||
                character.getWorldPos().y < 0 ||
                character.getWorldPos().x + widht > map.width*2.0f ||
                character.getWorldPos().y + height > map.height*2.0f){

                    character.undoMap();
                }
                if(CheckCollisionRecs(character.getColRec(),enemy.getColRec())){
                    
                    character.noMotion(); 
                }
        }

        // Starting Menu logic.
        else{

            float textMes;

            textMes = MeasureText("GEMS",40);
            DrawText("GEMS ",widht/2-textMes,height/2 -textMes,80,MAROON);

            textMes = MeasureText("Collector",40);
            DrawText("Collector",widht/2 - textMes,(height/2 - textMes) + 150,80,MAROON);

            textMes = MeasureText("Press Enter",20);
            DrawText("Press Enter",widht/2 - textMes,(height/2 - textMes) + 250,40,BLUE);
        }

        if(IsKeyPressed(KEY_ENTER) && showMenu){
            startGame = true;
            showMenu = false;
        }
       
        EndDrawing();
    }
    CloseWindow();
    return 0;
}