#ifndef RAYLIB_PROJECT_ERFAN
#define RAYLIB_PROJECT_ERFAN
#include "raylib.h"
#endif

void DrawRectangleBorder (int posx, int posy, float width, float height, Color in, Color border);

void DrawMapEdit (Vector2 pos, const int TILE, const int N, int map[N][N]);
void DrawMapPlay (Vector2 pos, const int TILE, const int N, int map[N][N]);

void UpdateMapAdd (const int N, const int TILE, Vector2 pos_map, Vector2 pos, Vector2 player, int map[N][N]);
void UpdateMapRemove (const int N, const int TILE, Vector2 pos_map, Vector2 pos, Vector2 player, int map[N][N]);
void InitMap (const int N, int map[N][N]);