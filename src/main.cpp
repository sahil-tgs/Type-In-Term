#include "TypingTest.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(nullptr)); // Seed random number generator

    int choice;
    bool exitMenu = false;

    while (!exitMenu) {
        std::cout << "TypeInterm - Typing Speed Test" << std::endl;
        std::cout << "1. Start Test" << std::endl;
        std::cout << "2. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Ignore newline character

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
                std::cout << "Invalid choice. Please enter 1 or 2." << std::endl;
                break;
            }
        }
    }

    return 0;
}
