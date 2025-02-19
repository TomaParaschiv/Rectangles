#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "analysis.h"
#include "control.h"
#include "visualization.h"

int main() {

    Rectangle *rectangles = NULL;  // Dynamic array of rectangles, initially empty
    char matrix[25][80];  // Character matrix with 25 rows and 80 columns
    int size = 0;  // Size of the rectangle array
    int error = 0;  // Error code
    char command[100];  // Buffer to store user commands 

    create_matrix(matrix);  // Initialize the matrix
    Rectangle r1, r2;  // Temporary variables

    printf("Welcome to the World of Rectangles! Please use the following commands:\n");
    printf("create x,y+w,h\nmoveright x,y+p\nmoveleft x,y+p\nmerge x1,y1+x2,y2\n");
    
    while(1){
        printf("Command: ");
        fgets(command, 100, stdin);  // Read user command
        command[strcspn(command, "\n")] = 0;  // Remove newline character
        
        int commandId = identify_command(command);  // Identify the command type
        Rectangle newRectangle;  // New rectangle to be created or moved
        int p;  // Distance to move the rectangle
        
        switch (commandId){
            case 1: // create
                error = command_create(command, &newRectangle);  // Extract parameters from create command
                if(!error){
                    error = verify_command(newRectangle, matrix);  // Check if the rectangle can be added
                }
                if(!error){
                    gravity(matrix, &newRectangle);  // Apply gravity to the rectangle
                    rectangles = add_rectangle(rectangles, &size, newRectangle, &error);  // Add rectangle to the array
                }
                break;

            case 2: // moveright
                error = command_moveright(command, &newRectangle, &p);  // Extract parameters from moveright command
                if(!error){
                    error = moveright(rectangles, size, newRectangle.x, newRectangle.y, p, matrix);  // Move rectangle to the right
                }
                break;

            case 3: // moveleft
                error = command_moveleft(command, &newRectangle, &p);  // Extract parameters from moveleft command
                if(!error){ 
                    error = moveleft(rectangles, size, newRectangle.x, newRectangle.y, p, matrix);  // Move rectangle to the left
                }
                break;

            case 4: // merge
                error = command_merge(command, &r1, &r2);  // Extract parameters from merge command
                if(!error && itself_rectangle(r1, r2)){
                    error = 6;  // Error: invalid merge
                }
                if(!error){
                    merge(rectangles, &size, r1.x, r1.y, r2.x, r2.y, &error); // Merge rectangles r1 and r2
                }
                break;

            default:
                error = 1;  // Invalid command
                break;
        }

        // Apply gravity to all rectangles and redraw the matrix
        create_matrix(matrix);  // Reset the matrix
        for(int i = 0; i < size; i++){
            gravity(matrix, &rectangles[i]);  // Reapply gravity to all rectangles
            print_rectangle(matrix, rectangles[i]);  // Redraw each rectangle
        }

        print_matrix(matrix);  // Print the matrix with rectangles
        
        if(error){
            error_dealing(error);  // Handle errors if any
        } else{
            // Check if there are rectangles with the same x and w (potential merge)
            int r1_index, r2_index;
            if(search_merge_poss(rectangles, size, &r1_index, &r2_index)){
                merge_alert();  // Alert about possible merge
            }
        }
    }

    free(rectangles);  // Free allocated memory for rectangles
    return 0;
}
