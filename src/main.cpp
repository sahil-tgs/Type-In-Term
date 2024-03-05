// main.cpp
#include "TypingTest.h"
#include <ncurses.h>
#include <cstdlib>
#include <ctime>


int main() {
    srand(time(nullptr)); // Seed random number generator

    int choice;
    bool exitMenu = false;

    // Initialize ncurses
    initscr();
    cbreak(); // Line buffering disabled, Pass on everty thing to me
    noecho(); // Don't echo() while we do getch
    keypad(stdscr, TRUE); // Enable the keypad
    curs_set(0); // Hide the cursor
    mousemask(ALL_MOUSE_EVENTS, nullptr); // Enable mouse events

    // Enable mouse click events
    mouseinterval(0); // No timeout for mouse click events

    while (!exitMenu) {
        clear(); // Clear the screen

        // Print menu options
        printw("TypeInterm - Typing Speed Test\n");
        printw("1. Start Test\n");
        printw("2. Exit\n");
        printw("Enter your choice: ");
        refresh();

        // Get user choice
        MEVENT event;
        int ch = getch();
        if (ch == KEY_MOUSE && getmouse(&event) == OK) {
            if (event.bstate & BUTTON1_CLICKED) {
                if (event.y == 3) {
                    choice = 1;
                } else if (event.y == 4) {
                    choice = 2;
                }
            }
        } else {
            choice = ch - '0'; // Convert char to int
        }

        switch (choice) {
            case 1: {
                TypingTest typingTest;
                typingTest.startTest();
                break;
            }
            case 2: {
                exitMenu = true;
                break;
            }
            default: {
                printw("Invalid choice. Please enter 1 or 2.\n");
                refresh();
                getch(); // Wait for user to press any key
                break;
            }
        }
    }

    // End ncurses
    endwin();

    return 0;
}
