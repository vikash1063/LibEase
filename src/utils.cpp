#include <bits/stdc++.h>

#include "../include/Auth.hpp"
#include "../include/Book.hpp"
#include "../include/User.hpp"

#define COLOR_GREEN "\x1b[32m"
#define COLOR_RED "\x1b[31m"
#define COLOR_RESET "\x1b[0m"
#define COLOR_BLUE "\x1b[34m"


#define ROT 13

void clearScreen()
{
   system("clear");
}


void pressEnterToContinue()
{
   std::cout << "Press Enter to continue . . .";
   std::cin.get();
   return;
}


void printBanner()
{
   
    cout << " #        " << "     " << " #        " << "  ####### " << "         " << "          " << "         " << endl;
    cout << " #        " << "     " << " #        " << "  #       " << "         " << "          " << "         " << endl;
    cout << " #        " << "  #  " << " #        " << "  #       " << "  #####  " << "  ######  " << "  #####  " << endl;
    cout << " #        " << "     " << " #######  " << "  ####    " << "       # " << " #        " << " #     # " << endl;
    cout << " #        " << "  #  " << " #      # " << "  #       " << "  #####  " << "  #####   " << "  #####  " << endl;
    cout << " #        " << "  #  " << " #      # " << "  #       " << " #     # " << "       #  " << " #       " << endl;
    cout << " #######  " << "  #  " << " #######  " << "  ####### " << "  ###### " << " ######   " << "  ###### " << endl;

    cout << COLOR_BLUE <<  "                          Lib Ease    \n"<< COLOR_RESET
              << COLOR_RED "--------------- Developed by Vikash Kumar ---------------\n"
              << COLOR_RESET;

}

void menuBar()
{
   std::cout << "\n";
   std::cout << COLOR_GREEN 
                "{1} -- Add Book\n"
             << "{2} -- Add Member\n"
             << "{3} -- Issue Book\n"
             << "{4} -- Return Book\n"
             << "{5} -- Search Book\n"
             << "{6} -- Search Member\n"
             << "{7} -- Display Books\n"
             << "{8} -- Display Members\n"
             << "{9} -- Edit Profile\n"
             << "{99} -- Exit\n" COLOR_RESET << "\n";
}

void replaceSpacesWithDashes(std::string &str)
{
   for (int i = 0; i < (int)str.length(); i++){
      (str[i] == ' ')?str[i]='-':str[i]=str[i];
   }
}


void charFiller(std::string &info, int spaces)
{
   int currentLength = info.length();
   int fillNumber = spaces - currentLength;

   if (fillNumber > 0)
   {
      for (int i = 0; i < fillNumber; i++)
      {
         info += " ";
      }
   }
}

void prompt()
{
   int input;

   while (1)
   {
      std::cout << "\n"
                << COLOR_GREEN "> " COLOR_RESET;

      std::cin >> input;
      std::cout << "\n";
      switch (input)
      {
      case 99:
         printf(COLOR_RED "LibEase has been terminated. \n" COLOR_RESET);
         exit(0);

      case 1:

         Book::addBook();
         break;

      case 2:
         addMember();
         break;

      case 3:
         User::issueBook();
         break;

      case 4:
         User::returnBook();
         break;

      case 5:
         Book::searchBook();
         break;

      case 6:
         User::searchMember();
         break;

      case 7:
         Book::displayBooks();
         break;

      case 8:
         User::displayMembers();
         break;

      case 9:
         User::editProfile();
         break;

      default:
         std::cout << COLOR_RED "\n Please enter valid  key" COLOR_RESET;

         return;
      }
   }
}


void rot13algorithm(std::string &pwd)
{
   
   for (int i = 0; i < (int)(pwd.size()); i++)
   {
      if (std::isalpha(pwd[i]))
      {
         if ((pwd[i] >= 'a' && pwd[i] <= 'm') || (pwd[i] >= 'A' && pwd[i] <= 'M'))
         {
            pwd[i] += ROT;
         }
         else
         {
            pwd[i] -= ROT;
         }
      }
   }
}

char *stringToCString(const std::string &str)
{
   char *cstr = new char[str.length() + 1];
   std::strcpy(cstr, str.c_str());
   return cstr;
}

