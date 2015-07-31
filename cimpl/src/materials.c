

#include "materials.h"
#include "stdio.h"

#define NUM_MATERIALS 5

material matter_def[NUM_MATERIALS];

void loadMaterials (void) {
    //TODO: Load values from a file
    //TODO: make sure materials are only loaded once
    material dirt;
    dirt.r = 160.0/255.0;
    dirt.g = 100.0/255.0;
    dirt.b = 50.0/255.0;
    dirt.visibility = 1;
    dirt.name = "dirt";
    matter_def[0] = dirt;

    material rock;
    rock.r = 120.0/255.0;
    rock.g = 120.0/255.0;
    rock.b = 120.0/255.0;
    rock.visibility = 1;
    rock.name = "rock";
    matter_def[1] = rock;

    material plant;
    plant.r = 30.0/255.0;
    plant.g = 150.0/255.0;
    plant.b = 30.0/255.0;
    plant.visibility = 1;
    plant.name = "plant";
    matter_def[2] = plant;

    material water;
    water.r = 0;
    water.g = 0;
    water.b = 255.0/255.0;
    water.visibility = 1;
    water.name = "water";
    matter_def[3] = water;

    material air;
    //TODO figure out transparency
    air.r = 0;
    air.g = 0;
    air.b = 0;
    air.visibility = 0;
    air.name = "air";
    matter_def[4] = air;



}

material getMaterial (voxel id) {
    if (id.id > NUM_MATERIALS) {
	//TODO do real error handling
        printf("Error: voxel with id %d greater than number of materials: %d", id.id, NUM_MATERIALS);
    }

    return matter_def[id.id];
}

char canStack (voxel id) {
    material q = getMaterial (id);
    //TODO make a property or do something else cleverer here
    if (id.id < 3) {
	return 1;
    }
    return 0;
}
