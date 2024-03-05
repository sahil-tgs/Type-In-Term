// TypingTest.cpp
#include "TypingTest.h"
#include <ncurses.h>
#include <iostream>
#include <chrono>

TypingTest::TypingTest() {}

TypingTest::~TypingTest() {}

void TypingTest::startTest() {
    // Generate random number of words to type (between 30 to 55)
    int numWords = rand() % 26 + 30;
    std::vector<std::string> targetWords = generateRandomWords(numWords);

    // Display instructions
    clear(); // Clear the screen
    printw("Type the following words:\n");
    for (const auto& word : targetWords) {
        printw("%s ", word.c_str());
    }
    printw("\n");
    refresh();

    // Start timer
    auto startTime = std::chrono::steady_clock::now();

    // Get user input
    std::string userInput;
    char c;
    while ((c = getch()) != '\n') {
        userInput += c;
    }

    // End timer
    auto endTime = std::chrono::steady_clock::now();
    double elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() / 1000.0;

    // Calculate accuracy and WPM
    double accuracy = calculateAccuracy(targetWords[0], userInput); // Accuracy for the first word
    double wpm = calculateWPM(1, elapsedTime);

    // Display results
    printw("Time taken: %.2f seconds\n", elapsedTime);
    printw("Accuracy: %.2f%%\n", accuracy);
    printw("Words per minute: %.2f\n", wpm);
    refresh();
    getch(); // Wait for user to press any key before exiting
}

std::vector<std::string> TypingTest::generateRandomWords(int count) {
    std::vector<std::string> words;
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

    int rareWordIndex = rand() % count;

    for (int i = 0; i < count; ++i) {
        std::string word;
        int wordLength = 1 + (rand() % 7); // Random word length between 1 to 7 characters

        // Generate a rare 7-letter word if the current index matches the rare word index
        if (i == rareWordIndex) {
            wordLength = 7;
        } else {
            // Randomly assign word length with probability of 3 to 4
            int randNum = rand() % 10;
            if (randNum < 3) {
                wordLength = 3;
            } else if (randNum > 6) {
                wordLength = 4;
            }
        }

        // Generate word
        for (int j = 0; j < wordLength; ++j) {
            word += alphabet[rand() % alphabet.length()];
        }

        // Add word to vector
        words.push_back(word);
    }

    return words;
}

double TypingTest::calculateAccuracy(const std::string& original, const std::string& typed) {
    int correctChars = 0;
    for (size_t i = 0; i < original.length(); ++i) {
        if (original[i] == typed[i]) {
            correctChars++;
        }
    }
    return (static_cast<double>(correctChars) / original.length()) * 100.0;
}

double TypingTest::calculateWPM(int wordsTyped, double elapsedTime) {
    double minutes = elapsedTime / 60.0;
    return wordsTyped / minutes;
}
