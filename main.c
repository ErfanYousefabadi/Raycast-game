#define RAYLIB_PROJECT_ERFAN
#define PLAYER_PROJECT_ERFAN
#include "raylib.h"
#include "map.h"
#include "player.h"
#include "raycaster.h"
#include "persistence.h"

typedef enum {
    PLAY_MODE,  // 3D First-person view
    EDIT_MODE   // 2D TOP-down map view
} GameState;

int main () {
    
    const int WX = 1280, WY = 720;
    InitWindow(WX, WY, "2D MAP");
    const int N = 15;
    const int TILE_PLAY = 15;
    const int TILE_EDIT = 35;
    Vector2 pos_map_play = {WX - TILE_PLAY * N - 20, 20};
    Vector2 pos_map_edit = {(WX - TILE_EDIT * N) / 2, (WY - TILE_EDIT * N) / 2};
    SetTargetFPS(60);
    int world_map[N][N];
    const char map_file[] = "map.txt";
    const char player_file[] = "player.txt";
    
    const float v = 30;
    Player p;
    {
        FILE *F = fopen(map_file, "r");
        if (!F) {
            InitMap(N, world_map);
        } else {
            fclose(F);
            LoadMap(N, world_map, map_file);
        }
        F = fopen(player_file, "r");
        if (!F) {
            InitPlayer(&p, N, TILE_PLAY, pos_map_play);
        } else {
            fclose(F);
            LoadPlayer(&p, player_file);
        }
        SaveBackup(N, world_map, p, map_file, player_file);
    }
    GameState GState = PLAY_MODE;
    while (!WindowShouldClose()) {
        
        // change GameState?
        if (IsKeyPressed(KEY_M)) {
            if (GState == PLAY_MODE)
            GState = EDIT_MODE;
            else GState = PLAY_MODE;
        }
        // save or load backup
        float dt = GetFrameTime();
        if (IsKeyPressed(KEY_F5)) // save
            SaveBackup(N, world_map, p, map_file, player_file);
        else if (IsKeyPressed(KEY_F9)) // load
            LoadBackup(N, world_map, &p, map_file, player_file);
        
        if (GState == PLAY_MODE) {
            // update player
            if (IsKeyDown(KEY_LEFT))
                RotatePlayer(&p, -dt * PI / 3 * 2);
            if (IsKeyDown(KEY_RIGHT))
                RotatePlayer(&p, dt * PI / 3 * 2);
            
            if (IsKeyDown(KEY_W))
                MovePlayerForward(&p, v, dt, N, world_map, TILE_PLAY, pos_map_play);
            if (IsKeyDown(KEY_S)) 
                MovePlayerBackward(&p, v, dt, N, world_map, TILE_PLAY, pos_map_play);
            if (IsKeyDown(KEY_D))
                MovePlayerRight(&p, v, dt, N, world_map, TILE_PLAY, pos_map_play);
            if (IsKeyDown(KEY_A))
                MovePlayerLeft(&p, v, dt, N, world_map, TILE_PLAY, pos_map_play);
            
            BeginDrawing();
                ClearBackground((Color){0, 167, 223, 255});
                DrawRectangle(0, WY / 2, WX, WY / 2, DARKGREEN);
                Raycast(p, N, world_map, pos_map_play, TILE_PLAY, WX, WY);
                DrawMapPlay(pos_map_play, TILE_PLAY, N, world_map);
                ShowPlayer(p);
                DrawFPS(WX - 100, WY / 2);
                DrawText("Play Mode  |  M: Map  |  F5: Save  |  F9: Load\n", 20, 20, 20, BLACK);
            EndDrawing();
        }
        else if (GState == EDIT_MODE) {
            // get player position from map_play to map_edit
            Player p2 = p;
            p2.pos.x -= pos_map_play.x, p2.pos.y -= pos_map_play.y;
            p2.pos.x /= TILE_PLAY, p2.pos.y /= TILE_PLAY;
            p2.pos.x *= TILE_EDIT, p2.pos.y *= TILE_EDIT;
            p2.pos.x += pos_map_edit.x, p2.pos.y += pos_map_edit.y;
            // update map
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) 
                UpdateMapAdd(N, TILE_EDIT, pos_map_edit, GetMousePosition(), p2.pos, world_map);
            if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) 
                UpdateMapRemove(N, TILE_EDIT, pos_map_edit, GetMousePosition(), p2.pos, world_map);
            
            BeginDrawing();
                ClearBackground(GRAY);
                DrawMapEdit(pos_map_edit, TILE_EDIT, N, world_map);
                ShowPlayer(p2);
                DrawText("Edit Mode  |  M: Play  |  F5: Save  |  F9: Load\n", 20, 20, 20, BLACK);
            EndDrawing();
        }
    }
    CloseWindow();
    return 0;
}