#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "person.h"
#include "librarian.h"
#include "member.h"
#include "book.h"
#include "date.h"
#include <vector>

std::vector<Member> memberMap;

Librarian::Librarian(int staffID, std::string name, std::string address, std::string email, int salary)
{
    std::cout << "object created" << '\n';
    Librarian::staffId = staffID;
    Person::setName(name);
    Person::setAddress(address);
    Person::setEmail(email);
    Librarian::salary = salary;
};

void Librarian::addMember()
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

    // REMEMBER  TO DO VALIDATION :)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))

    Member memberObj(tempMemID, tempName, tempAddress, tempEmail);

    memberMap.push_back(memberObj);

    memberObj.getMemberID();
    memberObj.getName();
    memberObj.getAddress();
    memberObj.getEmail();
};

void Librarian::issueBook(int memberID, int bookID)
{
    std::fstream bookfile;

    bookfile.open("library_books.csv", std::ios::in);

    if (!bookfile.is_open())
    {
        std::cerr << "Error opening csv file!" << std::endl;
        return;
    }
    else
    {
        std::cout << "Book Open" << '\n';
    }

    std::vector<std::string> row, bookDetails;
    std::string line, word;
    int d, m, y;
    int count = 0;

    while (std::getline(bookfile, line))
    {
        row.push_back(line);
        count++;
    }

    bookfile.close();

    std::string tempStr = row[bookID];

    std::stringstream bookStream(tempStr);

    while (bookStream.good())
    {
        std::getline(bookStream, word, ',');
        bookDetails.push_back(word);
    }

    Book bookObj(std::stoi(bookDetails[0]), bookDetails[1], bookDetails[2], bookDetails[3]);

    std::cout << "Please set a due date, day: ";
    std::cin >> d;
    std::cout << "Please set a due date, month: ";
    std::cin >> m;
    std::cout << "Please set a due date, year: ";
    std::cin >> y;

    Date validDate(d, m, y);
    bookObj.setDueDate(validDate);

    for (auto &obj : memberMap)
    {
        if (std::stoi(obj.getMemberID()) == memberID)
        {
            bookObj.borrowBook(&obj, validDate);
            obj.setBooksBorrowed(bookObj);
            Book f = obj.getBooksBorrowed()[0];
            std::cout << f.getbookName();
        }
        else
        {
            std::cout << "wrong ID: " << obj.getMemberID() << "or is it" << memberID << std::endl;
        }
    }
};

void Librarian::returnBook(int memberID, int bookID)
{
    int position = 0;
    for (auto &obj : memberMap)
    {
        if (std::stoi(obj.getMemberID()) == memberID)
        {

            auto books = obj.getBooksBorrowed();
            if (!books.empty())
            {
                bool bookFound = false;
                for (size_t i = 0; i < books.size(); ++i)
                {
                    if (std::stoi(books[i].getbookID()) == bookID)
                    {
                        books.erase(books.begin() + i);
                        bookFound = true;
                        break;
                    }
                }
                if (bookFound)
                {
                    obj.getBooksBorrowed().clear();
                    std::cout << obj.getBooksBorrowed().size();
                    for(const auto& book : books)
                    {
                        obj.setBooksBorrowed(book);
                    }
                    std::cout << "Book returned. Amount of books left: " << books.size() << std::endl;
                }
                else
                {
                    std::cout << "No book found with that ID." << std::endl;
                }
            }
            else
            {
                std::cout << "No book borrowed by this member!";
            }
            return;
        }
    }
     std::cout << "Member ID not found." << std::endl;
}

const void Librarian::displayBorrowedBooks(int memberID)
{
}

void calcFine(int memberID)
{
}

const int Librarian::getStaffID()
{
    return Librarian::staffId;
}

void Librarian::setStaffID(int staffID)
{
    Librarian::staffId = staffID;
}

const int Librarian::getSalary()
{
    std::cout << "Salary is " << Librarian::salary << '\n';
    return Librarian::salary;
}

void Librarian::setSalary(int salary)
{
    Librarian::salary = salary;
}
