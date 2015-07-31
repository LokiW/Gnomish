
#ifndef __VIEW_H__
#define __VIEW_H__

/*
 * Update display. Will redraw player and
 * world information.
 */
void display (void);

/*
 * Redraw world when window is resized.
 */
void reshape (int x, int y);

/*
 * Initialize drawing information.
 * TODO move some of this to main.c to decouple
 * controller and view more
 */
void initialize (int argc, char **argv);

/*
 * Draw's background based on world data in model.
 */
void drawWorld (void);

#endif
