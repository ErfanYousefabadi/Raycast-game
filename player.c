#ifndef RAYLIB_PROJECT_ERFAN
#define RAYLIB_PROJECT_ERFAN
#include "raylib.h"
#endif
#include "player.h"
#ifndef MATH_PROJECT_ERFAN
#define MATH_PROJECT_ERFAN
#include <math.h>
#endif

void ShowPlayer (Player p) {
    DrawCircle(p.pos.x, p.pos.y, 5, RED);
    DrawLine(p.pos.x, p.pos.y, p.pos.x + p.dir.x * 15, p.pos.y + p.dir.y * 15, RED);
    // debug
    // DrawLine(p.pos.x, p.pos.y, p.pos.x + (p.dir.x + p.plane.x) * 15, p.pos.y + (p.dir.y + p.plane.y) * 15, BLUE);
    // DrawLine(p.pos.x, p.pos.y, p.pos.x + (p.dir.x - p.plane.x) * 15, p.pos.y + (p.dir.y - p.plane.y) * 15, BLUE);
}

void RotatePlayer (Player *p, float alpha) {
    float nx = (*p).dir.x * cos(alpha) - (*p).dir.y * sin(alpha);
    float ny = (*p).dir.x * sin(alpha) + (*p).dir.y * cos(alpha);
    (*p).dir.x = nx, (*p).dir.y = ny;
    nx = (*p).plane.x * cos(alpha) - (*p).plane.y * sin(alpha);
    ny = (*p).plane.x * sin(alpha) + (*p).plane.y * cos(alpha);
    (*p).plane.x = nx, (*p).plane.y = ny;
}

void MovePlayerForward (Player *p, float v, float dt, int N, int map[N][N], int TILE, Vector2 mpos) {
    float nposx = (*p).pos.x + v * dt * (*p).dir.x;
    float nposy = (*p).pos.y + v * dt * (*p).dir.y;
    int bx = (int)((nposx - mpos.x) / TILE);
    int by = (int)((nposy - mpos.y) / TILE);
    int cx = (int)(((*p).pos.x - mpos.x) / TILE);
    int cy = (int)(((*p).pos.y - mpos.y) / TILE);
    if (!map[cx][by]) (*p).pos.y = nposy;
    if (!map[bx][cy]) (*p).pos.x = nposx;
}
void MovePlayerBackward (Player *p, float v, float dt, int N, int map[N][N], int TILE, Vector2 mpos) {
    float nposx = (*p).pos.x - v * dt * (*p).dir.x;
    float nposy = (*p).pos.y - v * dt * (*p).dir.y;
    int bx = (int)((nposx - mpos.x) / TILE);
    int by = (int)((nposy - mpos.y) / TILE);
    int cx = (int)(((*p).pos.x - mpos.x) / TILE);
    int cy = (int)(((*p).pos.y - mpos.y) / TILE);
    if (!map[cx][by]) (*p).pos.y = nposy;
    if (!map[bx][cy]) (*p).pos.x = nposx;
}
void MovePlayerLeft (Player *p, float v, float dt, int N, int map[N][N], int TILE, Vector2 mpos) {
    float nposx = (*p).pos.x + v * dt * (*p).dir.y;
    float nposy = (*p).pos.y - v * dt * (*p).dir.x;
    int bx = (int)((nposx - mpos.x) / TILE);
    int by = (int)((nposy - mpos.y) / TILE);
    int cx = (int)(((*p).pos.x - mpos.x) / TILE);
    int cy = (int)(((*p).pos.y - mpos.y) / TILE);
    if (!map[cx][by]) (*p).pos.y = nposy;
    if (!map[bx][cy]) (*p).pos.x = nposx;
}
void MovePlayerRight (Player *p, float v, float dt, int N, int map[N][N], int TILE, Vector2 mpos) {
    float nposx = (*p).pos.x - v * dt * (*p).dir.y;
    float nposy = (*p).pos.y + v * dt * (*p).dir.x;
    int bx = (int)((nposx - mpos.x) / TILE);
    int by = (int)((nposy - mpos.y) / TILE);
    int cx = (int)(((*p).pos.x - mpos.x) / TILE);
    int cy = (int)(((*p).pos.y - mpos.y) / TILE);
    if (!map[cx][by]) (*p).pos.y = nposy;
    if (!map[bx][cy]) (*p).pos.x = nposx;
}