// TypingTest.h
#ifndef TYPINGTEST_H
#define TYPINGTEST_H

#include <string>
#include <vector>

class TypingTest {
public:
    TypingTest();
    ~TypingTest();

    void startTest();

private:
    std::vector<std::string> generateRandomWords(int count);
    double calculateAccuracy(const std::string& original, const std::string& typed);
    double calculateWPM(int wordsTyped, double elapsedTime);
};

#endif
