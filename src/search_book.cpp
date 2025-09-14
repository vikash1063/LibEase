#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "../include/Utils.hpp"
#include "../include/Book.hpp"

#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_RESET "\x1b[0m"

void Book::searchBook()
{
    clearScreen();
    std::cout << ANSI_COLOR_GREEN "-----------Library Management System-----------\n";
    std::cout << "\n------------------Search Book------------------\n" ANSI_COLOR_RESET;
    std::string key;
    int flag = 0;
    Book book(0, "", "", 0, false);
    unsigned int borrowInt;

    std::ifstream file("data/books.csv");
    if (!file.is_open())
    {
        std::cout << ANSI_COLOR_RED "Error opening file.\n" ANSI_COLOR_RESET;
        return;
    }

    std::cout << ANSI_COLOR_RED "Make sure to type [-] wherever there are spaces.\n" ANSI_COLOR_RESET;
    std::cout << ANSI_COLOR_GREEN "Enter the book TITLE: \n>" ANSI_COLOR_RESET;
    std::cin >> key;

    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string token;

        std::getline(ss, token, ',');
        book.id = std::stoi(token);

        std::getline(ss, token, ',');
        book.title = token;

        std::getline(ss, token, ',');
        book.author = token;

        std::getline(ss, token, ',');
        book.year = std::stoi(token);

        std::getline(ss, token, ',');
        borrowInt = std::stoi(token);

        if (key == book.title)
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
    {
        std::cout << ANSI_COLOR_BLUE << book.id << "\t" << book.title << "\t\t\t" << book.author << "\t\t\t" << book.year << "\t\t" << (borrowInt ? "Borrowed" : "Not Borrowed") << std::endl;
    }
    else
    {
        std::cout << ANSI_COLOR_RED "Sorry the book that you have searched doesn't exist in this Library:\n" ANSI_COLOR_RESET;
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
        searchBook();
    }

    std::cout << ANSI_COLOR_RESET;
}
