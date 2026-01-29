#ifndef RAYLIB_PROJECT_ERFAN
#define RAYLIB_PROJECT_ERFAN
#include "raylib.h"
#endif

typedef struct {
    Vector2 pos;
    Vector2 dir;
    Vector2 plane;
}Player;

void ShowPlayer (Player p);
void RotatePlayer (Player *p, float alpha);
void InitPlayer (Player *p, const int N, const int TILE, Vector2 pos_map);
void MovePlayerForward (Player *p, float v, float dt, int N, int map[N][N], int TILE, Vector2 mpos);
void MovePlayerBackward (Player *p, float v, float dt, int N, int map[N][N], int TILE, Vector2 mpos);
void MovePlayerRight (Player *p, float v, float dt, int N, int map[N][N], int TILE, Vector2 mpos);
void MovePlayerLeft (Player *p, float v, float dt, int N, int map[N][N], int TILE, Vector2 mpos);

