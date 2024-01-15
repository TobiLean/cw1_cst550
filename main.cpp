#include <iostream>
#include <vector>
#include <ctime>
#include "member.h"
#include "librarian.h"
#include "book.h"
#include "date.h"

/*
  cw1.cpp
  author: M00885480
  created: 08/01/2024
  updated: 08/01/2024
*/

std::string calcDueDate(int numOfDays)
{
  int timeInSeconds = numOfDays * 24 * 60 * 60;

  time_t now = time(0);
  now = now + timeInSeconds;
  char *formatedTime = ctime(&now);

  return formatedTime;
};

int main()
{

  // Date date1(15,1,2024);
  // Date date2(14,1,2024);

  // if(date1 < date2)
  // {
  //   std::cout << "date 2 is greater than date 1";
  // }
  // else
  // {
  //   std::cout << "date 1 is greater than date 2";
  // }

  std::string option;
  std::string tempName;
  std::string tempAddress;
  std::string tempEmail;

  std::cout << "please enter option: (Librarian - l)(quit program - q)" << '\n';
  std::cin >> option;

  if (option == "l")
  {
    std::cout << "please enter Librarian name: ";
    std::cin >> tempName;
    std::cout << "please enter Librarian address: ";
    std::cin >> tempAddress;
    std::cout << "please enter Librarian email: ";
    std::cin >> tempEmail;

    Librarian librarianObj(1, tempName, tempAddress, tempEmail, 50);

    librarianObj.getName();
    librarianObj.getAddress();
    librarianObj.getEmail();
    librarianObj.getSalary();

    do
    {
      std::cout << '\n'
                << "----------" << '\n'
                << "Do you want to create a new member? (input m)" << '\n';
      std::cout << "Do you want to quit program? (input q)" << '\n';
      std::cin >> option;

      if (option == "m")
      {
        int tempMemID;
        int tempBookID;
        std::string issueBookOpt;
        std::string returnBookOpt;
        std::string displayBookOpt;
        librarianObj.addMember();

        do
        {

            std::cout << "Do you want to add a book? (y/n) ";
            std::cin >> issueBookOpt;

          if (issueBookOpt != "n")
          {
            std::cout << "Please enter member ID to issue book (must be a number): ";
            std::cin >> tempMemID;
            std::cout << "Please enter book ID (must be a number): ";
            std::cin >> tempBookID;
            librarianObj.issueBook(tempMemID, tempBookID);
          }
          else
          {
            issueBookOpt = "n";
          }

        } while (issueBookOpt != "n");

        do
        {

          std::cout << "Do you want to return a book? (y/n) ";
          std::cin >> returnBookOpt;

          if (returnBookOpt != "n")
          {
          std::cout << "Please enter member ID to return book (must be a number): ";
          std::cin >> tempMemID;
          std::cout << "Please enter book ID (must be a number): ";
          std::cin >> tempBookID;
          librarianObj.returnBook(tempMemID, tempBookID);
          }
          else
          {
            returnBookOpt = "n";
          }
          
          
        } while (returnBookOpt != "n");

        do
        {

          std::cout << "Do you want to display all books? (y/n) ";
          std::cin >> displayBookOpt;

          if (displayBookOpt != "n")
          {
          std::cout << "Please enter member ID to display book (must be a number): ";
          std::cin >> tempMemID;
          librarianObj.displayBorrowedBooks(tempMemID);
          std::cout << '\n';
          }
          else
          {
            displayBookOpt = "n";
          }
          
          
        } while (displayBookOpt != "n");
      }

      // std::cout << calcDueDate(10);

    } while (option != "q");
    std::cout << "application end!";
    return 0;
  }
  else
  {
    std::cout << "application end!";
    return 0;
  }
}
