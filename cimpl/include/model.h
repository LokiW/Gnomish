
#include "materials.h"

#ifndef __MODEL_H__
#define __MODEL_H__

/*
 * player struct containing relvant 
 */
typedef struct {
    //center location of player
    float x;
    float y;
    float z;

    // clockwise angle from positive y axis in radians
    float angle;
} player;

/*
 * Initialze player values. 
 * TODO load saved info rather than always setting player
 * to origin.
 */
void initPlayer (void);

/*
 * Get the player. Currently used to get player location,
 * TODO when player is more complicated, make new function
 *  to just get the player location.
 */ 
player getPlayer (void);

/*
 * Rotate player by rad radians clockwise.
 */
void rotatePlayer (float rad);

/*
 * Move player in the direction their facing by
 * the given distance
 * 
 * If the space is invalid, player will move back and/or
 * down to a valid space.
 */
void movePlayer (float distance);

/*
 * Move the player in the direction their facing by
 * the given distance and up by the given height.
 *
 * If the space is invalid, player will move back and/or
 * down to a valid space.
 */
void jumpPlayer (float height, float distance);

/*
 * Initialize world layout.
 */
void initWorld (void);

/*
 * Initialize a random world layout.
 */
void randomWorld (void);

/*
 * Get the material under the player.
 */
material materialAtPlayer (float x, float y, float z);

/*
 * Get the material at the given coordinate.
 */
material materialAtPoint (int x, int y, int z);

/* 
 * Check that given player is in the bounds of loaded world.
 */
char coordinatesInWorld(float x, float y, float z);

/*
 * Get the dimensions of the current loaded world.
 */
int worldXDim (void);
int worldYDim (void);
int worldZDim (void);


#endif
