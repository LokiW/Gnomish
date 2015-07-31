/*************************
 * User input and state change
 *************************/

#include "controller.h"
#include "model.h"

#include <stdio.h>

void keyPress (unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
            movePlayer(0.1);
            display();
            break;
        case 's':
            movePlayer(-0.1);
            display();
            break;
        case 'd':
            rotatePlayer(-0.1);
            display();
            break;
        case 'a':
            rotatePlayer(0.1);
            display();
            break;
	case ' ':
	    jumpPlayer(1.0,0.1);
	    display();
	    break;
	default:
	    printf("invalid press: %c", key);
	    break;
    }
}
