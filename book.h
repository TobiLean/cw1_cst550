#ifndef _BOOK_H_
#define _BOOK_H_

/*
    book.h
    Author: M00885480
    Created: 10/01/2024
    Updated: 15/01/2024
*/

#include <iostream>
#include <vector>
#include "member.h"
#include "date.h"

class Member;

class Book
{
private:
  int bookID;
  std::string bookName;
  std::string authorFirstName;
  std::string authorLastName;
  std::string bookType;
  Date dueDate;
  Member* borrower;

public:
  Book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName);

  const std::string getbookID();

  const std::string getbookName();

  const std::string getAuthorFirstName();

  const std::string getAuthorLastName();

  const Date getDueDate();

  void setDueDate(Date dueDate);

  void returnBook();

  void borrowBook(Member* borrower, Date dueDate);
};

#endif