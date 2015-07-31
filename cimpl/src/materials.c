

#include "materials.h"

#define NUM_MATERIALS 5

material matter_def[NUM_MATERIALS];

void loadMaterials (void) {
    //TODO: Load values from a file
    material dirt;
    dirt.r = 160;
    dirt.g = 100;
    dirt.b = 50;

    matter_def[0] = dirt;

    material rock;
    rock.r = 120;
    rock.g = 120;
    rock.b = 120;

    matter_def[1] = rock;

    material plant;
    plant.r = 30;
    plant.g = 150;
    plant.b = 30;

    matter_def[2] = plant;

    material water;
    water.r = 0;
    water.g = 0;
    water.b = 255;
    
    matter_def[3] = water;

}

material getMaterial (voxel id) {
    return matter_def[id.id];
}

