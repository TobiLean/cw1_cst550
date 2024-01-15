#include <iostream>
#include <vector>
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

int main()
{

  std::string option;
  std::string tempName;
  std::string tempAddress;
  std::string tempEmail;

  std::cout << "please enter option: (Librarian - l)(quit program - q)" << '\n';
  std::cin >> option;

  //option to create a new Librarian.
  if (option == "l")
  {
    std::cout << "please enter Librarian name: ";
    std::cin >> tempName;
    std::cout << "please enter Librarian address: ";
    std::cin >> tempAddress;
    std::cout << "please enter Librarian email: ";
    std::cin >> tempEmail;

    Librarian librarianObj(1, tempName, tempAddress, tempEmail, 50);
    std::cout << "----------";

    librarianObj.getName();
    librarianObj.getAddress();
    librarianObj.getEmail();
    librarianObj.getSalary();

    //loop through program until the user quits the system
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

        //option to add a book by calling the issueBook function from the librarian class
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
            std::cout << "----------";
          }
          else
          {
            issueBookOpt = "n";
          }

        } while (issueBookOpt != "n");

        //option to return a specific book using the returnBook function from the Librarian class
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
            std::cout << "----------";
          }
          else
          {
            returnBookOpt = "n";
          }

        } while (returnBookOpt != "n");

        //option to display all the books of a particular member
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
            std::cout << "----------";
          }
          else
          {
            displayBookOpt = "n";
          }

        } while (displayBookOpt != "n");
      }

    } while (option != "q");
    std::cout << "application end!";
    return 0;
  }
  else
  {
    //quit application
    std::cout << "application end!";
    return 0;
  }
}
