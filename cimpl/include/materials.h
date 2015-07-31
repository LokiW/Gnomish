

#ifndef __MATERIALS_H__
#define __MATERIALS_H__

/*
 * A voxel is an instance of a material. It should be
 * kept small as it will be used often, but also have
 * instance information that isn't generic to the material
 * as a whole but just this peice, like "on fire".
 */
typedef struct {
    unsigned char id;
} voxel;

/*
 * A type for materials, such as dirt, rock, ect.., 
 */
typedef struct {
    //For printing purposes
    char *name;

    //Color
    float r,g,b;
} material;

/*
 * Load all the different materials for the current world.
 * In the future will load these from a file, but currently
 * just uses hardcoded materials.
 */
void loadMaterials (void);

/*
 * Get the material of the given voxel.
 */
material getMaterial (voxel id);


#endif
