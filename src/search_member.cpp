#include <iostream>
#include <fstream>
#include <string>

#include "../include/Utils.hpp"
#include "../include/User.hpp"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_RESET "\x1b[0m"

void User::searchMember()
{
    clearScreen();
    std::cout << ANSI_COLOR_GREEN "-----------Library Management System-----------\n";
    std::cout << "\n------------------Search Member------------------\n" ANSI_COLOR_RESET;

    std::string key;
    int flag = 0;
    std::ifstream file("data/members.csv");
    if (!file.is_open())
    {
        std::cout << ANSI_COLOR_RED "Error opening file.\n" ANSI_COLOR_RESET;
        return;
    }
     std::cout << ANSI_COLOR_RED "Make sure to type [-] wherever there are spaces.\n" ANSI_COLOR_RESET;
    std::cout << ANSI_COLOR_GREEN "Enter the username: \n>";
    std::cin >> key;

    std::string line;
    while (std::getline(file, line))
    {
        std::string token = line.substr(0, line.find(','));
        if (token == key)
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
    {
        std::cout << ANSI_COLOR_GREEN "User Exists\n" ANSI_COLOR_RESET;
    }
    else
    {
        std::cout << ANSI_COLOR_RED "User Doesn't Exist:\n" ANSI_COLOR_RESET;
    }

    std::cout << ANSI_COLOR_BLUE "\nEnter [Y] to Continue OR [N] to go to Main Menu \n>" ANSI_COLOR_RESET;

    char continueSearch;
    std::cin >> continueSearch;

    if (continueSearch == 'N' || continueSearch == 'n')
    {
        clearScreen();
        printBanner();
        menuBar();
        prompt();
    }
    else
    {
        searchMember();
    }

    std::cout << ANSI_COLOR_RESET;
}
