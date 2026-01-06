#ifndef RAYLIB_PROJECT_ERFAN
#define RAYLIB_PROJECT_ERFAN
#include "raylib.h"
#endif
#ifndef MATH_PROJECT_ERFAN
#define MATH_PROJECT_ERFAN
#include <math.h>
#endif
#ifndef PLAYER_PROJECT_ERFAN
#define PLAYER_PROJECT_ERFAN
#include "player.h"
#endif

void DDA (int x_pixel, Vector2 pos, Vector2 ray, const int N, int map[N][N], Vector2 map_pos, const int TILE, const int WY);
void Raycast (Player p, const int N, int map[N][N], Vector2 map_pos, const int TILE, const int WX, const int WY);