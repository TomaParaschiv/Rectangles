#include <stdio.h>
#include <string.h>
#include "analysis.h"
#include "control.h"
#include "visualization.h"

// Function declarations for testing
void test_identify_command();
void test_command_create();
void test_command_moveright();
void test_command_moveleft();
void test_command_merge();
void test_verify_command();

void test_identify_command() {
    char validCommand[] = "create 10,15+5,6";
    char invalidCommand[] = "invalid 10,15+5,6";

    int result = identify_command(validCommand);
    if (result == 1) {
        printf("identify_command Valid Test - Success\n");
    } else {
        printf("identify_command Valid Test - Failed\n");
    }

    result = identify_command(invalidCommand);
    if (result == 5) {
        printf("identify_command Invalid Test - Success\n");
    } else {
        printf("identify_command Invalid Test - Failed\n");
    }
}

void test_command_create() {
    char validCommand[] = "create 10,15+5,6";
    char invalidCommand[] = "create 20,20+10";

    Rectangle rect;

    int result = command_create(validCommand, &rect);
    if (result == 0) {
        printf("command_create Valid Test - Success: x=%d, y=%d, w=%d, h=%d\n", rect.x, rect.y, rect.w, rect.h);
    } else {
        printf("command_create Valid Test - Failed\n");
    }

    result = command_create(invalidCommand, &rect);
    if (result == 2) {
        printf("command_create Invalid Test - Success: Invalid command detected\n");
    } else {
        printf("command_create Invalid Test - Failed\n");
    }
}

void test_command_moveright() {
    char validCommand[] = "moveright 10,15+5";
    char invalidCommand[] = "moveright 20,20";

    Rectangle rect;
    int p;

    int result = command_moveright(validCommand, &rect, &p);
    if (result == 0) {
        printf("command_moveright Valid Test - Success: x=%d, y=%d, p=%d\n", rect.x, rect.y, p);
    } else {
        printf("command_moveright Valid Test - Failed\n");
    }

    result = command_moveright(invalidCommand, &rect, &p);
    if (result == 2) {
        printf("command_moveright Invalid Test - Success: Invalid command detected\n");
    } else {
        printf("command_moveright Invalid Test - Failed\n");
    }
}

void test_command_moveleft() {
    char validCommand[] = "moveleft 10,15+5";
    char invalidCommand[] = "moveleft 20,20";

    Rectangle rect;
    int p;

    int result = command_moveleft(validCommand, &rect, &p);
    if (result == 0) {
        printf("command_moveleft Valid Test - Success: x=%d, y=%d, p=%d\n", rect.x, rect.y, p);
    } else {
        printf("command_moveleft Valid Test - Failed\n");
    }

    result = command_moveleft(invalidCommand, &rect, &p);
    if (result == 2) {
        printf("command_moveleft Invalid Test - Success: Invalid command detected\n");
    } else {
        printf("command_moveleft Invalid Test - Failed\n");
    }
}

void test_command_merge() {
    char validCommand[] = "merge 10,15+5,6";
    char invalidCommand[] = "merge 20,20";

    Rectangle r1, r2;

    int result = command_merge(validCommand, &r1, &r2);
    if (result == 0) {
        printf("command_merge Valid Test - Success: r1=(%d,%d), r2=(%d,%d)\n", r1.x, r1.y, r2.x, r2.y);
    } else {
        printf("command_merge Valid Test - Failed\n");
    }

    result = command_merge(invalidCommand, &r1, &r2);
    if (result == 1) {
        printf("command_merge Invalid Test - Success: Invalid command detected\n");
    } else {
        printf("command_merge Invalid Test - Failed\n");
    }
}

void test_verify_command() {
    char matrix[25][80];
    create_matrix(matrix);

    Rectangle validRectangle = {10, 15, 5, 6};
    Rectangle invalidRectangle = {100, 150, 5, 6}; // Out of bounds

    int result = verify_command(validRectangle, matrix);
    if (result == 0) {
        printf("verify_command Valid Test - Success\n");
    } else {
        printf("verify_command Valid Test - Failed\n");
    }

    result = verify_command(invalidRectangle, matrix);
    if (result == 3) {
        printf("verify_command Invalid Test - Success: Invalid coordinates detected\n");
    } else {
        printf("verify_command Invalid Test - Failed\n");
    }
}

int main() {
    test_identify_command();
    test_command_create();
    test_command_moveright();
    test_command_moveleft();
    test_command_merge();
    test_verify_command();

    return 0;
}
