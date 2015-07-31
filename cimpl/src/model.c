/****************************************
 * model and state 
 ****************************************/


#include "model.h"
#include "materials.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define WORLD_X_DIM 10
#define WORLD_Y_DIM 10
#define WORLD_Z_DIM 1

// -----------------------------------
// Player Information and Manipulation

// State variable for the current player
player cur;

void initPlayer (void) {
    cur.x = 5.0;
    cur.y = 5.0;
    cur.angle = 0;
}

player getPlayer (void) {
    return cur;
}

void rotatePlayer (float rad) {
    cur.angle += rad;
}

void movePlayer (float distance) {
    cur.x += cos(cur.angle)*distance;
    cur.y += sin(cur.angle)*distance;
}

//-----------------------------------
// World Information and Manipulation

// 3D array of Voxels, each is a 1x1x1 cube
voxel world[WORLD_X_DIM][WORLD_Y_DIM][WORLD_Z_DIM];

void printWorld (void) {
    int i = 0;
    for (i = 0; i < WORLD_Y_DIM; i++) {
        int j = 0;
        for (j = 0; j < WORLD_X_DIM; j++) {
            printf("%d:%s ", world[j][i][0].id, materialAtPoint(j,i,0).name); 
        }
        printf("/n");
    }
}

void initWorld (void) {
    loadMaterials();

    //TODO load from file
    srand(time(NULL));
    
    int i = 0;
    for (i = 0; i < WORLD_X_DIM; i++) {
        int j = 0;
        for (j = 0; j < WORLD_Y_DIM; j++) {
            voxel v;
            v.id = rand() % 4;
            world[i][j][0] = v;
        }
    }

    //printWorld();
}

material materialAtPlayer (float x, float y, float z) {
    return materialAtPoint((int) x, (int) y, (int) z);
}

material materialAtPoint (int x, int y, int z) {
    if (x < 0 || y < 0 || x >= WORLD_X_DIM || y >= WORLD_Y_DIM) {
        //error
    }
    //TODO add in z value
    return getMaterial(world[x][y][0]);
}

int worldXDim (void) {
    return (int) WORLD_X_DIM;
}

int worldYDim (void) {
    return (int) WORLD_Y_DIM;
}
