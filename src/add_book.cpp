#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "../include/Book.hpp"
#include "../include/Utils.hpp"

#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_BLUE "\x1b[34m"

void Book::addBook()
{
    std::cout << ANSI_COLOR_GREEN << "-----------Library Management System-----------" << std::endl;
    std::cout << "\n------------------Add Book---------------------" << ANSI_COLOR_RESET << std::endl;

    Book book(0, "", "", 0, false);

    std::cin.ignore();
    std::cout << "Enter the book TITLE: ";
    std::getline(std::cin, book.title);
    replaceSpacesWithDashes(book.title);

    std::cout << "Enter the book AUTHOR: ";
    std::getline(std::cin, book.author);
    replaceSpacesWithDashes(book.author);

    std::cout << "Enter the book YEAR: ";
    std::cin >> book.year;

    unsigned int lastId = getLastBookID("data/books.csv");
    book.id = lastId + 1;
    book.isBorrow = false;

    std::ofstream file("data/books.csv", std::ios::app);
    if (!file.is_open())
    {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    file << book.id << ',' << book.title << ',' << book.author << ',' << book.year << ',' << book.isBorrow << '\n';
    file.close();

    std::cout << "Book added with ID: " << book.id << std::endl;

    char inputBook;
    std::cout << "\nEnter [Y] to Continue OR [N] to go to Main Menu: ";
    std::cin >> inputBook;

    if (inputBook == 'Y' || inputBook == 'y')
    {
        addBook();
    }
    else
    {
        clearScreen();
        printBanner();
        menuBar();
        prompt();
    }
}

unsigned int Book::getLastBookID(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        return 0;
    }

    std::string line;
    unsigned int lastId = 0;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string token;
        std::getline(iss, token, ',');
        unsigned int id = std::stoi(token);
        lastId = std::max(lastId, id);
    }
    file.close();
    return lastId;
}
