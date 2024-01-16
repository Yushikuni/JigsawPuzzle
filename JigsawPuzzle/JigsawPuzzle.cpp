// JigsawPuzzle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "raylib.h"

// Funkce pro inicializaci hry
void InitGame() {
    // Inicializace hern�ch prom�nn�ch a objekt�
}

// Funkce pro aktualizaci hry
void UpdateGame() {
    // Aktualizace hern� logiky
}

// Funkce pro vykreslov�n� hry
void DrawGame() {
    // Vykreslen� hern�ch objekt�
}

int main() {
    // Inicializace raylib a nastaven� parametr� okna
    InitWindow(800, 600, "Jigsaw Puzzle");

    // Inicializace hry
    InitGame();

    // Hlavn� hern� smy�ka
    while (!WindowShouldClose()) {
        // Aktualizace hry
        UpdateGame();

        // Vykreslen� hry
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawGame();
        EndDrawing();
    }

    // Uvoln�n� pam�ti a ukon�en� programu
    CloseWindow();
    return 0;
}