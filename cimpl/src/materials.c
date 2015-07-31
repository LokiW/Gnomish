

#include "materials.h"
#include "stdio.h"

#define NUM_MATERIALS 5

material matter_def[NUM_MATERIALS];

void loadMaterials (void) {
    //TODO: Load values from a file
    material dirt;
    dirt.r = 160.0/255.0;
    dirt.g = 100.0/255.0;
    dirt.b = 50.0/255.0;
    dirt.name = "dirt";
    matter_def[0] = dirt;

    material rock;
    rock.r = 120.0/255.0;
    rock.g = 120.0/255.0;
    rock.b = 120.0/255.0;
    rock.name = "rock";
    matter_def[1] = rock;

    material plant;
    plant.r = 30.0/255.0;
    plant.g = 150.0/255.0;
    plant.b = 30.0/255.0;
    plant.name = "plant";
    matter_def[2] = plant;

    material water;
    water.r = 0;
    water.g = 0;
    water.b = 255.0/255.0;
    water.name = "water";
    matter_def[3] = water;

}

material getMaterial (voxel id) {
    if (id.id > NUM_MATERIALS) {
        printf("Error: voxel with id %d greater than number of materials: %d", id.id, NUM_MATERIALS);
    }

    return matter_def[id.id];
}

