#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "../include/User.hpp"
#include "../include/Book.hpp"
#include "../include/Utils.hpp"

#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_RESET "\x1b[0m"

void Book::displayBooks()
{
    clearScreen();
    std::cout << ANSI_COLOR_GREEN "-----------Library Management System-----------\n";
    std::cout << "\n------------------Display Books------------------\n" ANSI_COLOR_RESET;

    std::ifstream file("data/books.csv");
    if (!file.is_open())
    {
        std::cout << ANSI_COLOR_RED "Error opening file.\n" ANSI_COLOR_RESET;
        return;
    }
    else
    {
        std::cout << "\nID\tTitle\t\t\t\t\tAuthor\t\t\tYear\t\tBorrowed\n";
    }

    std::cout << ANSI_COLOR_BLUE;
    std::string line;
    while (std::getline(file, line))
    {
        std::vector<std::string> tokens;
        std::stringstream ss(line);
        std::string token;
        while (std::getline(ss, token, ','))
        {
            tokens.push_back(token);
        }

        if (tokens.size() != 5)
        {
            std::cout << "Invalid data format in file.\n";
            continue;
        }

        unsigned int id = std::stoi(tokens[0]);
        std::string title = tokens[1];
        std::string author = tokens[2];
        unsigned int year = std::stoi(tokens[3]);
        bool isBorrow = (tokens[4] == "1");

        charFiller(title, 20);
        charFiller(author, 20);

        std::cout << id << "\t" << title << "\t\t" << author << "\t\t" << year << "\t\t" << (isBorrow ? "Yes" : "No") << std::endl;
    }
    std::cout << ANSI_COLOR_RESET;
    std::cout << "\n";
    file.close();

    char input;
    std::cout << ANSI_COLOR_GREEN "\n\nType [Y] to go to main menu\n>" ANSI_COLOR_RESET;
    std::cin >> input;

    if (input == 'Y' || input == 'y')
    {
        clearScreen();
        printBanner();
        menuBar();
        prompt();
    }
    else
    {
        clearScreen();
        displayBooks();
    }
}
