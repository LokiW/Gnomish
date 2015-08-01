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
#define WORLD_Z_DIM 3

// -----------------------------------
// Player Information and Manipulation

// State variable for the current player
player cur;

void initPlayer (void) {
    cur.x = 5.0;
    cur.y = 5.0;
    cur.z = 1.0;
    cur.angle = 0;
}

player getPlayer (void) {
    return cur;
}

void rotatePlayer (float rad) {
    cur.angle += rad;
}

void movePlayer (float distance) {
//    cur.x += cos(cur.angle)*distance;
//    cur.y += sin(cur.angle)*distance;

    float tempX = cur.x + cos(cur.angle)*distance;
    float tempY = cur.y + sin(cur.angle)*distance;

//    if (!materialAtPlayer(tempX, tempY, cur.z).visibility) {
//	cur.x = tempX;
//	cur.y = tempY;
//    }

    float adjustDist = distance/2;

    while (!coordinatesInWorld(tempX, tempY, cur.z) || materialAtPlayer(tempX, tempY, cur.z).visibility) {
	tempX -= cos(cur.angle)*adjustDist;
	tempY -= sin(cur.angle)*adjustDist;
    }
    cur.x = tempX;
    cur.y = tempY;

    while (!materialAtPlayer(tempX, tempY, cur.z - 1.0).visibility && cur.z > 0) {
	cur.z - 1.0;
    }
}

void jumpPlayer (float height, float distance) {
//    cur.z += height;
//    movePlayer(distance);
}





//-----------------------------------
// World Information and Manipulation

// 3D array of Voxels, each is a 1x1x1 cube
voxel world[WORLD_X_DIM][WORLD_Y_DIM][WORLD_Z_DIM];

//Debugging function to print world information to consol
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
    randomWorld();
}

void randomWorld (void) {
    srand(time(NULL));
    int i,j,k;

    //TODO: make some algorith for likelyhoods of material adjacency
    for (k = 0; k < WORLD_Z_DIM; k++) {
        for (i = 0; i < WORLD_X_DIM; i++) {
            for (j = 0; j < WORLD_Y_DIM; j++) {
                voxel v;
                v.id = rand() % 4;
		if (k == 0) {
                    world[i][j][k] = v;
		} else if (world[i][j][k-1].id == v.id && (i != (float) cur.x && j != cur.y) 
				&& canStack(v)) { //k > 1
		    world[i][j][k] = v;
		} else {
		    //TODO: stop hardcoding air
		    v.id = 5;
		    world[i][j][k] = v;
		}
            }
        }
    }

    //printWorld();
}

char coordinatesInWorld (float x, float y, float z) {
	if (x < 0 || (int) x >= WORLD_X_DIM) {
	    return 0;
	} else if (y < 0 || (int) y >= WORLD_Y_DIM) {
	    return 0;
	} else if (z < 0 || (int) z >= WORLD_Z_DIM) {
	    return 0;
	} 
        return 1;
}

material materialAtPlayer (float x, float y, float z) {
    return materialAtPoint((int) x, (int) y, (int) z);
}

material materialAtPoint (int x, int y, int z) {
    if (!coordinatesInWorld((float) x, (float) y, (float) z)) {
        //error
    }
    return getMaterial(world[x][y][z]);
}

int worldXDim (void) {
    return (int) WORLD_X_DIM;
}

int worldYDim (void) {
    return (int) WORLD_Y_DIM;
}

int worldZDim (void) {
    return (int) WORLD_Z_DIM;
}
