#define RAYLIB_PROJECT_ERFAN
#define PLAYER_PROJECT_ERFAN
#include "raylib.h"
#include "map.h"
#include "player.h"
#include "raycaster.h"

int main () {
    
    const int WX = 1280, WY = 720;
    InitWindow(WX, WY, "2D MAP");
    const int TILE = 15, N = 15;
    Vector2 pos_map = {WX - TILE * N - 20, 20};
    SetTargetFPS(60);
    
    int map_2d[N][N];
    Player p;
    const float v = 50;
    p.pos.x = (N / 2.) * TILE + pos_map.x;
    p.pos.y = (N / 2.) * TILE + pos_map.y;
    p.dir.x = 1, p.dir.y = 0;
    p.plane.x = 0, p.plane.y = 0.66;
    InitMap(N, map_2d);
    while (!WindowShouldClose()) {
        // update map
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) 
            UpdateMap(N, TILE, pos_map, GetMousePosition(), p.pos, map_2d);
        float dt = GetFrameTime();

        // update player
        if (IsKeyDown(KEY_LEFT))
            RotatePlayer(&p, -dt * PI / 2);
        if (IsKeyDown(KEY_RIGHT))
            RotatePlayer(&p, dt * PI / 2);

        if (IsKeyDown(KEY_W))
            MovePlayerForward(&p, v, dt, N, map_2d, TILE, pos_map);
        if (IsKeyDown(KEY_S)) 
            MovePlayerBackward(&p, v / 2, dt, N, map_2d, TILE, pos_map);
        if (IsKeyDown(KEY_D))
            MovePlayerRight(&p, v / 2, dt, N, map_2d, TILE, pos_map);
        if (IsKeyDown(KEY_A))
            MovePlayerLeft(&p, v / 2, dt, N, map_2d, TILE, pos_map);

        BeginDrawing();
            ClearBackground((Color){0, 167, 223, 255});
            DrawRectangle(0, WY / 2, WX, WY / 2, DARKGREEN);
            Raycast(p, N, map_2d, pos_map, TILE, WX, WY);
            DrawMap(pos_map, TILE, N, map_2d);
            ShowPlayer(p);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}