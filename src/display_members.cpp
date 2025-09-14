#include <iostream>
#include <fstream>
#include <string>

#include "../include/Utils.hpp"
#include "../include/User.hpp"

#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"

void User::displayMembers()
{
    clearScreen();
    std::cout << ANSI_COLOR_GREEN "-----------Library Management System-----------\n";
    std::cout << "\n------------------Display Members------------------\n";

    std::ifstream file("data/members.csv");
    if (!file.is_open())
    {
        std::cout << ANSI_COLOR_RED "Error opening file.\n" ANSI_COLOR_RESET;
        return;
    }

    std::string line;
    int memberCount = 0;
    std::string members[500];

    while (std::getline(file, line))
    {
        std::string token = line.substr(0, line.find(','));
        members[memberCount++] = token;
    }

    file.close();

    for (int i = 0; i < memberCount; i++)
    {
        std::cout << ANSI_COLOR_GREEN "Member: " << members[i] << "\n" ANSI_COLOR_RESET;
    }

    std::cout << "\n";
    std::cout << ANSI_COLOR_GREEN "\nEnter [Y] to Continue OR [N] to go to Main Menu \n>" ANSI_COLOR_RESET;

    char input;
    std::cin >> input;

    if (input == 'Y' || input == 'y')
    {
        displayMembers();
    }
    else
    {
        clearScreen();
        printBanner();
        menuBar();
        prompt();
    }

    std::cout << ANSI_COLOR_RESET;
}
