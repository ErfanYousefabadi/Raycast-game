#include <stdio.h>
#include <stdlib.h>
#ifndef PLAYER_PROJECT_ERFAN
#define PLAYER_PROJECT_ERFAN
#include "player.h"
#endif

void SaveMap (int N, int map[N][N], const char *map_file);
void LoadMap (int N, int map[N][N], const char *map_file);
void SavePlayer (Player p, const char *player_file);
void LoadPlayer (Player *p, const char *player_file);
void SaveBackup (int N, int map[N][N], Player p, const char *map_file, const char *player_file);
void LoadBackup (int N, int map[N][N], Player *p, const char *map_file, const char *player_file);