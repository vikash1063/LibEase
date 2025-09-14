#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "../include/Utils.hpp"
#include "../include/User.hpp"
#include "../include/Book.hpp"

#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"

void editProfile_here(string username, string password)
{
    clearScreen();
    int edit_id;
    string new_username;
    string new_password;

    std::cout << ANSI_COLOR_GREEN << "Welcome " << username << "!" << std::endl;
    std::cout << "Edit Username(0), Change Password(1):" << ANSI_COLOR_GREEN << std::endl;
    std::cin >> edit_id;
    int status = edit_id;

    if (status == 0)
    {
        std::cout << "New Username: ";
        std::cin.ignore();
        std::getline(std::cin,new_username);
        replaceSpacesWithDashes(new_username);

        std::ifstream input_file("data/members.csv");
        if (!input_file.is_open())
        {
            std::cout << "Error opening file." << std::endl;
        }

        std::ofstream output_file("data/temp.csv"); // Temporary file for writing

        std::string line;
        while (std::getline(input_file, line))
        {
            std::string token = line.substr(0, line.find(','));
            if (token == username)
            {
                output_file << new_username << "," << password << "\n"; // Write updated data to temporary file
            }
            else
            {
                output_file << line << "\n"; // Copy unchanged data to temporary file
            }
        }

        std::cout<<ANSI_COLOR_GREEN<<"Username has been updated sucessfully \n"<<ANSI_COLOR_RESET;

        // Close both input and output files
        input_file.close();
        output_file.close();

        // Remove the original file and rename the temporary file
        if (std::remove("data/members.csv") != 0)
        {
            std::cout << "Error deleting file." << std::endl;
        }
        if (std::rename("data/temp.csv", "data/members.csv") != 0)
        {
            std::cout << "Error renaming file." << std::endl;
        }
    }

    else if (status == 1)
    {
        std::cout << "New Password: " << std::endl;
        std::cin.ignore();
        std::getline(std::cin,new_password);
        replaceSpacesWithDashes(new_password);

        string confirm_password;

        std::cout << "Confirm New Password: " << std::endl;
        std::getline(std::cin,confirm_password);
        replaceSpacesWithDashes(confirm_password);

        if (new_password!=confirm_password)
        {
            std::cout << ANSI_COLOR_RED << "Passwords do not match. Do you want to go to Main Menu? (Y)" << ANSI_COLOR_RESET << std::endl;
            char in;
            cin >> in;
            if (in == 'Y' || in == 'y')
            {
                clearScreen();
                printBanner();
                menuBar();
                prompt();
            }
            else
            {
                clearScreen();
                editProfile_here(username, password);
            }
        }

        else
        {
            rot13algorithm(new_password);

            std::ifstream input_file("data/members.csv");
            if (!input_file.is_open())
            {
                std::cout << "Error opening file." << std::endl;
            }

            std::ofstream output_file("data/temp.csv"); // Temporary file for writing

            std::string line;
            while (std::getline(input_file, line))
            {
                std::string token = line.substr(0, line.find(','));
                if (token == username)
                {
                    output_file << username << "," << new_password << "\n"; // Write updated data to temporary file
                }
                else
                {
                    output_file << line << "\n"; // Copy unchanged data to temporary file
                }
            }

            // Close both input and output files
            input_file.close();
            output_file.close();

            // Remove the original file and rename the temporary file
            if (std::remove("data/members.csv") != 0)
            {
                std::cout << "Error deleting file." << std::endl;
            }
            if (std::rename("data/temp.csv", "data/members.csv") != 0)
            {
                std::cout << "Error renaming file." << std::endl;
            }

             std::cout<<ANSI_COLOR_GREEN<<"Password has been updated sucessfully \n"<<ANSI_COLOR_RESET;
        }
    }
    else
    {
        std::cout << ANSI_COLOR_RED << "Incorrect code for edit. Do you want to go to Main Menu? (Y)" << ANSI_COLOR_RESET << std::endl;
        char in;
        cin >> in;
        if (in == 'Y' || in == 'y')
        {
            clearScreen();
            printBanner();
            menuBar();
            prompt();
        }
        else
        {
            clearScreen();
            editProfile_here(username, password);
        }
    }
}

void User::editProfile()
{
    clearScreen();
    std::cout << ANSI_COLOR_GREEN "-----------Library Management System-----------\n";
    std::cout << "\n------------------Edit Profile------------------\n" ANSI_COLOR_RESET;
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
        if (mem.name==username && mem.password==password)
        {
            flag = 1;
        }
    }
    fp.close();
    if (flag == 1)
        editProfile_here(username, password);
    else
        std::cout << ANSI_COLOR_RED << "Incorrect Credentials!" << ANSI_COLOR_RESET << std::endl;

    std::cout << ANSI_COLOR_GREEN "\nEnter [Y] to Continue OR [N] to go to Main Menu \n>" ANSI_COLOR_RESET;

    char inputEdit;
    std::cin >> inputEdit;

    if (inputEdit == 'Y' || inputEdit == 'y')
    {
        editProfile();
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
