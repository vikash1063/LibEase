#ifndef UTILS_HPP
#define UTILS_HPP

void printBanner();
void clearScreen();
void pressEnterToContinue();
void menuBar();
void prompt();
void rot13algorithm(std::string &);
void replaceSpacesWithDashes(std::string &str);
char *stringToCString(const std::string &str);
void charFiller(std::string &info, int spaces);

#endif
