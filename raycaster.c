#include "raycaster.h"

void DDA (int x_pixel, Vector2 pos, Vector2 ray, const int N, int map[N][N], Vector2 map_pos, const int TILE, const int WY) {
    pos.x -= map_pos.x, pos.y -= map_pos.y;
    pos.x /= TILE, pos.y /= TILE;
    double deltaDistX = (!ray.x) ? 1e30 : fabs(1 / ray.x);
    double deltaDistY = (!ray.y) ? 1e30 : fabs(1 / ray.y);
    float sideDistX, sideDistY;
    int stepX, stepY;
    if (ray.x < 0) {
        stepX = -1;
        sideDistX = (pos.x - (int)pos.x) * deltaDistX; 
    } 
    else {
        stepX = 1;
        sideDistX = ((int)pos.x + 1.0 - pos.x) * deltaDistX;
    }
    if (ray.y < 0) {
        stepY = -1;
        sideDistY = (pos.y - (int)pos.y) * deltaDistY;
    } 
    else {
        stepY = 1;
        sideDistY = ((int)pos.y + 1.0 - pos.y) * deltaDistY;
    }

    int hit = 0;
    int side = 0;
    while (!hit) {
        if (sideDistX < sideDistY) {
            sideDistX += deltaDistX;
            pos.x += stepX;
            side = 0; // X-side
        } 
        else {
            sideDistY += deltaDistY;
            pos.y += stepY;
            side = 1; // Y-side
        }
        hit = map[(int)pos.x][(int)pos.y] == 1;
    }

    float dis = sideDistX - deltaDistX;
    if (side) dis = sideDistY - deltaDistY;
    int h = WY / dis;
    Color color = GRAY;
    if (side == 1) color = DARKGRAY;
    DrawRectangle(x_pixel, (WY - h) / 2, 1, h, color);
}

void Raycast (Player p, const int N, int map[N][N], Vector2 map_pos, const int TILE, const int WX, const int WY) {
    for (int x = 0; x < WX; x++) {
        double cameraX = 2 * x / (double)WX - 1;
        Vector2 ray = (Vector2){p.dir.x + p.plane.x * cameraX, p.dir.y + p.plane.y * cameraX};
        DDA(x, p.pos, ray, N, map, map_pos, TILE, WY);
    }
}