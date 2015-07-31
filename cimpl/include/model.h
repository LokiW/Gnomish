
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
 */
void movePlayer (float distance);


/*
 * Initialize world layout.
 */
void initWorld (void);

/*
 * Get the material under the player.
 */
material materialAtPlayer (float x, float y, float z);

/*
 * Get the material at the given coordinate.
 */
material materialAtPoint (int x, int y, int z);

/*
 * Get the dimensions of the current loaded world.
 */
int worldXDim (void);
int worldYDim (void);

#endif
