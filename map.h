#ifndef RAYLIB_PROJECT_ERFAN
#define RAYLIB_PROJECT_ERFAN
#include "raylib.h"
#endif

void DrawRectangleBorder (int posx, int posy, float width, float height, Color in, Color border);

void DrawMap (Vector2 pos, const int TILE, const int N, int map[N][N]);

void UpdateMap (const int N, const int TILE, Vector2 pos_map, Vector2 pos, int map[N][N]);

void InitMap (const int N, int map[N][N]);