#ifndef _LIBRARIAN_H_
#define _LIBRARIAN_H_

#include <iostream>
#include <string>
#include "person.h"
#include "member.h"

class Librarian : public Person
{

private:
  int staffId;
  int salary;

public:
  Librarian(int staffID, std::string name, std::string address, std::string email, int salary);

  void addMember();

  void issueBook(int memberID, int bookID);

  void returnBook(int memberID, int bookID);

  const void displayBorrowedBooks(int memberID);

  void calcFine(int memberID);

  const int getStaffID();

  void setStaffID(int staffID);

  const int getSalary();

  void setSalary(int salary);
};

#endif