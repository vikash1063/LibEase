#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cstring>

#include "../include/Utils.hpp"
#include "../include/User.hpp"
#include "../include/Book.hpp"

#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"


void returnBookHere()
{
    int book_id;

    std::cout << "Enter the book id that you want to return :" << std::endl;
    std::cin >> book_id;
    int status = Book::updateBookStatus(book_id, 0);
    if (status == 1)
    {
        std::cout << "Book with ID " << book_id << " has been returned successfully." << std::endl;
    }
    else if (status == 0)
    {
        std::cout << "Book with ID " << book_id << " is already returned." << std::endl;
    }
    else
    {
        std::cout << "Book with ID " << book_id << " does not exist." << std::endl;
    }
}

void User::returnBook()
{
    clearScreen();
    std::cout << ANSI_COLOR_GREEN "-----------Library Management System-----------\n";
    std::cout << "\n------------------Issue Book------------------\n" ANSI_COLOR_RESET;
    int flag = 0;
    User mem("", "");
    string username, password;
    std::cout << ANSI_COLOR_GREEN "Enter the username:" ANSI_COLOR_RESET;
    std::cin.ignore();
    std::getline(std::cin,username);
    replaceSpacesWithDashes(username);
    std::cout << ANSI_COLOR_GREEN "Enter the password:" ANSI_COLOR_RESET;
    std::getline(std::cin,password);
    replaceSpacesWithDashes(password);
    rot13algorithm(password);

    std::ifstream fp("data/members.csv");
    if (!fp.is_open())
    {
        std::cout << "Error, the file doesnot exist" << std::endl;
    }

    std::string line;
    while (std::getline(fp, line))
    {
        std::istringstream iss(line);
        std::getline(iss, mem.name, ',');
        std::getline(iss, mem.password);
        cout << mem.name << " " << mem.password << endl;
        if (mem.name== username && mem.password== password)
        {
            flag = 1;
            break;
        }
    }
    fp.close();

    if (flag == 1)
        returnBookHere();
    else
        std::cout << "Sorry you're not registered yet:" << std::endl;

    std::cout << ANSI_COLOR_GREEN "\nEnter [Y] to Continue OR [N] to go to Main Menu \n>" ANSI_COLOR_RESET;

    char inputBook;
    std::cin >> inputBook;

    if (inputBook == 'Y' || inputBook == 'y')
    {
        returnBook();
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
