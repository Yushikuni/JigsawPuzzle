// JigsawPuzzle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "raylib.h"

// Funkce pro inicializaci hry
void InitGame() 
{
    // Inicializace herních promìnných a objektù
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
    // Aktualizace herní logiky
}

// Funkce pro vykreslování hry
void DrawGame() 
{
    // Vykreslení herních objektù
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

    // Inicializace raylib a nastavení parametrù okna
    

    // Inicializace hry
    InitGame();

    // Hlavní herní smyèka
    while (!WindowShouldClose()) 
    {
        // Aktualizace hry
        UpdateGame();

        // Vykreslení hry
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTexture(texture, screenWidth / 2 - texture.width / 2, screenHeight / 2 - texture.height / 2, WHITE);


        DrawGame();

        EndDrawing();
    }

    // Uvolnìní pamìti a ukonèení programu
    UnloadTexture(texture);

    CloseWindow();
    return 0;
}