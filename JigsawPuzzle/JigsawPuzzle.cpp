// JigsawPuzzle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "raylib.h"

// Funkce pro inicializaci hry
void InitGame() {
    // Inicializace herních promìnných a objektù
}

// Funkce pro aktualizaci hry
void UpdateGame() {
    // Aktualizace herní logiky
}

// Funkce pro vykreslování hry
void DrawGame() {
    // Vykreslení herních objektù
}

int main() {
    // Inicializace raylib a nastavení parametrù okna
    InitWindow(800, 600, "Jigsaw Puzzle");

    // Inicializace hry
    InitGame();

    // Hlavní herní smyèka
    while (!WindowShouldClose()) {
        // Aktualizace hry
        UpdateGame();

        // Vykreslení hry
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawGame();
        EndDrawing();
    }

    // Uvolnìní pamìti a ukonèení programu
    CloseWindow();
    return 0;
}