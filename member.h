#ifndef _MEMBER_H_
#define _MEMBER_H_

#include <iostream>
#include "person.h"
#include <vector>
#include "book.h"

class Book;

class Member : public Person
{
private:
  int memberId;
  std::vector<Book> booksLoaned;

public:
  Member(int memberID, std::string name, std::string address, std::string email);
  const std::string getMemberID();
  const std::vector<Book> getBooksBorrowed();
  void setBooksBorrowed(Book book);
};

#endif