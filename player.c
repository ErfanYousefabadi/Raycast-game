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