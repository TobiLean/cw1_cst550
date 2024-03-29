#ifndef _MEMBER_H_
#define _MEMBER_H_

/*
    member.h
    Author: M00885480
    Created: 10/01/2024
    Updated: 15/01/2024
*/

#include <iostream>
#include "person.h"
#include <vector>
#include "book.h"

class Member;

extern std::vector<Member> memberContainer;

class Book;

class Member : public Person
{
private:
  int memberId;
  std::vector<Book> booksLoaned;

public:
  Member(int memberID, std::string name, std::string address, std::string email);
  const std::string getMemberID();
  std::vector<Book>& getBooksBorrowed();
  void setBooksBorrowed(Book book);
};

#endif