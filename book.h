#ifndef _BOOK_H_
#define _BOOK_H_

#include <iostream>
#include <vector>
#include <ctime>
#include "member.h"

class Member;

class Book
{
private:
  int bookID;
  std::string bookName;
  std::string authorFirstName;
  std::string authorLastName;
  std::string bookType;
  time_t dueDate;
  Member* borrower;

public:
  Book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName);

  std::string getbookID();

  std::string getbookName();

  std::string getAuthorFirstName();

  std::string getAuthorLastName();

  time_t getDueDate();

  void setDueDate(time_t Date);

  void returnBook();

  void borrowBook(Member* borrower, time_t dueDate);
};

#endif