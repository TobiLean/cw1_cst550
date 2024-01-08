#include <iostream>
#include <vector>

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
  virtual ~Person()
  {}

  const std::string getName()
  {
    std::cout << Person::name << '\n';
    return Person::name;
  }

  void setName(std::string name)
  {
    Person::name = name;
  }

  const std::string getAddress()
  {
    std::cout << Person::address << '\n';
  }

  void setAddress(std::string address)
  {
    Person::address = address;
  }

  const std::string getEmail()
  {
    std::cout << Person::email << '\n';
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
  // : Person(name, address, email), staffId(staffId), salary(salary)
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
    return Librarian::staffId;
  }

  void setStaffID(int staffID)
  {
    Librarian::staffId = staffID;
  }

  int getSalary()
  {
    std::cout << "Salary is " << Librarian::salary;
    return Librarian::salary;
  }

  void setSalary(int salary)
  {
    Librarian::salary = salary;
  }
};

class Member : public Person
{
private:
  int memberId;
  // std::vector<Book> booksLoaned;

public:
  Member(int memberID, std::string name, std::string address, std::string email)
  {
    std::cout << "Member made" << '\n';
    Member::memberId = memberID;
    Person::setName(name);
    Person::setAddress(address);
    Person::setEmail(email);
  }
};

int main()
{

  std::string type;
  std::string tempName;
  std::string tempAddress;
  std::string tempEmail;
  std::string tempSalary;

  std::cout << "please enter type: (Liberian - l)(Member - m)" << '\n';
  std::cin >> type;
  if (type == "m")
  {
    std::cout << "please enter member name: ";
    std::cin >> tempName;
    std::cout << "please enter member address: ";
    std::cin >> tempAddress;
    std::cout << "please enter member email: ";
    std::cin >> tempEmail;

    Member obj1(12, tempName, tempAddress, tempEmail);

    // std::cout << "Member Name:"
    obj1.getName();
    obj1.getAddress();
    obj1.getEmail();
  }

  return 0;
}
