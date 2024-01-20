// JigsawPuzzle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "raylib.h"

#define PUZZLE_PIECES 4

#define PUZZLE_BOARD 16

#define PICTURE 4

struct PuzzlePiece
{
    Rectangle sourceOriginal;
    Vector2 piecePosition;
};

// Funkce pro inicializaci hry
void InitGame() 
{
    // Inicializace herních promìnných a objektù


    int currentMovement = 0;
    int countAllPieces = 0;
    int currentPiecesCorrectlyPlaced = 0;

    countAllPieces = PUZZLE_PIECES * PUZZLE_PIECES;

    // Show original picture at side of game window

}

Image LoadingPicture(Image OutImage)
{
    // Loading piscture
    OutImage = LoadImage("resources/Dragon.png");     // Loaded in CPU memory (RAM)
    return OutImage;
}

void SplitPictureToJigsaw(PuzzlePiece pieces[], Image GetImage)
{
    int pieceWidth = GetImage.width / PUZZLE_PIECES;
    int pieceHeight = GetImage.height / PUZZLE_PIECES;

    for (int i = 0; i < PUZZLE_PIECES; i++)
    {
        for (int j = 0; j < PUZZLE_PIECES; j++)
        {
            int index = (i * PUZZLE_PIECES) + j;

            pieces[index].sourceOriginal = { (float)i * pieceWidth, (float)j * pieceHeight,(float)pieceWidth,(float)pieceHeight };

            pieces[index].piecePosition = { (float)i * pieceWidth + (float)GetImage.width, (float)j * pieceHeight + (float)GetImage.height};
        }
    }
}

void LoadingTexture(Image GetPicture)
{
    LoadTextureFromImage(GetPicture);          // Image converted to texture, GPU memory (VRAM)
}

Texture2D SetTexture( Image GetPicture)
{
    Texture2D GetTextureImage = LoadTextureFromImage(GetPicture);
    return GetTextureImage;
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

void FullscreenMode()
{
    SetWindowSize(GetMonitorWidth(GetCurrentMonitor()), GetMonitorHeight(GetCurrentMonitor()));
}


int main()
{
    const int screenWidth = 1260;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Jigsaw Puzzle");
    
    Image image = LoadImage("resources/Arrow.png");     // Loaded in CPU memory (RAM)

    LoadingPicture(image);
    LoadingTexture(image);
    //ImageResize(&image, screenWidth, screenHeight);
    Texture2D texture = SetTexture(image);
    UnloadImage(image);   // Once image has been converted to texture and uploaded to VRAM, it can be unloaded from RAM

    PuzzlePiece puzzles[PUZZLE_PIECES * PUZZLE_PIECES];
    SplitPictureToJigsaw(puzzles,image);

    SetTargetFPS(60);

    // Inicializace raylib a nastavení parametrù okna

    // Inicializace hry
    //InitGame();

    // Hlavní herní smyèka
    while (!WindowShouldClose()) 
    {
        // Aktualizace hry
        UpdateGame();

        // Vykreslení hry
        BeginDrawing();
        ClearBackground(RAYWHITE);

        //DrawTexture(texture, screenWidth / 2 - texture.width / 2, screenHeight / 2 - texture.height / 2, WHITE);

        //DrawTextureRec(texture, Rectangle{0,0, (float)image.width,(float)image.height}, Vector2{0, 0}, WHITE);

        for (int i = 0; i < PUZZLE_PIECES * PUZZLE_PIECES; i++)
        {
            DrawTextureRec(texture, puzzles[i].sourceOriginal, puzzles[i].piecePosition, WHITE);
        }

        //DrawGame();

        EndDrawing();
    }

    // Uvolnìní pamìti a ukonèení programu
    UnloadTexture(texture);

    CloseWindow();
    return 0;
}