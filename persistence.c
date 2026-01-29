#include "persistence.h"

void SaveMap (int N, int map[N][N], const char *map_file) {
    FILE *f_map = fopen(map_file, "w");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) 
            fprintf(f_map, "%d ", map[i][j]);
        fprintf(f_map, "\n");
    }
    fclose(f_map);
}

void LoadMap (int N, int map[N][N], const char *map_file) {
    FILE *f_map = fopen(map_file, "r");
    if (f_map == NULL) return;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) 
            fscanf(f_map, "%d", &map[i][j]);
    fclose(f_map);
}

void SavePlayer (Player p, const char *player_file) {
    FILE *f_player = fopen(player_file, "w");
    fprintf(f_player, "%f %f %f %f %f %f\n",
        p.pos.x, p.pos.y,
        p.dir.x, p.dir.y,
        p.plane.x, p.plane.y
    );
    fclose(f_player);
}

void LoadPlayer (Player *p, const char *player_file) {
    FILE *f_player = fopen(player_file, "r");
    if (f_player == NULL) return;
    fscanf(f_player, "%f%f%f%f%f%f", 
        &((*p).pos.x), &((*p).pos.y),
        &((*p).dir.x), &((*p).dir.y),
        &((*p).plane.x), &((*p).plane.y)
    );
    fclose(f_player);
}

void SaveBackup (int N, int map[N][N], Player p, const char *map_file, const char *player_file) {
    SaveMap(N, map, map_file);
    SavePlayer(p, player_file);
}

void LoadBackup (int N, int map[N][N], Player *p, const char *map_file, const char *player_file) {
    LoadMap(N, map, map_file);
    LoadPlayer(p, player_file);
}