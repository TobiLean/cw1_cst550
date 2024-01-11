#include <iostream>
#include <vector>
#include <ctime>
#include "member.h"
#include "librarian.h"
#include "book.h"

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

  std::string option;
  int tempMemID;
  std::string tempName;
  std::string tempAddress;
  std::string tempEmail;

  do
  {
    std::cout << "please enter option: (Liberian - l)(quit program - q)" << '\n';
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

      std::cout << '\n----------' << "Do you want to create a new member? (input m)" << '\n';
      std::cout << "Do you want to quit program? (input q)" << '\n';
      std::cin >> option;

      if (option == "m")
      {
        librarianObj.addMember();
      }

      std::cout << calcDueDate(10);
    }
  } while (option != "q");

  std::cout << "application end!";

  return 0;
}