#include <iostream>
#include <fstream>
#include <cstring>
#include "../include/Utils.hpp"
#include "../include/User.hpp"

#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_BLUE "\x1b[34m"

#define ROT 13

void addMemberBanner();
void addMemberMenu();
void rot13algorithm(string &);

void addMember()
{
    clearScreen();
    addMemberBanner();
    addMemberMenu();
}

void addMemberBanner()
{
    std::cout << ANSI_COLOR_GREEN << "-----------Library Management System-----------\n";
    std::cout << "\n------------------Add Member---------------------\n"
              << ANSI_COLOR_RESET;
}

void User::addUser(std::string &name, std::string &password)
{
    name = name;
    password = password;

    std::ofstream file("data/members.csv", std::ios::app);
    if (file.is_open())
    {
        file << name << "," << password << "\n";
        file.close();
        std::cout << ANSI_COLOR_GREEN << "Member added to members.csv file.\n"
                  << ANSI_COLOR_RESET;
    }
    else
    {
        std::cout << ANSI_COLOR_RED << "Error: Unable to open file.\n"
                  << ANSI_COLOR_RESET;
    }
}

void addMemberMenu()
{
    string username, password, confirmPassword;
    std::cout << "\n"
              << ANSI_COLOR_GREEN << "Enter your username:\n> ";
    std::cin.ignore();
    std::getline(std::cin, username);
    replaceSpacesWithDashes(username);

    std::cout << "Enter your password:\n> ";
    std::getline(std::cin, password);
    replaceSpacesWithDashes(password);

    std::cout << "\nConfirm your password:\n> ";
    std::getline(std::cin, confirmPassword);
    replaceSpacesWithDashes(confirmPassword);
    std::cout << "\n";

    rot13algorithm(password);
    rot13algorithm(confirmPassword);
    if (password!=confirmPassword)
    {
        std::cout << ANSI_COLOR_RED << "Passwords did not match!\n"
                  << ANSI_COLOR_RESET;
        addMemberMenu();
    }
    else
    {
        User::addUser(username, password);
    }

    std::cout << ANSI_COLOR_GREEN << "\nEnter [Y] to add new member again OR [N] to go to Main Menu \n> " << ANSI_COLOR_RESET;

    char inputMember;
    std::cin >> inputMember;

    if (inputMember == 'Y' || inputMember == 'y')
    {
        addMemberMenu();
    }
    else
    {
        clearScreen();
        printBanner();
        menuBar();
        prompt();
    }
    std::cout << "\n";
}
