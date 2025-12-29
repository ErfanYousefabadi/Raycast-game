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


