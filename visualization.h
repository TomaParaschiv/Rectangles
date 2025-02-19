#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include "control.h"

// Function to draw a rectangle on the matrix
void print_rectangle(char matrix[25][80], Rectangle rect);

// Function to print the matrix
void print_matrix(char matrix[25][80]);

// Function to handle and display error messages
void error_dealing(int error);

// Function to print a merge possibility alert
void merge_alert();

#endif
