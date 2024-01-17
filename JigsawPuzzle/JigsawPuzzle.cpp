// JigsawPuzzle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "raylib.h"

// Funkce pro inicializaci hry
void InitGame() 
{
    // Inicializace hern�ch prom�nn�ch a objekt�
}

void LoadingPicture(int GetScreenWidth, int GetScreenHeight, Image OutImage)
{
    // Loading piscture
    OutImage = LoadImage("resources/Dragon.png");     // Loaded in CPU memory (RAM)
    ImageResize(&OutImage, GetScreenWidth, GetScreenHeight);
}

Texture2D LoadingTexture(Image GetPicture)
{
    return LoadTextureFromImage(GetPicture);          // Image converted to texture, GPU memory (VRAM)
}

// Funkce pro aktualizaci hry
void UpdateGame() 
{
    // Aktualizace hern� logiky
}

// Funkce pro vykreslov�n� hry
void DrawGame() 
{
    // Vykreslen� hern�ch objekt�
    //LoadingPicture();
}

void FullscreenMode(int GetCurrentDisplay)
{
    SetWindowSize(GetMonitorWidth(GetCurrentDisplay), GetMonitorHeight(GetCurrentDisplay));
}


int main() 
{
    const int screenWidth = 1260;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Jigsaw Puzzle");

   // LoadingPicture(screenWidth, screenHeight, OutImage);
    

    //UnloadImage(image);   // Once image has been converted to texture and uploaded to VRAM, it can be unloaded from RAM

    SetTargetFPS(60);

    // Inicializace raylib a nastaven� parametr� okna
    

    // Inicializace hry
    InitGame();

    // Hlavn� hern� smy�ka
    while (!WindowShouldClose()) 
    {
        // Aktualizace hry
        UpdateGame();

        // Vykreslen� hry
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTexture(texture, screenWidth / 2 - texture.width / 2, screenHeight / 2 - texture.height / 2, WHITE);


        DrawGame();

        EndDrawing();
    }

    // Uvoln�n� pam�ti a ukon�en� programu
    UnloadTexture(texture);

    CloseWindow();
    return 0;
}