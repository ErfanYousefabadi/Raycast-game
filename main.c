#ifndef RAYLIB_PROJECT_ERFAN
#define RAYLIB_PROJECT_ERFAN
#include "raylib.h"
#endif
#include "map.h"

int main () {
    
    const int WX = 800, WY = 450;
    InitWindow(WX, WY, "2D MAP");
    Vector2 pos_map = {10, 10};
    const int TILE = 20, N = 20;
    SetTargetFPS(60);
    
    int map_2d[N][N];

    InitMap(N, map_2d);

    while (!WindowShouldClose()) {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) 
            UpdateMap(N, TILE, pos_map, GetMousePosition(), map_2d);

        BeginDrawing();
            ClearBackground(GRAY);
            DrawMap(pos_map, TILE, N, map_2d);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}