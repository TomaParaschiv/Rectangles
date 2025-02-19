#ifndef CONTROL_H
#define CONTROL_H

// Rectangle structure
typedef struct {
    int x, y; // X-coordinate, Y-coordinate
    int w, h; // Width, Height
} Rectangle;
    
void create_matrix(char matrix[25][80]);

Rectangle* add_rectangle(Rectangle *rectangles, int *size, Rectangle newRectangle, int *error);

void gravity(char matrix[25][80], Rectangle *rect);

int coord_belong_rectangle(int x, int y, Rectangle rect);

int moveright(Rectangle *rectangles, int size, int x, int y, int p, char matrix[25][80]);

int moveleft(Rectangle *rectangles, int size, int x, int y, int p, char matrix[25][80]);

int search_merge_poss(Rectangle *rectangles, int size, int *r1_index, int *r2_index);

void merge(Rectangle *rectangles, int *size, int r1_x, int r1_y, int r2_x, int r2_y, int *error);

int itself_rectangle(Rectangle r1, Rectangle r2);

#endif
