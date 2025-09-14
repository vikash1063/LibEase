#ifndef Book_hpp
#define Book_hpp

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Book
{
private:
    unsigned int id;
    std::string title;
    std::string author;
    unsigned int year;
    bool isBorrow;

public:
    Book(unsigned int id, const std::string &title, const std::string &author, unsigned int year, bool isBorrow)
    {
        this->id = id;
        this->title = title;
        this->author = author;
        this->year = year;
        this->isBorrow = isBorrow;
    }
    static int updateBookStatus(int id, int newStatus)
    {
        int flag = 0;
        std::ifstream file_in("../data/books.csv");
        if (!file_in.is_open())
        {
            std::cout << "Error opening file." << std::endl;
            return -1;
        }

        std::ofstream temp_out("../data/temp.csv");
        if (!temp_out.is_open())
        {
            std::cout << "Error creating temporary file." << std::endl;
            file_in.close();
            return -1;
        }

        std::string line;
        while (std::getline(file_in, line))
        {
            std::stringstream ss(line);
            std::string token;
            int currentId;
            std::string bookname, authorname, year;
            int isborrow;

            std::getline(ss, token, ',');
            currentId = std::stoi(token);

            std::getline(ss, bookname, ',');
            std::getline(ss, authorname, ',');
            std::getline(ss, year, ',');
            std::getline(ss, token);
            isborrow = std::stoi(token);
            if (currentId == id && newStatus != isborrow)
            {
                temp_out << currentId << "," << bookname << "," << authorname << "," << year << "," << newStatus << "\n";
                flag = 1;
            }
            else
            {
                temp_out << currentId << "," << bookname << "," << authorname << "," << year << "," << isborrow << "\n";
            }
        }

        file_in.close();
        temp_out.close();

        if (std::remove("../data/books.csv") != 0)
        {
            std::cout << "Error deleting original file. Try changing permission of data using 'mingw32-make change-permission-win' command" << std::endl;
            return -1;
        }

        if (std::rename("../data/temp.csv", "../data/books.csv") != 0)
        {
            std::cout << "Error renaming temporary file. Try changing permission of data using 'mingw32-make change-permission-win'" << std::endl;
            return -1;
        }
        return flag;
    }
    static void addBook();
    static void searchBook();
    void editBook();
    void deleteBook();
    static void displayBooks();

private:
    // Helper function to get the last book ID from the file
    static unsigned int getLastBookID(const std::string &filename);
};

#endif
