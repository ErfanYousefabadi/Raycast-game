#ifndef RAYLIB_PROJECT_ERFAN
#define RAYLIB_PROJECT_ERFAN
#include "raylib.h"
#endif
#include "map.h"
#include "player.h"

int main () {
    
    const int WX = 800, WY = 450;
    InitWindow(WX, WY, "2D MAP");
    Vector2 pos_map = {200, 25};
    const int TILE = 20, N = 20;
    SetTargetFPS(60);
    
    int map_2d[N][N];
    Player p;
    p.pos.x = (N / 2 + .5) * TILE + pos_map.x;
    p.pos.y = (N / 2 + .5) * TILE + pos_map.y;
    p.dir.x = 1, p.dir.y = 0;
    p.plane.x = 0, p.plane.y = 0.66;
    InitMap(N, map_2d);
    while (!WindowShouldClose()) {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) 
            UpdateMap(N, TILE, pos_map, GetMousePosition(), p.pos, map_2d);
        float dt = GetFrameTime();
        if (IsKeyDown(KEY_LEFT))
            RotatePlayer(&p, -dt * PI);
        if (IsKeyDown(KEY_RIGHT))
            RotatePlayer(&p, dt * PI);

        BeginDrawing();
            ClearBackground(GRAY);
            DrawMap(pos_map, TILE, N, map_2d);
            ShowPlayer(p);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}