#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "analysis.h"

// Function to identify the type of command
int identify_command(char *command){
    if(strncmp(command, "create ", 7) == 0){
        return 1;
    } else if(strncmp(command, "moveright ", 10) == 0){
        return 2;
    } else if(strncmp(command, "moveleft ", 9) == 0){
        return 3;
    } else if(strncmp(command, "merge ", 6) == 0){
        return 4;
    } else{
        return 5; // Invalid command
    }
}

// Function to evaluate the "create" command
int command_create(char *command, Rectangle *newRectangle){
    int x, y, w, h;
    // Extract the coordinates and dimensions
    if(sscanf(command + 7, "%d,%d+%d,%d", &x, &y, &w, &h) != 4){
        return 2; // Incorrect format
    }
    newRectangle->x = x;
    newRectangle->y = y;
    newRectangle->w = w;
    newRectangle->h = h;
    return 0; // Success
}

// Function to evaluate the "moveright" command
int command_moveright(char *command, Rectangle *movRectangle, int *p){
    int x, y;
    // Extract the coordinates and movement distance
    if(sscanf(command + 10, "%d,%d+%d", &x, &y, p) != 3){
        return 2; // Incorrect format
    }
    movRectangle->x = x;
    movRectangle->y = y;
    movRectangle->w = 0;
    movRectangle->h = 0;
    return 0; // Success
}

// Function to evaluate the "moveleft" command
int command_moveleft(char *command, Rectangle *movRectangle, int *p){
    int x, y;
    // Extract the coordinates and movement distance
    if(sscanf(command + 9, "%d,%d+%d", &x, &y, p) != 3){
        return 2; // Incorrect format
    }
    movRectangle->x = x;
    movRectangle->y = y;
    movRectangle->w = 0;
    movRectangle->h = 0;
    return 0; // Success
}

// Function to evaluate the "merge" command
int command_merge(char *command, Rectangle *r1, Rectangle *r2){
    int x1, y1, x2, y2;
    // Extract the coordinates of the first and second rectangles to be merged
    if(sscanf(command + 6, "%d,%d+%d,%d", &x1, &y1, &x2, &y2) !=4){
        return 1;
    } 
    r1->x = x1;
    r1->y = y1;
    r2->x = x2;
    r2->y = y2;
    return  0; // Success
}

// Function to verify the validity of the command
int verify_command(Rectangle newRectangle, char matrix[25][80]){
    // Check if the coordinates and dimensions are within the matrix limits
    if(newRectangle.x < 1 || newRectangle.x + newRectangle.w - 1 > 80 || 
        newRectangle.y < 1 || newRectangle.y + newRectangle.h - 1 > 25){
        return 3; // Invalid coordinates or dimensions
    }

    // Check if there is an overlap with another rectangle
    for(int i = 0; i < newRectangle.h; i++){
        for (int j = 0; j < newRectangle.w; j++){
            int y = 25 - (newRectangle.y + i);
            int x = newRectangle.x + j - 1;
            if(matrix[y][x] != ' '){
                return 4; // Space already occupied
            }
        }
    }

    return 0; // Success
}
