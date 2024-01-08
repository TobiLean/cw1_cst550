#include <iostream>

/*
  cw1.cpp
  author: M00885480
  created: 08/01/2024
  updated: 08/01/2024
*/

class Person
{
private:
  std::string name;
  std::string address;
  std::string email;

public:
  std::string getName()
  {
    std::cout << Person::name;
  }

  void setName(std::string name)
  {
    Person::name = name;
  }

  std::string getAddress()
  {
    std::cout << Person::address;
  }

  void setAddress(std::string address)
  {
    Person::address = address;
  }

  std::string getEmail()
  {
    std::cout << Person::email;
  }

  void setEmail(std::string email)
  {
    Person::email = email;
  }
};

class Librarian : Person
{

private:
  int staffId;
  int salary;

public:
  Librarian(int staffId, std::string name, std::string address, std::string email, int salary)
  {
    std::cout << "object " << this << "created";
  }

  void addMember()
  {
  }

  void issueBook(int memberID, int bookID)
  {
  }

  void returnBook(int memberID, int bookID)
  {
  }

  void displayBorrowedBooks(int memberID)
  {
  }

  void calcFine(int memberID)
  {
  }

  int getStaffID()
  {
  }

  void setStaffID(int staffID)
  {
    Librarian::staffId = staffID;
  }

  int getSalary()
  {
  }

  void setSalary(int salary)
  {
    Librarian::salary = salary;
  }
};

int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}
