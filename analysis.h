#ifndef ANALYSIS_H
#define ANALYSIS_H

#include "control.h"

int identify_command(char *command);

int command_create(char *command, Rectangle *newRectangle);

int command_moveright(char *command, Rectangle *movRectangle, int *p);

int command_moveleft(char *command, Rectangle *movRectangle, int *p);

int command_merge(char *command, Rectangle *r1, Rectangle *r2);

int verify_command(Rectangle newRectangle, char matrix[25][80]);

#endif
