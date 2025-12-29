#include "map.h"

void DrawRectangleBorder (int posx, int posy, float width, float height, Color in, Color border) {
    DrawRectangle(posx, posy, width, height, border);
    DrawRectangle(posx + 1, posy + 1, width - 2, height - 2, in);
}

void DrawMap (Vector2 pos, const int TILE, const int N, int map[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (map[i][j])
                DrawRectangleBorder(pos.x + TILE * i, pos.y + TILE * j, TILE, TILE, DARKBLUE, LIGHTGRAY);
            else DrawRectangleBorder(pos.x + TILE * i, pos.y + TILE * j, TILE, TILE, RAYWHITE, LIGHTGRAY);
}

void UpdateMap (const int N, const int TILE, Vector2 pos_map, Vector2 pos, Vector2 player, int map[N][N]) {
    pos.x -= pos_map.x, pos.y -= pos_map.y;
    pos.x /= TILE, pos.y /= TILE;
    player.x -= pos_map.x, player.y -= pos_map.y;
    player.x /= TILE, player.y /= TILE;
    if ((int)pos.x == (int)player.x && (int)pos.y == (int)player.y) return;
    if (pos.x < (N - 1) && pos.y < (N - 1) && pos.x > 1 && pos.y > 1) 
        map[(int)pos.x][(int)pos.y] ^= 1;
}

void InitMap (const int N, int map[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) 
            map[i][j] = (!i || i == N - 1 || !j || j == N - 1);
}