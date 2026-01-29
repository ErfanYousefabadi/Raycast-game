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
    Player p;
    const float v = 30;
    p.pos.x = (N / 2.) * TILE_PLAY + pos_map_play.x;
    p.pos.y = (N / 2.) * TILE_PLAY + pos_map_play.y;
    p.dir.x = 0, p.dir.y = -1;
    p.plane.x = 0.66, p.plane.y = 0;
    {
        FILE *F = fopen("persistence.txt", "r");
        if (!F) {
            InitMap(N, world_map);
        }
        else {
            fclose(F);
            load_map(N, world_map);
        }
    }
    // InitMap(N, world_map);
    GameState GState = PLAY_MODE;
    while (!WindowShouldClose()) {
        
        // change GameState?
        if (IsKeyPressed(KEY_M)) {
            if (GState == PLAY_MODE)
            GState = EDIT_MODE;
            else GState = PLAY_MODE;
        }
        
        float dt = GetFrameTime();
        
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
                DrawText("Play Mode - Press M For map\n", 20, 20, 20, BLACK);
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
            
            // save or load
            if (IsKeyPressed(KEY_F5)) // save
                save_map(N, world_map);
            else if (IsKeyPressed(KEY_F9)) // load
                load_map(N, world_map);
            BeginDrawing();
                ClearBackground(GRAY);
                DrawMapEdit(pos_map_edit, TILE_EDIT, N, world_map);
                ShowPlayer(p2);
                DrawText("Edit Mode - Press M To Play\n", 20, 20, 20, BLACK);
            EndDrawing();
        }
    }
    CloseWindow();
    return 0;
}