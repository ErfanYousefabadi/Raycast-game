#include "persistence.h"

void save_map (int N, int map[N][N]) {
    FILE *f_map = fopen("persistence.txt", "w");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) 
            fprintf(f_map, "%d ", map[i][j]);
        fprintf(f_map, "\n");
    }
    fclose(f_map);
}

void load_map (int N, int map[N][N]) {
    FILE *f_map = fopen("persistence.txt", "r");
    if (f_map == NULL) return;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) 
            fscanf(f_map, "%d", &map[i][j]);
    fclose(f_map);
}
