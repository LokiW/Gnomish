
#include "materials.h"

#ifndef __MODEL_H__
#define __MODEL_H__

typedef struct {
    //center location of player
    float x;
    float y;

    // clockwise angle from positive y axis in radians
    float angle;
} player;

void initPlayer (void);
player getPlayer (void);
void rotatePlayer (float rad);
void movePlayer (float distance);

void initWorld (void);
material materialAtPlayer (float x, float y, float z);
material materialAtPoint (int x, int y, int z);
int worldXDim (void);
int worldYDim (void);

#endif
