#include <iostream>
#include <string>
#include "person.h"
#include "librarian.h"
#include "member.h"

Librarian::Librarian(int staffID, std::string name, std::string address, std::string email, int salary)
{
    std::cout << "object created" << '\n';
    Librarian::staffId = staffID;
    Person::setName(name);
    Person::setAddress(address);
    Person::setEmail(email);
    Librarian::salary = salary;
}

void addMember()
{

    int tempMemID;
    std::string tempName;
    std::string tempAddress;
    std::string tempEmail;

    std::cout << "please enter member ID: ";
    std::cin >> tempMemID;
    std::cout << "please enter member name: ";
    std::cin >> tempName;
    std::cout << "please enter member address: ";
    std::cin >> tempAddress;
    std::cout << "please enter member email: ";
    std::cin >> tempEmail;

    Member memberObj(tempMemID, tempName, tempAddress, tempEmail);

    memberObj.getMemberID();
    memberObj.getName();
    memberObj.getAddress();
    memberObj.getEmail();
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

int Librarian::getStaffID()
{
    return Librarian::staffId;
}

void Librarian::setStaffID(int staffID)
{
    Librarian::staffId = staffID;
}

int Librarian::getSalary()
{
    std::cout << "Salary is " << Librarian::salary << '\n';
    return Librarian::salary;
}

void Librarian::setSalary(int salary)
{
    Librarian::salary = salary;
}