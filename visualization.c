#include <stdio.h>
#include "visualization.h"
#include "control.h"

// Function to draw a rectangle on the matrix
void print_rectangle(char matrix[25][80], Rectangle rect){
    for(int i = 0; i < rect.h; i++){
        for(int j = 0; j < rect.w; j++){
            int y = 25 - (rect.y + i);
            int x = rect.x + j - 1;
            if(i == 0 || i == rect.h - 1 || j == 0 || j == rect.w - 1){
                matrix[y][x] = 'X'; // Rectangle border
            } else{
                matrix[y][x] = '0'; // Rectangle interior
            }
        }
    }
}

// Function to print the matrix
void print_matrix(char matrix[25][80]){
    for(int x = 0; x < 25; x++){
        printf("|");
        for (int y = 0; y < 80; y++){
            printf("%c", matrix[x][y]);  // Can be empty (' '), 'X' (border), or '0' (inside)
        }
        printf("|\n");
    }
    for(int i = 0; i < 82; i++){
        printf("T"); // Just to create a base line
    }
    printf("\n");
}

// Function to handle and display error messages
void error_dealing(int error){
    switch (error){
        case 1:
            printf("Error: Invalid command.\n");
            break;
        case 2:
            printf("Error: Invalid command format.\n");
            break;
        case 3:
            printf("Error: Invalid coordinates or dimensions.\n");
            break;
        case 4:
            printf("Error: Space already occupied by another rectangle.\n");
            break;
        case 5:
            printf("Error: Memory allocation failed.\n");
            break;
        case 6:
            printf("Error: Invalid merge operation.\n");
            break;
        case 7:
            printf("Error: Invalid movement.\n");
            break;
    }
}

// Function to print a merge possibility alert
void merge_alert(){
    printf("Merge possible!\n");
}
